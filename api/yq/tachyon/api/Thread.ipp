////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Frame.hpp"
#include "Thread.hpp"
#include "ThreadBind.hpp"
#include "ThreadData.hpp"
#include "ThreadInfoWriter.hpp"

namespace yq::tachyon {
    
    struct Thread::Control {
        TachyonID               parent;
        TachyonPtr              object;
        TachyonSnapCPtr         snap;
        TachyonThreadState      state       = TachyonThreadState::Normal;
        ThreadID                pushed;
        unsigned int            deleteIn    = 0;    // gives X ticks to real removal
        bool                    ticked      = false;
    };
    
    struct Thread::Inbox {
        std::set<TachyonPtr>     push;       //!< Tachyons being pushed to us
        std::set<TachyonID>      deletes;    //!< Tachyons to delete
        std::set<TachyonID>      pushed;     //!< Acknowledgement to being pushed (so delete from sender)
    };
    

    struct Thread::Repo {
        using mutex_t       = tbb::spin_rw_mutex;
        using lock_t        = mutex_t::scoped_lock;
        
        mutable mutex_t         mutex;
        thread_data_map_t       data;  // must be modified under mutex guard
        inbox_map_t             inboxes;
    };


// ------------------------------------------------------------------------

    ThreadBind::ThreadBind(const Thread* v) : m_thread( v ? v->id() : ThreadID{} )
    {
    }

// ------------------------------------------------------------------------

    ThreadInfo::ThreadInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
    }

// ------------------------------------------------------------------------

    Thread::Repo&    Thread::repo()
    {
        static Repo s_repo;
        return s_repo;
    }
    
// ------------------------------------------------------------------------

    Thread::Thread(const Param& p) : Tachyon(p)
    {
        static Repo&    _r  = repo();
        Repo::lock_t    _lock(_r.mutex, true);
        _r.inboxes[id()] = {};
    }
    
    Thread::~Thread()
    {
    }

    void    Thread::tick()
    {
        static Repo&  _r  = repo();
        
        thread_data_map_t   data;
        {
            Repo::lock_t    _lock(_r.mutex, false);
            data        = _r.data;
        }
        
        
    }
    
    void    Thread::tick(Context&)
    {
        Inbox   inbox;
    }

    void    Thread::tick(TachyonID tid)
    {
        Impl&   _i  = static_cast<Impl&>(impl());
        
        
    }
    
}
