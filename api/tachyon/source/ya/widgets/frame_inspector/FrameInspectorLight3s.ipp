////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Light3.hpp>

namespace yq::tachyon {
    class FrameInspectorLight³s : public FrameInspectorPane  {
        YQ_TACHYON_DECLARE(FrameInspectorLight³s, FrameInspectorPane)
    public:
    
        FrameInspectorLight³s() 
        {
        }
        
        ~FrameInspectorLight³s()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(Light³ID v : m_frame->ids(LIGHT³)){
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
