////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/api/Controller.hpp>
#include <tachyon/api/ControllerData.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/FrameBuilder.hpp>
#include <tachyon/api/Interface.hpp>
#include <tachyon/api/Manager.hpp>
#include <tachyon/api/ManagerData.hpp>
//#include <tachyon/api/Post.hpp>
#include <tachyon/api/Proxy.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/api/Thread.hpp>
#include <tachyon/api/ThreadData.hpp>

#include <yt/3D/Camera3.hpp>
#include <yt/3D/Camera3Data.hpp>
#include <yt/3D/Light3.hpp>
#include <yt/3D/Light3Data.hpp>
#include <yt/3D/Rendered3.hpp>
#include <yt/3D/Rendered3Data.hpp>
#include <yt/3D/Scene3.hpp>
#include <yt/3D/Scene3Data.hpp>
#include <yt/3D/Spatial3.hpp>
#include <yt/3D/Spatial3Data.hpp>

#include <tachyon/app/Viewer.hpp>
#include <tachyon/app/ViewerData.hpp>

#include <tachyon/os/Cursor.hpp>
#include <tachyon/os/CursorData.hpp>
#include <tachyon/os/Desktop.hpp>
#include <tachyon/os/DesktopData.hpp>
#include <tachyon/os/Gamepad.hpp>
#include <tachyon/os/GamepadData.hpp>
#include <tachyon/os/GraphicsCard.hpp>
#include <tachyon/os/GraphicsCardData.hpp>
#include <tachyon/os/Joystick.hpp>
#include <tachyon/os/JoystickData.hpp>
#include <tachyon/os/Keyboard.hpp>
#include <tachyon/os/KeyboardData.hpp>
#include <tachyon/os/Monitor.hpp>
#include <tachyon/os/MonitorData.hpp>
#include <tachyon/os/Mouse.hpp>
#include <tachyon/os/MouseData.hpp>
#include <tachyon/os/Window.hpp>
#include <tachyon/os/WindowData.hpp>

//#include <yt/ui/Editor.hpp>
//#include <yt/ui/EditorData.hpp>
#include <yt/ui/Widget.hpp>
#include <yt/ui/WidgetData.hpp>

#include <tachyon/api/Camera.hpp>
#include <tachyon/api/CameraData.hpp>
#include <tachyon/api/Light.hpp>
#include <tachyon/api/LightData.hpp>
#include <tachyon/api/Rendered.hpp>
#include <tachyon/api/RenderedData.hpp>
#include <tachyon/api/Scene.hpp>
#include <tachyon/api/SceneData.hpp>

#include <yt/sim/Model.hpp>
#include <yt/sim/ModelData.hpp>
#include <yt/sim/Spatial.hpp>
#include <yt/sim/SpatialData.hpp>

#include <yq/core/StreamOps.hpp>
#include <yt/logging.hpp>

namespace yq::tachyon {

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
    
