////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MonitorEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorEvent)

namespace yq::tachyon {
    
    MonitorEventInfo::MonitorEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl) :
        post::EventInfo(zName, base, sl)
    {
        set(Flag::MONITOR);
    }

    ////////////////////////////////////////////////////////////////////////////

    MonitorEvent::MonitorEvent(Monitor m, const Param& p) : post::Event(p), m_monitor(m)
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
