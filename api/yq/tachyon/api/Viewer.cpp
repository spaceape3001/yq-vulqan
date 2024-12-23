////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Viewer.hpp"

#include <log4cpp/CategoryStream.hh>
#include <yq/tachyon/logging.hpp>

#include <yq/tachyon/api/Application.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>
#include <yq/tachyon/api/ViewerBind.hpp>
#include <yq/tachyon/api/ViewerException.hpp>
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/api/Window.hpp>
#include <yq/tachyon/api/WindowData.hpp>

#include <yq/tachyon/commands/ViewerAspectCommand.hpp>
#include <yq/tachyon/commands/ViewerAttentionCommand.hpp>
#include <yq/tachyon/commands/ViewerCloseCommand.hpp>
#include <yq/tachyon/commands/ViewerCursorCaptureCommand.hpp>
#include <yq/tachyon/commands/ViewerCursorDisableCommand.hpp>
#include <yq/tachyon/commands/ViewerCursorHideCommand.hpp>
#include <yq/tachyon/commands/ViewerCursorNormalCommand.hpp>
#include <yq/tachyon/commands/ViewerFloatCommand.hpp>
#include <yq/tachyon/commands/ViewerFocusCommand.hpp>
#include <yq/tachyon/commands/ViewerHideCommand.hpp>
#include <yq/tachyon/commands/ViewerIconifyCommand.hpp>
#include <yq/tachyon/commands/ViewerMaximizeCommand.hpp>
#include <yq/tachyon/commands/ViewerMoveCommand.hpp>
#include <yq/tachyon/commands/ViewerPauseCommand.hpp>
#include <yq/tachyon/commands/ViewerRestoreCommand.hpp>
#include <yq/tachyon/commands/ViewerResumeCommand.hpp>
#include <yq/tachyon/commands/ViewerShowCommand.hpp>
#include <yq/tachyon/commands/ViewerSizeCommand.hpp>
#include <yq/tachyon/commands/ViewerTitleCommand.hpp>
#include <yq/tachyon/commands/ViewerUnfloatCommand.hpp>
#include <yq/tachyon/commands/WindowAspectCommand.hpp>
#include <yq/tachyon/commands/WindowAttentionCommand.hpp>
#include <yq/tachyon/commands/WindowCursorCaptureCommand.hpp>
#include <yq/tachyon/commands/WindowCursorDisableCommand.hpp>
#include <yq/tachyon/commands/WindowCursorHideCommand.hpp>
#include <yq/tachyon/commands/WindowCursorNormalCommand.hpp>
#include <yq/tachyon/commands/WindowFloatCommand.hpp>
#include <yq/tachyon/commands/WindowFocusCommand.hpp>
#include <yq/tachyon/commands/WindowHideCommand.hpp>
#include <yq/tachyon/commands/WindowIconifyCommand.hpp>
#include <yq/tachyon/commands/WindowMaximizeCommand.hpp>
#include <yq/tachyon/commands/WindowMoveCommand.hpp>
#include <yq/tachyon/commands/WindowRestoreCommand.hpp>
#include <yq/tachyon/commands/WindowShowCommand.hpp>
#include <yq/tachyon/commands/WindowSizeCommand.hpp>
#include <yq/tachyon/commands/WindowTitleCommand.hpp>
#include <yq/tachyon/commands/WindowUnfloatCommand.hpp>

