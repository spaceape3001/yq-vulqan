////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Event.hpp>
#include <yq/tachyon/Joystick.hpp>

namespace yq::tachyon {
    class JoystickEventInfo : public post::EventInfo {
    public:
        JoystickEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };

    class JoystickEvent : public post::Event {
        YQ_OBJECT_INFO(JoystickEventInfo)
        YQ_OBJECT_DECLARE(JoystickEvent, post::Event)
    public:
    
        struct Param : public post::Event::Param {
        };
    
        JoystickEvent(Joystick j, const Param&);
        virtual ~JoystickEvent();
        
        const Joystick& joystick() const { return m_joystick; }
        
    private:
        const Joystick  m_joystick;
    };
}
