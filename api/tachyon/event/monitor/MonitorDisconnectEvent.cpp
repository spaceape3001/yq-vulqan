////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/monitor/MonitorDisconnectEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {
    void MonitorDisconnectEvent::init_info()
    {
        auto w = writer<MonitorDisconnectEvent>();
        w.description("Monitor Disconnection Event");
    }

    MonitorDisconnectEvent::MonitorDisconnectEvent(const Header&h) : MonitorEvent(h)
    {
    }
    
    MonitorDisconnectEvent::MonitorDisconnectEvent(const MonitorDisconnectEvent& cp, const Header&h) : MonitorEvent(cp, h)
    {
    }

    MonitorDisconnectEvent::~MonitorDisconnectEvent()
    {
    }

    PostCPtr    MonitorDisconnectEvent::clone(rebind_k, const Header&h) const
    {
        return new MonitorDisconnectEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorDisconnectEvent)
