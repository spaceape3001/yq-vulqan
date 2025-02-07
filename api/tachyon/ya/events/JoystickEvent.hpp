////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Event.hpp>
#include <yt/os/Joystick.hpp>

namespace yq::tachyon {
    class JoystickEvent : public Event {
        YQ_OBJECT_DECLARE(JoystickEvent, Event)
    public:

        static void init_info();

    protected:
        JoystickEvent(const Header&);
        JoystickEvent(const JoystickEvent&, const Header&);
        virtual ~JoystickEvent();
        
    private:
        JoystickEvent(const JoystickEvent&) = delete;
        JoystickEvent(JoystickEvent&&) = delete;
        JoystickEvent& operator=(const JoystickEvent&) = delete;
        JoystickEvent& operator=(JoystickEvent&&) = delete;
    };
}
