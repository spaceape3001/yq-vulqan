////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneEditor.hpp"


#include "ControlPanelUI.hpp"
#include "InspectorUI.hpp"
#include "MetricsUI.hpp"

#include "event/CameraSelectEvent.hpp"
#include "event/ControllerSelectEvent.hpp"
#include "event/LightSelectEvent.hpp"
#include "event/ModelSelectEvent.hpp"
#include "event/RenderedSelectEvent.hpp"
#include "event/SceneAddEvent.hpp"
#include "event/SceneRemoveEvent.hpp"
#include "event/SceneSelectEvent.hpp"
#include "event/SceneVisibilityEvent.hpp"

#include "table/CameraTableUI.hpp"
#include "table/ControllerTableUI.hpp"
#include "table/LightTableUI.hpp"
#include "table/ModelTableUI.hpp"
#include "table/RenderedTableUI.hpp"
#include "table/SceneTableUI.hpp"

#include "data.hpp"
#include "utils.hpp"

#include <tachyon/MyImGui.hpp>
#include <tachyon/parameters.hpp>

#include <tachyon/api/Camera3.hpp>
#include <tachyon/api/Camera3Data.hpp>

#include <tachyon/api/Frame.hpp>
#include <tachyon/api/Light3.hpp>
#include <tachyon/api/Light3Data.hpp>
#include <tachyon/api/Model.hpp>
#include <tachyon/api/Rendered3.hpp>
#include <tachyon/api/Rendered3Data.hpp>
#include <tachyon/api/Scene.hpp>
#include <tachyon/api/SceneData.hpp>
#include <tachyon/app/Viewer.hpp>

#include <tachyon/camera/NullCamera.hpp>
#include <tachyon/camera/SpaceCamera.hpp>
#include <tachyon/command/controller/ListenCommand.hpp>
#include <tachyon/command/generic/SetSpatialCommand.hpp>
#include <tachyon/command/ui/TitleCommand.hpp>
#include <tachyon/controller/Space3Controller.hpp>

#include <tachyon/event/panel/InfoSelectionChangedEvent.hpp>

#include <tachyon/gfx/Raster.hpp>
#include <tachyon/gfx/Texture.hpp>

#include <tachyon/menu/CreateMenuUI.hpp>

#include <tachyon/panel/UIBuildableInfoList.hpp>

#include <tachyon/request/app/OpenFileRequest.hpp>

#include <tachyon/reply/io/LoadTSXReply.hpp>
#include <tachyon/reply/io/SaveTSXReply.hpp>
#include <tachyon/reply/viewer/ViewerScreenshotReply.hpp>

#include <tachyon/request/io/LoadTSXRequest.hpp>
#include <tachyon/request/io/SaveTSXRequest.hpp>
#include <tachyon/request/viewer/ViewerScreenshotRequest.hpp>

#include <tachyon/scene/HUDScene.hpp>
#include <tachyon/scene/BackgroundScene.hpp>
#include <tachyon/scene/ForegroundScene.hpp>
#include <tachyon/scene/SimpleScene.hpp>

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
    w.slot(&SceneEditor::on_controller_select_event);
    w.slot(&SceneEditor::on_load_tsx_reply);
    w.slot(&SceneEditor::on_info_selection_changed_event);
    w.slot(&SceneEditor::on_model_select_event);
    w.slot(&SceneEditor::on_rendered_select_event);
    w.slot(&SceneEditor::on_save_tsx_reply);
    w.slot(&SceneEditor::on_scene_add_event);
    w.slot(&SceneEditor::on_scene_remove_event);
    w.slot(&SceneEditor::on_scene_select_event);
    w.slot(&SceneEditor::on_scene_visibility_event);
    w.slot(&SceneEditor::on_viewer_screenshot_reply);
    
    
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
    //auto cp_collisions      = cp_tree.section("Collisions").make<UISimpleTree>();
    //auto cp_lights          = cp_tree.section("Lights").make<UISimpleTree>();
    //auto cp_models          = cp_tree.section("Models").make<UISimpleTree>();
    //auto cp_physics         = cp_tree.section("Physics").make<UISimpleTree>();
    auto cp_rendereds       = cp_tree.section("Rendereds").make<UISimpleTree>();
    auto cp_scenes          = cp_tree.section("Scenes").make<UISimpleTree>();
    auto cp_spatials        = cp_tree.section("Spatials").make<UISimpleTree>();

    cp_cameras.section("Available").make<UIBuildableInfoList<Camera>>().flag(SET, UIFlag::EmitSignal).uid("CameraAvailable");
    cp_cameras.section("Current").make<CameraTableUI>().uid("CameraTable");
    auto cpp_cameras      = cp_cameras.section("Properties");
    (cpp_cameras << new CreateMenuUI("Add/Create Spatial##AddCameraSpatialUI", meta<Spatial>())).action(&SceneEditor::action_create_camera_spatial);
    cpp_cameras.make<InspectorUI>().uid("CameraInspector");
    
    cp_controllers.section("Available").make<UIBuildableInfoList<Controller>>().flag(SET, UIFlag::EmitSignal).uid("ControllerAvailable");
    cp_controllers.section("Current").make<ControllerTableUI>().uid("ControllerTable");
    cp_controllers.section("Properties").make<InspectorUI>().uid("ControllerInspector");

