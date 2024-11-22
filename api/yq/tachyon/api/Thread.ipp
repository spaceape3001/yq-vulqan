////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Frame.hpp"
#include "FrameBuilder.hpp"
#include "Thread.hpp"
#include "ThreadBind.hpp"
#include "ThreadData.hpp"
#include "ThreadInfoWriter.hpp"

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
        mutable mutex_t         mutex;
        thread_data_map_t       data;  // must be modified under mutex guard
        inbox_map_t             inboxes;
        thread_map_t            threads;
        
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

// ------------------------------------------------------------------------

    Thread::Thread(const Param& p) : Tachyon(p)
    {
        static Repo&    _r  = repo();
        lock_t    _lock(_r.mutex, true);
        _r.threads[id()]    = this;
        _r.data[id()]       = {};
        _r.inboxes[id()]    = {};
    }
    
    Thread::~Thread()
    {
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

    void    Thread::execute(Control& ctr, Context& ctx)
    {
        ThreadData&     d    = data();

        //  Ignore the actual execution control (for now)
        
        auto res    = ctr.object->cycle(ctx);
        ctr.snap    = res.snap;
        d.tachyons.push_back({ ctr.object, res.data, res.snap });
    }

    void    Thread::join()
    {
        quit();
        m_thread.join();
    }

    void    Thread::quit()
    {
        m_quit  = true;
    }
    
    void    Thread::start()
    {
        if(m_thread.joinable()) // something's running... don't
            return ;
        m_thread    = std::thread([this](){ run(); });
    }

    void    Thread::tick()
    {
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
