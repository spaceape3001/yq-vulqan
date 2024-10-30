////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/events/MonitorEvent.hpp>

namespace yq::tachyon {
    class MonitorDisconnectEvent : public MonitorEvent {
        YQ_OBJECT_DECLARE(MonitorDisconnectEvent, MonitorEvent);
    public:
        static void init_info();
    
    
        struct Param : public MonitorEvent::Param {
        };
    
        MonitorDisconnectEvent(Monitor, const Param& p = {});
        ~MonitorDisconnectEvent();
    };
}
