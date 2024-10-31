////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Viewer.hpp"

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/Application.hpp>
#include <yq/tachyon/ViewerCreateInfo.hpp>
#include <yq/tachyon/viz/ViGui.hpp>

#include <yq/tachyon/commands/ViewerCloseCommand.hpp>
#include <yq/tachyon/events/ViewerCloseEvent.hpp>
#include <yq/tachyon/exceptions/ViewerException.hpp>
#include <yq/tachyon/image/Raster.hpp>
//#include <yq/tachyon/inputs/KeyCharacter.hpp>
#include <yq/tachyon/replies/ViewerCloseReply.hpp>
#include <yq/tachyon/requests/ViewerCloseRequest.hpp>
#include <yq/tachyon/viz/ViContext.hpp>
#include <yq/tachyon/viz/Visualizer.hpp>
#include <yq/tachyon/Widget.hpp>

#include <yq/errors.hpp>
#include <yq/core/DelayInit.hpp>
#include <yq/core/ErrorDB.hpp>
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
        w.receive(&Viewer::viewer_close_request);
        w.receive(&Viewer::viewer_close_command);
    }

    //  ----------------------------------------------------------------------------------------------------------------
    //  CALLBACKS

#if 0
    void Viewer::callback_character(GLFWwindow* window, unsigned int codepoint)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_character(codepoint);
        
    }
    
    void Viewer::callback_cursor_enter(GLFWwindow* window, int entered)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_cursor_enter(entered);
    }
    
    void Viewer::callback_cursor_position(GLFWwindow* window, double xpos, double ypos)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_cursor_position(xpos, ypos);
    }
    
    void Viewer::callback_drop(GLFWwindow* window, int count, const char** paths)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_drop(count, paths);
    }
    
    void Viewer::callback_framebuffer_size(GLFWwindow* window, int width, int height)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_framebuffer_size(width, height);
    }
    
    void Viewer::callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_key(key, scancode, action, mods);
    }
    
    void Viewer::callback_mouse_button(GLFWwindow* window, int button, int action, int mods)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_mouse_button(button, action, mods);
    }
    
    void Viewer::callback_scroll(GLFWwindow* window, double xoffset, double yoffset)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_scroll(xoffset, yoffset);
    }
    
    void Viewer::callback_window_close(GLFWwindow* window)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_window_close();
    }
    
    void Viewer::callback_window_focus(GLFWwindow* window, int focused)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_window_focus(focused);
    }
    
    void Viewer::callback_window_iconify(GLFWwindow* window, int iconified)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_window_iconify(iconified);
    }
    
    void Viewer::callback_window_maximize(GLFWwindow* window, int maximized)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_window_maximize(maximized);
    }
    
    void Viewer::callback_window_position(GLFWwindow* window, int xpos, int ypos)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_window_position(xpos, ypos);
    }
    
    void Viewer::callback_window_refresh(GLFWwindow* window)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_window_refresh();
    }
    
    void Viewer::callback_window_scale(GLFWwindow* window, float xscale, float yscale)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_window_scale(xscale, yscale);
    }
    
    void Viewer::callback_window_size(GLFWwindow* window, int xsize, int ysize)
    {
        Viewer* viewer  = (Viewer*) glfwGetWindowUserPointer(window);
        if(!viewer) // shouldn't ever happen.... but
            return ;
        viewer->dispatch_window_size(xsize, ysize);
    }
