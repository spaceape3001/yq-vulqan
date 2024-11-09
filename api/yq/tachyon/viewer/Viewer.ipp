////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Viewer.hpp"

#include <log4cpp/CategoryStream.hh>
#include <yq/tachyon/logging.hpp>

#include <yq/tachyon/app/Application.hpp>
//#include <yq/tachyon/commands/GLFWCloseCommand.hpp>
#include <yq/tachyon/commands/AppDeleteViewerCommand.hpp>
#include <yq/tachyon/commands/MouseCaptureCommand.hpp>
#include <yq/tachyon/commands/MouseDisableCommand.hpp>
#include <yq/tachyon/commands/MouseHideCommand.hpp>
#include <yq/tachyon/commands/MouseNormalCommand.hpp>
#include <yq/tachyon/commands/ViewerAttentionCommand.hpp>
#include <yq/tachyon/commands/ViewerCloseCommand.hpp>
#include <yq/tachyon/commands/ViewerHideCommand.hpp>
#include <yq/tachyon/commands/ViewerPauseCommand.hpp>
#include <yq/tachyon/commands/ViewerResumeCommand.hpp>
#include <yq/tachyon/commands/ViewerShowCommand.hpp>
#include <yq/tachyon/commands/WindowAttentionCommand.hpp>
#include <yq/tachyon/commands/WindowDestroyCommand.hpp>
#include <yq/tachyon/commands/WindowHideCommand.hpp>
#include <yq/tachyon/commands/WindowIconifyCommand.hpp>
#include <yq/tachyon/commands/WindowMaximizeCommand.hpp>
#include <yq/tachyon/commands/WindowMoveCommand.hpp>
#include <yq/tachyon/commands/WindowRestoreCommand.hpp>
#include <yq/tachyon/commands/WindowShowCommand.hpp>
#include <yq/tachyon/core/TachyonInfoWriter.hpp>
#include <yq/tachyon/events/MouseCaptureEvent.hpp>
#include <yq/tachyon/events/MouseDisableEvent.hpp>
#include <yq/tachyon/events/MouseHideEvent.hpp>
#include <yq/tachyon/events/MouseNormalEvent.hpp>
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
#include <yq/tachyon/requests/ViewerCloseRequest.hpp>
#include <yq/tachyon/viewer/ViewerCreateInfo.hpp>
#include <yq/tachyon/viewer/ViGui.hpp>
#include <yq/tachyon/viz/ViContext.hpp>
#include <yq/tachyon/viz/Visualizer.hpp>
#include <yq/tachyon/widget/Widget.hpp>

