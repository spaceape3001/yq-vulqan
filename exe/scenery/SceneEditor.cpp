////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ControlPanelUI.hpp"
#include "InspectorUI.hpp"
#include "MetricsUI.hpp"
#include "SceneEditor.hpp"
#include "SceneEntry.hpp"
#include "SceneTableUI.hpp"

#include "CameraSelectEvent.hpp"
#include "CameraTableUI.hpp"

#include "RenderedSelectEvent.hpp"
#include "RenderedTableUI.hpp"

#include <tachyon/MyImGui.hpp>
#include <tachyon/parameters.hpp>

#include <tachyon/api/Camera.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/Light.hpp>
#include <tachyon/api/Model.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/api/Rendered3.hpp>
#include <tachyon/api/Scene.hpp>
#include <tachyon/api/SceneData.hpp>
#include <tachyon/app/Viewer.hpp>

#include <tachyon/camera/SpaceCamera.hpp>
#include <tachyon/command/controller/ListenCommand.hpp>
#include <tachyon/command/ui/TitleCommand.hpp>
#include <tachyon/controller/Space3Controller.hpp>

#include <tachyon/event/panel/InfoSelectionChangedEvent.hpp>

#include <tachyon/gfx/Texture.hpp>

#include <tachyon/menu/CreateMenuUI.hpp>

#include <tachyon/panel/UIBuildableInfoList.hpp>

#include <tachyon/request/app/OpenFileRequest.hpp>

#include <tachyon/reply/io/LoadTSXReply.hpp>
#include <tachyon/reply/io/SaveTSXReply.hpp>

#include <tachyon/request/io/LoadTSXRequest.hpp>
#include <tachyon/request/io/SaveTSXRequest.hpp>

#include <tachyon/scene/HUDScene.hpp>
#include <tachyon/scene/BackgroundScene.hpp>
#include <tachyon/scene/ForegroundScene.hpp>

#include <tachyon/spatial/SimpleSpatial3.hpp>

#include <tachyon/tweak/OriginCameraTweak.hpp>

#include <tachyon/ui/UIMenuBar.hpp>
#include <tachyon/ui/UISection.hpp>
#include <tachyon/ui/UISimpleTree.hpp>
#include <tachyon/ui/UIStyle.hpp>
#include <tachyon/ui/UIWindow.hpp>
#include <tachyon/ui/UIWriters.hxx>
#include <tachyon/ui/UIElementInfoWriter.hpp>

#include <tachyon/widget/AppWidgetInfoWriter.hpp>


#include <ImGuiFileDialog.h>

#include <iostream>


YQ_TACHYON_IMPLEMENT(SceneEditor)

SceneEditor::EFlags       SceneEditor::flags_for(const CameraInfo& sc)
{
    EFlags  ret = {};
    return ret;
}

SceneEditor::EFlags       SceneEditor::flags_for(const SceneInfo& sc)
{
    EFlags  ret = {};
    if(sc.is_this<HUDScene>())
        ret |= E::HUD;
    if(sc.is_this<BackgroundScene>())
        ret |= E::OriginFix;
    if(sc.is_this<ForegroundScene>())
        ret |= E::OriginFix;
    return ret;
}

