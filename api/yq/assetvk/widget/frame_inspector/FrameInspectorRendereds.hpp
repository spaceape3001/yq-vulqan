////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/im/text.hpp>

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
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> RENDERED PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Culled");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->culled.key());
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("IBO");
            }
            if(ImGui::TableNextColumn()){
                bool    has = !std::get_if<std::monostate>(&snap->ibo);
                im::text( has ? "YES" : " NO");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("SBOs");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->sbos.size());
            }
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Textures");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->texs.size());
            }
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("UBOs");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->ubos.size());
            }
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("VBOs");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->vbos.size());
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Wireframe");
            }
            if(ImGui::TableNextColumn()){
                im::text(snap->wireframe.key());
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
