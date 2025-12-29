////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorRendereds.hpp"
#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/api/Rendered3Data.hpp>
#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/im/text.hpp>

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
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> RENDERED³ PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Spatial");
            }
            if(ImGui::TableNextColumn()){
                meta_id(snap->spatial);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("VM Override");
            }
            if(ImGui::TableNextColumn()){
                if(!snap->vm_override){
                    im::text("(disabled)");
                } else {
                    im::text(snap->vm_tensor);
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