void SceneEditor::init_info()
{
    auto w          = writer<SceneEditor>();
    
    w.slot(&SceneEditor::on_camera_select_event);
    w.slot(&SceneEditor::on_load_tsx_reply);
    w.slot(&SceneEditor::on_info_selection_changed_event);
    w.slot(&SceneEditor::on_rendered_select_event);
    w.slot(&SceneEditor::on_save_tsx_reply);
    
    w.description("The main widget");
    auto app        = w.imgui(UI, APP);
    
    auto mmb        = app.menubar(MAIN);
    mmb.uid("mmb");
    
    /////////////////////////////////
    //  CONTROL PANEL
    
    auto controlpanel       = app.make<ControlPanelUI>();
    auto cp_tree            = controlpanel.make<UISimpleTree>();
    
    cp_tree.section("Metrics").make<MetricsUI>();
    
    auto cp_cameras         = cp_tree.section("Cameras").make<UISimpleTree>();
    auto cp_controllers     = cp_tree.section("Controllers").make<UISimpleTree>();
    auto cp_lights          = cp_tree.section("Lights").make<UISimpleTree>();
    auto cp_models          = cp_tree.section("Models").make<UISimpleTree>();
    //auto cp_physics         = cp_tree.section("Physics").make<UISimpleTree>();
    auto cp_rendereds       = cp_tree.section("Rendereds").make<UISimpleTree>();
    auto cp_scenes          = cp_tree.section("Scenes").make<UISimpleTree>();
    auto cp_spatials        = cp_tree.section("Spatials").make<UISimpleTree>();

    cp_cameras.section("Available").make<UIBuildableInfoList<Camera>>().flag(SET, UIFlag::EmitSignal).uid("CameraAvailable");
    cp_cameras.section("Current").make<CameraTableUI>().uid("CameraTable");
    cp_cameras.section("Properties").make<InspectorUI>().uid("CameraInspector");
    
    cp_controllers.section("Available").make<UIBuildableInfoList<Controller>>().flag(SET, UIFlag::EmitSignal).uid("ControllerAvailable");
    //cp_controllers.section("Current").make<ControllerTableUI>().uid("ControllerTable");
    //cp_controllers.section("Properties").make<InspectorUI>().uid("ControllerInspector");

    cp_lights.section("Available").make<UIBuildableInfoList<Light>>().flag(SET, UIFlag::EmitSignal).uid("LightAvailable");
    //cp_lights.section("Current").make<LightTableUI>().uid("LightTable");
    cp_lights.section("Properties").make<InspectorUI>().uid("LightInspector");

    cp_models.section("Available").make<UIBuildableInfoList<Model>>().flag(SET, UIFlag::EmitSignal).uid("ModelAvailable");
    //cp_models.section("Current").make<ModelTableUI>().uid("ModelTable");
    cp_models.section("Properties").make<InspectorUI>().uid("ModelInspector");

    //cp_physics.section("Available").make<UIBuildableInfoList<Physics>>().flag(SET, UIFlag::EmitSignal).uid("PhysicsAvailable");
    //cp_physics.section("Current").make<PhysicsTableUI>().uid("PhysicsTable");
    //cp_physics.section("Properties").make<InspectorUI>().uid("PhysicsInspector");

    cp_rendereds.section("Available").make<UIBuildableInfoList<Rendered>>().flag(SET, UIFlag::EmitSignal).uid("RenderedAvailable");
    cp_rendereds.section("Current").make<RenderedTableUI>().uid("RenderedTable");
    cp_rendereds.section("Properties").make<InspectorUI>().uid("RenderedInspector");

    cp_scenes.section("Available").make<UIBuildableInfoList<Scene>>().flag(SET, UIFlag::EmitSignal).uid("SceneAvailable");
    cp_scenes.section("Current").make<ScenesTableUI>().uid("SceneTable");
    cp_scenes.section("Properties").make<InspectorUI>().uid("SceneInspector");

    cp_spatials.section("Available").make<UIBuildableInfoList<Spatial>>().flag(SET, UIFlag::EmitSignal).uid("SpatialAvailable");
    //cp_spatials.section("Current").make<SpatialTableUI>().uid("SpatialTable");
    //cp_spatials.section("Properties").make<InspectorUI>().uid("SpatialInspector");

    /////////////////////////////////
    //  MENUS
    
    auto file_menu          = mmb.menu("File");
    auto edit_menu          = mmb.menu("Edit");
    auto view_menu          = mmb.menu("View");
    auto camera_menu        = mmb.menu("Camera");
    //auto controller_menu    = mmb.menu("Controller");
    auto scene_menu         = mmb.menu("Scene");
    auto light_menu         = mmb.menu("Light");
    auto rendered_menu      = mmb.menu("Rendered");
    auto model_menu         = mmb.menu("Model");
    //auto physics_menu       = mmb.menu("Physics");
    auto window_menu        = mmb.menu("Window");
    auto help_menu          = mmb.menu("Help");
    auto debug_menu         = mmb.menu("Debug");

    /////////////////////////////////
    //  MENU ITEMS
    
    (camera_menu << new CreateMenuUI("Add/Create##AddCameraUI", meta<Camera>())).action(&SceneEditor::create_payload);

    edit_menu.menuitem("Copy", "Ctrl+C");
    edit_menu.menuitem("Paste", "Ctrl+V");

    file_menu.menuitem("New").action(&SceneEditor::cmd_file_new);
    file_menu.menuitem("Open", "Ctrl+O").action(&SceneEditor::cmd_file_open);
    file_menu.menuitem("Save", "Ctrl+S").action(&SceneEditor::cmd_file_save);
    file_menu.menuitem("Save As").action(&SceneEditor::cmd_file_save_as);

    (light_menu << new CreateMenuUI("Add/Create##AddLightUI", meta<Light>())).action(&SceneEditor::create_payload);

    (model_menu << new CreateMenuUI("Add/Create##AddModelUI", meta<Model>())).action(&SceneEditor::create_payload);

    (rendered_menu << new CreateMenuUI("Add/Create##AddRenderedUI", meta<Rendered>())).action(&SceneEditor::create_payload);

    (scene_menu << new CreateMenuUI("Add/Create##AddSceneUI", meta<Scene>())).action(&SceneEditor::create_payload);
    
    view_menu.checkbox(VISIBLE, controlpanel);


}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SceneEditor::SceneEditor()
{
}

