////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Camera3.hpp>

namespace yq::tachyon {
    class FrameInspectorCamera³s : public FrameInspectorPane  {
        YQ_TACHYON_DECLARE(FrameInspectorCamera³s, FrameInspectorPane)
    public:
    
        FrameInspectorCamera³s() 
        {
        }
        
        ~FrameInspectorCamera³s()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(Camera³ID v : m_frame->ids(CAMERA³)){
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