#if 0
    cp_lights.section("Available").make<UIBuildableInfoList<Light>>().flag(SET, UIFlag::EmitSignal).uid("LightAvailable");
    cp_lights.section("Current").make<LightTableUI>().uid("LightTable");
    auto cpp_lights    = cp_lights.section("Properties");
    (cpp_lights << new CreateMenuUI("Add/Create Spatial##AddLightSpatialUI", meta<Spatial>())).action(&SceneEditor::action_create_light_spatial);
    cpp_lights.make<InspectorUI>().uid("LightInspector");
#endif

#if 0
    cp_models.section("Available").make<UIBuildableInfoList<Model>>().flag(SET, UIFlag::EmitSignal).uid("ModelAvailable");
    cp_models.section("Current").make<ModelTableUI>().uid("ModelTable");
    auto cpp_models = cp_models.section("Properties");
    (cpp_models << new CreateMenuUI("Add/Create Spatial##AddModelSpatialUI", meta<Spatial>()));
    cpp_models = make<InspectorUI>().uid("ModelInspector");
#endif

    //cp_physics.section("Available").make<UIBuildableInfoList<Physics>>().flag(SET, UIFlag::EmitSignal).uid("PhysicsAvailable");
    //cp_physics.section("Current").make<PhysicsTableUI>().uid("PhysicsTable");
    //cp_physics.section("Properties").make<InspectorUI>().uid("PhysicsInspector");

    cp_rendereds.section("Available").make<UIBuildableInfoList<Rendered>>().flag(SET, UIFlag::EmitSignal).uid("RenderedAvailable");
    cp_rendereds.section("Current").make<RenderedTableUI>().uid("RenderedTable");
    auto rendered_props = cp_rendereds.section("Properties");
    (rendered_props << new CreateMenuUI("Add/Create Spatial##AddRenderedSpatialUI", meta<Spatial>())).action(&SceneEditor::action_create_rendered_spatial);
    rendered_props.make<InspectorUI>().uid("RenderedInspector");

    cp_scenes.section("Available").make<UIBuildableInfoList<Scene>>().flag(SET, UIFlag::EmitSignal).uid("SceneAvailable");
    cp_scenes.section("Current").make<SceneTableUI>().uid("SceneTable");
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
    auto scene_menu         = mmb.menu("Scene");
    //auto light_menu         = mmb.menu("Light");
    auto rendered_menu      = mmb.menu("Rendered");
    //auto model_menu         = mmb.menu("Model");
    auto controller_menu    = mmb.menu("Controller");
    //auto collision_menu     = mmb.menu("Collision");
    //auto physics_menu       = mmb.menu("Physics");
    //auto window_menu        = mmb.menu("Window");
    //auto help_menu          = mmb.menu("Help");
    auto debug_menu         = mmb.menu("Debug");

    /////////////////////////////////
    //  MENU ITEMS
    
    (camera_menu << new CreateMenuUI("Add/Create##AddCameraUI", meta<Camera>())).action(&SceneEditor::action_create_camera);
    
    //(controller_menu << new CreateMenuUI("Add/Create##AddControllerUI", meta<Controller>())).action(&SceneEditor::create_payload);


    edit_menu.menuitem("Copy", "Ctrl+C");
    edit_menu.menuitem("Paste", "Ctrl+V");

    file_menu.menuitem("New").action(&SceneEditor::cmd_file_new);
    file_menu.menuitem("Open", "Ctrl+O").action(&SceneEditor::cmd_file_open);
    file_menu.menuitem("Save", "Ctrl+S").action(&SceneEditor::cmd_file_save);
    file_menu.menuitem("Save As").action(&SceneEditor::cmd_file_save_as);
    file_menu.menuitem("Screenshot", "F12").action(&SceneEditor::cmd_screenshot);

    //(light_menu << new CreateMenuUI("Add/Create##AddLightUI", meta<Light>())).action(&SceneEditor::create_payload);

    //(model_menu << new CreateMenuUI("Add/Create##AddModelUI", meta<Model>())).action(&SceneEditor::create_payload);

    (rendered_menu << new CreateMenuUI("Add/Create##AddRenderedUI", meta<Rendered>())).action(&SceneEditor::action_create_rendered);

    (scene_menu << new CreateMenuUI("Add/Create##AddSceneUI", meta<Scene>())).action(&SceneEditor::action_create_scene);
    
    view_menu.checkbox(VISIBLE, controlpanel);


}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SceneEditor::SceneEditor()
{
}

