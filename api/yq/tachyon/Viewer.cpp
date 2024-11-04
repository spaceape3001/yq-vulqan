////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Viewer.hpp"

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/Application.hpp>
#include <yq/tachyon/GLFWManager.hpp>
#include <yq/tachyon/TachyonInfoWriter.hpp>
#include <yq/tachyon/ViewerCreateInfo.hpp>
#include <yq/tachyon/ViewerInitData.hpp>
#include <yq/tachyon/ViGui.hpp>

#include <yq/tachyon/commands/MouseCaptureCommand.hpp>
#include <yq/tachyon/commands/MouseDisableCommand.hpp>
#include <yq/tachyon/commands/MouseHideCommand.hpp>
#include <yq/tachyon/commands/MouseNormalCommand.hpp>
#include <yq/tachyon/commands/ViewerAttentionCommand.hpp>
#include <yq/tachyon/commands/ViewerCloseCommand.hpp>
#include <yq/tachyon/commands/ViewerHideCommand.hpp>
#include <yq/tachyon/commands/ViewerIconifyCommand.hpp>
#include <yq/tachyon/commands/ViewerMaximizeCommand.hpp>
#include <yq/tachyon/commands/ViewerPauseCommand.hpp>
#include <yq/tachyon/commands/ViewerRestoreCommand.hpp>
#include <yq/tachyon/commands/ViewerResumeCommand.hpp>
#include <yq/tachyon/commands/ViewerShowCommand.hpp>
#include <yq/tachyon/events/MouseCaptureEvent.hpp>
#include <yq/tachyon/events/MouseDisableEvent.hpp>
#include <yq/tachyon/events/MouseHideEvent.hpp>
#include <yq/tachyon/events/MouseNormalEvent.hpp>
#include <yq/tachyon/events/ViewerCloseEvent.hpp>
#include <yq/tachyon/events/ViewerResizeEvent.hpp>
#include <yq/tachyon/exceptions/ViewerException.hpp>
#include <yq/tachyon/Raster.hpp>
//#include <yq/tachyon/inputs/KeyCharacter.hpp>
#include <yq/tachyon/replies/ViewerCloseReply.hpp>
#include <yq/tachyon/requests/ViewerCloseRequest.hpp>
#include <yq/tachyon/viz/ViContext.hpp>
#include <yq/tachyon/viz/Visualizer.hpp>
#include <yq/tachyon/Widget.hpp>

