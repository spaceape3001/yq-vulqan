////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/sim/Spatial.hpp>

namespace yq::tachyon {
    class FrameInspectorSpatials : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorSpatials, FrameInspectorPane)
    public:
    
        FrameInspectorSpatials() 
        {
        }
        
        ~FrameInspectorSpatials()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(SpatialID v : m_frame->ids(SPATIAL)){
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
