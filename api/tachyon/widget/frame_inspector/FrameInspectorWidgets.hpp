////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <tachyon/api/Widget.hpp>
#include <tachyon/api/WidgetData.hpp>

namespace yq::tachyon {
    class FrameInspectorWidgets : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorWidgets, FrameInspectorTachyons)
    public:
    
        FrameInspectorWidgets() 
        {
        }
        
        ~FrameInspectorWidgets()
        {
        }

        uint64_t    count() const override { return m_frame->count(WIDGET); }
        virtual const char* name() const override { return "Widget"; }

        using FrameInspectorTachyons::render;
        
        void    render(widget_k)
        {
            const WidgetSnap*   snap    = static_cast<const WidgetSnap*>(m_snap);
            
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("------");
            }
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted(">>> WIDGET PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                ImGui::TextUnformatted("Viewer");
            }
            if(ImGui::TableNextColumn()){
                meta_id(snap->viewer);
            }
        }
        
        void    render(ViContext&ctx) override
        {
            for(WidgetID v : m_frame->ids(WIDGET)){
                if(!begin(v))
                    continue;
                render(WIDGET);
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
