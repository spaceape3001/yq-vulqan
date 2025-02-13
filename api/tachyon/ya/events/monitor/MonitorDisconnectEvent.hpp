////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/events/MonitorEvent.hpp>

namespace yq::tachyon {
    class MonitorDisconnectEvent : public MonitorEvent {
        YQ_OBJECT_DECLARE(MonitorDisconnectEvent, MonitorEvent);
    public:
        static void init_info();
    
        MonitorDisconnectEvent(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MonitorDisconnectEvent(const MonitorDisconnectEvent&, const Header&);
        virtual ~MonitorDisconnectEvent();

    private:
        MonitorDisconnectEvent(const MonitorDisconnectEvent&) = delete;
        MonitorDisconnectEvent(MonitorDisconnectEvent&&) = delete;
        MonitorDisconnectEvent& operator=(const MonitorDisconnectEvent&) = delete;
        MonitorDisconnectEvent& operator=(MonitorDisconnectEvent&&) = delete;
    };
}
