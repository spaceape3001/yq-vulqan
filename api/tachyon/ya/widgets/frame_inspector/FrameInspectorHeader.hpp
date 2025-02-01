////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

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

        static void init_info()
        {
        }
        
        void    render(ViContext&ctx) override
        {
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::TextUnformatted("Number");
            ImGui::TableNextColumn();
            ImGui::Text("%ld", m_frame->number());
        
            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::TextUnformatted("Tick");
            ImGui::TableNextColumn();
            ImGui::Text("%ld", m_frame->tick());

            ImGui::TableNextRow();
            ImGui::TableNextColumn();
            ImGui::TextUnformatted("Origin");
            ImGui::TableNextColumn();
            ImGui::Text("%ld", m_frame->origin().id);
        }
        
    private:
        bool            m_init = false;
    };
}
