////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/im/text.hpp>

namespace yq::tachyon {
    class FrameInspectorHeader : public Widget, public FrameInspector::Pane {
        YQ_TACHYON_DECLARE(FrameInspectorHeader, Widget)
    public:
        FrameInspectorHeader() 
        {
        }
        
        ~FrameInspectorHeader()
        {
        }
        
        const char* name() const override
        {
            return "Header";
        }

        static void init_meta()
        {
        }
        
        void    render(ViContext&ctx) override
        {
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            im::text("Number");
            ImGui::TableNextColumn();
            im::text(m_frame->number());
        
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            im::text("Tick");
            ImGui::TableNextColumn();
            im::text(m_frame->tick());

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            im::text("Origin");
            ImGui::TableNextColumn();
            im::text(m_frame->origin().id);

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            im::text("Time");
            ImGui::TableNextColumn();
            im::text(m_frame->time().value);
        }
        
    private:
        bool            m_init = false;
    };
}
