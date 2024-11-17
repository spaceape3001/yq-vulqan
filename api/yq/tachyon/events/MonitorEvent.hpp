////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/glfw/Monitor.hpp>

namespace yq::tachyon {
    class MonitorEventInfo : public EventInfo {
    public:
        MonitorEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl=std::source_location::current());
    };

    class MonitorEvent : public Event {
        YQ_OBJECT_INFO(MonitorEventInfo)
        YQ_OBJECT_DECLARE(MonitorEvent, Event)
    public:
    
        struct Param : public Event::Param {
        };
    
        virtual ~MonitorEvent();

        const Monitor&  monitor() const { return m_monitor; }
        
        static void init_info();
        
    protected:
        MonitorEvent(Monitor, const Param&);
    private:
        const Monitor  m_monitor;
    };
}
