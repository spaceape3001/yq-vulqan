////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Thread.hpp"
#include "ThreadBind.hpp"
#include "ThreadData.hpp"
#include "ThreadInfoWriter.hpp"

namespace yq::tachyon {
    struct Thread::Control {
        TachyonID           parent;
        TachyonPtr          object;
        TachyonSnapCPtr     snap;
        bool                ticked  = false;
    };
    

    struct Thread::Impl : public Tachyon::Impl {
    
        std::map<uint64_t, Control>     objects;
        std::vector<TachyonFrame>       minis;
    
        Impl(uint64_t i) : Tachyon::Impl(i) 
        {
        }
    };


    struct Thread::Repo {
        using mutex_t   = tbb::spin_rw_mutex;
        using lock_t    = mutex_t::scoped_lock;
        
        mutable mutex_t     mutex;
        
    };


// ------------------------------------------------------------------------

    ThreadBind::ThreadBind(const Thread* v) : m_thread( v ? v->id() : ThreadID{})
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

    Thread::Thread(const Param& p) : Tachyon(p, [](uint64_t i){ return new Impl(i); })
    {
    }
    
    Thread::~Thread()
    {
    }

    void    Thread::tick()
    {
        static Repo&  _r  = repo();
    }
    
    void    Thread::tick(Context&)
    {
    }

    void    Thread::tick(TachyonID tid)
    {
        Impl&   _i  = static_cast<Impl&>(impl());
        
        
    }
    
}