SceneEditor::~SceneEditor()
{
}

void    SceneEditor::_activate(CameraID ca)
{
    if(m_camera.table && !m_camera.table->selected()){
        m_camera.table->set_selected(ca);
        if(m_camera.properties) // the set-selected *SHOULD* be working, but it isn't
            m_camera.properties->bind(TypedID(ca.id, Type::Camera));
    }
}

void    SceneEditor::_activate(RenderedID re)
{
    if(m_rendered.table && !m_rendered.table->selected()){
        m_rendered.table->set_selected(re);
        if(m_rendered.properties) // the set-selected *SHOULD* be working, but it isn't
            m_rendered.properties->bind(TypedID(re.id, Type::Camera));
    }
}

void    SceneEditor::_activate(SceneID sc)
{
    SceneEntry* e   = _entry(sc);
    if(!e)  
        return ;

    if(e->flags(E::Invisible)){
        e->flags -= E::Invisible;
        m_flags |= F::Stale;
    }
    
    m_scene.selected    = sc;
    m_scene.editing     = e;
    if(m_scene.properties)
        m_scene.properties -> bind(TypedID(sc.id, Type::Scene));
}

SceneEditor::SceneEntry*                  SceneEditor::_add(const Scene& sc)
{
    SceneEntry*  ret = _entry(sc.id());
    if(ret)
        return ret;
        
    SceneID edit;       // used to preserve editing
    if(m_scene.editing)
        edit        = m_scene.editing -> scene;
        
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
    m_scene.entries.push_back(en);

    if(edit){
        m_scene.editing   = _entry(edit);
    } else if(!m_scene.editing){
        m_scene.editing   = &m_scene.entries.back();
        m_scene.selected    = sc.id();
    }
        
    m_flags |= F::Stale;
    return &m_scene.entries.back();
}

void                    SceneEditor::_clear()
{
    m_layers.clear();
    if(m_scene.entries.empty())
        return;

    const Frame* frame  = Frame::current();
    if(!frame)
        return ;

    for(auto& e : m_scene.entries){
        Scene*    sc  = frame->object(e.scene);
        if(sc)
            sc -> cmd_teardown();
    }

    m_scene.entries.clear();
}


SceneEditor::SceneEntry*                  SceneEditor::_entry(SceneID sc)
{
    for(auto& e : m_scene.entries)
        if(e.scene == sc)
            return &e;
    return nullptr;
}

