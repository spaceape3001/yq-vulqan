////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/InputEvent.hpp>
#include <yq/tachyon/Monitor.hpp>

namespace yq::tachyon {
    class MonitorEventInfo : public InputEventInfo {
    public:
        MonitorEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
    };

    class MonitorEvent : public InputEvent {
        YQ_OBJECT_INFO(MonitorEventInfo)
        YQ_OBJECT_DECLARE(MonitorEvent, InputEvent)
    public:
    
        struct Param : public InputEvent::Param {
        };
    
        virtual ~MonitorEvent();

        const Monitor&  monitor() const { return m_monitor; }
        
    protected:
        MonitorEvent(Monitor, const Param&);
    private:
        const Monitor  m_monitor;
    };
}
