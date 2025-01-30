////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Rendered3.hpp>

namespace yq::tachyon {
    class FrameInspectorRendered³s : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorRendered³s, FrameInspectorPane)
    public:
    
        FrameInspectorRendered³s() 
        {
        }
        
        ~FrameInspectorRendered³s()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(Rendered³ID v : m_frame->ids(RENDERED³)){
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
