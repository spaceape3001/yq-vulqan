////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickPressEvent : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickPressEvent, JoystickEvent);
    public:
        static void init_info();
    
        struct Param : public JoystickEvent::Param {
        };
    
        JoystickPressEvent(Joystick, size_t, const Param& p={});
        ~JoystickPressEvent();

        size_t  button() const { return m_button; }
        
    private:
        const size_t  m_button;
    };
}
