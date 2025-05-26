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
#include <tachyon/api/Frame.hpp>
#include <tachyon/camera/SpaceCamera.hpp>
#include <tachyon/ui/UIWindow.hpp>
#include <tachyon/ui/UIWriters.hxx>
#include <ImGuiFileDialog.h>
#include <tachyon/ui/UIElementInfoWriter.hpp>
#include <tachyon/scene/HUDScene.hpp>
#include <tachyon/scene/BackgroundScene.hpp>
#include <tachyon/scene/ForegroundScene.hpp>
#include <tachyon/tweak/OriginCameraTweak.hpp>

YQ_TACHYON_IMPLEMENT(SceneEditor)


class SceneEditor::UIScenes : public UIWindow {
    YQ_OBJECT_DECLARE(UIScenes, UIWindow)
public:
    static void init_info()
    {
        auto w = writer<UIScenes>();
        w.description("Scene panel for the scene editor");
    }
    
    UIScenes(UIFlags flags={}) : UIWindow("Scenes", flags)
    {
    }
    
    UIScenes(const UIScenes& cp) : UIWindow(cp)
    {
        m_editor    = dynamic_cast<SceneEditor*>(widget());
        //  /opt/open_icons/icons/png/32x32/emblems/emblem-art.png 
    }
    

    void content()
    {
        UIWindow::content();
        
        
        if(!m_editor)
            return;
        
        
        
        
        if(ImGui::BeginTable("Table", 4)){
            ImGui::TableNextRow(ImGuiTableRowFlags_Headers);
            if(ImGui::TableNextColumn()){
                ImGui::Text("ID");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("Name");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("Type");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("Visible");
            }
        
            for(const Entry& e : m_editor->m_scenes){
                ImGui::TableNextRow();
                if(ImGui::TableNextColumn()){
                    ImGui::TextUnformatted(to_string_view(e.scene.id));
                }
                if(ImGui::TableNextColumn()){
                    ImGui::TextUnformatted(e.name);
                }
                if(ImGui::TableNextColumn()){
                    ImGui::TextUnformatted(e.info->stem());
                }
                ImGui::TableNextColumn();
            }
        
            ImGui::EndTable();
        }
    }
    
    UIScenes*  clone() const
    {
        return new UIScenes(*this);
    }
    
    SceneEditor*    m_editor    = nullptr;
};

YQ_OBJECT_IMPLEMENT(SceneEditor::UIScenes);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SceneEditor::EFlags       SceneEditor::flags_for(const SceneInfo& sc)
{
    EFlags  ret = {};
    if(sc.is_base(meta<HUDScene>()) || sc.is_this(meta<HUDScene>()))
        ret |= E::HUD;
    if(sc.is_base(meta<BackgroundScene>()) || sc.is_this(meta<BackgroundScene>()))
        ret |= E::OriginFix;
    if(sc.is_base(meta<ForegroundScene>()) || sc.is_this(meta<ForegroundScene>()))
        ret |= E::OriginFix;
    return ret;
}

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


    file.menuitem("Import", "Ctrl+O");
    file.menuitem("Export", "Ctrl+S");

    edit.menuitem("Copy", "Ctrl+C");
    edit.menuitem("Paste", "Ctrl+V");

    auto cscene     = edit.menu("Create Scene");
    cscene.menuitem("Background").action(&SceneEditor::cmd_new_back_scene);
    cscene.menuitem("Foreground").action(&SceneEditor::cmd_new_fore_scene);
    cscene.menuitem("HUD").action(&SceneEditor::cmd_new_hud_scene);
    cscene.menuitem("Simple").action(&SceneEditor::cmd_new_simple_scene);


    auto etb        = app.toolbar(EAST,  "east");
    etb.button("E");
    auto wtb        = app.toolbar(WEST,  "west");
    wtb.button("W");
    auto ntb        = app.toolbar(NORTH, "north");
    ntb.button("N");
    auto stb        = app.toolbar(SOUTH, "south");
    stb.button("S");
    
    auto scenepanel    = app << new UIScenes;
    view.menuitem("Scenes").action(VISIBLE, scenepanel);
    
    //auto hbx        = app.vbox();
    //auto h1         = hbx.window();
    //h1.height(200);
    //h1.label("Hello");
    //auto h2         = hbx.window();
    //h2.label("World");
    //auto h3         = hbx.window();
    //h3.label("Goodbye");
    
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SceneEditor::SceneEditor()
{
}

SceneEditor::~SceneEditor()
{
}

SceneEditor::Entry*                  SceneEditor::_add(const Scene& sc)
{
    Entry*  ret = entry(sc.id());
    if(ret)
        return ret;
        
    SceneID edit;       // used to preserve editing
    if(m_editing)
        edit        = m_editing -> scene;
        
    Entry   en;
    en.scene        = sc.id();
    en.info         = static_cast<const SceneInfo*>(&sc.metaInfo());
    en.name         = sc.name();
    if(en.name.empty())
        en.name     = std::string(en.info -> stem());
    en.flags        = flags_for(*en.info);
    m_scenes.push_back(en);

    if(edit){
        m_editing   = entry(edit);
    } else if(!m_editing)
        m_editing   = &m_scenes.back();
    return &m_scenes.back();
}

void    SceneEditor::_rebuild()
{
    static const CameraTweakCPtr        s_originFix = new OriginCameraTweak();
    
    //const Frame*    frame   = Frame::current();
    
    m_layers.clear();
    for(const Entry& e : m_scenes){
        if(e.flags(E::Invisible))
            continue;
        CLayer  lay;
        lay.scene   = e.scene;
        if(e.flags(E::HUD)){
            lay.camera  = m_camera.hud;
        } else
            lay.camera  = m_camera.space;
        if(e.flags(E::OriginFix))
            lay.tweaks.push_back(s_originFix);
        m_layers.push_back(lay);
    }
}

void    SceneEditor::create_scene(const SceneInfo&info)
{
    Scene*  sc  = Tachyon::create_on<Scene>(SIM, info);
    if(!sc)
        return;
    _add(*sc);
    _rebuild();
}

void    SceneEditor::cmd_new_back_scene()
{
    create_scene(meta<BackgroundScene>());
}

void    SceneEditor::cmd_new_fore_scene()
{
    create_scene(meta<ForegroundScene>());
}

void    SceneEditor::cmd_new_hud_scene()
{
    create_scene(meta<HUDScene>());
}

void    SceneEditor::cmd_new_simple_scene()
{
    create_scene(meta<SimpleScene>());
}

SceneEditor::Entry*                  SceneEditor::entry(SceneID sc)
{
    for(auto& e : m_scenes)
        if(e.scene == sc)
            return &e;
    return nullptr;
}

const SceneEditor::Entry*            SceneEditor::entry(SceneID sc) const
{
    for(auto& e : m_scenes)
        if(e.scene == sc)
            return &e;
    return nullptr;
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
        if(ImGui::MenuItem("Import", "Ctrl+O")){
            IGFD::FileDialogConfig config;
            config.path = ".";
            ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".tsx", config);        
        }
        if(ImGui::MenuItem("Export", "Ctrl+S")){
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

Execution   SceneEditor::setup(const Context&ctx) 
{
    if(!m_camera.space){
        m_camera.space  = Tachyon::create_on<SpaceCamera>(SIM) -> id();
    }
    if(!m_camera.hud){
        //  TODO
    }
    return Widget::setup(ctx);
}
