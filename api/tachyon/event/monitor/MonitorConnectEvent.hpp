////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/event/MonitorEvent.hpp>

namespace yq::tachyon {
    class MonitorConnectEvent : public MonitorEvent {
        YQ_OBJECT_DECLARE(MonitorConnectEvent, MonitorEvent);
    public:
        static void init_info();
        
        MonitorConnectEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MonitorConnectEvent(const MonitorConnectEvent&, const Header&);
        ~MonitorConnectEvent();
    
    private:
        MonitorConnectEvent(const MonitorConnectEvent&) = delete;
        MonitorConnectEvent(MonitorConnectEvent&&) = delete;
        MonitorConnectEvent& operator=(const MonitorConnectEvent&) = delete;
        MonitorConnectEvent& operator=(MonitorConnectEvent&&) = delete;
    };
}
