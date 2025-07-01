////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/widget/ImGuiDemoWidget.hpp>
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/WidgetMetaWriter.hpp>

namespace yq::tachyon {
    ImGuiDemoWidget::ImGuiDemoWidget()
    {
    }
    
    ImGuiDemoWidget::~ImGuiDemoWidget()
    {
    }
    
    void    ImGuiDemoWidget::imgui(ViContext&) 
    {
        ImGui::ShowDemoWindow();
    }
    
    void ImGuiDemoWidget::init_meta()
    {
        auto w = writer<ImGuiDemoWidget>();
        w.description("Widget using the imgui demo");
        w.imgui();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::ImGuiDemoWidget)
