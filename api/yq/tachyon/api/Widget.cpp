////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>
#include <yq/tachyon/api/WidgetData.hpp>
#include <yq/tachyon/ui/UIElement.hpp>

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/CameraTweak.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/app/Viewer.hpp>
#include <yq/tachyon/command/ViewerCommand.hpp>
#include <yq/tachyon/command/tachyon/DestroyCommand.hpp>
#include <yq/tachyon/command/ui/CloseCommand.hpp>
#include <yq/tachyon/command/ui/HideCommand.hpp>
#include <yq/tachyon/command/ui/ShowCommand.hpp>
#include <yq/tachyon/command/ui/StartupCommand.hpp>
#include <yq/tachyon/command/ui/TitleCommand.hpp>
#include <yq/tachyon/command/widget/SetViewer.hpp>
#include <yq/tachyon/event/ui/HideEvent.hpp>
#include <yq/tachyon/event/ui/ShowEvent.hpp>
#include <yq/tachyon/event/window/FramebufferResizeEvent.hpp>
#include <yq/tachyon/request/ui/CloseRequest.hpp>
#include <yq/tachyon/reply/ui/CloseReply.hpp>
//#include <yq/tachyon/api/Layout.hpp>

#include <yq/text/format.hpp>
#include <yq/meta/Init.hpp>
#include <optional>

#include <yq/tensor/Tensor44.hxx>
#include <yq/vector/Vector4.hxx>
#include <yq/tachyon/api/Camera3.hpp>
#include <yq/tachyon/api/Camera3Data.hpp>
#include <yq/tachyon/api/Rendered3Data.hpp>
#include <yq/tachyon/api/Spatial2.hpp>
#include <yq/tachyon/api/Spatial2Data.hpp>
#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/api/Spatial3Data.hpp>
#include <yq/tachyon/vulkan/ViContext.hpp>
#include <yq/tachyon/pipeline/Pipeline.hpp>
#include <yq/tachyon/pipeline/PushData.hpp>
#include <yq/container/BasicBuffer.hpp>
#include <yq/tachyon/vulkan/ViRendered.hpp>
#include <yq/util/AutoReset.hpp>
#include <yq/tachyon/api/Rendered.hpp>
#include <yq/tachyon/vulkan/Visualizer.hpp>
#include <yq/tachyon/vulkan/Visualizer.hxx>
#include <yq/tachyon/ui/UIElements.hpp>
#include <yq/util/AutoReset.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Widget)
YQ_TYPE_IMPLEMENT(yq::tachyon::WidgetID)

namespace yq::tachyon {
    WidgetMeta::WidgetMeta(std::string_view zName, TachyonMeta& base, const std::source_location& sl) :
        TachyonMeta(zName, base, sl)
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

    void Widget::camera_matrix(PreContext&ctx, CameraID cam, std::span<const CameraTweakCPtr> tweaks)
    {
        camera_matrix(ctx.view, ctx.projection, ctx.frame, cam, tweaks);
    }

    void Widget::camera_matrix(Tensor44D& view, Tensor44D& proj, const Frame& frame, CameraID cam, std::span<const CameraTweakCPtr> tweaks)
    {
        const Camera³Snap*  camera  = dynamic_cast<const Camera³Snap*>(frame.snap(cam));
        if(camera){
            proj        = camera->projection;
            if(const Spatial³Snap* s³ = frame.snap(Spatial³ID(camera -> spatial))){
                view        = s³ -> domain2local;
            } else {
                view        = IDENTITY;
            }
        } else {
            view            = IDENTITY;
            proj            = IDENTITY;
        }
        for(auto& t : tweaks){
            if(t)
                t -> camera_tweak(view, proj);
        }
    }

