////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/app/Viewer.hpp>
#include <yq/text/format.hpp>

namespace yq::tachyon {
    class FrameInspectorViewers : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorViewers, FrameInspectorTachyons)
    public:
    
        FrameInspectorViewers() 
        {
        }
        
        ~FrameInspectorViewers()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(VIEWER); }
        virtual const char* name() const override { return "Viewer"; }

        using FrameInspectorTachyons::render;

        void    render(viewer_k)
        {
        }

        void    render(ViContext&ctx) override
        {
            for(ViewerID v : m_frame->ids(VIEWER)){
                if(!begin(v))
                    continue;

                render(VIEWER);
                separator();
                render(TACHYON);
                end();
            }
        }

        static void init_info()
        {
        }
    };
}
