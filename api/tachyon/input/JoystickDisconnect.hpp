////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickDisconnect : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickDisconnect, JoystickEvent);
    public:
        static void init_info();
    
        JoystickDisconnect(Joystick);
        ~JoystickDisconnect();
    };
}
