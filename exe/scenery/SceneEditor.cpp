////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SceneEditor.hpp"

//#include "InspectorUI.hpp"

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

#include <yq/errors.hpp>

#include <yq/assetvk/camera/SpaceCamera.hpp>
#include <yq/assetvk/controller/Space3Controller.hpp>
#include <yq/assetvk/menu/CreateMenuUI.hpp>
#include <yq/assetvk/scene/HUDScene.hpp>
#include <yq/assetvk/scene/BackgroundScene.hpp>
#include <yq/assetvk/scene/ForegroundScene.hpp>
#include <yq/assetvk/scene/SimpleScene.hpp>
#include <yq/assetvk/tweak/OriginCameraTweak.hpp>
#include <yq/assetvk/ui/UIFrameMetrics.hpp>
#include <yq/assetvk/ui/UIBuildableMetaList.hpp>
#include <yq/assetvk/ui/UISimpleTree.hpp>
#include <yq/assetvk/ui/UITachyonEditor.hpp>
#include <yq/assetvk/widget/FrameInspector.hpp>

#include <yq/date/dateutils.hpp>

#include <yq/luavk/LuaExecuteReply.hpp>
#include <yq/luavk/LuaExecuteFileRequest.hpp>
#include <yq/luavk/LuaExecuteStringRequest.hpp>
#include <yq/luavk/LuaTVM.hpp>
#include <yq/luavk/LuaWindowUI.hpp>

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/parameters.hpp>
#include <yq/tachyon/texture.hpp>

#include <yq/tachyon/api/Camera3.hpp>
#include <yq/tachyon/api/Camera3Data.hpp>

#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Light3.hpp>
#include <yq/tachyon/api/Light3Data.hpp>
#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/api/Rendered3Data.hpp>
#include <yq/tachyon/api/Scene.hpp>
#include <yq/tachyon/api/SceneData.hpp>
#include <yq/tachyon/app/Viewer.hpp>

#include <yq/tachyon/asset/Raster.hpp>

#include <yq/tachyon/camera/NullCamera.hpp>
#include <yq/tachyon/command/controller/ListenCommand.hpp>
#include <yq/tachyon/command/generic/SetSpatialCommand.hpp>
#include <yq/tachyon/command/thread/ScheduleCommand.hpp>
#include <yq/tachyon/command/ui/TitleCommand.hpp>

#include <yq/assetvk/event/panel/MetaSelectionChangedEvent.hpp>

#include <yq/tachyon/io/Save.hpp>
//#include <yq/tachyon/io/save/SaveXML.hpp>


#include <yq/tachyon/request/app/OpenFileRequest.hpp>

#include <yq/tachyon/reply/io/LoadTSXReply.hpp>
#include <yq/tachyon/reply/io/SaveTSXReply.hpp>
#include <yq/tachyon/reply/viewer/ViewerScreenshotReply.hpp>

#include <yq/tachyon/request/io/LoadTSXRequest.hpp>
#include <yq/tachyon/request/io/SaveTSXRequest.hpp>

#include <yq/tachyon/request/viewer/ViewerScreenshotRequest.hpp>

#include <yq/tachyon/spatial/SimpleSpatial3.hpp>


#include <yq/tachyon/ui/UIMenuBar.hpp>
#include <yq/tachyon/ui/UIPanelWriter.hpp>
#include <yq/tachyon/ui/UISection.hpp>
#include <yq/tachyon/ui/UIStyle.hpp>
#include <yq/tachyon/ui/UIWindow.hpp>
#include <yq/tachyon/ui/UIWriters.hxx>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

#include <yq/tachyon/ui/calc/SnapLeftToOtherRightUICalc.hpp>

#include <yq/tachyon/api/WidgetMetaWriter.hpp>

#include <yq/text/format.hpp>
#include <yq/text/transform.hpp>

#include <ImGuiFileDialog.h>

#include <iostream>

#include <yq/tachyon/api/Tachyon.hxx>
#include <yq/tachyon/errors.hpp>

YQ_TACHYON_IMPLEMENT(SceneEditor)

namespace errors {
    using namespace yq::errors;
    using missing_default_file  = error_db::entry<"No default scene file">;
    using cant_load_save_file   = error_db::entry<"Unable to load save file">;
}

Expect<TachyonPtrVector>    SceneEditor:: _load(const std::filesystem::path& fp)
{
    std::error_code ec;
    if(!std::filesystem::exists(fp, ec))
        return unexpected(ec);
    
    SaveCPtr    save    = Save::IO::load(fp, { .cache=Tristate::NO, .load=Tristate::YES });
    if(!save)
        return ::errors::cant_load_save_file();
    
    TachyonPtrVector    tachyons;
    ec   = save->execute(tachyons);
    if(ec != std::error_code())
        return unexpected(ec);
    return tachyons;
}


