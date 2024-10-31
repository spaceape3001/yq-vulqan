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
#include <yq/tachyon/events/KeyPressEvent.hpp>
#include <yq/tachyon/events/KeyReleaseEvent.hpp>
#include <yq/tachyon/events/MonitorConnectEvent.hpp>
#include <yq/tachyon/events/MonitorDisconnectEvent.hpp>

#include <yq/tachyon/exceptions/GLFWException.hpp>

#include <yq/tachyon/requests/ViewerCloseRequest.hpp>

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
    //   CALLBACKS

    #if 0
    void GLFWManager::callback_character(GLFWwindow* window, unsigned int codepoint)
    {
    }
    #endif
    
    #if 0
    void GLFWManager::callback_cursor_enter(GLFWwindow* window, int entered)
    {
    }
    #endif
    
    #if 0
    void GLFWManager::callback_cursor_position(GLFWwindow* window, double xpos, double ypos)
    {
    }
    #endif
    
    #if 0
    void GLFWManager::callback_drop(GLFWwindow* window, int count, const char** paths)
    {
    }
    #endif
    
    #if 0
    void GLFWManager::callback_framebuffer_size(GLFWwindow* window, int width, int height)
    {
    }
    #endif
    
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
    
    void GLFWManager::callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        static Common& g = common();

        Viewer*v    = (Viewer*) glfwGetWindowUserPointer(window);
        if(!v)
            return ;
            
        if(action == GLFW_PRESS){
            KeyPressEvent::Param    p;
            p.viewer        = v;
            p.modifiers     = _modifiers(window);
            p.scan          = scancode;
            p.key           = keycode_glfw(key);
            g.manager->dispatch(new KeyPressEvent(p));
        } else {
            KeyReleaseEvent::Param    p;
            p.viewer        = v;
            p.modifiers     = _modifiers(window);
            p.scan          = scancode;
            p.key           = keycode_glfw(key);
            g.manager->dispatch(new KeyReleaseEvent(p));
        }
    }
    
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
    
    #if 0
    void GLFWManager::callback_mouse_button(GLFWwindow* window, int button, int action, int mods)
    {
        static Common& g = common();
    }
    #endif
    
    #if 0
    void GLFWManager::callback_scroll(GLFWwindow* window, double xoffset, double yoffset)
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
    
    #if 0
    void GLFWManager::callback_window_focus(GLFWwindow* window, int focused)
    {
        static Common& g = common();
    }
    #endif
    
    #if 0
    void GLFWManager::callback_window_iconify(GLFWwindow* window, int iconified)
    {
        static Common& g = common();
    }
    #endif
    
    #if 0
    void GLFWManager::callback_window_maximize(GLFWwindow* window, int maximized)
    {
        static Common& g = common();
    }
    #endif
    
    #if 0
    void GLFWManager::callback_window_position(GLFWwindow* window, int xpos, int ypos)
    {
    }
    #endif
    
    #if 0
    void GLFWManager::callback_window_refresh(GLFWwindow* window)
    {
    }
    #endif
    
    #if 0
    void GLFWManager::callback_window_scale(GLFWwindow* window, float xscale, float yscale)
    {
    }
    #endif
    
    #if 0
    void GLFWManager::callback_window_size(GLFWwindow*, int, int)
    {
    }
    #endif
        
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   INFORMATION/PROBING
    
    bool    GLFWManager::raw_mouse_motion_supported()
    {
        return glfwRawMouseMotionSupported() == GLFW_TRUE;
    }

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

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //   POLL-LOOP

    void    GLFWManager::_poll(unit::Second timeout)
    {
        Common& g   = common();

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
    //   VIEWERS

    void    GLFWManager::install(Viewer& v)
    {
        static Common& g = common();

        ViewerData& vd = g.viewers[&v];
        vd.viewer       = &v;
        vd.window       = v.window();
        
        glfwSetWindowUserPointer(vd.window, &v);
        
        glfwSetKeyCallback(vd.window, callback_key);
        glfwSetWindowCloseCallback(vd.window, callback_window_close);
    }
    


    void    GLFWManager::remove(Viewer& v)
    {
        static Common& g = common();
        g.viewers.erase(&v);
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
