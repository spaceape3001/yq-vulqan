////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/JoystickEvent.hpp>
#include <yq/tachyon/os/HatState.hpp>

namespace yq::tachyon {
    class JoystickHatEvent : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickHatEvent, JoystickEvent);
    public:
        static void init_meta();
    
        HatState    state() const { return m_state; }
        size_t      hat() const { return m_hat; }
    
        JoystickHatEvent(const Header&, size_t, HatState);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        ~JoystickHatEvent();
        JoystickHatEvent(const JoystickHatEvent&, const Header&);

    private:
        size_t    m_hat;
        HatState  m_state;
        
        JoystickHatEvent(const JoystickHatEvent&) = delete;
        JoystickHatEvent(JoystickHatEvent&&) = delete;
        JoystickHatEvent& operator=(const JoystickHatEvent&) = delete;
        JoystickHatEvent& operator=(JoystickHatEvent&&) = delete;
    };
}
