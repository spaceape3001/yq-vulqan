////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

//#include "Camera.hpp"
//#include "CameraData.hpp"
//#include "Editor.hpp"
//#include "EditorData.hpp"
#include "Frame.hpp"
#include "FrameBuilder.hpp"
//#include "Light.hpp"
//#include "LightData.hpp"
//#include "Manager.hpp"
//#include "ManagerData.hpp"
//#include "Post.hpp"
//#include "Proxy.hpp"
//#include "Rendered.hpp"
//#include "RenderedData.hpp"
//#include "Scene.hpp"
//#include "SceneData.hpp"
#include "Tachyon.hpp"
#include "TachyonData.hpp"
#include "Thread.hpp"
#include "ThreadData.hpp"
//#include "Viewer.hpp"
//#include "ViewerData.hpp"
//#include "Widget.hpp"
//#include "WidgetData.hpp"

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
    
    Frame::Frame(ThreadID th) : m_origin(th), m_number(++s_lastId), m_wallclock(clock_t::now()) 
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

        //if(types(Type::Camera))
            //m_cameras.insert(t, tac.data.ptr(), tac.snap.ptr());
        //if(types(Type::Editor))
            //m_editors.insert(t, tac.data.ptr(), tac.snap.ptr());
        //if(types(Type::Light))
            //m_lights.insert(t, tac.data.ptr(), tac.snap.ptr());
        //if(types(Type::Manager))
            //m_managers.insert(t, tac.data.ptr(), tac.snap.ptr());
        //if(types(Type::Rendered))
            //m_rendereds.insert(t, tac.data.ptr(), tac.snap.ptr());
        //if(types(Type::Scene))
            //m_scenes.insert(t, tac.data.ptr(), tac.snap.ptr());
        if(types(Type::Thread))
            m_threads.insert(t, tac.data.ptr(), tac.snap.ptr());
        //if(types(Type::Viewer))
            //m_viewers.insert(t, tac.data.ptr(), tac.snap.ptr());
        //if(types(Type::Widget))
            //m_widgets.insert(t, tac.data.ptr(), tac.snap.ptr());
    }
    
    #if 0
    bool Frame::contains(CameraID id) const
    {
        return m_cameras.has(id);
    }
    #endif

    #if 0
    bool Frame::contains(EditorID id) const
    {
        return m_editors.has(id);
    }
    #endif

    #if 0
    bool Frame::contains(LightID id) const
    {
        return m_lights.has(id);
    }
    #endif

    #if 0
    bool Frame::contains(ManagerID id) const
    {
        return m_managers.has(id);
    }
    #endif

    #if 0
    bool Frame::contains(RenderedID id) const
    {
        return m_rendereds.has(id);
    }
    #endif

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

    #if 0
    bool Frame::contains(WidgetID id) const
    {
        return m_widgets.has(id);
    }
    #endif
    
    #if 0
    const CameraData*                   Frame::data(CameraID id) const
    {
        return m_cameras.data(id);
    }
    #endif

    #if 0
    const EditorData*                   Frame::data(EditorID id) const
    {
        return m_editors.data(id);
    }
    #endif

    #if 0
    const LightData*                   Frame::data(LightID id) const
    {
        return m_lights.data(id);
    }
    #endif

    #if 0
    const ManagerData*                  Frame::data(ManagerID id) const
    {
        return m_managers.data(id);
    }
    #endif

    #if 0
    const RenderedsData*                Frame::data(RenderedsID id) const
    {
        return m_rendereds.data(id);
    }
    #endif

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

    #if 0
    const WidgetData*                   Frame::data(WidgetID id) const
    {
        return m_widgets.data(id);
    }
    #endif

    #if 0
    Camera*                             Frame::object(CameraID id) const
    {
        return m_cameras.pointer(id);
    }
    #endif

    #if 0
    Manager*                            Frame::object(ManagerID id) const
    {
        return m_managers.pointer(id);
    }
    #endif

    #if 0
    Rendered*                           Frame::object(RenderedID id) const
    {
        return m_rendereds.pointer(id);
    }
    #endif

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

    #if 0
    Widget*                             Frame::object(WidgetID id) const
    {
        return m_widgets.pointer(id);
    }
    #endif

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
    
    
    #if 0
    const CameraSnap*                  Frame::snap(CameraID id) const
    {
        return m_cameras.snap(id);
    }
    #endif

    #if 0
    const ManagerSnap*                 Frame::snap(ManagerID id) const
    {
        return m_managers.snap(id);
    }
    #endif

    #if 0
    const RenderedData*                Frame::snap(RenderedID id) const
    {
        return m_rendereds.snap(id);
    }
    #endif

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

    #if 0
    const WidgetSnap*                  Frame::snap(WidgetID id) const
    {
        return m_widgets.snap(id);
    }
    #endif
    
    Types   Frame::types(TachyonID id) const
    {
        auto i = m_types.find(id);
        if(i != m_types.end())
            return i->second;
        return {};
    }

    ////////////////////////
    // FRAME BUILDER
    
    Frame::Builder::Builder(ThreadID th)
    {
        m_frame   = new Frame(th);
    }
    
    Frame::Builder::~Builder()
    {
    }
    
    void        Frame::Builder::add(ThreadID th, const ThreadData& tdata)
    {
        if(!m_frame)
            return ;
            
        for(const TachyonFrame& tf : tdata.tachyons){
            if(!tf.object)
                continue;
            if(!tf.data)
                continue;
            if(!tf.snap)
                continue;
            switch(tf.state){
            case TachyonThreadState::Normal:
                m_frame->add(th, tf);
                break;
            case TachyonThreadState::Pushed:
                m_pushed.push_back({th, tf});
                break;
            default:
                break;
            }
        }
    }
    
    FramePtr    Frame::Builder::finalize()
    {
        if(!m_frame)
            return {};
            
        for(auto& p : m_pushed){
            if(m_frame -> contains(p.second.object->id()))
                continue;
            m_frame->add(p.first, p.second);
        }
        
        FramePtr    ret;
        std::swap(ret, m_frame);
        return ret;
    }
    
}
