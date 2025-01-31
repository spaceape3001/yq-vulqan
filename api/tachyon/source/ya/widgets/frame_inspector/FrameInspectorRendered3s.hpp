////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorRendereds.hpp"
#include <yt/3D/Rendered3.hpp>

namespace yq::tachyon {
    class FrameInspectorRendered³s : public FrameInspectorRendereds {
        YQ_TACHYON_DECLARE(FrameInspectorRendered³s, FrameInspectorRendereds)
    public:
    
        FrameInspectorRendered³s() 
        {
        }
        
        ~FrameInspectorRendered³s()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(RENDERED³); }
        virtual const char* name() const override { return "Rendered³"; }

        using FrameInspectorRendereds::render;

        void    render(ViContext&ctx) override
        {
            for(Rendered³ID v : m_frame->ids(RENDERED³)){
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
