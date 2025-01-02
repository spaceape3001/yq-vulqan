////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowGLFW.hpp"
#include <yq/tachyon/logging.hpp>
#include <yt/os/WindowInfoWriter.hpp>
#include <yq/tachyon/commands/WindowAspectCommand.hpp>
#include <yq/tachyon/commands/WindowAttentionCommand.hpp>
#include <yq/tachyon/commands/WindowCursorCaptureCommand.hpp>
#include <yq/tachyon/commands/WindowCursorDisableCommand.hpp>
#include <yq/tachyon/commands/WindowCursorHideCommand.hpp>
#include <yq/tachyon/commands/WindowCursorNormalCommand.hpp>
#include <yq/tachyon/commands/WindowDestroyCommand.hpp>
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
#include <yt/os/KeyCode.hpp>
#include <yq/tachyon/events/KeyCharacterEvent.hpp>
#include <yq/tachyon/events/KeyPressEvent.hpp>
#include <yq/tachyon/events/KeyReleaseEvent.hpp>
#include <yq/tachyon/events/KeyRepeatEvent.hpp>
#include <yq/tachyon/events/MouseDropEvent.hpp>
#include <yq/tachyon/events/MouseEnterEvent.hpp>
#include <yq/tachyon/events/MouseLeaveEvent.hpp>
#include <yq/tachyon/events/MouseMoveEvent.hpp>
#include <yq/tachyon/events/MousePressEvent.hpp>
#include <yq/tachyon/events/MouseReleaseEvent.hpp>
#include <yq/tachyon/events/MouseScrollEvent.hpp>
#include <yq/tachyon/events/WindowAspectEvent.hpp>
#include <yq/tachyon/events/WindowCursorCaptureEvent.hpp>
#include <yq/tachyon/events/WindowCursorDisableEvent.hpp>
#include <yq/tachyon/events/WindowCursorHideEvent.hpp>
#include <yq/tachyon/events/WindowCursorNormalEvent.hpp>
#include <yq/tachyon/events/WindowDefocusEvent.hpp>
#include <yq/tachyon/events/WindowDestroyEvent.hpp>
#include <yq/tachyon/events/WindowFocusEvent.hpp>
#include <yq/tachyon/events/WindowFrameBufferResizeEvent.hpp>
#include <yq/tachyon/events/WindowHideEvent.hpp>
#include <yq/tachyon/events/WindowIconifyEvent.hpp>
#include <yq/tachyon/events/WindowMaximizeEvent.hpp>
#include <yq/tachyon/events/WindowMoveEvent.hpp>
#include <yq/tachyon/events/WindowRestoreEvent.hpp>
#include <yq/tachyon/events/WindowResizeEvent.hpp>
#include <yq/tachyon/events/WindowScaleEvent.hpp>
#include <yq/tachyon/events/WindowShowEvent.hpp>
#include <yq/tachyon/events/WindowTitleEvent.hpp>
#include <yq/tachyon/glfw/DesktopGLFW.hpp>
#include <yq/tachyon/glfw/LoggingGLFW.hpp>
#include <yq/tachyon/glfw/MonitorGLFW.hpp>
#include <yq/tachyon/requests/WindowCloseRequest.hpp>
#include <yq/tachyon/requests/WindowRefreshRequest.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::WindowGLFW)

namespace yq::tachyon {

