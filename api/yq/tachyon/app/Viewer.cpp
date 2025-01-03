////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Viewer.hpp"

#include <log4cpp/CategoryStream.hh>
#include <yt/logging.hpp>

#include <yq/tachyon/app/Application.hpp>
#include <yt/api/Context.hpp>
#include <yt/api/Frame.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yt/api/Thread.hpp>
#include <yq/tachyon/app/ViewerBind.hpp>
#include <yq/tachyon/app/ViewerData.hpp>
#include <yq/tachyon/app/ViewerException.hpp>
#include <yt/gfx/Raster.hpp>
#include <yt/os/Window.hpp>
#include <yt/os/WindowData.hpp>
#include <yt/ui/Widget.hpp>

#include <ya/commands/ViewerAspectCommand.hpp>
#include <ya/commands/ViewerAttentionCommand.hpp>
#include <ya/commands/ViewerCloseCommand.hpp>
#include <ya/commands/ViewerCursorCaptureCommand.hpp>
#include <ya/commands/ViewerCursorDisableCommand.hpp>
#include <ya/commands/ViewerCursorHideCommand.hpp>
#include <ya/commands/ViewerCursorNormalCommand.hpp>
#include <ya/commands/ViewerFloatCommand.hpp>
#include <ya/commands/ViewerFocusCommand.hpp>
#include <ya/commands/ViewerHideCommand.hpp>
#include <ya/commands/ViewerIconifyCommand.hpp>
#include <ya/commands/ViewerMaximizeCommand.hpp>
#include <ya/commands/ViewerMoveCommand.hpp>
#include <ya/commands/ViewerPauseCommand.hpp>
#include <ya/commands/ViewerRestoreCommand.hpp>
#include <ya/commands/ViewerResumeCommand.hpp>
#include <ya/commands/ViewerShowCommand.hpp>
#include <ya/commands/ViewerSizeCommand.hpp>
#include <ya/commands/ViewerTitleCommand.hpp>
#include <ya/commands/ViewerUnfloatCommand.hpp>
#include <ya/commands/WidgetStartupCommand.hpp>
#include <ya/commands/WindowAspectCommand.hpp>
#include <ya/commands/WindowAttentionCommand.hpp>
#include <ya/commands/WindowCursorCaptureCommand.hpp>
#include <ya/commands/WindowCursorDisableCommand.hpp>
#include <ya/commands/WindowCursorHideCommand.hpp>
#include <ya/commands/WindowCursorNormalCommand.hpp>
#include <ya/commands/WindowDestroyCommand.hpp>
#include <ya/commands/WindowFloatCommand.hpp>
#include <ya/commands/WindowFocusCommand.hpp>
#include <ya/commands/WindowHideCommand.hpp>
#include <ya/commands/WindowIconifyCommand.hpp>
#include <ya/commands/WindowMaximizeCommand.hpp>
#include <ya/commands/WindowMoveCommand.hpp>
#include <ya/commands/WindowRestoreCommand.hpp>
#include <ya/commands/WindowShowCommand.hpp>
#include <ya/commands/WindowSizeCommand.hpp>
#include <ya/commands/WindowTitleCommand.hpp>
#include <ya/commands/WindowUnfloatCommand.hpp>

#include <ya/events/KeyCharacterEvent.hpp>
#include <ya/events/KeyPressEvent.hpp>
#include <ya/events/KeyReleaseEvent.hpp>
#include <ya/events/MouseMoveEvent.hpp>
#include <ya/events/MousePressEvent.hpp>
#include <ya/events/MouseReleaseEvent.hpp>
#include <ya/events/MouseMoveEvent.hpp>
#include <ya/events/MousePressEvent.hpp>
#include <ya/events/MouseReleaseEvent.hpp>
#include <ya/events/ViewerCloseEvent.hpp>
#include <ya/events/ViewerDestroyEvent.hpp>
#include <ya/events/ViewerPauseEvent.hpp>
#include <ya/events/ViewerResumeEvent.hpp>
#include <ya/events/WindowDefocusEvent.hpp>
#include <ya/events/WindowDestroyEvent.hpp>
#include <ya/events/WindowFocusEvent.hpp>
#include <ya/events/WindowFrameBufferResizeEvent.hpp>
#include <ya/events/WindowHideEvent.hpp>
#include <ya/events/WindowMoveEvent.hpp>
#include <ya/events/WindowResizeEvent.hpp>
#include <ya/events/WindowShowEvent.hpp>

