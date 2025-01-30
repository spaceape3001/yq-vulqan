////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/app/Viewer.hpp>

namespace yq::tachyon {
    class FrameInspectorViewers : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorViewers, FrameInspectorPane)
    public:
    
        FrameInspectorViewers() 
        {
        }
        
        ~FrameInspectorViewers()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;
            for(ViewerID v : m_frame->ids(VIEWER)){
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
