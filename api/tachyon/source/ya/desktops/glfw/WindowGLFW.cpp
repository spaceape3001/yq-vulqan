////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/desktops/glfw/WindowGLFW.hpp>
#include <ya/desktops/glfw/LoggingGLFW.hpp>
#include <yt/logging.hpp>
#include <yt/os/WindowInfoWriter.hpp>
#include <ya/commands/WindowAspectCommand.hpp>
#include <ya/commands/WindowCursorCaptureCommand.hpp>
#include <ya/commands/WindowCursorDisableCommand.hpp>
#include <ya/commands/WindowCursorHideCommand.hpp>
#include <ya/commands/WindowCursorNormalCommand.hpp>
#include <ya/commands/WindowDestroyCommand.hpp>
#include <ya/commands/WindowFloatCommand.hpp>
#include <ya/commands/WindowTitleCommand.hpp>
#include <ya/commands/WindowUnfloatCommand.hpp>
#include <ya/commands/ui/AttentionCommand.hpp>
#include <ya/commands/ui/FocusCommand.hpp>
#include <ya/commands/ui/HideCommand.hpp>
#include <ya/commands/ui/IconifyCommand.hpp>
#include <ya/commands/ui/MaximizeCommand.hpp>
#include <ya/commands/ui/RestoreCommand.hpp>
#include <ya/commands/ui/ShowCommand.hpp>
#include <yt/os/KeyCode.hpp>
#include <ya/events/KeyCharacterEvent.hpp>
#include <ya/events/KeyPressEvent.hpp>
#include <ya/events/KeyReleaseEvent.hpp>
#include <ya/events/KeyRepeatEvent.hpp>
#include <ya/events/MouseDropEvent.hpp>
#include <ya/events/MouseEnterEvent.hpp>
#include <ya/events/MouseLeaveEvent.hpp>
#include <ya/events/MouseMoveEvent.hpp>
#include <ya/events/MousePressEvent.hpp>
#include <ya/events/MouseReleaseEvent.hpp>
#include <ya/events/MouseScrollEvent.hpp>
#include <ya/events/WindowAspectEvent.hpp>
#include <ya/events/WindowCursorCaptureEvent.hpp>
#include <ya/events/WindowCursorDisableEvent.hpp>
#include <ya/events/WindowCursorHideEvent.hpp>
#include <ya/events/WindowCursorNormalEvent.hpp>
#include <ya/events/WindowDestroyEvent.hpp>
#include <ya/events/WindowFrameBufferResizeEvent.hpp>
#include <ya/events/WindowTitleEvent.hpp>
#include <ya/events/ui/DefocusEvent.hpp>
#include <ya/events/ui/FocusEvent.hpp>
#include <ya/events/ui/HideEvent.hpp>
#include <ya/events/ui/IconifyEvent.hpp>
#include <ya/events/ui/MaximizeEvent.hpp>
#include <ya/events/ui/RestoreEvent.hpp>
#include <ya/events/ui/ShowEvent.hpp>
#include <ya/requests/WindowCloseRequest.hpp>
#include <ya/requests/WindowRefreshRequest.hpp>
#include <yq/trait/numbers.hpp>
#include <yq/math/utility.hpp>

#include <ya/desktops/glfw/DesktopGLFW.hpp>
#include <ya/desktops/glfw/LoggingGLFW.hpp>
#include <ya/desktops/glfw/MonitorGLFW.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::WindowGLFW)

namespace yq::tachyon {

