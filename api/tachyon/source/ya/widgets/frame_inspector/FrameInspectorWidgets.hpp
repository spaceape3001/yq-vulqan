////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/ui/Widget.hpp>

namespace yq::tachyon {
    class FrameInspectorWidgets : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorWidgets, FrameInspectorTachyons)
    public:
    
        FrameInspectorWidgets() 
        {
        }
        
        ~FrameInspectorWidgets()
        {
        }

        uint64_t    count() const override { return m_frame->count(WIDGET); }
        virtual const char* name() const override { return "Widget"; }

        using FrameInspectorTachyons::render;
        
        void    render(widget_k)
        {
        }
        
        void    render(ViContext&ctx) override
        {
            for(WidgetID v : m_frame->ids(WIDGET)){
                if(!begin(v))
                    continue;
                render(WIDGET);
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
