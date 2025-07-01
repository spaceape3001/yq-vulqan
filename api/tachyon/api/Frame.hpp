////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <tachyon/keywords.hpp>
#include <tachyon/api/ID.hpp>
#include <tachyon/api/Type.hpp>
#include <tachyon/api/TypedID.hpp>
#include <tachyon/api/Interface.hpp>
#include <tachyon/api/Proxy.hpp>
#include <tachyon/typedef/camera.hpp>
#include <tachyon/typedef/camera3.hpp>
#include <tachyon/typedef/clock.hpp>
#include <tachyon/typedef/controller.hpp>
#include <tachyon/typedef/cursor.hpp>
#include <tachyon/typedef/desktop.hpp>
#include <tachyon/typedef/frame.hpp>
#include <tachyon/typedef/gamepad.hpp>
#include <tachyon/typedef/graphics_card.hpp>
#include <tachyon/typedef/group.hpp>
#include <tachyon/typedef/joystick.hpp>
#include <tachyon/typedef/keyboard.hpp>
#include <tachyon/typedef/layer.hpp>
#include <tachyon/typedef/light.hpp>
#include <tachyon/typedef/light3.hpp>
#include <tachyon/typedef/manager.hpp>
#include <tachyon/typedef/model.hpp>
#include <tachyon/typedef/monitor.hpp>
#include <tachyon/typedef/mouse.hpp>
#include <tachyon/typedef/rendered.hpp>
#include <tachyon/typedef/rendered3.hpp>
#include <tachyon/typedef/post.hpp>
#include <tachyon/typedef/scene.hpp>
#include <tachyon/typedef/scene3.hpp>
#include <tachyon/typedef/spatial.hpp>
#include <tachyon/typedef/spatial2.hpp>
#include <tachyon/typedef/spatial3.hpp>
#include <tachyon/typedef/tachyon.hpp>
#include <tachyon/typedef/thread.hpp>
#include <tachyon/typedef/viewer.hpp>
#include <tachyon/typedef/widget.hpp>
#include <tachyon/typedef/window.hpp>

#include <tachyon/logging.hpp>

#include <chrono>
#include <functional>
#include <unordered_map>
#include <set>

namespace yq { class Stream; }

namespace yq::tachyon {
    class Proxy;
    class InterfaceMeta;

    /*
        Tachyons will *belong* to a thread... either directly or indirectly 
        (ie a chain).  During some threads execution (ie, sim-thread or viz-thread), 
        these may be temporarily delegated into other threads, but will not strip 
        the owning thread of ownership.
    */
    
    struct TachyonFrame;

    class Frame : public RefCount {
    public:
    
        using KeyToIDMap    = std::multimap<std::string,uint64_t,IgCase>;
    
        //! Returns the current "published" frame for this thread 
        //! \note This may be null, so check!
        static const Frame*     current() { return s_current; }
    
        static TypedID  resolve(TachyonSpec);
    
        using proxy_span_t  = std::span<Proxy* const>;

        std::span<const TypedID>    children(TachyonID) const;
        
        bool contains(CameraID) const;
        bool contains(Camera³ID) const;
        bool contains(ControllerID) const;
        bool contains(CursorID) const;
        bool contains(DesktopID) const;
        //bool contains(EditorID) const;
        bool contains(GamepadID) const;
        bool contains(GraphicsCardID) const;
        bool contains(GroupID) const;
        bool contains(JoystickID) const;
        bool contains(KeyboardID) const;
        bool contains(LayerID) const;
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
        bool contains(Spatial²ID) const;
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
        size_t count(gamepad_k) const;
        size_t count(graphics_card_k) const;
        size_t count(group_k) const;
        size_t count(joystick_k) const;
        size_t count(keyboard_k) const;
        size_t count(layer_k) const;
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
        size_t count(spatial²_k) const;
        size_t count(spatial³_k) const;
        size_t count(tachyon_k) const;
        size_t count(thread_k) const;
        size_t count(viewer_k) const;
        size_t count(widget_k) const;
        size_t count(window_k) const;
        
        size_t count(children_k, TachyonID) const;
    
