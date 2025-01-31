////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/scene/Rendered.hpp>

namespace yq::tachyon {
    class FrameInspectorRendereds : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorRendereds, FrameInspectorTachyons)
    public:
    
        FrameInspectorRendereds() 
        {
        }
        
        ~FrameInspectorRendereds()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(RENDERED); }
        virtual const char* name() const override { return "Rendered"; }

        using FrameInspectorTachyons::render;

        void    render(ViContext&ctx) override
        {
            for(RenderedID v : m_frame->ids(RENDERED)){
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
