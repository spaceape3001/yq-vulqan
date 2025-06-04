////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraEntry.hpp"
#include "CameraTableUI.hpp"
#include "ControlPanelUI.hpp"
#include "InspectorUI.hpp"
#include "SceneEditor.hpp"
#include "SceneEntry.hpp"
#include "SceneTableUI.hpp"

#include <tachyon/application.hpp>
#include <tachyon/MyImGui.hpp>

#include <tachyon/api/Camera.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/api/SceneData.hpp>
#include <tachyon/app/Viewer.hpp>

#include <tachyon/camera/SpaceCamera.hpp>
#include <tachyon/command/ui/TitleCommand.hpp>

#include <tachyon/event/panel/InfoSelectionChangedEvent.hpp>

#include <tachyon/gfx/Texture.hpp>

#include <tachyon/io/FileIOManager.hpp>

#include <tachyon/panel/UIBuildableInfoList.hpp>

#include <tachyon/request/app/OpenFileRequest.hpp>

#include <tachyon/reply/io/LoadTSXReply.hpp>
#include <tachyon/reply/io/SaveTSXReply.hpp>

#include <tachyon/request/io/LoadTSXRequest.hpp>
#include <tachyon/request/io/SaveTSXRequest.hpp>

#include <tachyon/scene/HUDScene.hpp>
#include <tachyon/scene/BackgroundScene.hpp>
#include <tachyon/scene/ForegroundScene.hpp>

#include <tachyon/tweak/OriginCameraTweak.hpp>

#include <tachyon/ui/UIMenuBar.hpp>
#include <tachyon/ui/UISection.hpp>
#include <tachyon/ui/UISimpleTree.hpp>
#include <tachyon/ui/UIStyle.hpp>
#include <tachyon/ui/UIWindow.hpp>
#include <tachyon/ui/UIWriters.hxx>
#include <tachyon/ui/UIElementInfoWriter.hpp>

#include <tachyon/widget/AppWidgetInfoWriter.hpp>

#include <yq/asset/Asset.hpp>
#include <yq/file/FileResolver.hpp>

#include <ImGuiFileDialog.h>

#include <iostream>


