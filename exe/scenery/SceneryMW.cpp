////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/application.hpp>
#include "SceneryMW.hpp"
#include <ya/requests/app/OpenFileRequest.hpp>
#include <ya/widgets/AppWidgetInfoWriter.hpp>
#include <iostream>
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/UIWriters.hxx>
#include <ImGuiFileDialog.h>

YQ_TACHYON_IMPLEMENT(SceneryMW)

SceneryMW::SceneryMW()
{
}

SceneryMW::~SceneryMW()
{
}

void    SceneryMW::imgui(ViContext&u) 
{
    Widget::imgui(UI,u);
}

#if 0
void SceneryMW::content(ViContext& u) 
{   
    if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey")) {
        if (ImGuiFileDialog::Instance()->IsOk()) { // action if OK
            std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
            std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
          // action
        }
        
        // close
        ImGuiFileDialog::Instance()->Close();
    }
}

void SceneryMW::menubar(ViContext&u) 
{
    if(ImGui::BeginMenu("File")){
        if(ImGui::MenuItem("Open", "Ctrl+O")){
            IGFD::FileDialogConfig config;
            config.path = ".";
            ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".cpp,.h,.hpp", config);        
        }
        if(ImGui::MenuItem("Save", "Ctrl+S")){
            //on_save_file(u);
        }
        ImGui::EndMenu();
    }
    if(ImGui::BeginMenu("Edit")){
        if(ImGui::MenuItem("Copy", "Ctrl+C")){
        }
        if(ImGui::MenuItem("Paste", "Ctrl+V")){
            
        }
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
#endif


void SceneryMW::init_info()
{
    auto w          = writer<SceneryMW>();
    w.description("The main widget");
    auto app        = w.imgui(UI, APP);
    
    auto mmb        = app.menubar(MAIN);
    mmb.uid("mmb");
    
    auto file       = mmb.menu("File");
    auto edit       = mmb.menu("Edit");
    auto view       = mmb.menu("View");
    auto window     = mmb.menu("Window");
    auto help       = mmb.menu("Help");
    auto debug      = mmb.menu("Debug");

    file.menuitem("Open", "Ctrl+O");
    file.menuitem("Save", "Ctrl+S");

    edit.menuitem("Copy", "Ctrl+C");
    edit.menuitem("Paste", "Ctrl+V");

    auto etb        = app.toolbar(EAST,  "east");
    auto wtb        = app.toolbar(WEST,  "west");
    auto ntb        = app.toolbar(NORTH, "north");
    auto stb        = app.toolbar(SOUTH, "south");
    
}
