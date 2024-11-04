////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MonitorConnectEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

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
