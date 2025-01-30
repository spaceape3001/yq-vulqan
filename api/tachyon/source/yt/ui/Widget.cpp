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
#include <ya/commands/ui/HideCommand.hpp>
#include <ya/commands/ui/ShowCommand.hpp>
#include <ya/commands/ui/StartupCommand.hpp>
#include <ya/commands/widget/SetViewer.hpp>
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
    
    /////////////////////////
    
    WidgetData::~WidgetData()
    {
    }

    /////////////////////////

    WidgetSnap::~WidgetSnap()
    {
    }


    /////////////////////////

    void Widget::init_info()
    {
        auto w = writer<Widget>();
        w.description("Widget base class");
        w.slot(&Widget::on_close_request);
        w.slot(&Widget::on_close_command);
        w.slot(&Widget::on_set_viewer);
        //w.slot(&Widget::on_startup_command);
    }

    Widget::Widget() : Tachyon(), m_windowID(fmt_hex(UniqueID::id()))
    {
    }
    
    Widget::~Widget()
    {
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

    void    Widget::close(accept_k)
    {
yInfo() << ident() << "::close(ACCEPT)";
        PostID  pId;
        if(m_closeRequest)
            pId = m_closeRequest -> id();
        send(new CloseReply({.cause=pId, .target=m_viewer}, m_closeRequest, Response::QaPla));
        mail(new CloseCommand({.cause=pId, .target=*this}));
        m_closeRequest = {};
    }
    
    void    Widget::close(reject_k)
    {
yInfo() << ident() <<  "::close(REJECT)";
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

    //void    Widget::accept(close_k)
    //{
        //if(m_viewer)
            //m_viewer -> accept(CLOSE);
    //}
    

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
yInfo() << ident() << "::on_close_command(" << cmd.trace() << ")";
        if(cmd.target() != id())
            return ;
        if(m_viewer){
            send(new HideCommand({.source=*this, .target=m_viewer}), MG::Viewer);
        }
        mail(new HideCommand({.source=*this, .target=*this}));
        for(TypedID t : children()){
            send(new CloseCommand({.source=*this, .target=t}), {});
        }
        
yInfo() << ident() <<  "::on_close_command() ... sending destroy";
        teardown();
        //mail(new DestroyCommand({.target=*this}));
    }

    void    Widget::on_close_request(const CloseRequestCPtr&req)
    {
        if(!req)
            return ;
yInfo() << ident() << "::on_close_request(" << req->trace() << ")";
        if(m_closeRequest){
            if(req){
                send(new CloseReply({.target=req->source()}, req, Response::Busy));
            }
            return ;
        }
        
        m_closeRequest  = req;
        close(REQUEST);
    }

    void    Widget::on_set_viewer(const SetViewer&cmd)
    {
        if(cmd.target() != id())
            return ;
            
        m_viewer    = cmd.viewer();
yInfo() << "Widget::on_set_viewer() ... setting to viewer " << m_viewer.id;
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
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
        frame->foreach<Widget>(PTR, children(), [&](Widget* w){
            w->prerecord(u);
        });
    }

    //void    Widget::reject(close_k)
    //{
        //if(m_viewer)
            //m_viewer -> reject(CLOSE);
    //}

    WidgetID        Widget::root() const
    {
        const Frame*    f   = Frame::current();
        if(!f)
            return {};
        
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

#if 0
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
#endif

    void    Widget::snap(WidgetSnap& sn) const
    {
        Tachyon::snap(sn);
        sn.viewer   = m_viewer;
    }

#if 0
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
#endif

    Execution       Widget::tick(const Context&) 
    {
        //if(!m_flags(F::Startup)){
            //startup();
        //}
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
            return (ViewerID) m_viewer;
        
        const Frame*    f   = Frame::current();
        if(!f)
            return {};
        
        const WidgetSnap*   sn  = f->snap(root());
        if(!sn)
            return {};
        return (ViewerID) sn -> viewer.id;
    }

    bool        Widget::visible() const
    {
        return m_flags(F::Visible);
    }

#if 0
    Widget* Widget::widget_at(const Vector2D&) const
    {
        return const_cast<Widget*>(this);
    }
#endif
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  EVENT PROCESSING (BELOW, one "section" per event type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