#endif

    //  ----------------------------------------------------------------------------------------------------------------
    //  INITIALIZATION/DESTRUCTION

    std::atomic<int>        Viewer::s_count{0};
    std::atomic<uint64_t>   Viewer::s_lastId{1};
    
    Viewer::~Viewer()
    {
        m_cleanup.sweep();

        Application::remove(this);
        glfwDestroyWindow(m_window);
        m_widget -> m_viewer    = nullptr;
        delete m_widget;
        
        --s_count;
    }

    post::PBX::Param   Viewer::_pbx(const ViewerCreateInfo&vci)
    {
        PBX::Param  ret;
        ret.name    = "TachyonViewer";
        return ret;
    }

    Viewer::Viewer(const ViewerCreateInfo&vci, Widget*w) : post::PBX(_pbx(vci)), m_id(++s_lastId)
    {
        try {
            if(!Application::initialized())
                throw ViewerException("Application is not initialized");
            if(!w)
                throw ViewerException("Widget is required");
            
            m_widget    = w;
            
            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_FLOATING, vci.floating ? GLFW_TRUE : GLFW_FALSE);
            glfwWindowHint(GLFW_DECORATED, vci.decorated ? GLFW_TRUE : GLFW_FALSE);
            glfwWindowHint(GLFW_RESIZABLE, vci.resizable ? GLFW_TRUE : GLFW_FALSE);
            
            int wx      = std::max(1,vci.size.width());
            int wy      = std::max(1,vci.size.height());
            
            m_title     = vci.title;
            m_window    = glfwCreateWindow(wx, wy, m_title.c_str(), vci.monitor.monitor(), nullptr);
            if(!m_window){
                const char* description = nullptr;
                glfwGetError(&description);
                if(description)
                    viewerCritical << "Unable to create GLFW window.  " << description;
                throw ViewerException("GLFW window could not be instantiated");
            }

            m_viz       = std::make_unique<Visualizer>(vci, m_window, m_cleanup);
            
            if(vci.imgui)
                m_imgui= std::make_unique<ViGui>(*m_viz);
        }
        catch(...)
        {
            if(m_imgui)
                m_imgui = {};
            if(m_viz)
                m_viz   = {};
            if(m_window)
                glfwDestroyWindow(m_window);
            throw;
        }
        
        
        m_widget -> m_viewer    = this;
        connect(TX, *m_widget);
        connect(RX, *m_widget);
        
        glfwGetCursorPos(m_window, &m_cursorPos.x, &m_cursorPos.y);
        Application::add(this);
        ++s_count;
    }
    
    //  ----------------------------------------------------------------------------------------------------------------
    //  INFORMATION/GETTERS

    //  ----------------------------------------------------------------------------------------------------------------
    //  INFORMATION/GETTERS
    
    uint64_t    Viewer::frame_number() const
    {
        return m_viz -> tick();
    }

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
    
    bool        Viewer::should_close() const
    {
        if(!m_window) 
            return true;
        return glfwWindowShouldClose(m_window);
    }

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

    Widget*             Viewer::widget_at(const Vector2D& pt) const
    {
        return m_widget -> widget_at(pt);
    }

    Visualizer&         Viewer::visualizer() const
    {
        assert(m_viz);
        return *m_viz;
    }

    int  Viewer::width() const
    {
        int ret;
        glfwGetWindowSize(m_window, &ret, nullptr);
        return ret;
    }

#if 0
    bool Viewer::zero_framebuffer() const
    {
        return any(framebuffer_size()) <= 0;
    }
#endif
    
    //  ----------------------------------------------------------------------------------------------------------------
    //  GLFW EVENT DISPATCHERS
 
#if 0
    void    Viewer::dispatch_character(unsigned int code)
    {
        if(m_imgui && (!m_focus || m_focus->is_imgui())){
            ImGui_ImplGlfw_CharCallback(m_window, codepoint);
        }

#if 0
        KeyCharacter&   evt = publish(new KeyCharacter(this, m_focus, codepoint), REFERENCE);
        if(m_focus){
            m_focus->on(evt);
        }
#endif
    }
    
    void    Viewer::dispatch_cursor_enter(int)
    {
        
        
        if(viewer->m_imgui){
            ImGui_ImplGlfw_CursorEnterCallback(window, entered);
        }
        
        Vector2D    pos = viewer -> cursor_position();
        Widget* widget  = viewer -> widget_at(pos);
        
        switch(entered){
        case GLFW_TRUE:
            {
            }
            break;
        case GLFW_FALSE:
            {
            }
            break;
        }
    }
    
    void    Viewer::dispatch_cursor_position(double x, double y)
    {
        m_cursorPos     = Vector2D(x,y);
        
    }
    
    void    Viewer::dispatch_drop(int, const char**)
    {
    }
    
    void    Viewer::dispatch_framebuffer_size(int, int)
    {
    }
    
    void    Viewer::dispatch_key(int, int, int, int)
    {
    }
    
    void    Viewer::dispatch_mouse_button(int, int, int)
    {
    }
    
    void    Viewer::dispatch_scroll(double, double)
    {
    }
    
    void    Viewer::dispatch_window_close()
    {
    }
    
    void    Viewer::dispatch_window_focus(int)
    {
    }
    
    void    Viewer::dispatch_window_iconify(int)
    {
    }
    
    void    Viewer::dispatch_window_maximize(int)
    {
    }
    
    void    Viewer::dispatch_window_position(int, int)
    {
    }
    
    void    Viewer::dispatch_window_refresh()
    {
    }
    
    void    Viewer::dispatch_window_scale(float, float)
    {
    }
    
    void    Viewer::dispatch_window_size(int,int)
    {
    }
#endif    

    //  ----------------------------------------------------------------------------------------------------------------
    //  GLFW/SETTERS
    
    void        Viewer::set_flag(F f)
    {
        m_flags |= f;
    }

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

    void    Viewer::cmd_attention()
    {
        glfwRequestWindowAttention(m_window);
    }

    
    void    Viewer::cmd_focus()
    {
        glfwFocusWindow(m_window);
    }

    void    Viewer::cmd_hide()
    {
        glfwHideWindow(m_window);
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
    //  EVENT PROCESSING (BELOW, one "section" per event/command type)
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
        cmd_close();
    }
    
    void     Viewer::reject(close_t)
    {
        if(m_viewerCloseRequest){
            dispatch(new ViewerCloseReply(m_viewerCloseRequest, this, Response::Rejected));
            m_viewerCloseRequest = {};
        }
    }
    

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    YQ_INVOKE(Viewer::init_info();)
}
