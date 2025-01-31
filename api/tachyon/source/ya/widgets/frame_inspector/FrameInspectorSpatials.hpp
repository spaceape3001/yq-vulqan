////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/sim/Spatial.hpp>

namespace yq::tachyon {
    class FrameInspectorSpatials : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorSpatials, FrameInspectorTachyons)
    public:
    
        FrameInspectorSpatials() 
        {
        }
        
        ~FrameInspectorSpatials()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(SPATIAL); }
        virtual const char* name() const override { return "Spatial"; }

        using FrameInspectorTachyons::render;

        void    render(ViContext&ctx) override
        {
            for(SpatialID v : m_frame->ids(SPATIAL)){
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
