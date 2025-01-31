////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorCameras.hpp"
#include <yt/3D/Camera3.hpp>

namespace yq::tachyon {
    class FrameInspectorCamera³s : public FrameInspectorCameras  {
        YQ_TACHYON_DECLARE(FrameInspectorCamera³s, FrameInspectorCameras)
    public:
    
        FrameInspectorCamera³s() 
        {
        }
        
        ~FrameInspectorCamera³s()
        {
        }

        uint64_t    count() const override { return m_frame->count(CAMERA³); }

        virtual const char* name() const override { return "Camera³"; }
        
        using FrameInspectorCameras::render;
        
        void    render(ViContext&ctx) override
        {
            for(Camera³ID v : m_frame->ids(CAMERA³)){
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
