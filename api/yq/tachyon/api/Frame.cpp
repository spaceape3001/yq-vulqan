////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CameraData.hpp"
#include "Frame.hpp"
#include "Post.hpp"
#include "Proxy.hpp"
#include "Tachyon.hpp"
#include "TachyonData.hpp"
#include "Thread.hpp"
#include "ThreadData.hpp"
#include "ViewerData.hpp"
#include "WidgetData.hpp"

namespace yq::tachyon {

    template <SomeTachyon T>
    struct Frame::Container {
        using snap_t    = typename T::MySnap;
        using data_t    = typename T::MyData;
    
        std::unordered_map<uint64_t, Ref<T>>                objects;
        std::unordered_map<uint64_t, Ref<const data_t>>     datas;
        std::unordered_map<uint64_t, Ref<const snap_t>>     snaps;
        
        void    insert(Tachyon* p, const TachyonData* d, const TachyonSnap* s)
        {
            objects[p->id]      = static_cast<T*>(p);
            datas[p->id]        = static_cast<const data_t*>(d);
            snaps[p->id]        = static_cast<const snap_t*>(s);
        }
        
        const data_t*   data(uint64_t n) const
        {
            auto i = datas.find(n);
            if(i != datas.end())
                return i->second.ptr();
            return nullptr;
        }
        
        const snap_t    snap(uint64_t n) const
        {
            auto i = snaps.find(n);
            if(i != snaps.end())
                return i->second.ptr();
            return nullptr;
        }
        
        T* pointer(uint64_t n) const
        {
            auto i = objects.find(n);
            if(i != objects.end())
                return i->second.ptr();
            return nullptr;
        }
    };

    std::atomic<uint64_t>    Frame::s_lastId{0};
    
    struct Frame::Impl {
        const ThreadID          thread;
        const uint64_t          number;
        const time_point_t      wallclock;

        //Container<Camera>       cameras;
        //Container<Editor>       editors;
        //Container<Light>        lights;
        //Container<Manager>      managers;
        //Container<Rendered>     rendereds;
        //Container<Scene>        scenes;
        Container<Tachyon>      tachyons;
        Container<Thread>       threads;
        //Container<Viewer>       viewers;
        //Container<Widget>       widgets;
        
        Impl(ThreadID th) : thread(th), number(++s_lastId), wallclock(clock_t::now()) 
    };


    
    Frame::Frame(ThreadID th) : m(new Impl(th))
    {
    }

    Frame::~Frame()
    {
    }

    void    Frame::add(TachyonPtr p, TachyonDataPtr d, TachyonSnapPtr s)
    {
        if(!(p && d && s))  
            return ;

        m->tachyons.insert(p.ptr(), d.ptr(), s.ptr());

        Types   types   = p -> metaInfo().types();
        //if(types(Type::Camera))
            //m->cameras.insert(p.ptr(), d.ptr(), s.ptr());
        //if(types(Type::Editor))
            //m->editors.insert(p.ptr(), d.ptr(), s.ptr());
        //if(types(Type::Light))
            //m->lights.insert(p.ptr(), d.ptr(), s.ptr());
        //if(types(Type::Manager))
            //m->managers.insert(p.ptr(), d.ptr(), s.ptr());
        //if(types(Type::Rendered))
            //m->rendereds.insert(p.ptr(), d.ptr(), s.ptr());
        //if(types(Type::Scene))
            //m->scenes.insert(p.ptr(), d.ptr(), s.ptr());
        if(types(Type::Thread))
            m->threads.insert(p.ptr(), d.ptr(), s.ptr());
        //if(types(Type::Viewer))
            //m->viewers.insert(p.ptr(), d.ptr(), s.ptr());
        //if(types(Type::Widget))
            //m->widgets.insert(p.ptr(), d.ptr(), s.ptr());
    }
    
    
    #if 0
    const CameraData*                   Frame::data(CameraID id) const
    {
        return m->cameras.data(id);
    }
    #endif

    #if 0
    const EditorData*                   Frame::data(EditorID id) const
    {
        return m->editors.data(id);
    }
    #endif

    #if 0
    const LightData*                   Frame::data(LightID id) const
    {
        return m->lights.data(id);
    }
    #endif

    #if 0
    const ManagerData*                  Frame::data(ManagerID id) const
    {
        return m->managers.data(id);
    }
    #endif

    #if 0
    const RenderedsData*                Frame::data(RenderedsID id) const
    {
        return m->rendereds.data(id);
    }
    #endif

    const TachyonData*                  Frame::data(TachyonID id) const
    {
        return m->tachyons.data(id);
    }
    
