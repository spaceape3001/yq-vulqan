////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>
#include <yt/os/Joystick.hpp>

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
    
        JoystickEvent(JoystickID j, const Param&);
        virtual ~JoystickEvent();
        
        JoystickID          joystick() const { return m_joystick; }
        
        static void init_info();
        
    private:
        const JoystickID  m_joystick;
    };
}
