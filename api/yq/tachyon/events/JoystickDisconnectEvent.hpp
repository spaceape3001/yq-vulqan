////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickDisconnectEvent : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickDisconnectEvent, JoystickEvent);
    public:
        static void init_info();
        
        struct Param : public JoystickEvent::Param {
        };
    
        JoystickDisconnectEvent(Joystick, const Param& p={});
        ~JoystickDisconnectEvent();
    };
}
