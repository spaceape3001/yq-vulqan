////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/widget/ImGuiDemoWidget.hpp>
#include <tachyon/MyImGui.hpp>
#include <tachyon/api/WidgetInfoWriter.hpp>

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
    
    void ImGuiDemoWidget::init_info()
    {
        auto w = writer<ImGuiDemoWidget>();
        w.description("Widget using the imgui demo");
        w.imgui();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::ImGuiDemoWidget)
