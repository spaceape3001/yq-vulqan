////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MonitorEvent.hpp"

#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorEvent)

namespace yq::tachyon {
    
    MonitorEventInfo::MonitorEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
        set(Flag::COMMAND);
    }

    ////////////////////////////////////////////////////////////////////////////

    MonitorEvent::MonitorEvent(Monitor m) : m_monitor(m)
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
