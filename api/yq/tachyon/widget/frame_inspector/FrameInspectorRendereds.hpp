////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <tachyon/api/Rendered.hpp>
#include <tachyon/api/RenderedData.hpp>

namespace yq::tachyon {
    class FrameInspectorRendereds : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorRendereds, FrameInspectorTachyons)
    public:
    
        FrameInspectorRendereds() 
        {
        }
        
        ~FrameInspectorRendereds()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(RENDERED); }
        virtual const char* name() const override { return "Rendered"; }

        using FrameInspectorTachyons::render;

        void    render(rendered_k)
        {
            const RenderedSnap* snap    = static_cast<const RenderedSnap*>(m_snap);
        
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> RENDERED PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Culled");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(snap->culled.key());
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("IBOs");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%ld", snap->ibos.size());
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("SBOs");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%ld", snap->sbos.size());
            }
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Textures");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%ld", snap->texs.size());
            }
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("UBOs");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%ld", snap->ubos.size());
            }
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("VBOs");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("%ld", snap->vbos.size());
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Wireframe");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(snap->wireframe.key());
            }
        }

        void    render(ViContext&ctx) override
        {
            for(RenderedID v : m_frame->ids(RENDERED)){
                if(!begin(v))
                    continue;
                render(RENDERED);
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
