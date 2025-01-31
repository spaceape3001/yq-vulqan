////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/os/Monitor.hpp>

namespace yq::tachyon {
    class FrameInspectorMonitors : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorMonitors, FrameInspectorTachyons)
    public:
    
        FrameInspectorMonitors() 
        {
        }
        
        ~FrameInspectorMonitors()
        {
        }

        uint64_t    count() const override { return m_frame->count(MONITOR); }
        virtual const char* name() const override { return "Monitor"; }
        
        using FrameInspectorTachyons::render;

        void    render(monitor_k)
        {
        }

        void   render(ViContext&ctx) override
        {
            for(MonitorID v : m_frame->ids(MONITOR)){
                if(!begin(v))
                    continue;
                render(MONITOR);
                separator();
                render(TACHYON);
                end();
            }
        }

        static void init_info()
        {
        }
    };
}
