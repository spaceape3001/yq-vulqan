////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Widget.hpp>

namespace yq::tachyon {
    class FrameInspectorWidgets : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorWidgets, FrameInspectorPane)
    public:
    
        FrameInspectorWidgets() 
        {
        }
        
        ~FrameInspectorWidgets()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(WidgetID v : m_frame->ids(WIDGET)){
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
