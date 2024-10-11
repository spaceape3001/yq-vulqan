////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ImGuiDemoWidget.hpp"
#include <yq-vulqan/imgui/MyImGui.hpp>

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
    
    namespace {
        void reg_imgui_demo()
        {
            auto w = writer<ImGuiDemoWidget>();
            w.imgui();
        }
        YQ_INVOKE(reg_imgui_demo();)
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::ImGuiDemoWidget)
