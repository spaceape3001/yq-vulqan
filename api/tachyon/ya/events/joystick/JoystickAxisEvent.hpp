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
    
        JoystickAxisEvent(const Header&, size_t axis, float value, float delta);
        
        size_t  axis() const { return m_axis; }
        float   value() const { return m_value; }
        float   delta() const { return m_delta; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        JoystickAxisEvent(const JoystickAxisEvent&, const Header&);
        ~JoystickAxisEvent();
        
    private:
        size_t      m_axis;
        float       m_value;
        float       m_delta;
        
        JoystickAxisEvent(const JoystickAxisEvent&) = delete;
        JoystickAxisEvent(JoystickAxisEvent&&) = delete;
        JoystickAxisEvent& operator=(const JoystickAxisEvent&) = delete;
        JoystickAxisEvent& operator=(JoystickAxisEvent&&) = delete;
    };
}
