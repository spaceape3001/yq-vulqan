////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Viewer.hpp"

#include <log4cpp/CategoryStream.hh>
#include <yq/tachyon/logging.hpp>

#include <yq/tachyon/api/Application.hpp>
//#include <yq/tachyon/commands/GLFWCloseCommand.hpp>
#include <yq/tachyon/commands/AppDeleteViewerCommand.hpp>
#include <yq/tachyon/commands/viewer.hpp>
#include <yq/tachyon/commands/window.hpp>

#include <yq/tachyon/core/ControllingInfoWriter.hpp>
#include <yq/tachyon/events/ViewerCloseEvent.hpp>
#include <yq/tachyon/events/ViewerPauseEvent.hpp>
#include <yq/tachyon/events/ViewerResumeEvent.hpp>
#include <yq/tachyon/events/WindowDestroyEvent.hpp>
#include <yq/tachyon/events/WindowHideEvent.hpp>
#include <yq/tachyon/events/WindowResizeEvent.hpp>
#include <yq/tachyon/events/WindowShowEvent.hpp>
#include <yq/tachyon/events/WindowStateEvent.hpp>
#include <yq/tachyon/exceptions/ViewerException.hpp>
#include <yq/tachyon/glfw/GLFWManager.hpp>
#include <yq/tachyon/image/Raster.hpp>
//#include <yq/tachyon/inputs/KeyCharacter.hpp>
#include <yq/tachyon/replies/ViewerCloseReply.hpp>
#include <yq/tachyon/replies/ViewerWidgetReply.hpp>
#include <yq/tachyon/requests/ViewerCloseRequest.hpp>
#include <yq/tachyon/requests/ViewerWidgetRequest.hpp>
#include <yq/tachyon/requests/WindowRefreshRequest.hpp>
#include <yq/tachyon/viewer/ViewerCreateInfo.hpp>
#include <yq/tachyon/viewer/ViGui.hpp>
#include <yq/tachyon/viz/ViContext.hpp>
#include <yq/tachyon/viz/Visualizer.hpp>
#include <yq/tachyon/widget/Widget.hpp>

#include <yq/errors.hpp>
#include <yq/core/ErrorDB.hpp>
#include <yq/core/ThreadId.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>
#include <yq/shape/Size2.hxx>
#include <yq/util/AutoReset.hpp>
#include <yq/vector/Vector2.hpp>

#include <backends/imgui_impl_glfw.h>

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
        
#if 0        
        w.slot(&Viewer::viewer_resize_event);
        w.property("mouse", &Viewer::mouse_state).description("Mouse state");
