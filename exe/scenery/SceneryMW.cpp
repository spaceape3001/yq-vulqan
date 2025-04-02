////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/application.hpp>
#include "SceneryMW.hpp"
#include <ya/widgets/AppWidgetInfoWriter.hpp>
#include <iostream>
#include <yt/ui/MyImGui.hpp>

YQ_TACHYON_IMPLEMENT(SceneryMW)

SceneryMW::SceneryMW()
{
}

SceneryMW::~SceneryMW()
{
}

void SceneryMW::menubar(ViContext&) 
{
    if(ImGui::BeginMenu("File")){
        ImGui::EndMenu();
    }
    if(ImGui::BeginMenu("Edit")){
        ImGui::EndMenu();
    }
    if(ImGui::BeginMenu("View")){
        ImGui::EndMenu();
    }
    if(ImGui::BeginMenu("Window")){
        ImGui::EndMenu();
    }
    if(ImGui::BeginMenu("Help")){
        ImGui::EndMenu();
    }
    if(ImGui::BeginMenu("Debug")){
        ImGui::EndMenu();
    }
}

void SceneryMW::init_info()
{
    auto w = writer<SceneryMW>();
    w.description("The main widget");
    w.imgui();
    w.menubar();
}
