////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/api/Context.hpp>
#include <yt/api/Frame.hpp>
#include <yt/api/FrameBuilder.hpp>
#include <yt/api/Thread.hpp>
#include <yt/api/ThreadData.hpp>
#include <yt/api/ThreadInfoWriter.hpp>

#include <yq/core/ThreadId.hpp>
#include <yq/stream/Logger.hpp>
#include <yt/logging.hpp>
#include <ya/events/thread/ThreadAddTachyonEvent.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    using namespace std::chrono_literals;

    static constexpr const std::chrono::milliseconds kFrameReport    = 0ms;

    inline bool    is_specified(const Execution&es)
    {
        return !std::get_if<std::monostate>(&es);
    }

// ------------------------------------------------------------------------

    enum class XMode {
        Stopped     = 0,
        Run,
        Pause,
        Step
    };
    
    struct Thread::Control {
        TachyonPtr              object;
        TachyonSnapCPtr         snap;
        TachyonThreadState      state       = TachyonThreadState::Normal;
        ThreadID                pushed;     // thread being pushed to
        //XMode                   mode        = XMode::Stop;
        unsigned int            deleteIn    = 0;    // gives X ticks to real removal
        bool                    ticked      = false;
    };
    
    struct Thread::Inbox {
        std::vector<TachyonPtr>  push;       //!< Tachyons being pushed to us
        std::vector<TachyonID>   deletes;    //!< Tachyons to delete
        std::set<TachyonID>      pushed;     //!< Acknowledgement to being pushed (so delete from sender)
    };
    

// ------------------------------------------------------------------------

    ThreadData::~ThreadData()
    {
    }

// ------------------------------------------------------------------------

    ThreadFrame::operator TachyonFrame() const
    {
        return { thread, data, snap};
    }

// ------------------------------------------------------------------------

    ThreadSnap::~ThreadSnap()
    {
    }

// ------------------------------------------------------------------------

    ThreadInfo::ThreadInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
        set(Type::Thread);
    }

// ------------------------------------------------------------------------

    thread_local Thread*        Thread::s_current   = nullptr;
    Thread*                     Thread::s_main      = nullptr;
    Thread*                     Thread::s_sink      = nullptr;
    Thread::mutex_t             Thread::s_mutex;
    Thread::thread_map_t        Thread::s_threads;
    Thread::sthread_map_t       Thread::s_sthreads;
    Thread::inbox_map_t         Thread::s_inboxes;
    std::vector<TachyonPtr>     Thread::s_misfits;

    
    void Thread::init_info()
    {
        auto w = writer<Thread>();
        w.description("Thread of execution");
        
        auto wt = writer<ThreadID>();
        wt.description("Thread Identifier");
        wt.set(Meta::Flag::ID);
    }

    std::vector<ThreadPtr>   Thread::all()
    {
        std::vector<ThreadPtr>  ret;
        {
            lock_t  _lock(s_mutex, false);
            ret.reserve(s_threads.size());
            for(auto& i : s_threads)
                ret.push_back(i.second.thread);
        }
        return ret;
    }

    ThreadPtr    Thread::get(ThreadID tid)
    {
        lock_t  _lock(s_mutex, false);
        auto i = s_threads.find(tid);
        if(i != s_threads.end())
            return i->second.thread;
        return {};
    }

    void Thread::remove(TachyonID tid, ThreadID th)
    {
        lock_t _lock(s_mutex, true);
        s_inboxes[th].deletes.push_back(tid);
    }
    
    void Thread::retain(TachyonPtr tp)
    {
        if(!tp)
            return;
            
        if(dynamic_cast<Thread*>(tp.ptr()))
            return;
        
        if(s_current){
            lock_t _lock(s_current->m_mutex, true);
            s_current -> m_creates.push_back(tp);
            return;
        }
        
        if(s_sink){
            lock_t _lock2(s_sink->m_mutex, true);
            s_sink->m_creates.push_back(tp);
            return ;
        }
        
        if(s_main){
            lock_t _lock2(s_main->m_mutex, true);
            s_main->m_creates.push_back(tp);
            return ;
        }
        
        lock_t  _lock(s_mutex, true);
        s_misfits.push_back(tp);
    }
    
    void Thread::retain(TachyonPtr tp, ThreadID tid)
    {
        if(!tp)
            return;

        ThreadPtr   th = get(tid);
        if(th){
            lock_t _lock(tp->m_mutex, true);
            th->m_creates.push_back(tp);
            return;
        }
        
        retain(tp);
    }

    void Thread::retain(TachyonPtr tp, StdThread st)
    {
        ThreadID    tid = standard(st);
        if(tid){
            retain(tp, tid);
        } else {
            retain(tp);
        }
    }

    void Thread::rethread(TachyonPtr tac, ThreadID tgt)
    {
        if(!tac)
            return ;
            
        ThreadPtr   th  = get(tgt);
        if(!th)
            return;

        ThreadPtr   me  = get(tac->owner());
        if(me){
            {
                lock_t _lock(me->m_mutex, true);
                me->m_pushing.push_back({tac->id(), tgt});
            }
        } else {
            //  Not in any, becomes a create
            lock_t  _lock(th->m_mutex, true);
            th->m_creates.push_back(tac);
        }
    }

    ThreadID Thread::standard(StdThread st)
    {
        lock_t _lock(s_mutex, false);
        auto itr = s_sthreads.find(st);
        if(itr != s_sthreads.end())
            return itr->second;
        return {};
    }

    void Thread::standard(StdThread st, ThreadID tid)
    {
        lock_t _lock(s_mutex, true);
        s_sthreads[st]  = tid;
    }

    bool Thread::valid(ThreadID tid)
    {
        lock_t  _lock(s_mutex, false);
        auto i = s_threads.find(tid);
        if(i != s_threads.end())
            return i->second.thread.valid();
        return false;
    }


