////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickReleaseEvent : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickReleaseEvent, JoystickEvent);
    public:
        static void init_info();
    
        struct Param : public JoystickEvent::Param {
        };
    
        JoystickReleaseEvent(Joystick, size_t, const Param& p={});
        ~JoystickReleaseEvent();
        
        size_t  button() const { return m_button; }
        
    private:
        const size_t  m_button;
    };
}
