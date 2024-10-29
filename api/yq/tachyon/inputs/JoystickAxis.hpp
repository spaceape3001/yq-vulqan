////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickAxis : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickAxis, JoystickEvent);
    public:
        static void init_info();
    
        struct Param : public JoystickEvent::Param {
        };
    
        JoystickAxis(const Param&);
        ~JoystickAxis();
    };
}
