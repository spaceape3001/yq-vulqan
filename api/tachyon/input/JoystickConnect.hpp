////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickConnect : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickConnect, JoystickEvent);
    public:
        static void init_info();
    
        JoystickConnect(Joystick);
        ~JoystickConnect();
    };
}