#endif
    }

    //  ----------------------------------------------------------------------------------------------------------------
    //  INITIALIZATION/DESTRUCTION

    std::atomic<int>        Viewer::s_count{0};
    std::atomic<uint64_t>   Viewer::s_lastNumber{0};

    Viewer::Viewer(WidgetPtr w, const ViewerCreateInfo& vci) : Viewer(w, vci, _params(vci))
    {
    }
    
    Viewer::Viewer(WidgetPtr w, const ViewerCreateInfo& vci, const Param&p)
    {
        if(!Application::initialized())
            throw ViewerException("Application is not initialized");
        if(!is_main_thread())
            throw ViewerException("Viewer being created outside main thread.");
        if(!w)
            throw ViewerException("Widget is required");
            
        m_createInfo        = std::make_unique<ViewerCreateInfo>(vci);
        m_widget                = w;
        m_widget -> m_viewer    = this;
        connect(TX, *m_widget);
        connect(RX, *m_widget);
        set_post_mode(PostMode::Queued);
        ++s_count;
    }
    
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

        Viewer::Stage   Viewer::_stage() const
        {
            return m_stage;
        }

        const Size2I&   Viewer::aspect() const
        {
            return state().window.aspect;
        }

        bool    Viewer::closing() const
        {
            return _stage() == Stage::Closing;
        }
        
        bool    Viewer::closing_or_kaput() const
        {
            Stage st = _stage();
            return (st == Stage::Closing) || (st == Stage::Kaput);
        }

        const ViewerCreateInfo&     Viewer::create_info() const
        {
            return *m_createInfo;
        }

        const Size2I&               Viewer::framebuffer_size() const
        {
            return state().window.pixels;
        }

        int         Viewer::height() const
        {
            return state().window.area.y;
        }

        bool        Viewer::is_decorated() const
        {
            return state().window.flags(WindowFlag::Decorated);
        }
        
        bool        Viewer::is_focused() const
        {
            return state().window.flags(WindowFlag::Focused);
        }
        
        bool        Viewer::is_floating() const
        {
            return state().window.flags(WindowFlag::Floating);
        }
        
        bool        Viewer::is_fullscreen() const
        {
            return state().window.monitor;
        }
        
        bool        Viewer::is_hovered() const
        {
            return state().window.flags(WindowFlag::Hovered);
        }
        
        bool        Viewer::is_iconified() const
        {
            return state().window.flags(WindowFlag::Iconified);
        }

        bool        Viewer::is_maximized() const
        {
            return state().window.flags(WindowFlag::Maximized);
        }
        
        bool        Viewer::is_resizable() const
        {
            return state().window.flags(WindowFlag::Resizable);
        }
        
        bool        Viewer::is_visible() const
        {
            return state().window.flags(WindowFlag::Visible);
        }

        bool    Viewer::kaput() const
        {
            return _stage() == Stage::Kaput;
        }
        
        bool    Viewer::never_started() const
        {
            return _stage() == Stage::Preinit;
        }

        bool    Viewer::paused() const 
        { 
            return m_paused; 
        }

        const Vector2I&   Viewer::position() const
        {
            return m_state.window.position;
        }

        bool    Viewer::running() const
        {
            return _stage() == Stage::Running;
        }

        const Size2I&   Viewer::size() const
        {
            return state().window.area;
        }

        bool    Viewer::started() const
        {
            return _stage() == Stage::Started;
        }
        
        bool    Viewer::started_or_running() const
        {
            Stage st = _stage();
            return (st == Stage::Started) || (st == Stage::Running);
        }

        const ViewerState&  Viewer::state() const
        {
            if(thread_id() == thread::id()) // same thread, horse's mouth
                return m_state;

            struct VData {
                ViewerState     state;
                uint64_t        ticks   = 0;
            };
            
            static thread_local std::map<const Viewer*,VData> tls;
            
            VData&  v   = tls[this];
            if(v.ticks != m_ticks){
                LOCK
                v.state = m_state;
                v.ticks = m_ticks;
            }
            
            return v.state;
        }

        const std::string&  Viewer::title() const
        {
            return state().window.title;
        }

        Visualizer&         Viewer::visualizer() const
        {
            assert(m_viz);
            return *m_viz;
        }

        int Viewer::width() const
        {
            return state().window.area.x;
        }

        bool Viewer::zero_framebuffer() const
        {
            return any(framebuffer_size()) <= 0;
        }


    //  ----------------------------------------------------------------------------------------------------------------
    //  ATTENTION
    //  

        void    Viewer::aspect_command(const ViewerAspectCommand&cmd)
        {
            if(started_or_running()){
                dispatch(new WindowAspectCommand(this, cmd.aspect()));
            }
        }

        void    Viewer::set_aspect(const Size2I& sz)
        {
            dispatch(SELF, new ViewerAspectCommand(this, sz));
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


    //  ----------------------------------------------------------------------------------------------------------------
    //  ATTENTION
    //  

        void    Viewer::attention_command(const ViewerAttentionCommand&)
        {
            if(m_stage == Stage::Running){
                dispatch(new WindowAttentionCommand(this));
            }
        }

        void    Viewer::cmd_attention()
        {
            dispatch(SELF, new ViewerAttentionCommand(this));
        }
        
    //  ----------------------------------------------------------------------------------------------------------------
    //  CLOSING
    //  

        void     Viewer::accept(close_t)
        {
            ViewerCloseRequestCPtr  req = assign(&Viewer::m_viewerCloseRequest, {});
            if(req){
                dispatch(new ViewerCloseReply(req, this, Response::QaPla));
                dispatch(SELF, new ViewerCloseCommand(this));
            }
        }
        
        void    Viewer::close_command(const ViewerCloseCommand&)
        {
            if(!closing_or_kaput()){
                m_stage = Stage::Closing;
                dispatch(new WindowHideCommand(this));
            }
        }

        void    Viewer::close_request(const ViewerCloseRequestCPtr& req)
        {
            if(closing_or_kaput()){
                dispatch(new ViewerCloseReply(req, this, Response::Busy));
                return ;
            }
        
            // this is the *ONLY* thread that'll be altering this
            if(m_viewerCloseRequest){
                if(m_viewerCloseRequest != req){
                    dispatch(new ViewerCloseReply(req, this, Response::Busy));
                }
                return;
            }
            
            assign(&Viewer::m_viewerCloseRequest, req);
            on_close_request();
        }

        void    Viewer::cmd_close(bool force)
        {
            if(force){
                dispatch(SELF, new ViewerCloseCommand(this));
            } else {
                dispatch(SELF, new ViewerCloseRequest(this));
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

        void     Viewer::reject(close_t)
        {
            ViewerCloseRequestCPtr  req = assign(&Viewer::m_viewerCloseRequest, {});
            if(req){
                dispatch(new ViewerCloseReply(req, this, Response::Rejected));
            }
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  CURSOR CONTROL
    //  

        void    Viewer::cmd_cursor_capture()
        {
            dispatch(SELF, new ViewerCursorCaptureCommand(this));
        }
        
        void    Viewer::cmd_cursor_disable()
        {
            dispatch(SELF, new ViewerCursorDisableCommand(this));
        }
        
        void    Viewer::cmd_cursor_hide()
        {
            dispatch(SELF, new ViewerCursorHideCommand(this));
        }
        
        void    Viewer::cmd_cursor_normal()
        {
            dispatch(SELF, new ViewerCursorNormalCommand(this));
        }

        void    Viewer::cursor_capture_command(const ViewerCursorCaptureCommand&)
        {
            if(started_or_running()){
                dispatch(new WindowCursorCaptureCommand(this));
            }
        }
        
        void    Viewer::cursor_disable_command(const ViewerCursorDisableCommand&)
        {
            if(started_or_running()){
                dispatch(new WindowCursorDisableCommand(this));
            }
        }
        
        void    Viewer::cursor_hide_command(const ViewerCursorHideCommand&)
        {
            if(started_or_running()){
                dispatch(new WindowCursorHideCommand(this));
            }
        }
        
        void    Viewer::cursor_normal_command(const ViewerCursorNormalCommand&)
        {
            if(started_or_running()){
                dispatch(new WindowCursorNormalCommand(this));
            }
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  FLOATING (ie, ALWAYS ON TOP)
    //  

        void    Viewer::cmd_float()
        {
            dispatch(SELF, new ViewerFloatCommand(this));
        }
        
        void    Viewer::cmd_unfloat()
        {
            dispatch(SELF, new ViewerUnfloatCommand(this));
        }

        void    Viewer::float_command(const ViewerFloatCommand&)
        {
            if(started_or_running()){
                dispatch(new WindowFloatCommand(this));
            }
        }
        
        void    Viewer::unfloat_command(const ViewerUnfloatCommand&)
        {
            if(started_or_running()){
                dispatch(new WindowUnfloatCommand(this));
            }
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  FOCUS
    //  

        void    Viewer::cmd_focus()
        {
            dispatch(SELF, new ViewerFocusCommand(this));
        }

        void    Viewer::focus_command(const ViewerFocusCommand&)
        {
            if(started_or_running()){
                dispatch(new WindowFocusCommand(this));
            }
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  ICONIFY
    //  

        void    Viewer::cmd_iconify()
        {
            dispatch(SELF, new ViewerIconifyCommand(this));
        }

        void    Viewer::iconify_command(const ViewerIconifyCommand&)
        {
            if(started_or_running()){
                dispatch(new WindowIconifyCommand(this));
            }
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  MAXIMIZE
    //  

        void    Viewer::cmd_maximize()
        {
            dispatch(SELF, new ViewerMaximizeCommand(this));
        }

        void    Viewer::maximize_command(const WindowMaximizeCommand&)
        {
            if(started_or_running()){
                dispatch(new WindowMaximizeCommand(this));
            }
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  MOVE/POSITION
    //  

        void    Viewer::set_position(const Vector2I&v)
        {
            dispatch(SELF, new ViewerMoveCommand(this, v));
        }

        void    Viewer::set_position(int x, int y)
        {
            set_position({x,y});
        }


        void    Viewer::move_command(const ViewerMoveCommand& cmd)
        {
            if(started_or_running()){
                dispatch(new WindowMoveCommand(this, cmd.position()));
            }
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  PAUSE/PLAY
    //  

        void    Viewer::cmd_pause()
        {
            dispatch(SELF, new ViewerPauseCommand(this));
        }
        
        void    Viewer::cmd_resume()
        {
            dispatch(SELF, new ViewerResumeCommand(this));
        }

        void    Viewer::pause_command(const ViewerPauseCommand&)
        {
            m_paused    = true;
            dispatch(new ViewerPauseEvent(this));
        }
        
        void    Viewer::resume_command(const ViewerResumeCommand&)
        {
            m_paused    = false;
            dispatch(new ViewerResumeEvent(this));
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  RESTORE
    //  

        void    Viewer::cmd_restore()
        {
            dispatch(SELF, new ViewerRestoreCommand(this));
        }

        void    Viewer::restore_command(const ViewerRestoreCommand&cmd)
        {
            if(started_or_running()){
                dispatch(new WindowRestoreCommand(this));
            }
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  SHOW/HIDE
    //  

        void    Viewer::cmd_hide()
        {
            dispatch(SELF, new ViewerHideCommand(this));
        }

        void    Viewer::cmd_show()
        {
            dispatch(SELF, new ViewerShowCommand(this));
        }

        void    Viewer::hide_command(const ViewerHideCommand&)
        {
            if(started_or_running()){
                dispatch(new WindowHideCommand(this));
            }
        }

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
        
        void    Viewer::show_command(const ViewerShowCommand&)
        {
            if(started_or_running()){
                dispatch(new WindowShowCommand(this));
            }
        }

        void    Viewer::show_event(const WindowShowEvent&)
        {
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  SIZE
    //  

        void    Viewer::set_size(const Size2I&sz)
        {
            dispatch(SELF, new ViewerSizeCommand(this, sz));
        }
        
        void    Viewer::set_size(int w, int h)
        {
            set_size({w,h});
        }

        void    Viewer::size_command(const ViewerSizeCommand& cmd)
        {
            if(started_or_running()){
                dispatch(new WindowSizeCommand(this, cmd.size()));
            }
        }


    //  ----------------------------------------------------------------------------------------------------------------
    //  STATE
    //  

        void    Viewer::state_event(const WindowStateEvent&evt)
        {
            XLOCK
            m_state = evt.state();
        }
        

    //  ----------------------------------------------------------------------------------------------------------------
    //  TITLE
    //  

        void    Viewer::set_title(std::string_view kTitle)
        {
            dispatch(SELF, new ViewerTitleCommand(this, kTitle));
        }

        void    Viewer::title_command(const ViewerTitleCommand&cmd)
        {
            if(started_or_running()){
                dispatch(new WindowTitleCommand(this, cmd.title()));
            }
        }

    //  ----------------------------------------------------------------------------------------------------------------
    //  WIDGET
    //  

        void    Viewer::_install(widget_t)
        {
            if(m_widget){
                m_widget -> m_viewer    = this;
                attach(FORWARD, m_widget.ptr());
                connect(TX, *m_widget);
                connect(RX, *m_widget);
            }
        }
        
        void    Viewer::_remove(widget_t)
        {
            if(m_widget){
                m_widget -> m_viewer    = nullptr;
                detach(FORWARD, m_widget.ptr());
                disconnect(*m_widget);
            }
        }
        
        void    Viewer::_widget(WidgetPtr w)
        {
            _remove(WIDGET);
            m_widget    = w;
            _install(WIDGET);
        }
        
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

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  OLD CODE


    //  ----------------------------------------------------------------------------------------------------------------
    //  MOUSE


    
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



}
