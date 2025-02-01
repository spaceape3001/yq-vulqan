////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/MonitorConnectEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

namespace yq::tachyon {
    void MonitorConnectEvent::init_info()
    {
        auto w = writer<MonitorConnectEvent>();
        w.description("Monitor Connection Event");
    }

    MonitorConnectEvent::MonitorConnectEvent(Monitor m, const Param& p) : MonitorEvent(m, p)
    {
    }
    
    MonitorConnectEvent::~MonitorConnectEvent()
    {
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorConnectEvent)
