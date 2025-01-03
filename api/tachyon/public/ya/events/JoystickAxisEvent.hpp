////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickAxisEvent : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickAxisEvent, JoystickEvent);
    public:
        static void init_info();
    
        struct Param : public JoystickEvent::Param {
        };
    
        JoystickAxisEvent(Joystick, size_t axis, float value, float delta, const Param& p={});
        ~JoystickAxisEvent();
        
        size_t  axis() const { return m_axis; }
        float   value() const { return m_value; }
        float   delta() const { return m_delta; }
        
    private:
        size_t      m_axis;
        float       m_value;
        float       m_delta;
    };
}
