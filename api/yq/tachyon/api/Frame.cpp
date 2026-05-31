////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Frame.hpp"

#include <yq/tachyon/api/Controller.hpp>
#include <yq/tachyon/api/ControllerData.hpp>
#include <yq/tachyon/api/FrameBuilder.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/api/Manager.hpp>
#include <yq/tachyon/api/ManagerData.hpp>
//#include <yq/tachyon/api/Post.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/api/ThreadData.hpp>

#include <yq/tachyon/api/Camera3.hpp>
#include <yq/tachyon/api/Camera3Data.hpp>
#include <yq/tachyon/api/Group.hpp>
#include <yq/tachyon/api/GroupData.hpp>

#include <yq/tachyon/api/Kinetic3.hpp>
#include <yq/tachyon/api/Kinetic3Data.hpp>

#include <yq/tachyon/api/Layer.hpp>
#include <yq/tachyon/api/LayerData.hpp>
#include <yq/tachyon/api/Light3.hpp>
#include <yq/tachyon/api/Light3Data.hpp>
#include <yq/tachyon/api/Physics.hpp>
#include <yq/tachyon/api/PhysicsData.hpp>

#include <yq/tachyon/api/Rendered3.hpp>
#include <yq/tachyon/api/Rendered3Data.hpp>
#include <yq/tachyon/api/Scene3.hpp>
#include <yq/tachyon/api/Scene3Data.hpp>
#include <yq/tachyon/api/Spatial2.hpp>
#include <yq/tachyon/api/Spatial2Data.hpp>
#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/api/Spatial3Data.hpp>

#include <yq/tachyon/app/Engine.hpp>
#include <yq/tachyon/app/EngineData.hpp>
#include <yq/tachyon/app/Master.hpp>
#include <yq/tachyon/app/MasterData.hpp>
#include <yq/tachyon/app/Viewer.hpp>
#include <yq/tachyon/app/ViewerData.hpp>

#include <yq/tachyon/os/Cursor.hpp>
#include <yq/tachyon/os/CursorData.hpp>
#include <yq/tachyon/os/Desktop.hpp>
#include <yq/tachyon/os/DesktopData.hpp>
#include <yq/tachyon/os/Gamepad.hpp>
#include <yq/tachyon/os/GamepadData.hpp>
#include <yq/tachyon/os/GraphicsCard.hpp>
#include <yq/tachyon/os/GraphicsCardData.hpp>
#include <yq/tachyon/os/Joystick.hpp>
#include <yq/tachyon/os/JoystickData.hpp>
#include <yq/tachyon/os/Keyboard.hpp>
#include <yq/tachyon/os/KeyboardData.hpp>
#include <yq/tachyon/os/Monitor.hpp>
#include <yq/tachyon/os/MonitorData.hpp>
#include <yq/tachyon/os/Mouse.hpp>
#include <yq/tachyon/os/MouseData.hpp>
#include <yq/tachyon/os/Window.hpp>
#include <yq/tachyon/os/WindowData.hpp>

//#include <yq/tachyon/api/Editor.hpp>
//#include <yq/tachyon/api/EditorData.hpp>
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/api/WidgetData.hpp>

#include <yq/tachyon/api/Camera.hpp>
#include <yq/tachyon/api/CameraData.hpp>
#include <yq/tachyon/api/Light.hpp>
#include <yq/tachyon/api/LightData.hpp>
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/api/RenderedData.hpp>
#include <yq/tachyon/api/Scene.hpp>
#include <yq/tachyon/api/SceneData.hpp>

#include <yq/tachyon/api/Model.hpp>
#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/api/Spatial.hpp>
#include <yq/tachyon/api/SpatialData.hpp>

#include <yq/core/Enumeration.hpp>
#include <yq/core/StreamOps.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/meta/ObjectMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Frame)

namespace yq::tachyon {
    void Frame::init_meta()
    {
        auto w = writer<Frame>();
        w.description("Tachyon Frame");
        w.abstract();
    }


    template <typename T, typename D, typename S>
    size_t   Frame::Container<T,D,S>::count() const
    {
        return objects.size();
    }

    template <typename T, typename D, typename S>
    const D*   Frame::Container<T,D,S>::data(uint64_t n) const
    {
        auto i = datas.find(n);
        if(i != datas.end())
            return i->second.ptr();
        return nullptr;
    }

