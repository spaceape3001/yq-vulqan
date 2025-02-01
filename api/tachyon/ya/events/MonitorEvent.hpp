////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Event.hpp>
#include <yt/os/Monitor.hpp>

namespace yq::tachyon {
    class MonitorEventInfo : public EventInfo {
    public:
        MonitorEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl=std::source_location::current());
    };

    class MonitorEvent : public Event {
        YQ_OBJECT_INFO(MonitorEventInfo)
        YQ_OBJECT_DECLARE(MonitorEvent, Event)
    public:
    
        // NOT USED....
    
        struct Param : public Event::Param {
        };
    
        virtual ~MonitorEvent();

        const Monitor&  monitor() const { return m_monitor; }
        
        static void init_info();
        
    protected:
        MonitorEvent(Monitor, const Param&);
    private:
        const MonitorID  m_monitor;
    };
}
