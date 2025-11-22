////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorCameras.hpp"
#include <yq/tachyon/api/Camera3.hpp>
#include <yq/tachyon/api/Camera3Data.hpp>
#include <yq/tachyon/api/Spatial3.hpp>

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
        
        void    render(camera³_k)
        {
            const Camera³Snap*  snap    = static_cast<const Camera³Snap*>(m_snap);
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> CAMERA³ PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Projection");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text(snap->projection);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Screen");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text(snap->screen);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Spatial");
            }
            if(ImGui::TableNextColumn()){
                meta_id(snap->spatial);
            }

            //ImGui::TableNextRow();
            //if(ImGui::TableNextColumn()){
                //ImGui::TextUnformatted("View");
            //}
            //if(ImGui::TableNextColumn()){
                //ImGui::Text(snap->view);
            //}
        }
        
        void    render(ViContext&ctx) override
        {
            for(Camera³ID v : m_frame->ids(CAMERA³)){
                if(!begin(v))
                    continue;
                    
                render(CAMERA³);
                separator();
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