        const CameraData*                   data(CameraID) const;
        const Camera³Data*                  data(Camera³ID) const;
        const ControllerData*               data(ControllerID) const;
        const CursorData*                   data(CursorID) const;
        const DesktopData*                  data(DesktopID) const;
        //const EditorData*                   data(EditorID) const;
        const GamepadData*                  data(GamepadID) const;
        const GraphicsCardData*             data(GraphicsCardID) const;
        const GroupData*                    data(GroupID) const;
        const JoystickData*                 data(JoystickID) const;
        const KeyboardData*                 data(KeyboardID) const;
        const LayerData*                    data(LayerID) const;
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
        const Spatial²Data*                 data(Spatial²ID) const;
        const Spatial³Data*                 data(Spatial³ID) const;
        const TachyonData*                  data(TachyonID) const;
        const ThreadData*                   data(ThreadID) const;
        const ViewerData*                   data(ViewerID) const;
        const WidgetData*                   data(WidgetID) const;
        const WindowData*                   data(WindowID) const;
        
        GraphicsCardID                      first(graphics_card_k) const;
        
        template <typename C, typename Pred>
        void        foreach(ptr_k, std::span<const TypedID> ids, Pred&& pred) const;
        
        template <typename C, typename Pred>
        void        foreach(ref_k, std::span<const TypedID> ids, Pred&& pred) const;
        
        template <typename Pred>
        void        foreach(child_k, TachyonID, Pred&& pred) const;

        template <typename Pred>
        void        foreach(child_k, recursive_k, TachyonID, Pred&& pred) const;
        
        const std::set<CameraID>&           ids(camera_k) const;
        const std::set<Camera³ID>&          ids(camera³_k) const;
        const std::set<ControllerID>&       ids(controller_k) const;
        const std::set<CursorID>&           ids(cursor_k) const;
        const std::set<DesktopID>&          ids(desktop_k) const;
        const std::set<GamepadID>&          ids(gamepad_k) const;
        const std::set<GraphicsCardID>&     ids(graphics_card_k) const;
        const std::set<GroupID>&            ids(group_k) const;
        const std::set<JoystickID>&         ids(joystick_k) const;
        const std::set<KeyboardID>&         ids(keyboard_k) const;
        const std::set<LayerID>&            ids(layer_k) const;
        const std::set<LightID>&            ids(light_k) const;
        const std::set<Light³ID>&           ids(light³_k) const;
        const std::set<ManagerID>&          ids(manager_k) const;
        const std::set<ModelID>&            ids(model_k) const;
        const std::set<MonitorID>&          ids(monitor_k) const;
        const std::set<MouseID>&            ids(mouse_k) const;
        const std::set<RenderedID>&         ids(rendered_k) const;
        const std::set<Rendered³ID>&        ids(rendered³_k) const;
        const std::set<SceneID>&            ids(scene_k) const;
        const std::set<Scene³ID>&           ids(scene³_k) const;
        const std::set<SpatialID>&          ids(spatial_k) const;
        const std::set<Spatial²ID>&         ids(spatial²_k) const;
        const std::set<Spatial³ID>&         ids(spatial³_k) const;
        const std::set<TachyonID>&          ids(tachyon_k) const;
        const std::set<ThreadID>&           ids(thread_k) const;
        const std::set<ViewerID>&           ids(viewer_k) const;
        const std::set<WidgetID>&           ids(widget_k) const;
        const std::set<WindowID>&           ids(window_k) const;

        const CameraMeta*                   info(CameraID) const;
        const Camera³Info*                  info(Camera³ID) const;
        const ControllerMeta*               info(ControllerID) const;
        const CursorInfo*                   info(CursorID) const;
        const DesktopInfo*                  info(DesktopID) const;
        const GamepadInfo*                  info(GamepadID) const;
        const GraphicsCardInfo*             info(GraphicsCardID) const;
        const GroupMeta*                    info(GroupID) const;
        const JoystickInfo*                 info(JoystickID) const;
        const KeyboardInfo*                 info(KeyboardID) const;
        const LayerMeta*                    info(LayerID) const;
        const LightMeta*                    info(LightID) const;
        const Light³Info*                   info(Light³ID) const;
        const ManagerMeta*                  info(ManagerID) const;
        const ModelMeta*                    info(ModelID) const;
        const MouseInfo*                    info(MouseID) const;
        const RenderedMeta*                 info(RenderedID) const;
        const Rendered³Info*                info(Rendered³ID) const;
        const SceneMeta*                    info(SceneID) const;
        const Scene³Info*                   info(Scene³ID) const;
        const SpatialMeta*                  info(SpatialID) const;
        const Spatial²Info*                 info(Spatial²ID) const;
        const Spatial³Info*                 info(Spatial³ID) const;
        const TachyonMeta*                  info(TachyonID) const;
        const ThreadMeta*                   info(ThreadID) const;
        const TachyonMeta*                  info(ViewerID) const;
        const WidgetMeta*                   info(WidgetID) const;
        const WindowInfo*                   info(WindowID) const;
        
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
        