    void WindowGLFW::callback_character(GLFWwindow* win, unsigned int codepoint)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        KeyCharacterEvent::Param    p;
        p.modifiers = w->modifiers(READ);
        p.code      = codepoint;
        w->send(new KeyCharacterEvent(w, p));
        w->mark();
    }
    
    void WindowGLFW::callback_cursor_enter(GLFWwindow* win, int entered)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
            
        if(entered){
            MouseEnterEvent::Param p;
            p.modifiers = w->modifiers(READ);
            p.buttons   = w->buttons(READ);
            p.position  = w->mouse(READ);
            w->send(new MouseEnterEvent(w, p));
        } else {
            MouseLeaveEvent::Param p;
            p.modifiers = w->modifiers(READ);
            p.buttons   = w->buttons(READ);
            p.position  = w->mouse(READ);
            w->send(new MouseLeaveEvent(w, p));
        }
        w->mark();
    }
    
    void WindowGLFW::callback_cursor_position(GLFWwindow* win, double xpos, double ypos)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;

        MouseMoveEvent::Param p;
        p.modifiers = w->modifiers(READ);
        p.buttons   = w->buttons(READ);
        p.position  = { xpos, ypos };
        w->send(new MouseMoveEvent(w, p));
        w->mark();
    }
    
    void WindowGLFW::callback_drop(GLFWwindow* win, int count, const char** paths)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        if(count <= 0)
            return ;
        if(!paths)
            return ;

        std::vector<std::string>    copy;
        for(int i=0;i<count;++i){
            if(!paths[i])
                continue;
            copy.push_back(std::string(paths[i]));
        }
        
        MouseDropEvent::Param p;
        p.modifiers = w->modifiers(READ);
        p.buttons   = w->buttons(READ);
        p.position  = w->mouse(READ);
        w->send(new MouseDropEvent(w, std::move(copy), p));
        w->mark();
    }
    
    void WindowGLFW::callback_framebuffer_size(GLFWwindow* win, int width, int height)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        w->send(new WindowFrameBufferResizeEvent(w, Size2I( width, height)));
        w->mark();
    }
    
    void WindowGLFW::callback_key(GLFWwindow* win, int key, int scancode, int action, int mods)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;

        switch(action){
        case GLFW_PRESS:
            {
                KeyPressEvent::Param    p;
                p.modifiers     = w->modifiers(READ);
                p.scan          = scancode;
                p.key           = keycode_glfw(key);
                w->send(new KeyPressEvent(w,p));
            }
            break;
        case GLFW_RELEASE:
            {
                KeyReleaseEvent::Param    p;
                p.modifiers     = w->modifiers(READ);
                p.scan          = scancode;
                p.key           = keycode_glfw(key);
                w->send(new KeyReleaseEvent(w,p));
            }
            break;
        case GLFW_REPEAT:
            {
                KeyRepeatEvent::Param    p;
                p.modifiers     = w->modifiers(READ);
                p.scan          = scancode;
                p.key           = keycode_glfw(key);
                w->send(new KeyRepeatEvent(w,p));
            }
            break;
        default:
            break;
        }
        w->mark();
    }
    
    void WindowGLFW::callback_mouse_button(GLFWwindow* win, int button, int action, int mods)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        
        if(action == GLFW_PRESS){
            MousePressEvent::Param p;
            p.modifiers = w->modifiers(READ);
            p.buttons   = w->buttons(READ);
            p.position  = w->mouse(READ);
            p.button    = MouseButton(button);
            w->send(new MousePressEvent(w, p));
        } else {
            MouseReleaseEvent::Param p;
            p.modifiers = w->modifiers(READ);
            p.buttons   = w->buttons(READ);
            p.position  = w->mouse(READ);
            p.button    = MouseButton(button);
            w->send(new MouseReleaseEvent(w, p));
        }
        w->mark();
    }
    
    void WindowGLFW::callback_scroll(GLFWwindow* win, double xoffset, double yoffset)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;

        MouseScrollEvent::Param p;
        p.modifiers = w->modifiers(READ);
        p.buttons   = w->buttons(READ);
        p.delta     = { xoffset, yoffset };
        w->send(new MouseScrollEvent(w, p));
        w->mark();
    }
    
    void WindowGLFW::callback_window_close(GLFWwindow* win)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
    
            // so we don't repeat this....
        glfwSetWindowShouldClose(win, GLFW_FALSE);
        w->send(new WindowCloseRequest(w));
        w->mark();
    }
    
    void WindowGLFW::callback_window_focus(GLFWwindow* win, int focused)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        if(focused){
            w->send(new FocusEvent({.source=w}));
        } else {
            w->send(new DefocusEvent({.source=w}));
        }
        w->mark();
    }
    
    void WindowGLFW::callback_window_iconify(GLFWwindow* win, int iconified)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        if(iconified){
            w->send(new IconifyEvent({.source=w}));
        } else {
            w->send(new RestoreEvent({.source=w}));
        }
        w->mark();
    }
    
    void WindowGLFW::callback_window_maximize(GLFWwindow* win, int maximized)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        if(maximized){
            w->send(new MaximizeEvent({.source=w}));
        } else {
            w->send(new RestoreEvent({.source=w}));
        }
        w->mark();
    }
    
    void WindowGLFW::callback_window_position(GLFWwindow* win, int xpos, int ypos)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
            
        w->m_position = Vector2D(xpos, ypos);
        w->mark();
        w->position(EMIT);
    }
    
    void WindowGLFW::callback_window_refresh(GLFWwindow* win)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        w->send(new WindowRefreshRequest(w));
    }
    
    void WindowGLFW::callback_window_scale(GLFWwindow* win, float xscale, float yscale)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
            
        w->m_scale  = Vector2D( xscale, yscale );
        w->mark();
        w->scale(EMIT);
    }
    
    void WindowGLFW::callback_window_size(GLFWwindow* win, int width, int height)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        
        w->m_size = Size2D( width, height );
        w->mark();
        w->size(EMIT);
    }

    WindowGLFW*  WindowGLFW::_window(GLFWwindow*w)
    {
        return  (WindowGLFW*) glfwGetWindowUserPointer(w);
    }

    WindowGLFW*  WindowGLFW::window(ptr_k, GLFWwindow* w)
    {
        return _window(w);
    }
    
    WindowID     WindowGLFW::window(GLFWwindow* w)
    {
        WindowGLFW*p    = _window(w);
        if(!p)
            return {};
        return p->id();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    WindowGLFW::WindowGLFW(DesktopGLFW* d, GLFWwindow* w, const ViewerCreateInfo & vci, const Param&p) : 
        Window(vci, p), m_desktop(d), m_window(w)
    {
        assert(w && d);
        glfwSetWindowUserPointer(w, this);
        
        glfwSetCharCallback(w, callback_character);
        glfwSetCursorEnterCallback(w, callback_cursor_enter);
        glfwSetCursorPosCallback(w, callback_cursor_position);
        glfwSetDropCallback(w, callback_drop);
        glfwSetFramebufferSizeCallback(w, callback_framebuffer_size);
        glfwSetKeyCallback(w, callback_key);
        glfwSetMouseButtonCallback(w, callback_mouse_button);
        glfwSetScrollCallback(w, callback_scroll);
        glfwSetWindowCloseCallback(w, callback_window_close);
        glfwSetWindowContentScaleCallback(w, callback_window_scale);
        glfwSetWindowFocusCallback(w, callback_window_focus);
        glfwSetWindowIconifyCallback(w, callback_window_iconify);
        glfwSetWindowMaximizeCallback(w, callback_window_maximize);
        glfwSetWindowPosCallback(w, callback_window_position);
        glfwSetWindowRefreshCallback(w, callback_window_refresh);
        glfwSetWindowSizeCallback(w, callback_window_size);
     
        m_position  = position(READ);
        m_scale     = scale(READ);
        m_size      = size(READ);
        m_stage     = Stage::Running;
    }
    
    WindowGLFW::~WindowGLFW()
    {
        m_desktop->m_windows.erase(id());
    
        glfwSetWindowUserPointer(m_window, nullptr);

        glfwSetCharCallback(m_window, nullptr);
        glfwSetCursorEnterCallback(m_window, nullptr);
        glfwSetCursorPosCallback(m_window, nullptr);
        glfwSetDropCallback(m_window, nullptr);
        glfwSetFramebufferSizeCallback(m_window, nullptr);
        glfwSetKeyCallback(m_window, nullptr);
        glfwSetMouseButtonCallback(m_window, nullptr);
        glfwSetScrollCallback(m_window, nullptr);
        glfwSetWindowCloseCallback(m_window, nullptr);
        glfwSetWindowContentScaleCallback(m_window, nullptr);
        glfwSetWindowFocusCallback(m_window, nullptr);
        glfwSetWindowIconifyCallback(m_window, nullptr);
        glfwSetWindowMaximizeCallback(m_window, nullptr);
        glfwSetWindowPosCallback(m_window, nullptr);
        glfwSetWindowRefreshCallback(m_window, nullptr);
        glfwSetWindowSizeCallback(m_window, nullptr);

        glfwDestroyWindow(m_window);
    }

    PostAdvice  WindowGLFW::advise(const Post&pp) const 
    {
        PostAdvice  pa  = Window::advise(pp);
        if(!unspecified(pa))
            return pa;
        if(dynamic_cast<const WindowCloseRequest*>(&pp))
            return MG::General;
        return {};
    }

    MouseButtons        WindowGLFW::buttons(read_k) const
    {
        MouseButtons    ret;
        if(glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
            ret |= MouseButton::Button1;
        if(glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
            ret |= MouseButton::Button2;
        if(glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_3) == GLFW_PRESS)
            ret |= MouseButton::Button3;
        if(glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_4) == GLFW_PRESS)
            ret |= MouseButton::Button4;
        if(glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_5) == GLFW_PRESS)
            ret |= MouseButton::Button5;
        if(glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_6) == GLFW_PRESS)
            ret |= MouseButton::Button6;
        if(glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_7) == GLFW_PRESS)
            ret |= MouseButton::Button7;
        if(glfwGetMouseButton(m_window, GLFW_MOUSE_BUTTON_8) == GLFW_PRESS)
            ret |= MouseButton::Button8;
        return ret;
    }

    WindowFlags         WindowGLFW::flags(read_k) const
    {
        WindowFlags ret;
        ret.set(WindowFlag::AutoIconify,       static_cast<bool>(glfwGetWindowAttrib(m_window, GLFW_AUTO_ICONIFY)));
        ret.set(WindowFlag::Decorated,         static_cast<bool>(glfwGetWindowAttrib(m_window, GLFW_DECORATED)));
        ret.set(WindowFlag::Floating,          static_cast<bool>(glfwGetWindowAttrib(m_window, GLFW_FLOATING)));
        ret.set(WindowFlag::Focused,           static_cast<bool>(glfwGetWindowAttrib(m_window, GLFW_FOCUSED)));
        ret.set(WindowFlag::FocusOnShow,       static_cast<bool>(glfwGetWindowAttrib(m_window, GLFW_FOCUS_ON_SHOW)));
        ret.set(WindowFlag::Hovered,           static_cast<bool>(glfwGetWindowAttrib(m_window, GLFW_HOVERED)));
        ret.set(WindowFlag::Iconified,         static_cast<bool>(glfwGetWindowAttrib(m_window, GLFW_ICONIFIED)));
        ret.set(WindowFlag::Maximized,         static_cast<bool>(glfwGetWindowAttrib(m_window, GLFW_MAXIMIZED)));
        ret.set(WindowFlag::MousePassThrough,  static_cast<bool>(glfwGetWindowAttrib(m_window, GLFW_MOUSE_PASSTHROUGH)));
        ret.set(WindowFlag::Resizable,         static_cast<bool>(glfwGetWindowAttrib(m_window, GLFW_RESIZABLE)));
        ret.set(WindowFlag::Transparent,       static_cast<bool>(glfwGetWindowAttrib(m_window, GLFW_TRANSPARENT_FRAMEBUFFER)));
        ret.set(WindowFlag::Visible,           static_cast<bool>(glfwGetWindowAttrib(m_window, GLFW_VISIBLE)));
        return ret;
    }

    Size2I              WindowGLFW::framebuffer(read_k) const
    {
        Size2I  ret;
        glfwGetFramebufferSize(m_window, &ret.x, &ret.y);
        return ret;
    }

    namespace {
        std::pair<int,double>   filter(double v)
        {
            if(is_nan(v) || (v < 0.5)){
                return { -1, NaN };
            } else {
                return { iround(v), v };
            }
        }
    }
    
    void    WindowGLFW::max_size(set_k, const Size2D& sz) 
    {
        auto [i,x]  = filter(sz.x);
        auto [j,y]  = filter(sz.y);

        glfwSetWindowSizeLimits(m_window, m_minSize.x, m_minSize.y, i, j);
        m_maxSize   = { i, j };
        AMaxSize²::max_size(SET, Size2D(x,y));
    }
    
    void    WindowGLFW::min_size(set_k, const Size2D& sz) 
    {
        auto [i,x]  = filter(sz.x);
        auto [j,y]  = filter(sz.y);
        glfwSetWindowSizeLimits(m_window, i, j, m_maxSize.x, m_maxSize.y);
        AMinSize²::min_size(SET, Size2D(x,y));
    }
    
    ModifierKeys        WindowGLFW::modifiers(read_k) const
    {
        ModifierKeys    ret;
        if(glfwGetKey(m_window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
            ret |= ModifierKey::AltLeft;
        if(glfwGetKey(m_window, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS)
            ret |= ModifierKey::AltRight;
        if(glfwGetKey(m_window, GLFW_KEY_CAPS_LOCK) == GLFW_PRESS)
            ret |= ModifierKey::CapsLock;
        if(glfwGetKey(m_window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
            ret |= ModifierKey::ControlLeft;
        if(glfwGetKey(m_window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS)
            ret |= ModifierKey::ControlRight;
        if(glfwGetKey(m_window, GLFW_KEY_NUM_LOCK) == GLFW_PRESS)
            ret |= ModifierKey::NumLock;
        if(glfwGetKey(m_window, GLFW_KEY_SCROLL_LOCK) == GLFW_PRESS)
            ret |= ModifierKey::ScrollLock;
        if(glfwGetKey(m_window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            ret |= ModifierKey::ShiftLeft;
        if(glfwGetKey(m_window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS)
            ret |= ModifierKey::ShiftRight;
        if(glfwGetKey(m_window, GLFW_KEY_LEFT_SUPER) == GLFW_PRESS)
            ret |= ModifierKey::SuperLeft;
        if(glfwGetKey(m_window, GLFW_KEY_RIGHT_SUPER) == GLFW_PRESS)
            ret |= ModifierKey::SuperRight;
        return ret;
    }

    Vector2D  WindowGLFW::mouse(read_k) const
    {
        Vector2D ret;
        glfwGetCursorPos(m_window, &ret.x, &ret.y);
        return ret;
    }

    void    WindowGLFW::on_aspect_command(const WindowAspectCommand&cmd)
    {
        if(m_aspect == cmd.aspect())
            return ;
    
        glfwSetWindowAspectRatio(m_window, cmd.width(), cmd.height());
        send(new WindowAspectEvent(this, cmd.aspect()));
        mark();
    }

    void    WindowGLFW::on_attention_command(const AttentionCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
            
        glfwRequestWindowAttention(m_window);
    }

    void    WindowGLFW::on_cursor_capture_command(const WindowCursorCaptureCommand&)
    {
        if(m_mouseMode == MouseMode::Captured)
            return;
        m_mouseMode = MouseMode::Captured;
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_CAPTURED);
        send(new WindowCursorCaptureEvent(this));
        mark();
    }
    
    void    WindowGLFW::on_cursor_disable_command(const WindowCursorDisableCommand&)
    {
        if(m_mouseMode == MouseMode::Disabled)
            return ;
        m_mouseMode = MouseMode::Disabled;
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        send(new WindowCursorDisableEvent(this));
        mark();
    }
    
    void    WindowGLFW::on_cursor_hide_command(const WindowCursorHideCommand&)
    {
        if(m_mouseMode == MouseMode::Hidden)
            return ;
        m_mouseMode = MouseMode::Hidden;
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        send(new WindowCursorHideEvent(this));
        mark();
    }
    
    void    WindowGLFW::on_cursor_normal_command(const WindowCursorNormalCommand&)
    {
        if(m_mouseMode == MouseMode::Normal)
            return ;
        m_mouseMode = MouseMode::Normal;
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        send(new WindowCursorNormalEvent(this));
        mark();
    }

    void    WindowGLFW::on_destroy_command(const WindowDestroyCommand& cmd)
    {
        m_stage = Stage::Destruct;
    }

    void    WindowGLFW::on_float_command(const WindowFloatCommand&cmd)
    {
        glfwSetWindowAttrib(m_window, GLFW_FLOATING, GLFW_TRUE);
        mark();
    }

    void    WindowGLFW::on_focus_command(const FocusCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        glfwFocusWindow(m_window);
        mark();
    }

    void    WindowGLFW::on_hide_command(const HideCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(!glfwGetWindowAttrib(m_window, GLFW_VISIBLE))
            return ;
        glfwHideWindow(m_window);
        send(new HideEvent({.source=this}));
        mark();
    }
    
    void    WindowGLFW::on_iconify_command(const IconifyCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        glfwIconifyWindow(m_window);
        mark();
    }
    
    void    WindowGLFW::on_maximize_command(const MaximizeCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        glfwMaximizeWindow(m_window);
        mark();
    }
    
    void    WindowGLFW::on_restore_command(const RestoreCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        glfwRestoreWindow(m_window);
        mark();
    }

    void    WindowGLFW::on_show_command(const ShowCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(glfwGetWindowAttrib(m_window, GLFW_VISIBLE))
            return ;
        glfwShowWindow(m_window);
        send(new ShowEvent({.source=this}));
        mark();
    }

    void    WindowGLFW::on_title_command(const WindowTitleCommand&cmd)
    {
        glfwSetWindowTitle(m_window, cmd.title().c_str());
        send(new WindowTitleEvent(this, cmd.title()));
        mark();
    }
    
    void    WindowGLFW::on_unfloat_command(const WindowUnfloatCommand&cmd)
    {
        glfwSetWindowAttrib(m_window, GLFW_FLOATING, GLFW_FALSE);
        mark();
    }


    Vector2D    WindowGLFW::position(read_k) const 
    {
        Vector2I    ret;
        glfwGetWindowPos(m_window, &ret.x, &ret.y);
        return ret.cast<double>();
    }
    
    void    WindowGLFW::position(set_k, const Vector2D& ps) 
    {
        if(is_nan(ps.x))
            return ;
        if(is_nan(ps.y))
            return ;
        glfwSetWindowPos(m_window, iround(ps.x), iround(ps.y));
    }

    Vector2D  WindowGLFW::scale(read_k) const
    {
        float x, y;
        glfwGetWindowContentScale(m_window, &x, &y);
        return Vector2D(x,y);
    }
    
    void    WindowGLFW::scale(set_k, const Vector2D&) 
    {
        /* OS DRIVEN, CANNOT CHANGE */
    }
    
    void    WindowGLFW::size(set_k, const Size2D& sz) 
    {
        if(is_nan(sz.x))
            return ;
        if(is_nan(sz.y))
            return ;
        
        int i   = iround(sz.x);
        if((i<=0) || ((m_minSize.x > 0) && (i < m_minSize.x)) || ((m_maxSize.x > 0) && (i > m_maxSize.x))){
            return ;
        }
        
        int j   = iround(sz.y);
        if((j<=0) || ((m_minSize.y > 0) && (j < m_minSize.y)) || ((m_maxSize.y > 0) && (j > m_maxSize.y))){
            return;
        }
    
        glfwSetWindowSize(m_window, i, j);
    }

    Size2D    WindowGLFW::size(read_k) const
    {
        int x, y;
        glfwGetWindowSize(m_window, &x, &y);
        return Size2D(x,y);
    }

    void      WindowGLFW::snap(WindowSnap& sn) const
    {
        Window::snap(sn);

        for(KeyCode kc : KeyCode::all_values()){
            int gk  = encode_glfw(kc);
            if(gk == GLFW_KEY_UNKNOWN)
                continue;
            sn.keyboard.keys.set((int) kc.value(), glfwGetKey(m_window, gk) == GLFW_PRESS);
        }

        sn.keyboard.modifiers   = modifiers(READ);
        sn.mouse.buttons        = buttons(READ);
        sn.mouse.position       = mouse(READ);
        sn.mouse.mode           = m_mouseMode;
        
        sn.window.area          = m_size;
        sn.window.aspect        = m_aspect;
        sn.window.flags         = flags(READ);
        sn.window.max           = m_maxSize;
        sn.window.min           = m_minSize;
        sn.window.monitor       = MonitorGLFW::monitor(glfwGetWindowMonitor(m_window));
        sn.window.opacity       = glfwGetWindowOpacity(m_window);
        sn.window.pixels        = framebuffer(READ);
        sn.window.position      = m_position;
        sn.window.scale         = m_scale;
        sn.window.title         = title(READ);

        sn.time             = glfwGetTime();
    }

    Execution WindowGLFW::tick(Context&ctx) 
    {
        Window::tick(ctx);
        if(m_stage == Stage::Destruct){
            send(new WindowDestroyEvent(this));
            return DELETE;
        }
        
        //  TODO
        
        return {};
    }

    std::string         WindowGLFW::title(read_k) const
    {
        return glfwGetWindowTitle(m_window);
    }

    //std::string_view    WindowGLFW::title() const
    //{
    //}
    
    //void                WindowGLFW::title(const std::string&)
    //{
    //}

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void WindowGLFW::init_info()
    {
        auto w = writer<WindowGLFW>();
        w.description("GLFW Window");
        w.interface<IPosition²>();
        w.slot(&WindowGLFW::on_aspect_command);
        w.slot(&WindowGLFW::on_attention_command);
        w.slot(&WindowGLFW::on_cursor_capture_command);
        w.slot(&WindowGLFW::on_cursor_disable_command);
        w.slot(&WindowGLFW::on_cursor_hide_command);
        w.slot(&WindowGLFW::on_cursor_normal_command);
        w.slot(&WindowGLFW::on_destroy_command);
        w.slot(&WindowGLFW::on_float_command);
        w.slot(&WindowGLFW::on_focus_command);
        w.slot(&WindowGLFW::on_hide_command);
        w.slot(&WindowGLFW::on_iconify_command);
        w.slot(&WindowGLFW::on_maximize_command);
        w.slot(&WindowGLFW::on_restore_command);
        w.slot(&WindowGLFW::on_show_command);
        w.slot(&WindowGLFW::on_title_command);
        w.slot(&WindowGLFW::on_unfloat_command);
    }
}
