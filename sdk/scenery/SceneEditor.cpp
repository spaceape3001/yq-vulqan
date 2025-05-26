////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneEditor.hpp"

#include <tachyon/application.hpp>
#include <tachyon/MyImGui.hpp>

#include <tachyon/api/Frame.hpp>

#include <tachyon/camera/SpaceCamera.hpp>
#include <tachyon/gfx/Texture.hpp>

#include <tachyon/request/app/OpenFileRequest.hpp>

#include <tachyon/scene/HUDScene.hpp>
#include <tachyon/scene/BackgroundScene.hpp>
#include <tachyon/scene/ForegroundScene.hpp>

#include <tachyon/tweak/OriginCameraTweak.hpp>

#include <tachyon/ui/UIStyle.hpp>
#include <tachyon/ui/UIWindow.hpp>
#include <tachyon/ui/UIWriters.hxx>
#include <tachyon/ui/UIElementInfoWriter.hpp>

#include <tachyon/widget/AppWidgetInfoWriter.hpp>

#include <ImGuiFileDialog.h>

#include <iostream>


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class SceneEditor::UIScenes : public UIElement {
    YQ_OBJECT_DECLARE(UIScenes, UIElement)
public:

    static void init_info()
    {
        auto w = writer<UIScenes>();
        w.description("Scene Editor's Scene Table");
    }

    UIScenes(UIFlags flags={}) : UIElement(flags)
    {
    }
    
    UIScenes(const UIScenes& cp) : UIElement(cp)
    {
    }
    
    virtual UIScenes*   clone() const 
    {
        return new UIScenes(*this);
    }
    
    void    render() override
    {
        UIElement::render();
        
        float   sz  = ImGui::GetFrameHeight() * 0.9;
        
        Size2F      imgBtnSize    = { sz, sz };
        
        if(!m_invisible)
            m_invisible = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-p000-general.png"));
        if(!m_editing)
            m_editing   = install(texture("openicon/icons/png/32x32/symbols/pictogram-din-e001-direction-right.png"));
        if(!m_visible)
            m_visible   = install(texture("sdk/scenery/eyeball48.png"));
        
        SceneEditor*    editor  = dynamic_cast<SceneEditor*>(widget());
        if(!editor)
            return ;
            
        if(ImGui::BeginTable("Scenes", 4)){
            ImGui::TableNextRow(ImGuiTableRowFlags_Headers);
            ImGui::TableNextColumn();
            ImGui::TableNextColumn();
            if(ImGui::TableNextColumn()){
                ImGui::Text("Name");
            }
            if(ImGui::TableNextColumn()){
                ImGui::Text("Type");
            }

            for(Entry& e : editor->m_scenes){
                ImGui::TableNextRow();
                if(ImGui::TableNextColumn()){
                    if(&e == editor->m_editing){
                        if(m_editing){
                            ImGui::Image(m_editing, imgBtnSize);
                        } else {
                            ImGui::TextUnformatted("E");
                        }
                    } else {
                        if(e.flags(E::Invisible)){
                            if(m_invisible ? ImGui::ImageButton(e.invisBtn.c_str(), m_invisible, imgBtnSize) : ImGui::Button(e.invisBtn2.c_str())){
                                e.flags -= E::Invisible;
                                editor->m_flags |= F::Stale;
                            }
                        } else {
                            if(m_visible ? ImGui::ImageButton(e.visBtn.c_str(), m_visible, imgBtnSize) : ImGui::Button(e.visBtn2.c_str())){
                                e.flags |= E::Invisible;
                                editor->m_flags |= F::Stale;
                            }
                        }
                    }
                }
                
                if(ImGui::TableNextColumn()){
                    if(&e == editor->m_editing){
                        ImGui::TextUnformatted(to_string_view(e.scene.id));
                    } else {
                        if(ImGui::Button(e.editBtn.c_str())){
                            if(e.flags(E::Invisible)){
                                e.flags -= E::Invisible;
                                editor->m_flags |= F::Stale;
                            }
                            editor->m_editing = &e;
                        }
                    }
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
    
    void    header()
    {
    }
    
    void    row(const Entry& e)
    {
   }
   
   ImTextureID      m_invisible;
   ImTextureID      m_visible;
   ImTextureID      m_editing;
};

YQ_OBJECT_IMPLEMENT(SceneEditor::UIScenes)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


YQ_TACHYON_IMPLEMENT(SceneEditor)

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


    file.menuitem("Import", "Ctrl+O").action(&SceneEditor::cmd_file_import);
    file.menuitem("Export", "Ctrl+S").action(&SceneEditor::cmd_file_export);

    edit.menuitem("Copy", "Ctrl+C");
    edit.menuitem("Paste", "Ctrl+V");

    auto cscene     = edit.menu("Create Scene");
    cscene.menuitem("Background").action(&SceneEditor::cmd_new_back_scene);
    cscene.menuitem("Foreground").action(&SceneEditor::cmd_new_fore_scene);
    // cscene.menuitem("HUD").action(&SceneEditor::cmd_new_hud_scene);
    cscene.menuitem("Simple").action(&SceneEditor::cmd_new_simple_scene);


    auto etb        = app.toolbar(EAST,  "east");
    etb.button("E");
    auto wtb        = app.toolbar(WEST,  "west");
    wtb.button("W");
    auto ntb        = app.toolbar(NORTH, "north");
    ntb.button("N");
    auto stb        = app.toolbar(SOUTH, "south");
    stb.button("S");
    
    
    auto scenepanel    = app.window("Scenes");
    scenepanel.flags(SET, { UIFlag::AlwaysAutoResize });
    scenepanel << new UIScenes;

    view.menuitem("Scenes").action(VISIBLE, scenepanel);
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
    Entry*  ret = _entry(sc.id());
    if(ret)
        return ret;
        
    SceneID edit;       // used to preserve editing
    if(m_editing)
        edit        = m_editing -> scene;
        
    Entry   en;
    en.scene        = sc.id();
    en.visBtn       = std::format("{}##VISIBLE{}", en.scene.id, en.scene.id);
    en.visBtn2      = std::format("V##VISIBLE{}", en.scene.id);
    en.invisBtn     = std::format("{}##INVISIBLE{}", en.scene.id, en.scene.id);
    en.invisBtn2    = std::format("I##INVISIBLE{}", en.scene.id);
    en.editBtn      = std::format("{}##EDIT{}", en.scene.id, en.scene.id);
    en.info         = static_cast<const SceneInfo*>(&sc.metaInfo());
    en.name         = sc.name();
    if(en.name.empty())
        en.name     = std::string(en.info -> stem());
    en.flags        = flags_for(*en.info);
    m_scenes.push_back(en);

    if(edit){
        m_editing   = _entry(edit);
    } else if(!m_editing)
        m_editing   = &m_scenes.back();
        
    m_flags |= F::Stale;
    return &m_scenes.back();
}

SceneEditor::Entry*                  SceneEditor::_entry(SceneID sc)
{
    for(auto& e : m_scenes)
        if(e.scene == sc)
            return &e;
    return nullptr;
}

const SceneEditor::Entry*            SceneEditor::_entry(SceneID sc) const
{
    for(auto& e : m_scenes)
        if(e.scene == sc)
            return &e;
    return nullptr;
}

void    SceneEditor::_rebuild()
{
    static const CameraTweakCPtr        s_originFix = new OriginCameraTweak();
    
    //const Frame*    frame   = Frame::current();
    
    m_layers.clear();
    for(const Entry& e : m_scenes){
        if(e.flags(E::Invisible) && (m_editing != &e))
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
    m_flags -= F::Stale;
}

void    SceneEditor::create_scene(const SceneInfo&info)
{
    Scene*  sc  = Tachyon::create_on<Scene>(SIM, info);
    if(!sc)
        return;
    _add(*sc);
}

void    SceneEditor::cmd_export(std::string_view fp)
{
    tachyonInfo << "TODO exporting (" << fp << ")";
}

void    SceneEditor::cmd_import(std::string_view fp)
{
    tachyonInfo << "TODO importing (" << fp << ")";
}

void    SceneEditor::cmd_file_export()
{
    IGFD::FileDialogConfig config;
    config.path = ".";
    config.flags |= ImGuiFileDialogFlags_ConfirmOverwrite;
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File to Save", ".tsx", config);        
    m_fileMode  = FileMode::Export;
}

void    SceneEditor::cmd_file_import()
{
    IGFD::FileDialogConfig config;
    config.path = ".";
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File to Open", ".tsx", config);        
    m_fileMode  = FileMode::Import;
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

void    SceneEditor::imgui(ViContext&u) 
{
    Widget::imgui(UI,u);
    

    if(m_fileMode != FileMode::None){
        ImVec2  minSize = { (float)(0.5 * width()), (float)(0.5 * height()) };
        if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey", ImGuiWindowFlags_NoCollapse, minSize)) {
            if (ImGuiFileDialog::Instance()->IsOk()) { // action if OK
                std::string filePathName = ImGuiFileDialog::Instance()->GetFilePathName();
                std::string filePath = ImGuiFileDialog::Instance()->GetCurrentPath();
                
                switch(m_fileMode){
                case FileMode::None:
                    break;
                case FileMode::Import:
                    cmd_import(filePathName);
                    break;
                case FileMode::Export:
                    cmd_export(filePathName);
                    break;
                }
            }
            ImGuiFileDialog::Instance()->Close();
        }
    }
}

void    SceneEditor::prerecord(ViContext&u) 
{
    if(m_flags(F::Stale))
        _rebuild();
    CompositeWidget::prerecord(u);
}

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


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    aci.thread.sim        = true;
    aci.view.title        = "Scenery Editor";
    aci.view.size         = { 1920, 1080 };
    aci.view.clear        = { 0.0f, 0.0f, 0.0f, 1.f };
    aci.view.imgui        = true;
    aci.view.resizable    = true;
    
    Application app(argc, argv, aci);
    app.start();
    
    SceneEditor*     w   = Widget::create<SceneEditor>();
    app.run(w);
    return 0;
}