    template <typename T, typename D, typename S>
    ID<T>   Frame::Container<T,D,S>::first() const
    {
        if(ids.empty())
            return {};
        return ID<T>(*ids.begin());
    }

    template <typename T, typename D, typename S>
    bool    Frame::Container<T,D,S>::has(uint64_t n) const
    {
        return datas.contains(n);
    }

    template <typename T, typename D, typename S>
    void    Frame::Container<T,D,S>::insert(Tachyon* p, const TachyonData* d, const TachyonSnap* s)
    {
        objects[p->id()]      = static_cast<T*>(p);
        datas[p->id()]        = static_cast<const data_k*>(d);
        snaps[p->id()]        = static_cast<const snap_t*>(s);
        names.insert({p->name(), p->id()});
        ids.insert(ID<T>(p->id()));
    }
    
    template <typename T, typename D, typename S>
    T* Frame::Container<T,D,S>::pointer(uint64_t n) const
    {
        auto i = objects.find(n);
        if(i != objects.end())
            return const_cast<T*>(i->second.ptr());
        return nullptr;
    }
        
    template <typename T, typename D, typename S>
    const S*    Frame::Container<T,D,S>::snap(uint64_t n) const
    {
        auto i = snaps.find(n);
        if(i != snaps.end())
            return i->second.ptr();
        return nullptr;
    }
    
    ////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////

    std::atomic<uint64_t>      Frame::s_lastId{0};
    thread_local const Frame*  Frame::s_current = nullptr;

    TypedID  Frame::resolve(TachyonSpec ts)
    {
        if(auto p = std::get_if<TypedID>(&ts))
            return *p;
        
        if(auto p = std::get_if<TachyonID>(&ts)){
            if(s_current)
                return s_current -> typed(*p);
        }
        return {};
    }

    ////////////////////////////////////////////////////////////////////////////
    
    Frame::Frame(ThreadID th, uint64_t ti, unit::Second now) : 
        m_origin(th), m_number(++s_lastId), m_wallclock(clock_t::now()), m_tick(ti), m_time(now)
    {
        for(Type t : values_of<Type>()){
            m_idsByType[t]  = {};
        }
    }


    Frame::~Frame()
    {
    }

