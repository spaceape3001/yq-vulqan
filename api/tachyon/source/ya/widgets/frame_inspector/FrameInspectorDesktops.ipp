////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Desktop.hpp>

namespace yq::tachyon {
    class FrameInspectorDesktops : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorDesktops, FrameInspectorPane)
    public:
    
        FrameInspectorDesktops() 
        {
        }
        
        ~FrameInspectorDesktops()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(DesktopID v : m_frame->ids(DESKTOP)){
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