        Gamepad*                            object(GamepadID) const;

        GraphicsCard*                       object(GraphicsCardID) const;

        //! Group pointer
        //! \note WARNING this will break thread-safety guarantees
        Group*                              object(GroupID) const;

        //! Joystick pointer
        //! \note WARNING this will break thread-safety guarantees
        Joystick*                           object(JoystickID) const;

        //! Keyboard pointer
        //! \note WARNING this will break thread-safety guarantees
        Keyboard*                           object(KeyboardID) const;

        //! Layer pointer
        //! \note WARNING this will break thread-safety guarantees
        Layer*                              object(LayerID) const;

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
        Spatial²*                           object(Spatial²ID) const;
        Spatial³*                           object(Spatial³ID) const;

        //! Tachyon pointer
        //! \note WARNING this will break thread-safety guarantees
        Tachyon*                            object(TachyonID) const;

        Tachyon*                            object(tachyon_k, uint64_t) const;

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

        Tachyon*                            object(parent_k, TachyonID) const;
        Tachyon*                            object(root_k, TachyonID) const;

        ThreadID                            owner(TachyonID) const;
        TypedID                             parent(TachyonID) const;

        //! First parent of type (ie, may skip
        TypedID                             parent(Type, TachyonID) const;


        proxy_span_t                        proxies(TachyonID) const;
        
        /*! \brief Gets the specific proxy
        
            This will get the specific proxy, if it exists.  
            Practically, this will be okay to call once a tick for a specific 
            tachyon/interface need, however, it should be cached for the rest
            of the tick (if practical). 
            
            \note DON'T GO WILD, ONLY CALL FOR NECESSARY INTERFACES ON DEMAND
        */
        template <typename P>
        P*                                  proxy(TachyonID) const;

        Proxy*                              proxy(TachyonID, const InterfaceMeta&) const;
        
        //! Gets the root tachyon of this chain
        //! \note It'll return wherever the tree stops in this frame (ie, missing snapshot)
        //! \note Root *may* be itself for the case of no-parent
        TypedID                             root(TachyonID) const;
        
        //! Gets the upper most tachyon of given type
        //! \note If specified tachyon *fits*, it'll be returned
        TypedID                             root(Type, TachyonID) const;

        
        const CameraSnap*                   snap(CameraID) const;
        const Camera³Snap*                  snap(Camera³ID) const;
        const ControllerSnap*               snap(ControllerID) const;
        const CursorSnap*                   snap(CursorID) const;
        const DesktopSnap*                  snap(DesktopID) const;
        //const EditorSnap*                   snap(EditorID) const;
        const GamepadSnap*                  snap(GamepadID) const;
        const GraphicsCardSnap*             snap(GraphicsCardID) const;
        const GroupSnap*                    snap(GroupID) const;
        const JoystickSnap*                 snap(JoystickID) const;
        const KeyboardSnap*                 snap(KeyboardID) const;
        const LayerSnap*                    snap(LayerID) const;
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
        const Spatial²Snap*                 snap(Spatial²ID) const;
        const Spatial³Snap*                 snap(Spatial³ID) const;
        const TachyonSnap*                  snap(TachyonID) const;
        const ThreadSnap*                   snap(ThreadID) const;
        const ViewerSnap*                   snap(ViewerID) const;
        const WidgetSnap*                   snap(WidgetID) const;
        const WindowSnap*                   snap(WindowID) const;
        

        Types           types(TachyonID) const;
        TypedID         typed(TachyonID) const;

        ThreadID        origin() const { return m_origin; }
        uint64_t        number() const { return m_number; }
        time_point_t    wallclock() const { return m_wallclock; }
        uint64_t        tick() const { return m_tick; }
        
        void            report(Stream&) const;

    private:

        static std::atomic<uint64_t>    s_lastId;

        // triple template argument to avoid the header includes for smarter
        template <typename T, typename D, typename S> 
        struct Container {
            using tachyon_k     = T;
            using data_k        = D;
            using snap_t        = S;
            
            std::unordered_map<uint64_t, Ref<T>>        objects;
            std::unordered_map<uint64_t, Ref<const D>>  datas;
            std::unordered_map<uint64_t, Ref<const S>>  snaps;
            std::multimap<std::string,uint64_t,IgCase>  names;
            std::set<ID<T>>                             ids;
            