TypedID     gFileIO;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////



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
    
    w.slot(&SceneEditor::on_load_tsx_reply);
    w.slot(&SceneEditor::on_save_tsx_reply);
    
    
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

    file.menuitem("New").action(&SceneEditor::cmd_file_new);
    file.menuitem("Open", "Ctrl+O").action(&SceneEditor::cmd_file_open);
    file.menuitem("Save", "Ctrl+S").action(&SceneEditor::cmd_file_save);
    file.menuitem("Save As").action(&SceneEditor::cmd_file_save_as);

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
    
    auto controlpanel   = app.make<ControlPanelUI>();
    {
        auto tree       = controlpanel.make<UISimpleTree>();
        {
            auto cameras    = tree.section("Cameras");
            auto ctree      = cameras.make<UISimpleTree>();
            
            {
                auto section    = ctree.section("Available");
                auto p          = section.make<UIBuildableInfoList<Camera>>();
                p.flag(SET, UIFlag::EmitSignal);
            }
            {
                auto section    = ctree.section("Current");
                auto menus      = section.hline();
                auto add        = menus.menu("Add");
                add.menuitem("Foo");
                auto ctable     = section.make<CameraTableUI>();
                ctable.uid("CameraTable");
            }
            {
                auto section    = ctree.section("Properties");
                auto i          = section.make<InspectorUI>();
                i.uid("CameraInspector");
            }
        }
    
        {
            auto scenes         = tree.section("Scenes");
            auto stree          = scenes.make<UISimpleTree>();
            
            {
                auto section    = stree.section("Current");
                auto menus      = section.hline();
                auto add        = menus.menu("Add");
                add.menuitem("Foo");
                auto stable     = section.make<ScenesTableUI>();
                stable.uid("SceneTable");
            }
            {
                auto section    = stree.section("Properties");
                auto i          = section.make<InspectorUI>();
                i.uid("SceneInspector");
            }
        }


        {
            auto rendereds      = tree.section("Rendereds");
            auto rtree          = rendereds.make<UISimpleTree>();
        
            {
                auto section    = rtree.section("Available");
                auto p          = section.make<UIBuildableInfoList<Rendered>>();
                p.flag(SET, UIFlag::EmitSignal);
            }
            
            {
                auto section    = rtree.section("Current");
                //  TODO
            }

        
            {
                auto section    = rtree.section("Properties");
                auto i          = section.make<InspectorUI>();
                i.uid("RenderedInspector");
            }
        }
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SceneEditor::SceneEditor()
{
}

SceneEditor::~SceneEditor()
{
}

SceneEditor::SceneEntry*                  SceneEditor::_add(const Scene& sc)
{
    SceneEntry*  ret = _entry(sc.id());
    if(ret)
        return ret;
        
    SceneID edit;       // used to preserve editing
    if(m_editing)
        edit        = m_editing -> scene;
        
    SceneEntry   en;
    en.scene        = sc.id();
    en.visBtn       = std::format("{}##VISIBLE{}", en.scene.id, en.scene.id);
    en.visBtn2      = std::format("V##VISIBLE{}", en.scene.id);
    en.invisBtn     = std::format("{}##INVISIBLE{}", en.scene.id, en.scene.id);
    en.invisBtn2    = std::format("I##INVISIBLE{}", en.scene.id);
    en.info         = static_cast<const SceneInfo*>(&sc.metaInfo());
    en.sid          = std::format("{}##{}.SELECT_ID", en.scene.id, en.scene.id);
    en.stype        = std::format("{}##{}.SELECT_TYPE", en.info->stem(), en.scene.id);
    en.flags        = flags_for(*en.info);
    m_scenes.push_back(en);

    if(edit){
        m_editing   = _entry(edit);
    } else if(!m_editing)
        m_editing   = &m_scenes.back();
        
    m_flags |= F::Stale;
    return &m_scenes.back();
}

void                    SceneEditor::_clear()
{
    m_layers.clear();
    if(m_scenes.empty())
        return;

    const Frame* frame  = Frame::current();
    if(!frame)
        return ;

    for(auto& e : m_scenes){
        Scene*    sc  = frame->object(e.scene);
        if(sc)
            sc -> cmd_teardown();
    }
    m_scenes.clear();
}


SceneEditor::SceneEntry*                  SceneEditor::_entry(SceneID sc)
{
    for(auto& e : m_scenes)
        if(e.scene == sc)
            return &e;
    return nullptr;
}

const SceneEditor::SceneEntry*            SceneEditor::_entry(SceneID sc) const
{
    for(auto& e : m_scenes)
        if(e.scene == sc)
            return &e;
    return nullptr;
}

void    SceneEditor::_open(const std::filesystem::path& fp)
{
    send(new LoadTSXRequest({ .source = *this, .target= gFileIO }, fp, SIM));
}

void    SceneEditor::_rebuild()
{
    static const CameraTweakCPtr        s_originFix = new OriginCameraTweak();
    
    //const Frame*    frame   = Frame::current();
    
    m_layers.clear();
    for(const SceneEntry& e : m_scenes){
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

void    SceneEditor::_title()
{
    std::string     newTitle;
    if(m_filepath.empty()){
        newTitle        = "Scenery Editor";
    } else {
        newTitle        = std::format("{} - {} - Scenery Editor", m_filepath.filename().string(), m_filepath.parent_path().string());
    }
    send(new TitleCommand({.source=*this, .target=TypedID(viewer().id, Type::Viewer)}, newTitle));
}


void    SceneEditor::_save(const std::filesystem::path& fp)
{
    TachyonIDSet        tacs;
    for(const SceneEntry& e : m_scenes)
        tacs.insert(e.scene);
    send(new SaveTSXRequest({.source=*this, .target=gFileIO}, fp, SIM, { SaveOption::SkipOwnership }));
}


void    SceneEditor::create_scene(const SceneInfo&info)
{
    Scene*  sc  = Tachyon::create_on<Scene>(SIM, info);
    if(!sc)
        return;
    _add(*sc);
}

void    SceneEditor::cmd_file_new()
{
    _clear();
    m_filepath.clear();
    _title();
}

void    SceneEditor::cmd_file_open()
{
    IGFD::FileDialogConfig config;
    config.path = ".";
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File to Open", ".tsx", config);        
    m_fileMode  = FileMode::Open;
}

void    SceneEditor::cmd_file_save()
{
    if(m_filepath.empty()){
        cmd_file_save_as();
    } else {
        _save(m_filepath);
    }
}

void    SceneEditor::cmd_file_save_as()
{
    IGFD::FileDialogConfig config;
    config.path = ".";
    config.flags |= ImGuiFileDialogFlags_ConfirmOverwrite;
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File to Save", ".tsx", config);        
    m_fileMode  = FileMode::Save;
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
                case FileMode::Open:
                    _open(filePathName);
                    break;
                case FileMode::Save:
                    _save(filePathName);
                    break;
                }
            }
            ImGuiFileDialog::Instance()->Close();
        }
    }
}

