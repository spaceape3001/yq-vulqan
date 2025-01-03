////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLFWManager.hpp"

#include <yq/tachyon/errors.hpp>
#include <yt/logging.hpp>
#include <yq/tachyon/api/Application.hpp>
#include <yq/tachyon/api/ManagerInfoWriter.hpp>
#include <yq/tachyon/api/Viewer.hpp>
#include <yq/tachyon/api/ViewerCreateInfo.hpp>
#include <ya/commands/window.hpp>
#include <ya/events/cursor.hpp>
#include <ya/events/joystick.hpp>
#include <ya/events/keyboard.hpp>
#include <ya/events/MonitorConnectEvent.hpp>
#include <ya/events/MonitorDisconnectEvent.hpp>
#include <ya/events/mouse.hpp>
#include <ya/events/window.hpp>
#include <yq/tachyon/exceptions/GLFWException.hpp>
#include <yq/tachyon/glfw/Joystick.hpp>
#include <yq/tachyon/glfw/Monitor.hpp>
#include <yq/tachyon/requests/ViewerCloseRequest.hpp>
#include <yq/tachyon/requests/WindowRefreshRequest.hpp>

#include <yq/core/ThreadId.hpp>
#include <yq/util/Safety.hpp>
#include <yq/shape/Size2.hxx>

#include <GLFW/glfw3.h>

namespace yq::tachyon {

    namespace errors {
        using glfw_no_window_for_viewer         = error_db::entry<"No associated window to the specified viewer">;
        using glfw_no_viewer_for_window         = error_db::entry<"No viewer associated with GLFW window">;
    }

    struct GLFWManager::JoystickData {
        
        struct {
            std::span<const float>          axes;
            std::span<const unsigned char>  buttons;
            std::span<const unsigned char>  hats;
        } state;
        
        struct {
            std::vector<float>              axes;
            std::vector<unsigned char>      buttons;
            std::vector<unsigned char>      hats;
        } snapshot;
        
        
        bool                        connected   = false;
        bool                        gamepad     = false;
        bool                        present     = false;

        void                        copy()
        {
            snapshot.axes.assign(state.axes.begin(), state.axes.end());
            snapshot.buttons.assign(state.buttons.begin(), state.buttons.end());
            snapshot.hats.assign(state.hats.begin(), state.hats.end());
        }
        
        void                        probe(Joystick j)
        {
            state.axes       = j.axes();
            state.buttons    = j.buttons();
            state.hats       = j.hats();
        }
    };
    
    enum class VD : uint8_t {
        Modifiers,
        Buttons
    };
    
    struct GLFWManager::Window {
        Viewer*         viewer      = nullptr;
        GLFWwindow*     window      = nullptr;
        ViewerState     state;
    };

    static constexpr const unsigned kMaxJoysticks   = (unsigned) GLFW_JOYSTICK_LAST + 1;
    struct GLFWManager::Common {
        GLFWManager*                                manager = nullptr;
        std::atomic_flag                            claimed;
        std::array<JoystickData, kMaxJoysticks>     joysticks{};
        std::map<Viewer*, Window>               viewers;
        bool                                        imgui   = false;
    };
    
    GLFWManager::Common&  GLFWManager::common()
    {
        static Common s_ret;
        return s_ret;
    }