            void        insert(Tachyon*, const TachyonData*, const TachyonSnap*);
            const D*    data(uint64_t) const;
            const S*    snap(uint64_t) const;
            T*          pointer(uint64_t) const;
            bool        has(uint64_t) const;
            size_t      count() const;
            ID<T>       first() const;
        };
    
        const ThreadID          m_origin;
        const uint64_t          m_number;
        const time_point_t      m_wallclock;
        const uint64_t          m_tick;
        
        static thread_local const Frame*                            s_current;
                                                                    
        std::unordered_map<uint64_t, ThreadID>                      m_owners;
        std::unordered_map<uint64_t, Types>                         m_types;
                                                                    
        Container<Camera, CameraData, CameraSnap>                   m_cameras;
        Container<Camera³, Camera³Data, Camera³Snap>                m_camera³s;
        Container<Controller, ControllerData, ControllerSnap>       m_controllers;
        Container<Cursor, CursorData, CursorSnap>                   m_cursors;
        Container<Desktop, DesktopData, DesktopSnap>                m_desktops;
        //Container<Editor, EditorData, EditorSnap>                   m_editors;
        Container<Gamepad, GamepadData, GamepadSnap>                m_gamepads;
        Container<GraphicsCard, GraphicsCardData, GraphicsCardSnap> m_graphicsCards;
        Container<Group, GroupData, GroupSnap>                      m_groups;
        Container<Joystick, JoystickData, JoystickSnap>             m_joysticks;
        Container<Keyboard, KeyboardData, KeyboardSnap>             m_keyboards;
        Container<Layer, LayerData, LayerSnap>                      m_layers;
        Container<Light, LightData, LightSnap>                      m_lights;
        Container<Light³, Light³Data, Light³Snap>                   m_light³s;
        Container<Manager, ManagerData, ManagerSnap>                m_managers;
        Container<Model, ModelData, ModelSnap>                      m_models;
        Container<Monitor, MonitorData, MonitorSnap>                m_monitors;
        Container<Mouse, MouseData, MouseSnap>                      m_mouses;
        Container<Rendered, RenderedData, RenderedSnap>             m_rendereds;
        Container<Rendered³, Rendered³Data, Rendered³Snap>          m_rendered³s;
        Container<Scene, SceneData, SceneSnap>                      m_scenes;
        Container<Scene³, Scene³Data, Scene³Snap>                   m_scene³s;
        Container<Spatial, SpatialData, SpatialSnap>                m_spatials;
        Container<Spatial², Spatial²Data, Spatial²Snap>             m_spatial²s;
        Container<Spatial³, Spatial³Data, Spatial³Snap>             m_spatial³s;
        Container<Tachyon, TachyonData, TachyonSnap>                m_tachyons;
        Container<Thread, ThreadData, ThreadSnap>                   m_threads;
        Container<Viewer, ViewerData, ViewerSnap>                   m_viewers;
        Container<Widget, WidgetData, WidgetSnap>                   m_widgets;
        Container<Window, WindowData, WindowSnap>                   m_windows;


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

    template <typename Pred>
    void    Frame::foreach(child_k, TachyonID tac, Pred&& pred) const
    {
        for(TypedID typed : children(tac)){
            pred(typed);
        }
    }

    template <typename Pred>
    void    Frame::foreach(child_k, recursive_k, TachyonID tac, Pred&& pred) const
    {
        for(TypedID typed : children(tac)){
            pred(typed);
            foreach(CHILD, RECURSIVE, typed, pred);
        }
    }

    template <typename C, typename Pred>
    void    Frame::foreach(ptr_k, std::span<const TypedID> ids, Pred&& pred) const
    {
        for(const TypedID& t : ids){
            C*  c   = dynamic_cast<C*>(object(TACHYON, t.id));
            if(c){
                pred(c);
            }
        }
    }

    template <typename C, typename Pred>
    void    Frame::foreach(ref_k, std::span<const TypedID> ids, Pred&& pred) const
    {
        for(const TypedID& t : ids){
            C*  c   = dynamic_cast<C*>(object(TACHYON, t.id));
            if(c){
                pred(*c);
            }
        }
    }

    template <typename C>
    C*      Frame::proxy(TachyonID tid) const
    {
        for(Proxy* p : proxies(tid)){
            if(C* c = dynamic_cast<C*>(p)){
                return c;
            }
        }

        return nullptr;
    }
}
