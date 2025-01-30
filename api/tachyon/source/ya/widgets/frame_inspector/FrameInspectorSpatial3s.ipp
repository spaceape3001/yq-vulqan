////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Spatial3.hpp>

namespace yq::tachyon {
    class FrameInspectorSpatial³s : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorSpatial³s, FrameInspectorPane)
    public:
    
        FrameInspectorSpatial³s() 
        {
        }
        
        ~FrameInspectorSpatial³s()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(Spatial³ID v : m_frame->ids(SPATIAL³)){
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
