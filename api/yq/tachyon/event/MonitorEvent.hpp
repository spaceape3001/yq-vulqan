////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/typedef/monitor.hpp>

namespace yq::tachyon {
    class MonitorEvent : public Event {
        YQ_OBJECT_DECLARE(MonitorEvent, Event)
    public:
    
        static void init_meta();
    
    protected:
        MonitorEvent(const Header&);
        MonitorEvent(const MonitorEvent&, const Header&);
        virtual ~MonitorEvent();
        
    private:
        MonitorEvent(const MonitorEvent&);
        MonitorEvent(MonitorEvent&&);
        MonitorEvent& operator=(const MonitorEvent&);
        MonitorEvent& operator=(MonitorEvent&&);
    };
}
