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
    

    struct Thread::Repo {
    
        Thread*                 main = nullptr;
        ThreadID                mainID;
    
        //! Sink is the thread that'll be "in case" nothing fits
        Thread*                 sink = nullptr;
        ThreadID                sinkID;

        mutable mutex_t         mutex;
        thread_data_map_t       data;  // must be modified under mutex guard
        inbox_map_t             inboxes;
        thread_map_t            threads;
        
        std::vector<TachyonPtr> misfits;  //<! Adds that need retention by the next available thread
        
        void    acknowledge(ThreadID tgt, TachyonID tac)
        {
            lock_t  _lock(mutex, true);
            inboxes[tgt].pushed.insert(tac);
        }
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

    Thread::Repo&    Thread::repo()
    {
        static Repo s_repo;
        return s_repo;
    }
    
    thread_local Thread*     Thread::s_current  = nullptr;
    
    void Thread::init_info()
    {
        auto w = writer<Thread>();
        w.description("Thread of execution");
    }

    std::vector<ThreadPtr>   Thread::all()
    {
        std::vector<ThreadPtr>  ret;
        {
            static Repo& _r = repo();
            lock_t  _lock(_r.mutex, false);
            ret.reserve(_r.threads.size());
            for(auto& i : _r.threads)
                ret.push_back(i.second);
        }
        return ret;
    }

    void Thread::retain(TachyonPtr tp)
    {
        static Repo&    _r  = repo();
    
        if(!tp)
            return;
            
        if(Thread* th = dynamic_cast<Thread*>(tp.ptr())){
            lock_t _lock(_r.mutex, true);
            _r.threads[th->id()]    = th;
            return;
        }
        
        if(s_current){
            lock_t _lock(s_current->m_mutex, true);
            s_current -> m_creates.push_back(tp);
            return;
        }
        
        lock_t _lock(_r.mutex, true);
        if(_r.sink){
            lock_t _lock2(_r.sink->m_mutex, true);
            _r.sink->m_creates.push_back(tp);
            return ;
        }
        if(_r.main){
            lock_t _lock2(_r.main->m_mutex, true);
            _r.main->m_creates.push_back(tp);
            return ;
        }
        
        _r.misfits.push_back(tp);
    }
    
    void Thread::retain(TachyonPtr tp, ThreadID tid)
    {
        static Repo&    _r  = repo();
        if(!tp)
            return;

        ThreadPtr   th;
        {
            lock_t _lock(_r.mutex, false);
            auto i = _r.threads.find(tid);
            if(i != _r.threads.end())
                th = i->second;
        }
        
        if(th){
            lock_t _lock(tp->m_mutex, true);
            th->m_creates.push_back(tp);
            return;
        }
        
        retain(tp);
    }

// ------------------------------------------------------------------------

    Thread::Thread(const Param& p) : Tachyon(p)
    {
        static Repo&    _r  = repo();
        ThreadID    _id = id();
        
        lock_t    _lock(_r.mutex, true);
        if(!thread::id() && !_r.main){
            _r.main     = this;
            _r.mainID   = _id;
            _r.sink     = this;
            _r.sinkID   = _id;
        }
        
        _r.threads[_id]    = this;
        _r.data[_id]       = {};
        _r.inboxes[_id]    = {};
        
        tachyonInfo << "Thread::Thread()";
    }
    
    Thread::~Thread()
    {
        if(this == s_current){
            s_current    = nullptr;
        }
    
        static Repo& _r = repo();
        lock_t _lock(_r.mutex, true);
        if(_r.main == this){
            _r.main = nullptr;
            _r.mainID   = {};
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
        tachyonInfo << "Thread{" << metaInfo().name() << "}::execute(Control&, Context&)";
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
        tachyonInfo << "Thread{" << metaInfo().name() << "}::tick()";
        static Repo&  _r  = repo();
  
        thread_data_map_t   data;
        {
            lock_t      _lock(_r.mutex, false);
            data        = _r.data;
        }
  
        FramePtr        frame   = new Frame(id(), m_tick);
        Frame::Builder  build(*frame);
        for(auto& i : data){
            build.add(i.first, *i.second);
        }
        build.finalize();

        Context ctx(*frame);
        cycle(ctx);
    }
    
    Execution    Thread::tick(Context& ctx)
    {
        tachyonInfo << "Thread{" << metaInfo().name() << "}::tick(Context&)";
        static Repo& _r = repo();
        Thread* old = s_current;
        s_current   = this;
    
        ThreadData&     d    = data();

        Inbox   inbox;
        {
            lock_t    _lock(_r.mutex, true);
            std::swap(inbox, _r.inboxes[id()]);
        }
        
        //  Process the inbox...
        for(auto& in : inbox.push){
            if(!in)
                continue;
            
            m_objects[in->id()].object  = in;
            _r.acknowledge(in->owner(), in->id());
            {
                lock_t  _lock(in->m_mutex, true);
                in->m_owner = id();
            }
            d.arrived.insert(in->id());
        }
        
        for(auto  in : inbox.pushed){
            m_control.erase(in);
        }
        
        for(auto in : inbox.deletes){
            m_control.erase(in);
            d.deleted.insert(in);
        }
        
        //data.duration   = ctx.
        
        //  TODO: Some multithreadedness...
        for(auto itr = m_objects.begin(); itr != m_objects.end(); ++itr){
            execute(itr->second, ctx);
        }
        
        s_current   = old;
        return {};
    }


    
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Thread)
