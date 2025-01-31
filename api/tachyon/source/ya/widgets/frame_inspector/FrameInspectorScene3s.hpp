////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorScenes.hpp"
#include <yt/3D/Scene3.hpp>

namespace yq::tachyon {
    class FrameInspectorScene³s : public FrameInspectorScenes {
        YQ_TACHYON_DECLARE(FrameInspectorScene³s, FrameInspectorScenes)
    public:
    
        FrameInspectorScene³s() 
        {
        }
        
        ~FrameInspectorScene³s()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(SCENE³); }
        virtual const char* name() const override { return "Scene³"; }

        using FrameInspectorScenes::render;
        
        void    render(ViContext&ctx) override
        {
            for(Scene³ID v : m_frame->ids(SCENE³)){
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
