////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/monitor.hpp>

namespace yq::tachyon {
    class Monitor;

    //! Utiltity to bind a viewer to the whatever...
    class MonitorBind {
    public:
        MonitorID    monitor() const { return m_monitor; }
        
    protected:
        MonitorBind(MonitorID v) : m_monitor(v) {}
        MonitorBind(const Monitor* v);
        virtual ~MonitorBind() {}
        
        MonitorID const m_monitor;
    };
}
