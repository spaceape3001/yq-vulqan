////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/app/Viewer.hpp>

#include <log4cpp/CategoryStream.hh>
#include <tachyon/logging.hpp>

#include <tachyon/app/Application.hpp>
#include <tachyon/api/Context.hpp>
#include <tachyon/api/Frame.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/api/Thread.hpp>
#include <tachyon/app/ViewerData.hpp>
#include <tachyon/app/ViewerException.hpp>
#include <tachyon/gfx/Raster.hpp>
#include <tachyon/os/GraphicsCard.hpp>
#include <tachyon/os/Window.hpp>
#include <tachyon/os/WindowData.hpp>
#include <tachyon/api/Widget.hpp>
#include <tachyon/api/WidgetData.hpp>

#include <tachyon/command/SpatialCommand.hpp>

#include <tachyon/command/cursor/CursorCaptureCommand.hpp>
#include <tachyon/command/cursor/CursorDisableCommand.hpp>
#include <tachyon/command/cursor/CursorHideCommand.hpp>
#include <tachyon/command/cursor/CursorNormalCommand.hpp>

#include <tachyon/command/sim/PauseCommand.hpp>
#include <tachyon/command/sim/ResumeCommand.hpp>

#include <tachyon/command/position/SetPosition2.hpp>
#include <tachyon/command/size/SetSize2.hpp>

#include <tachyon/command/ui/AspectCommand.hpp>
#include <tachyon/command/ui/AttentionCommand.hpp>
#include <tachyon/command/ui/CloseCommand.hpp>
#include <tachyon/command/ui/FloatCommand.hpp>
#include <tachyon/command/ui/FocusCommand.hpp>
#include <tachyon/command/ui/HideCommand.hpp>
#include <tachyon/command/ui/IconifyCommand.hpp>
#include <tachyon/command/ui/MaximizeCommand.hpp>
#include <tachyon/command/ui/RestoreCommand.hpp>
#include <tachyon/command/ui/ShowCommand.hpp>
#include <tachyon/command/ui/StartupCommand.hpp>
#include <tachyon/command/ui/TitleCommand.hpp>
#include <tachyon/command/ui/UnfloatCommand.hpp>

#include <tachyon/command/tachyon/DestroyCommand.hpp>
#include <tachyon/command/tachyon/RethreadCommand.hpp>
#include <tachyon/command/tachyon/SubscribeCommand.hpp>
#include <tachyon/command/tachyon/UnsubscribeCommand.hpp>

#include <tachyon/command/widget/SetViewer.hpp>

#include <tachyon/event/keyboard/KeyCharacterEvent.hpp>
#include <tachyon/event/keyboard/KeyPressEvent.hpp>
#include <tachyon/event/keyboard/KeyReleaseEvent.hpp>

#include <tachyon/event/mouse/MouseMoveEvent.hpp>
#include <tachyon/event/mouse/MousePressEvent.hpp>
#include <tachyon/event/mouse/MouseReleaseEvent.hpp>
#include <tachyon/event/mouse/MouseMoveEvent.hpp>
#include <tachyon/event/mouse/MousePressEvent.hpp>
#include <tachyon/event/mouse/MouseReleaseEvent.hpp>

#include <tachyon/event/spatial/Position2Event.hpp>
#include <tachyon/event/spatial/Size2Event.hpp>

#include <tachyon/event/sim/PauseEvent.hpp>
#include <tachyon/event/sim/ResumeEvent.hpp>

#include <tachyon/event/tachyon/DestroyEvent.hpp>

#include <tachyon/event/ui/CloseEvent.hpp>
#include <tachyon/event/ui/DefocusEvent.hpp>
#include <tachyon/event/ui/FocusEvent.hpp>
#include <tachyon/event/ui/HideEvent.hpp>
#include <tachyon/event/ui/ShowEvent.hpp>

#include <tachyon/event/window/FramebufferResizeEvent.hpp>

#include <tachyon/os/glfw/WindowGLFW.hpp>

#include <tachyon/reply/graphics_card/GetDeviceReply.hpp>
#include <tachyon/reply/ui/CloseReply.hpp>

#include <tachyon/request/graphics_card/GetDeviceRequest.hpp>
#include <tachyon/request/ui/RefreshRequest.hpp>
#include <tachyon/request/ui/CloseRequest.hpp>

