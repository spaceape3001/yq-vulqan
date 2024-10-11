////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/Event.hpp>
#include <tachyon/glfw/Monitor.hpp>

namespace yq::tachyon {
    class MonitorEventInfo : public EventInfo {
    public:
        template <typename C> class Writer;

        MonitorEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl=std::source_location::current());
        
    protected:
    };


    class MonitorEvent : public Event {
        YQ_OBJECT_INFO(MonitorEventInfo)
        YQ_OBJECT_DECLARE(MonitorEvent, Event)
    public:
    
        //  EVENT TODO
    
        MonitorEvent(Monitor);
        virtual ~MonitorEvent();
        
        const Monitor&  monitor() const { return m_monitor; }
    private:
        const Monitor  m_monitor;
    };

    /*! \brief Writer of event information
    */
    template <typename C>
    class MonitorEventInfo::Writer : public EventInfo::Writer<C> {
    public:
    
        //! Constructor of widget info (this is used by derived classes and this classes other constructor)
        Writer(MonitorEventInfo* joystickInputInfo) : EventInfo::Writer<C>(joystickInputInfo), m_meta(joystickInputInfo)
        {
        }
        
        //! Constructor of widget info (this is used by the writer<T>() methods)
        Writer(MonitorEventInfo& joystickInputInfo) : Writer(&joystickInputInfo)
        {
        }

    private:
        MonitorEventInfo* m_meta;
    };
}
