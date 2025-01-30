////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/scene/Light.hpp>

namespace yq::tachyon {
    class FrameInspectorLights : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorLights, FrameInspectorPane)
    public:
    
        FrameInspectorLights() 
        {
        }
        
        ~FrameInspectorLights()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(LightID v : m_frame->ids(LIGHT)){
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
