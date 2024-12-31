////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Camera.hpp"
#include "CameraData.hpp"
#include "Controller.hpp"
#include "ControllerData.hpp"
//#include "Editor.hpp"
//#include "EditorData.hpp"
#include "Frame.hpp"
#include "FrameBuilder.hpp"
#include "Interface.hpp"
#include "Light.hpp"
#include "LightData.hpp"
#include "Manager.hpp"
#include "ManagerData.hpp"
#include "Model.hpp"
#include "ModelData.hpp"
//#include "Post.hpp"
#include "Proxy.hpp"
#include "Rendered.hpp"
#include "RenderedData.hpp"
//#include "Scene.hpp"
//#include "SceneData.hpp"
#include "Tachyon.hpp"
#include "TachyonData.hpp"
#include "Thread.hpp"
#include "ThreadData.hpp"
#include "Viewer.hpp"
#include "ViewerData.hpp"
#include "Widget.hpp"
#include "WidgetData.hpp"

#include <yq/tachyon/desktop/Cursor.hpp>
#include <yq/tachyon/desktop/CursorData.hpp>
#include <yq/tachyon/desktop/Desktop.hpp>
#include <yq/tachyon/desktop/DesktopData.hpp>
#include <yq/tachyon/desktop/Joystick.hpp>
#include <yq/tachyon/desktop/JoystickData.hpp>
#include <yq/tachyon/desktop/Keyboard.hpp>
#include <yq/tachyon/desktop/KeyboardData.hpp>
#include <yq/tachyon/desktop/Monitor.hpp>
#include <yq/tachyon/desktop/MonitorData.hpp>
#include <yq/tachyon/desktop/Mouse.hpp>
#include <yq/tachyon/desktop/MouseData.hpp>
#include <yq/tachyon/desktop/Window.hpp>
#include <yq/tachyon/desktop/WindowData.hpp>

#include <yq/tachyon/scene3/Camera3.hpp>
#include <yq/tachyon/scene3/Camera3Data.hpp>
#include <yq/tachyon/scene3/Light3.hpp>
#include <yq/tachyon/scene3/Light3Data.hpp>
#include <yq/tachyon/scene3/Rendered3.hpp>
#include <yq/tachyon/scene3/Rendered3Data.hpp>

