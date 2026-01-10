////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Gesture.hpp"
#include "GestureMetaWriter.hpp"
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/app/Viewer.hpp>
#include <yq/tachyon/app/ViewerData.hpp>
#include <yq/tachyon/os/Window.hpp>
#include <yq/tachyon/os/WindowData.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Gesture)

namespace yq::tachyon {
    
    GestureMeta::GestureMeta(std::string_view name, ObjectMeta& base, const std::source_location& sl) :
        ObjectMeta(name, base, sl)
    {
    }
    
    thread_local Widget*        Gesture::s_widget       = nullptr;
    thread_local ViContext*     Gesture::s_viContext    = nullptr;
    thread_local const Context* Gesture::s_context      = nullptr;

    void            Gesture::gesture(GesturePtr&& g)
    {
        if(s_widget)
            s_widget -> gesture(std::move(g));
    }

    ViewerID       Gesture::id(viewer_k)
    {
        if(s_widget)
            return s_widget -> viewer();
        return {};
    }
    
    WidgetID       Gesture::id(widget_k)
    {
        if(s_widget)
            return s_widget->id();
        return {};
    }
    
    WindowID       Gesture::id(window_k)
    {
        const ViewerSnap*   vsnap   = snap(VIEWER);
        if(!vsnap)
            return {};
        return { vsnap -> window.id };
    }


    void           Gesture::mail(const PostCPtr& pp)
    {
        if(s_widget)
            s_widget -> mail(pp);
    }
    
    void           Gesture::send(const PostCPtr& pp)
    {
        if(s_widget)
            s_widget -> send(pp, TARGET);
    }

    const ViewerSnap*    Gesture::snap(viewer_k)
    {
        ViewerID    vid = id(VIEWER);
        if(!vid)
            return nullptr;
        const Frame*    frame   = Frame::current();
        if(!frame)
            return nullptr;
        return frame->snap(vid);
    }

    const WindowSnap*    Gesture::snap(window_k)
    {
        WindowID    wid = id(WINDOW);
        if(!wid)    
            return nullptr;
        return Frame::current()->snap(wid);
    }

    ///////////////

    Gesture::Gesture()
    {
    }
    
    Gesture::Gesture(const Gesture&)
    {
    }
    
    Gesture::~Gesture()
    {
    }

    
    void Gesture::init_meta()
    {
        auto w = writer<Gesture>();
        w.abstract();
        w.description("Gesture base");
    }
}
