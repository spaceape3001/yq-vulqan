////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yt/keywords.hpp>
#include <yt/Type.hpp>
#include <yt/ID.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/typedef/camera.hpp>
#include <yq/tachyon/typedef/camera3.hpp>
#include <yt/typedef/clock.hpp>
#include <yq/tachyon/typedef/controller.hpp>
#include <yt/typedef/cursor.hpp>
#include <yt/typedef/desktop.hpp>
#include <yt/typedef/frame.hpp>
#include <yt/typedef/joystick.hpp>
#include <yt/typedef/keyboard.hpp>
#include <yq/tachyon/typedef/light.hpp>
#include <yq/tachyon/typedef/light3.hpp>
#include <yq/tachyon/typedef/manager.hpp>
#include <yq/tachyon/typedef/model.hpp>
#include <yt/typedef/monitor.hpp>
#include <yt/typedef/mouse.hpp>
#include <yq/tachyon/typedef/rendered.hpp>
#include <yq/tachyon/typedef/rendered3.hpp>
#include <yt/typedef/post.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/tachyon/typedef/scene3.hpp>
#include <yq/tachyon/typedef/spatial.hpp>
#include <yq/tachyon/typedef/spatial3.hpp>
#include <yt/typedef/tachyon.hpp>
#include <yt/typedef/thread.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/widget.hpp>
#include <yt/typedef/window.hpp>

#include <chrono>
#include <unordered_map>

namespace yq { class Stream; }

namespace yq::tachyon {
    class Proxy;
    class InterfaceInfo;

    /*
        Tachyons will *belong* to a thread... either directly or indirectly 
        (ie a chain).  During some threads execution (ie, sim-thread or viz-thread), 
        these may be temporarily delegated into other threads, but will not strip 
        the owning thread of ownership.
    */
    
    struct TachyonFrame;

    class Frame : public RefCount {
    public:
    
        //! Returns the current "published" frame for this thread 
        //! \note This may be null, so check!
        static const Frame*     current() { return s_current; }
    
        using proxy_span_t  = std::span<Proxy* const>;

        bool contains(CameraID) const;
        bool contains(Camera³ID) const;
        bool contains(ControllerID) const;
        bool contains(CursorID) const;
        bool contains(DesktopID) const;
        //bool contains(EditorID) const;
        bool contains(JoystickID) const;
        bool contains(KeyboardID) const;
        bool contains(LightID) const;
        bool contains(Light³ID) const;
        bool contains(ManagerID) const;
        bool contains(ModelID) const;
        bool contains(MonitorID) const;
        bool contains(MouseID) const;
        bool contains(RenderedID) const;
        bool contains(Rendered³ID) const;
        bool contains(SceneID) const;
        bool contains(Scene³ID) const;
        bool contains(SpatialID) const;
        bool contains(Spatial³ID) const;
        bool contains(TachyonID) const;
        bool contains(ThreadID) const;
        bool contains(ViewerID) const;
        bool contains(WidgetID) const;
        bool contains(WindowID) const;
        
        size_t count(camera_k) const;
        size_t count(camera³_k) const;
        size_t count(controller_k) const;
        size_t count(cursor_k) const;
        size_t count(desktop_k) const;
        size_t count(keyboard_k) const;
        size_t count(joystick_k) const;
        size_t count(light_k) const;
        size_t count(light³_k) const;
        size_t count(manager_k) const;
        size_t count(model_k) const;
        size_t count(monitor_k) const;
        size_t count(mouse_k) const;
        size_t count(rendered³_k) const;
        size_t count(rendered_k) const;
        size_t count(scene_k) const;
        size_t count(scene³_k) const;
        size_t count(spatial_k) const;
        size_t count(spatial³_k) const;
        size_t count(tachyon_k) const;
        size_t count(thread_k) const;
        size_t count(viewer_k) const;
        size_t count(widget_k) const;
        size_t count(window_k) const;
    
        const CameraData*                   data(CameraID) const;
        const Camera³Data*                  data(Camera³ID) const;
        const ControllerData*               data(ControllerID) const;
        const CursorData*                   data(CursorID) const;
        const DesktopData*                  data(DesktopID) const;
        //const EditorData*                   data(EditorID) const;
        const JoystickData*                 data(JoystickID) const;
        const KeyboardData*                 data(KeyboardID) const;
        const LightData*                    data(LightID) const;
        const Light³Data*                   data(Light³ID) const;
        const ManagerData*                  data(ManagerID) const;
        const ModelData*                    data(ModelID) const;
        const MonitorData*                  data(MonitorID) const;
        const MouseData*                    data(MouseID) const;
        const RenderedData*                 data(RenderedID) const;
        const Rendered³Data*                data(Rendered³ID) const;
        const SceneData*                    data(SceneID) const;
        const Scene³Data*                   data(Scene³ID) const;
        const SpatialData*                  data(SpatialID) const;
        const Spatial³Data*                 data(Spatial³ID) const;
        const TachyonData*                  data(TachyonID) const;
        const ThreadData*                   data(ThreadID) const;
        const ViewerData*                   data(ViewerID) const;
        const WidgetData*                   data(WidgetID) const;
        const WindowData*                   data(WindowID) const;
        
