////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/thread/ThreadAddTachyonEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ThreadAddTachyonEvent)

namespace yq::tachyon {
    ThreadAddTachyonEvent::ThreadAddTachyonEvent(const Header& h, TypedID tac) : 
        ThreadEvent(h), m_tachyon(tac)
    {
    }
    
    ThreadAddTachyonEvent::ThreadAddTachyonEvent(const ThreadAddTachyonEvent& cp, const Header& h) : 
        ThreadEvent(cp, h), m_tachyon(cp.m_tachyon)
    {
    }

    ThreadAddTachyonEvent::~ThreadAddTachyonEvent()
    {
    }
        
    PostCPtr    ThreadAddTachyonEvent::clone(rebind_k, const Header& h) const 
    {
        return new ThreadAddTachyonEvent(*this, h);
    }

    void ThreadAddTachyonEvent::init_info()
    {
        auto w = writer<ThreadAddTachyonEvent>();
        w.description("Thread Added a Tachyon Event");
    }
    
}