#include <yq/errors.hpp>
#include <yq/core/DelayInit.hpp>
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

    void Viewer::init_info()
    {
        auto w = writer<Viewer>();
        w.description("Tachyon Viewer");
#if 0        
        w.receive(&Viewer::viewer_close_request);
        w.receive(&Viewer::viewer_close_command);
        w.receive(&Viewer::viewer_resize_event);
        w.property("mouse", &Viewer::mouse_state).description("Mouse state");
#endif
    }

    //  ----------------------------------------------------------------------------------------------------------------
    //  INITIALIZATION/DESTRUCTION

    std::atomic<int>        Viewer::s_count{0};
    std::atomic<uint64_t>   Viewer::s_lastId{1};
    
    Viewer::~Viewer()
    {
viewerInfo << "Viewer::~Viewer() [START]";
        disconnect(ALL);
viewerInfo << "Viewer::~Viewer() [REMOVING FROM APP]";
        Application::remove(this);
        m_cleanup.sweep();
        m_widget -> m_viewer    = nullptr;
viewerInfo << "Viewer::~Viewer() [DELETING WIDGET]";
        delete m_widget;
        m_cleanup.sweep();
viewerInfo << "Viewer::~Viewer() [CLEARING IMGUI]";
        m_imgui     = {};
        m_cleanup.sweep();
viewerInfo << "Viewer::~Viewer() [KILLING VISUALIZER]";
        m_viz       = {};
        m_cleanup.sweep();
viewerInfo << "Viewer::~Viewer() [DESTROYING GLFW WINDOW]";

        GLFWManager::remove(this);
//        glfwDestroyWindow(m_window);
        m_cleanup.sweep();
        
        --s_count;
viewerInfo << "Viewer::~Viewer() [DONE]";
    }

    Tachyon::Param   Viewer::_pbx(const ViewerCreateInfo&vci)
    {
        Tachyon::Param  ret;
        ret.name    = "Viewer";
        return ret;
    }

    Viewer::Viewer(const ViewerCreateInfo&vci, Widget*w) : Tachyon(_pbx(vci)), m_id(++s_lastId)
    {
        ViewerInitData  vid;
        try {
            if(!Application::initialized())
                throw ViewerException("Application is not initialized");
            if(!is_main_thread())
                throw ViewerException("Viewer being created outside main thread.");
            if(!w)
                throw ViewerException("Widget is required");
            
            m_widget    = w;
            
            vid = GLFWManager::create(this, vci);
            m_viz       = std::make_unique<Visualizer>(vci, vid.window, m_cleanup);
            
            if(vci.imgui)
                m_imgui= std::make_unique<ViGui>(*m_viz);
                
            m_state     = vid.state;
        }
        catch(...)
        {
            if(m_imgui)
                m_imgui = {};
            if(m_viz)
                m_viz   = {};
            if(vid.window)
                GLFWManager::remove(this);
            throw;
        }
        
        
        m_widget -> m_viewer    = this;
        connect(TX, *m_widget);
        connect(RX, *m_widget);
        
        //glfwGetCursorPos(m_window, &m_cursorPos.x, &m_cursorPos.y);
        Application::add(this);
        ++s_count;
    }

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
    
    uint64_t    Viewer::frame_number() const
    {
        return m_viz -> tick();
    }

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

    bool        Viewer::is_decorated() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_DECORATED) != 0;
    }
    
    bool        Viewer::is_focused() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_FOCUSED ) != 0;
    }
    
    bool        Viewer::is_floating() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_FLOATING) != 0;
    }
    
    bool        Viewer::is_fullscreen() const
    {
        return glfwGetWindowMonitor(m_window) != nullptr;
    }
    
    bool        Viewer::is_hovered() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_HOVERED) != 0;
    }
    
    bool        Viewer::is_iconified() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_ICONIFIED) != 0;
    }

    bool        Viewer::is_maximized() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_MAXIMIZED) != 0;
    }
    
    bool        Viewer::is_resizable() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_RESIZABLE) != 0;
    }
    
    bool        Viewer::is_visible() const
    {
        return glfwGetWindowAttrib(m_window, GLFW_VISIBLE) != 0;
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

    bool        Viewer::should_close() const
    {
//        if(!m_window) 
//            return true;
        return false; // glfwWindowShouldClose(m_window);
    }

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

    Widget*             Viewer::widget_at(const Vector2D& pt) const
    {
        return m_widget -> widget_at(pt);
    }

    Visualizer&         Viewer::visualizer() const
    {
        assert(m_viz);
        return *m_viz;
    }

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
    
    void        Viewer::set_flag(F f)
    {
        m_flags |= f;
    }
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
    
    void    Viewer::cmd_pause()
    {
        m_flags |= F::Paused;
    }

    void    Viewer::cmd_restore()
    {
        glfwRestoreWindow(m_window);
    }
    
    void    Viewer::cmd_show()
    {
        glfwShowWindow(m_window);
    }
    
    void    Viewer::cmd_unpause()
    {
        m_flags -= F::Paused;
    }
#endif

    //  ----------------------------------------------------------------------------------------------------------------
    //  VULKAN/RENDER


    //  ----------------------------------------------------------------------------------------------------------------


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

    void     Viewer::purge_deleted()
    {
        m_cleanup.sweep();
    }

/*
    void    Viewer::window_framebuffer_resized(const Size2I&s)
    {
        m_zeroSize  = zero_framebuffer();
        trigger_rebuild();
    }
*/

    void    Viewer::set_render_paused(bool v)
    {
        m_paused    = v;
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  EVENT/COMMAND/POST PROCESSING (BELOW, one "section" per event/command type)
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void    Viewer::receive(const post::PostCPtr& pp) 
    {
        if(const ViewerBind* p = dynamic_cast<const ViewerBind*>(pp.ptr())){
            if(p->viewer() != this)
                return ;
            if(m_imgui)
                m_imgui->receive(pp);
        }
        m_widget->receive(pp);
        Tachyon::receive(pp);
    }

    //  ----------------------------------------------------------------------------------------------------------------
    //  ATTENTION
    //  
#if 0
    void    Viewer::cmd_attention()
    {
        glfwRequestWindowAttention(m_window);
    }

    bool    Viewer::viewer_attention_command(const ViewerAttentionCommandCPtr&cmd)
    {
        if(!cmd)
            return false;
        if(cmd->viewer() != this)
            return false;
        cmd_attention();
        return true;
    }
#endif

    //  ----------------------------------------------------------------------------------------------------------------
    //  CLOSING
    //  

#if 0
    void    Viewer::cmd_close()
    {
        dispatch(new ViewerCloseEvent(this));
        glfwSetWindowShouldClose(m_window, GLFW_TRUE);
    }

    bool     Viewer::viewer_close_command(const ViewerCloseCommandCPtr& cmd)
    {
        if(!cmd)
            return false;
        if(cmd->viewer() != this)
            return false;
        cmd_close();
        return true;
    }
#endif

    bool     Viewer::viewer_close_request(const ViewerCloseRequestCPtr& req)
    {
        if(!req)
            return false;
        if(req->viewer() != this)
            return false;
        if(m_viewerCloseRequest){
            if(m_viewerCloseRequest != req){
                dispatch(new ViewerCloseReply(req, this, Response::Busy));
            }
            return true;
        }

        m_viewerCloseRequest    = req;
        on_close_request();
        return true;
    }

    void     Viewer::accept(close_t)
    {
        if(m_viewerCloseRequest){
            dispatch(new ViewerCloseReply(m_viewerCloseRequest, this, Response::QaPla));
            m_viewerCloseRequest = {};
        }
//        cmd_close();
    }
    
    void     Viewer::reject(close_t)
    {
        if(m_viewerCloseRequest){
            dispatch(new ViewerCloseReply(m_viewerCloseRequest, this, Response::Rejected));
            m_viewerCloseRequest = {};
        }
    }
    
    //  ----------------------------------------------------------------------------------------------------------------
    //  HIDING
    //  
#if 0
    void    Viewer::cmd_hide()
    {
        glfwHideWindow(m_window);
    }
    
    bool    Viewer::viewer_hide_command(const ViewerHideCommandCPtr& cmd)
    {
        if(!cmd)
            return false;
        if(cmd->viewer() != this)
            return false;
        cmd_hide();
        return true;
    }

    //  ----------------------------------------------------------------------------------------------------------------
    //  RESIZING
    //  

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

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    YQ_INVOKE(Viewer::init_info();)
}
