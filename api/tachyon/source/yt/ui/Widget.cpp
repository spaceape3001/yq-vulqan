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
#include <ya/commands/ui/ShowCommand.hpp>
#include <ya/commands/ui/StartupCommand.hpp>

#include <yq/text/format.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Widget)

namespace yq::tachyon {
    WidgetBind::WidgetBind(const Widget* v) : m_widget(v ? v->id() : WidgetID{}) 
    {
    }

    void Widget::init_info()
    {
        auto w = writer<Widget>();
        w.description("Widget base class");
        w.slot(&Widget::on_startup_command);
    }

    WidgetInfo::WidgetInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
        set(Flag::WIDGET);
        set(Type::Widget);
    }

    Widget::Widget(const Param& p) : Tachyon(p)
    {
        m_windowID      = std::string(fmt_hex(id()));
    }
    
    Widget::~Widget()
    {
        //for(Widget* w : m_children)
            //delete w;
        m_children.clear();
    }

    void    Widget::close(accept_k)
    {
        PostID  pId;
        if(m_closeRequest)
            pId = m_closeRequest -> id();
        send(new CloseReply({.cause=pId, .target=m_viewer}, m_closeRequest, Response::QaPla));
        send(new CloseCommand({.cause=pId, .target=m_viewer}));
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
        return m_parent || m_viewer;
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

    void    Widget::on_startup_command(const StartupCommand&cmd)
    {
        if(cmd.target() == id()){
            startup();
        }
    }
    
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

    Widget*         Widget::root(ptr_k)
    {
        Widget* w   = this;
        while(w->m_parent)
            w   = w->m_parent;
        return w;
    }
    
    const Widget*   Widget::root(ptr_k) const
    {
        return const_cast<Widget*>(this) -> root();
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
        if(m_parent){
            m_flags |= F::Startup;
        }
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

    Viewer*         Widget::viewer()
    {
        Widget* w   = root();
        if(w)
            return w->m_viewer;
        return nullptr;
    }
    
    const Viewer*   Widget::viewer() const 
    {
        return const_cast<Widget*>(this)->viewer();
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

