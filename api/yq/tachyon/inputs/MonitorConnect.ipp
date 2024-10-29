////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MonitorConnect.hpp"
#include <yq/tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {
    void MonitorConnect::init_info()
    {
        auto w = writer<MonitorConnect>();
        w.description("Monitor Connection Event");
    }

    MonitorConnect::MonitorConnect(const Param& p) : MonitorEvent(p)
    {
    }
    
    MonitorConnect::~MonitorConnect()
    {
    }
    
    YQ_INVOKE(MonitorConnect::init_info();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MonitorConnect)
