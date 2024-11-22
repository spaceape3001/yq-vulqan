////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/ID.hpp>
#include <yq/tachyon/typedef/camera.hpp>
#include <yq/tachyon/typedef/clock.hpp>
#include <yq/tachyon/typedef/frame.hpp>
//#include <yq/tachyon/typedef/light.hpp>
//#include <yq/tachyon/typedef/manager.hpp>
#include <yq/tachyon/typedef/rendered.hpp>
#include <yq/tachyon/typedef/post.hpp>
//#include <yq/tachyon/typedef/scene.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/tachyon/typedef/types.hpp>
//#include <yq/tachyon/typedef/viewer.hpp>
//#include <yq/tachyon/typedef/widget.hpp>

#include <chrono>
#include <unordered_map>

namespace yq::tachyon {
    class Proxy;

    /*
        Tachyons will *belong* to a thread... either directly or indirectly 
        (ie a chain).  During some threads execution (ie, sim-thread or viz-thread), 
        these may be temporarily delegated into other threads, but will not strip 
        the owning thread of ownership.
    */
    
    struct TachyonFrame;

    class Frame : public RefCount {
    public:
    
        using proxy_span_t  = std::span<Proxy* const>;

        bool contains(CameraID) const;
        //bool contains(EditorID) const;
        //bool contains(LightID) const;
        //bool contains(ManagerID) const;
        bool contains(RenderedID) const;
        //bool contains(SceneID) const;
        bool contains(TachyonID) const;
        bool contains(ThreadID) const;
        //bool contains(ViewerID) const;
        //bool contains(WidgetID) const;
    
        const CameraData*                   data(CameraID) const;
        //const EditorData*                   data(EditorID) const;
        //const LightData*                    data(LightID) const;
        //const ManagerData*                  data(ManagerID) const;
        const RenderedData*                 data(RenderedID) const;
        //const SceneData*                    data(SceneID) const;
        const TachyonData*                  data(TachyonID) const;
        const ThreadData*                   data(ThreadID) const;
        //const ViewerData*                   data(ViewerID) const;
        //const WidgetData*                   data(WidgetID) const;
        

        Camera*                             object(CameraID) const;
        //Editor*                             object(EditorID) const;
        //Light*                              object(LightID) const;
        //Manager*                            object(ManagerID) const;
        Rendered*                           object(RenderedID) const;
        //Scene*                              object(SceneID) const;
        Tachyon*                            object(TachyonID) const;
        Thread*                             object(ThreadID) const;
        //Viewer*                             object(ThreadID) const;
        //Widget*                             object(ThreadID) const;
        
        ThreadID                            owner(TachyonID) const;
        proxy_span_t                        proxies(TachyonID) const;
        
        const CameraSnap*                   snap(CameraID) const;
        //const EditorSnap*                   snap(EditorID) const;
        //const LightSnap*                    snap(LightID) const;
        //const ManagerSnap*                  snap(ManagerID) const;
        const RenderedSnap*                 snap(RenderedID) const;
        const TachyonSnap*                  snap(TachyonID) const;
        const ThreadSnap*                   snap(ThreadID) const;
        //const SceneSnap*                    snap(SceneID) const;
        //const ViewerSnap*                   snap(ViewerID) const;
        //const WidgetSnap*                   snap(WidgetID) const;

        Types           types(TachyonID) const;

        ThreadID        origin() const { return m_origin; }
        uint64_t        number() const { return m_number; }
        time_point_t    wallclock() const { return m_wallclock; }
        uint64_t        tick() const { return m_tick; }

    private:

        static std::atomic<uint64_t>    s_lastId;

        template <typename T, typename D, typename S> 
        struct Container {
            using tachyon_t     = T;
            using data_t        = D;
            using snap_t        = S;
            
            std::unordered_map<uint64_t, Ref<T>>        objects;
            std::unordered_map<uint64_t, Ref<const D>>  datas;
            std::unordered_map<uint64_t, Ref<const S>>  snaps;
            
            void        insert(Tachyon*, const TachyonData*, const TachyonSnap*);
            const D*    data(uint64_t) const;
            const S*    snap(uint64_t) const;
            T*          pointer(uint64_t) const;
            bool        has(uint64_t) const;
        };
    
        const ThreadID          m_origin;
        const uint64_t          m_number;
        const time_point_t      m_wallclock;
        const uint64_t          m_tick;
        
        std::unordered_map<uint64_t, ThreadID>              m_owners;
        std::unordered_map<uint64_t, Types>                 m_types;

        Container<Camera, CameraData, CameraSnap>           m_cameras;
        //Container<Editor, EditorData, EditorSnap>           m_editors;
        //Container<Light, LightData, LightSnap>              m_lights;
        //Container<Manager, ManagerData, ManagerSnap>        m_managers;
        Container<Rendered, RenderedData, RenderedSnap>     m_rendereds;
        Container<Tachyon, TachyonData, TachyonSnap>        m_tachyons;
        Container<Thread, ThreadData, ThreadSnap>           m_threads;
        //Container<Viewer, ViewerData, ViewerSnap>           m_viewers;
        //Container<Widget, WidgetData, WidgetSnap>           m_widgets;

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
}
