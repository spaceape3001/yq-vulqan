////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/api/Scene.hpp>
#include <yq/tachyon/api/SceneData.hpp>

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
            
            table(NESTED, "Cameras", snap->cameras);
            table(NESTED, "Lights", snap->lights);
            table(NESTED, "Rendereds", snap->rendereds);
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

        static void init_meta()
        {
        }
    };
}
