////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/ui/Widget.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>
#include <yt/ui/WidgetData.hpp>
#include <yt/ui/UIElement.hpp>

#include <yt/logging.hpp>
#include <yt/api/Frame.hpp>
#include <yt/app/Viewer.hpp>
#include <ya/commands/tachyon/DestroyCommand.hpp>
#include <ya/commands/ui/CloseCommand.hpp>
#include <ya/commands/ui/HideCommand.hpp>
#include <ya/commands/ui/ShowCommand.hpp>
#include <ya/commands/ui/StartupCommand.hpp>
#include <ya/commands/ui/TitleCommand.hpp>
#include <ya/commands/widget/SetViewer.hpp>
#include <ya/events/ui/HideEvent.hpp>
#include <ya/events/ui/ShowEvent.hpp>
#include <ya/requests/ui/CloseRequest.hpp>
#include <ya/replies/ui/CloseReply.hpp>
#include <yt/ui/Layout.hpp>

#include <yq/text/format.hpp>
#include <yq/meta/Init.hpp>
#include <optional>

#include <yq/tensor/Tensor44.hxx>
#include <yq/vector/Vector4.hxx>
#include <yt/3D/Camera3.hpp>
#include <yt/3D/Camera3Data.hpp>
#include <yt/3D/Rendered3Data.hpp>
#include <yt/3D/Spatial3.hpp>
#include <yt/3D/Spatial3Data.hpp>
#include <yv/ViContext.hpp>
#include <yt/gfx/Pipeline.hpp>
#include <yt/gfx/PushData.hpp>
#include <yq/container/BasicBuffer.hpp>
#include <yv/ViRendered.hpp>
#include <yq/util/AutoReset.hpp>
#include <yt/scene/Rendered.hpp>
#include <yv/Visualizer.hpp>
#include <yv/Visualizer.hxx>
#include <ya/uis/UIItems.hpp>
#include <yq/util/AutoReset.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Widget)
YQ_TYPE_IMPLEMENT(yq::tachyon::WidgetID)

namespace yq::tachyon {
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
    
    struct Widget::R {
        ViRenderedPtr   vi;
        PushBuffer      push;
    };

    /////////////////////////

    void Widget::camera_matrix(PreContext&ctx, Camera³ID cam)
    {
        camera_matrix(ctx.view, ctx.projection, ctx.frame, cam);
    }

    void Widget::camera_matrix(Tensor44D& view, Tensor44D& proj, const Frame& frame, Camera³ID cam)
    {
        const Camera³Snap*  camera  = frame.snap(cam);
        if(!camera){
            view            = IDENTITY;
            proj            = IDENTITY;
            return;
        }
        
        proj        = camera->projection;
        const Spatial³Snap* s³ = frame.snap(Spatial³ID(camera -> spatial));
        if(s³){
            view      = s³ -> domain2local;
        } else {
            view      = IDENTITY;
        }
    }

    void Widget::init_info()
    {
        auto w = writer<Widget>();
        w.description("Widget base class");
        w.slot(&Widget::on_close_request);
        w.slot(&Widget::on_close_command);
        w.slot(&Widget::on_title_command);
        w.slot(&Widget::on_set_viewer);
        //w.delegate("layout", &Widget::m_layout);

        auto wt = writer<WidgetID>();
        wt.description("Widget Identifier");
        wt.set(Meta::Flag::ID);
    }

    void Widget::push_buffer(PushBuffer&pb, const PreContext&ctx, const RenderedSnap&sn)
    {
        if(!sn.pipeline)
            return ;
            
        switch(sn.pipeline->push().type){
        case PushConfigType::Full:
            if(sn.self(Type::Rendered³)){
                push_buffer_full(pb, ctx, static_cast<const Rendered³Snap&>(sn));
            } else {
                push_buffer_view(pb, ctx, sn);
            }
            break;
        case PushConfigType::MVP:
            if(sn.self(Type::Rendered³)){
                push_buffer_mvp(pb, ctx, static_cast<const Rendered³Snap&>(sn));
            }
            break;
        case PushConfigType::View:
            push_buffer_view(pb, ctx, sn);
            break;
        case PushConfigType::ViewProj:
            push_buffer_viewproj(pb, ctx, sn);
            break;
        case PushConfigType::View64Proj:
            push_buffer_view64proj(pb, ctx, sn);
            break;
        case PushConfigType::Custom:
            pb  = sn.push;
            break;
        case PushConfigType::None:
        default:
            break;
        }
    }

