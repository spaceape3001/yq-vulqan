////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickZeroEvent : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickZeroEvent, JoystickEvent);
    public:
        static void init_info();
    
        JoystickZeroEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        JoystickZeroEvent(const JoystickZeroEvent&, const Header&);
        ~JoystickZeroEvent();
        
    private:
        JoystickZeroEvent(const JoystickZeroEvent&) = delete;
        JoystickZeroEvent(JoystickZeroEvent&&) = delete;
        JoystickZeroEvent& operator=(const JoystickZeroEvent&) = delete;
        JoystickZeroEvent& operator=(JoystickZeroEvent&&) = delete;
    };
}
