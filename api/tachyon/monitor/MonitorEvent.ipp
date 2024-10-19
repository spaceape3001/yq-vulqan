////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MonitorEvent.hpp"
#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorEvent)

namespace yq::tachyon {
    
    MonitorEventInfo::MonitorEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::MONITOR);
    }

    ////////////////////////////////////////////////////////////////////////////

    MonitorEvent::MonitorEvent(const Param& p) : InputEvent(p), m_monitor(p.monitor)
    {
    }
    
    MonitorEvent::~MonitorEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_monitor_event()
    {
        {
            auto w = writer<MonitorEvent>();
            w.description("Monitor event base class");
        }
    }
    
    YQ_INVOKE(reg_monitor_event();)
}
