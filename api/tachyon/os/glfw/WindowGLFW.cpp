////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/glfw/WindowGLFW.hpp>
#include <tachyon/os/glfw/LoggingGLFW.hpp>
#include <yt/logging.hpp>
#include <yt/os/WindowInfoWriter.hpp>
#include <ya/commands/cursor/CursorCaptureCommand.hpp>
#include <ya/commands/cursor/CursorDisableCommand.hpp>
#include <ya/commands/cursor/CursorHideCommand.hpp>
#include <ya/commands/cursor/CursorNormalCommand.hpp>
#include <ya/commands/ui/AspectCommand.hpp>
#include <ya/commands/ui/AttentionCommand.hpp>
#include <ya/commands/ui/FloatCommand.hpp>
#include <ya/commands/ui/FocusCommand.hpp>
#include <ya/commands/ui/HideCommand.hpp>
#include <ya/commands/ui/IconifyCommand.hpp>
#include <ya/commands/ui/MaximizeCommand.hpp>
#include <ya/commands/ui/RestoreCommand.hpp>
#include <ya/commands/ui/ShowCommand.hpp>
#include <ya/commands/ui/TitleCommand.hpp>
#include <ya/commands/ui/UnfloatCommand.hpp>
#include <yt/os/KeyCode.hpp>
#include <ya/events/GamepadEvent.hpp>
#include <ya/events/JoystickEvent.hpp>
#include <ya/events/cursor/CursorCaptureEvent.hpp>
#include <ya/events/cursor/CursorDisableEvent.hpp>
#include <ya/events/cursor/CursorHideEvent.hpp>
#include <ya/events/cursor/CursorNormalEvent.hpp>
#include <ya/events/keyboard/KeyCharacterEvent.hpp>
#include <ya/events/keyboard/KeyPressEvent.hpp>
#include <ya/events/keyboard/KeyReleaseEvent.hpp>
#include <ya/events/keyboard/KeyRepeatEvent.hpp>
#include <ya/events/mouse/MouseDropEvent.hpp>
#include <ya/events/mouse/MouseEnterEvent.hpp>
#include <ya/events/mouse/MouseLeaveEvent.hpp>
#include <ya/events/mouse/MouseMoveEvent.hpp>
#include <ya/events/mouse/MousePressEvent.hpp>
#include <ya/events/mouse/MouseReleaseEvent.hpp>
#include <ya/events/mouse/MouseScrollEvent.hpp>
#include <ya/events/ui/AspectEvent.hpp>
#include <ya/events/ui/DefocusEvent.hpp>
#include <ya/events/ui/FocusEvent.hpp>
#include <ya/events/ui/HideEvent.hpp>
#include <ya/events/ui/IconifyEvent.hpp>
#include <ya/events/ui/MaximizeEvent.hpp>
#include <ya/events/ui/RestoreEvent.hpp>
#include <ya/events/ui/ShowEvent.hpp>
#include <ya/events/ui/TitleEvent.hpp>
#include <ya/events/window/FramebufferResizeEvent.hpp>
#include <ya/requests/ui/CloseRequest.hpp>
#include <ya/requests/ui/RefreshRequest.hpp>
#include <yq/trait/numbers.hpp>
#include <yq/math/utility.hpp>
#include <yt/app/ViewerCreateInfo.hpp>

#include <tachyon/os/glfw/DesktopGLFW.hpp>
#include <tachyon/os/glfw/LoggingGLFW.hpp>
#include <tachyon/os/glfw/MonitorGLFW.hpp>
#include <tachyon/vulkan/VulqanManager.hpp>
#include <tachyon/vulkan/ViSurface.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::WindowGLFW)

namespace yq::tachyon {