    void    Frame::add(ThreadID th, const TachyonFrame& tac)
    {
        if(!(tac.object && tac.data && tac.snap))  
            return ;

        Types     types = tac.object->metaInfo().types();
        TachyonID id    = tac.object->id();

        //if(th){
            //m_owners[id]    = th;
        //}
        //m_types[id]     = types;
        m_allIds.insert(id);
        auto& tbit  = m_data[id];
        if(th)
            tbit.owner          = th;
        //tbit.types              = types;
        tbit.object             = tac.object;
        tbit.data               = tac.data;
        tbit.snap               = tac.snap;
        tbit.typedId            = *tac.object;
        for(Type t : values_of<Type>()){
            if(!types(t))
                continue;
            m_idsByType[t].insert(id);
        }
        
        
        Tachyon*   t = const_cast<Tachyon*>(tac.object.ptr());
        m_tachyons.insert(t, tac.data.ptr(), tac.snap.ptr());

        if(types(Type::Camera))
            m_cameras.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Camera³))
            m_camera³s.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Controller))
            m_controllers.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Cursor))
            m_cursors.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Desktop))
            m_desktops.insert(t, tac.data.ptr(), tac.snap.ptr());
        //if(types(Type::Editor))
            //m_editors.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Engine))
            m_engines.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Gamepad))
            m_gamepads.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::GraphicsCard))
            m_graphicsCards.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Group))
            m_groups.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Joystick))
            m_joysticks.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Keyboard))
            m_keyboards.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Kinetic))
            m_kinetics.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Kinetic³))
            m_kinetic³s.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Layer))
            m_layers.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Light))
            m_lights.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Light³))
            m_light³s.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Manager))
            m_managers.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Master))
            m_masters.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Model))
            m_models.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Monitor))
            m_monitors.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Mouse))
            m_mouses.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Physics))
            m_physics.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Rendered))
            m_rendereds.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Rendered³))
            m_rendered³s.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Scene))
            m_scenes.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Scene³))
            m_scene³s.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Spatial))
            m_spatials.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Spatial²))
            m_spatial²s.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Spatial³))
            m_spatial³s.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Thread))
            m_threads.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Viewer))
            m_viewers.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Widget))
            m_widgets.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Window))
            m_windows.insert(t, tac.data.ptr(), tac.snap.ptr());
    }

    std::span<const TypedID>    Frame::children(TachyonID tac) const
    {
        const TachyonSnap*  sn  = snap(tac);
        if(!sn)
            return {};
        return sn->children;
    }

    bool Frame::contains(Type type, uint64_t id) const
    {
        if(!is_valid(type))
            return false;
        return m_idsByType[type].contains({id});
    }

    bool Frame::contains(TypedID tid) const
    {
        return m_data.contains(tid.id);
    }

    size_t Frame::count(Type t) const
    {
        if(!is_valid(t))
            return 0;
        return m_idsByType[t].size();
    }

    size_t Frame::count(children_k, TachyonID tid) const
    {
        const TachyonSnap*  sn  = snap(tid);
        if(!sn)
            return 0;
        
        size_t  ret = 0;
        for(TypedID t : sn->children){
            if(contains((TachyonID) t)){
                ++ ret;
            }
        }
        return ret;
    }

    size_t Frame::count(tachyon_k) const
    {
        return m_allIds.size();
    }
    
    const CameraData*                   Frame::data(CameraID id) const
    {
        return m_cameras.data(id);
    }

    const Camera³Data*                  Frame::data(Camera³ID id) const
    {
        return m_camera³s.data(id);
    }

    const ControllerData*               Frame::data(ControllerID id) const
    {
        return m_controllers.data(id);
    }

    const CursorData*                   Frame::data(CursorID id) const
    {
        return m_cursors.data(id);
    }

    const DesktopData*                  Frame::data(DesktopID id) const
    {
        return m_desktops.data(id);
    }

    #if 0
    const EditorData*                   Frame::data(EditorID id) const
    {
        return m_editors.data(id);
    }
    #endif

    const EngineData*                   Frame::data(EngineID id) const
    {
        return m_engines.data(id);
    }

    const GamepadData*                  Frame::data(GamepadID id) const
    {
        return m_gamepads.data(id);
    }

    const GraphicsCardData*             Frame::data(GraphicsCardID id) const
    {
        return m_graphicsCards.data(id);
    }

    const GroupData*                    Frame::data(GroupID id) const
    {
        return m_groups.data(id);
    }

    const JoystickData*                 Frame::data(JoystickID id) const
    {
        return m_joysticks.data(id);
    }

    const KeyboardData*                 Frame::data(KeyboardID id) const
    {
        return m_keyboards.data(id);
    }

    const KineticData*                  Frame::data(KineticID id) const
    {
        return m_kinetics.data(id);
    }

    const Kinetic³Data*                 Frame::data(Kinetic³ID id) const
    {
        return m_kinetic³s.data(id);
    }

    const LightData*                    Frame::data(LightID id) const
    {
        return m_lights.data(id);
    }

    const LayerData*                    Frame::data(LayerID id) const
    {
        return m_layers.data(id);
    }

    const Light³Data*                   Frame::data(Light³ID id) const
    {
        return m_light³s.data(id);
    }

    const ManagerData*                  Frame::data(ManagerID id) const
    {
        return m_managers.data(id);
    }

    const MasterData*                   Frame::data(MasterID id) const
    {
        return m_masters.data(id);
    }

    const ModelData*                    Frame::data(ModelID id) const
    {
        return m_models.data(id);
    }

    const MouseData*                    Frame::data(MouseID id) const
    {
        return m_mouses.data(id);
    }

    const PhysicsData*                  Frame::data(PhysicsID id) const
    {
        return m_physics.data(id);
    }

    const RenderedData*                 Frame::data(RenderedID id) const
    {
        return m_rendereds.data(id);
    }

    const Rendered³Data*                Frame::data(Rendered³ID id) const
    {
        return m_rendered³s.data(id);
    }

    const SceneData*                    Frame::data(SceneID id) const
    {
        return m_scenes.data(id);
    }

    const Scene³Data*                   Frame::data(Scene³ID id) const
    {
        return m_scene³s.data(id);
    }

    const SpatialData*                  Frame::data(SpatialID id) const
    {
        return m_spatials.data(id);
    }

    const Spatial²Data*                 Frame::data(Spatial²ID id) const
    {
        return m_spatial²s.data(id);
    }

    const Spatial³Data*                 Frame::data(Spatial³ID id) const
    {
        return m_spatial³s.data(id);
    }

    const TachyonData*                  Frame::data(TachyonID id) const
    {
        return m_tachyons.data(id);
    }
    
    const ThreadData*                   Frame::data(ThreadID id) const
    {
        return m_threads.data(id);
    }

    const ViewerData*                   Frame::data(ViewerID id) const
    {
        return m_viewers.data(id);
    }

    const WidgetData*                   Frame::data(WidgetID id) const
    {
        return m_widgets.data(id);
    }

    const WindowData*                   Frame::data(WindowID id) const
    {
        return m_windows.data(id);
    }

    EngineID                            Frame::first(engine_k) const
    {
        return m_engines.first();
    }

    GraphicsCardID                      Frame::first(graphics_card_k) const
    {
        return m_graphicsCards.first();
    }

    MasterID                            Frame::first(master_k) const
    {
        return m_masters.first();
    }

    const std::set<TachyonID>&          Frame::ids_of(Type t) const
    {
        static const std::set<TachyonID> s_null;
        if(!is_valid(t))
            return s_null;
        return m_idsByType[t];
    }
    
    
    /*

    const std::set<CameraID>&           Frame::ids(camera_k) const
    {
        return m_cameras.ids;
    }
    
    const std::set<Camera³ID>&          Frame::ids(camera³_k) const
    {
        return m_camera³s.ids;
    }
    
    const std::set<ControllerID>&       Frame::ids(controller_k) const
    {
        return m_controllers.ids;
    }
    
    const std::set<CursorID>&           Frame::ids(cursor_k) const
    {
        return m_cursors.ids;
    }
    
    const std::set<DesktopID>&          Frame::ids(desktop_k) const
    {
        return m_desktops.ids;
    }
    
    const std::set<EngineID>&           Frame::ids(engine_k) const
    {
        return m_engines.ids;
    }

    const std::set<GamepadID>&          Frame::ids(gamepad_k) const
    {
        return m_gamepads.ids;
    }

    const std::set<GraphicsCardID>&     Frame::ids(graphics_card_k) const
    {
        return m_graphicsCards.ids;
    }

    const std::set<GroupID>&            Frame::ids(group_k) const
    {
        return m_groups.ids;
    }

    const std::set<JoystickID>&         Frame::ids(joystick_k) const
    {
        return m_joysticks.ids;
    }
    
    const std::set<KeyboardID>&         Frame::ids(keyboard_k) const
    {
        return m_keyboards.ids;
    }

    const std::set<KineticID>&          Frame::ids(kinetic_k) const
    {
        return m_kinetics.ids;
    }
    
    const std::set<Kinetic³ID>&         Frame::ids(kinetic³_k) const
    {
        return m_kinetic³s.ids;
    }
    
    const std::set<LayerID>&            Frame::ids(layer_k) const
    {
        return m_layers.ids;
    }
    
    const std::set<LightID>&            Frame::ids(light_k) const
    {
        return m_lights.ids;
    }

    const std::set<Light³ID>&           Frame::ids(light³_k) const
    {
        return m_light³s.ids;
    }
    
    const std::set<ManagerID>&          Frame::ids(manager_k) const
    {
        return m_managers.ids;
    }
    
    const std::set<MasterID>&           Frame::ids(master_k) const
    {
        return m_masters.ids;
    }

    const std::set<ModelID>&            Frame::ids(model_k) const
    {
        return m_models.ids;
    }

    const std::set<MonitorID>&          Frame::ids(monitor_k) const
    {
        return m_monitors.ids;
    }
    
    const std::set<MouseID>&            Frame::ids(mouse_k) const
    {
        return m_mouses.ids;
    }

    const std::set<PhysicsID>&          Frame::ids(physics_k) const
    {
        return m_physics.ids;
    }
    
    const std::set<RenderedID>&         Frame::ids(rendered_k) const
    {
        return m_rendereds.ids;
    }
    
    const std::set<Rendered³ID>&        Frame::ids(rendered³_k) const
    {
        return m_rendered³s.ids;
    }
    
    const std::set<SceneID>&            Frame::ids(scene_k) const
    {
        return m_scenes.ids;
    }
    
    const std::set<Scene³ID>&           Frame::ids(scene³_k) const
    {
        return m_scene³s.ids;
    }
    
    const std::set<SpatialID>&          Frame::ids(spatial_k) const
    {
        return m_spatials.ids;
    }
    
    const std::set<Spatial²ID>&         Frame::ids(spatial²_k) const
    {
        return m_spatial²s.ids;
    }
    
    const std::set<Spatial³ID>&         Frame::ids(spatial³_k) const
    {
        return m_spatial³s.ids;
    }

    const std::set<TachyonID>&          Frame::ids(tachyon_k) const
    {
        return m_tachyons.ids;
    }
    
    const std::set<ThreadID>&           Frame::ids(thread_k) const
    {
        return m_threads.ids;
    }
    
    const std::set<ViewerID>&           Frame::ids(viewer_k) const
    {
        return m_viewers.ids;
    }
    
    const std::set<WidgetID>&           Frame::ids(widget_k) const
    {
        return m_widgets.ids;
    }
    
    const std::set<WindowID>&           Frame::ids(window_k) const
    {
        return m_windows.ids;
    }
    */

    const CameraMeta*                   Frame::meta(CameraID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const Camera³Meta*                  Frame::meta(Camera³ID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const ControllerMeta*               Frame::meta(ControllerID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const CursorMeta*                   Frame::meta(CursorID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const DesktopMeta*                  Frame::meta(DesktopID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const EngineMeta*                   Frame::meta(EngineID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const GamepadMeta*                  Frame::meta(GamepadID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const GraphicsCardMeta*             Frame::meta(GraphicsCardID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const GroupMeta*                    Frame::meta(GroupID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const JoystickMeta*                 Frame::meta(JoystickID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const KeyboardMeta*                 Frame::meta(KeyboardID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const KineticMeta*                  Frame::meta(KineticID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }

    const Kinetic³Meta*                 Frame::meta(Kinetic³ID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }

    const LayerMeta*                    Frame::meta(LayerID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const LightMeta*                    Frame::meta(LightID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const Light³Meta*                   Frame::meta(Light³ID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const ManagerMeta*                  Frame::meta(ManagerID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const MasterMeta*                   Frame::meta(MasterID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }

    const ModelMeta*                    Frame::meta(ModelID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const MouseMeta*                    Frame::meta(MouseID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }

    const PhysicsMeta*                  Frame::meta(PhysicsID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }

    
    const RenderedMeta*                 Frame::meta(RenderedID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const Rendered³Meta*                Frame::meta(Rendered³ID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const SceneMeta*                    Frame::meta(SceneID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const Scene³Meta*                   Frame::meta(Scene³ID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const SpatialMeta*                  Frame::meta(SpatialID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const Spatial²Meta*                 Frame::meta(Spatial²ID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const Spatial³Meta*                 Frame::meta(Spatial³ID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const TachyonMeta*                  Frame::meta(TachyonID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const ThreadMeta*                   Frame::meta(ThreadID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const TachyonMeta*                  Frame::meta(ViewerID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const WidgetMeta*                   Frame::meta(WidgetID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    const WindowMeta*                   Frame::meta(WindowID id) const
    {
        auto obj = object(id);
        if(obj)
            return &obj->metaInfo();
        return nullptr;
    }
    
    Camera*                             Frame::object(CameraID id) const
    {
        return m_cameras.pointer(id);
    }

    Camera³*                            Frame::object(Camera³ID id) const
    {
        return m_camera³s.pointer(id);
    }

    Controller*                         Frame::object(ControllerID id) const
    {
        return m_controllers.pointer(id);
    }

    Cursor*                             Frame::object(CursorID id) const
    {
        return m_cursors.pointer(id);
    }

    Desktop*                            Frame::object(DesktopID id) const
    {
        return m_desktops.pointer(id);
    }

    Engine*                             Frame::object(EngineID id) const
    {
        return m_engines.pointer(id);
    }

    Gamepad*                            Frame::object(GamepadID id) const
    {
        return m_gamepads.pointer(id);
    }

    GraphicsCard*                       Frame::object(GraphicsCardID id) const
    {
        return m_graphicsCards.pointer(id);
    }

    Group*                              Frame::object(GroupID id) const
    {
        return m_groups.pointer(id);
    }

    Joystick*                           Frame::object(JoystickID id) const
    {
        return m_joysticks.pointer(id);
    }

    Keyboard*                           Frame::object(KeyboardID id) const
    {
        return m_keyboards.pointer(id);
    }

    Kinetic*                            Frame::object(KineticID id) const
    {
        return m_kinetics.pointer(id);
    }

    Kinetic³*                           Frame::object(Kinetic³ID id) const
    {
        return m_kinetic³s.pointer(id);
    }

    Light*                              Frame::object(LightID id) const
    {
        return m_lights.pointer(id);
    }

    Layer*                              Frame::object(LayerID id) const
    {
        return m_layers.pointer(id);
    }

    Light³*                             Frame::object(Light³ID id) const
    {
        return m_light³s.pointer(id);
    }

    Manager*                            Frame::object(ManagerID id) const
    {
        return m_managers.pointer(id);
    }

    Master*                             Frame::object(MasterID id) const
    {
        return m_masters.pointer(id);
    }

    Model*                              Frame::object(ModelID id) const
    {
        return m_models.pointer(id);
    }

    Mouse*                              Frame::object(MouseID id) const
    {
        return m_mouses.pointer(id);
    }

    Physics*                            Frame::object(PhysicsID id) const
    {
        return m_physics.pointer(id);
    }

    Rendered*                           Frame::object(RenderedID id) const
    {
        return m_rendereds.pointer(id);
    }

    Rendered³*                          Frame::object(Rendered³ID id) const
    {
        return m_rendered³s.pointer(id);
    }

    Scene*                              Frame::object(SceneID id) const
    {
        return m_scenes.pointer(id);
    }

    Scene³*                             Frame::object(Scene³ID id) const
    {
        return m_scene³s.pointer(id);
    }

    Spatial*                            Frame::object(SpatialID id) const
    {
        return m_spatials.pointer(id);
    }

    Spatial²*                           Frame::object(Spatial²ID id) const
    {
        return m_spatial²s.pointer(id);
    }

    Spatial³*                           Frame::object(Spatial³ID id) const
    {
        return m_spatial³s.pointer(id);
    }

    Tachyon*                            Frame::object(TachyonID id) const
    {
        return m_tachyons.pointer(id);
    }
    
    Thread*                             Frame::object(ThreadID id) const
    {
        return m_threads.pointer(id);
    }
    
    Viewer*                             Frame::object(ViewerID id) const
    {
        return m_viewers.pointer(id);
    }

    Widget*                             Frame::object(WidgetID id) const
    {
        return m_widgets.pointer(id);
    }

    Window*                             Frame::object(WindowID id) const
    {
        return m_windows.pointer(id);
    }

    Tachyon*                            Frame::object(parent_k, TachyonID tac) const
    {
        return object(parent(tac));
    }
    
    Tachyon*                            Frame::object(root_k, TachyonID tac) const
    {
        return object(root(tac));
    }

    Tachyon*                            Frame::object(tachyon_k, uint64_t id) const
    {
        return m_tachyons.pointer(id);
    }

    ThreadID                            Frame::owner(TachyonID tac) const
    {
        if(auto itr = m_data.find(tac); itr != m_data.end())
            return itr->second.owner;
        return {};
    }
    
    TypedID                             Frame::parent(TachyonID tac) const
    {
        const TachyonSnap*sn        = snap(tac);
        if(!sn)
            return {};
        return sn -> parent;
    }

    TypedID                             Frame::parent(Type t, TachyonID tac) const
    {
        for(const TachyonSnap* sn = snap(tac); sn && sn -> parent; sn = snap(sn->parent)){
            if(sn->parent(t))
                return sn->parent;
        }
        return {};
    }

    std::span<Proxy* const>             Frame::proxies(TachyonID tac) const
    {
        const TachyonSnap* ts = snap(tac);
        if(!ts)
            return {};
        return ts->proxies;
    }
    
    Proxy*                              Frame::proxy(TachyonID tac, const InterfaceMeta& ii) const
    {
        const TachyonSnap*  ts  = snap(tac);
        if(!ts)
            return nullptr;
        for(Proxy* p : ts->proxies){
            if(p->interface(INFO) == &ii)
                return p;
        }
        return nullptr;
    }

    void    Frame::report(Stream& out) const
    {
        out << "Report for Frame (" << m_number << ")\n"
            << "  Origin:        " << (uint64_t) m_origin << "\n"
            << "  Tick:          " << m_tick << "\n"
            << "  Clock:         " << std::format("{:%Y%m%d %H:%M:%S.%Z}", m_wallclock) << "\n"
            << "     - - - - - \n"
            << "  Cameras:       " << count(CAMERA) << "\n"
            << "  Camera³s:      " << count(CAMERA³) << "\n"
            << "  Controllers:   " << count(CONTROLLER) << "\n"
            << "  Cursors:       " << count(CURSOR) << "\n"
            << "  Desktops:      " << count(DESKTOP) << "\n"
            << "  Engines:       " << count(ENGINE) << "\n"
            << "  Gamepads:      " << count(GAMEPAD) << "\n"
            << "  GraphicsCards: " << count(GRAPHICS_CARD) << "\n"
            << "  Groups:        " << count(GROUP) << "\n"
            << "  Keyboards:     " << count(KEYBOARD) << "\n"
            << "  Kinetics:      " << count(KINETIC) << "\n"
            << "  Kinetic³s:     " << count(KINETIC³) << "\n"
            << "  Joysticks:     " << count(JOYSTICK) << "\n"
            << "  Layers:        " << count(LAYER) << "\n"
            << "  Lights:        " << count(LIGHT) << "\n"
            << "  Light³s:       " << count(LIGHT³) << "\n"
            << "  Managers:      " << count(MANAGER) << "\n"
            << "  Masters:       " << count(MASTER) << "\n"
            << "  Models:        " << count(MODEL) << "\n"
            << "  Mouses:        " << count(MOUSE) << "\n"
            << "  Physics:       " << count(PHYSICS) << "\n"
            << "  Rendereds:     " << count(RENDERED) << "\n"
            << "  Rendered³s:    " << count(RENDERED³) << "\n"
            << "  Scenes:        " << count(SCENE) << "\n"
            << "  Scene³s:       " << count(SCENE³) << "\n"
            << "  Spatials:      " << count(SPATIAL) << "\n"
            << "  Spatial²s:     " << count(SPATIAL²) << "\n"
            << "  Spatial³s:     " << count(SPATIAL³) << "\n"
            << "  Tachyons:      " << count(TACHYON) << "\n"
            << "  Threads:       " << count(THREAD) << "\n"
            << "  Viewers:       " << count(VIEWER) << "\n"
            << "  Widgets:       " << count(WIDGET) << "\n"
            << "  Windows:       " << count(WINDOW) << "\n"
        ;
    }

    TypedID                             Frame::root(Type type, TachyonID tac) const
    {
        TypedID     ret;
        TypedID     ttid    = typed(tac);
        if(ttid(type))
            ret = ttid;
        
        for(const TachyonSnap*  sn = snap(tac); sn && sn->parent; sn = snap(sn->parent)){
            if(sn->parent(type))
                ret = sn->parent;
        }
        
        return ret;
    }

    TypedID                             Frame::root(TachyonID tac) const
    {
        TypedID     ret = typed(tac);
        for(const TachyonSnap* sn = snap(tac); sn && sn->parent; sn = snap(sn->parent)){
            ret = sn->parent;
        }
        return ret;
    }

    const CameraSnap*                  Frame::snap(CameraID id) const
    {
        return m_cameras.snap(id);
    }

    const Camera³Snap*                 Frame::snap(Camera³ID id) const
    {
        return m_camera³s.snap(id);
    }

    const ControllerSnap*              Frame::snap(ControllerID id) const
    {
        return m_controllers.snap(id);
    }

    const CursorSnap*                  Frame::snap(CursorID id) const
    {
        return m_cursors.snap(id);
    }

    const DesktopSnap*                 Frame::snap(DesktopID id) const
    {
        return m_desktops.snap(id);
    }

    const EngineSnap*                  Frame::snap(EngineID id) const
    {
        return m_engines.snap(id);
    }

    const GamepadSnap*                 Frame::snap(GamepadID id) const
    {
        return m_gamepads.snap(id);
    }

    const GraphicsCardSnap*            Frame::snap(GraphicsCardID id) const
    {
        return m_graphicsCards.snap(id);
    }

    const GroupSnap*                   Frame::snap(GroupID id) const
    {
        return m_groups.snap(id);
    }

    const JoystickSnap*                Frame::snap(JoystickID id) const
    {
        return m_joysticks.snap(id);
    }

    const KeyboardSnap*                Frame::snap(KeyboardID id) const
    {
        return m_keyboards.snap(id);
    }

    const KineticSnap*                 Frame::snap(KineticID id) const
    {
        return m_kinetics.snap(id);
    }

    const Kinetic³Snap*                Frame::snap(Kinetic³ID id) const
    {
        return m_kinetic³s.snap(id);
    }

    const LayerSnap*                   Frame::snap(LayerID id) const
    {
        return m_layers.snap(id);
    }

    const LightSnap*                   Frame::snap(LightID id) const
    {
        return m_lights.snap(id);
    }

    const Light³Snap*                   Frame::snap(Light³ID id) const
    {
        return m_light³s.snap(id);
    }

    const ManagerSnap*                 Frame::snap(ManagerID id) const
    {
        return m_managers.snap(id);
    }

    const MasterSnap*                  Frame::snap(MasterID id) const
    {
        return m_masters.snap(id);
    }

    const ModelSnap*                   Frame::snap(ModelID id) const
    {
        return m_models.snap(id);
    }

    const MonitorSnap*                 Frame::snap(MonitorID id) const
    {
        return m_monitors.snap(id);
    }

    const MouseSnap*                   Frame::snap(MouseID id) const
    {
        return m_mouses.snap(id);
    }

    const PhysicsSnap*                 Frame::snap(PhysicsID id) const
    {
        return m_physics.snap(id);
    }


    const RenderedSnap*                Frame::snap(RenderedID id) const
    {
        return m_rendereds.snap(id);
    }

    const Rendered³Snap*               Frame::snap(Rendered³ID id) const
    {
        return m_rendered³s.snap(id);
    }

    const SceneSnap*                   Frame::snap(SceneID id) const
    {
        return m_scenes.snap(id);
    }

    const Scene³Snap*                  Frame::snap(Scene³ID id) const
    {
        return m_scene³s.snap(id);
    }

    const SpatialSnap*                 Frame::snap(SpatialID id) const
    {
        return m_spatials.snap(id);
    }

    const Spatial²Snap*                Frame::snap(Spatial²ID id) const
    {
        return m_spatial²s.snap(id);
    }

    const Spatial³Snap*                Frame::snap(Spatial³ID id) const
    {
        return m_spatial³s.snap(id);
    }

    const TachyonSnap*                 Frame::snap(TachyonID id) const
    {
        return m_tachyons.snap(id);
    }
    
    const ThreadSnap*                  Frame::snap(ThreadID id) const
    {
        return m_threads.snap(id);
    }

    const ViewerSnap*                  Frame::snap(ViewerID id) const
    {
        return m_viewers.snap(id);
    }

    const WidgetSnap*                  Frame::snap(WidgetID id) const
    {
        return m_widgets.snap(id);
    }

    const WindowSnap*                  Frame::snap(WindowID id) const
    {
        return m_windows.snap(id);
    }

    TypedID Frame::typed(TachyonID id) const
    {
        if(auto itr = m_data.find(id); itr != m_data.end())
            return itr->second.typedId;
        return {};
    }

    TypedID Frame::typed(StdThread st) const
    {
        return typed(Thread::standard(st));
    }
    
    Types   Frame::types(TachyonID id) const
    {
        if(auto itr = m_data.find(id); itr != m_data.end())
            return itr->second.typedId.types;
        return {};
    }

    ////////////////////////
    // FRAME BUILDER
    
    Frame::Builder::Builder(Frame& fp) : m_frame(fp)
    {
    }
    
    Frame::Builder::~Builder()
    {
    }
    
    void        Frame::Builder::add(ThreadID th, const ThreadData& tdata)
    {
        for(const TachyonFrame& tf : tdata.tachyons){
            if(!tf.object){
                //tachyonInfo << "frame build... item " << tf.object->ident() << " has no object";
                continue;
            }
            if(!tf.data){
                //tachyonInfo << "frame build... item " << tf.object->ident() << " has no data";
                continue;
            }
            if(!tf.snap){
                //tachyonInfo << "frame build... item " << tf.object->ident() << " has no snap";
                continue;
            }
                
            switch(tf.state){
            case TachyonThreadState::Normal:
                m_frame.add(th, tf);
                break;
            case TachyonThreadState::Pushed:
                //tachyonInfo << "frame build... item " << tf.object->ident() << " pushed";
                m_pushed.push_back({th, tf});
                break;
            case TachyonThreadState::Delete:
                //tachyonInfo << "frame build... item " << tf.object->ident() << " deleted";
                break;
            default:
                //tachyonInfo << "frame build... item " << tf.object->ident() << " unknown state";
                break;
            }
        }
    }
    
    void    Frame::Builder::finalize()
    {
        for(auto& p : m_pushed){
            if(m_frame.contains(p.second.object->id()))
                continue;
            m_frame.add(p.first, p.second);
        }
    }
    
}
