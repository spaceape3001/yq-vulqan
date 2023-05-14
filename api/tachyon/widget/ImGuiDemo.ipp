////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/widget/ImGuiDemo.hpp>
#include <tachyon/imgui/MyImGui.hpp>

namespace yq::tachyon {
    ImGuiDemo::ImGuiDemo()
    {
    }
    
    ImGuiDemo::~ImGuiDemo()
    {
    }
    
    void    ImGuiDemo::imgui_(ViContext&) 
    {
        ImGui::ShowDemoWindow();
    }
    
    namespace {
        void reg_imgui_demo()
        {
            auto w = writer<ImGuiDemo>();
            w.imgui();
        }
        YQ_INVOKE(reg_imgui_demo();)
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::ImGuiDemo)
