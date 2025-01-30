////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Monitor.hpp>

namespace yq::tachyon {
    class FrameInspectorMonitors : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorMonitors, FrameInspectorPane)
    public:
    
        FrameInspectorMonitors() 
        {
        }
        
        ~FrameInspectorMonitors()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(MonitorID v : m_frame->ids(MONITOR)){
                if(begin(v)){
                    FrameInspectorPane::imgui(ctx);
                    end();
                }
            }
        }

        static void init_info()
        {
        }
    };
}
