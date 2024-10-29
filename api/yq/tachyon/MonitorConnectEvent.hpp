////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/MonitorEvent.hpp>

namespace yq::tachyon {
    class MonitorConnectEvent : public MonitorEvent {
        YQ_OBJECT_DECLARE(MonitorConnectEvent, MonitorEvent);
    public:
        static void init_info();
        
        struct Param : public MonitorEvent::Param {
        };
    
        MonitorConnectEvent(Monitor, const Param& p={});
        ~MonitorConnectEvent();
    };
}