SceneEditor::~SceneEditor()
{
}

void    SceneEditor::_activate(CameraID id)
{
    if(m_camera.selected == id)
        return;
    m_camera.selected   = id;
    if(m_camera.table && (m_camera.table->selected() != id))
        m_camera.table -> set_selected(id);
    if(m_camera.properties && (m_camera.properties->bound() != id))
        m_camera.properties -> bind(TypedID(id.id, Type::Camera));
}

void    SceneEditor::_activate(ControllerID id)
{
    if(m_controller.selected == id)
        return;
    m_controller.selected   = id;
    if(m_controller.table && (m_controller.table->selected() != id))
        m_controller.table -> set_selected(id);
    if(m_controller.properties && (m_controller.properties->bound() != id))
        m_controller.properties -> bind(TypedID(id.id, Type::Controller));
}

void    SceneEditor::_activate(LightID id)
{
    if(m_light.selected == id)
        return;
    m_light.selected   = id;
    if(m_light.table && (m_light.table->selected() != id))
        m_light.table -> set_selected(id);
    if(m_light.properties && (m_light.properties->bound() != id))
        m_light.properties -> bind(TypedID(id.id, Type::Light));
}

void    SceneEditor::_activate(ModelID id)
{
    if(m_model.selected == id)
        return;
    m_model.selected   = id;
    if(m_model.table && (m_model.table->selected() != id))
        m_model.table -> set_selected(id);
    if(m_model.properties && (m_model.properties->bound() != id))
        m_model.properties -> bind(TypedID(id.id, Type::Model));
}

void    SceneEditor::_activate(RenderedID id)
{
    if(m_rendered.selected == id)
        return;
    m_rendered.selected   = id;
    if(m_rendered.table && (m_rendered.table->selected() != id))
        m_rendered.table -> set_selected(id);
    if(m_rendered.properties && (m_rendered.properties->bound() != id))
        m_rendered.properties -> bind(TypedID(id.id, Type::Rendered));
}

void    SceneEditor::_activate(SceneID id)
{
    if(m_scene.selected == id)
        return;
    m_scene.selected   = id;
    if(m_scene.table && (m_scene.table->selected() != id))
        m_scene.table -> set_selected(id);
    if(m_scene.properties && (m_scene.properties->bound() != id))
        m_scene.properties -> bind(TypedID(id.id, Type::Scene));
}

CameraID        SceneEditor::_create(const CameraInfo& info)
{
    Camera* res = Tachyon::create_on<Camera>(SIM, info);
    if(!res){
        yNotice() << "Unable to create camera (" << info.stem() << ") due to instantiation problem";
        return {};
    }
    return res->id();
}

