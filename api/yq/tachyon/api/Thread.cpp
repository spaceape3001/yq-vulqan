////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Context.hpp"
#include "Frame.hpp"
#include "FrameBuilder.hpp"
#include "Thread.hpp"
#include "ThreadBind.hpp"
#include "ThreadData.hpp"
#include "ThreadInfoWriter.hpp"

#include <yq/core/ThreadId.hpp>
#include <yq/tachyon/logging.hpp>

namespace yq::tachyon {

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
        std::set<TachyonID>      deletes;    //!< Tachyons to delete
        std::set<TachyonID>      pushed;     //!< Acknowledgement to being pushed (so delete from sender)
    };
    

// ------------------------------------------------------------------------

    ThreadBind::ThreadBind(const Thread* v) : m_thread( v ? v->id() : ThreadID{} )
    {
    }

// ------------------------------------------------------------------------

    ThreadData::~ThreadData()
    {
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
    Thread::thread_data_map_t   Thread::s_data;
    Thread::thread_map_t        Thread::s_threads;
    Thread::inbox_map_t         Thread::s_inboxes;
    std::vector<TachyonPtr>     Thread::s_misfits;
    
    void Thread::init_info()
    {
        auto w = writer<Thread>();
        w.description("Thread of execution");
    }

    std::vector<ThreadPtr>   Thread::all()
    {
        std::vector<ThreadPtr>  ret;
        {
            lock_t  _lock(s_mutex, false);
            ret.reserve(s_threads.size());
            for(auto& i : s_threads)
                ret.push_back(i.second);
        }
        return ret;
    }

    ThreadPtr    Thread::get(ThreadID tid)
    {
        lock_t  _lock(s_mutex, false);
        auto i = s_threads.find(tid);
        if(i != s_threads.end())
            return i->second;
        return {};
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
                auto& obj   = me->m_objects[tac->id()];
                obj.pushed  = tgt;
                obj.state   = TachyonThreadState::Pushed;
                if(!obj.object)
                    obj.object  = tac;
                me->unsubscribe(tac->id(), MG::Tachyon);
            }
            tac->unsubscribe(tac->owner(), MG::Thread);
            {
                lock_t _lock(s_mutex, true);
                s_inboxes[tgt].push.push_back(tac);
            }
        } else {
            //  Not in any, becomes a create
            lock_t  _lock(th->m_mutex, true);
            th->m_creates.push_back(tac);
        }
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
        s_threads[_id]    = this;
        s_data[_id]       = {};
        s_inboxes[_id]    = {};
        
        tachyonInfo << "Thread::Thread()";
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
        
        tachyonInfo << "Thread::~Thread()";
    }

    ThreadData&     Thread::data()
    {
        return static_cast<ThreadData&>(Tachyon::data());
    }

    void    Thread::exec()
    {
        tachyonInfo << "Thread{" << metaInfo().name() << "}::exec()";
        while(!m_quit){
            tick();
        }
    }

    void    Thread::execute(Control& ctr, Context& ctx)
    {
        if(ctr.state != TachyonThreadState::Normal)
            return ;
    
        //tachyonInfo << "Thread{" << metaInfo().name() << "}::execute(Control&, Context&)";
        ThreadData&     d    = data();

        //  Ignore the actual execution control (for now)
        
        auto res    = ctr.object->cycle(ctx);
        ctr.snap    = res.snap;
        d.tachyons.push_back({ ctr.object, res.data, res.snap });
    }

    void    Thread::join()
    {
        tachyonInfo << "Thread{" << metaInfo().name() << "}::join()";
        quit();
        m_thread.join();
    }

    void    Thread::quit()
    {
        tachyonInfo << "Thread{" << metaInfo().name() << "}::quit()";
        m_quit  = true;
    }
    
    void    Thread::start()
    {
        tachyonInfo << "Thread{" << metaInfo().name() << "}::start()";
        if(m_thread.joinable()) // something's running... don't
            return ;
        m_thread    = std::thread([this](){ 
            s_current   = this;
            run(); 
            s_current   = nullptr;
        });
    }

    void    Thread::tick()
    {
        //tachyonInfo << "Thread{" << metaInfo().name() << "}::tick()";
  
        thread_data_map_t   data;
        {
            lock_t      _lock(s_mutex, false);
            data        = s_data;
        }
  
        FramePtr        frame   = new Frame(id(), m_tick);
        Frame::Builder  build(*frame);
        for(auto& i : data){
            if(!i.second)
                continue;
            build.add(i.first, *i.second);
        }
        build.finalize();

        Context ctx(*frame);
        auto d = cycle(ctx);
        {
            lock_t  _lock(s_mutex, true);
            s_data[id()] = (ThreadData*) d.data.ptr();
        }
    }
    
    Execution    Thread::tick(Context& ctx)
    {
        //tachyonInfo << "Thread{" << metaInfo().name() << "}::tick(Context&)";
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
        }
        
        for(auto  in : inbox.pushed){
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
            c.object        = std::move(tp);
        }
        
        //  TODO: Some multithreadedness...
        for(auto itr = m_objects.begin(); itr != m_objects.end(); ++itr){
            execute(itr->second, ctx);
        }
        
        s_current   = old;
        return {};
    }


    
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Thread)
