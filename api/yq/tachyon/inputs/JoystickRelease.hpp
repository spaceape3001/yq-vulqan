////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/input/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickRelease : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickRelease, JoystickEvent);
    public:
        static void init_info();
    
        struct Param : public JoystickEvent::Param {
        };
    
        JoystickRelease(const Param&);
        ~JoystickRelease();
    };
}
