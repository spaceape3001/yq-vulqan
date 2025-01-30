////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Mouse.hpp>

namespace yq::tachyon {
    class FrameInspectorMouses : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorMouses, FrameInspectorPane)
    public:
    
        FrameInspectorMouses() 
        {
        }
        
        ~FrameInspectorMouses()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(MouseID v : m_frame->ids(MOUSE)){
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