#include <tachyon/vulkan/ViContext.hpp>
#include <tachyon/vulkan/ViDevice.hpp>
#include <tachyon/vulkan/ViGui.hpp>
#include <tachyon/vulkan/Visualizer.hpp>
#include <tachyon/vulkan/VisualizerCreateData.hpp>

//#include <tachyon/reply/ViewerWidgetReply.hpp>
//#include <tachyon/request/ViewerWidgetRequest.hpp>

//#include <tachyon/api/TachyonInfoWriter.hpp>

#include <yq/errors.hpp>
#include <yq/core/ErrorDB.hpp>
#include <yq/core/ThreadId.hpp>
#include <yq/shape/Size2.hxx>
#include <yq/text/format.hpp>
#include <yq/util/AutoReset.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/meta/Init.hpp>

#define viewerAlert                 yAlert("viewer")
#define viewerCritical              yCritical("viewer")
#define viewerDebug                 yDebug("viewer")
#define viewerError                 yError("viewer")
#define viewerEmergency             yEmergency("viewer")
#define viewerFatal                 yFatal("viewer")
#define viewerInfo                  yInfo("viewer")
#define viewerNotice                yNotice("viewer")
#define viewerWarning               yWarning("viewer")

YQ_TACHYON_IMPLEMENT(yq::tachyon::Viewer)
YQ_TYPE_IMPLEMENT(yq::tachyon::ViewerID)

namespace yq::tachyon {

    std::atomic<int>        Viewer::s_count{0};
    std::atomic<unsigned>   Viewer::s_lastNumber{0};