    const ThreadData*                   Frame::data(ThreadID id) const
    {
        return m->threads.data(id);
    }

    #if 0
    const ViewerData*                   Frame::data(ViewerID id) const
    {
        return m->viewers.data(id);
    }
    #endif

    #if 0
    const WidgetData*                   Frame::data(WidgetID id) const
    {
        return m->widgets.data(id);
    }
    #endif

    #if 0
    Camera*                             Frame::object(CameraID id) const
    {
        return m->cameras.pointer(id);
    }
    #endif

    #if 0
    Manager*                            Frame::object(ManagerID id) const
    {
        return m->managers.pointer(id);
    }
    #endif

    #if 0
    Rendered*                           Frame::object(RenderedID id) const
    {
        const RenderedSnap*   ts  = snap(id);
        if(!ts)
            return nullptr;
        return static_cast<Rendered*>(const_cast<Tachyon*>(ts->object.ptr()));
    }
    #endif

    Tachyon*                            Frame::object(TachyonID id) const
    {
        const TachyonSnap*  ts  = snap(id);
        if(!ts)
            return nullptr;
        return const_cast<Tachyon*>(ts->object.ptr());
    }
    
    Thread*                             Frame::object(ThreadID id) const
    {
        const ThreadSnap*   ts  = snap(id);
        if(!ts)
            return nullptr;
        return static_cast<Thread*>(const_cast<Tachyon*>(ts->object.ptr()));
    }
    
    #if 0
    Viewer*                             Frame::object(ViewerID id) const
    {
        const ViewerSnap*   ts  = snap(id);
        if(!ts)
            return nullptr;
        return static_cast<Viewer*>(const_cast<Tachyon*>(ts->object.ptr()));
    }
    #endif

    #if 0
    Widget*                             Frame::object(WidgetID id) const
    {
        const WidgetSnap*   ts  = snap(id);
        if(!ts)
            return nullptr;
        return static_cast<Widget*>(const_cast<Tachyon*>(ts->object.ptr()));
    }
    #endif

    ThreadID                            Frame::owner(TachyonID id) const
    {
        const TachyonData* td   = data(id);
        if(!td)
            return {};
        return td->owner;
    }
    
    std::span<Proxy* const>             Frame::proxies(TachyonID id) const
    {
        const TachyonSnap* ts = snap(id);
        if(!ts)
            return {};
        return ts->proxies;
    }
    
    std::span<PostCPtr const>           Frame::received(TachyonID id) const
    {
        const TachyonData*  td  = data(id);
        if(!td)
            return {};
        return td->received;
    }
    
    std::span<PostCPtr const>           Frame::sent(TachyonID id) const
    {
        const TachyonData*  td  = data(id);
        if(!td)
            return {};
        return td->sent;
    }
    
    #if 0
    const CameraSnap*                  Frame::snap(CameraID id) const
    {
        const CameraData*  td  = data(id);
        if(!td)
            return nullptr;
        return static_cast<const CameraSnap*>(td->snap.ptr());
    }
    #endif

    #if 0
    const ManagerSnap*                 Frame::snap(ManagerID id) const
    {
        const ManagerData*  td  = data(id);
        if(!td)
            return nullptr;
        return static_cast<const ManagerSnap*>(td->snap.ptr());
    }
    #endif

    #if 0
    const RenderedData*                Frame::snap(RenderedID id) const
    {
        const RenderedSnap*  td  = data(id);
        if(!td)
            return nullptr;
        return static_cast<const RenderedSnap*>(td->snap.ptr());
    }
    #endif

    const TachyonSnap*                 Frame::snap(TachyonID id) const
    {
        const TachyonData*  td  = data(id);
        if(!td)
            return nullptr;
        return td->snap.ptr();
    }
    
    const ThreadSnap*                  Frame::snap(ThreadID id) const
    {
        const ThreadData*  td  = data(id);
        if(!td)
            return nullptr;
        return static_cast<const ThreadSnap*>(td->snap.ptr());
    }

    #if 0
    const ViewerSnap*                  Frame::snap(ViewerID id) const
    {
        const ViewerData*  td  = data(id);
        if(!td)
            return nullptr;
        return static_cast<const ViewerSnap*>(td->snap.ptr());
    }
    #endif

    #if 0
    const WidgetSnap*                  Frame::snap(WidgetID id) const
    {
        const WidgetData*  td  = data(id);
        if(!td)
            return nullptr;
        return static_cast<const WidgetSnap*>(td->snap.ptr());
    }
    #endif
}
