////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/application.hpp>
#include "SceneEditor.hpp"
#include <tachyon/request/app/OpenFileRequest.hpp>
#include <tachyon/widget/AppWidgetInfoWriter.hpp>
#include <iostream>
#include <tachyon/MyImGui.hpp>
#include <tachyon/ui/UIWriters.hxx>
#include <ImGuiFileDialog.h>

YQ_TACHYON_IMPLEMENT(SceneEditor)

SceneEditor::SceneEditor()
{
}

SceneEditor::~SceneEditor()
{
}

void    SceneEditor::imgui(ViContext&u) 
{
    Widget::imgui(UI,u);
}

#if 0
void SceneEditor::content(ViContext& u) 
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

void SceneEditor::menubar(ViContext&u) 
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


void SceneEditor::init_info()
{
    auto w          = writer<SceneEditor>();
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

    auto etb        = app.buttonbar(EAST,  "east");
    etb.button("E");
    auto wtb        = app.buttonbar(WEST,  "west");
    wtb.button("W");
    auto ntb        = app.buttonbar(NORTH, "north");
    ntb.button("N");
    auto stb        = app.buttonbar(SOUTH, "south");
    stb.button("S");
    
    //auto hbx        = app.vbox();
    //auto h1         = hbx.window();
    //h1.height(200);
    //h1.label("Hello");
    //auto h2         = hbx.window();
    //h2.label("World");
    //auto h3         = hbx.window();
    //h3.label("Goodbye");
    
}
