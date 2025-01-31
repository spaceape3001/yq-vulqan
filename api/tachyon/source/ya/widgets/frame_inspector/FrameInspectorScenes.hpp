////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yt/scene/Scene.hpp>
#include <yt/scene/SceneData.hpp>

namespace yq::tachyon {
    class FrameInspectorScenes : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorScenes, FrameInspectorTachyons)
    public:
    
        FrameInspectorScenes() 
        {
        }
        
        ~FrameInspectorScenes()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(SCENE); }
        virtual const char* name() const override { return "Scene"; }

        using FrameInspectorTachyons::render;

        void    render(scene_k)
        {
            const SceneSnap*    snap    = static_cast<const SceneSnap*>(m_snap);
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> SCENE PROPERTIES <<<");
            }
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Cameras");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%ld", snap->cameras.size());
            }
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Lights");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%ld", snap->lights.size());
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Rendereds");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%ld", snap->rendereds.size());
            }
        }

        void    render(ViContext&ctx) override
        {
            for(SceneID v : m_frame->ids(SCENE)){
                if(!begin(v))
                    continue;
                render(SCENE);
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
