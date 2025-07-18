////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/MonitorEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

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

    void MonitorEvent::init_meta()
    {
        auto w = writer<MonitorEvent>();
        w.description("Monitor event base class");
    }
}
