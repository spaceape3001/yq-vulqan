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
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/thread.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/widget.hpp>

#include <chrono>
#include <unordered_map>

namespace yq::tachyon {

    struct CameraData;
    struct LightData;
    struct ManagerData;
    struct RenderedData;
    struct SceneData;
    struct TachyonData;
    struct ThreadData;
    struct ViewerData;
    struct WidgetData;
    
    struct ThreadSnap;
    class Thread;

    /*
        Tachyons will *belong* to a thread... either directly or indirectly 
        (ie a chain).  During some threads execution (ie, sim-thread or viz-thread), 
        these may be temporarily delegated into other threads, but will not strip 
        the owning thread of ownership.
    */

    class Frame : public RefCount {
    public:
    
        //const CameraData*                   data(CameraID) const;
        //const EditorData*                   data(EditorID) const;
        //const LightData*                    data(LightID) const;
        //const ManagerData*                  data(ManagerID) const;
        //const RenderedData*                 data(RenderedID) const;
        //const SceneData*                    data(SceneID) const;
        const TachyonData*                  data(TachyonID) const;
        const ThreadData*                   data(ThreadID) const;
        //const ViewerData*                   data(ViewerID) const;
        //const WidgetData*                   data(WidgetID) const;

        //Camera*                             object(CameraID) const;
        //Light*                              object(LightID) const;
        //Manager*                            object(ManagerID) const;
        //Rendered*                           object(RenderedID) const;
        //Scene*                              scene(SceneID) const;
        Tachyon*                            object(TachyonID) const;
        Thread*                             object(ThreadID) const;
        //Viewer*                             object(ThreadID) const;
        //Widget*                             object(ThreadID) const;
        
        ThreadID                            owner(TachyonID) const;
        std::span<Proxy* const>             proxies(TachyonID) const;
        std::span<PostCPtr const>           received(TachyonID) const;
        std::span<PostCPtr const>           sent(TachyonID) const;
        
        //const CameraSnap*                   snap(CameraID) const;
        //const LightSnap*                    snap(LightID) const;
        //const ManagerSnap*                  snap(ManagerID) const;
        //const RenderedSnap*                 snap(RenderedID) const;
        const TachyonSnap*                  snap(TachyonID) const;
        const ThreadSnap*                   snap(ThreadID) const;
        //const SceneSnap*                    snap(SceneID) const;
        //const ViewerSnap*                   snap(ViewerID) const;
        //const WidgetSnap*                   snap(WidgetID) const;
        
        Frame(ThreadID);
        ~Frame();
        
    private:
        friend class Thread;
    
        static std::atomic<uint64_t>    s_lastId;
        
        Frame(const Frame&) = delete;
        Frame(Frame&&) = delete;
        Frame& operator=(const Frame&) = delete;
        Frame& operator=(Frame&&) = delete;
        
        template <SomeTachyon> struct Container;
        
        struct Impl;
        std::unique_ptr<Impl>       m;
        
        void    add(TachyonPtr, TachyonDataCPtr, TachyonSnapCPtr);
    };
}
