////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Joystick.hpp>

namespace yq::tachyon {
    class FrameInspectorJoysticks : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorJoysticks, FrameInspectorPane)
    public:
    
        FrameInspectorJoysticks() 
        {
        }
        
        ~FrameInspectorJoysticks()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(JoystickID v : m_frame->ids(JOYSTICK)){
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
