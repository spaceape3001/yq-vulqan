////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickPressEvent : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickPressEvent, JoystickEvent);
    public:
        static void init_info();
    
        JoystickPressEvent(const Header&, size_t);

        size_t  button() const { return m_button; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        JoystickPressEvent(const JoystickPressEvent&, const Header&);
        ~JoystickPressEvent();
    private:
        size_t  m_button;
        
        JoystickPressEvent(const JoystickPressEvent&) = delete;
        JoystickPressEvent(JoystickPressEvent&&) = delete;
        JoystickPressEvent& operator=(const JoystickPressEvent&) = delete;
        JoystickPressEvent& operator=(JoystickPressEvent&&) = delete;
    };
}
