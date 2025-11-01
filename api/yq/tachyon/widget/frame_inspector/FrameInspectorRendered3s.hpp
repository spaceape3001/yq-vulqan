////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorRendereds.hpp"
#include <tachyon/api/Rendered3.hpp>
#include <tachyon/api/Rendered3Data.hpp>
#include <tachyon/api/Spatial.hpp>

namespace yq::tachyon {
    class FrameInspectorRendered³s : public FrameInspectorRendereds {
        YQ_TACHYON_DECLARE(FrameInspectorRendered³s, FrameInspectorRendereds)
    public:
    
        FrameInspectorRendered³s() 
        {
        }
        
        ~FrameInspectorRendered³s()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(RENDERED³); }
        virtual const char* name() const override { return "Rendered³"; }

        using FrameInspectorRendereds::render;
        
        void    render(rendered³_k)
        {
            const Rendered³Snap *snap = static_cast<const Rendered³Snap*>(m_snap);
        
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> RENDERED³ PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Spatial");
            }
            if(ImGui::TableNextColumn()){
                meta_id(snap->spatial);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("VM Override");
            }
            if(ImGui::TableNextColumn()){
                if(!snap->vm_override){
                    ImGui::TextUnformatted("(disabled)");
                } else {
                    ImGui::Text(snap->vm_tensor);
                }
            }
        }

        void    render(ViContext&ctx) override
        {
            for(Rendered³ID v : m_frame->ids(RENDERED³)){
                if(!begin(v))
                    continue;
                render(RENDERED³);
                separator();
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
