////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Scene3.hpp>

namespace yq::tachyon {
    class FrameInspectorScene³s : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorScene³s, FrameInspectorPane)
    public:
    
        FrameInspectorScene³s() 
        {
        }
        
        ~FrameInspectorScene³s()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(Scene³ID v : m_frame->ids(SCENE³)){
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