    void Viewer::init_info()
    {
        auto w = writer<Viewer>();
        
        w.description("Tachyon Viewer");
        w.property("ticks", &Viewer::ticks).description("Total number of ticks so far");
        w.type(Type::Viewer);

        w.slot(&Viewer::on_aspect_command);
        w.slot(&Viewer::on_attention_command);
        w.slot(&Viewer::on_close_command);
        w.slot(&Viewer::on_close_request);
        w.slot(&Viewer::on_close_reply);
        w.slot(&Viewer::on_cursor_command);
        w.slot(&Viewer::on_defocus_event);
        w.slot(&Viewer::on_destroy_event);
        w.slot(&Viewer::on_fb_resize_event);
        w.slot(&Viewer::on_float_command);
        w.slot(&Viewer::on_focus_command);
        w.slot(&Viewer::on_focus_event);
        w.slot(&Viewer::on_get_device_reply);
        w.slot(&Viewer::on_hide_command);
        w.slot(&Viewer::on_hide_event);
        w.slot(&Viewer::on_iconify_command);
        
        w.slot(&Viewer::on_key_character_event);
        w.slot(&Viewer::on_key_press_event);
        w.slot(&Viewer::on_key_release_event);
        
        w.slot(&Viewer::on_maximize_command);
        w.slot(&Viewer::on_mouse_move_event);
        w.slot(&Viewer::on_mouse_press_event);
        w.slot(&Viewer::on_mouse_release_event);
        
        w.slot(&Viewer::on_move_event);
        //w.slot(&Viewer::on_pause_command);
        w.slot(&Viewer::on_restore_command);
        //w.slot(&Viewer::on_resume_command);
        w.slot(&Viewer::on_size_event);
        w.slot(&Viewer::on_show_command);
        //w.slot(&Viewer::on_show_event);
        w.slot(&Viewer::on_title_command);
        w.slot(&Viewer::on_unfloat_command);

        auto wt = writer<ViewerID>();
        wt.description("Viewer Identifier");
        wt.set(Meta::Flag::ID);
        
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Viewer::Viewer(Window* win, Widget* w, const ViewerCreateInfo& vci) : 
        m_createInfo(vci), m_number(++s_lastNumber)
    {
        assert(win && w);
        
            // THIS WILL EVENTUALLY MERGE INTO SETUP....???
        
        
        m_window                = win;
        m_widget                = *w;
        w->m_viewer             = *this;
        subscribe(m_widget, {MG::Widget, MG::General});
        w->subscribe(id(), {MG::Viewer, MG::General});
        
        m_widgetPtr     = w;
        _widget(w);
        
        ++s_count;
        tachyonInfo << "Viewer::Viewer(" << m_number << ") ID " << (uint64_t) id() << ", window=" 
            << (uint64_t) m_window.id << ", widget=" << m_widget.id;
    }
    
    Viewer::~Viewer()
    {
        --s_count;
        _widget({});
        _sweepwait();
        if(m_imgui)
            m_imgui = {};
        _sweepwait();
        if(m_viz)
            m_viz   = {};
        m_cleanup.sweep();
    }

    void    Viewer::_sweepwait()
    {
        if(m_viz)
            m_viz -> wait_idle();
        m_cleanup.sweep();
    }


    void    Viewer::_widget(TypedID w)
    {
        if(w == m_widget)
            return ;
            
        if(m_widget){
            send(new SetViewer({.source=*this, .target=m_widget}, {}));
            send(new UnsubscribeCommand({.source=*this, .target=m_widget}, *this));
            unsubscribe(m_widget, {MG::Widget, MG::General});
        }
        m_widget    = w;
        if(m_widget){
            send(new SetViewer({.source=*this, .target=m_widget}, *this));
            send(new SubscribeCommand({.source=*this, .target=m_widget}, *this, {MG::Viewer, MG::General}));
            subscribe(m_widget, {MG::Widget, MG::General});
        }
    }

    PostAdvice  Viewer::advise(const Post& pp) const 
    {
        const TypedID&   src = pp.source();
        if(src(Type::Window) && src.id != m_window.id)
            return REJECT;
            
        const TypedID&   tgt = pp.target();
        if(tgt(Type::Viewer) && tgt.id != id().id)
            return REJECT;

        if(dynamic_cast<const InputEvent*>(&pp))
            return MG::Widget;
        
        #ifdef __GNUC__
            /*
                The return below falsely triggers an "maybe-uninitialized" warning.
            */
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wmaybe-uninitialized"   
        #endif

        return {};

        #ifdef __GNUC__
        #pragma GCC diagnostic pop
        #endif

    }

    const Size2I&   Viewer::aspect() const
    {
        return m_state.window.aspect;
    }


    void    Viewer::cmd_attention()
    {
        send(new AttentionCommand({.source=this, .target=m_window}));
    }

    void    Viewer::cmd_close(bool force)
    {
        if(force){
            mail(new CloseCommand({.source=this, .target=this}));
        } else {
            mail(new CloseRequest({.source=this, .target=this}));
        }
    }

    void    Viewer::cmd_cursor_capture()
    {
        mail(new CursorCaptureCommand({.source=this, .target=this}));
    }
    
    void    Viewer::cmd_cursor_disable()
    {
        mail(new CursorDisableCommand({.source=this, .target=this}));
    }
    
    void    Viewer::cmd_cursor_hide()
    {
        mail(new CursorHideCommand({.source=this, .target=this}));
    }
    
    void    Viewer::cmd_cursor_normal()
    {
        mail(new CursorNormalCommand({.source=this, .target=this}));
    }

    void    Viewer::cmd_float()
    {
        send(new FloatCommand({.source=this, .target=m_window}));
    }

    void    Viewer::cmd_focus()
    {
        send(new FocusCommand({.source=this, .target=m_window}));
    }

    void    Viewer::cmd_hide()
    {
        send(new HideCommand({.source=this, .target=m_window}));
    }

    void    Viewer::cmd_iconify()
    {
        send(new IconifyCommand({.source=this, .target=m_window}));
    }

    void    Viewer::cmd_maximize()
    {
        send(new MaximizeCommand({.source=this, .target=m_window}));
    }

    void    Viewer::cmd_pause()
    {
        mail(new PauseCommand({.source=this, .target=this}));
    }
    
    void    Viewer::cmd_restore()
    {
        send(new RestoreCommand({.source=this, .target=m_window}));
    }

    void    Viewer::cmd_resume()
    {
        mail(new ResumeCommand({.source=this, .target=this}));
    }

    void    Viewer::cmd_show()
    {
        send(new ShowCommand({.source=this, .target=m_window}));
    }

    void    Viewer::cmd_unfloat()
    {
        send(new UnfloatCommand({.source=this, .target=m_window}));
    }

    std::error_code     Viewer::draw()
    {
        ViContext   u;
        u.viewport  = { 
            .x          = 0.f, .y=0.f,
            .width      = (float) m_state.window.pixels.x,
            .height     = (float) m_state.window.pixels.y,
            .minDepth   = 0.,
            .maxDepth   = 1.
        };
        
        //  ENABLE to get the validation issue
        //  u.snapshot  = DataFormat(DataFormat::R8G8B8A8_SRGB);
        return draw(u);
    }

    std::error_code     Viewer::draw(ViContext& u)
    {
        if(paused() || m_zeroSize)
            return std::error_code();
            
        const Frame*    frame   = Frame::current();
        if(!frame)
            return std::error_code();
        Widget*w        = frame->object((WidgetID) m_widget);
        if(!w)
            return std::error_code();
        
        std::filesystem::path   snapshot;
        if(auto p = std::get_if<std::filesystem::path>(&u.snapshot)){
            snapshot    = *p;
            u.snapshot  = DataFormat(DataFormat::R8G8B8A8_SRGB);
        }
        
        auto start = std::chrono::high_resolution_clock::now();
        auto r1 = auto_reset(u.tick, m_viz->tick());
        auto r2 = auto_reset(u.viewer, this);
        //auto r3 = auto_reset(u.window, static_cast<Window*>(this));
        if(w && m_imgui){
            w -> m_size = { u.viewport.width, u.viewport.height };
            w -> m_flags |= Widget::F::HasSize;
            m_imgui -> draw(u, w);
        }
        std::error_code ec = m_viz->draw(u, {
            .prerecord = [&](ViContext& u){
                if(w){
                    w -> prerecord(u);
                }
                if(m_imgui){
                    m_imgui -> update();
                }
            },
            .record = [&](ViContext& u){
                if(u.command_buffer){
                    vkCmdSetViewport(u.command_buffer, 0, 1, &u.viewport);
                }
                if(w)
                    w -> vulkan(u);
                if(m_imgui)
                    m_imgui -> record(u);
            }
        });

        auto end   = std::chrono::high_resolution_clock::now();
        m_drawTime          = (end-start).count();
        if(ec != std::error_code())
            viewerCritical << "Viewer" << ident() << "::draw() failed ... " << ec.message();
            
        if(!snapshot.empty()){
            if(auto p = std::get_if<RasterPtr>(&u.snapshot)){
                RasterPtr   img  = *p;
                if(img){
                    img -> save_to(snapshot);
                }
            }
            if(auto p = std::get_if<std::error_code>(&u.snapshot)){
                viewerError << "Viewer" << ident() << "::draw() snapshot failed ... " << p->message();
            }
        }

        return ec;
    }

    const Size2I&   Viewer::framebuffer_size() const
    {
        return m_state.window.pixels;
    }

    int         Viewer::height() const
    {
        return m_state.window.area.y;
    }

    bool        Viewer::is_decorated() const
    {
        return m_state.window.flags(WindowFlag::Decorated);
    }
    
    bool        Viewer::is_focused() const
    {
        return m_state.window.flags(WindowFlag::Focused);
    }
    
    bool        Viewer::is_floating() const
    {
        return m_state.window.flags(WindowFlag::Floating);
    }
    
    bool        Viewer::is_fullscreen() const
    {
        return m_state.window.monitor;
    }
    
    bool        Viewer::is_hovered() const
    {
        return m_state.window.flags(WindowFlag::Hovered);
    }
    
    bool        Viewer::is_iconified() const
    {
        return m_state.window.flags(WindowFlag::Iconified);
    }

    bool        Viewer::is_maximized() const
    {
        return m_state.window.flags(WindowFlag::Maximized);
    }
    
    bool        Viewer::is_resizable() const
    {
        return m_state.window.flags(WindowFlag::Resizable);
    }
    
    bool        Viewer::is_visible() const
    {
        return m_state.window.flags(WindowFlag::Visible);
    }
    
    void    Viewer::on_aspect_command(const AspectCommand& cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }

    void    Viewer::on_attention_command(const AttentionCommand& cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }

    void    Viewer::on_close_command(const CloseCommand& cmd)
    {
        if(!dying() && (cmd.target() == id()))
            teardown();
    }

    void    Viewer::on_close_reply(const CloseReply&rep)
    {
        if(rep.source() != m_widget)
            return ;

            
        if(m_closeRequest){
            send(new CloseReply({.source=rep.source(), .target=m_closeRequest->source()}, m_closeRequest, rep.response()));
            m_closeRequest = {};
        }
    }

    void    Viewer::on_close_request(const CloseRequestCPtr&req) 
    { 
        if(!req)
            return ;

        if((req->target() != id()) && (req->source() != m_window))
            return;


        if(dying()){
            send(new CloseReply({.source=this, .target=req->source()}, req, Response::Busy));
            return ;
        }

        if(m_closeRequest){
            if(m_closeRequest->id() != req->id()){
                send(new CloseReply({.source=this, .target=req->source()}, req, Response::Busy));
            }
            return ;
        }
        
        m_closeRequest  = req.ptr();
        send(req->clone(REBIND, {.target=m_widget}));
    }
    
    void    Viewer::on_cursor_command(const CursorCommand&cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }

    void    Viewer::on_defocus_event(const DefocusEvent&evt)
    {
        if(m_imgui){
            m_imgui->on(evt);
        }
    }

    void    Viewer::on_destroy_event(const DestroyEvent&evt)
    {
        if(evt.source() == m_widget){
            // we're dead...
            teardown();
        }
        if(evt.source() == m_window){
            // that's dead too...
            send(new DestroyCommand({.source=evt.source(), .target=m_widget}));
            teardown();
        }
    }

    void    Viewer::on_fb_resize_event(const FramebufferResizeEvent&evt)
    {
        if(evt.source() != m_window)
            return;
        if(!dying()){
            //send(evt.clone(REBIND, {.target=m_widget}));
        }
    }
    
    void    Viewer::on_float_command(const FloatCommand& cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }

    void    Viewer::on_focus_command(const FocusCommand&cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }
    
    void    Viewer::on_focus_event(const FocusEvent& evt)
    {
        if(m_imgui && (evt.source() == m_window)){
            m_imgui->on(evt);
        }
    }

    void    Viewer::on_get_device_reply(const GetDeviceReply& rep)
    {
    
        if(rep.target() != id())
            return;
            
        //if(m_viz)
            //return ;

        const Frame*    frame   = Frame::current();
        if(!frame){
            viewerCritical << "Viewer: Unable to get current frame, aborting the viewer";
            m_flags |= X::Failure;
            return ;
        }
        
        const WindowSnap*   ws  = frame->snap((WindowID) m_window);
        if(!ws){
            viewerCritical << "Viewer: Unable to get window snap, aborting the viewer";
            m_flags |= X::Failure;
            return ;
        }
        
        const Window* win   = frame->object((WindowID) m_window);
        if(!win){
            viewerCritical << "Viewer: Unable to get window, aborting the viewer";
            m_flags |= X::Failure;
            return ;
        }
        
        const Widget* wid   = frame->object((WidgetID) m_widget);
        if(!wid){
            viewerCritical << "Viewer: Unable to get widget, aborting the viewer";
            m_flags |= X::Failure;
            return ;
        }

        Visualizer::CreateData      vcd{ m_createInfo };
        vcd.device      = rep.device();
        
        if(!vcd.device || !vcd.device->valid()){
            viewerCritical << "Viewer: Unable to get a valid device, aborting the viewer";
            m_flags |= X::Failure;
            return;
        }
        
        vcd.surface     = win -> create_surface();
        if(!vcd.surface || !vcd.surface->valid()){
            viewerCritical << "Viewer: Unable to get a valid surface, aborting the viewer";
            m_flags |= X::Failure;
            return;
        }
        
        vcd.pixels      = ws -> window.pixels;
        vcd.number      = (uint32_t) m_number;

        try {
            m_viz       = std::make_unique<Visualizer>(vcd);
        } 
        catch(const std::exception& ex)
        {
            viewerCritical << "Viewer: unable to create visualizer: " << ex.what();
            m_flags |= X::Failure;
        }
        catch(const std::error_code& ec)
        {
            viewerCritical << "Viewer: unable to create visualizer: " << ec.message();
            m_flags |= X::Failure;
        }
        
        if(!m_viz)
            return ;

        if(m_createInfo.imgui || wid->is_imgui()){
            try {
                m_imgui = std::make_unique<ViGui>(*m_viz);
            }
            catch(const std::exception& ex){
                m_flags |= X::Failure;
                viewerCritical << "Viewer: cannot create imgui: " << ex.what();
            }
            catch(const std::error_code& ec){
                m_flags |= X::Failure;
                viewerCritical << "Viewer: cannot create imgui: " << ec.message();
            }
        }

        m_flags |= X::DevReply;   
    }
    
    void    Viewer::on_hide_command(const HideCommand& cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }

    void    Viewer::on_hide_event(const HideEvent& evt)
    {
        if(dying() && (evt.source() == m_window)){
            m_flags     |= X::HideEvent;
        }
    }
    
    void    Viewer::on_iconify_command(const IconifyCommand& cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }
    
    void    Viewer::on_key_character_event(const KeyCharacterEvent&evt)
    {
        if(m_imgui){
            m_imgui->on(evt);
        }
    }

    void    Viewer::on_key_press_event(const KeyPressEvent&evt)
    {
        if(m_imgui){
            m_imgui->on(evt);
        }
    }
    
    void    Viewer::on_key_release_event(const KeyReleaseEvent&evt)
    {
        if(m_imgui){
            m_imgui->on(evt);
        }
    }

    void    Viewer::on_maximize_command(const MaximizeCommand& cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }
    
    void    Viewer::on_mouse_move_event(const MouseMoveEvent&evt)
    {
        if(m_imgui){
            m_imgui->on(evt);
        }
    }

    void    Viewer::on_mouse_press_event(const MousePressEvent&evt)
    {
        if(m_imgui){
            m_imgui->on(evt);
        }
    }
    
    void    Viewer::on_mouse_release_event(const MouseReleaseEvent&evt)
    {
        if(m_imgui){
            m_imgui->on(evt);
        }
    }

    void    Viewer::on_move_event(const Position²Event&evt)
    {
        if(evt.source() == m_window){
            // yInfo() << "Viewer moved (" << evt.x() << ", " << evt.y() << ")";
            // TODO (might not even matter TBH)
        }
    }

    void    Viewer::on_restore_command(const RestoreCommand& cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }

    void    Viewer::on_show_command(const ShowCommand& cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }

    void    Viewer::on_spatial_command(const SpatialCommand&cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }

    void    Viewer::on_title_command(const TitleCommand&cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }
    
    void    Viewer::on_unfloat_command(const UnfloatCommand&cmd)
    {
        if(!dying() && (cmd.target() == id())){
            send(cmd.clone(REBIND, {.target=m_window}));
        }
    }


    void    Viewer::on_size_event(const Size²Event&evt)
    {
        if(evt.source() == m_window){
            yInfo() << "Viewer resized (" << evt.x() << ", " << evt.y() << ")";
        }
    }

    void    Viewer::set_aspect(const Size2I& sz)
    {
        mail(new AspectCommand({.target=this}, sz));
    }
    
    void    Viewer::set_aspect(int w, int h)
    {
        set_aspect({w,h});
    }
    
    void    Viewer::set_aspect(unlock_k)
    {
        set_aspect({-1,-1});
    }
    
    void    Viewer::set_aspect(unlocked_k)
    {
        set_aspect({-1,-1});
    }

    void    Viewer::set_position(const Vector2D&v)
    {
        send(new SetPosition²({.source=this, .target=m_window}, v));
    }

    void    Viewer::set_position(double x, double y)
    {
        set_position(Vector2D(x,y));
    }

    void    Viewer::set_size(const Size2D&sz)
    {
        send(new SetSize²({.source=this, .target=m_window}, sz));
    }
    
    void    Viewer::set_size(double w, double h)
    {
        set_size(Size2D(w,h));
    }

    void    Viewer::set_title(std::string_view kTitle)
    {
        mail(new TitleCommand({.target=this}, kTitle));
    }

    Execution   Viewer::setup(const Context&ctx) 
    {
        if(m_flags(X::Failure))
            return ABORT;
    
        const Frame*    frame   = Frame::current();
        if(!frame)
            return WAIT;
        
        if(!m_graphicsCard){
            GraphicsCardID  gid = frame->first(GRAPHICS_CARD);
            if(!gid){
                viewerDebug << "Viewer: Graphics Card not detected, waiting";
                return WAIT;
            }
            
            m_graphicsCard  = frame->typed(gid);
            if(!m_graphicsCard) [[unlikely]]
                return WAIT;
        }

        if(!frame->snap((WindowID) m_window))
            return WAIT;

        const WidgetSnap*  w    = frame->snap((WidgetID) m_widget);
        if(!w)
            return WAIT;

        if(!m_flags(X::SentDevRequest)){
            send(new GetDeviceRequest({.source=*this, .target=m_graphicsCard}), TARGET);
            m_flags |= X::SentDevRequest;
            return WAIT;
        }
        
        if(!m_flags(X::DevReply))
            return WAIT;
        
        if(!w->started)
            return WAIT;
    
        if(!m_createInfo.hidden){
            cmd_show();
        }
    
        return update(ctx);
    }

    void Viewer::snap(ViewerSnap&sn) const
    {
        sn.widget   = m_widget;
        sn.window   = m_window;
        sn.focus    = m_focus;
        //sn.paused   = m_paused;
        Tachyon::snap(sn);
    }
    
    Execution   Viewer::teardown(const Context&ctx) 
    {

        if(is_visible() && (window_mode() != WindowMode::Fullscreen)){
            if(!m_flags(X::HideCommand)){
                m_flags |= X::HideCommand;
                send(new HideCommand({.source=*this, .target=m_window}), TARGET);
                return WAIT;
            }
        }
    
        m_cleanup.sweep();

        if(m_viz){
            m_viz -> wait_idle();
        }

        if(m_imgui)
            m_imgui = {};

        if(m_viz){
            m_viz -> wait_idle();
            m_viz   = {};
        }
        
        send(new DestroyCommand({.source=this, .target=m_window}));
        send(new CloseEvent({.source=this}));

        return {};
    }

    Execution   Viewer::tick(const Context&ctx) 
    {
        return update(ctx);
    }

    Execution   Viewer::update(const Context&ctx) 
    {
        if(const Frame* f = Frame::current()){
            if(const WindowSnap* sn = f->snap(WindowID(m_window.id))){
                m_state.window      = sn->window;
                m_state.keyboard    = sn->keyboard;
                m_state.mouse       = sn->mouse;
                m_state.time        = sn->time;
            }
        }

        if(m_imgui)
            m_imgui->tick(m_state);

        if(running() && is_visible() && (!is_iconified()) && (all(m_state.window.pixels) != 0)){
            draw(); // HACK (for now)
        } else {
            #if 0
            //  Here for use with debuging
            if(m_stage == Stage::Running){
                if(!is_visible()){
                    tachyonInfo << ident() << "::tick() skipping draw() due to not being visible";        
                }
                if(is_iconified()){
                    tachyonInfo << ident() << "::tick() skipping draw() due to being iconified";        
                }
                if(any(m_state.window.pixels) == 0){
                    tachyonInfo << ident() << "::tick() skipping draw() due to no pixels";        
                }
            }
            #endif
        }

        m_cleanup.sweep();
        ++m_ticks;
        return {};
    }


    const std::string&  Viewer::title() const
    {
        return m_state.window.title;
    }

    Visualizer&         Viewer::visualizer() const
    {
        assert(m_viz);
        return *m_viz;
    }

    int Viewer::width() const
    {
        return m_state.window.area.x;
    }

    WindowMode  Viewer::window_mode() const
    {   
        return m_state.window.mode;
    }

    bool Viewer::zero_framebuffer() const
    {
        return any(framebuffer_size()) <= 0;
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  OLD CODE (some still needs to be brought over)

#if 0
    void    Viewer::set_widget(WidgetPtr w)
    {
        dispatch(SELF, new ViewerWidgetRequest(this, w));
    }
    
    void    Viewer::widget_request(const ViewerWidgetRequestCPtr& cmd)
    {
        if(!cmd)
            return ;
        
        Response    rep     = Response::QaPla;
        WidgetPtr   w       = cmd->widget();
        if(!w){
            rep = Response::NullPointer;
        } else if(w->attached()){
            rep = Response::NotUnattached;
        } else {
            _widget(w);
        }
        
        dispatch(new ViewerWidgetReply(cmd, this, rep));
    }
#endif

#if 0
    Monitor     Viewer::monitor() const
    {
        return Monitor();
    }
#endif

#if 0
    Widget*             Viewer::widget_at(const Vector2D& pt) const
    {
        return m_widget -> widget_at(pt);
    }
#endif
    

#if 0    
    void        Viewer::set_widget(Widget*w, bool fDestroyOld)
    {
        if(!w)
            return ;
        if(w == m_widget)
            return ;
        
        m_widget -> m_viewer    = nullptr;
        w->m_viewer             = this;
            
        std::swap(w, m_widget);
        if(fDestroyOld)
            m_delete.push_back(w);
    }
#endif
}
