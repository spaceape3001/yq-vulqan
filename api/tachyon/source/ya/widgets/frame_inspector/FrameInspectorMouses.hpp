////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/os/Mouse.hpp>

namespace yq::tachyon {
    class FrameInspectorMouses : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorMouses, FrameInspectorTachyons)
    public:
    
        FrameInspectorMouses() 
        {
        }
        
        ~FrameInspectorMouses()
        {
        }

        uint64_t    count() const override { return m_frame->count(MOUSE); }
        virtual const char* name() const override { return "Mouse"; }
        
        using FrameInspectorTachyons::render;
        
        void    render(mouse_k)
        {
        }
        
        void    render(ViContext&ctx) override
        {
            for(MouseID v : m_frame->ids(MOUSE)){
                if(!begin(v))
                    continue;
                render(MOUSE);
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