    void Widget::push_buffer_full(PushBuffer&pb, const PreContext&ctx, const Rendered³Snap& sn)
    {
        StdPushData&    pd  = *pb.create_single<StdPushData>();
        pd.time         = ctx.time;
        pd.gamma        = ctx.gamma;

        const Spatial³Snap* s³ = ctx.frame.snap(Spatial³ID(sn.spatial));
        if(sn.vm_override){
            if(s³){
                Tensor44D   vm  = comingle(ctx.view, s³->local2domain, sn.vm_tensor);
                pd.matrix   = glm::dmat4(ctx.projection * vm);
            } else {
                Tensor44D   vm  = comingle(ctx.view, Tensor44D(IDENTITY), sn.vm_tensor);
                pd.matrix   = glm::dmat4(ctx.projection * vm);
            }
        } else {
            if(s³){
                pd.matrix   = glm::dmat4(ctx.projection * ctx.view * s³->local2domain);
            } else {
                pd.matrix   = glm::dmat4(ctx.projection * ctx.view);
            }
        }
    }
    
    void Widget::push_buffer_mvp(PushBuffer&pb, const PreContext&ctx, const Rendered³Snap&sn)
    {
        static constexpr glm::mat4  I44 = glm::dmat4(Tensor44D(IDENTITY));
        StdPushDataMVP&    pd  = *pb.create_single<StdPushDataMVP>();
        pd.time         = ctx.time;
        pd.gamma        = ctx.gamma;
        
        if(sn.camera){  
            Tensor44D   V, P;
            camera_matrix(V, P, ctx.frame, sn.camera);
            pd.view         = glm::dmat4(V);
            pd.projection   = glm::dmat4(P);
        } else {
            pd.view         = glm::dmat4(ctx.view);
            pd.projection   = glm::dmat4(ctx.projection);
        }
        
        //  gamma/colors/etc
        
        const Spatial³Snap* s³ = ctx.frame.snap(Spatial³ID(sn.spatial));
        if(s³){
            pd.model        = glm::dmat4(s³->local2domain);
        } else {
            pd.model        = I44;
        }
    }
    
    void Widget::push_buffer_view(PushBuffer&pb, const PreContext&ctx, const RenderedSnap&)
    {
        StdPushData&    pd  = *pb.create_single<StdPushData>();
        pd.time         = ctx.time;
        pd.gamma        = ctx.gamma;
        pd.matrix       = glm::dmat4(ctx.projection*ctx.view);
    }
    
    void Widget::push_buffer_viewproj(PushBuffer&pb, const PreContext&ctx, const RenderedSnap&sn)
    {
        StdPushDataViewProj&    pd  = *pb.create_single<StdPushDataViewProj>();
        pd.time         = ctx.time;
        pd.gamma        = ctx.gamma;
        if(sn.self(Type::Rendered³) && static_cast<const Rendered³Snap&>(sn).camera){
            Tensor44D   V, P;
            camera_matrix(V, P, ctx.frame, static_cast<const Rendered³Snap&>(sn).camera);
            pd.view         = glm::dmat4(V);
            pd.projection   = glm::dmat4(P);
        } else {
            pd.view         = glm::dmat4(ctx.view);
            pd.projection   = glm::dmat4(ctx.projection);
        }
    }
    
