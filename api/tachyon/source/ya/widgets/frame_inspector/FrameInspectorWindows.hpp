////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/os/Window.hpp>

namespace yq::tachyon {
    class FrameInspectorWindows : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorWindows, FrameInspectorTachyons)
    public:
    
        FrameInspectorWindows() 
        {
        }
        
        ~FrameInspectorWindows()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(WINDOW); }
        virtual const char* name() const override { return "Window"; }

        using FrameInspectorTachyons::render;
        
        void    render(ViContext&ctx) override
        {
            for(WindowID v : m_frame->ids(WINDOW)){
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
