////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Window.hpp>

namespace yq::tachyon {
    class FrameInspectorWindows : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorWindows, FrameInspectorPane)
    public:
    
        FrameInspectorWindows() 
        {
        }
        
        ~FrameInspectorWindows()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(WindowID v : m_frame->ids(WINDOW)){
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
