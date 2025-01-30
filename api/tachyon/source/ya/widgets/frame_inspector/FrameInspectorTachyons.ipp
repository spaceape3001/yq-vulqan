////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Tachyon.hpp>

namespace yq::tachyon {
    class FrameInspectorTachyons : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorTachyons, FrameInspectorPane)
    public:
    
        FrameInspectorTachyons() 
        {
        }
        
        ~FrameInspectorTachyons()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(TachyonID v : m_frame->ids(TACHYON)){
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
