////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/input/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickState : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickState, JoystickEvent);
    public:
        static void init_info();
    
        struct Param : public JoystickEvent::Param {
        };
    
        JoystickState(const Param&);
        ~JoystickState();
    };
}