SpatialID       SceneEditor::_create(camera_k, const SpatialInfo& info)
{
    TypedID     pid = typed_for(m_camera.selected);
    if(pid(Type::Camera³))
        return _create((Camera³ID) m_camera.selected, info);
    return {};
}

SpatialID       SceneEditor::_create(Camera³ID pid, const SpatialInfo& info)
{
    Camera³*    parent  = pointer(pid);
    if(!parent) {
        yNotice() << "Unable to create spatial (" << info.stem() << ") due to no corresponding camera (id " << pid.id << ")";
        return {};
    }
    
    const Camera³Snap*    psnap   = snapshot(pid);
    if(!psnap){
        yNotice() << "Unable to create spatial (" << info.stem() << ") due to no corresponding camera (id " << pid.id << ") on the frame";
        return {};
    }
    
    Spatial*   res  = parent->create_child_on<Spatial>(SIM, info);
    if(!res){
        yNotice() << "Unable to create spatial (" << info.stem() << ") due to instantiation problem";
        return {};
    }
    
    if(!psnap->spatial)
        send(new SetSpatialCommand({.target=*parent}, *res));
    return res->id();
}

ControllerID    SceneEditor::_create(const ControllerInfo& info)
{
    Controller* res = Tachyon::create_on<Controller>(SIM, info);
    if(!res){
        yNotice() << "Unable to create controller (" << info.stem() << ")";
        return {};
    }
    return res->id();
}

LightID         SceneEditor::_create(const LightInfo& info)
{
    Scene*  parent  = pointer(m_scene.selected);
    if(!parent){
        yNotice() << "Unable to create light (" << info.stem() << ") due to no parent scene";
        return {};
    }
    
    Light*    res  = parent->create_child_on<Light>(SIM, info);
    if(!res){
        yNotice() << "Unable to create light (" << info.stem() << ") due to instantiation problem";
        return {};
    }
    return res->id();
}

SpatialID       SceneEditor::_create(light_k, const SpatialInfo& info)
{
    TypedID     pid = typed_for(m_light.selected);
    if(pid(Type::Light³))
        return _create((Light³ID) m_light.selected, info);
    return {};
}

SpatialID       SceneEditor::_create(Light³ID pid, const SpatialInfo& info)
{
    Light³*     parent  = pointer(pid);
    if(!parent) {
        yNotice() << "Unable to create spatial (" << info.stem() << ") due to no corresponding light (id " << pid.id << ")";
        return {};
    }
    
    const Light³Snap*     psnap   = snapshot(pid);
    if(!psnap){
        yNotice() << "Unable to create spatial (" << info.stem() << ") due to no corresponding light (id " << pid.id << ") on the frame";
        return {};
    }
    
    Spatial*    res  = parent->create_child_on<Spatial>(SIM, info);
    if(!res){
        yNotice() << "Unable to create spatial (" << info.stem() << ") due to instantiation problem";
        return {};
    }
    
    if(!psnap->spatial)
        send(new SetSpatialCommand({.target=*parent}, *res));
    return res->id();
}

ModelID         SceneEditor::_create(const ModelInfo& info)
{
    Model* res = Tachyon::create_on<Model>(SIM, info);
    if(!res){
        yNotice() << "Unable to create model (" << info.stem() << ") due to instantiation problem";
        return {};
    }
    return res->id();
}

RenderedID      SceneEditor::_create(const RenderedInfo& info)
{
    Scene*  parent  = pointer(m_scene.selected);
    if(!parent){
        yNotice() << "Unable to create rendered (" << info.stem() << ") due to no parent scene";
        return {};
    }
    
    Rendered*    res  = parent->create_child_on<Rendered>(SIM, info);
    if(!res){
        yNotice() << "Unable to create rendered (" << info.stem() << ") due to instantiation problem";
        return {};
    }
    return res->id();
}

SpatialID       SceneEditor::_create(rendered_k, const SpatialInfo& info)
{
    TypedID     pid = typed_for(m_rendered.selected);
    if(pid(Type::Rendered³))
        return _create((Rendered³ID) m_rendered.selected, info);
    return {};
}

