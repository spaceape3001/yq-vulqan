////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLFWManager.hpp"

#include <yq/core/ThreadId.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/ManagerInfoWriter.hpp>
#include <yq/tachyon/Joystick.hpp>
#include <yq/tachyon/Monitor.hpp>
#include <yq/tachyon/Viewer.hpp>

#include <yq/tachyon/events/JoystickAxisEvent.hpp>
#include <yq/tachyon/events/JoystickConnectEvent.hpp>
#include <yq/tachyon/events/JoystickDisconnectEvent.hpp>
#include <yq/tachyon/events/JoystickHatEvent.hpp>
#include <yq/tachyon/events/JoystickPressEvent.hpp>
#include <yq/tachyon/events/JoystickReleaseEvent.hpp>
#include <yq/tachyon/events/KeyCharacterEvent.hpp>
#include <yq/tachyon/events/KeyPressEvent.hpp>
#include <yq/tachyon/events/KeyReleaseEvent.hpp>
#include <yq/tachyon/events/KeyRepeatEvent.hpp>
#include <yq/tachyon/events/MonitorConnectEvent.hpp>
#include <yq/tachyon/events/MonitorDisconnectEvent.hpp>
#include <yq/tachyon/events/MouseDropEvent.hpp>
#include <yq/tachyon/events/MouseEnterEvent.hpp>
#include <yq/tachyon/events/MouseLeaveEvent.hpp>
#include <yq/tachyon/events/MouseMoveEvent.hpp>
#include <yq/tachyon/events/MousePressEvent.hpp>
#include <yq/tachyon/events/MouseReleaseEvent.hpp>
#include <yq/tachyon/events/MouseScrollEvent.hpp>
#include <yq/tachyon/events/ViewerDefocusEvent.hpp>
#include <yq/tachyon/events/ViewerFocusEvent.hpp>
#include <yq/tachyon/events/ViewerIconifyEvent.hpp>
#include <yq/tachyon/events/ViewerMaximizeEvent.hpp>
#include <yq/tachyon/events/ViewerMoveEvent.hpp>
#include <yq/tachyon/events/ViewerResizeEvent.hpp>
#include <yq/tachyon/events/ViewerRestoreEvent.hpp>
#include <yq/tachyon/events/ViewerScaleEvent.hpp>

#include <yq/tachyon/exceptions/GLFWException.hpp>

#include <yq/tachyon/requests/ViewerCloseRequest.hpp>
#include <yq/tachyon/requests/ViewerRefreshRequest.hpp>

#include <GLFW/glfw3.h>

namespace yq::tachyon {

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
    
    struct GLFWManager::ViewerData {
        Viewer*         viewer  = nullptr;
        GLFWwindow*     window  = nullptr;
    };