#include <yq/errors.hpp>
#include <yq/core/ErrorDB.hpp>
#include <yq/core/ThreadId.hpp>
#include <yq/post/PBXInfoWriter.hpp>
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

    Tachyon::Param   Viewer::_pbx(const ViewerCreateInfo&vci)
    {
        Tachyon::Param  ret;
        ret.name    = "Viewer";
        return ret;
    }

    void Viewer::init_info()
    {
        auto w = writer<Viewer>();
        
        w.description("Tachyon Viewer");
        w.property("ticks", &Viewer::ticks).description("Total number of ticks so far");
        
        w.receive(&Viewer::attention_command).name("attention_command");
        w.receive(&Viewer::close_command).name("close_command");
        w.receive(&Viewer::close_request).name("close_request");
        w.receive(&Viewer::destroy_event).name("destroy_event");
        w.receive(&Viewer::hide_command).name("hide_command");
        w.receive(&Viewer::hide_event).name("hide_event");
        w.receive(&Viewer::pause_command).name("pause_command");
        w.receive(&Viewer::resume_command).name("resume_command");
        w.receive(&Viewer::show_command).name("show_command");
        w.receive(&Viewer::show_event).name("show_event");
        w.receive(&Viewer::state_event).name("state_event");
        
#if 0        
        w.receive(&Viewer::viewer_resize_event);
        w.property("mouse", &Viewer::mouse_state).description("Mouse state");
#endif
    }

    //  ----------------------------------------------------------------------------------------------------------------
    //  INITIALIZATION/DESTRUCTION

    std::atomic<int>        Viewer::s_count{0};
    std::atomic<uint64_t>   Viewer::s_lastId{0};

    Viewer::Viewer(const ViewerCreateInfo&vci, WidgetPtr w) : Tachyon(_pbx(vci)), m_id(++s_lastId)
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
        m_widget    = {};
        m_cleanup.sweep();
        --s_count;
    }

    void    Viewer::_kill()
    {
        if(m_imgui)
            m_imgui = {};
        if(m_viz)
            m_viz   = {};
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
        
        m_stage = Stage::Started;
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
            if(m_imgui && !in_replay())  
                m_imgui->receive(pp);
            
        } else if(!in_replay()){   
            m_widget->receive(pp);
        }
        Tachyon::receive(pp);
    }

    void    Viewer::tick(/* frame...eventually */)
    {
        replay(ALL);
        if(m_imgui)
            m_imgui->tick();
        if(m_widget)
            m_widget -> tick();
        if((m_stage == Stage::Running) && is_visible() && !is_iconified()){
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

        Visualizer&         Viewer::visualizer() const
        {
            assert(m_viz);
            return *m_viz;
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
    //  SHOW/HIDE
    //  

    void    Viewer::cmd_hide()
    {
        if(m_stage == Stage::Running){
            dispatch(new WindowHideCommand(this));
        }
    }

    void    Viewer::cmd_show()
    {
        if(m_stage == Stage::Running){
            dispatch(new WindowShowCommand(this));
        }
    }

    void    Viewer::hide_command(const ViewerHideCommand&)
    {
        cmd_hide();
    }

    void    Viewer::hide_event(const WindowHideEvent&)
    {
        switch(m_stage){
        case Stage::Closing:
            on_hide_closing();
            break;
        case Stage::Started:
        case Stage::Running:
            break;
        default:
            break;
        }
    }
    
    void    Viewer::show_command(const ViewerShowCommand&)
    {
        cmd_show();
    }

    void    Viewer::show_event(const WindowShowEvent&)
    {
        switch(m_stage){
        case Stage::Started:
        case Stage::Running:
            break;
        default:
            break;
        }
    }


    //  ----------------------------------------------------------------------------------------------------------------
    //  STATE
    //  

    void    Viewer::set_position(int x, int y)
    {
        dispatch(new WindowMoveCommand(this, {x,y}));
    }

    void    Viewer::state_event(const WindowStateEvent&evt)
    {
        XLOCK
        m_state = evt.state();
    }
    


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  OLD CODE


    //  ----------------------------------------------------------------------------------------------------------------
    //  MOUSE

#if 0
        void    Viewer::cmd_mouse_capture()
        {
            glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_CAPTURED);
            m_mouseState    = MouseMode::Captured;
            dispatch(new MouseCaptureEvent(this));
        }
        
        void    Viewer::cmd_mouse_disable()
        {
            glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
            m_mouseState    = MouseMode::Disabled;
            dispatch(new MouseDisableEvent(this));
        }
        
        void    Viewer::cmd_mouse_hide()
        {
            glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
            m_mouseState    = MouseMode::Hidden;
            dispatch(new MouseHideEvent(this));
        }
        
        void    Viewer::cmd_mouse_normal()
        {
            glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
            m_mouseState    = MouseMode::Normal;
            dispatch(new MouseNormalEvent(this));
        }

        bool    Viewer::mouse_capture_command(const MouseCaptureCommandCPtr&cmd)
        {
            if(!cmd)
                return false;
            if(cmd->viewer() != this)
                return false;
            cmd_mouse_capture();
            return true;
        }
        
        bool    Viewer::mouse_disable_command(const MouseDisableCommandCPtr&cmd)
        {
            if(!cmd)
                return false;
            if(cmd->viewer() != this)
                return false;
            cmd_mouse_disable();
            return true;
        }
        
        bool    Viewer::mouse_hide_command(const MouseHideCommandCPtr&cmd)
        {
            if(!cmd)
                return false;
            if(cmd->viewer() != this)
                return false;
            cmd_mouse_hide();
            return true;
        }
        
        bool    Viewer::mouse_normal_command(const MouseNormalCommandCPtr&cmd)
        {
            if(!cmd)
                return false;
            if(cmd->viewer() != this)
                return false;
            cmd_mouse_normal();
            return true;
        }
#endif

    
    //  ----------------------------------------------------------------------------------------------------------------
    //  INFORMATION/GETTERS

    //  ----------------------------------------------------------------------------------------------------------------
    //  INFORMATION/GETTERS



#if 0
    Size2I  Viewer::framebuffer_size() const
    {
        Size2I  ret;
        glfwGetFramebufferSize(m_window, &ret.x, &ret.y);
        return ret;
    }
    
    int  Viewer::height() const
    {
        int ret;
        glfwGetWindowSize(m_window, nullptr, &ret);
        return ret;
    }


    Monitor     Viewer::monitor() const
    {
        return Monitor();
    }

    Vector2I    Viewer::position() const
    {
        Vector2I   ret;
        glfwGetWindowPos(m_window, &ret.x, &ret.y);
        return ret;
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
    Size2I      Viewer::size() const
    {
        Size2I  ret;
        glfwGetWindowSize(m_window, &ret.x, &ret.y);
        return ret;
    }
    
    std::string    Viewer::title() const 
    { 
        return m_title; 
    }
#endif
#if 0
    Widget*             Viewer::widget_at(const Vector2D& pt) const
    {
        return m_widget -> widget_at(pt);
    }
#endif

#if 0
    int  Viewer::width() const
    {
        int ret;
        glfwGetWindowSize(m_window, &ret, nullptr);
        return ret;
    }
#endif
#if 0
    bool Viewer::zero_framebuffer() const
    {
        return any(framebuffer_size()) <= 0;
    }
#endif
    
    //  ----------------------------------------------------------------------------------------------------------------
    //  GLFW EVENT DISPATCHERS
 


    //  ----------------------------------------------------------------------------------------------------------------
    //  GLFW/SETTERS
    
#if 0
    void        Viewer::set_position(int x, int y)
    {
        glfwSetWindowPos(m_window, x, y);
    }

    void        Viewer::set_position(const Vector2I& pos)
    {
        set_position(pos.x, pos.y);
    }

    void        Viewer::set_size(const Size2I& sz)
    {
        set_size(sz.x, sz.y);
    }

    void        Viewer::set_size(int w, int h)
    {
        glfwSetWindowSize(m_window, std::max(1, w), std::max(1, h));
    }
    
    void        Viewer::set_title(std::string_view txt)
    {
        m_title = std::string(txt);
        glfwSetWindowTitle(m_window, m_title.c_str());
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
    //  COMMANDS


#if 0    
    void    Viewer::cmd_focus()
    {
        glfwFocusWindow(m_window);
    }

    void    Viewer::cmd_iconify()
    {
        glfwIconifyWindow(m_window);
    }
    
    void    Viewer::cmd_maximize()
    {
        glfwMaximizeWindow(m_window);
    }
    
    void    Viewer::cmd_restore()
    {
        glfwRestoreWindow(m_window);
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


    //  ----------------------------------------------------------------------------------------------------------------
    //  RESIZING
    //  

#if 0
    bool     Viewer::viewer_resize_event(const ViewerResizeEventCPtr& evt)
    {
        if(!evt)
            return false;
        if(evt->viewer() != this)
            return false;
            
        // TODO
        
        return false;
    }
#endif


}