void     SceneEditor::clear_edit_thread()
{
    clear_thread(Thread::standard(EDIT));
}

void     SceneEditor::clear_aux_thread()
{
    clear_thread(Thread::standard(AUX));
}

void     SceneEditor::clear_thread(ThreadID owner)
{
    const Frame* frame  = Frame::current();
    if(!frame)
        return ;

    auto zap = [&](TachyonID id){
        const TachyonData*  data    = frame->data(id);
        if(!data)
            return;
        if(data->owner != owner)
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


SceneEditor::EFlags       SceneEditor::flags_for(const CameraMeta& sc)
{
    EFlags  ret = {};
    return ret;
}

SceneEditor::EFlags       SceneEditor::flags_for(const SceneMeta& sc)
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

void SceneEditor::init_meta()
{
    auto w          = writer<SceneEditor>();
    w.description("The main widget");
    init_slots();
    init_ui();

}

void SceneEditor::init_slots()
{
    auto w          = writer<SceneEditor>();
    w.slot(&SceneEditor::on_camera_select_event);
    w.slot(&SceneEditor::on_controller_select_event);
    w.slot(&SceneEditor::on_load_tsx_reply);
    w.slot(&SceneEditor::on_lua_exec_reply);
    w.slot(&SceneEditor::on_meta_selection_changed_event);
    w.slot(&SceneEditor::on_model_select_event);
    w.slot(&SceneEditor::on_rendered_select_event);
    w.slot(&SceneEditor::on_save_tsx_reply);
    w.slot(&SceneEditor::on_scene_add_event);
    w.slot(&SceneEditor::on_scene_remove_event);
    w.slot(&SceneEditor::on_scene_select_event);
    w.slot(&SceneEditor::on_scene_visibility_event);
    w.slot(&SceneEditor::on_viewer_screenshot_reply);
}

void SceneEditor::init_ui()
{
    auto w          = writer<SceneEditor>();
    auto app        = w.imgui(UI, APP);
    auto menuBar    = app.menubar(MAIN);
    menuBar.uid("mmb");
    
    /////////////////////////////////
    //  CONTROL PANEL

    auto controlPanel       = app.make<UIPanel>("Control Panel", UIFlags{ UIFlag::NoCollapse });
    //auto controlPanel       = app.make<ControlPanelUI>();
    {
        controlPanel.uid("ControlPanel");
        controlPanel.width(MIN, PIVOT, 0.1);
        controlPanel.width(MAX, PIVOT, 0.8);
        controlPanel.width(START, PIVOT, 0.2);
        auto controlTree        = controlPanel.make<UISimpleTree>();

        {
            auto csMetrics          = controlTree.section("Metrics");
            csMetrics.make<UIFrameMetrics>();
        }

        {
            auto csCameras          = controlTree.section("Cameras").make<UISimpleTree>();
            auto blCameras          = csCameras.section("Available").make<UIBuildableMetaList<Camera>>();
            auto curCameras         = csCameras.section("Current").make<CameraTableUI>();
            auto propCameras        = csCameras.section("Properties");
            auto addSpatial         = propCameras << new CreateMenuUI("Add/Create Spatial##AddCameraSpatialUI", meta<Spatial>());
            auto inspCameras        = propCameras.make<UITachyonEditor>();

            blCameras.uid("CameraAvailable");
            blCameras.flag(SET, UIFlag::EmitSignal);

            curCameras.uid("CameraTable");

            addSpatial.action(&SceneEditor::action_create_camera_spatial);

            inspCameras.uid("CameraInspector");
            inspCameras.flag(SET, UIFlag::Children);
        }
        
        {
            auto csControllers      = controlTree.section("Controllers").make<UISimpleTree>();
            auto blControllers      = csControllers.section("Available").make<UIBuildableMetaList<Controller>>();
            auto curControllers     = csControllers.section("Current").make<ControllerTableUI>();
            auto propControllers    = csControllers.section("Properties");
            //auto addSpatial         = propControllers << new CreateMenuUI("Add/Create Spatial##AddControllerSpatialUI", meta<Spatial>());
            auto inspControllers    = propControllers.make<UITachyonEditor>();

            blControllers.uid("ControllerAvailable");
            blControllers.flag(SET, UIFlag::EmitSignal);

            curControllers.uid("ControllerTable");

            //addSpatial.action(&SceneEditor::action_create_camera_spatial);

            inspControllers.uid("ControllerInspector");
            inspControllers.flag(SET, UIFlag::Children);
        }
        
        {
            //auto csCollisions       = controlTree.section("Collisions").make<UISimpleTree>();
            //auto blCollisions       = csControllers.section("Available").make<UIBuildableList<Controller>>();
            //auto curCollisions      = csControllers.section("Current").make<CollisionTableUI>();
            //auto propCollisions       = csCollisions.section("Properties");
            //auto addSpatial           = propCollisions << new CreateMenuUI("Add/Create Spatial##AddCollisionSpatialUI", meta<Spatial>());
            //auto inspCollisions       = propCollisions.make<UITachyonEditor>();

            //blCollisions.uid("CollisionAvailable");
            //blCollisions.flag(SET, UIFlag::EmitSignal);

            //curCollisions.uid("CollisionTable");

            //addSpatial.action(&SceneEditor::action_create_controller_spatial);

            //inspControllers.uid("ControllerInspector");
            //inspControllers.flag(SET, UIFlag::Children);
        }
        
        {
            auto csLights           = controlTree.section("Lights").make<UISimpleTree>();
            auto blLights           = csLights.section("Available").make<UIBuildableMetaList<Light>>();
            auto curLights          = csLights.section("Current").make<LightTableUI>();
            auto propLights         = csLights.section("Properties");
            auto addSpatial         = propLights << new CreateMenuUI("Add/Create Spatial##AddLightSpatialUI", meta<Spatial>());
            auto inspLights         = propLights.make<UITachyonEditor>();

            blLights.uid("LightAvailable");
            blLights.flag(SET, UIFlag::EmitSignal);

            curLights.uid("LightTable");

            addSpatial.action(&SceneEditor::action_create_light_spatial);

            inspLights.uid("LightInspector");
            inspLights.flag(SET, UIFlag::Children);
        }
        
        {
            //auto csModels           = controlTree.section("Models").make<UISimpleTree>();
            //auto blModels           = csModels.section("Available").make<UIBuildableMetaList<Model>>();
            //auto curModels          = csModels.section("Current").make<ModelTableUI>();
            //auto propModels         = csModels.section("Properties");
            //auto addSpatial         = propModels << new CreateMenuUI("Add/Create Spatial##AddModelSpatialUI", meta<Spatial>());
            //auto inspModels         = propModels.make<UITachyonEditor>();

            //blModels.uid("ModelAvailable");
            //blModels.flag(SET, UIFlag::EmitSignal);

            //curModels.uid("ModelTable");
            
            //addSpatial.action(&SceneEditor::action_create_model_spatial);

            //inspModels.uid("ModelInspector");
            //inspModels.flag(SET, UIFlag::Children);
        }

        {
            //auto csPhysics          = controlTree.section("Physics").make<UISimpleTree>();
            //auto blPhysics          = csPhysics.section("Available").make<UIBuildableMetaList<Physic>>();
            //auto curPhysics         = csPhysics.section("Current").make<PhysicsTableUI>();
            //auto propPhysics        = csPhysics.section("Properties");
            //auto addSpatial         = propPhysics << new CreateMenuUI("Add/Create Spatial##AddPhysicsSpatialUI", meta<Spatial>());

            //blPhysics.uid("PhysicsAvailable");
            //blPhysics.flag(SET, UIFlag::EmitSignal);

            //curPhysics.uid("PhysicsTable");

            //addSpatial.action(&SceneEditor::action_create_physics_spatial);

            //inspPhysics.uid("PhysicsInspector");
            //inspPhysics.flag(SET, UIFlag::Children);
        }

        {
            auto csRendereds        = controlTree.section("Rendereds").make<UISimpleTree>();
            auto blRendereds        = csRendereds.section("Available").make<UIBuildableMetaList<Rendered>>();
            auto curRendereds       = csRendereds.section("Current").make<RenderedTableUI>();
            auto propRendereds      = csRendereds.section("Properties");
            auto addSpatial         = propRendereds << new CreateMenuUI("Add/Create Spatial##AddRenderedSpatialUI", meta<Spatial>());
            auto inspRendereds      = propRendereds.make<UITachyonEditor>();

            blRendereds.uid("RenderedAvailable");
            blRendereds.flag(SET, UIFlag::EmitSignal);
            
            curRendereds.uid("RenderedTable");

            addSpatial.action(&SceneEditor::action_create_rendered_spatial);

            inspRendereds.uid("RenderedInspector");
            inspRendereds.flag(SET, UIFlag::Children);
        }

        {
            auto csScenes           = controlTree.section("Scenes").make<UISimpleTree>();
            auto blScenes           = csScenes.section("Available").make<UIBuildableMetaList<Scene>>();
            auto curScenes          = csScenes.section("Current").make<SceneTableUI>();
            auto propScenes         = csScenes.section("Properties");
            auto inspScenes         = propScenes.make<UITachyonEditor>();

            blScenes.uid("SceneAvailable");
            blScenes.flag(SET, UIFlag::EmitSignal);

            curScenes.uid("SceneTable");

            inspScenes.uid("SceneInspector");
            inspScenes.flag(SET, UIFlag::Children);
        }

        {
            auto csSpatials         = controlTree.section("Spatials").make<UISimpleTree>();
            auto blSpatials         = csSpatials.section("Available").make<UIBuildableMetaList<Spatial>>();
            //auto curSpatials         = csSpatials.section("Current").make<SpatialTableUI>();
            //auto propSpatials        = csSpatials.section("Properties");
            //auto inspSpatials        = propSpatials.make<UITachyonEditor>();
            
            //blSpatials.uid("SpatialAvailable");
            //blSpatials.flag(SET, UIFlag::EmitSignal);
            
            //curSpatials.uid("SpatialTable");

            //addSpatial.action(&SceneEditor::action_create_camera_spatial);

            //inspSpatials.uid("SpatialInspector");
            //inspSpatials.flag(SET, UIFlag::Children);
        }
    }

    /////////////////////////////////
    //  LUA
    
    auto luaPanel  = app.make<LuaWindowUI>("Lua Panel", UIFlags({UIFlag::NoCollapse, UIFlag::NoResize, UIFlag::Invisible, UIFlag::NoBackground}));
    luaPanel.uid("LuaWindow");
    luaPanel.top(PIVOT, 0.75);
    luaPanel.left("ControlPanel", RIGHT);
    

    /////////////////////////////////
    //  FRAME

    auto framePanel         = app.make<UIPanel>("Frame Inspector", UIFlags({UIFlag::NoCollapse, UIFlag::Invisible}));
    framePanel.uid("FramePanel");
    framePanel.bottom("LuaWindow", TOP);
    framePanel.left(PIVOT, 0.75);
    
    

    /////////////////////////////////
    //  MENUS
    
    auto fileMenu           = menuBar.menu("File");
    {
        fileMenu.menuitem("New").action(&SceneEditor::cmd_file_new);
        fileMenu.menuitem("Open", "Ctrl+O").action(&SceneEditor::cmd_file_open);
        fileMenu.menuitem("Save", "Ctrl+S").action(&SceneEditor::cmd_file_save);
        fileMenu.menuitem("Save As").action(&SceneEditor::cmd_file_save_as);
        fileMenu.menuitem("Screenshot", "F12").action(&SceneEditor::cmd_screenshot);
        fileMenu.separator();
        fileMenu.menuitem("Import").action(&SceneEditor::cmd_file_import);
        
        fileMenu.menuitem("Execute Lua...").action(&SceneEditor::cmd_file_lua_execute);
    }
    
    auto editMenu          = menuBar.menu("Edit");
    {
        editMenu.menuitem("Copy", "Ctrl+C");
        editMenu.menuitem("Paste", "Ctrl+V");
    }
    
    auto viewMenu           = menuBar.menu("View");
    {
        viewMenu.checkbox(VISIBLE, controlPanel);
        viewMenu.checkbox(VISIBLE, luaPanel);
        viewMenu.checkbox(VISIBLE, framePanel);
    }
    
    auto cameraMenu        = menuBar.menu("Camera");
    {
        (cameraMenu << new CreateMenuUI("Add/Create##AddCameraUI", meta<Camera>())).action(&SceneEditor::action_create_camera);
    }
    
    auto sceneMenu         = menuBar.menu("Scene");
    {
        (sceneMenu << new CreateMenuUI("Add/Create##AddSceneUI", meta<Scene>())).action(&SceneEditor::action_create_scene);
    }
    
    auto lightMenu         = menuBar.menu("Light");
    {
        (lightMenu << new CreateMenuUI("Add/Create##AddLightUI", meta<Light>())).action(&SceneEditor::action_create_light);
    }
    
    auto renderedMenu      = menuBar.menu("Rendered");
    {
        (renderedMenu << new CreateMenuUI("Add/Create##AddRenderedUI", meta<Rendered>())).action(&SceneEditor::action_create_rendered);
    }
    
    
    auto modelMenu         = menuBar.menu("Model");
    {
        //(model_menu << new CreateMenuUI("Add/Create##AddModelUI", meta<Model>())).action(&SceneEditor::action_create_model);
    }
    
    auto controllerMenu     = menuBar.menu("Controller");
    {
        //(controller_menu << new CreateMenuUI("Add/Create##AddControllerUI", meta<Controller>())).action(&SceneEditor::action_create_controller);
    }
    
    auto collisionMenu     = menuBar.menu("Collision");
    {
    }
    
    auto physicsMenu       = menuBar.menu("Physics");
    {
    }
    
    auto windowMenu        = menuBar.menu("Window");
    {
    }
    
    auto helpMenu          = menuBar.menu("Help");
    {
    }
    
    auto debugMenu         = menuBar.menu("Debug");
    {
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

SceneEditor::SceneEditor(PostStartupFN&& mv) : m_startup(std::move(mv))
{
}

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
yInfo() << "Activating scene " << id.id;
    //if(m_scene.selected == id)
        //return;
    m_scene.selected   = id;
    if(m_scene.table && (m_scene.table->selected() != id))
        m_scene.table -> set_selected(id);
    if(m_scene.properties && (m_scene.properties->bound() != id))
        m_scene.properties -> bind(TypedID(id.id, Type::Scene));
}

CameraID        SceneEditor::_create(const CameraMeta& meta)
{
    Camera* res = Tachyon::create_on<Camera>(EDIT, meta);
    if(!res){
        yNotice() << "Unable to create camera (" << meta.stem() << ") due to instantiation problem";
        return {};
    }
    return res->id();
}

SpatialID       SceneEditor::_create(camera_k, const SpatialMeta& meta)
{
    TypedID     pid = typed_for(m_camera.selected);
    if(pid(Type::Camera³))
        return _create((Camera³ID) m_camera.selected, meta);
    return {};
}

SpatialID       SceneEditor::_create(Camera³ID pid, const SpatialMeta& meta)
{
    Camera³*    parent  = pointer(pid);
    if(!parent) {
        yNotice() << "Unable to create spatial (" << meta.stem() << ") due to no corresponding camera (id " << pid.id << ")";
        return {};
    }
    
    const Camera³Snap*    psnap   = snapshot(pid);
    if(!psnap){
        yNotice() << "Unable to create spatial (" << meta.stem() << ") due to no corresponding camera (id " << pid.id << ") on the frame";
        return {};
    }
    
    Spatial*   res  = parent->create_child_on<Spatial>(EDIT, meta);
    if(!res){
        yNotice() << "Unable to create spatial (" << meta.stem() << ") due to instantiation problem";
        return {};
    }
    
    if(!psnap->spatial)
        send(new SetSpatialCommand({.target=*parent}, *res));
    return res->id();
}

ControllerID    SceneEditor::_create(const ControllerMeta& meta)
{
    Controller* res = Tachyon::create_on<Controller>(EDIT, meta);
    if(!res){
        yNotice() << "Unable to create controller (" << meta.stem() << ")";
        return {};
    }
    return res->id();
}

LightID         SceneEditor::_create(const LightMeta& meta)
{
    Scene*  parent  = pointer(m_scene.selected);
    if(!parent){
        yNotice() << "Unable to create light (" << meta.stem() << ") due to no parent scene";
        return {};
    }
    
    Light*    res  = Tachyon::create<Light>(meta);
    if(!res){
        yNotice() << "Unable to create light (" << meta.stem() << ") due to instantiation problem";
        return {};
    }
    res -> set_parent(*parent);
    res -> owner(PUSH, EDIT);
    return res->id();
}

SpatialID       SceneEditor::_create(light_k, const SpatialMeta& meta)
{
    TypedID     pid = typed_for(m_light.selected);
    if(pid(Type::Light³))
        return _create((Light³ID) m_light.selected, meta);
    return {};
}

SpatialID       SceneEditor::_create(Light³ID pid, const SpatialMeta& meta)
{
    Light³*     parent  = pointer(pid);
    if(!parent) {
        yNotice() << "Unable to create spatial (" << meta.stem() << ") due to no corresponding light (id " << pid.id << ")";
        return {};
    }
    
    const Light³Snap*     psnap   = snapshot(pid);
    if(!psnap){
        yNotice() << "Unable to create spatial (" << meta.stem() << ") due to no corresponding light (id " << pid.id << ") on the frame";
        return {};
    }
    
    Spatial*    res  = parent->create_child_on<Spatial>(EDIT, meta);
    if(!res){
        yNotice() << "Unable to create spatial (" << meta.stem() << ") due to instantiation problem";
        return {};
    }
    
    if(!psnap->spatial)
        send(new SetSpatialCommand({.target=*parent}, *res));
    return res->id();
}

ModelID         SceneEditor::_create(const ModelMeta& meta)
{
    Model* res = Tachyon::create_on<Model>(EDIT, meta);
    if(!res){
        yNotice() << "Unable to create model (" << meta.stem() << ") due to instantiation problem";
        return {};
    }
    return res->id();
}

RenderedID      SceneEditor::_create(const RenderedMeta& meta)
{
    Scene*  parent  = pointer(m_scene.selected);
    if(!parent){
        yNotice() << "Unable to create rendered (" << meta.stem() << ") due to no parent scene";
        return {};
    }
    
    Rendered*    res  = Tachyon::create<Rendered>(meta);
    if(!res){
        yNotice() << "Unable to create rendered (" << meta.stem() << ") due to instantiation problem";
        return {};
    }
 
    res -> rebuild();
    res -> set_parent(*parent);
    res -> owner(PUSH, EDIT);
    return res->id();
}

SpatialID       SceneEditor::_create(rendered_k, const SpatialMeta& meta)
{
    TypedID     pid = typed_for(m_rendered.selected);
    if(pid(Type::Rendered³))
        return _create((Rendered³ID) m_rendered.selected, meta);
    return {};
}

SpatialID       SceneEditor::_create(Rendered³ID pid, const SpatialMeta& meta)
{
    Rendered³*     parent  = pointer(pid);
    if(!parent){
        yNotice() << "Unable to create spatial (" << meta.stem() << ") due to no corresponding rendered (id " << pid.id << ")";
        return {};
    }
    
    const Rendered³Snap*     psnap   = snapshot(pid);
    if(!psnap){
        yNotice() << "Unable to create spatial (" << meta.stem() << ") due to no corresponding rendered (id " << pid.id << ") on the frame";
        return {};
    }
    
    Spatial*    res  = parent->create_child_on<Spatial>(EDIT, meta);
    if(!res){
        yNotice() << "Unable to create spatial (" << meta.stem() << ") due to instantiation problem";
        return {};
    }
    
    if(!psnap->spatial)
        send(new SetSpatialCommand({.target=*parent}, *res));
    return res->id();
}

SceneID         SceneEditor::_create(const SceneMeta& meta)
{
    Scene* res = Tachyon::create_on<Scene>(EDIT, meta);
    if(!res){
        yNotice() << "Unable to create scene (" << meta.stem() << ") due to instantiation problem";
        return {};
    }
    return res->id();
}

void                    SceneEditor::_clear()
{
    const Frame* frame  = Frame::current();
    if(!frame)
        return ;

    m_layers.clear();
    clear_edit_thread();
}

void    SceneEditor::_default()
{
    auto                tachload    = _default_load();  // TODO ... overridable default
    bool                hasDef      = tachload.has_value();
    TachyonPtrVector    tachyons;

    if(hasDef){
        tachyons    = std::move(*tachload);

        for(TachyonPtr& tp : tachyons){
            if(dynamic_cast<SpaceCamera*>(tp.ptr()))
                m_camera.space  = *tp;
            if(auto p = dynamic_cast<SimpleScene*>(tp.ptr())){
                m_scene.simple      = *p;
                m_scene.selected    = p->id();
            }
        }
    }

        // Editor's default cameras/controllers go onto the auxillary thread
    if(!m_scene.simple){
        Scene*  scene   = create_on<SimpleScene>(AUX);
        scene->set_name("SceneEditor Default Scene");
        m_scene.simple  = *scene;
        m_scene.selected    = scene -> id();
    }
    
    if(!m_camera.space){
        SpaceCamera::Param p;
        p.near      = 0.1;
        p.far       = 60.;
        p.position  = ZERO;
        
        Camera* cam     = create_on<SpaceCamera>(AUX, p);
        cam->set_name("SceneEditor Space Camera");
        m_camera.space  = *cam;
    }

    if(!m_camera.hud){
        // exact choice TBD (not yet created)
        NullCamera::Param p;
        Camera* cam     = create_on<NullCamera>(AUX, p);
        cam->set_name("SceneEditor HUD Camera");
        m_camera.hud    = *cam;
    }

    if(hasDef)
        _schedule(AUX, std::move(tachyons));
}

Expect<TachyonPtrVector>     SceneEditor::_default_load(std::string_view pp)
{
    std::error_code ec;
    Url   deftsx  = Resource::resolve(pp);
    if(deftsx.path.empty())
        return ::errors::missing_default_file();
    return _load(deftsx.path);
}

void    SceneEditor::_import(const std::filesystem::path& fp, StdThread st)
{
    send(new LoadTSXRequest({ .source = *this, .target= gFileIO }, fp, {
        .owner  = st,
        .parent = TypedID(pointer(m_scene.selected))
    }));
}

void    SceneEditor::_lua(const std::filesystem::path& fp)
{
    send(new LuaExecuteFileRequest({.target=m_lua.tvm}, fp));
}

void    SceneEditor::_open(const std::filesystem::path& fp, StdThread st)
{
    send(new LoadTSXRequest({ .source = *this, .target= gFileIO }, fp, {
        .owner  = st,
        .parent = TypedID(pointer(m_scene.selected))
    }, SceneEditor::clear_edit_thread));
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

void    SceneEditor::_save(const std::filesystem::path& fp, ThreadSpec st)
{
    const Frame* frame  = Frame::current();
    if(!frame)
        return ;
        
    SaveTSXRequest::Config cfg;
    cfg.thread   = EDIT;
    cfg.flags   |= SaveFlag::SkipOwnership;
    send(new SaveTSXRequest({.source=*this, .target=gFileIO}, fp, cfg));
}

void        SceneEditor::_schedule(StdThread st, TachyonPtrVector&& tachyons)
{
    _schedule(Thread::standard(st), std::move(tachyons));
}

void        SceneEditor::_schedule(ThreadID owner, TachyonPtrVector&& tachyons)
{
    for(TachyonPtr& tp : tachyons){
        if(dynamic_cast<Light*>(tp.ptr()) || dynamic_cast<Rendered*>(tp.ptr())){
            if(tp->parent())
                continue;
            tp -> load_set_parent(m_scene.simple);
        }
    }

    TypedID         ownerT( owner.id, Type::Thread );
    mail(owner, new ScheduleCommand({.target=ownerT}, std::move(tachyons)));
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


void    SceneEditor::action_create_camera(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateMeta))){
        const CameraMeta*   meta    = dynamic_cast<const CameraMeta*>(itr.second);
        if(!meta)
            continue;
        CameraID    res = _create(*meta);
        if(res && !m_camera.selected)
            _activate(res);
    }
}

void    SceneEditor::action_create_camera_spatial(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateMeta))){
        const SpatialMeta*   meta    = dynamic_cast<const SpatialMeta*>(itr.second);
        if(!meta)
            continue;
        _create(CAMERA, *meta);
    }
}

