////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/ThreadEvent.hpp>
#include <yt/api/TypedID.hpp>

namespace yq::tachyon {
    class ThreadAddTachyonEvent : public ThreadEvent {
        YQ_OBJECT_DECLARE(ThreadAddTachyonEvent, ThreadEvent)
    public:
    
        ThreadAddTachyonEvent(Thread*, TypedID, const Param&p={});
        ThreadAddTachyonEvent(ThreadID, TypedID, const Param&p={});
        ~ThreadAddTachyonEvent();
        
        static void init_info();

        TypedID tachyon() const { return m_tachyon; }
    
    private:
        TypedID const m_tachyon;
    };
}
