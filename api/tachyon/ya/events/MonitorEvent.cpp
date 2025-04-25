////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/MonitorEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorEvent)

namespace yq::tachyon {
    
    MonitorEvent::MonitorEvent(const Header& h) : Event(h)
    {
    }
    
    MonitorEvent::MonitorEvent(const MonitorEvent& cp, const Header& h) : Event(cp, h)
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
