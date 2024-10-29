////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/input/MonitorEvent.hpp>

namespace yq::tachyon {
    class MonitorDisconnect : public MonitorEvent {
        YQ_OBJECT_DECLARE(MonitorDisconnect, MonitorEvent);
    public:
        static void init_info();
    
    
        struct Param : public MonitorEvent::Param {
        };
    
        MonitorDisconnect(const Param& p);
        ~MonitorDisconnect();
    };
}
