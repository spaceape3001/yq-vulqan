////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/scene/Scene.hpp>

namespace yq::tachyon {
    class FrameInspectorScenes : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorScenes, FrameInspectorPane)
    public:
    
        FrameInspectorScenes() 
        {
        }
        
        ~FrameInspectorScenes()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(SceneID v : m_frame->ids(SCENE)){
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
