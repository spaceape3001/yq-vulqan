////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Manager.hpp>

namespace yq::tachyon {
    class FrameInspectorManagers : public FrameInspectorPane {
        YQ_TACHYON_DECLARE(FrameInspectorManagers, FrameInspectorPane)
    public:
    
        FrameInspectorManagers() 
        {
        }
        
        ~FrameInspectorManagers()
        {
        }
        
        void    imgui(ViContext&ctx) override
        {
            if(!m_frame)
                return ;

            for(ManagerID v : m_frame->ids(MANAGER)){
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
