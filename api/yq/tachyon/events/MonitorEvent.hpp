////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/post/Event.hpp>
#include <yq/tachyon/glfw/Monitor.hpp>

namespace yq::tachyon {
    class MonitorEventInfo : public post::EventInfo {
    public:
        MonitorEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl=std::source_location::current());
    };

    class MonitorEvent : public post::Event {
        YQ_OBJECT_INFO(MonitorEventInfo)
        YQ_OBJECT_DECLARE(MonitorEvent, post::Event)
    public:
    
        struct Param : public post::Event::Param {
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