        //! Camera pointer
        //! \note WARNING this will break thread-safety guarantees
        Camera*                             object(CameraID) const;
        Camera³*                            object(Camera³ID) const;

        Controller*                         object(ControllerID) const;

        //! Cursor pointer
        //! \note WARNING this will break thread-safety guarantees
        Cursor*                             object(CursorID) const;

        //! Desktop pointer
        //! \note WARNING this will break thread-safety guarantees
        Desktop*                            object(DesktopID) const;

        //Editor*                             object(EditorID) const;

        //! Joystick pointer
        //! \note WARNING this will break thread-safety guarantees
        Joystick*                           object(JoystickID) const;

        //! Keyboard pointer
        //! \note WARNING this will break thread-safety guarantees
        Keyboard*                           object(KeyboardID) const;

        //! Light pointer
        //! \note WARNING this will break thread-safety guarantees
        Light*                              object(LightID) const;

        Light³*                             object(Light³ID) const;

        //! Manager pointer
        //! \note WARNING this will break thread-safety guarantees
        Manager*                            object(ManagerID) const;

        //! Model pointer
        //! \note WARNING this will break thread-safety guarantees
        Model*                              object(ModelID) const;

        //! Mouse pointer
        //! \note WARNING this will break thread-safety guarantees
        Mouse*                              object(MouseID) const;

        //! Rendered pointer
        //! \note WARNING this will break thread-safety guarantees
        Rendered*                           object(RenderedID) const;

        Rendered³*                          object(Rendered³ID) const;

        Scene*                              object(SceneID) const;
        Scene³*                             object(Scene³ID) const;

        Spatial*                            object(SpatialID) const;
        Spatial³*                           object(Spatial³ID) const;

        //! Tachyon pointer
        //! \note WARNING this will break thread-safety guarantees
        Tachyon*                            object(TachyonID) const;

        //! Thread pointer
        //! \note WARNING this will break thread-safety guarantees
        Thread*                             object(ThreadID) const;
        
        Viewer*                             object(ViewerID) const;

        //! Widget pointer
        //! \note WARNING this will break thread-safety guarantees
        Widget*                             object(WidgetID) const;
        
        //! Window pointer
        //! \note WARNING this will break thread-safety guarantees
        Window*                             object(WindowID) const;

        ThreadID                            owner(TachyonID) const;

        /*! \brief Gets the specific interface
        
            This will get the specific interface, if it exists.  
            Practically, this will be okay to call once a tick for a specific 
            tachyon/interface need, however, it should be cached for the rest
            of the tick (if practical). 
            
            \note DON'T GO WILD, ONLY CALL FOR NECESSARY INTERFACES ON DEMAND
        */
        template <typename C>
        C*                                  interface(TachyonID) const;

        proxy_span_t                        proxies(TachyonID) const;
        
        Proxy*                              proxy(TachyonID, const InterfaceInfo&) const;
        
        const CameraSnap*                   snap(CameraID) const;
        const Camera³Snap*                  snap(Camera³ID) const;
        const ControllerSnap*               snap(ControllerID) const;
        const CursorSnap*                   snap(CursorID) const;
        const DesktopSnap*                  snap(DesktopID) const;
        //const EditorSnap*                   snap(EditorID) const;
        const JoystickSnap*                 snap(JoystickID) const;
        const KeyboardSnap*                 snap(KeyboardID) const;
        const LightSnap*                    snap(LightID) const;
        const Light³Snap*                   snap(Light³ID) const;
        const ManagerSnap*                  snap(ManagerID) const;
        const ModelSnap*                    snap(ModelID) const;
        const MonitorSnap*                  snap(MonitorID) const;
        const MouseSnap*                    snap(MouseID) const;
        const RenderedSnap*                 snap(RenderedID) const;
        const Rendered³Snap*                snap(Rendered³ID) const;
        const SceneSnap*                    snap(SceneID) const;
        const Scene³Snap*                   snap(Scene³ID) const;
        const SpatialSnap*                  snap(SpatialID) const;
        const Spatial³Snap*                 snap(Spatial³ID) const;
        const TachyonSnap*                  snap(TachyonID) const;
        const ThreadSnap*                   snap(ThreadID) const;
        const ViewerSnap*                   snap(ViewerID) const;
        const WidgetSnap*                   snap(WidgetID) const;
        const WindowSnap*                   snap(WindowID) const;

