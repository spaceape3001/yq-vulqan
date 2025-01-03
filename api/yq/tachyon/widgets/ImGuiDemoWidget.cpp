////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ImGuiDemoWidget.hpp"
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>

namespace yq::tachyon {
    ImGuiDemoWidget::ImGuiDemoWidget()
    {
    }
    
    ImGuiDemoWidget::~ImGuiDemoWidget()
    {
    }
    
    void    ImGuiDemoWidget::imgui_(ViContext&) 
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