#include <yq/tachyon/events/KeyCharacterEvent.hpp>
#include <yq/tachyon/events/KeyPressEvent.hpp>
#include <yq/tachyon/events/KeyReleaseEvent.hpp>
#include <yq/tachyon/events/MouseMoveEvent.hpp>
#include <yq/tachyon/events/MousePressEvent.hpp>
#include <yq/tachyon/events/MouseReleaseEvent.hpp>
#include <yq/tachyon/events/MouseMoveEvent.hpp>
#include <yq/tachyon/events/MousePressEvent.hpp>
#include <yq/tachyon/events/MouseReleaseEvent.hpp>
#include <yq/tachyon/events/ViewerPauseEvent.hpp>
#include <yq/tachyon/events/ViewerResumeEvent.hpp>
#include <yq/tachyon/events/WindowDefocusEvent.hpp>
#include <yq/tachyon/events/WindowFocusEvent.hpp>
#include <yq/tachyon/events/WindowFrameBufferResizeEvent.hpp>
#include <yq/tachyon/events/WindowHideEvent.hpp>
#include <yq/tachyon/events/WindowMoveEvent.hpp>
#include <yq/tachyon/events/WindowResizeEvent.hpp>
#include <yq/tachyon/events/WindowShowEvent.hpp>

#include <yq/tachyon/glfw/WindowGLFW.hpp>

#include <yq/tachyon/replies/ViewerCloseReply.hpp>

#include <yq/tachyon/requests/ViewerCloseRequest.hpp>
#include <yq/tachyon/requests/WindowCloseRequest.hpp>
#include <yq/tachyon/requests/WindowRefreshRequest.hpp>

#include <yq/tachyon/viz/ViContext.hpp>
#include <yq/tachyon/viz/ViGui.hpp>
#include <yq/tachyon/viz/Visualizer.hpp>

//#include <yq/tachyon/commands/GLFWCloseCommand.hpp>
//#include <yq/tachyon/commands/AppDeleteViewerCommand.hpp>
//#include <yq/tachyon/commands/viewer.hpp>
//#include <yq/tachyon/commands/window.hpp>

//#include <yq/tachyon/even4s/ViewerCloseEvent.hpp>
//#include <yq/tachyon/events/WindowDestroyEvent.hpp>
//#include <yq/tachyon/events/WindowHideEvent.hpp>
//#include <yq/tachyon/events/WindowResizeEvent.hpp>
//#include <yq/tachyon/events/WindowShowEvent.hpp>
//#include <yq/tachyon/image/Raster.hpp>
//#include <yq/tachyon/replies/ViewerWidgetReply.hpp>
//#include <yq/tachyon/requests/ViewerWidgetRequest.hpp>

#include <yq/errors.hpp>
#include <yq/core/ErrorDB.hpp>
#include <yq/core/ThreadId.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>
#include <yq/shape/Size2.hxx>
#include <yq/util/AutoReset.hpp>
#include <yq/vector/Vector2.hpp>

//#include <backends/imgui_impl_glfw.h>

