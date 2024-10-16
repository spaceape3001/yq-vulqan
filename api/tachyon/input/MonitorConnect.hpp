////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/input/MonitorEvent.hpp>

namespace yq::tachyon {
    class MonitorConnect : public MonitorEvent {
        YQ_OBJECT_DECLARE(MonitorConnect, MonitorEvent);
    public:
        static void init_info();
    
        MonitorConnect(Monitor);
        ~MonitorConnect();
    };
}