SpatialID       SceneEditor::_create(Rendered³ID pid, const SpatialInfo& info)
{
    Rendered³*     parent  = pointer(pid);
    if(!parent){
        yNotice() << "Unable to create spatial (" << info.stem() << ") due to no corresponding rendered (id " << pid.id << ")";
        return {};
    }
    
    const Rendered³Snap*     psnap   = snapshot(pid);
    if(!psnap){
        yNotice() << "Unable to create spatial (" << info.stem() << ") due to no corresponding rendered (id " << pid.id << ") on the frame";
        return {};
    }
    
    Spatial*    res  = parent->create_child_on<Spatial>(SIM, info);
    if(!res){
        yNotice() << "Unable to create spatial (" << info.stem() << ") due to instantiation problem";
        return {};
    }
    
    if(!psnap->spatial)
        send(new SetSpatialCommand({.target=*parent}, *res));
    return res->id();
}

SceneID         SceneEditor::_create(const SceneInfo& info)
{
    Scene* res = Tachyon::create_on<Scene>(SIM, info);
    if(!res){
        yNotice() << "Unable to create scene (" << info.stem() << ") due to instantiation problem";
        return {};
    }
    return res->id();
}

static void     clearSimThread()
{
    const Frame* frame  = Frame::current();
    if(!frame)
        return ;

    ThreadID        simThread   = Thread::standard(SIM);
    auto zap = [&](TachyonID id){
        const TachyonData*  data    = frame->data(id);
        if(!data)
            return;
        if(data->owner != simThread)
            return;
        Tachyon*    tac = frame->object(id);
        if(!tac)
            return;
        tac -> cmd_teardown();
    };
    
    for(CameraID c : frame->ids(CAMERA))
        zap(c);
    for(ControllerID c : frame->ids(CONTROLLER))
        zap(c);
    for(LightID c : frame->ids(LIGHT))
        zap(c);
    for(ModelID c : frame->ids(MODEL))
        zap(c);
    for(RenderedID c : frame->ids(RENDERED))
        zap(c);
    for(SceneID c : frame->ids(SCENE))
        zap(c);
    for(SpatialID c : frame->ids(SPATIAL))
        zap(c);
}

void                    SceneEditor::_clear()
{
    const Frame* frame  = Frame::current();
    if(!frame)
        return ;

    m_layers.clear();

    clearSimThread();
}


void    SceneEditor::_open(const std::filesystem::path& fp)
{
    send(new LoadTSXRequest({ .source = *this, .target= gFileIO }, fp, SIM, clearSimThread));
}

void    SceneEditor::_rebuild()
{
    static const CameraTweakCPtr        s_originFix = new OriginCameraTweak();
    if(!m_scene.table)
        return;

    m_layers.clear();
    for(auto& e : m_scene.table->snaps()){
        if((e.scene != m_scene.selected) && !e.visible)
            continue;
        CLayer  lay;
        lay.scene   = e.scene;

        if(e.camera){
            lay.camera  = e.camera;
        } else if(e.info->is_this<HUDScene>()){ 
            lay.camera  = { m_camera.hud.id };
        } else if(e.info->is_this<BackgroundScene>()){
            lay.camera  = { m_camera.space.id };
            lay.tweaks.push_back(s_originFix);
        } else {
            lay.camera  = { m_camera.space.id };
        }
        
        m_layers.push_back(lay);
    }
    
    m_scene.rebuild = false;
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
    send(new SaveTSXRequest({.source=*this, .target=gFileIO}, fp, SIM, { SaveOption::SkipOwnership }));
}

void    SceneEditor::action_create_camera(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateInfo))){
        const CameraInfo*   info    = dynamic_cast<const CameraInfo*>(itr.second);
        if(!info)
            continue;
        CameraID    res = _create(*info);
        if(res && !m_camera.selected)
            _activate(res);
    }
}

void    SceneEditor::action_create_camera_spatial(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateInfo))){
        const SpatialInfo*   info    = dynamic_cast<const SpatialInfo*>(itr.second);
        if(!info)
            continue;
        _create(CAMERA, *info);
    }
}

