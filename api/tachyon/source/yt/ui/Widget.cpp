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
#include <ya/events/ui/HideEvent.hpp>
#include <ya/events/ui/ShowEvent.hpp>
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

    void    Widget::cmd_hide()
    {
        mail(new HideCommand({.target=*this}));
    }

    void    Widget::cmd_show()
    {
        mail(new ShowCommand({.target=*this}));
    }

    void    Widget::imgui(ViContext& u)
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
            
        frame->foreach<Widget>(PTR, children(), [&](Widget* w){
            if(w->visible()){
                w->imgui(u);
            }
        });
    }
    
    void    Widget::vulkan(ViContext&u)
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
        frame->foreach<Widget>(PTR, children(), [&](Widget* w){
            if(w->visible()){
                w->vulkan(u);
            }
        });
    }
    
    const char*     Widget::imgui_id() const
    {
        return m_windowID.c_str();
    }


    bool    Widget::is_imgui() const
    {
        return metaInfo().is_imgui();
    }

    void    Widget::on_close_command(const CloseCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(m_viewer){
            send(new HideCommand({.source=*this, .target=m_viewer}), MG::Viewer);
        }
        mail(new HideCommand({.source=*this, .target=*this}));
        for(TypedID t : children()){
            send(new CloseCommand({.source=*this, .target=t}), {});
        }
        
        teardown();
    }

    void    Widget::on_close_request(const CloseRequestCPtr&req)
    {
        if(!req)
            return ;
        if(m_closeRequest){
            if(req){
                send(new CloseReply({.target=req->source()}, req, Response::Busy));
            }
            return ;
        }
        
        m_closeRequest  = req;
        close(REQUEST);
    }

    void    Widget::on_hide_command(const HideCommand& cmd)
    {
        if(cmd.target() != id())
            return;
        if(m_flags(F::Visible)){
            m_flags -= F::Visible;
            send(new HideEvent({.source=*this}));
        }
    }

    void    Widget::on_set_viewer(const SetViewer&cmd)
    {
        if(cmd.target() != id())
            return ;
            
        m_viewer    = cmd.viewer();
    }

    void    Widget::on_show_command(const ShowCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(!m_flags(F::Visible)){
            m_flags |= F::Visible;
            send(new ShowEvent({.source=*this}));
        }
    }

    void            Widget::prerecord(ViContext& u)
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
        frame->foreach<Widget>(PTR, children(), [&](Widget* w){
            if(w->visible())
                w->prerecord(u);
        });
    }

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

    void    Widget::snap(WidgetSnap& sn) const
    {
        Tachyon::snap(sn);
        sn.viewer   = m_viewer;
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

    Widget* Widget::widget_at(const Vector2D&) const
    {
        return const_cast<Widget*>(this);   // TODO 
    }
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  EVENT PROCESSING (BELOW, one "section" per event type
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

