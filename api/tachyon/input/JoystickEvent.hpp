////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/InputEvent.hpp>
#include <tachyon/glfw/Joystick.hpp>

namespace yq::tachyon {
    class JoystickEventInfo : public InputEventInfo {
    public:
        JoystickEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class JoystickEvent : public InputEvent {
        YQ_OBJECT_INFO(JoystickEventInfo)
        YQ_OBJECT_DECLARE(JoystickEvent, InputEvent)
    public:
    
        JoystickEvent(Joystick);
        virtual ~JoystickEvent();
        
        const Joystick& joystick() const { return m_joystick; }
        
    private:
        const Joystick  m_joystick;
    };
}
