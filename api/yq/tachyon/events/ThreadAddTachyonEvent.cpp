////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ThreadAddTachyonEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ThreadAddTachyonEvent)

namespace yq::tachyon {
    ThreadAddTachyonEvent::ThreadAddTachyonEvent(Thread*t, TypedID tac, const Param&p) : 
        ThreadEvent(t, p), m_tachyon(tac)
    {
    }
    
    ThreadAddTachyonEvent::ThreadAddTachyonEvent(ThreadID t, TypedID tac, const Param& p) : 
        ThreadEvent(t, p), m_tachyon(tac)
    {
    }
    
    ThreadAddTachyonEvent::~ThreadAddTachyonEvent()
    {
    }
        
    void ThreadAddTachyonEvent::init_info()
    {
        auto w = writer<ThreadAddTachyonEvent>();
        w.description("Thread Added a Tachyon Event");
    }
    
}

