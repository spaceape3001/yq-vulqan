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
    
        ThreadAddTachyonEvent(const Header&, TypedID);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();

        TypedID tachyon() const { return m_tachyon; }

    protected:
    
        ThreadAddTachyonEvent(const ThreadAddTachyonEvent&, const Header&);
        ~ThreadAddTachyonEvent();
    
    private:
        TypedID m_tachyon;
        
        ThreadAddTachyonEvent(const ThreadAddTachyonEvent&) = delete;
        ThreadAddTachyonEvent(ThreadAddTachyonEvent&&) = delete;
        ThreadAddTachyonEvent& operator=(const ThreadAddTachyonEvent&) = delete;
        ThreadAddTachyonEvent& operator=(ThreadAddTachyonEvent&&) = delete;
    };
}
