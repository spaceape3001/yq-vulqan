////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/api/Controller.hpp>

namespace yq::tachyon {
    class FrameInspectorControllers : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorControllers, FrameInspectorTachyons)
    public:
    
        FrameInspectorControllers() 
        {
        }
        
        ~FrameInspectorControllers()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(CONTROLLER); }
        virtual const char* name() const override { return "Controller"; }

        using FrameInspectorTachyons::render;
        
        void    render(controller_k)
        {
        }

        void    render(ViContext&ctx) override
        {
            for(ControllerID v : m_frame->ids(CONTROLLER)){
                if(!begin(v))
                    continue;
                    
                render(CONTROLLER);
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