    void WindowGLFW::callback_character(GLFWwindow* win, unsigned int codepoint)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        KeyCharacterEvent::Param    p;
        p.modifiers = w->modifiers();
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
            p.modifiers = w->modifiers();
            p.buttons   = w->buttons();
            p.position  = w->mouse();
            w->send(new MouseEnterEvent(w, p));
        } else {
            MouseLeaveEvent::Param p;
            p.modifiers = w->modifiers();
            p.buttons   = w->buttons();
            p.position  = w->mouse();
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
        p.modifiers = w->modifiers();
        p.buttons   = w->buttons();
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
        p.modifiers = w->modifiers();
        p.buttons   = w->buttons();
        p.position  = w->mouse();
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
                p.modifiers     = w->modifiers();
                p.scan          = scancode;
                p.key           = keycode_glfw(key);
                w->send(new KeyPressEvent(w,p));
            }
            break;
        case GLFW_RELEASE:
            {
                KeyReleaseEvent::Param    p;
                p.modifiers     = w->modifiers();
                p.scan          = scancode;
                p.key           = keycode_glfw(key);
                w->send(new KeyReleaseEvent(w,p));
            }
            break;
        case GLFW_REPEAT:
            {
                KeyRepeatEvent::Param    p;
                p.modifiers     = w->modifiers();
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
            p.modifiers = w->modifiers();
            p.buttons   = w->buttons();
            p.position  = w->mouse();
            p.button    = MouseButton(button);
            w->send(new MousePressEvent(w, p));
        } else {
            MouseReleaseEvent::Param p;
            p.modifiers = w->modifiers();
            p.buttons   = w->buttons();
            p.position  = w->mouse();
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
        p.modifiers = w->modifiers();
        p.buttons   = w->buttons();
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
            w->send(new WindowFocusEvent(w));
        } else {
            w->send(new WindowDefocusEvent(w));
        }
        w->mark();
    }
    
    void WindowGLFW::callback_window_iconify(GLFWwindow* win, int iconified)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        if(iconified){
            w->send(new WindowIconifyEvent(w));
        } else {
            w->send(new WindowRestoreEvent(w));
        }
        w->mark();
    }
    
    void WindowGLFW::callback_window_maximize(GLFWwindow* win, int maximized)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        if(maximized){
            w->send(new WindowMaximizeEvent(w));
        } else {
            w->send(new WindowRestoreEvent(w));
        }
        w->mark();
    }
    
    void WindowGLFW::callback_window_position(GLFWwindow* win, int xpos, int ypos)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        w->send(new WindowMoveEvent(w, Vector2I(xpos, ypos)));
        w->mark();
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
        w->send(new WindowScaleEvent(w, { xscale, yscale }));
        w->mark();
    }
    
    void WindowGLFW::callback_window_size(GLFWwindow* win, int width, int height)
    {
        WindowGLFW *w  = _window(win);
        if(!w)
            return ;
        w->send(new WindowResizeEvent(w, Size2I(width, height)));
        w->mark();
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
        
        m_stage = Stage::Running;
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

    MouseButtons        WindowGLFW::buttons() const
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

    WindowFlags         WindowGLFW::flags() const
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

    Size2I              WindowGLFW::framebuffer() const
    {
        Size2I  ret;
        glfwGetFramebufferSize(m_window, &ret.x, &ret.y);
        return ret;
    }

    ModifierKeys        WindowGLFW::modifiers() const
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

    Vector2D  WindowGLFW::mouse() const
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

    void    WindowGLFW::on_attention_command(const WindowAttentionCommand&)
    {
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

    void    WindowGLFW::on_focus_command(const WindowFocusCommand&)
    {
        glfwFocusWindow(m_window);
        mark();
    }

    void    WindowGLFW::on_hide_command(const WindowHideCommand&)
    {
        if(!glfwGetWindowAttrib(m_window, GLFW_VISIBLE))
            return ;
        glfwHideWindow(m_window);
        send(new WindowHideEvent(this));
        mark();
    }
    
    void    WindowGLFW::on_iconify_command(const WindowIconifyCommand&)
    {
        glfwIconifyWindow(m_window);
        mark();
    }
    
    void    WindowGLFW::on_maximize_command(const WindowMaximizeCommand&)
    {
        glfwMaximizeWindow(m_window);
        mark();
    }

    void    WindowGLFW::on_move_command(const WindowMoveCommand&cmd)
    {
        glfwSetWindowPos(m_window, cmd.x(), cmd.y());
        mark();
    }
    
    void    WindowGLFW::on_restore_command(const WindowRestoreCommand&)
    {
        glfwRestoreWindow(m_window);
        mark();
    }

    void    WindowGLFW::on_show_command(const WindowShowCommand&)
    {
        if(glfwGetWindowAttrib(m_window, GLFW_VISIBLE))
            return ;
        glfwShowWindow(m_window);
        send(new WindowShowEvent(this));
        mark();
    }

    void    WindowGLFW::on_size_command(const WindowSizeCommand&cmd)
    {
        glfwSetWindowSize(m_window, cmd.width(), cmd.height());
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

    Vector2D    WindowGLFW::position() const 
    {
        Vector2I    ret;
        glfwGetWindowPos(m_window, &ret.x, &ret.y);
        return ret.cast<double>();
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

        sn.keyboard.modifiers   = modifiers();
        sn.mouse.buttons        = buttons();
        glfwGetCursorPos(m_window, &sn.mouse.position.x, &sn.mouse.position.y);
        sn.mouse.mode           = m_mouseMode;
        
        sn.window.aspect        = m_aspect;
        sn.window.flags         = flags();
        sn.window.max           = m_maxSize;
        sn.window.min           = m_minSize;
        sn.window.monitor       = MonitorGLFW::monitor(glfwGetWindowMonitor(m_window));
        sn.window.opacity       = glfwGetWindowOpacity(m_window);
        sn.window.title         = title();

        glfwGetWindowSize(m_window, &sn.window.area.x, &sn.window.area.y);
        glfwGetFramebufferSize(m_window, &sn.window.pixels.x, &sn.window.pixels.y);
        glfwGetWindowPos(m_window, &sn.window.position.x, &sn.window.position.y);
        glfwGetWindowContentScale(m_window, &sn.window.scale.x, &sn.window.scale.y);
        
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

    std::string         WindowGLFW::title() const
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
        w.slot(&WindowGLFW::on_move_command);
        w.slot(&WindowGLFW::on_restore_command);
        w.slot(&WindowGLFW::on_show_command);
        w.slot(&WindowGLFW::on_size_command);
        w.slot(&WindowGLFW::on_title_command);
        w.slot(&WindowGLFW::on_unfloat_command);
    }
}
