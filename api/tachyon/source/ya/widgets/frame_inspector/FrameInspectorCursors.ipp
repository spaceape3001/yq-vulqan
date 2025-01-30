////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Cursor.hpp>

namespace yq::tachyon {
    class FrameInspectorCursors : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorCursors, FrameInspectorPane)
    public:
    
        FrameInspectorCursors() 
        {
        }
        
        ~FrameInspectorCursors()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(CursorID v : m_frame->ids(CURSOR)){
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
