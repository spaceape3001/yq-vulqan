////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/api/WidgetData.hpp>
#include <yq/tachyon/im/text.hpp>

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
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> WIDGET PROPERTIES <<<");
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Viewer");
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

        static void init_meta()
        {
        }
    };
}
