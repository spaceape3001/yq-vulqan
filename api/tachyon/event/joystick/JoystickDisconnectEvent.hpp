////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickDisconnectEvent : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickDisconnectEvent, JoystickEvent);
    public:
        static void init_meta();
        
        JoystickDisconnectEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        JoystickDisconnectEvent(const JoystickDisconnectEvent&, const Header&);
        ~JoystickDisconnectEvent();
        
    private:
        JoystickDisconnectEvent(const JoystickDisconnectEvent&) = delete;
        JoystickDisconnectEvent(JoystickDisconnectEvent&&) = delete;
        JoystickDisconnectEvent& operator=(const JoystickDisconnectEvent&) = delete;
        JoystickDisconnectEvent& operator=(JoystickDisconnectEvent&&) = delete;
    };
}
