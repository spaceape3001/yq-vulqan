////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/JoystickEvent.hpp>
#include <yq/tachyon/enum/JoystickHatState.hpp>

namespace yq::tachyon {
    class JoystickHatEvent : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickHatEvent, JoystickEvent);
    public:
        static void init_info();
    
        struct Param : public JoystickEvent::Param {
        };
        
        JoystickHatState state() const { return m_state; }
        size_t           hat() const { return m_hat; }
    
        JoystickHatEvent(Joystick, size_t, JoystickHatState, const Param& p={});
        ~JoystickHatEvent();

    private:
        const size_t              m_hat;
        const JoystickHatState    m_state;
    };
}