        Types           types(TachyonID) const;

        ThreadID        origin() const { return m_origin; }
        uint64_t        number() const { return m_number; }
        time_point_t    wallclock() const { return m_wallclock; }
        uint64_t        tick() const { return m_tick; }
        
        void            report(Stream&) const;

    private:

        static std::atomic<uint64_t>    s_lastId;

        template <typename T, typename D, typename S> 
        struct Container {
            using tachyon_k     = T;
            using data_k        = D;
            using snap_t        = S;
            
            std::unordered_map<uint64_t, Ref<T>>        objects;
            std::unordered_map<uint64_t, Ref<const D>>  datas;
            std::unordered_map<uint64_t, Ref<const S>>  snaps;
            
            void        insert(Tachyon*, const TachyonData*, const TachyonSnap*);
            const D*    data(uint64_t) const;
            const S*    snap(uint64_t) const;
            T*          pointer(uint64_t) const;
            bool        has(uint64_t) const;
            size_t      count() const;
        };
    
        const ThreadID          m_origin;
        const uint64_t          m_number;
        const time_point_t      m_wallclock;
        const uint64_t          m_tick;
        
        static thread_local const Frame*                        s_current;
        
        std::unordered_map<uint64_t, ThreadID>                  m_owners;
        std::unordered_map<uint64_t, Types>                     m_types;

        Container<Camera, CameraData, CameraSnap>               m_cameras;
        Container<Camera³, Camera³Data, Camera³Snap>            m_camera³s;
        Container<Controller, ControllerData, ControllerSnap>   m_controllers;
        Container<Cursor, CursorData, CursorSnap>               m_cursors;
        Container<Desktop, DesktopData, DesktopSnap>            m_desktops;
        //Container<Editor, EditorData, EditorSnap>               m_editors;
        Container<Joystick, JoystickData, JoystickSnap>         m_joysticks;
        Container<Keyboard, KeyboardData, KeyboardSnap>         m_keyboards;
        Container<Light, LightData, LightSnap>                  m_lights;
        Container<Light³, Light³Data, Light³Snap>               m_light³s;
        Container<Manager, ManagerData, ManagerSnap>            m_managers;
        Container<Model, ModelData, ModelSnap>                  m_models;
        Container<Monitor, MonitorData, MonitorSnap>            m_monitors;
        Container<Mouse, MouseData, MouseSnap>                  m_mouses;
        Container<Rendered, RenderedData, RenderedSnap>         m_rendereds;
        Container<Rendered³, Rendered³Data, Rendered³Snap>      m_rendered³s;
        Container<Scene, SceneData, SceneSnap>                  m_scenes;
        Container<Scene³, Scene³Data, Scene³Snap>               m_scene³s;
        Container<Spatial, SpatialData, SpatialSnap>            m_spatials;
        Container<Spatial³, Spatial³Data, Spatial³Snap>         m_spatial³s;
        Container<Tachyon, TachyonData, TachyonSnap>            m_tachyons;
        Container<Thread, ThreadData, ThreadSnap>               m_threads;
        Container<Viewer, ViewerData, ViewerSnap>               m_viewers;
        Container<Widget, WidgetData, WidgetSnap>               m_widgets;
        Container<Window, WindowData, WindowSnap>               m_windows;


        friend class Thread;
        friend FramePtr;
        friend FrameCPtr;

        Frame(ThreadID, uint64_t);
        ~Frame();
        
        void add(ThreadID, const TachyonFrame&);
        
        struct Builder;
    
        Frame(const Frame&) = delete;
        Frame(Frame&&) = delete;
        Frame& operator=(const Frame&) = delete;
        Frame& operator=(Frame&&) = delete;
    };

    template <typename C>
    C*      Frame::interface(TachyonID tid) const
    {
        if constexpr (is_interface_v<C>){
            for(Proxy* p : proxies(tid)){
                if(p -> interface(INFO) == &meta<C>()){
                    return static_cast<typename C::MyProxy*>(p);
                }
            }
            return nullptr;
        } 
        
        // other type, or non-existent, try the other way
        for(Proxy* p : proxies(tid)){
            if(C* c = dynamic_cast<C*>(p)){
                return c;
            }
        }
        return nullptr;
    }
}
