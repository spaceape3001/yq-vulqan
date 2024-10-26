////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


#include <tachyon/logging.hpp>
#include <tachyon/Application.hpp>
#include <tachyon/Viewer.hpp>
#include <tachyon/app/ViewerCreateInfo.hpp>
#include <tachyon/glfw/GLFWManager.hpp>
#include <tachyon/imgui/ViGui.hpp>
#include <tachyon/image/Raster.hpp>
//#include <tachyon/inputs/KeyCharacter.hpp>
#include <tachyon/viz/ViContext.hpp>
#include <tachyon/widget/Widget.hpp>

#include <yq/errors.hpp>
#include <yq/core/ErrorDB.hpp>
#include <yq/util/AutoReset.hpp>
#include <yq/vector/Vector2.hpp>

#include <backends/imgui_impl_glfw.h>

#include <GLFW/glfw3.h>

namespace yq::tachyon {

    //  ----------------------------------------------------------------------------------------------------------------
    //  CALLBACKS

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

    //  ----------------------------------------------------------------------------------------------------------------
    //  INITIALIZATION/DESTRUCTION

    std::atomic<int>        Viewer::s_count{0};
    std::atomic<uint64_t>   Viewer::s_lastId{1};
    
    Viewer::~Viewer()
    {
        --s_count;
        kill();
    }

    Viewer::Viewer(const ViewerCreateInfo&vci, Widget*w) : post::PBX({}), m_id(++s_lastId)
    {
        try {
            std::error_code ec = initialize(vci, w);
            if(ec){
                tachyonCritical << "Unable to initialize the viewer ... " << ec.message();
                throw ec;
            }
        
        } 
        catch(...){
            --s_count;
            rethrow;
        }
        
        ++s_count;
    }


    void    Viewer::_init(const ViewerCreateInfo&vci, Widget* w)
    {
        if(m_widget)
            return std::error_code();

        if(!w)
            return errors::null_pointer();
    
        std::error_code ec = init_window(vci);
        if(ec)
            return ec;
        ec  = init_visualizer(vci, window());
        if(ec)
            return ec;
         
        if(vci.imgui){
            m_imgui = std::make_unique<ViGui>(*this);
        }

        install_hooks();
        m_widget    = w;
        w->m_viewer = this;
        return std::error_code();
        
        
        m_cursorPos = _probe_cursor_position();
    }

    void                Viewer::_kill()
    {
        Application*    s   = Application::app();
        if(s)
            s->_remove(this);
        purge_deleted();
        if(m_widget){
            m_widget->m_viewer  = nullptr;
            delete m_widget;
        }
        m_widget    = nullptr;
        m_imgui     = {};
        kill_visualizer();
        Viewer::kill_window();
    }
    
    //  ----------------------------------------------------------------------------------------------------------------
    //  INFORMATION/GETTERS
    
    Vector2D    Viewer::_probe_cursor_position() const
    {
        Vector2D    ret;
        glfwGetCursorPos(m_window, &ret.x, &ret.y);
        return ret;
    }

    Vector2D    Viewer::cursor_position(bool probe) const
    {
        if(probe){
            return _probe_cursor_position();
        } else {
            return m_cursorPos;
        }
    }

    uint64_t    Viewer::frame_number() const
    {
        return m_viz -> tick();
    }

    Size2I  Viewer::framebuffer_size() const
    {
        Size2I  ret;
        glfwGetFramebufferSize(m_window, &ret.x, &ret.y);
        return Size2I(width, height);
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
    
    std::string_view    Viewer::title() const 
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

    bool Viewer::zero_framebuffer() const
    {
        return any(framebuffer_size()) <= 0;
    }
    
    //  ----------------------------------------------------------------------------------------------------------------
    //  GLFW EVENT DISPATCHERS
 
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

    void    Viewer::cmd_close()
    {
        glfwSetWindowShouldClose(m_window, GLFW_TRUE);
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
        auto r1 = auto_reset(u.tick, tick());
        auto r2 = auto_reset(u.viewer, this);
        auto r3 = auto_reset(u.window, static_cast<Window*>(this));
        if(m_widget && m_imgui){
            m_imgui -> draw(u, m_widget);
        }
        std::error_code ec = Visualizer::draw(u);
        auto end   = std::chrono::high_resolution_clock::now();
        m_drawTime          = (end-start).count();
        if(ec != std::error_code())
            viewCritical << "Viewer::draw() failed ... " << ec.message();
            
        if(!snapshot.empty()){
            if(auto p = std::get_if<RasterPtr>(&u.snapshot)){
                RasterPtr   img  = *p;
                if(img){
                    img -> save_to(snapshot);
                }
            }
            if(auto p = std::get_if<std::error_code>(&u.snapshot)){
                viewError << "Viewer::draw() snapshot failed ... " << p->message();
            }
        }
        //cleanup_sweep();
        return ec;
    }


    void     Viewer::prerecord(ViContext&u)
    {
        if(m_widget){
            m_widget -> prerecord(u);
        }
        if(m_imgui){
            m_imgui -> update();
        }
    }

    void     Viewer::purge_deleted()
    {
        if(!m_delete.empty()){
            for(Widget* w : m_delete)
                delete w;
            m_delete.clear();
        }
    }

    void    Viewer::record(ViContext&u)
    {
        if(m_widget)
            m_widget -> vulkan_(u);
        if(m_imgui)
            m_imgui -> record(u);
    }


    void    Viewer::window_framebuffer_resized(const Size2I&s)
    {
        m_zeroSize  = zero_framebuffer();
        trigger_rebuild();
    }

    void    Viewer::set_render_paused(bool v)
    {
        m_paused    = v;
    }

    
}
