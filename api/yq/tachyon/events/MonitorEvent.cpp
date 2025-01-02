////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MonitorEvent.hpp"
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorEvent)

namespace yq::tachyon {
    
    MonitorEventInfo::MonitorEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
        set(Flag::MONITOR);
    }

    ////////////////////////////////////////////////////////////////////////////

    MonitorEvent::MonitorEvent(Monitor m, const Param& p) : Event(p), m_monitor(m)
    {
    }
    
    MonitorEvent::~MonitorEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MonitorEvent::init_info()
    {
        auto w = writer<MonitorEvent>();
        w.description("Monitor event base class");
    }
}
