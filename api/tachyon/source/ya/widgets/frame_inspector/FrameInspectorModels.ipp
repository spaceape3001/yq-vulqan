////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/sim/Model.hpp>

namespace yq::tachyon {
    class FrameInspectorModels : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorModels, FrameInspectorPane)
    public:
    
        FrameInspectorModels() 
        {
        }
        
        ~FrameInspectorModels()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(ModelID v : m_frame->ids(MODEL)){
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