// ------------------------------------------------------------------------

    Thread::Thread(const Param& p) : Tachyon(p)
    {
        ThreadID    _id = id();
        
        if(!thread::id() && !s_main){
            s_main      = this;
            s_sink      = this;
        }
        
        lock_t    _lock(s_mutex, true);
        s_threads[_id].thread   = this;
        s_inboxes[_id]          = {};
    }
    
    Thread::~Thread()
    {
        if(this == s_current){
            s_current    = nullptr;
        }
    
        lock_t _lock(s_mutex, true);
        if(s_main == this){
            s_main  = nullptr;
        }
        if(s_sink == this){
            s_sink  = nullptr;
        }
    }

    ThreadData&     Thread::data()
    {
        return static_cast<ThreadData&>(Tachyon::data());
    }

    void    Thread::exec()
    {
        while(!m_quit){
            tick();
        }
    }

    void    Thread::execute(Control& ctr, const Context& ctx)
    {
        if(ctr.state != TachyonThreadState::Normal)
            return ;
    
        //tachyonInfo << "Thread{" << metaInfo().name() << "}::execute(Control&, Context&)";
        ThreadData&     d    = data();

        //  Ignore the actual execution control (for now)
        
        auto res    = ctr.object->cycle(ctx);
        ctr.snap    = res.snap;
        d.tachyons.push_back({ ctr.object, res.data, res.snap });
        
        if(std::get_if<delete_k>(&res.execute)){
            lock_t _lock(s_mutex, true);
            s_inboxes[id()].deletes.push_back(ctr.object->id());
        }
    }

    void    Thread::join()
    {
        quit();
        m_thread.join();
    }


    void    Thread::owner(push_k, ThreadID) 
    {
        //  Threads cannot be pushed to another thread, they are their own entity
    }

    void    Thread::quit()
    {
        m_quit  = true;
    }
    
    void    Thread::shutdown()
    {
        quit();
    }
    
    void    Thread::start()
    {
        if(m_thread.joinable()) // something's running... don't
            return ;
        m_thread    = std::thread([this](){ 
            s_current   = this;
            run(); 
            s_current   = nullptr;
        });
    }

    Execution   Thread::subtick(const Context&)
    {
        return {};
    }

    void    Thread::task(task_fn&&fn)
    {
        if(!fn)
            return ;
        lock_t _lock(m_mutex, true);
        m_tasks.push_back(fn);
    }

    void    Thread::tick()
    {
        thread_map_t        threads;
        {
            lock_t      _lock(s_mutex, false);
            threads     = s_threads;
        }
  
        FramePtr        frame   = new Frame(id(), m_tick);
        Frame::Builder  build(*frame);
        
        /*
            NOTE, on the threadripper, we seem to be missing data/frames
            for a few steps, which causes the whole thing not to startup
            properly.  (TODO... fix later once the t-ripper is back
            in operation)
        */
        
        m_missing   = false;
        for(auto& i : threads){
            if(!i.second.data){
                m_missing   = true;
                continue;
            }
            frame->add({}, i.second);
            build.add(i.first, *i.second.data);
        }
        build.finalize();
        
        if constexpr (kFrameReport != 0ms){
            time_point_t    n   = clock_t::now();
            if((m_lastFrameReport == time_point_t{}) || (m_lastFrameReport + kFrameReport <= n)){
                m_lastFrameReport   = n;
                stream::Logger  log(tachyonInfo);
                log << ident() << " -- ";
                frame->report(log);
            }
        }
        
        Frame::s_current  = frame.ptr();

        Context ctx;
        ctx.wall            = frame->wallclock();
        ctx.tick            = m_tick;
        
        if(m_lastTickTime != time_point_t{}){
            ctx.Δwall       = unit::Nanosecond(duration_picoseconds_t(frame->wallclock() - m_lastTickTime).count());
        }
        m_lastTickTime   = frame->wallclock();
        
        auto d = cycle(ctx);
        {
            // doing this trick to postpone any destructors
            ThreadDataCPtr      data    = (const ThreadData*) d.data.ptr();
            ThreadSnapCPtr      snap    = (const ThreadSnap*) d.snap.ptr();
            {
                lock_t  _lock(s_mutex, true);
                auto& tf    = s_threads[id()];
                std::swap(data, tf.data);
                std::swap(snap, tf.snap);
            }
        }
        
        Frame::s_current  = nullptr;
        
        ++m_tick;
    }
    
    Execution    Thread::tick(const Context& ctx)
    {
        //tachyonInfo << "Thread{" << metaInfo().name() << "}::tick(const Context&)";
        Thread* old = s_current;
        s_current   = this;
    
        ThreadData&     d    = data();

        Inbox   inbox;
        {
            lock_t    _lock(s_mutex, true);
            std::swap(inbox, s_inboxes[id()]);
        }
        
        //  Process the inbox...
        for(auto& in : inbox.push){
            if(!in)
                continue;
            
            m_objects[in->id()].object  = in;
            {
                lock_t  _lock(s_mutex, true);
                s_inboxes[in->owner()].pushed.insert(in->id());
            }
            {
                lock_t  _lock(in->m_mutex, true);
                in->m_owner = id();
                in->subscribe(id(), MG::Thread);
            }
            subscribe(in->id(), MG::Tachyon);
            d.arrived.insert(in->id());
            send(new ThreadAddTachyonEvent({.source=this}, in.ptr()));
        }
        
        for(auto  in : inbox.pushed){
            unsubscribe(in, MG::Tachyon);
            m_objects.erase(in);
        }
        
        for(auto in : inbox.deletes){
            unsubscribe(in, MG::Tachyon);
            m_objects.erase(in);
            d.deleted.insert(in);
        }
        
        //data.duration   = ctx.
        std::vector<TachyonPtr>         creates;
        {
            lock_t  _lock(m_mutex, true);
            std::swap(m_creates, creates);
        }
        for(TachyonPtr& tp : creates){
            Control&    c   = m_objects[tp->id()];
            tp->m_owner     = id();
            tp->subscribe(id(), MG::Thread);
            subscribe(tp->id(), MG::Tachyon);
            d.created.insert(tp->id());
            send(new ThreadAddTachyonEvent({.source=this}, tp.ptr()));
            c.object        = std::move(tp);
        }
        
        //  TODO: Some multithreadedness... 
        //  NOTE: For multithreading, don't forget to set Frame::s_current!
        {
            std::vector<task_fn>            tasks;
            {
                lock_t _lock(m_mutex, true);
                std::swap(tasks, m_tasks);
            }
            for(task_fn& fn : tasks)
                fn();
        }
        
        Execution ex = subtick(ctx);
        for(auto itr = m_objects.begin(); itr != m_objects.end(); ++itr){
            execute(itr->second, ctx);
        }
        
        std::vector<PP> pushing;
        {
            lock_t _lock(m_mutex, true);
            std::swap(m_pushing, pushing);
        }
        
        for(const PP& pp : pushing){
            ThreadPtr   th  = get(pp.destination);
            if(!th) // skipping pushes to non-existent threads
                continue;
            
            auto j  = m_objects.find(pp.tachyon);
            if(j == m_objects.end())    // not in this object
                continue;
            Control&    c   = j->second;
            if(!c.object)               // nothing to push
                continue;
            
            c.pushed    = pp.destination;
            c.state     = TachyonThreadState::Pushed;
            c.object->unsubscribe(id(), MG::Thread);
            unsubscribe(pp.tachyon, MG::Tachyon);
        
            lock_t _lock(s_mutex, true);
            s_inboxes[pp.destination].push.push_back(c.object);
        }
        
        s_current   = old;
        return ex;
    }


    
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Thread)
YQ_TYPE_IMPLEMENT(yq::tachyon::ThreadID)
