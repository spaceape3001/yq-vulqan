////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "FrameInspectorTachyons.hpp"
#include <yq/tachyon/app/Viewer.hpp>
#include <yq/tachyon/app/ViewerData.hpp>
#include <yq/tachyon/im/text.hpp>
#include <yq/text/format.hpp>

namespace yq::tachyon {
    class FrameInspectorViewers : public FrameInspectorTachyons {
        YQ_TACHYON_DECLARE(FrameInspectorViewers, FrameInspectorTachyons)
    public:
    
        FrameInspectorViewers() 
        {
        }
        
        ~FrameInspectorViewers()
        {
        }
        
        uint64_t    count() const override { return m_frame->count(VIEWER); }
        virtual const char* name() const override { return "Viewer"; }

        using FrameInspectorTachyons::render;

        void    render(viewer_k)
        {
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("------");
            }
            if(ImGui::TableNextColumn()){
                im::text(">>> VIEWER PROPERTIES <<<");
            }

            const ViewerSnap*   snap    = static_cast<const ViewerSnap*>(m_snap);
            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Focus");
            }
            if(ImGui::TableNextColumn()){
                meta_id(snap->focus);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Widget");
            }
            if(ImGui::TableNextColumn()){
                meta_id(snap->widget);
            }

            ImGui::TableNextRow();
            if(ImGui::TableNextColumn()){
                im::text("Window");
            }
            if(ImGui::TableNextColumn()){
                meta_id(snap->window);
            }
        }

        void    render(ViContext&ctx) override
        {
            for(ViewerID v : m_frame->ids(VIEWER)){
                if(!begin(v))
                    continue;

                render(VIEWER);
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
