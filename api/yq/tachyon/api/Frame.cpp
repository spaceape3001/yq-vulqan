////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Camera.hpp"
#include "CameraData.hpp"
#include "Cursor.hpp"
#include "CursorData.hpp"
#include "Desktop.hpp"
#include "DesktopData.hpp"
//#include "Editor.hpp"
//#include "EditorData.hpp"
#include "Frame.hpp"
#include "FrameBuilder.hpp"
#include "Interface.hpp"
#include "Joystick.hpp"
#include "JoystickData.hpp"
#include "Keyboard.hpp"
#include "KeyboardData.hpp"
#include "Light.hpp"
#include "LightData.hpp"
#include "Manager.hpp"
#include "ManagerData.hpp"
#include "Model.hpp"
#include "ModelData.hpp"
#include "Monitor.hpp"
#include "MonitorData.hpp"
#include "Mouse.hpp"
#include "MouseData.hpp"
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
//#include "Viewer.hpp"
//#include "ViewerData.hpp"
#include "Widget.hpp"
#include "WidgetData.hpp"
#include "Window.hpp"
#include "WindowData.hpp"

namespace yq::tachyon {

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
        datas[p->id()]        = static_cast<const data_t*>(d);
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

    std::atomic<uint64_t>    Frame::s_lastId{0};
    
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

        m_owners[id]    = th;
        m_types[id]     = types;
        
        Tachyon*   t = const_cast<Tachyon*>(tac.object.ptr());
        m_tachyons.insert(t, tac.data.ptr(), tac.snap.ptr());

        if(types(Type::Camera))
            m_cameras.insert(t, tac.data.ptr(), tac.snap.ptr());
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
        //if(types(Type::Scene))
            //m_scenes.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Thread))
            m_threads.insert(t, tac.data.ptr(), tac.snap.ptr());
        //if(types(Type::Viewer))
            //m_viewers.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Widget))
            m_widgets.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Window))
            m_windows.insert(t, tac.data.ptr(), tac.snap.ptr());
    }
    
    bool Frame::contains(CameraID id) const
    {
        return m_cameras.has(id);
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
    
    #if 0
    bool Frame::contains(ViewerID id) const
    {
        return m_viewers.has(id);
    }
    #endif

    bool Frame::contains(WidgetID id) const
    {
        return m_widgets.has(id);
    }

    bool Frame::contains(WindowID id) const
    {
        return m_windows.has(id);
    }
    
    const CameraData*                   Frame::data(CameraID id) const
    {
        return m_cameras.data(id);
    }

    const CursorData*                   Frame::data(CursorID id) const
    {
        return m_cursors.data(id);
    }

    const DesktopData*                   Frame::data(DesktopID id) const
    {
        return m_desktops.data(id);
    }

    #if 0
    const EditorData*                   Frame::data(EditorID id) const
    {
        return m_editors.data(id);
    }
    #endif

    const JoystickData*                   Frame::data(JoystickID id) const
    {
        return m_joysticks.data(id);
    }

    const KeyboardData*                   Frame::data(KeyboardID id) const
    {
        return m_keyboards.data(id);
    }

    const LightData*                   Frame::data(LightID id) const
    {
        return m_lights.data(id);
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

    const TachyonData*                  Frame::data(TachyonID id) const
    {
        return m_tachyons.data(id);
    }
    
    const ThreadData*                   Frame::data(ThreadID id) const
    {
        return m_threads.data(id);
    }

    #if 0
    const ViewerData*                   Frame::data(ViewerID id) const
    {
        return m_viewers.data(id);
    }
    #endif

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

    Tachyon*                            Frame::object(TachyonID id) const
    {
        return m_tachyons.pointer(id);
    }
    
    Thread*                             Frame::object(ThreadID id) const
    {
        return m_threads.pointer(id);
    }
    
    #if 0
    Viewer*                             Frame::object(ViewerID id) const
    {
        return m_viewers.pointer(id);
    }
    #endif

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

    const CameraSnap*                  Frame::snap(CameraID id) const
    {
        return m_cameras.snap(id);
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

    const TachyonSnap*                 Frame::snap(TachyonID id) const
    {
        return m_tachyons.snap(id);
    }
    
    const ThreadSnap*                  Frame::snap(ThreadID id) const
    {
        return m_threads.snap(id);
    }

    #if 0
    const ViewerSnap*                  Frame::snap(ViewerID id) const
    {
        return m_viewers.snap(id);
    }
    #endif

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
            if(!tf.object)
                continue;
            if(!tf.data)
                continue;
            if(!tf.snap)
                continue;
            switch(tf.state){
            case TachyonThreadState::Normal:
                m_frame.add(th, tf);
                break;
            case TachyonThreadState::Pushed:
                m_pushed.push_back({th, tf});
                break;
            default:
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
