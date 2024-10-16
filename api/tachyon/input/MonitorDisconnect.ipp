////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MonitorDisconnect.hpp"
#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void MonitorDisconnect::init_info()
    {
        auto w = writer<MonitorDisconnect>();
        w.description("Monitor Disconnection Event");
    }

    MonitorDisconnect::MonitorDisconnect(Monitor m) : MonitorEvent(m)
    {
    }
    
    MonitorDisconnect::~MonitorDisconnect()
    {
    }
    
    YQ_INVOKE(MonitorDisconnect::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorDisconnect)
