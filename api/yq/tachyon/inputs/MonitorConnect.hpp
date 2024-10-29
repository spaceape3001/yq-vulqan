////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/input/MonitorEvent.hpp>

namespace yq::tachyon {
    class MonitorConnect : public MonitorEvent {
        YQ_OBJECT_DECLARE(MonitorConnect, MonitorEvent);
    public:
        static void init_info();
        
        struct Param : public MonitorEvent::Param {
        };
    
        MonitorConnect(const Param&);
        ~MonitorConnect();
    };
}