#include <ya/desktops/glfw/WindowGLFW.hpp>


#include <ya/replies/ViewerCloseReply.hpp>

#include <ya/requests/ViewerCloseRequest.hpp>
#include <ya/requests/WindowCloseRequest.hpp>
#include <ya/requests/WindowRefreshRequest.hpp>

#include <yv/ViContext.hpp>
#include <yv/ViGui.hpp>
#include <yv/Visualizer.hpp>

//#include <ya/replies/ViewerWidgetReply.hpp>
//#include <ya/requests/ViewerWidgetRequest.hpp>

#include <yq/errors.hpp>
#include <yq/core/ErrorDB.hpp>
#include <yq/core/ThreadId.hpp>
#include <yt/api/TachyonInfoWriter.hpp>
#include <yq/shape/Size2.hxx>
#include <yq/util/AutoReset.hpp>
#include <yq/vector/Vector2.hpp>

#define viewerAlert                 yAlert("viewer")
#define viewerCritical              yCritical("viewer")
#define viewerDebug                 yDebug("viewer")
#define viewerError                 yError("viewer")
#define viewerEmergency             yEmergency("viewer")
#define viewerFatal                 yFatal("viewer")
#define viewerInfo                  yInfo("viewer")
#define viewerNotice                yNotice("viewer")
#define viewerWarning               yWarning("viewer")

YQ_OBJECT_IMPLEMENT(yq::tachyon::Viewer)

namespace yq::tachyon {