#include <yq/core/StreamOps.hpp>
#include <yq/tachyon/logging.hpp>

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
        //if(types(Type::Camera3))
        //    m_camera3s.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Controller))
            m_controllers.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Cursor))
            m_cursors.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Desktop))
            m_desktops.insert(t, tac.data.ptr(), tac.snap.ptr());
        //if(types(Type::Editor))
            //m_editors.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Joystick))
            m_joysticks.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Keyboard))
            m_keyboards.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Light))
            m_lights.insert(t, tac.data.ptr(), tac.snap.ptr());
        //if(types(Type::Light3))
        //    m_light3s.insert(t, tac.data.ptr(), tac.snap.ptr());
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
        if(types(Type::Rendered3))
            m_rendered3s.insert(t, tac.data.ptr(), tac.snap.ptr());
        //if(types(Type::Scene))
            //m_scenes.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Thread))
            m_threads.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Viewer))
            m_viewers.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Widget))
            m_widgets.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Window))
            m_windows.insert(t, tac.data.ptr(), tac.snap.ptr());
    }
    
    bool Frame::contains(CameraID id) const
    {
        return m_cameras.has(id);
    }

    #if 0
    bool Frame::contains(Camera3ID id) const
    {
        return m_camera3s.has(id);
    }
    #endif

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

    #if 0
    bool Frame::contains(Light3ID id) const
    {
        return m_light3s.has(id);
    }
    #endif

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

    bool Frame::contains(Rendered3ID id) const
    {
        return m_rendered3s.has(id);
    }

    #if 0
    bool Frame::contains(SceneID id) const
    {
        return m_scenes.has(id);
    }
    #endif
    
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
    
    #if 0
    size_t Frame::count(camera3_k) const
    {
        return m_camera3s.count();
    }
    #endif

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
    
    size_t Frame::count(keyboard_k) const
    {
        return m_keyboards.count();
    }
    
    size_t Frame::count(joystick_k) const
    {
        return m_joysticks.count();
    }
    
    size_t Frame::count(light_k) const
    {
        return m_lights.count();
    }
    
    #if 0
    size_t Frame::count(light3_k) const
    {
        return m_light3s.count();
    }
    #endif

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

    size_t Frame::count(rendered3_k) const
    {
        return m_rendered3s.count();
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

    #if 0
    const Camera3Data*                  Frame::data(Camera3ID id) const
    {
        return m_camera3s.data(id);
    }
    #endif

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

    #if 0
    const Light3Data*                   Frame::data(Light3ID id) const
    {
        return m_light3s.data(id);
    }
    #endif

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

    const Rendered3Data*               Frame::data(Rendered3ID id) const
    {
        return m_rendered3s.data(id);
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

    Camera*                             Frame::object(CameraID id) const
    {
        return m_cameras.pointer(id);
    }

    #if 0
    Camera3*                            Frame::object(Camera3ID id) const
    {
        return m_camera3s.pointer(id);
    }
    #endif

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

    #if 0
    Light3*                             Frame::object(Light3ID id) const
    {
        return m_light3s.pointer(id);
    }
    #endif

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

    Rendered3*                          Frame::object(Rendered3ID id) const
    {
        return m_rendered3s.pointer(id);
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

    ThreadID                            Frame::owner(TachyonID id) const
    {
        auto i = m_owners.find(id);
        if(i != m_owners.end())
            return i->second;
        return {};
    }
    
    std::span<Proxy* const>             Frame::proxies(TachyonID id) const
    {
        const TachyonSnap* ts = snap(id);
        if(!ts)
            return {};
        return ts->proxies;
    }
    
    Proxy*                              Frame::proxy(TachyonID id, const InterfaceInfo& ii) const
    {
        const TachyonSnap*  ts  = snap(id);
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
            << "  Origin:       " << (uint64_t) m_origin << "\n"
            << "  Tick:         " << m_tick << "\n"
            << "  Clock:        " << std::format("{:%Y%m%d %H:%M:%S.%Z}", m_wallclock) << "\n"
            << "     - - - - - \n"
            << "  Cameras:      " << count(CAMERA) << "\n"
            //<< "  Camera3s:     " << count(CAMERA3) << "\n"
            << "  Controllers:  " << count(CONTROLLER) << "\n"
            << "  Cursors:      " << count(CURSOR) << "\n"
            << "  Desktops:     " << count(DESKTOP) << "\n"
            << "  Keyboards:    " << count(KEYBOARD) << "\n"
            << "  Joysticks:    " << count(JOYSTICK) << "\n"
            << "  Lights:       " << count(LIGHT) << "\n"
            //<< "  Light3s:      " << count(LIGHT3) << "\n"
            << "  Managers:     " << count(MANAGER) << "\n"
            << "  Models:       " << count(MODEL) << "\n"
            << "  Mouses:       " << count(MOUSE) << "\n"
            << "  Rendereds:    " << count(RENDERED) << "\n"
            //<< "  Rendered3s:   " << count(RENDERED3) << "\n"
            << "  Tachyons:     " << count(TACHYON) << "\n"
            << "  Threads:      " << count(THREAD) << "\n"
            << "  Viewers:      " << count(VIEWER) << "\n"
            << "  Widgets:      " << count(WIDGET) << "\n"
            << "  Windows:      " << count(WINDOW) << "\n"
        ;
    }

    const CameraSnap*                  Frame::snap(CameraID id) const
    {
        return m_cameras.snap(id);
    }

    #if 0
    const Camera3Snap*                 Frame::snap(Camera3ID id) const
    {
        return m_camera3s.snap(id);
    }
    #endif

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

    #if 0
    const Light3Snap*                   Frame::snap(Light3ID id) const
    {
        return m_light3s.snap(id);
    }
    #endif

    const ManagerSnap*                 Frame::snap(ManagerID id) const
    {
        return m_managers.snap(id);
    }

    const ModelSnap*                   Frame::snap(ModelID id) const
    {
        return m_models.snap(id);
    }

    const MouseSnap*                   Frame::snap(MouseID id) const
    {
        return m_mouses.snap(id);
    }

    const RenderedSnap*                Frame::snap(RenderedID id) const
    {
        return m_rendereds.snap(id);
    }

    const Rendered3Snap*               Frame::snap(Rendered3ID id) const
    {
        return m_rendered3s.snap(id);
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
