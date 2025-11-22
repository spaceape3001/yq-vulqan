////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/os/GraphicsCard.hpp>
#include <yq/tachyon/os/GraphicsCardData.hpp>

namespace yq::tachyon {
    class FrameInspectorGraphicsCards : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorGraphicsCards, FrameInspectorTachyons)
    public:
    
        FrameInspectorGraphicsCards() 
        {
        }
        
        ~FrameInspectorGraphicsCards()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(GRAPHICS_CARD); }
        virtual const char* name() const override { return "GPU"; }

        using FrameInspectorTachyons::render;

        void    render(graphics_card_k)
        {
            const GraphicsCardSnap* snap = static_cast<const GraphicsCardSnap*>(m_snap);
        
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> GPU PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Heap");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text(snap->heap);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Name");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(snap->name);
            }
        }

        void    render(ViContext&ctx) override
        {
            for(GraphicsCardID v : m_frame->ids(GRAPHICS_CARD)){
                if(!begin(v))
                    continue;
                render(GRAPHICS_CARD);
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
