////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/ui/Widget.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>
#include <yt/ui/WidgetBind.hpp>
#include <yt/ui/WidgetData.hpp>

#include <yt/logging.hpp>
#include <yt/api/Frame.hpp>
#include <yt/app/Viewer.hpp>
#include <ya/commands/tachyon/DestroyCommand.hpp>
#include <ya/commands/ui/CloseCommand.hpp>
#include <ya/commands/ui/ShowCommand.hpp>
#include <ya/commands/ui/StartupCommand.hpp>
#include <ya/requests/ui/CloseRequest.hpp>
#include <ya/replies/ui/CloseReply.hpp>

#include <yq/text/format.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Widget)

namespace yq::tachyon {
    WidgetBind::WidgetBind(const Widget* v) : m_widget(v ? v->id() : WidgetID{}) 
    {
    }
    /////////////////////////


    WidgetInfo::WidgetInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
        set(Flag::WIDGET);
        set(Type::Widget);
    }

    void Widget::init_info()
    {
        auto w = writer<Widget>();
        w.description("Widget base class");
        //w.slot(&Widget::on_startup_command);
    }

    Widget::Widget() : Tachyon()
    {
        m_windowID      = std::string(fmt_hex(UniqueID::id()));
    }
    
    Widget::~Widget()
    {
    }

    void    Widget::close(accept_k)
    {
        PostID  pId;
        if(m_closeRequest)
            pId = m_closeRequest -> id();
        send(new CloseReply({.cause=pId, .target=m_viewer}, m_closeRequest, Response::QaPla));
        mail(new CloseCommand({.cause=pId, .target=*this}));
        m_closeRequest = {};
    }
    
    void    Widget::close(reject_k)
    {
        PostID  pId;
        if(m_closeRequest)
            pId = m_closeRequest -> id();
        send(new CloseReply({.cause=pId, .target=m_viewer}, m_closeRequest, Response::Rejected));
        m_closeRequest = {};
    }

    void    Widget::imgui(ViContext& u)
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
        frame->foreach<Widget>(PTR, children(), [&](Widget* w){
            w->imgui(u);
        });
    }
    
    void    Widget::vulkan(ViContext&u)
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
        frame->foreach<Widget>(PTR, children(), [&](Widget* w){
            w->vulkan(u);
        });
    }

    void    Widget::accept(close_k)
    {
        if(m_viewer)
            m_viewer -> accept(CLOSE);
    }
    

    PostAdvice    Widget::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const WidgetBind* p = dynamic_cast<const WidgetBind*>(&pp)){
            if(p->widget() != id())
                return REJECT;
        }
        return {};
    }

    bool    Widget::attached() const
    {
        return parent() || m_viewer;
    }

/*
    bool    Widget::has_parentage(const Widget* p) const
    {
        if(!p)
            return false;
        for(const Widget* x = m_parent; x; x = x -> m_parent){
            if(p == x)
                return true;
        }
        return false;
    }
*/

    bool    Widget::is_imgui() const
    {
        return metaInfo().is_imgui();
    }

    void    Widget::on_close_command(const CloseCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        
        mail(new DestroyCommand({.target=*this}));
    }

    void    Widget::on_close_request(const CloseRequestCPtr&req)
    {
        if(m_closeRequest){
            if(req){
                send(new CloseReply({.target=req->source()}, req, Response::Busy));
            }
            return ;
        }
        
        m_closeRequest  = req;
        close(REQUEST);
    }

#if 0
    void    Widget::on_startup_command(const StartupCommand&cmd)
    {
        if(cmd.target() == id()){
            startup();
        }
    }
#endif
    
    void            Widget::prerecord(ViContext& u)
    {
        for(Widget* w : m_children)
            w->prerecord(u);
    }

    void    Widget::reject(close_k)
    {
        if(m_viewer)
            m_viewer -> reject(CLOSE);
    }

    WidgetID        Widget::root() const
    {
        const Frame*    f   = Frame::current();
        if(!f)
            return nullptr;
        
        TypedID     w   = f->root(Type::Widget, id());
        if(w){
            return WidgetID(w.id);
        } else {
            return {};
        }
    }

    Widget*         Widget::root(ptr_k)
    {
        const Frame*    f   = Frame::current();
        if(!f)
            return nullptr;
        return f->object(root());
    }
    
    const Widget*   Widget::root(ptr_k) const
    {
        const Frame*    f   = Frame::current();
        if(!f)
            return nullptr;
        return f->object(root());
    }

    bool    Widget::set_parent(Widget* p)
    {
        if(p == m_parent)   // already the parent
            return true;
        if(p == this)       // it's this widget
            return false;
        if(p && p->has_parentage(this))      // no loops please
            return false;
            
        if(m_parent){
            //m_parent->child_removed(this);
            std::erase(m_parent->m_children, this);
        }
        m_parent    = p;
        if(m_parent){
            m_parent->m_children.push_back(this);
            //m_parent->child_added(this);
        }
        return true;
   }

    void    Widget::snap(const WidgetSnap&sn) const
    {
        Tachyon::snap(sn);
        sn.viewer   = TypedID(m_viewer);
    }

    bool            Widget::started() const
    {
        return m_flags(F::Started);
    }

    void            Widget::startup()
    {
        if(m_viewer){
            m_viewer->mail(new ShowCommand({.source=this, .target=m_viewer}));
        }
    }

    Execution       Widget::tick(const Context&) 
    {
        if(!m_flags(F::Startup)){
            startup();
        }
        return {};
    }

    Viewer*         Widget::viewer(ptr_k)
    {
        const Frame*    f   = Frame::current();
        if(!f)
            return nullptr;
        return f->object(viewer());
    }
    
    const Viewer*   Widget::viewer(ptr_k) const 
    {
        const Frame*    f   = Frame::current();
        if(!f)
            return nullptr;
        return f->object(viewer());
    }
    
    ViewerID        Widget::viewer() const
    {
        if(m_viewer)
            return m_viewer;
        
        const Frame*    f   = Frame::current();
        if(!f)
            return {};
        
        const WidgetSnap*   sn  = f->snap(root());
        if(!sn)
            return {};
        return sn -> viewer;
    }

    bool        Widget::visible() const
    {
        return m_flags(F::Visible);
    }

    Widget* Widget::widget_at(const Vector2D&) const
    {
        return const_cast<Widget*>(this);
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  EVENT PROCESSING (BELOW, one "section" per event type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