const SceneEditor::SceneEntry*            SceneEditor::_entry(SceneID sc) const
{
    for(auto& e : m_scene.entries)
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
    for(const SceneEntry& e : m_scene.entries){
        if(e.flags(E::Invisible) && (m_scene.editing != &e))
            continue;
        CLayer  lay;
        lay.scene   = e.scene;
        if(e.flags(E::HUD)){
            lay.camera  = { m_camera.hud.id };
        } else
            lay.camera  = (CameraID) m_camera.space;
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
    const Frame* frame  = Frame::current();
    if(!frame)
        return ;

    TachyonIDSet        tacs;
    for(const CameraID& e : frame->ids(CAMERA))
        tacs.insert(e);
    for(const SceneEntry& e : m_scene.entries)
        tacs.insert(e.scene);
    send(new SaveTSXRequest({.source=*this, .target=gFileIO}, fp, SIM, { SaveOption::SkipOwnership }));
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

TypedID    SceneEditor::create(const CameraInfo& info)
{
    Camera* sc = Tachyon::create_on<Camera>(SIM, info);
    if(!sc)
        return {};
        
    _activate(sc->id());
    return *sc;
    //return sc->id();
}

#if 0
void    SceneEditor::create(const LightInfo& info)
{
    const Frame*  frame = Frame::current();
    if(!frame){
    yInfo() << "SceneEditor's create_light(" << info.name() << ") no frame";
        return;
    }
    
    Scene*    sc  = frame->object( m_scene.selected);
    if(!sc){
    yInfo() << "SceneEditor's create_light(" << info.name() << ") no scene";
        return ;
    }

    Light*      li   = sc->create_child<Light>(info);
    if(!li){
    yInfo() << "SceneEditor's create_light(" << info.name() << ") unable to create";
        return ;
    }
    
    //  TODO (More)
    
}

void    SceneEditor::create(const ModelInfo&info)
{
    const Frame*  frame = Frame::current();
    if(!frame){
    yInfo() << "SceneEditor's create_model(" << info.name() << ") no frame";
        return;
    }
    
    Scene*    sc  = frame->object( m_scene.selected);
    if(!sc){
    yInfo() << "SceneEditor's create_model(" << info.name() << ") no scene";
        return ;
    }

    Model*      mo   = sc->create_child<Model>(info);
    if(!mo){
    yInfo() << "SceneEditor's create_model(" << info.name() << ") unable to create";
        return ;
    }
    
    //  TODO (More)
    
}
#endif

TypedID    SceneEditor::create(const RenderedInfo& info)
{
    const Frame*  frame = Frame::current();
    if(!frame){
    yInfo() << "SceneEditor's create_rendered(" << info.name() << ") no frame";
        return {};
    }
    
    Scene*    sc  = frame->object( m_scene.selected);
    if(!sc){
    yInfo() << "SceneEditor's create_rendered(" << info.name() << ") no scene";
        return {};
    }
    
    Rendered*   re  = sc->create_child<Rendered>(info);
    if(!re){
    yInfo() << "SceneEditor's create_rendered(" << info.name() << ") unable to create";
        return {} ;
    }
    
    Rendered³*  r3  = dynamic_cast<Rendered³*>(re);
    if(r3){
        //  eventually an option...
        Spatial*    sp   = r3->create_child<SimpleSpatial³>();
        if(sp)
            r3->set_spatial(*sp);
    }
    
    _activate(re->id());
    return *re;
    //  add & activate.... (later)
}

TypedID    SceneEditor::create(const SceneInfo&info)
{
    Scene*  sc  = Tachyon::create_on<Scene>(SIM, info);
    if(!sc)
        return {};
    _add(*sc);
    _activate(sc->id());
    return *sc;
}

#if 0
void    SceneEditor::create(const SpatialInfo& info)
{
    const Frame*  frame = Frame::current();
    if(!frame){
    yInfo() << "SceneEditor's create_spatial(" << info.name() << ") no frame";
        return;
    }
    
    Rendered³*   re  = frame->object((Rendered³ID) m_rendered.selected);
    if(!re){
    yInfo() << "SceneEditor's create_spatial(" << info.name() << ") no rendered";
        return ;
    }
    
    Spatial*    sp  = re->create_child<Spatial>(info);
    if(sp && !re->spatial())
        re->set_spatial(*sp);
    
    //  TODO
}
#endif

void    SceneEditor::create_payload(const Payload& payload)
{
    auto r  = payload.m_metas.equal_range(kParam_CreateInfo);
    for(auto itr = r.first; itr != r.second; ++itr){
        if(const CameraInfo* ci = dynamic_cast<const CameraInfo*>(itr->second)){
            create(*ci);
        }
        if(const RenderedInfo* ri = dynamic_cast<const RenderedInfo*>(itr->second)){
            create(*ri);
        }
        if(const SceneInfo* si = dynamic_cast<const SceneInfo*>(itr->second)){
            create(*si);
        }
    }
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

void    SceneEditor::on_camera_select_event(const CameraSelectEvent&evt)
{
    if(m_camera.properties)
        m_camera.properties->bind(TypedID(evt.camera().id, Type::Camera));
}


void    SceneEditor::on_info_selection_changed_event(const InfoSelectionChangedEvent&evt)
{
    if(const CameraInfo* p = dynamic_cast<const CameraInfo*>(evt.info()))
        m_camera.info       = p;
    if(const RenderedInfo* p = dynamic_cast<const RenderedInfo*>(evt.info()))
        m_rendered.info     = p;
    if(const SceneInfo* p = dynamic_cast<const SceneInfo*>(evt.info()))
        m_scene.info        = p;
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
        const Tachyon* t    = frame->object(id);
        if(const Camera* ca = dynamic_cast<const Camera*>(t)){
            //  todo
        }
        if(const Scene*  sc  = dynamic_cast<const Scene*>(t)){
            _add(*sc);
        }
    }
    
    m_filepath  = req->filepath();
    _title();
}

void    SceneEditor::on_rendered_select_event(const RenderedSelectEvent&evt)
{
    if(m_rendered.properties)
        m_rendered.properties->bind(TypedID(evt.rendered().id, Type::Rendered));
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
    const Frame*    curFrame    = Frame::current();
    if(!curFrame)
        return WAIT;

    if(!m_camera.space){
        SpaceCamera::Param p;
        p.near      = 0.1;
        p.far       = 60.;
        p.position  = ZERO;
        
        Camera* cam     = create_child_on<SpaceCamera>(SIM, p);
        m_camera.space  = *cam;
    }

    if(!m_camera.hud){
        //  TODO
    }
    
    Camera* cam   = curFrame->object((CameraID) m_camera.space);
    if(!cam)
        return WAIT;
    
    if(!m_controller){ 
        Space³Controller::Param p;
        p.keyboard      = false;
        Space³Controller* sc    = create_on<Space³Controller>(SIM, m_camera.space, p);
        m_controller            = *sc;
    }
    
    if(!curFrame->contains(m_controller))
        return WAIT;
        
    if(!m_controllerInit){
        TachyonID    vid    = viewer();
        if(!curFrame->contains(vid))
            return WAIT;
            
        send(new ListenCommand({.target=m_controller}, TypedID(vid, Type::Viewer)));
        m_controllerInit = true;
    }

    Execution ret = Widget::setup(ctx);
    
    if(!m_camera.properties)
        m_camera.properties     = static_cast<InspectorUI*>(element(FIRST, "CameraInspector"));
    if(!m_camera.table)
        m_camera.table          = static_cast<CameraTableUI*>(element(FIRST, "CameraTable"));
    if(!m_rendered.properties)
        m_rendered.properties   = static_cast<InspectorUI*>(element(FIRST, "RenderedInspector"));
    if(!m_rendered.table)
        m_rendered.table        = static_cast<RenderedTableUI*>(element(FIRST, "RenderedTable"));
    if(!m_scene.properties)
        m_scene.properties      = static_cast<InspectorUI*>(element(FIRST, "SceneInspector"));
        
    {
        _activate(cam->id());
    }
    
    return ret;
}

Execution   SceneEditor::teardown(const Context&ctx) 
{
    _clear();       // eventually to have ref counting....
    return CompositeWidget::teardown(ctx);
}