    void Widget::push_buffer_view64proj(PushBuffer&pb, const PreContext&ctx, const RenderedSnap&sn)
    {
        StdPushDataView64Proj&    pd  = *pb.create_single<StdPushDataView64Proj>();
        pd.time         = ctx.time;
        pd.gamma        = ctx.gamma;
        if(sn.self(Type::Rendered³) && static_cast<const Rendered³Snap&>(sn).camera){
            Tensor44D   V, P;
            camera_matrix(V, P, ctx.frame, static_cast<const Rendered³Snap&>(sn).camera);
            pd.view         = glm::dmat4(V);
            pd.projection   = glm::dmat4(P);
        } else {
            pd.view         = glm::dmat4(ctx.view);
            pd.projection   = glm::dmat4(ctx.projection);
        }
    }

    /////////////////////////

    Widget::Widget() : Tachyon(), m_windowID(fmt_hex(UniqueID::id()))
    {
    }
    
    Widget::~Widget()
    {
        if(m_ui){
            delete m_ui;
            m_ui        = nullptr;
        }
    }

    PostAdvice    Widget::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        return {};
    }

    bool    Widget::attached() const
    {
        return parent() || m_viewer;
    }

    void    Widget::close(accept_k)
    {
        send(new CloseReply({.cause=m_closeRequest, .target=m_viewer}, m_closeRequest, Response::QaPla));
        mail(new CloseCommand({.cause=m_closeRequest, .target=*this}));
        m_closeRequest = {};
    }
    
    void    Widget::close(reject_k)
    {
        send(new CloseReply({.cause=m_closeRequest, .target=m_viewer}, m_closeRequest, Response::Rejected));
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
        imgui(CHILDREN, u);
    }

    //! Calls the imgui on all children
    void    Widget::imgui(children_k, ViContext&u)
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

    
    //! Calls the render on all UIElement elements
    void    Widget::imgui(ui_k, ViContext&u)
    {
        if(m_ui){
            auto wid        = auto_reset(UIElement::s_widget, this);
            auto ctx        = auto_reset(UIElement::s_context, &u);
            m_ui -> draw();
        }
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

    void    Widget::on_title_command(const TitleCommand& cmd)
    {
        if(cmd.target() != id())
            return ;
        if(m_viewer){
            send(cmd.clone(REBIND, {.target=m_viewer}));
        }
    }

    void        Widget::prerecord(const PreContext& ctx, RenderedID renID)
    {
        const RenderedSnap* sn  = ctx.frame.snap(renID);
        if(!sn)
            return;
        
        if(!sn->pipeline)
            return;
        
        ViRenderedPtr  rr  = ctx.vi.frame0 -> create(sn);
        if(!rr)
            return;
            
        R&  r  = m_rendereds.emplace_back();
        r.vi    = rr;
        push_buffer(r.push, ctx, *sn);
        rr->update(ctx.vi, *sn);
        rr->descriptors();
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

    void    Widget::set_layout(LayoutPtr lay)
    {
        LayoutPtr   old = lay;
        {
            lock_t  _lock(m_mutex, true);
            std::swap(m_layout, lay);
        }
    }

    Execution       Widget::setup(const Context& ctx)
    {
        if(!m_ui){
            const WidgetInfo&   wi  = metaInfo();
            if(wi.m_ui){
                auto wid        = auto_reset(UIElement::s_widget, this);
                m_ui            = wi.m_ui->clone();
            }
        }
        return Tachyon::setup(ctx);
    }

    void    Widget::snap(WidgetSnap& sn) const
    {
        Tachyon::snap(sn);
        sn.viewer   = m_viewer;
    }

    Execution  Widget::tick(const Context&ctx)
    {
        LayoutPtr   lay;
        {
            lock_t _lock(m_mutex, false);
            lay = m_layout;
        }
        if(lay){
            lay -> tick(*this, ctx);
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
            return ViewerID{ m_viewer.id };
        
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

    void    Widget::vulkan(ViContext&u)
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return ;
        
        //  TODO set viewport (later...)
        
        auto w  = auto_reset(u.wireframe, m_wireframe);
        for(const R& r : m_rendereds){
            r.vi->record(u, r.push);
        }
        m_rendereds.clear();
            
        frame->foreach<Widget>(PTR, children(), [&](Widget* w){
            if(w->visible()){
                w->vulkan(u);
            }
        });
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

