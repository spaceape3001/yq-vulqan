////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/event/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickReleaseEvent : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickReleaseEvent, JoystickEvent);
    public:
        static void init_meta();
    
        JoystickReleaseEvent(const Header&, size_t);
        ~JoystickReleaseEvent();
        
        size_t  button() const { return m_button; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        JoystickReleaseEvent(const JoystickReleaseEvent&, const Header&);
    
    private:
        size_t  m_button;
        
        JoystickReleaseEvent(const JoystickReleaseEvent&) = delete;
        JoystickReleaseEvent(JoystickReleaseEvent&&) = delete;
        JoystickReleaseEvent& operator=(const JoystickReleaseEvent&) = delete;
        JoystickReleaseEvent& operator=(JoystickReleaseEvent&&) = delete;
    };
}
