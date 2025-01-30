////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/scene/Rendered.hpp>

namespace yq::tachyon {
    class FrameInspectorRendereds : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorRendereds, FrameInspectorPane)
    public:
    
        FrameInspectorRendereds() 
        {
        }
        
        ~FrameInspectorRendereds()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(RenderedID v : m_frame->ids(RENDERED)){
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