void    SceneEditor::action_create_controller(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateMeta))){
        const ControllerMeta*   meta    = dynamic_cast<const ControllerMeta*>(itr.second);
        if(!meta)
            continue;
        ControllerID  res = _create(*meta);
        if(res && !m_controller.selected)
            _activate(res);
    }
}

void    SceneEditor::action_create_light(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateMeta))){
        const LightMeta*   meta    = dynamic_cast<const LightMeta*>(itr.second);
        if(!meta)
            continue;
        LightID res = _create(*meta);
        if(res && !m_light.selected)
            _activate(res);
    }
}

void    SceneEditor::action_create_light_spatial(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateMeta))){
        const SpatialMeta*   meta    = dynamic_cast<const SpatialMeta*>(itr.second);
        if(!meta)
            continue;
        _create(LIGHT, *meta);
    }
}

void    SceneEditor::action_create_model(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateMeta))){
        const ModelMeta*   meta    = dynamic_cast<const ModelMeta*>(itr.second);
        if(!meta)
            continue;
        ModelID res = _create(*meta);
        if(res && !m_model.selected)
            _activate(res);
    }
}

#if 0
void    SceneEditor::action_create_physics(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateMeta))){
        const PhysicsInfo*   meta    = dynamic_cast<const PhysicsInfo*>(itr.second);
        if(!meta)
            continue;
        PhysicsID res = _create(*meta);
        if(res && !m_physics.selected)
            _activate(res);
    }
}
#endif