    static constexpr const unsigned kMaxJoysticks   = (unsigned) GLFW_JOYSTICK_LAST + 1;
    struct GLFWManager::Common {
        GLFWManager*                                manager = nullptr;
        std::atomic_flag                            claimed;
        std::array<JoystickData, kMaxJoysticks>     joysticks{};
        std::map<Viewer*, ViewerData>               viewers;
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
        g.manager->dispatch(new KeyCharacterEvent(p));
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
                g.manager->dispatch(new KeyPressEvent(p));
            }
            break;
        case GLFW_RELEASE:
            {
                KeyReleaseEvent::Param    p;
                p.viewer        = v;
                p.modifiers     = _modifiers(window);
                p.scan          = scancode;
                p.key           = keycode_glfw(key);
                g.manager->dispatch(new KeyReleaseEvent(p));
            }
            break;
        case GLFW_REPEAT:
            {
                KeyRepeatEvent::Param    p;
                p.viewer        = v;
                p.modifiers     = _modifiers(window);
                p.scan          = scancode;
                p.key           = keycode_glfw(key);
                g.manager->dispatch(new KeyRepeatEvent(p));
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
                    g.manager->dispatch(new JoystickPressEvent(j,i));
                } else {
                    g.manager->dispatch(new JoystickReleaseEvent(j,i));
                }
                changed = true;
            }
        }
        
        for(size_t i=0;i<jx.state.hats.size();++i){
            if(jx.state.hats[i] != jx.snapshot.hats[i]){
                g.manager->dispatch(new JoystickHatEvent(j, i, (JoystickHatState) jx.state.hats[i]));
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
            g.manager->dispatch(new JoystickConnectEvent(j));
        } else {
            g.manager->dispatch(new JoystickDisconnectEvent(j));
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
            g.manager->dispatch(new MouseEnterEvent(p));
        } else {
            MouseLeaveEvent::Param p;
            p.viewer    = v;
            p.modifiers = _modifiers(window);
            p.buttons   = _buttons(window);
            p.position  = _mouse_pos(window);
            g.manager->dispatch(new MouseLeaveEvent(p));
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
        g.manager->dispatch(new MouseDropEvent(std::move(copy), p));
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
            g.manager->dispatch(new MousePressEvent(p));
        } else {
            MouseReleaseEvent::Param p;
            p.viewer    = v;
            p.modifiers = _modifiers(window);
            p.buttons   = _buttons(window);
            p.position  = _mouse_pos(window);
            p.button    = MouseButton(button);
            g.manager->dispatch(new MouseReleaseEvent(p));
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
        g.manager->dispatch(new MouseScrollEvent(p));
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
            g.manager->dispatch(new MonitorConnectEvent(monitor));
        } else {
            g.manager->dispatch(new MonitorDisconnectEvent(monitor));
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   POLL-LOOP

    void    GLFWManager::_poll(unit::Second timeout)
    {
        if(timeout.value > 0.){
            glfwWaitEventsTimeout(timeout.value);
        } else {
            glfwPollEvents();
        }
        
        for(int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_LAST; ++jid){
            _poll(Joystick(jid));
        }
    }

    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   VIEWERS/WINDOW

    void    GLFWManager::install(Viewer& v)
    {
        static Common& g = common();

        ViewerData& vd = g.viewers[&v];
        vd.viewer       = &v;
        vd.window       = v.window();
        
        glfwSetWindowUserPointer(vd.window, &v);
        
        glfwSetCharCallback(vd.window, callback_character);
        glfwSetCursorEnterCallback(vd.window, callback_cursor_enter);
        glfwSetCursorPosCallback(vd.window, callback_cursor_position);
        glfwSetDropCallback(vd.window, callback_drop);
        //glfwSetFramebufferSizeCallback(vd.window, callback_framebuffer_size);
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
    }
    
    void    GLFWManager::remove(Viewer& v)
    {
        static Common& g = common();
        g.viewers.erase(&v);
    }

    
    #if 0
    void GLFWManager::callback_framebuffer_size(GLFWwindow* window, int width, int height)
    {
    }
    #endif

    void GLFWManager::callback_window_close(GLFWwindow* window)
    {
        static Common& g = common();
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(v){
            g.manager->dispatch(new ViewerCloseRequest(v));
        } else {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    }
    
    void GLFWManager::callback_window_focus(GLFWwindow* window, int focused)
    {
        static Common& g = common();
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;

        if(focused){
            g.manager->dispatch(new ViewerFocusEvent(v));
        } else {
            g.manager->dispatch(new ViewerDefocusEvent(v));
        }
    }
    
    void GLFWManager::callback_window_iconify(GLFWwindow* window, int iconified)
    {
        static Common& g = common();
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;

        if(iconified){
            g.manager->dispatch(new ViewerIconifyEvent(v));
        } else {
            g.manager->dispatch(new ViewerRestoreEvent(v));
        }
    }
    
    void GLFWManager::callback_window_maximize(GLFWwindow* window, int maximized)
    {
        static Common& g = common();
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;

        if(maximized){
            g.manager->dispatch(new ViewerMaximizeEvent(v));
        } else {
            g.manager->dispatch(new ViewerRestoreEvent(v));
        }
    }
    
    void GLFWManager::callback_window_position(GLFWwindow* window, int xpos, int ypos)
    {
        static Common& g = common();
        
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;

        g.manager->dispatch(new ViewerMoveEvent(v, { xpos, ypos }));
    }
    
    void GLFWManager::callback_window_refresh(GLFWwindow* window)
    {
        static Common& g = common();
        
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(v){
            g.manager->dispatch(new ViewerRefreshRequest(v));
        }
    }
    
    void GLFWManager::callback_window_scale(GLFWwindow* window, float xscale, float yscale)
    {
        static Common& g = common();
        
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(v){
            g.manager->dispatch(new ViewerScaleEvent(v, { xscale, yscale }));
        }
    }
    
    void GLFWManager::callback_window_size(GLFWwindow* window, int xsize, int ysize)
    {
        static Common& g = common();
        
        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(v){
            g.manager->dispatch(new ViewerResizeEvent(v, { xsize, ysize }));
        }
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
        _poll(timeout);
    }
    
    static void reg_glfw_manager()
    {
        auto w = writer<GLFWManager>();
        w.abstract();
        w.description("GLFW Manager");
    }
    
    YQ_INVOKE(reg_glfw_manager();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::GLFWManager)
