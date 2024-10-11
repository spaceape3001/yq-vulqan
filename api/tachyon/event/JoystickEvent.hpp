////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/Event.hpp>
#include <tachyon/glfw/Joystick.hpp>

namespace yq::tachyon {
    class JoystickEventInfo : public EventInfo {
    public:
        template <typename C> class Writer;

        JoystickEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class JoystickEvent : public Event {
        YQ_OBJECT_INFO(JoystickEventInfo)
        YQ_OBJECT_DECLARE(JoystickEvent, Event)
    public:
    
        //  EVENT TODO
    
        JoystickEvent(Joystick);
        virtual ~JoystickEvent();
        
        const Joystick& joystick() const { return m_joystick; }
        
    private:
        const Joystick  m_joystick;
    };

    /*! \brief Writer of event information
    */
    template <typename C>
    class JoystickEventInfo::Writer : public EventInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(JoystickEventInfo* joystickInputInfo) : EventInfo::Writer<C>(joystickInputInfo), m_meta(joystickInputInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(JoystickEventInfo& joystickInputInfo) : Writer(&joystickInputInfo)
        {
        }

    private:
        JoystickEventInfo* m_meta;
    };
}