    ViewerBind::ViewerBind(const Viewer* v) : m_viewer(v ? v->id() : ViewerID{}) 
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ViewerInfo::ViewerInfo(std::string_view szName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(szName, base, sl)
    {
        set(Type::Viewer);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::atomic<int>        Viewer::s_count{0};
    std::atomic<unsigned>   Viewer::s_lastNumber{0};

    Viewer::Param   Viewer::_params(const ViewerCreateInfo&vci)
    {
        Param  ret;
        //ret.name    = "Viewer";
        return ret;
    }

    void Viewer::init_info()
    {
        auto w = writer<Viewer>();
        
        w.description("Tachyon Viewer");
        w.property("ticks", &Viewer::ticks).description("Total number of ticks so far");
        w.slot(&Viewer::on_cursor_capture_command);
        w.slot(&Viewer::on_cursor_disable_command);
        w.slot(&Viewer::on_cursor_hide_command);
        w.slot(&Viewer::on_cursor_normal_command);
        
        w.slot(&Viewer::on_key_character_event);
        w.slot(&Viewer::on_key_press_event);
        w.slot(&Viewer::on_key_release_event);
        
        w.slot(&Viewer::on_mouse_move_event);
        w.slot(&Viewer::on_mouse_press_event);
        w.slot(&Viewer::on_mouse_release_event);
        
        w.slot(&Viewer::on_viewer_aspect_command);
        w.slot(&Viewer::on_viewer_attention_command);
        w.slot(&Viewer::on_viewer_close_command);
        w.slot(&Viewer::on_viewer_close_request);
        w.slot(&Viewer::on_viewer_float_command);
        w.slot(&Viewer::on_viewer_focus_command);
        w.slot(&Viewer::on_viewer_hide_command);
        w.slot(&Viewer::on_viewer_iconify_command);
        w.slot(&Viewer::on_viewer_maximize_command);
        w.slot(&Viewer::on_viewer_move_command);
        w.slot(&Viewer::on_viewer_pause_command);
        w.slot(&Viewer::on_viewer_restore_command);
        w.slot(&Viewer::on_viewer_resume_command);
        w.slot(&Viewer::on_viewer_show_command);
        w.slot(&Viewer::on_viewer_size_command);
        w.slot(&Viewer::on_viewer_title_command);
        w.slot(&Viewer::on_viewer_unfloat_command);
        
        w.slot(&Viewer::on_window_close_request);
        w.slot(&Viewer::on_window_defocus_event);
        w.slot(&Viewer::on_window_destroy_event);
        w.slot(&Viewer::on_window_fb_resize_event);
        w.slot(&Viewer::on_window_focus_event);
        w.slot(&Viewer::on_window_hide_event);
        w.slot(&Viewer::on_window_move_event);
        w.slot(&Viewer::on_window_resize_event);
        w.slot(&Viewer::on_window_show_event);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Viewer::Viewer(Window* win, WidgetPtr w, const ViewerCreateInfo& vci) : Viewer(win, w, vci, _params(vci))
    {
    }


    Viewer::Viewer(Window* win, WidgetPtr w, const ViewerCreateInfo& vci, const Param&p) : 
        Tachyon(p), m_createInfo(vci), m_number(++s_lastNumber)
    {
        assert(win && w);
        
        m_window                = win->id();
        _widget(w);
        
        // HACK (becase we know it's GLFW ATM)
        WindowGLFW* w2  = static_cast<WindowGLFW*>(win);
        GLFWwindow* gw  = w2 -> glfw();
        m_pixels        = w2->framebuffer();
        try {
            m_viz       = std::make_unique<Visualizer>(m_createInfo, gw, m_cleanup);
        } 
        catch(const std::exception& ex) {
            tachyonCritical << ident() << " cannot create the visualizer.  " << ex.what();
            throw;
        }
        catch(const std::error_code& ec){
            tachyonCritical << ident() << " cannot create the visualizer.  " << ec.message();
            throw;
        }
        
        
        if(m_createInfo.imgui){
            try {
                m_imgui = std::make_unique<ViGui>(*m_viz);
            }
            catch(const std::exception& ex){
                tachyonCritical << ident() << " cannot create imgui.  " << ex.what();
            }
            catch(const std::error_code& ec){
                tachyonCritical << ident() << " cannot create imgui.  " << ec.message();
                throw;
            }
        }
        
        m_stage     = Stage::Started;
        
        ++s_count;
        tachyonInfo << "Viewer::Viewer(" << m_number << ") ID " << (uint64_t) id() << ", window=" 
            << (uint64_t) win->id() << ", widget=" << w->id();
    }
    
    Viewer::~Viewer()
    {
        --s_count;
        _remove(WIDGET);
        m_widget = {};
        _sweepwait();
        if(m_imgui)
            m_imgui = {};
        _sweepwait();
        if(m_viz)
            m_viz   = {};
        m_cleanup.sweep();
        tachyonInfo << "Viewer::~Viewer(" << m_number << ")";
    }

    void    Viewer::_install(widget_k)
    {
        if(m_widget){
            m_widget -> m_viewer    = this;
            subscribe(m_widget->id(), {MG::Widget, MG::General});
            m_widget->subscribe(id(), {MG::General, MG::Viewer});
        }
    }
    
    void    Viewer::_remove(widget_k)
    {
        if(m_widget){
            m_widget -> m_viewer    = nullptr;
            m_widget->unsubscribe(id(), {MG::Viewer, MG::General});
            unsubscribe(m_widget->id(), {MG::Widget, MG::General});
        }
    }
    
    void    Viewer::_sweepwait()
    {
        if(m_viz)
            m_viz -> wait_idle();
        m_cleanup.sweep();
    }


    void    Viewer::_widget(WidgetPtr w)
    {
        _remove(WIDGET);
        m_widget    = w;
        _install(WIDGET);
    }

    void     Viewer::accept(close_k)
    {
        m_widget -> m_flags -= Widget::F::ClosePending;
        RequestCPtr  req = swap(Viewer::m_closeRequest, {});
        if(req){
            send(new ViewerCloseReply(req, this, Response::QaPla));
            mail(new ViewerCloseCommand(this));
        }
    }

    PostAdvice  Viewer::advise(const Post& pp) const 
    {
        if(const WindowBind*   wb  = dynamic_cast<const WindowBind*>(&pp)){
            if(wb -> window() != m_window)
                return REJECT;
            if(dynamic_cast<const InputEvent*>(&pp)){
                return MG::Widget;
            }
        }
        if(const ViewerBind* vb = dynamic_cast<const ViewerBind*>(&pp)){
            if(vb -> viewer() != id())
                return REJECT;
        }
        
        return {};
    }

    const Size2I&   Viewer::aspect() const
    {
        return m_state.window.aspect;
    }

    void    Viewer::close_request()
    {
        if(m_widget){
            m_widget -> m_flags |= Widget::F::ClosePending;
            m_widget -> on_close_request();
        } else {
            accept(CLOSE); 
        }
    }

    bool    Viewer::closing() const
    {
        return stage() == Stage::Closing;
    }
    
    bool    Viewer::closing_or_kaput() const
    {
        Stage st = stage();
        return (st == Stage::Closing) || (st == Stage::Kaput);
    }

    void    Viewer::cmd_attention()
    {
        mail(new ViewerAttentionCommand(this));
    }

    void    Viewer::cmd_close(bool force)
    {
        if(force){
            mail(new ViewerCloseCommand(this));
        } else {
            mail(new ViewerCloseRequest(this));
        }
    }

    void    Viewer::cmd_cursor_capture()
    {
        mail(new ViewerCursorCaptureCommand(this));
    }
    
    void    Viewer::cmd_cursor_disable()
    {
        mail(new ViewerCursorDisableCommand(this));
    }
    
    void    Viewer::cmd_cursor_hide()
    {
        mail(new ViewerCursorHideCommand(this));
    }
    
    void    Viewer::cmd_cursor_normal()
    {
        mail(new ViewerCursorNormalCommand(this));
    }

    void    Viewer::cmd_float()
    {
        mail(new ViewerFloatCommand(this));
    }

    void    Viewer::cmd_focus()
    {
        mail(new ViewerFocusCommand(this));
    }

    void    Viewer::cmd_hide()
    {
        mail(new ViewerHideCommand(this));
    }

    void    Viewer::cmd_iconify()
    {
        mail(new ViewerIconifyCommand(this));
    }

    void    Viewer::cmd_maximize()
    {
        mail(new ViewerMaximizeCommand(this));
    }

    void    Viewer::cmd_pause()
    {
        mail(new ViewerPauseCommand(this));
    }
    
    void    Viewer::cmd_restore()
    {
        mail(new ViewerRestoreCommand(this));
    }

    void    Viewer::cmd_resume()
    {
        mail(new ViewerResumeCommand(this));
    }

    void    Viewer::cmd_show()
    {
        mail(new ViewerShowCommand(this));
    }

    void    Viewer::cmd_unfloat()
    {
        mail(new ViewerUnfloatCommand(this));
    }

    std::error_code     Viewer::draw()
    {
        ViContext   u;
        
        //  ENABLE to get the validation issue
        //  u.snapshot  = DataFormat(DataFormat::R8G8B8A8_SRGB);
        return draw(u);
    }

    std::error_code     Viewer::draw(ViContext& u)
    {
        if(m_paused || m_zeroSize)
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
        if(m_widget && m_imgui){
            m_imgui -> draw(u, m_widget);
        }
        std::error_code ec = m_viz->draw(u, {
            .prerecord = [&](ViContext& u){
                if(m_widget){
                    m_widget -> prerecord(u);
                }
                if(m_imgui){
                    m_imgui -> update();
                }
            },
            .record = [&](ViContext& u){
                if(m_widget)
                    m_widget -> vulkan_(u);
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
    
    bool    Viewer::kaput() const
    {
        return stage() == Stage::Kaput;
    }
    
    bool    Viewer::never_started() const
    {
        return stage() == Stage::Preinit;
    }

    void    Viewer::on_cursor_capture_command(const ViewerCursorCaptureCommand&)
    {
        if(started_or_running()){
            send(new WindowCursorCaptureCommand(m_window));
        }
    }
    
    void    Viewer::on_cursor_disable_command(const ViewerCursorDisableCommand&)
    {
        if(started_or_running()){
            send(new WindowCursorDisableCommand(m_window));
        }
    }
    
    void    Viewer::on_cursor_hide_command(const ViewerCursorHideCommand&)
    {
        if(started_or_running()){
            send(new WindowCursorHideCommand(m_window));
        }
    }
    
    void    Viewer::on_cursor_normal_command(const ViewerCursorNormalCommand&)
    {
        if(started_or_running()){
            send(new WindowCursorNormalCommand(m_window));
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

    void    Viewer::on_viewer_aspect_command(const ViewerAspectCommand& cmd)
    {
        if(started_or_running()){
            send(new WindowAspectCommand(m_window, cmd.aspect()));
        }
    }

    void    Viewer::on_viewer_attention_command(const ViewerAttentionCommand&)
    {
        if(started_or_running()){
            send(new WindowAttentionCommand(m_window));
        }
    }

    void    Viewer::on_viewer_close_command(const ViewerCloseCommand&)
    {
        if(started_or_running()){
            send(new WindowHideCommand(m_window));
            m_stage = Stage::Closing;
        }
    }

    void    Viewer::on_viewer_close_request(const ViewerCloseRequestCPtr&req) 
    { 
        if(!req){
            return ;
        }
        
        if(closing_or_kaput()){
            send(new ViewerCloseReply(req, this, Response::Busy));
            return ;
        }

        if(m_closeRequest){
            if(m_closeRequest->id() != req->id()){
                send(new ViewerCloseReply(req, this, Response::Busy));
            }
            return ;
        }
    
        {
            TXLOCK
            m_closeRequest  = req.ptr();
        }
        close_request();
    }

    void    Viewer::on_viewer_float_command(const ViewerFloatCommand&)
    {
        if(started_or_running()){
            send(new WindowFloatCommand(m_window));
        }
    }
    
    void    Viewer::on_viewer_focus_command(const ViewerFocusCommand&)
    {
        if(started_or_running()){
            send(new WindowFocusCommand(m_window));
        }
    }
    
    void    Viewer::on_viewer_hide_command(const ViewerHideCommand&)
    {
        if(started_or_running()){
            send(new WindowHideCommand(m_window));
        }
    }
    void    Viewer::on_viewer_iconify_command(const ViewerIconifyCommand&)
    {
        if(started_or_running()){
            send(new WindowIconifyCommand(m_window));
        }
    }
    
    void    Viewer::on_viewer_maximize_command(const ViewerMaximizeCommand&)
    {
        if(started_or_running()){
            send(new WindowMaximizeCommand(m_window));
        }
    }
    
    void    Viewer::on_viewer_move_command(const ViewerMoveCommand&cmd)
    {
        if(started_or_running()){
            send(new WindowMoveCommand(m_window, cmd.position()));
        }
    }

    void    Viewer::on_viewer_pause_command(const ViewerPauseCommand&)
    {
        m_paused    = true;
        send(new ViewerPauseEvent(this));
        mark();
    }
    
    void    Viewer::on_viewer_restore_command(const ViewerRestoreCommand&)
    {
        if(started_or_running()){
            send(new WindowRestoreCommand(m_window));
        }
    }
    
    void    Viewer::on_viewer_resume_command(const ViewerResumeCommand&)
    {
        m_paused    = false;
        send(new ViewerResumeEvent(this));
        mark();
    }
    
    void    Viewer::on_viewer_show_command(const ViewerShowCommand&)
    {
        if(started_or_running()){
            send(new WindowShowCommand(m_window));
        }
    }

    void    Viewer::on_viewer_size_command(const ViewerSizeCommand& cmd)
    {
        if(started_or_running()){
            send(new WindowSizeCommand(m_window, cmd.size()));
        }
    }

    void    Viewer::on_viewer_title_command(const ViewerTitleCommand&cmd)
    {
        if(started_or_running()){
            send(new WindowTitleCommand(m_window, cmd.title()));
        }
    }
    
    void    Viewer::on_viewer_unfloat_command(const ViewerUnfloatCommand&)
    {
        if(started_or_running()){
            send(new WindowUnfloatCommand(m_window));
        }
    }

    void    Viewer::on_window_close_request(const WindowCloseRequestCPtr&req) 
    { 
        if(!req){
            return ;
        }

        if(closing_or_kaput()){
            send(new ViewerCloseReply(req, this, Response::Busy));
            return ;
        }

        if(m_closeRequest){
            if(m_closeRequest->id() != req->id()){
                send(new ViewerCloseReply(req, this, Response::Busy));
            }
            return ;
        }
    
        {
            TXLOCK
            m_closeRequest  = req.ptr();
        }
        close_request();
    }

    void    Viewer::on_window_defocus_event(const WindowDefocusEvent&evt)
    {
        if(m_imgui){
            m_imgui->on(evt);
        }
    }

    void    Viewer::on_window_destroy_event(const WindowDestroyEvent&)
    {
        m_stage     = Stage::Destruct;
    }

    void    Viewer::on_window_fb_resize_event(const WindowFrameBufferResizeEvent&evt)
    {
    }
    
    void    Viewer::on_window_focus_event(const WindowFocusEvent&evt)
    {
        if(m_imgui){
            m_imgui->on(evt);
        }
    }


    void    Viewer::on_window_hide_event(const WindowHideEvent&)
    {
        if(closing()){
            m_stage     = Stage::Kaput;
            
            send(new WindowDestroyCommand(m_window));
            send(new ViewerCloseEvent(this));

            _sweepwait();
            m_imgui     = {};
            _sweepwait();
            m_viz       = {};
            _sweepwait();
        } else {
            //  DO NOTHING
        }
    }
    
    void    Viewer::on_window_move_event(const WindowMoveEvent&evt)
    {
    }

    void    Viewer::on_window_resize_event(const WindowResizeEvent&evt)
    {
    }
    
    void    Viewer::on_window_show_event(const WindowShowEvent&evt)
    {
        switch(m_stage){
        case Stage::Started:
        case Stage::WidgetStart:
            m_stage = Stage::Running;
            break;
        default:
            break;
        }
    }

    void     Viewer::owner(push_k, ThreadID tid) 
    {
        Tachyon::owner(PUSH, tid);
        if(m_widget)
            m_widget -> owner(PUSH, tid);
            
        #if 0
            //  here in case we move imgui/viz to the tachyon model
        if(m_imgui)
            m_imgui -> owner(PUSH, tid);
        if(m_viz)
            m_viz -> owner(PUSH, tid);
        #endif
    }

    bool    Viewer::paused() const 
    { 
        return m_paused; 
    }

    const Vector2I&   Viewer::position() const
    {
        return m_state.window.position;
    }

    void     Viewer::reject(close_k)
    {
        m_widget -> m_flags -= Widget::F::ClosePending;
        RequestCPtr  req = swap(Viewer::m_closeRequest, {});
        if(req){
            send(new ViewerCloseReply(req, this, Response::Rejected));
        }
    }

    bool    Viewer::running() const
    {
        return stage() == Stage::Running;
    }

    void    Viewer::set_aspect(const Size2I& sz)
    {
        mail(new ViewerAspectCommand(this, sz));
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

    void    Viewer::set_position(const Vector2I&v)
    {
        mail(new ViewerMoveCommand(this, v));
    }

    void    Viewer::set_position(int x, int y)
    {
        set_position({x,y});
    }

    void    Viewer::set_size(const Size2I&sz)
    {
        mail(new ViewerSizeCommand(this, sz));
    }
    
    void    Viewer::set_size(int w, int h)
    {
        set_size({w,h});
    }

    void    Viewer::set_title(std::string_view kTitle)
    {
        mail(new ViewerTitleCommand(this, kTitle));
    }

    const Size2I&   Viewer::size() const
    {
        return m_state.window.area;
    }

    void Viewer::snap(ViewerSnap&sn) const
    {
        sn.window   = m_window;
        sn.paused   = m_paused;
    }

    Viewer::Stage   Viewer::stage() const
    {
        return m_stage;
    }

    bool    Viewer::started() const
    {
        return stage() == Stage::Started;
    }
    
    bool    Viewer::started_or_running() const
    {
        Stage st = stage();
        return (st == Stage::Started) || (st == Stage::WidgetStart) || (st == Stage::Running);
    }

    Execution   Viewer::tick(Context&ctx) 
    {
        switch(stage()){
        case Stage::Preinit:
            return {};
        case Stage::Started:
            if(!(ctx.frame.contains(id()) && ctx.frame.contains(m_window))){
                return {};
            }
            send(new WidgetStartupCommand(m_widget), m_widget->id());
            m_stage = Stage::WidgetStart;
            break;
        case Stage::WidgetStart:
            break;
        case Stage::Running:
            break;
        case Stage::Closing:
            return {};
        case Stage::Kaput:
            return {};
        case Stage::Destruct:
            send(new ViewerDestroyEvent(this), MGF{MG::Thread, MG::General});
            return DELETE;
        }

        if(const Frame* f = frame()){
            if(const WindowSnap* sn = f->snap(m_window)){
                m_state.window      = sn->window;
                m_state.keyboard    = sn->keyboard;
                m_state.mouse       = sn->mouse;
                m_state.time        = sn->time;
            }
        }

        if(m_imgui)
            m_imgui->tick(m_state);
        
        if((m_stage == Stage::Running) && is_visible() && (!is_iconified()) && (all(m_state.window.pixels) != 0)){
            
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
        mark();
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