    void Widget::init_meta()
    {
        auto w = writer<Widget>();
        w.description("Widget base class");
        w.slot(&Widget::on_close_request);
        w.slot(&Widget::on_close_command);
        w.slot(&Widget::on_fb_resize_event);
        w.slot(&Widget::on_title_command);
        w.slot(&Widget::on_set_viewer);
        w.slot(&Widget::on_viewer_command);
        //w.delegate("layout", &Widget::m_layout);

        auto wt = writer<WidgetID>();
        wt.description("Widget Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Widget>);
        wt.casts<TachyonID>();
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
        
        //  TODO... 

        const Spatial³Snap* s³ = ctx.frame.snap(Spatial³ID(sn.spatial));
        if(sn.vm_override){
            if(s³){
                Tensor44D   vm  = comingle(ctx.view, ctx.domain * s³->local2domain, sn.vm_tensor);
                pd.matrix   = glm::dmat4(ctx.projection * vm);
            } else {
                Tensor44D   vm  = comingle(ctx.view, ctx.domain, sn.vm_tensor);
                pd.matrix   = glm::dmat4(ctx.projection * vm);
            }
        } else {
            if(s³){
                pd.matrix   = glm::dmat4(ctx.projection * ctx.view * ctx.domain * s³->local2domain);
            } else {
                pd.matrix   = glm::dmat4(ctx.projection * ctx.view * ctx.domain);
            }
        }
    }
    
    void Widget::push_buffer_mvp(PushBuffer&pb, const PreContext&ctx, const Rendered³Snap&sn)
    {
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
            pd.model        = glm::dmat4(ctx.domain * s³->local2domain);
        } else {
            pd.model        = glm::dmat4(ctx.domain);
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

    Widget::Widget() : Widget(Param())
    {
    }
    
    Widget::Widget(const Param&p) : Tachyon(p), m_windowID(fmt_hex(UniqueID::id()))
    {
    }

    Widget::~Widget()
    {
        _kill();
    }

    void    Widget::_erase(UIElement* ui)
    {
        if(ui->binding())
            _erase_bid(ui);
        if(!ui->uid().empty())
            _erase_uid(ui);
    }

    void    Widget::_erase_bid(UIElement* ui)
    {
        if(!ui->binding())
            return ;
        auto r = m_ui.bids.equal_range(ui->binding());
        for(auto itr=r.first; itr != r.second; ++itr){
            if(itr->second == ui){
                m_ui.bids.erase(itr);
                break;
            }
        }
    }
    
    void    Widget::_erase_uid(UIElement* ui)
    {
        if(ui->uid().empty())
            return ;
        auto r = m_ui.uids.equal_range(ui->uid());
        for(auto itr=r.first; itr != r.second; ++itr){
            if(itr->second == ui){
                m_ui.uids.erase(itr);
                break;
            }
        }
    }
    
    bool    Widget::_has_bid(const UIElement*ui) const
    {
        if(!ui)
            return false;
        if(!ui->binding())
            return false;
        auto r = m_ui.bids.equal_range(ui->binding());
        for(auto itr = r.first; itr != r.second; ++itr){
            if(itr->second == ui)
                return true;
        }
        return false;
    }

    bool    Widget::_has_uid(const UIElement*ui) const
    {
        if(!ui)
            return false;
        if(ui->uid().empty())
            return false;
        auto r = m_ui.uids.equal_range(ui->uid());
        for(auto itr = r.first; itr != r.second; ++itr){
            if(itr->second == ui)
                return true;
        }
        return false;
    }
    
    void    Widget::_insert(UIElement* ui)
    {
        if(ui->binding() && !_has_bid(ui)){
            m_ui.bids.emplace( ui->binding(), ui );
        }
        if(!ui->uid().empty() && !_has_uid(ui)){
            m_ui.uids.emplace( ui->uid(), ui );
        }
    }

    void    Widget::_kill()
    {
        for(UIElement* e : m_ui.erasing){
            if(e) [[likely]]
                delete e;
        }
        m_ui.erasing.clear();
        m_ui.uids.clear();
        m_ui.bids.clear();
        for(UIElement* e : m_ui.popups){
            if(e) [[likely]]
                delete e;
        }
        m_ui.popups.clear();
        if(m_ui.root){
            delete m_ui.root;
            m_ui.root        = nullptr;
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

    UIElement*      Widget::element(first_k, uint64_t bid) const
    {
        auto itr = m_ui.bids.find(bid);
        if(itr != m_ui.bids.end())
            return itr->second;
        return nullptr;
    }

    UIElement*      Widget::element(first_k, const std::string& k) const
    {
        auto itr = m_ui.uids.find(k);
        if(itr != m_ui.uids.end())
            return itr->second;
        return nullptr;
    }

    double  Widget::height() const
    {
        if(m_flags(F::HasSize))
            return m_size.y;
        return -1.;
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
        if(m_ui.root){
            auto wid        = auto_reset(UIElement::s_widget, this);
            auto ctx        = auto_reset(UIElement::s_viContext, &u);
            m_ui.root -> draw();
            for(UIElement* ue : m_ui.popups){
                if(!ue) [[unlikely]]
                    continue;
                ue -> draw();
            }
            
            for(UIElement* ue : m_ui.erasing)
                delete ue;
            m_ui.erasing.clear();
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

    void    Widget::on_fb_resize_event(const FramebufferResizeEvent&evt)
    {
        if(evt.target() != id())
            return ;
        
        m_size      = Size2D(evt.size());
        m_flags |= F::HasSize;
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

    void    Widget::on_viewer_command(const ViewerCommand& cmd)
    {
        if(cmd.target() != id())
            return ;
        if(m_viewer){
            send(cmd.clone(REBIND, {.target=m_viewer}));
        }
    }

    uint64_t    Widget::popup(push_k, UIElement* pop)
    {
        if(!pop)
            return 0;
        m_ui.popups.push_back(pop);
        uint64_t    bid = pop->binding(CREATE);
        _insert(pop);
        return bid;
    }

    uint64_t    Widget::popup(push_k, const UIElement& pop)
    {
        return popup(PUSH, pop.clone());
    }
    
    void        Widget::popup(pop_k)
    {
        if(m_ui.popups.empty())
            return;
        UIElement*  ui  = m_ui.popups.back();
        _erase(ui);
        m_ui.erasing.push_back(ui);
        m_ui.popups.pop_back();
    }
    
    void        Widget::popup(erase_k, uint64_t id)
    {
        for(auto itr=m_ui.popups.begin(); itr != m_ui.popups.end(); ){
            if(!*itr){  [[unlikely]]    // very unlikely 
                itr = m_ui.popups.erase(itr);
                continue;
            }
            
            if((*itr)->binding() == id){
                _erase(*itr);
                m_ui.erasing.push_back(*itr);
                itr = m_ui.popups.erase(itr);
            } else {
                ++itr;
            }
        }
    }

    void        Widget::prerecord(const PreContext& ctx, RenderedID renID)
    {
        const RenderedSnap* sn  = ctx.frame.snap(renID);
        if(!sn)
            return;
        if(!sn->good)
            return;
        if(!sn->pipeline)
            return;
        
        ViRenderedPtr  rr  = ctx.vi.frame0 -> create(sn);
        if(!rr)
            return;

        #if 0
            //  useful for when troubleshooting rendering issues
        if(yFirstSeen(rr.ptr()))
            rr -> debug_report();
        #endif
            
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

    Execution       Widget::setup(const Context& ctx)
    {
        if(!m_ui.root){
            const WidgetMeta&   wi  = metaInfo();
            if(wi.m_ui){
                auto wid        = auto_reset(UIElement::s_widget, this);
                m_ui.root       = wi.m_ui->copy();
            }
        }
        if(m_ui.root){
            auto wid        = auto_reset(UIElement::s_widget, this);
            //auto ctx        = auto_reset(UIElement::s_viContext, &u);
            m_ui.root -> tick();
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
        if(m_ui.root){
            auto wid        = auto_reset(UIElement::s_widget, this);
            //auto ctx        = auto_reset(UIElement::s_viContext, &u);
            m_ui.root -> tick();
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
    
    double  Widget::width() const
    {
        if(m_flags(F::HasSize))
            return m_size.x;
        return -1.;
    }

    Widget* Widget::widget_at(const Vector2D&) const
    {
        return const_cast<Widget*>(this);   // TODO 
    }
    
    
}

