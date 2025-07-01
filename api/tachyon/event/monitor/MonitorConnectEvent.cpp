////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/monitor/MonitorConnectEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {
    void MonitorConnectEvent::init_meta()
    {
        auto w = writer<MonitorConnectEvent>();
        w.description("Monitor Connection Event");
    }

    MonitorConnectEvent::MonitorConnectEvent(const Header&h) : MonitorEvent(h)
    {
    }
    
    MonitorConnectEvent::MonitorConnectEvent(const MonitorConnectEvent& cp, const Header&h) : MonitorEvent(cp, h)
    {
    }
    
    MonitorConnectEvent::~MonitorConnectEvent()
    {
    }

    PostCPtr    MonitorConnectEvent::clone(rebind_k, const Header&h) const 
    {
        return new MonitorConnectEvent(*this, h);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorConnectEvent)
