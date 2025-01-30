////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/scene/Camera.hpp>

namespace yq::tachyon {
    class FrameInspectorCameras : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorCameras, FrameInspectorPane)
    public:
    
        FrameInspectorCameras() 
        {
        }
        
        ~FrameInspectorCameras()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(CameraID v : m_frame->ids(CAMERA)){
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
