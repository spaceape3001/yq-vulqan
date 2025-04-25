////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/JoystickEvent.hpp>

namespace yq::tachyon {
    class JoystickConnectEvent : public JoystickEvent {
        YQ_OBJECT_DECLARE(JoystickConnectEvent, JoystickEvent);
    public:
        static void init_info();
    
        JoystickConnectEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        JoystickConnectEvent(const JoystickConnectEvent&, const Header&);
        ~JoystickConnectEvent();
        
    private:
        JoystickConnectEvent(const JoystickConnectEvent&) = delete;
        JoystickConnectEvent(JoystickConnectEvent&&) = delete;
        JoystickConnectEvent& operator=(const JoystickConnectEvent&) = delete;
        JoystickConnectEvent& operator=(JoystickConnectEvent&&) = delete;
    };
}
