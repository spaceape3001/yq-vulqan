////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickConnectEvent : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickConnectEvent, JoystickEvent);
    public:
        static void init_info();
    
        struct Param : public JoystickEvent::Param {
        };
    
        JoystickConnectEvent(Joystick, const Param& p = {});
        ~JoystickConnectEvent();
    };
}
