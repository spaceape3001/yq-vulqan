////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Thread.hpp>

namespace yq::tachyon {
    class FrameInspectorThreads : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorThreads, FrameInspectorPane)
    public:
    
        FrameInspectorThreads() 
        {
        }
        
        ~FrameInspectorThreads()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(ThreadID v : m_frame->ids(THREAD)){
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