    GLFWManager*        GLFWManager::manager()
    {
        static Common& g = common();
        return g.manager;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   KEYBOARD
    
    ModifierKeys GLFWManager::_modifiers(GLFWwindow* w)
    {
        ModifierKeys    ret;
        if(glfwGetKey(w, GLFW_KEY_LEFT_ALT) == GLFW_PRESS)
            ret |= ModifierKey::AltLeft;
        if(glfwGetKey(w, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS)
            ret |= ModifierKey::AltRight;
        if(glfwGetKey(w, GLFW_KEY_CAPS_LOCK) == GLFW_PRESS)
            ret |= ModifierKey::CapsLock;
        if(glfwGetKey(w, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
            ret |= ModifierKey::ControlLeft;
        if(glfwGetKey(w, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS)
            ret |= ModifierKey::ControlRight;
        if(glfwGetKey(w, GLFW_KEY_NUM_LOCK) == GLFW_PRESS)
            ret |= ModifierKey::NumLock;
        if(glfwGetKey(w, GLFW_KEY_SCROLL_LOCK) == GLFW_PRESS)
            ret |= ModifierKey::ScrollLock;
        if(glfwGetKey(w, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            ret |= ModifierKey::ShiftLeft;
        if(glfwGetKey(w, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS)
            ret |= ModifierKey::ShiftRight;
        if(glfwGetKey(w, GLFW_KEY_LEFT_SUPER) == GLFW_PRESS)
            ret |= ModifierKey::SuperLeft;
        if(glfwGetKey(w, GLFW_KEY_RIGHT_SUPER) == GLFW_PRESS)
            ret |= ModifierKey::SuperRight;
        return ret;
    }
    
    void GLFWManager::callback_character(GLFWwindow* window, unsigned int codepoint)
    {
        static Common& g = common();

        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;
            
        KeyCharacterEvent::Param    p;
        p.viewer        = v;
        p.modifiers     = _modifiers(window);
        p.code          = (char32_t) codepoint;
        g.manager->send(new KeyCharacterEvent(p));
    }

    void GLFWManager::callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        static Common& g = common();

        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;
            
        switch(action){
        case GLFW_PRESS:
            {
                KeyPressEvent::Param    p;
                p.viewer        = v;
                p.modifiers     = _modifiers(window);
                p.scan          = scancode;
                p.key           = keycode_glfw(key);
                g.manager->send(new KeyPressEvent(p));
            }
            break;
        case GLFW_RELEASE:
            {
                KeyReleaseEvent::Param    p;
                p.viewer        = v;
                p.modifiers     = _modifiers(window);
                p.scan          = scancode;
                p.key           = keycode_glfw(key);
                g.manager->send(new KeyReleaseEvent(p));
            }
            break;
        case GLFW_REPEAT:
            {
                KeyRepeatEvent::Param    p;
                p.viewer        = v;
                p.modifiers     = _modifiers(window);
                p.scan          = scancode;
                p.key           = keycode_glfw(key);
                g.manager->send(new KeyRepeatEvent(p));
            }
            break;
        }
    }
    

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   JOYSTICKS

    void    GLFWManager::_install(Joystick j)
    {
        static Common& g = common();
        if(j.id >= kMaxJoysticks)
            return ;
        
        auto & jx = g.joysticks[j.id];
        if(!j.is_present()){
            jx  = {};
        } else {
            jx.present          = true;
            jx.gamepad          = j.is_gamepad();
            jx.probe(j);
            jx.copy();
        }
    }
    
    void    GLFWManager::_poll(Joystick j)
    {
        static Common& g = common();

        if(j.id >= kMaxJoysticks)
            return;

        auto & jx = g.joysticks[j.id];
        if(!jx.present)
            return;
        
        bool    changed = false;
        
        jx.probe(j);
        
        for(size_t i=0;i<jx.state.axes.size();++i){
            if(jx.state.axes[i] != jx.snapshot.axes[i]){
                g.manager -> dispatch(new JoystickAxisEvent(j, i, jx.state.axes[i], 
                    jx.state.axes[i] - jx.snapshot.axes[i]));
                changed = true;
            }
        }
        
        for(size_t i=0;i<jx.state.buttons.size();++i){
            if(jx.state.buttons[i] != jx.snapshot.buttons[i]){
                if(jx.state.buttons[i] == GLFW_PRESS){
                    g.manager->send(new JoystickPressEvent(j,i));
                } else {
                    g.manager->send(new JoystickReleaseEvent(j,i));
                }
                changed = true;
            }
        }
        
        for(size_t i=0;i<jx.state.hats.size();++i){
            if(jx.state.hats[i] != jx.snapshot.hats[i]){
                g.manager->send(new JoystickHatEvent(j, i, (JoystickHatState) jx.state.hats[i]));
                changed = true;
            }
        }

        if(changed){
            jx.copy();
        }
    }

    void GLFWManager::callback_joystick(int jid, int event)
    {
        static Common& g = common();

        if((unsigned) jid > kMaxJoysticks)
            return ;
    
        if(!g.manager)
            return ;
            
        Joystick    j(jid);
        _install(j);
        if(event == GLFW_CONNECTED){
            g.manager->send(new JoystickConnectEvent(j));
        } else {
            g.manager->send(new JoystickDisconnectEvent(j));
        }
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   MICE

    MouseButtons GLFWManager::_buttons(GLFWwindow*w)
    {
        MouseButtons    ret;
        if(glfwGetMouseButton(w, GLFW_MOUSE_BUTTON_1) == GLFW_PRESS)
            ret |= MouseButton::Button1;
        if(glfwGetMouseButton(w, GLFW_MOUSE_BUTTON_2) == GLFW_PRESS)
            ret |= MouseButton::Button2;
        if(glfwGetMouseButton(w, GLFW_MOUSE_BUTTON_3) == GLFW_PRESS)
            ret |= MouseButton::Button3;
        if(glfwGetMouseButton(w, GLFW_MOUSE_BUTTON_4) == GLFW_PRESS)
            ret |= MouseButton::Button4;
        if(glfwGetMouseButton(w, GLFW_MOUSE_BUTTON_5) == GLFW_PRESS)
            ret |= MouseButton::Button5;
        if(glfwGetMouseButton(w, GLFW_MOUSE_BUTTON_6) == GLFW_PRESS)
            ret |= MouseButton::Button6;
        if(glfwGetMouseButton(w, GLFW_MOUSE_BUTTON_7) == GLFW_PRESS)
            ret |= MouseButton::Button7;
        if(glfwGetMouseButton(w, GLFW_MOUSE_BUTTON_8) == GLFW_PRESS)
            ret |= MouseButton::Button8;
        return ret;
    }

    void     GLFWManager::_cursor_capture(Window*w)
    {
        static Common& g = common();
        if(!w->window)
            return;
            
        glfwSetInputMode(w->window, GLFW_CURSOR, GLFW_CURSOR_CAPTURED);
        w->state.mouse.mode = MouseMode::Captured;
        if(w->viewer){
            g.manager->send(new CursorCaptureEvent(w->viewer));
        }
    }
    
    void     GLFWManager::_cursor_disable(Window*w)
    {
        static Common& g = common();
        if(!w->window)
            return;

        glfwSetInputMode(w->window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        w->state.mouse.mode = MouseMode::Disabled;
        if(w->viewer){
            g.manager->send(new CursorDisableEvent(w->viewer));
        }
    }
    
    void     GLFWManager::_cursor_hide(Window*w)
    {
        static Common& g = common();
        if(!w->window)
            return;

        glfwSetInputMode(w->window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
        w->state.mouse.mode = MouseMode::Hidden;
        if(w->viewer){
            g.manager->send(new CursorHideEvent(w->viewer));
        }
    }
    
    void     GLFWManager::_cursor_normal(Window*w)
    {
        static Common& g = common();
        if(!w->window)
            return;
        glfwSetInputMode(w->window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        w->state.mouse.mode = MouseMode::Normal;
        if(w->viewer){
            g.manager->send(new CursorNormalEvent(w->viewer));
        }
    }

    Vector2D     GLFWManager::_mouse_pos(GLFWwindow*w)
    {
        Vector2D ret;
        glfwGetCursorPos(w, &ret.x, &ret.y);
        return ret;
    }

    void GLFWManager::callback_cursor_enter(GLFWwindow* window, int entered)
    {
        static Common& g = common();

        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;
        
        if(entered){
            MouseEnterEvent::Param p;
            p.viewer    = v;
            p.modifiers = _modifiers(window);
            p.buttons   = _buttons(window);
            p.position  = _mouse_pos(window);
            g.manager->send(new MouseEnterEvent(p));
        } else {
            MouseLeaveEvent::Param p;
            p.viewer    = v;
            p.modifiers = _modifiers(window);
            p.buttons   = _buttons(window);
            p.position  = _mouse_pos(window);
            g.manager->send(new MouseLeaveEvent(p));
        }
    }

    void GLFWManager::callback_drop(GLFWwindow* window, int count, const char** paths)
    {
        static Common& g = common();

        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;
        if(count <= 0)
            return ;
        
        std::vector<std::string>    copy;
        for(int i=0;i<count;++i){
            if(!paths[i])
                continue;
            copy.push_back(std::string(paths[i]));
        }
        
        MouseDropEvent::Param p;
        p.viewer    = v;
        p.modifiers = _modifiers(window);
        p.buttons   = _buttons(window);
        p.position  = _mouse_pos(window);
        g.manager->send(new MouseDropEvent(std::move(copy), p));
    }

    void GLFWManager::callback_cursor_position(GLFWwindow* window, double xpos, double ypos)
    {
        static Common& g = common();

        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;
            
        MouseMoveEvent::Param p;
        p.viewer    = v;
        p.modifiers = _modifiers(window);
        p.buttons   = _buttons(window);
        p.position  = { xpos, ypos };
        g.manager -> dispatch(new MouseMoveEvent(p));
    }

    void GLFWManager::callback_mouse_button(GLFWwindow* window, int button, int action, int mods)
    {
        static Common& g = common();

        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;
            
        if(action == GLFW_PRESS){
            MousePressEvent::Param p;
            p.viewer    = v;
            p.modifiers = _modifiers(window);
            p.buttons   = _buttons(window);
            p.position  = _mouse_pos(window);
            p.button    = MouseButton(button);
            g.manager->send(new MousePressEvent(p));
        } else {
            MouseReleaseEvent::Param p;
            p.viewer    = v;
            p.modifiers = _modifiers(window);
            p.buttons   = _buttons(window);
            p.position  = _mouse_pos(window);
            p.button    = MouseButton(button);
            g.manager->send(new MouseReleaseEvent(p));
        }
        
    }

    void GLFWManager::callback_scroll(GLFWwindow* window, double xoffset, double yoffset)
    {
        static Common& g = common();

        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;
        MouseScrollEvent::Param p;
        p.viewer    = v;
        p.modifiers = _modifiers(window);
        p.buttons   = _buttons(window);
        p.delta     = { xoffset, yoffset };
        g.manager->send(new MouseScrollEvent(p));
    }

    void    GLFWManager::cmd_cursor_capture(const WindowCursorCaptureCommand&cmd)
    {
        Window* w = _window(cmd.viewer());
        if(w){
            _cursor_capture(w);
        }
    }
    
    void    GLFWManager::cmd_cursor_disable(const WindowCursorDisableCommand&cmd)
    {
        Window* w = _window(cmd.viewer());
        if(w){
            _cursor_disable(w);
        }
    }
    
    void    GLFWManager::cmd_cursor_hide(const WindowCursorHideCommand&cmd)
    {
        Window* w = _window(cmd.viewer());
        if(w){
            _cursor_hide(w);
        }
    }
    
    void    GLFWManager::cmd_cursor_normal(const WindowCursorNormalCommand&cmd)
    {
        Window* w = _window(cmd.viewer());
        if(w){
            _cursor_normal(w);
        }
    }

    bool    GLFWManager::raw_mouse_motion_supported()
    {
        return glfwRawMouseMotionSupported() == GLFW_TRUE;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   MONITOR

    void GLFWManager::callback_monitor(GLFWmonitor* monitor, int event)
    {
        static Common& g = common();

        if(!monitor)
            return ;

        if(event == GLFW_CONNECTED){
            g.manager->send(new MonitorConnectEvent(monitor));
        } else {
            g.manager->send(new MonitorDisconnectEvent(monitor));
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   POLL-LOOP

    void    GLFWManager::_poll(unit::Second timeout)
    {
        static Common& g = common();
      
        if(timeout.value > 0.){
            glfwWaitEventsTimeout(timeout.value);
        } else {
            glfwPollEvents();
        }
        
        for(int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_LAST; ++jid){
            _poll(Joystick(jid));
        }
        
        for(auto& itr : g.viewers){
            _update(itr.second.window, itr.second.state);
            g.manager->send(new WindowStateEvent(itr.first, itr.second.state));
        }
    }

    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   VIEWER/WINDOW RELATIONS
    
    void     GLFWManager::_aspect(Window* w, const Size2I& sz)
    {
        static Common& g = common();
        if(!w->window)
            return ;
        glfwSetWindowAspectRatio(w->window, sz.x, sz.y);
        w->state.window.aspect   = sz;
        if(w->viewer){
            g.manager->send(new WindowAspectEvent(w->viewer, sz));
        }
    }

    void     GLFWManager::_attention(Window*w)
    {
        if(!w->window)
            return ;
        glfwRequestWindowAttention(w->window);
    }
    
    void     GLFWManager::_destroy(Window*w)
    {
        static Common& g = common();
        if(!w->window)
            return ;

        Viewer* v   = w->viewer;
        glfwSetWindowUserPointer(w->window, nullptr);

        glfwSetCharCallback(w->window, nullptr);
        glfwSetCursorEnterCallback(w->window, nullptr);
        glfwSetCursorPosCallback(w->window, nullptr);
        glfwSetDropCallback(w->window, nullptr);
        glfwSetFramebufferSizeCallback(w->window, nullptr);
        glfwSetKeyCallback(w->window, nullptr);
        glfwSetMouseButtonCallback(w->window, nullptr);
        glfwSetScrollCallback(w->window, nullptr);
        glfwSetWindowCloseCallback(w->window, nullptr);
        glfwSetWindowContentScaleCallback(w->window, nullptr);
        glfwSetWindowFocusCallback(w->window, nullptr);
        glfwSetWindowIconifyCallback(w->window, nullptr);
        glfwSetWindowMaximizeCallback(w->window, nullptr);
        glfwSetWindowPosCallback(w->window, nullptr);
        glfwSetWindowRefreshCallback(w->window, nullptr);
        glfwSetWindowSizeCallback(w->window, nullptr);

        glfwDestroyWindow(w->window);
        w->window   = nullptr;
        g.viewers.erase(v); // WARNING, implicitly destroys w!
        if(v){
            g.manager->send(new WindowDestroyEvent(v));
        }
        g.manager->disconnect(*v);
    }
    
    void     GLFWManager::_float(Window*w)
    {
        if(!w->window)
            return;
        glfwSetWindowAttrib(w->window, GLFW_FLOATING, GLFW_TRUE);
    }
    
    void     GLFWManager::_focus(Window*w)
    {
        if(!w->window)
            return ;
        glfwFocusWindow(w->window);
    }
    
    void     GLFWManager::_hide(Window*w)
    {
        static Common& g = common();

        if(!w->window)
            return ;
        if(!glfwGetWindowAttrib(w->window, GLFW_VISIBLE))
            return ;
        glfwHideWindow(w->window);
        if(w->viewer){
            g.manager->send(new WindowHideEvent(w->viewer));
        }
    }
    
    void     GLFWManager::_iconify(Window*w)
    {
        if(!w->window)
            return ;
        glfwIconifyWindow(w->window);
    }
    
    void     GLFWManager::_maximize(Window*w)
    {
        if(!w->window)
            return ;
        glfwMaximizeWindow(w->window);
    }
    
    void     GLFWManager::_move(Window*w, const Vector2I&v)
    {
        if(!w->window)
            return;
        glfwSetWindowPos(w->window, v.x, v.y);
    }

    void     GLFWManager::_restore(Window*w)
    {
        if(!w->window)
            return ;
        glfwRestoreWindow(w->window);
    }
    
    void     GLFWManager::_show(Window*w)
    {
        static Common& g = common();

        if(!w->window)
            return ;
        if(glfwGetWindowAttrib(w->window, GLFW_VISIBLE))
            return ;
        glfwShowWindow(w->window);
        if(w->viewer){
            g.manager->send(new WindowShowEvent(w->viewer));
        }
    }

    void  GLFWManager::_size(Window*w, const Size2I&size)
    {
        if(!w->window)
            return ;
        glfwSetWindowSize(w->window, size.x, size.y );
    }

    void  GLFWManager::_title(Window*w, const std::string&title)
    {
        static Common& g = common();
        if(!w->window)
            return;
        glfwSetWindowTitle(w->window, title.c_str());
        if(w->viewer){
            g.manager->send(new WindowTitleEvent(w->viewer, title));
        }
    }

    void     GLFWManager::_unfloat(Window*w)
    {
        if(!w->window)
            return;
        glfwSetWindowAttrib(w->window, GLFW_FLOATING, GLFW_FALSE);
    }

    void  GLFWManager::_update(GLFWwindow* w, ViewerState&vs)
    {
        for(KeyCode kc : KeyCode::all_values()){
            int gk  = encode_glfw(kc);
            if(gk == GLFW_KEY_UNKNOWN)
                continue;
            vs.keyboard.keys.set((int) kc.value(), glfwGetKey(w, gk) == GLFW_PRESS);
        }
        vs.keyboard.modifiers    = _modifiers(w);

        vs.mouse.buttons      = _buttons(w);
        glfwGetCursorPos(w, &vs.mouse.position.x, &vs.mouse.position.y);
        
        vs.window.title         = glfwGetWindowTitle(w);
        vs.window.monitor       = Monitor(glfwGetWindowMonitor(w));

        vs.window.flags.set(WindowFlag::AutoIconify,       static_cast<bool>(glfwGetWindowAttrib(w, GLFW_AUTO_ICONIFY)));
        vs.window.flags.set(WindowFlag::Decorated,         static_cast<bool>(glfwGetWindowAttrib(w, GLFW_DECORATED)));
        vs.window.flags.set(WindowFlag::Floating,          static_cast<bool>(glfwGetWindowAttrib(w, GLFW_FLOATING)));
        vs.window.flags.set(WindowFlag::Focused,           static_cast<bool>(glfwGetWindowAttrib(w, GLFW_FOCUSED)));
        vs.window.flags.set(WindowFlag::FocusOnShow,       static_cast<bool>(glfwGetWindowAttrib(w, GLFW_FOCUS_ON_SHOW)));
        vs.window.flags.set(WindowFlag::Hovered,           static_cast<bool>(glfwGetWindowAttrib(w, GLFW_HOVERED)));
        vs.window.flags.set(WindowFlag::Iconified,         static_cast<bool>(glfwGetWindowAttrib(w, GLFW_ICONIFIED)));
        vs.window.flags.set(WindowFlag::Maximized,         static_cast<bool>(glfwGetWindowAttrib(w, GLFW_MAXIMIZED)));
        vs.window.flags.set(WindowFlag::MousePassThrough,  static_cast<bool>(glfwGetWindowAttrib(w, GLFW_MOUSE_PASSTHROUGH)));
        vs.window.flags.set(WindowFlag::Resizable,         static_cast<bool>(glfwGetWindowAttrib(w, GLFW_RESIZABLE)));
        vs.window.flags.set(WindowFlag::Transparent,       static_cast<bool>(glfwGetWindowAttrib(w, GLFW_TRANSPARENT_FRAMEBUFFER)));
        vs.window.flags.set(WindowFlag::Visible,           static_cast<bool>(glfwGetWindowAttrib(w, GLFW_VISIBLE)));

        vs.window.opacity      = glfwGetWindowOpacity(w);
        glfwGetWindowSize(w, &vs.window.area.x, &vs.window.area.y);
        glfwGetFramebufferSize(w, &vs.window.pixels.x, &vs.window.pixels.y);
        glfwGetWindowContentScale(w, &vs.window.scale.x, &vs.window.scale.y);
        glfwGetWindowPos(w, &vs.window.position.x, &vs.window.position.y);
        
        vs.time             = glfwGetTime();
    }
    
    //Viewer*  GLFWManager::_viewer(GLFWwindow*w)
    //{
        //return (Viewer*) glfwGetWindowUserPointer(w);
    //}

    GLFWManager::Window*  GLFWManager::_window(Viewer* vd)
    {
        static Common& g = common();
        auto itr = g.viewers.find(vd);
        if(itr == g.viewers.end())
            return nullptr;
        return &(itr->second);
    }
    
    GLFWManager::Window*  GLFWManager::_window(GLFWwindow* w)
    {
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(w);
        return _window(v);
    }

    //  ...............................................................................................................
    //      CALLBACKS
    
    void GLFWManager::callback_framebuffer_size(GLFWwindow* window, int width, int height)
    {
        static Common& g = common();
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;

        g.manager->send(new WindowFrameBufferResizeEvent(v, {width, height}));
    }

    void GLFWManager::callback_window_close(GLFWwindow* window)
    {
        static Common& g = common();
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;

            // so we don't repeat this....
        glfwSetWindowShouldClose(window, GLFW_FALSE);
        g.manager->send(new ViewerCloseRequest(v));
    }
    
    void GLFWManager::callback_window_focus(GLFWwindow* window, int focused)
    {
        static Common& g = common();

        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;

        if(focused){
            g.manager->send(new WindowFocusEvent(v));
        } else {
            g.manager->send(new WindowDefocusEvent(v));
        }
    }
    
    void GLFWManager::callback_window_iconify(GLFWwindow* window, int iconified)
    {
        static Common& g = common();

        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;

        if(iconified){
            g.manager->send(new WindowIconifyEvent(v));
        } else {
            g.manager->send(new WindowRestoreEvent(v));
        }
    }
    
    void GLFWManager::callback_window_maximize(GLFWwindow* window, int maximized)
    {
        static Common& g = common();

        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;

        if(maximized){
            g.manager->send(new WindowMaximizeEvent(v));
        } else {
            g.manager->send(new WindowRestoreEvent(v));
        }
    }
    
    void GLFWManager::callback_window_position(GLFWwindow* window, int xpos, int ypos)
    {
        static Common& g = common();
        
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;

        g.manager->send(new WindowMoveEvent(v, { xpos, ypos }));
    }
    
    void GLFWManager::callback_window_refresh(GLFWwindow* window)
    {
        static Common& g = common();
        
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(v){
            g.manager->send(new WindowRefreshRequest(v));
        }
    }
    
    void GLFWManager::callback_window_scale(GLFWwindow* window, float xscale, float yscale)
    {
        static Common& g = common();
        
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(v){
            g.manager->send(new WindowScaleEvent(v, { xscale, yscale }));
        }
    }
    
    void GLFWManager::callback_window_size(GLFWwindow* window, int xsize, int ysize)
    {
        static Common& g = common();
        
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(v){
            g.manager->send(new WindowResizeEvent(v, { xsize, ysize }));
        }
    }
        
    //  ...............................................................................................................
    //      COMMANDS

    void    GLFWManager::cmd_aspect(const WindowAspectCommand&cmd)
    {
        Window *w   = _window(cmd.viewer());
        if(w){
            _aspect(w, cmd.aspect());
        }
    }
    
    void    GLFWManager::cmd_attention(const WindowAttentionCommand& cmd)
    {
        Window *w = _window(cmd.viewer());
        if(w){
            _show(w);
        }
    }
    
    void    GLFWManager::cmd_destroy(const WindowDestroyCommand& cmd)
    {
        Window *w = _window(cmd.viewer());
        if(w){
            _destroy(w);
        }
    }

    void    GLFWManager::cmd_float(const WindowFloatCommand&cmd)
    {
        Window* w = _window(cmd.viewer());
        if(w){
            _float(w);
        }
    }
    
    void    GLFWManager::cmd_focus(const WindowFocusCommand& cmd)
    {
        Window *w = _window(cmd.viewer());
        if(w){
            _focus(w);
        }
    }
    
    void    GLFWManager::cmd_hide(const WindowHideCommand& cmd)
    {
        Window *w = _window(cmd.viewer());
        if(w){
            _hide(w);
        }
    }
    
    void    GLFWManager::cmd_iconify(const WindowIconifyCommand& cmd)
    {
        Window *w = _window(cmd.viewer());
        if(w){
            _iconify(w);
        }
    }
    
    void    GLFWManager::cmd_maximize(const WindowMaximizeCommand& cmd)
    {
        Window *w = _window(cmd.viewer());
        if(w){
            _maximize(w);
        }
    }
    
    void    GLFWManager::cmd_move(const WindowMoveCommand&cmd)
    {
        Window *w = _window(cmd.viewer());
        if(w){
            _move(w, cmd.position());
        }
    }

    void    GLFWManager::cmd_restore(const WindowRestoreCommand& cmd)
    {
        Window *w = _window(cmd.viewer());
        if(w){
            _restore(w);
        }
    }
    
    void    GLFWManager::cmd_show(const WindowShowCommand& cmd)
    {
        Window *w = _window(cmd.viewer());
        if(w){
            _show(w);
        }
    }

    void    GLFWManager::cmd_size(const WindowSizeCommand& cmd)
    {
        Window* w = _window(cmd.viewer());
        if(w){
            _size(w, cmd.size());
        }
    }

    void    GLFWManager::cmd_title(const WindowTitleCommand&cmd)
    {
        Window* w   = _window(cmd.viewer());
        if(w){
            _title(w, cmd.title());
        }
    }

    void    GLFWManager::cmd_unfloat(const WindowUnfloatCommand&cmd)
    {
        Window* w = _window(cmd.viewer());
        if(w){
            _unfloat(w);
        }
    }

    //  ...............................................................................................................
    //      WINDOW MANAGEMENT


    std::error_code     GLFWManager::win_destroy(Viewer* v)
    {
        Window* w   = _window(v);
        if(!w)
            return errors::glfw_no_window_for_viewer();
        _destroy(w);
        return {};
    }

    std::error_code     GLFWManager::win_hide(Viewer* v)
    {
        Window*w    = _window(v);
        if(!w)
            return errors::glfw_no_window_for_viewer();
    
        _hide(w);
        return {};
    }

    std::error_code     GLFWManager::win_show(Viewer* v)
    {
        Window*w    = _window(v);
        if(!w)
            return errors::glfw_no_window_for_viewer();
        _show(w);
        return {};
    }

    std::error_code     GLFWManager::win_start(Viewer* v)
    {
        if(!v->never_started())
            return create_error<"Viewer has already been started">();
    
        static Common& g = common();
        if(!g.manager)
            return create_error<"GLFW has not been initialized">();
            
        if(g.viewers.contains(v))
            return create_error<"Viewer is already known to GLFW">();

        const ViewerCreateInfo& vci = v->create_info();

        Window  vd;
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_FLOATING, vci.floating ? GLFW_TRUE : GLFW_FALSE);
        glfwWindowHint(GLFW_DECORATED, vci.decorated ? GLFW_TRUE : GLFW_FALSE);
        glfwWindowHint(GLFW_RESIZABLE, vci.resizable ? GLFW_TRUE : GLFW_FALSE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
        
        int wx      = std::max(1,vci.size.width());
        int wy      = std::max(1,vci.size.height());
        
        std::string     title   = vci.title;
        if(title.empty())
            title   = Application::app_name();
        
        vd.viewer   = v;
        
        vd.window   = glfwCreateWindow(wx, wy, title.c_str(), vci.monitor.monitor(), nullptr);
        if(!vd.window){
            const char* description = nullptr;
            glfwGetError(&description);
            if(description)
                glfwCritical << "Unable to create GLFW window.  " << description;
            return create_error<"GLFW window could not be instantiated">();
        }
        
        auto destruct   = safety([&](){
            glfwDestroyWindow(vd.window);
        });
        
        glfwSetWindowUserPointer(vd.window, v);
        glfwSetCharCallback(vd.window, callback_character);
        glfwSetCursorEnterCallback(vd.window, callback_cursor_enter);
        glfwSetCursorPosCallback(vd.window, callback_cursor_position);
        glfwSetDropCallback(vd.window, callback_drop);
        glfwSetFramebufferSizeCallback(vd.window, callback_framebuffer_size);
        glfwSetKeyCallback(vd.window, callback_key);
        glfwSetMouseButtonCallback(vd.window, callback_mouse_button);
        glfwSetScrollCallback(vd.window, callback_scroll);
        glfwSetWindowCloseCallback(vd.window, callback_window_close);
        glfwSetWindowContentScaleCallback(vd.window, callback_window_scale);
        glfwSetWindowFocusCallback(vd.window, callback_window_focus);
        glfwSetWindowIconifyCallback(vd.window, callback_window_iconify);
        glfwSetWindowMaximizeCallback(vd.window, callback_window_maximize);
        glfwSetWindowPosCallback(vd.window, callback_window_position);
        glfwSetWindowRefreshCallback(vd.window, callback_window_refresh);
        glfwSetWindowSizeCallback(vd.window, callback_window_size);
            
        _update(vd.window, vd.state);

        try {
            std::error_code ec  = v->_startup(vd.window, vd.state);
            if(ec != std::error_code()){
                glfwCritical << "Viewer unable to startup (error " << ec.message() << ")";
                return ec;
            }
        }
        catch(std::error_code ec)
        {
            glfwCritical << "Viewer unable to startup (error " << ec.message() << ")";
            return ec;
        }
        catch(const std::exception& ex)
        {
            glfwCritical << "Viewer unable to startup (exception " << ex.what() << ")";
            return create_error<"Exception thrown during viewer startup">();
        }
        
        destruct.disarm();
        g.manager->connect(RX, *v);
        g.manager->connect(TX, *v);
        g.viewers[v]        = std::move(vd);
        return {};
    }

    bool    GLFWManager::has_viewers()
    {
        return !common().viewers.empty();
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    namespace {
        static void    glfwLogging(int ec, const char* why)
        {
            static const auto  prior = glfwSetErrorCallback(glfwLogging);
            if(ec){
                if(!why)
                    why = "Unknown error";
                glfwWarning << "GLFW error (" << ec << "): " << why;
            }
            if(prior)
                prior(ec, why);
        }
    }

    GLFWManager::Param    GLFWManager::_augment(const Param&pars)
    {
        Param p(pars);
        if(p.name.empty())
            p.name  = "GLFW";
        return p;
    }

    GLFWManager::GLFWManager(const Param&p) : Manager(_augment(p))
    {
        if(thread::id())    // not the main thread...
            throw GLFWException("GLFW must be created/reside on the main thread");

        add_role(R::Poller);

        Common&     g = common();
        if(g.claimed.test_and_set())
            throw GLFWException("Only one GLFWManagers is permitted");
            
        g.manager   = this;

        glfwLogging(0,nullptr);
        glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);
        glfwInit();
        
        for(int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_LAST; ++jid){
            _install(Joystick(jid));
        }
        
        glfwSetJoystickCallback( callback_joystick );
        glfwSetMonitorCallback( callback_monitor );
        
        set_post_mode(PostMode::Queued);
        
        tachyonInfo << "GLFWManager initialized";
    }
    
    GLFWManager::~GLFWManager()
    {
        Common& g   = common();
        if(g.manager != this)
            return;
            
        glfwTerminate();
        g.manager   = nullptr;

        tachyonInfo << "GLFWManager destroyed";
    }

    void    GLFWManager::polling(unit::Second timeout) 
    {
        replay(ALL);
        _poll(timeout);
    }
    
    void GLFWManager::init_info()
    {
        auto w = writer<GLFWManager>();
        w.abstract();
        w.description("GLFW Manager");
        w.slot(&GLFWManager::cmd_attention);
        w.slot(&GLFWManager::cmd_cursor_capture);
        w.slot(&GLFWManager::cmd_cursor_disable);
        w.slot(&GLFWManager::cmd_cursor_hide);
        w.slot(&GLFWManager::cmd_cursor_normal);
        w.slot(&GLFWManager::cmd_destroy);
        w.slot(&GLFWManager::cmd_float);
        w.slot(&GLFWManager::cmd_focus);
        w.slot(&GLFWManager::cmd_hide);
        w.slot(&GLFWManager::cmd_iconify);
        w.slot(&GLFWManager::cmd_maximize);
        w.slot(&GLFWManager::cmd_move);
        w.slot(&GLFWManager::cmd_restore);
        w.slot(&GLFWManager::cmd_show);
        w.slot(&GLFWManager::cmd_size);
        w.slot(&GLFWManager::cmd_title);
        w.slot(&GLFWManager::cmd_unfloat);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::GLFWManager)