void    SceneEditor::action_create_rendered(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateMeta))){
        const RenderedMeta*   meta    = dynamic_cast<const RenderedMeta*>(itr.second);
        if(!meta)
            continue;
        RenderedID res = _create(*meta);
        if(res && !m_rendered.selected)
            _activate(res);
    }
}

void    SceneEditor::action_create_rendered_spatial(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateMeta))){
        const SpatialMeta*   meta    = dynamic_cast<const SpatialMeta*>(itr.second);
        if(!meta)
            continue;
        _create(RENDERED, *meta);
    }
}

void    SceneEditor::action_create_scene(const Payload& pay)
{
    for(auto& itr : as_iterable(pay.m_metas.equal_range(kParam_CreateMeta))){
        const SceneMeta*   meta    = dynamic_cast<const SceneMeta*>(itr.second);
        if(!meta)
            continue;
        SceneID res = _create(*meta);
        if(res && !m_scene.selected)
            _activate(res);
        m_scene.rebuild = true;
    }
}

void    SceneEditor::cmd_file_import()
{
    IGFD::FileDialogConfig config;
    config.path = ".";
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File to IMport", ".tsx", config);        
    m_fileMode  = FileMode::Import;
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

void    SceneEditor::cmd_file_lua_execute()
{
    #ifdef YQ_LUA_ENABLE
    IGFD::FileDialogConfig config;
    config.path = ".";
    ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose Lua File to LuaExecute", ".lua", config);        
    m_fileMode  = FileMode::Lua;
    #endif
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
                
                switch(m_fileMode){
                case FileMode::None:
                    break;
                case FileMode::Import:
                    _import(filePathName);
                    break;
                case FileMode::Open:
                    _open(filePathName);
                    break;
                case FileMode::Save:
                    _save(filePathName);
                    break;
                case FileMode::Lua:
                    _lua(filePathName);
                    break;
                }
                m_fileMode  = FileMode::None;
            }
            ImGuiFileDialog::Instance()->Close();
        }
    }
    
    Widget::imgui(u);
}