void    SceneEditor::action_create_controller(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateInfo))){
        const ControllerInfo*   info    = dynamic_cast<const ControllerInfo*>(itr.second);
        if(!info)
            continue;
        ControllerID  res = _create(*info);
        if(res && !m_controller.selected)
            _activate(res);
    }
}

void    SceneEditor::action_create_light(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateInfo))){
        const LightInfo*   info    = dynamic_cast<const LightInfo*>(itr.second);
        if(!info)
            continue;
        LightID res = _create(*info);
        if(res && !m_light.selected)
            _activate(res);
    }
}

void    SceneEditor::action_create_light_spatial(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateInfo))){
        const SpatialInfo*   info    = dynamic_cast<const SpatialInfo*>(itr.second);
        if(!info)
            continue;
        _create(LIGHT, *info);
    }
}

void    SceneEditor::action_create_model(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateInfo))){
        const ModelInfo*   info    = dynamic_cast<const ModelInfo*>(itr.second);
        if(!info)
            continue;
        ModelID res = _create(*info);
        if(res && !m_model.selected)
            _activate(res);
    }
}

#if 0
void    SceneEditor::action_create_physics(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateInfo))){
        const PhysicsInfo*   info    = dynamic_cast<const PhysicsInfo*>(itr.second);
        if(!info)
            continue;
        PhysicsID res = _create(*info);
        if(res && !m_physics.selected)
            _activate(res);
    }
}
#endif

void    SceneEditor::action_create_rendered(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateInfo))){
        const RenderedInfo*   info    = dynamic_cast<const RenderedInfo*>(itr.second);
        if(!info)
            continue;
        RenderedID res = _create(*info);
        if(res && !m_rendered.selected)
            _activate(res);
    }
}

void    SceneEditor::action_create_rendered_spatial(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateInfo))){
        const SpatialInfo*   info    = dynamic_cast<const SpatialInfo*>(itr.second);
        if(!info)
            continue;
        _create(RENDERED, *info);
    }
}

void    SceneEditor::action_create_scene(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateInfo))){
        const SceneInfo*   info    = dynamic_cast<const SceneInfo*>(itr.second);
        if(!info)
            continue;
        SceneID res = _create(*info);
        if(res && !m_scene.selected)
            _activate(res);
        m_scene.rebuild = true;
    }
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

void    SceneEditor::cmd_screenshot()
{
    ViewerID        viewID  = viewer();
    TypedID         view(viewID.id, Type::Viewer);
    send(new ViewerScreenshotRequest({.target=view}));
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
    _activate(evt.camera());
}

