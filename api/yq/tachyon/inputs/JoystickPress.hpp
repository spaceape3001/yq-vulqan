////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/input/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickPress : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickPress, JoystickEvent);
    public:
        static void init_info();
    
        struct Param : public JoystickEvent::Param {
        };
    
        JoystickPress(const Param&);
        ~JoystickPress();
    };
}
