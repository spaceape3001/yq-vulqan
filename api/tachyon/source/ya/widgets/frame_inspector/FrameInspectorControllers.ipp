////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Controller.hpp>

namespace yq::tachyon {
    class FrameInspectorControllers : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorControllers, FrameInspectorPane)
    public:
    
        FrameInspectorControllers() 
        {
        }
        
        ~FrameInspectorControllers()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(ControllerID v : m_frame->ids(CONTROLLER)){
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
