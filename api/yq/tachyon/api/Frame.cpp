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
    std::atomic<uint64_t>    Frame::s_lastId{0};
    
    Frame::Frame(ThreadID th) : thread(th), number(++s_lastId), wallclock(clock_t::now()) 
    {
    }

    Frame::~Frame()
    {
        _clear(HASH);
        raw.clear();
    }

    bool    Frame::_add(const TachyonData* td)
    {
        if(!td)
            return false;
        if(!td->snap)
            return false;
        const Tachyon* tac    = td->snap->object.ptr();
        if(!tac)
            return false;
        
        tachyons[tac->id()]     = td;
        
        Types   types  = tac->metaInfo().types();
        
        //  And we'll do this one by one
        
        //if(types(Type::Camera))
        //    cameras[tac->id()]  = static_cast<const CameraData*>(td);
        //if(types(Type::Editor))
        //    editors[tac->id()]  = static_cast<const EditorData*>(td);
        //if(types(Type::Manager))
        //    managers[tac->id()] = static_cast<const ManagerData*>(td);
        //if(types(Type::Rendered))
        //    rendereds[tac->id()]  = static_cast<const RenderedData*>(td);
        if(types(Type::Thread))
            threads[tac->id()]  = static_cast<const ThreadData*>(td);
        //if(types(Type::Viewer))
        //    viewers[tac->id()]  = static_cast<const ViewerData*>(td);
        //if(types(Type::Widget))
        //    widgets[tac->id()]  = static_cast<const WidgetData*>(td);
        
        return true;
    }

    void    Frame::_clear(hash_t)
    {
        //cameras.clear();
        //managers.clear();
        //rendereds.clear();
        tachyons.clear();
        threads.clear();
        //viewers.clear();
        //widgets.clear();
    }

    void    Frame::build()
    {
        _clear(HASH);
        for(const ThreadDataCPtr& th : raw){
            if(!_add(th.ptr()))
                continue;
            for(const TachyonDataCPtr& tp : th->tachyons)
                _add(tp.ptr());
        }
    }
    
    #if 0
    const CameraData*                   Frame::data(CameraID id) const
    {
        auto i = cameras.find(id);
        if(i == cameras.end())
            return nullptr;
        return i->second;
    }
    #endif

    #if 0
    const ManagerData*                  Frame::data(ManagerID id) const
    {
        auto i = managers.find(id);
        if(i == managers.end())
            return nullptr;
        return i->second;
    }
    #endif

    #if 0
    const RenderedsData*                Frame::data(RenderedsID id) const
    {
        auto i = rendereds.find(id);
        if(i == rendereds.end())
            return nullptr;
        return i->second;
    }
    #endif

    const TachyonData*                  Frame::data(TachyonID id) const
    {
        auto i  = tachyons.find(id);
        if(i == tachyons.end())
            return nullptr;
        return i->second;
    }
    
    const ThreadData*                   Frame::data(ThreadID id) const
    {
        auto i = threads.find(id);
        if(i == threads.end())
            return nullptr;
        return i->second;
    }

    #if 0
    const ViewerData*                   Frame::data(ViewerID id) const
    {
        auto i = viewers.find(id);
        if(i == viewers.end())
            return nullptr;
        return i->second;
    }
    #endif

    #if 0
    const WidgetData*                   Frame::data(WidgetID id) const
    {
        auto i = widgets.find(id);
        if(i == widgets.end())
            return nullptr;
        return i->second;
    }
    #endif

    #if 0
    Camera*                             Frame::object(CameraID id) const
    {
        const CameraSnap*   ts  = snap(id);
        if(!ts)
            return nullptr;
        return static_cast<Camera*>(const_cast<Tachyon*>(ts->object.ptr()));
    }
    #endif

    #if 0
    Manager*                            Frame::object(ManagerID id) const
    {
        const ManagerSnap*   ts  = snap(id);
        if(!ts)
            return nullptr;
        return static_cast<Manager*>(const_cast<Tachyon*>(ts->object.ptr()));
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
