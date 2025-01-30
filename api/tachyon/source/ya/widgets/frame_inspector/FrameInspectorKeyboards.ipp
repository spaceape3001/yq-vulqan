////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Keyboard.hpp>

namespace yq::tachyon {
    class FrameInspectorKeyboards : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorKeyboards, FrameInspectorPane)
    public:
    
        FrameInspectorKeyboards() 
        {
        }
        
        ~FrameInspectorKeyboards()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(KeyboardID v : m_frame->ids(KEYBOARD)){
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
