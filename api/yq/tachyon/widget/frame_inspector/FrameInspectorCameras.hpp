////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/api/Camera.hpp>
#include <yq/tachyon/api/CameraData.hpp>

namespace yq::tachyon {
    class FrameInspectorCameras : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorCameras, FrameInspectorTachyons)
    public:
    
        FrameInspectorCameras() 
        {
        }
        
        ~FrameInspectorCameras()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(CAMERA); }
        virtual const char* name() const override { return "Camera"; }

        using FrameInspectorTachyons::render;
        
        void    render(camera_k)
        {
            //const CameraSnap* snap = static_cast<const CameraSnap*>(m_snap);
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> CAMERA PROPERTIES <<<");
            }
        }

        void    render(ViContext&ctx) override
        {
            for(CameraID v : m_frame->ids(CAMERA)){
                if(!begin(v))
                    continue;
                    
                render(CAMERA);
                separator();
                render(TACHYON);
                end();
            }
        }

        static void init_meta()
        {
        }
    };
}