void    SceneEditor::on_info_selection_changed_event(const InfoSelectionChangedEvent&evt)
{
    if(const CameraInfo* p = dynamic_cast<const CameraInfo*>(evt.info()))
        m_selection.cameraInfo      = p;
    if(const RenderedInfo* p = dynamic_cast<const RenderedInfo*>(evt.info()))
        m_selection.renderedInfo    = p;
}


void    SceneEditor::on_load_tsx_reply(const LoadTSXReply&rep)
{
    if(rep.response() != Response::QaPla)
        return ;
    
    const LoadTSXRequest* req = dynamic_cast<const LoadTSXRequest*>(rep.request());
    if(!req)
        return ;
    
    if(rep.tachyons().empty())
        return;
    
    _clear();
    
    const Frame*    frame   = Frame::current();
    for(auto id : rep.tachyons()){
        const Scene*    sc  = dynamic_cast<const Scene*>(frame->object(id));
        if(!sc)
            continue;
        _add(*sc);
    }
    
    m_filepath  = req->filepath();
    _title();
}

void    SceneEditor::on_save_tsx_reply(const SaveTSXReply&rep)
{
    if(rep.response() != Response::QaPla)
        return ;

    const SaveTSXRequest* req   = dynamic_cast<const SaveTSXRequest*>(rep.request());
    if(!req)
        return ;

    if(req->filepath() != m_filepath){
        m_filepath  = req->filepath();
        _title();
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
        m_camera.space  = create_child_on<SpaceCamera>(SIM) -> id();
    }
    if(!m_camera.hud){
        //  TODO
    }
    return Widget::setup(ctx);
}

Execution   SceneEditor::teardown(const Context&ctx) 
{
    _clear();       // eventually to have ref counting....
    return CompositeWidget::teardown(ctx);
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    aci.thread.io           = true;
    aci.thread.sim          = true;
    aci.view.title          = "Scenery Editor";
    aci.view.size           = { 1920, 1080 };
    aci.view.clear          = { 0.0f, 0.0f, 0.0f, 1.f };
    aci.view.imgui          = true;
    aci.view.resizable      = true;
    
    Application app(argc, argv, aci);
    Meta::init();
    app.vulqan_libraries(LOAD);
    Meta::init();
    
    for(const std::filesystem::path& pth : Asset::resolver().paths())
        yInfo() << "asset path> " << pth;
    
    app.start();
    
    gFileIO             = Tachyon::create_on<FileIOManager>(IO)->typed_id();
    
    SceneEditor* w      = Widget::create<SceneEditor>();
    app.run(w);
    return 0;
}

