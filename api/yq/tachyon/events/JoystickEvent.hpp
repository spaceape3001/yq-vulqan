////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/glfw/Joystick.hpp>

namespace yq::tachyon {
    class JoystickEventInfo : public EventInfo {
    public:
        JoystickEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class JoystickEvent : public Event {
        YQ_OBJECT_INFO(JoystickEventInfo)
        YQ_OBJECT_DECLARE(JoystickEvent, Event)
    public:
    
        struct Param : public Event::Param {
        };
    
        JoystickEvent(Joystick j, const Param&);
        virtual ~JoystickEvent();
        
        const Joystick& joystick() const { return m_joystick; }
        
        uint8_t joystick_id() const { return m_joystick.id; }
        
        static void init_info();
        
    private:
        const Joystick  m_joystick;
    };
}
