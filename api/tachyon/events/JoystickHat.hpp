////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickHat : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickHat, JoystickEvent);
    public:
        static void init_info();
    
        struct Param : public JoystickEvent::Param {
        };
    
        JoystickHat(const Param&);
        ~JoystickHat();
    };
}
