////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/scene/Scene.hpp>

namespace yq::tachyon {
    class FrameInspectorScenes : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorScenes, FrameInspectorTachyons)
    public:
    
        FrameInspectorScenes() 
        {
        }
        
        ~FrameInspectorScenes()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(SCENE); }
        virtual const char* name() const override { return "Scene"; }

        using FrameInspectorTachyons::render;

        void    render(ViContext&ctx) override
        {
            for(SceneID v : m_frame->ids(SCENE)){
                if(begin(v)){
                    render(TACHYON);
                    end();
                }
            }
        }

        static void init_info()
        {
        }
    };
}