void    SceneEditor::on_camera_select_event(const CameraSelectEvent&evt)
{
    _activate(evt.camera());
}

void    SceneEditor::on_controller_select_event(const ControllerSelectEvent&evt)
{
    _activate(evt.controller());
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

void    SceneEditor::on_lua_exec_reply(const LuaExecuteReply& evt)
{
    #if YQ_LUA_ENABLE
    if(m_lua.panel)
        m_lua.panel -> submit(evt);
    #endif
}

void    SceneEditor::on_meta_selection_changed_event(const MetaSelectionChangedEvent&evt)
{
    if(const CameraMeta* p = dynamic_cast<const CameraMeta*>(evt.meta()))
        m_camera.meta       = p;
    if(const RenderedMeta* p = dynamic_cast<const RenderedMeta*>(evt.meta()))
        m_rendered.meta     = p;
    if(const SceneMeta* p = dynamic_cast<const SceneMeta*>(evt.meta()))
        m_scene.meta        = p;
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
        

    if(!m_defaultInit){
        _default();
        m_defaultInit   = true;
    }
    
    if(!m_lua.tvm){
        LuaTVM*     ch = create_on<LuaTVM>(AUX);
        m_lua.tvm      = *ch;
        
        subscribe(ch->id());

        //  might do some standard configuration (later)

        return WAIT;
    } else {
        if(!curFrame->object(m_lua.tvm))
            return WAIT;
    }


    Camera* cam   = curFrame->object((CameraID) m_camera.space);
    if(!cam)
        return WAIT;
    
        // these will eventually go to the default too....
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
        #ifdef YQ_LUA_ENABLE
            send(new ListenCommand({.target=m_lua.tvm}, *this));
        #endif

        m_controller.init = true;
    }

    // end of default....

    Execution ret = Widget::setup(ctx);
    
    if(!m_camera.properties)
        m_camera.properties     = static_cast<UITachyonEditor*>(element(FIRST, "CameraInspector"));
    if(!m_camera.table)
        m_camera.table          = static_cast<CameraTableUI*>(element(FIRST, "CameraTable"));
    if(!m_controller.properties)
        m_controller.properties = static_cast<UITachyonEditor*>(element(FIRST, "ControllerInspector"));
    if(!m_controller.table)
        m_controller.table      = static_cast<ControllerTableUI*>(element(FIRST, "ControllerTable"));
    if(!m_light.properties)
        m_light.properties      = static_cast<UITachyonEditor*>(element(FIRST, "LightInspector"));
    if(!m_light.table)
        m_light.table           = static_cast<LightTableUI*>(element(FIRST, "LightTable"));
    if(!m_model.properties)
        m_model.properties      = static_cast<UITachyonEditor*>(element(FIRST, "ModelInspector"));
    if(!m_model.table)
        m_model.table           = static_cast<ModelTableUI*>(element(FIRST, "ModelTable"));
    if(!m_rendered.properties)
        m_rendered.properties   = static_cast<UITachyonEditor*>(element(FIRST, "RenderedInspector"));
    if(!m_rendered.table)
        m_rendered.table        = static_cast<RenderedTableUI*>(element(FIRST, "RenderedTable"));
    if(!m_scene.properties)
        m_scene.properties      = static_cast<UITachyonEditor*>(element(FIRST, "SceneInspector"));
    if(!m_scene.table)
        m_scene.table           = static_cast<SceneTableUI*>(element(FIRST, "SceneTable"));

    if(!m_lua.panel){
        m_lua.panel             = static_cast<LuaWindowUI*>(element(FIRST, "LuaWindow"));
        m_lua.panel -> tvm(SET, m_lua.tvm);
        m_lua.panel -> info("Scenery Editor's Lua Panel, try help() to get started");
    }
        
    _activate((CameraID) m_camera.space );
    
    if(m_scene.rebuild)
        _rebuild();
        
    if(m_startup){
        m_startup(*this);
        m_startup   = {};
    }

#if FRAME_INSPECTOR    
    if(!m_inspector){
        m_inspector     = create_child<FrameInspector>();
    }
#endif

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

    