void    SceneEditor::on_controller_select_event(const ControllerSelectEvent&evt)
{
    _activate(evt.controller());
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

void    SceneEditor::on_light_select_event(const LightSelectEvent&evt)
{
    _activate(evt.light());
}


void    SceneEditor::on_load_tsx_reply(const LoadTSXReply&rep)
{
    if(rep.response() != Response::QaPla)
        return ;
    
    const LoadTSXRequest* req = dynamic_cast<const LoadTSXRequest*>(rep.request());
    if(!req)
        return ;
    
    m_filepath  = req->filepath();
    _title();
}

void    SceneEditor::on_model_select_event(const ModelSelectEvent&evt)
{
    _activate(evt.model());
}

void    SceneEditor::on_rendered_select_event(const RenderedSelectEvent&evt)
{
    _activate(evt.rendered());
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

void    SceneEditor::on_scene_add_event(const SceneAddEvent&)
{
    m_scene.rebuild = true;
}

void    SceneEditor::on_scene_remove_event(const SceneRemoveEvent&)
{
    m_scene.rebuild = true;
}

void    SceneEditor::on_scene_select_event(const SceneSelectEvent&evt)
{
    _activate(evt.scene());
}

void    SceneEditor::on_scene_visibility_event(const SceneVisibilityEvent&)
{
    m_scene.rebuild = true;
}

void    SceneEditor::on_viewer_screenshot_reply(const ViewerScreenshotReply& rep)
{
    std::string     filename    = std::format("screenshot-{}.png", iso8601basic_now());
    if(rep.raster())
        rep.raster() -> save_to(filename);
}


void    SceneEditor::prerecord(ViContext&u) 
{
    if(m_scene.rebuild)
        _rebuild();
    CompositeWidget::prerecord(u);
}

Execution   SceneEditor::setup(const Context&ctx) 
{
    const Frame*    curFrame    = Frame::current();
    if(!curFrame)
        return WAIT;

        // Editor's default cameras/controllers go onto the auxillary thread
    if(!m_scene.simple){
        Scene*  scene   = create_child_on<SimpleScene>(AUX);
        scene->set_name("SceneEditor Default Scene");
        m_scene.simple  = *scene;
    }

    if(!m_camera.space){
        SpaceCamera::Param p;
        p.near      = 0.1;
        p.far       = 60.;
        p.position  = ZERO;
        
        Camera* cam     = create_child_on<SpaceCamera>(AUX, p);
        cam->set_name("SceneEditor Space Camera");
        m_camera.space  = *cam;
    }

    if(!m_camera.hud){
        // exact choice TBD (not yet created)
        NullCamera::Param p;
        Camera* cam     = create_child_on<NullCamera>(AUX, p);
        cam->set_name("SceneEditor HUD Camera");
        m_camera.hud    = *cam;
    }
    
    Camera* cam   = curFrame->object((CameraID) m_camera.space);
    if(!cam)
        return WAIT;
    
    if(!m_controller.space){ 
        Space³Controller::Param p;
        p.keyboard      = false;
        Space³Controller* sc    = create_on<Space³Controller>(AUX, m_camera.space, p);
        m_controller.space            = *sc;
    }
    
    if(!curFrame->contains(m_controller.space))
        return WAIT;
        
    if(!m_controller.init){
        TachyonID    vid    = viewer();
        if(!curFrame->contains(vid))
            return WAIT;
            
        send(new ListenCommand({.target=m_controller.space}, TypedID(vid, Type::Viewer)));
        m_controller.init = true;
    }

    Execution ret = Widget::setup(ctx);
    
    if(!m_camera.properties)
        m_camera.properties     = static_cast<InspectorUI*>(element(FIRST, "CameraInspector"));
    if(!m_camera.table)
        m_camera.table          = static_cast<CameraTableUI*>(element(FIRST, "CameraTable"));
    if(!m_controller.properties)
        m_controller.properties = static_cast<InspectorUI*>(element(FIRST, "ControllerInspector"));
    if(!m_controller.table)
        m_controller.table      = static_cast<ControllerTableUI*>(element(FIRST, "ControllerTable"));
    if(!m_light.properties)
        m_light.properties      = static_cast<InspectorUI*>(element(FIRST, "LightInspector"));
    if(!m_light.table)
        m_light.table           = static_cast<LightTableUI*>(element(FIRST, "LightTable"));
    if(!m_model.properties)
        m_model.properties      = static_cast<InspectorUI*>(element(FIRST, "ModelInspector"));
    if(!m_model.table)
        m_model.table           = static_cast<ModelTableUI*>(element(FIRST, "ModelTable"));
    if(!m_rendered.properties)
        m_rendered.properties   = static_cast<InspectorUI*>(element(FIRST, "RenderedInspector"));
    if(!m_rendered.table)
        m_rendered.table        = static_cast<RenderedTableUI*>(element(FIRST, "RenderedTable"));
    if(!m_scene.properties)
        m_scene.properties      = static_cast<InspectorUI*>(element(FIRST, "SceneInspector"));
    if(!m_scene.table)
        m_scene.table           = static_cast<SceneTableUI*>(element(FIRST, "SceneTable"));
        
    _activate((CameraID) m_camera.space );
    
    if(m_scene.rebuild)
        _rebuild();
    
    return ret;
}

Execution   SceneEditor::teardown(const Context&ctx) 
{
    _clear();       // eventually to have ref counting....
    return CompositeWidget::teardown(ctx);
}

Execution   SceneEditor::tick(const Context& ctx) 
{
    if(m_scene.rebuild)
        _rebuild();
    return CompositeWidget::tick(ctx);
}

    