    Frame::Frame(ThreadID th, uint64_t ti) : m_origin(th), m_number(++s_lastId), m_wallclock(clock_t::now()), m_tick(ti)
    {
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

        if(th){
            m_owners[id]    = th;
        }
        m_types[id]     = types;
        
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
        if(types(Type::Gamepad))
            m_gamepads.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::GraphicsCard))
            m_graphicsCards.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Joystick))
            m_joysticks.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Keyboard))
            m_keyboards.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Light))
            m_lights.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Light³))
            m_light³s.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Manager))
            m_managers.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Model))
            m_models.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Monitor))
            m_monitors.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Mouse))
            m_mouses.insert(t, tac.data.ptr(), tac.snap.ptr());
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

    bool Frame::contains(CameraID id) const
    {
        return m_cameras.has(id);
    }

    bool Frame::contains(Camera³ID id) const
    {
        return m_camera³s.has(id);
    }

    bool Frame::contains(ControllerID id) const
    {
        return m_controllers.has(id);
    }

    bool Frame::contains(CursorID id) const
    {
        return m_cursors.has(id);
    }

    bool Frame::contains(DesktopID id) const
    {
        return m_desktops.has(id);
    }

    #if 0
    bool Frame::contains(EditorID id) const
    {
        return m_editors.has(id);
    }
    #endif

    bool Frame::contains(GamepadID id) const
    {
        return m_gamepads.has(id);
    }

    bool Frame::contains(GraphicsCardID id) const
    {
        return m_graphicsCards.has(id);
    }

    bool Frame::contains(JoystickID id) const
    {
        return m_joysticks.has(id);
    }

    bool Frame::contains(KeyboardID id) const
    {
        return m_keyboards.has(id);
    }

    bool Frame::contains(LightID id) const
    {
        return m_lights.has(id);
    }

    bool Frame::contains(Light³ID id) const
    {
        return m_light³s.has(id);
    }

    bool Frame::contains(ManagerID id) const
    {
        return m_managers.has(id);
    }

    bool Frame::contains(ModelID id) const
    {
        return m_models.has(id);
    }

    bool Frame::contains(MonitorID id) const
    {
        return m_monitors.has(id);
    }

    bool Frame::contains(MouseID id) const
    {
        return m_mouses.has(id);
    }

    bool Frame::contains(RenderedID id) const
    {
        return m_rendereds.has(id);
    }

    bool Frame::contains(Rendered³ID id) const
    {
        return m_rendered³s.has(id);
    }

    bool Frame::contains(SceneID id) const
    {
        return m_scenes.has(id);
    }

    bool Frame::contains(Scene³ID id) const
    {
        return m_scene³s.has(id);
    }
    
    bool Frame::contains(SpatialID id) const
    {
        return m_spatials.has(id);
    }

    bool Frame::contains(Spatial³ID id) const
    {
        return m_spatial³s.has(id);
    }

    bool Frame::contains(TachyonID id) const
    {
        return m_tachyons.has(id);
    }
    
    bool Frame::contains(ThreadID id) const
    {
        return m_threads.has(id);
    }
    
    bool Frame::contains(ViewerID id) const
    {
        return m_viewers.has(id);
    }

    bool Frame::contains(WidgetID id) const
    {
        return m_widgets.has(id);
    }

    bool Frame::contains(WindowID id) const
    {
        return m_windows.has(id);
    }

    size_t Frame::count(camera_k) const
    {
        return m_cameras.count();
    }
    
    size_t Frame::count(camera³_k) const
    {
        return m_camera³s.count();
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

    size_t Frame::count(controller_k) const
    {
        return m_controllers.count();
    }
    
    size_t Frame::count(cursor_k) const
    {
        return m_cursors.count();
    }
    
    size_t Frame::count(desktop_k) const
    {
        return m_desktops.count();
    }
    
    size_t Frame::count(gamepad_k) const
    {
        return m_gamepads.count();
    }

    size_t Frame::count(graphics_card_k) const
    {
        return m_graphicsCards.count();
    }

    size_t Frame::count(joystick_k) const
    {
        return m_joysticks.count();
    }
    
    size_t Frame::count(keyboard_k) const
    {
        return m_keyboards.count();
    }
    
    size_t Frame::count(light_k) const
    {
        return m_lights.count();
    }
    
    size_t Frame::count(light³_k) const
    {
        return m_light³s.count();
    }

    size_t Frame::count(manager_k) const
    {
        return m_managers.count();
    }
    
    size_t Frame::count(model_k) const
    {
        return m_models.count();
    }
    
    size_t Frame::count(monitor_k) const
    {
        return m_monitors.count();
    }

    size_t Frame::count(mouse_k) const
    {
        return m_mouses.count();
    }
    
    size_t Frame::count(rendered_k) const
    {
        return m_rendereds.count();
    }

    size_t Frame::count(rendered³_k) const
    {
        return m_rendered³s.count();
    }

    size_t Frame::count(scene_k) const
    {
        return m_scenes.count();
    }
    
    size_t Frame::count(scene³_k) const
    {
        return m_scene³s.count();
    }

    size_t Frame::count(spatial_k) const
    {
        return m_spatials.count();
    }
    
    size_t Frame::count(spatial³_k) const
    {
        return m_spatial³s.count();
    }

    size_t Frame::count(tachyon_k) const
    {
        return m_tachyons.count();
    }

    size_t Frame::count(thread_k) const
    {
        return m_threads.count();
    }

    size_t Frame::count(viewer_k) const
    {
        return m_viewers.count();
    }

    size_t Frame::count(widget_k) const
    {
        return m_widgets.count();
    }
    
    size_t Frame::count(window_k) const
    {
        return m_windows.count();
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

    const GamepadData*                  Frame::data(GamepadID id) const
    {
        return m_gamepads.data(id);
    }

    const GraphicsCardData*             Frame::data(GraphicsCardID id) const
    {
        return m_graphicsCards.data(id);
    }

    const JoystickData*                 Frame::data(JoystickID id) const
    {
        return m_joysticks.data(id);
    }

    const KeyboardData*                 Frame::data(KeyboardID id) const
    {
        return m_keyboards.data(id);
    }

    const LightData*                    Frame::data(LightID id) const
    {
        return m_lights.data(id);
    }

    const Light³Data*                   Frame::data(Light³ID id) const
    {
        return m_light³s.data(id);
    }

    const ManagerData*                  Frame::data(ManagerID id) const
    {
        return m_managers.data(id);
    }

    const ModelData*                    Frame::data(ModelID id) const
    {
        return m_models.data(id);
    }

    const MouseData*                   Frame::data(MouseID id) const
    {
        return m_mouses.data(id);
    }

    const RenderedData*                Frame::data(RenderedID id) const
    {
        return m_rendereds.data(id);
    }

    const Rendered³Data*               Frame::data(Rendered³ID id) const
    {
        return m_rendered³s.data(id);
    }

    const SceneData*                   Frame::data(SceneID id) const
    {
        return m_scenes.data(id);
    }

    const Scene³Data*                  Frame::data(Scene³ID id) const
    {
        return m_scene³s.data(id);
    }

    const SpatialData*                 Frame::data(SpatialID id) const
    {
        return m_spatials.data(id);
    }

    const Spatial³Data*                Frame::data(Spatial³ID id) const
    {
        return m_spatial³s.data(id);
    }

    const TachyonData*                 Frame::data(TachyonID id) const
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

    GraphicsCardID                      Frame::first(graphics_card_k) const
    {
        return m_graphicsCards.first();
    }

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
    
    const std::set<GamepadID>&          Frame::ids(gamepad_k) const
    {
        return m_gamepads.ids;
    }

    const std::set<GraphicsCardID>&     Frame::ids(graphics_card_k) const
    {
        return m_graphicsCards.ids;
    }

    const std::set<JoystickID>&         Frame::ids(joystick_k) const
    {
        return m_joysticks.ids;
    }
    
    const std::set<KeyboardID>&         Frame::ids(keyboard_k) const
    {
        return m_keyboards.ids;
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

    Gamepad*                            Frame::object(GamepadID id) const
    {
        return m_gamepads.pointer(id);
    }

    GraphicsCard*                       Frame::object(GraphicsCardID id) const
    {
        return m_graphicsCards.pointer(id);
    }

    Joystick*                           Frame::object(JoystickID id) const
    {
        return m_joysticks.pointer(id);
    }

    Keyboard*                           Frame::object(KeyboardID id) const
    {
        return m_keyboards.pointer(id);
    }

    Light*                              Frame::object(LightID id) const
    {
        return m_lights.pointer(id);
    }

    Light³*                             Frame::object(Light³ID id) const
    {
        return m_light³s.pointer(id);
    }

    Manager*                            Frame::object(ManagerID id) const
    {
        return m_managers.pointer(id);
    }

    Model*                              Frame::object(ModelID id) const
    {
        return m_models.pointer(id);
    }

    Mouse*                              Frame::object(MouseID id) const
    {
        return m_mouses.pointer(id);
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

    Spatial*                              Frame::object(SpatialID id) const
    {
        return m_spatials.pointer(id);
    }

    Spatial³*                             Frame::object(Spatial³ID id) const
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
        auto i = m_owners.find(tac);
        if(i != m_owners.end())
            return i->second;
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
    
    Proxy*                              Frame::proxy(TachyonID tac, const InterfaceInfo& ii) const
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
            << "  Gamepads:      " << count(GAMEPAD) << "\n"
            << "  GraphicsCards: " << count(GRAPHICS_CARD) << "\n"
            << "  Keyboards:     " << count(KEYBOARD) << "\n"
            << "  Joysticks:     " << count(JOYSTICK) << "\n"
            << "  Lights:        " << count(LIGHT) << "\n"
            << "  Light³s:       " << count(LIGHT³) << "\n"
            << "  Managers:      " << count(MANAGER) << "\n"
            << "  Models:        " << count(MODEL) << "\n"
            << "  Mouses:        " << count(MOUSE) << "\n"
            << "  Rendereds:     " << count(RENDERED) << "\n"
            << "  Rendered³s:    " << count(RENDERED³) << "\n"
            << "  Scenes:        " << count(LIGHT) << "\n"
            << "  Scene³s:       " << count(LIGHT³) << "\n"
            << "  Spatials:      " << count(SPATIAL) << "\n"
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

    const GamepadSnap*                 Frame::snap(GamepadID id) const
    {
        return m_gamepads.snap(id);
    }

    const GraphicsCardSnap*            Frame::snap(GraphicsCardID id) const
    {
        return m_graphicsCards.snap(id);
    }

    const JoystickSnap*                Frame::snap(JoystickID id) const
    {
        return m_joysticks.snap(id);
    }

    const KeyboardSnap*                Frame::snap(KeyboardID id) const
    {
        return m_keyboards.snap(id);
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

    const Scene³Snap*                   Frame::snap(Scene³ID id) const
    {
        return m_scene³s.snap(id);
    }

    const SpatialSnap*                   Frame::snap(SpatialID id) const
    {
        return m_spatials.snap(id);
    }

    const Spatial³Snap*                   Frame::snap(Spatial³ID id) const
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
        return TypedID(id, types(id));
    }
    
    Types   Frame::types(TachyonID id) const
    {
        auto i = m_types.find(id);
        if(i != m_types.end())
            return i->second;
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
