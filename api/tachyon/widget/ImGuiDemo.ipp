////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/widget/ImGuiDemo.hpp>
#include <tachyon/ui/MyImGui.hpp>

namespace yq {
    namespace tachyon {
        namespace widget {
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
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::widget::ImGuiDemo)
