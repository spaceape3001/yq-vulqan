////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/InputEvent.hpp>
#include <tachyon/glfw/Monitor.hpp>

namespace yq::tachyon {
    class MonitorEventInfo : public InputEventInfo {
    public:
        MonitorEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl=std::source_location::current());
    };

    class MonitorEvent : public InputEvent {
        YQ_OBJECT_INFO(MonitorEventInfo)
        YQ_OBJECT_DECLARE(MonitorEvent, InputEvent)
    public:
        virtual ~MonitorEvent();

        const Monitor&  monitor() const { return m_monitor; }
        
    protected:
        MonitorEvent(Monitor);
    private:
        const Monitor  m_monitor;
    };
}