    void WindowGLFW::callback_character(GLFWwindow* win, unsigned int codepoint)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        w->send(new KeyCharacterEvent({.source=w}, w->modifiers(READ), codepoint));
        w->mark();
    }
    
    void WindowGLFW::callback_cursor_enter(GLFWwindow* win, int entered)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
            
        if(entered){
            w->send(new MouseEnterEvent({.source=w}, w->modifiers(READ), w->mouse(READ), w->buttons(READ)));
        } else {
            w->send(new MouseLeaveEvent({.source=w}, w->modifiers(READ), w->mouse(READ), w->buttons(READ)));
        }
        w->mark();
    }
    
    void WindowGLFW::callback_cursor_position(GLFWwindow* win, double xpos, double ypos)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;

        w->send(new MouseMoveEvent({.source=w}, w->modifiers(READ), Vector2D(xpos, ypos), w->buttons(READ)));
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
        
        w->send(new MouseDropEvent({.source=w}, w->modifiers(READ), w->mouse(READ), w->buttons(READ), std::move(copy)));
        w->mark();
    }
    
    void WindowGLFW::callback_framebuffer_size(GLFWwindow* win, int width, int height)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        w->send(new FramebufferResizeEvent({.source=w}, Size2I( width, height)));
        w->mark();
    }
    
    void WindowGLFW::callback_key(GLFWwindow* win, int key, int scancode, int action, int mods)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;

        switch(action){
        case GLFW_PRESS:
            w->send(new KeyPressEvent({.source=w}, w->modifiers(READ), scancode, keycode_glfw(key)));
            break;
        case GLFW_RELEASE:
            w->send(new KeyReleaseEvent({.source=w}, w->modifiers(READ), scancode, keycode_glfw(key)));
            break;
        case GLFW_REPEAT:
            w->send(new KeyRepeatEvent({.source=w}, w->modifiers(READ), scancode, keycode_glfw(key)));
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
            w->send(new MousePressEvent({.source=w}, w->modifiers(READ), w->mouse(READ), w->buttons(READ), MouseButton(button)));
        } else {
            w->send(new MouseReleaseEvent({.source=w}, w->modifiers(READ), w->mouse(READ), w->buttons(READ), MouseButton(button)));
        }
        w->mark();
    }
    
    void WindowGLFW::callback_scroll(GLFWwindow* win, double xoffset, double yoffset)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;

        w->send(new MouseScrollEvent({.source=w}, 
            w->modifiers(READ), w->mouse(READ), w->buttons(READ), Vector2D(xoffset, yoffset)
        ));
        w->mark();
    }
    
    void WindowGLFW::callback_window_close(GLFWwindow* win)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
    
            // so we don't repeat this....
        glfwSetWindowShouldClose(win, GLFW_FALSE);
        w->send(new CloseRequest({.source=w}));
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
        w->send(new RefreshRequest({.source=w}));
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

        //  TODO... more on window modes...

    WindowGLFW::WindowGLFW(DesktopGLFW* d, GLFWwindow* w, const ViewerCreateInfo & vci) : 
        Window(vci), m_desktop(d), m_window(w)
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
     
        m_position      = position(READ);
        m_scale         = scale(READ);
        m_size          = size(READ);
        m_stage         = Stage::Running;
        m_windowMode    = vci.wmode;
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
        if(dynamic_cast<const CloseRequest*>(&pp))
            return MG::General;
        if(dynamic_cast<const GamepadEvent*>(&pp))
            return MG::General;
        if(dynamic_cast<const JoystickEvent*>(&pp))
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

    ViSurfacePtr    WindowGLFW::create_surface() const 
    {
        VkSurfaceKHR    surface = nullptr;
        VkResult    result = glfwCreateWindowSurface(VulqanManager::instance(), m_window, nullptr, &surface);
        if(result != VK_SUCCESS)
            return {};
        return new ViSurface(surface);
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

    void    WindowGLFW::on_aspect_command(const AspectCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(m_aspect == cmd.aspect())
            return ;
    
        glfwSetWindowAspectRatio(m_window, cmd.width(), cmd.height());
        send(new AspectEvent({.source=this}, cmd.aspect()));
        mark();
    }

    void    WindowGLFW::on_attention_command(const AttentionCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
            
        glfwRequestWindowAttention(m_window);
    }

    void    WindowGLFW::on_cursor_capture_command(const CursorCaptureCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(m_mouseMode == MouseMode::Captured)
            return;
        m_mouseMode = MouseMode::Captured;
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_CAPTURED);
        send(new CursorCaptureEvent({.source=this}));
        mark();
    }
    
    void    WindowGLFW::on_cursor_disable_command(const CursorDisableCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(m_mouseMode == MouseMode::Disabled)
            return ;
        m_mouseMode = MouseMode::Disabled;
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        send(new CursorDisableEvent({.source=this}));
        mark();
    }
    
    void    WindowGLFW::on_cursor_hide_command(const CursorHideCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(m_mouseMode == MouseMode::Hidden)
            return ;
        m_mouseMode = MouseMode::Hidden;
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        send(new CursorHideEvent({.source=this}));
        mark();
    }
    
    void    WindowGLFW::on_cursor_normal_command(const CursorNormalCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        if(m_mouseMode == MouseMode::Normal)
            return ;
        m_mouseMode = MouseMode::Normal;
        glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        send(new CursorNormalEvent({.source=this}));
        mark();
    }
    
    void    WindowGLFW::on_float_command(const FloatCommand&cmd)
    {
        if(cmd.target() != id())
            return ;

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
        send(new HideEvent({.source=*this}));
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

    void    WindowGLFW::on_title_command(const TitleCommand&cmd)
    {
        if(cmd.target() != id())
            return ;
        glfwSetWindowTitle(m_window, cmd.title().c_str());
        send(new TitleEvent({.source=this}, cmd.title()));
        mark();
    }
    
    void    WindowGLFW::on_unfloat_command(const UnfloatCommand&cmd)
    {
        if(cmd.target() != id())
            return ;

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
        sn.window.mode          = m_windowMode;

        sn.time                 = glfwGetTime();
    }

    Execution WindowGLFW::tick(const Context&ctx) 
    {
        if(m_desktop){
            if(glfwGetWindowAttrib(m_window, GLFW_FOCUSED)){
                m_desktop->m_focus      = *this;
            } else if(m_desktop->m_focus == id()){
                m_desktop->m_focus      = {};
            }
        }
        return {};  // TODO: throw a rate limit here... 10-100ms? (well, once we honor it)
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