#include <GLFW/glfw3.h>


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
        GLFWwindow* gw  = static_cast<WindowGLFW*>(win) -> glfw();
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
        m_cleanup.sweep();
        if(m_imgui)
            m_imgui = {};
        m_cleanup.sweep();
        if(m_viz)
            m_viz   = {};
        m_cleanup.sweep();
        tachyonInfo << "Viewer::~Viewer(" << m_number << ")";
    }

    void    Viewer::_install(widget_t)
    {
        if(m_widget){
            m_widget -> m_viewer    = this;
            subscribe(m_widget->id(), {MG::Forward, MG::General});
            m_widget->subscribe(id(), MG::General);
        }
    }
    
    void    Viewer::_remove(widget_t)
    {
        if(m_widget){
            m_widget -> m_viewer    = nullptr;
            m_widget->unsubscribe(id(), {MG::Forward, MG::General});
        }
    }
    
    void    Viewer::_widget(WidgetPtr w)
    {
        _remove(WIDGET);
        m_widget    = w;
        _install(WIDGET);
    }

    void     Viewer::accept(close_t)
    {
        m_widget -> m_flags -= Widget::F::ClosePending;
        RequestCPtr  req = swap(Viewer::m_closeRequest, {});
        if(req){
            send(new ViewerCloseReply(req, this, Response::QaPla));
            mail(new ViewerCloseCommand(this));
        }
        tachyonInfo << ident() << "::accept(CLOSE)";
    }

    PostAdvice  Viewer::advise(const Post& pp) const 
    {
        if(const WindowBind*   wb  = dynamic_cast<const WindowBind*>(&pp)){
            if(wb -> window() != m_window)
                return REJECT;
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
        return {};
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

    void    Viewer::on_window_hide_event(const WindowHideEvent&)
    {
        if(closing()){
            m_stage     = Stage::Kaput;
            
            
            tachyonInfo << ident() << " Window Hidden (TODO -- DESTRUCTION)";
            
            //  DESTROY VIEWER
            
        } else {
            //  DO NOTHING
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

    void    Viewer::on_window_fb_resize_event(const WindowFrameBufferResizeEvent&evt)
    {
        tachyonInfo << ident() << " Framebuffer resized (" << evt.width() << ", " << evt.height() << ")";
    }
    
    void    Viewer::on_window_focus_event(const WindowFocusEvent&evt)
    {
        if(m_imgui){
            m_imgui->on(evt);
        }
    }
    
    void    Viewer::on_window_move_event(const WindowMoveEvent&evt)
    {
        tachyonInfo << ident() << " Window moved (" << evt.x() << ", " << evt.y() << ")";
    }

    void    Viewer::on_window_resize_event(const WindowResizeEvent&evt)
    {
        tachyonInfo << ident() << " Window resized (" << evt.width() << ", " << evt.height() << ")";
    }
    
    void    Viewer::on_window_show_event(const WindowHideEvent&evt)
    {
        
    }

    void     Viewer::owner(push_t, ThreadID tid) 
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

    void     Viewer::reject(close_t)
    {
        m_widget -> m_flags -= Widget::F::ClosePending;
        RequestCPtr  req = swap(Viewer::m_closeRequest, {});
        if(req){
            send(new ViewerCloseReply(req, this, Response::Rejected));
        }
        tachyonInfo << ident() << "::reject(CLOSE)";
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
    
    void    Viewer::set_aspect(unlock_t)
    {
        set_aspect({-1,-1});
    }
    
    void    Viewer::set_aspect(unlocked_t)
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
        return (st == Stage::Started) || (st == Stage::Running);
    }


    Execution   Viewer::tick(Context&ctx) 
    {
        const WindowSnap* sn = frame().snap(m_window);
        if(sn){
            m_state.window      = sn->window;
            m_state.keyboard    = sn->keyboard;
            m_state.mouse       = sn->mouse;
            m_state.time        = sn->time;
        }
        
        switch(stage()){
        case Stage::Preinit:
            return tick_1_preinit(ctx);
        case Stage::Started:
            return tick_2_started(ctx);
        case Stage::Running:
            return tick_3_running(ctx);
        case Stage::Closing:
            return tick_4_closing(ctx);
        case Stage::Kaput:
            return tick_5_kaput(ctx);
        }

        return {};
    }

    Execution    Viewer::tick_1_preinit(Context&)
    {
        return {};
    }
    
    Execution    Viewer::tick_2_started(Context&)
    {
        // Might do something with the widget?
        send(new WindowShowCommand(m_window));
        m_stage = Stage::Running;
        return {};
    }
    
    Execution    Viewer::tick_3_running(Context&)
    {
        return {};
    }
    
    Execution    Viewer::tick_4_closing(Context&)
    {
        return {};
    }
    
    Execution    Viewer::tick_5_kaput(Context&)
    {
        return {};
    }

    const std::string&  Viewer::title() const
    {
        return m_state.window.title;
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
    //  OLD CODE

#if 0
    void Viewer::init_info()
    {
        auto w = writer<Viewer>();
        
        w.description("Tachyon Viewer");
        w.property("ticks", &Viewer::ticks).description("Total number of ticks so far");
        
        w.slot(&Viewer::aspect_command).name("aspect_command");
        w.slot(&Viewer::attention_command).name("attention_command");
        w.slot(&Viewer::close_command).name("close_command");
        w.slot(&Viewer::close_request).name("close_request");
        w.slot(&Viewer::cursor_capture_command).name("cursor_capture_command");
        w.slot(&Viewer::cursor_disable_command).name("cursor_disable_command");
        w.slot(&Viewer::cursor_hide_command).name("cursor_hide_command");
        w.slot(&Viewer::cursor_normal_command).name("cursor_normal_command");
        w.slot(&Viewer::destroy_event).name("destroy_event");
        w.slot(&Viewer::float_command).name("float_command");
        w.slot(&Viewer::focus_command).name("focus_command");
        w.slot(&Viewer::hide_command).name("hide_command");
        w.slot(&Viewer::hide_event).name("hide_event");
        w.slot(&Viewer::iconify_command).name("iconify_command");
        w.slot(&Viewer::maximize_command).name("maximize_command");
        w.slot(&Viewer::move_command).name("move_command");
        w.slot(&Viewer::pause_command).name("pause_command");
        w.slot(&Viewer::resume_command).name("resume_command");
        w.slot(&Viewer::restore_command).name("restore_command");
        w.slot(&Viewer::show_command).name("show_command");
        w.slot(&Viewer::show_event).name("show_event");
        w.slot(&Viewer::size_command).name("size_command");
        w.slot(&Viewer::state_event).name("state_event");
        w.slot(&Viewer::title_command).name("title_command");
        w.slot(&Viewer::unfloat_command).name("unfloat_command");
        w.slot(&Viewer::widget_request).name("widget_request");
        
        w.slot(&Viewer::viewer_resize_event);
        w.property("mouse", &Viewer::mouse_state).description("Mouse state");
    }
#endif

#if 0
    //  ----------------------------------------------------------------------------------------------------------------
    //  INITIALIZATION/DESTRUCTION


 
    Viewer::~Viewer()
    {
        disconnect(ALL);
        _kill();
        m_cleanup.sweep();
        --s_count;
    }

    void    Viewer::_kill()
    {
        _remove(WIDGET);
        m_widget = {};
        if(m_imgui){
            detach(FORWARD, m_imgui.get());
            m_imgui = {};
        }
        if(m_viz){
            //detach(FORWARD, m_viz.get()); // TODO
            m_viz   = {};
        }
    }

    void    Viewer::_quit()
    {
        // TODO
    }

    std::error_code         Viewer::_startup(GLFWwindow* win, const ViewerState& st)
    {
        assert(m_stage == Stage::Preinit);
        m_state     = st;
        m_viz       = std::make_unique<Visualizer>(*m_createInfo, win, m_cleanup);
        if(m_createInfo->imgui){
            m_imgui = std::make_unique<ViGui>(*m_viz);
        }
        
        m_stage = Stage::Started;

        std::error_code     ec;
        try {
            ec = startup({win});
        }
        catch(...)
        {
            m_stage = Stage::Kaput;
            
            #ifdef NDEBUG
            ec = create_error<"Exception caught during Viewer startup">();
            #else
            throw;
            #endif
            
        }
        

        if(ec != std::error_code()){
            m_stage = Stage::Kaput;
            _kill();
            return ec;
        }
        
        if(m_imgui){
            attach(FORWARD, m_imgui.get());
        }
        if(m_viz){
            //attach(FORWARD, m_viz.get()); // TODO
        }
        attach(FORWARD, m_widget.ptr());
        return {};
    }

    void    Viewer::_sweepwait()
    {
        if(m_viz)
            m_viz -> wait_idle();
        m_cleanup.sweep();
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
            viewerCritical << "Viewer::draw() failed ... " << ec.message();
            
        if(!snapshot.empty()){
            if(auto p = std::get_if<RasterPtr>(&u.snapshot)){
                RasterPtr   img  = *p;
                if(img){
                    img -> save_to(snapshot);
                }
            }
            if(auto p = std::get_if<std::error_code>(&u.snapshot)){
                viewerError << "Viewer::draw() snapshot failed ... " << p->message();
            }
        }
        return ec;
    }
    
    void    Viewer::receive(const post::PostCPtr& pp) 
    {
        if(!pp)
            return ;
    
        if(const ViewerBind* p = dynamic_cast<const ViewerBind*>(pp.ptr())){
            if(p->viewer() != this){
                return ;
            }
            if(!in_replay())
                forward(pp);
        } else if(!in_replay()){   
            forward(pp);
        }
        Controlling::receive(pp);
    }

    void    Viewer::tick(/* frame...eventually */)
    {
        replay(ALL);
        tick(CONTROLLERS);
        replay(ALL);
        if(m_imgui)
            m_imgui->tick();
        if(m_widget)
            m_widget -> tick();
        if((m_stage == Stage::Running) && is_visible() && !is_iconified() && (all(m_state.window.pixels) != 0)){
            draw(); // HACK (for now)
        }
        m_cleanup.sweep();
        ++m_ticks;
    }
    

    //  ----------------------------------------------------------------------------------------------------------------
    //  GENERAL INFO
    //  


        Visualizer&         Viewer::visualizer() const
        {
            assert(m_viz);
            return *m_viz;
        }



        
    //  ----------------------------------------------------------------------------------------------------------------
    //  CLOSING
    //  

        
        void    Viewer::close_command(const ViewerCloseCommand&)
        {
            if(!closing_or_kaput()){
                m_stage = Stage::Closing;
                dispatch(new WindowHideCommand(this));
            }
        }

        void    Viewer::on_close_request() 
        { 
            if(m_widget){
                m_widget -> m_flags |= Widget::F::ClosePending;
                m_widget -> on_close_request();
            } else {
                accept(CLOSE); 
            }
        }

        void    Viewer::on_hide_closing()
        {
            _sweepwait();
            // eventually... threading
            m_imgui     = {};
            _sweepwait();
            m_viz       = {};
            _sweepwait();
            dispatch(new WindowDestroyCommand(this));
        }

        void    Viewer::destroy_event(const WindowDestroyEvent&)
        {
            m_stage = Stage::Kaput;
            dispatch(new AppDeleteViewerCommand(this));
        }





    //  ----------------------------------------------------------------------------------------------------------------
    //  MOVE/POSITION
    //  

        void    Viewer::move_command(const ViewerMoveCommand& cmd)
        {
            if(started_or_running()){
                dispatch(new WindowMoveCommand(this, cmd.position()));
            }
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  SHOW/HIDE
    //  

        void    Viewer::hide_event(const WindowHideEvent&)
        {
            switch(m_stage){
            case Stage::Closing:
                on_hide_closing();
                break;
            default:
                break;
            }
        }
        

        void    Viewer::show_event(const WindowShowEvent&)
        {
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  SIZE
    //  




    //  ----------------------------------------------------------------------------------------------------------------
    //  STATE
    //  

#if 0
        void    Viewer::state_event(const WindowStateEvent&evt)
        {
            {
                XLOCK
                m_state = evt.state();
            }
            if(m_imgui){
                m_imgui->on(evt);
            }
        }
#endif



    //  ----------------------------------------------------------------------------------------------------------------
    //  WIDGET
    //  

        
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



    
    //  ----------------------------------------------------------------------------------------------------------------
    //  ----------------------------------------------------------------------------------------------------------------


#if 0
    Monitor     Viewer::monitor() const
    {
        return Monitor();
    }
#endif
#if 0
    bool        Viewer::should_close() const
    {
//        if(!m_window) 
//            return true;
        return false; // glfwWindowShouldClose(m_window);
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


    //  ----------------------------------------------------------------------------------------------------------------
    //  VULKAN/RENDER

/*
    void    Viewer::window_framebuffer_resized(const Size2I&s)
    {
        m_zeroSize  = zero_framebuffer();
        trigger_rebuild();
    }
*/

#endif

}