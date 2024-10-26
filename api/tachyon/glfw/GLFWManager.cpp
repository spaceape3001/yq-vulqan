////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLFWManager.hpp"
#include <tachyon/app/ManagerInfoWriter.hpp>
#include <tachyon/glfw/Joystick.hpp>
#include <tachyon/glfw/Monitor.hpp>
//#include <tachyon/glfw/Window.hpp>
#if 0
#include <tachyon/input/JoystickConnect.hpp>
#include <tachyon/input/JoystickDisconnect.hpp>
#include <tachyon/input/MonitorConnect.hpp>
#include <tachyon/input/MonitorDisconnect.hpp>
#endif
#include <GLFW/glfw3.h>
#include <tachyon/logging.hpp>
#include <yq/core/ThreadId.hpp>

namespace yq::tachyon {

    struct GLFWManager::Joystix {
        
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

        void                        copy()
        {
            snapshot.axes.assign(state.axes.begin(), state.axes.end());
            snapshot.buttons.assign(state.buttons.begin(), state.buttons.end());
            snapshot.hats.assign(state.hats.begin(), state.hats.end());
        }
    };

    struct GLFWManager::Common {
        static constexpr const unsigned kMaxJoysticks   = (unsigned) GLFW_JOYSTICK_LAST + 1;
        

        GLFWManager*                            manager = nullptr;
        std::atomic_flag                        claimed;
        std::array<Joystix, kMaxJoysticks>      joysticks{};
        bool                                    imgui   = false;
        
    };
    
    GLFWManager::Common&  GLFWManager::common()
    {
        static Common s_ret;
        return s_ret;
    }

    GLFWManager*        GLFWManager::manager()
    {
        return common().manager;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    #if 0
    void GLFWManager::callback_character(GLFWwindow* window, unsigned int codepoint)
    {
    }
    
    void GLFWManager::callback_cursor_enter(GLFWwindow* window, int entered)
    {
    }
    
    void GLFWManager::callback_cursor_position(GLFWwindow* window, double xpos, double ypos)
    {
    }
    
    void GLFWManager::callback_drop(GLFWwindow* window, int count, const char** paths)
    {
    }
    
    
    void GLFWManager::callback_framebuffer_size(GLFWwindow* window, int width, int height)
    {
    }
    #endif
    
    void GLFWManager::callback_joystick(int jid, int event)
    {
        if((unsigned) jid > Common::kMaxJoysticks)
            return ;
    
    #if 0
        Common& g   = common();
        
        if(!g.manager)
            return ;
        
        Joystick    j(jid);
        if(event == GLFW_CONNECTED){
            joystick_initialize(j);
            g.manager->publish(new JoystickConnect(j));
        } else if(event == GLFW_DISCONNECTED){
            joystick_kill(j);
            g.manager->publish(new JoystickDisconnect(j));
        }
    #endif
    }
    
    #if 0
    void GLFWManager::callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
    }
    #endif
    
    void GLFWManager::callback_monitor(GLFWmonitor* monitor, int event)
    {
        #if 0
        
            //  disabled until we can figure out the Monitor thing (because the pointer will be bad after the fact)
        Common& g   = common();
        if(!g.manager)
            return ;
            
        #endif
    }
    
    #if 0
    void GLFWManager::callback_mouse_button(GLFWwindow* window, int button, int action, int mods)
    {
    }
    
    void GLFWManager::callback_scroll(GLFWwindow* window, double xoffset, double yoffset)
    {
    }
    
    void GLFWManager::callback_window_close(GLFWwindow* window)
    {
    }
    
    void GLFWManager::callback_window_focus(GLFWwindow* window, int focused)
    {
    }
    
    void GLFWManager::callback_window_iconify(GLFWwindow* window, int iconified)
    {
    }
    
    void GLFWManager::callback_window_maximize(GLFWwindow* window, int maximized)
    {
    }
    
    void GLFWManager::callback_window_position(GLFWwindow* window, int xpos, int ypos)
    {
    }
    
    void GLFWManager::callback_window_refresh(GLFWwindow* window)
    {
    }
    
    void GLFWManager::callback_window_scale(GLFWwindow* window, float xscale, float yscale)
    {
    }
    
    void GLFWManager::callback_window_size(GLFWwindow*, int, int)
    {
    }
    #endif

    ///////////////////////////////////////////////////////////////////////////

    void GLFWManager::joystick_initialize(Joystick j)
    {
        Common& g = common();
        if(j.id >= g.joysticks.size())
            return ;
        
        auto & jx = g.joysticks[j.id];
        if(!j.is_present()){
            jx  = {};
        } else {
            jx.gamepad          = j.is_gamepad();
            jx.state.axes       = j.axes();
            jx.state.buttons    = j.buttons();
            jx.state.hats       = j.hats();
            jx.copy();
        }
        
    }
    
    void GLFWManager::joystick_kill(Joystick j)
    {
        Common& g = common();
        if(j.id >= g.joysticks.size())
            return ;
        g.joysticks[j.id]   = {};
    }

    ///////////////////////////////////////////////////////////////////////////
    

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
            return ;

        add_role(R::Poller);

        Common&     g = common();
        if(g.claimed.test_and_set())
            return ;
            
        g.manager   = this;

        glfwLogging(0,nullptr);
        glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);
        glfwInit();
        
        for(int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_LAST; ++jid){
            joystick_initialize(Joystick(jid));
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
        if(timeout.value > 0.){
            glfwWaitEventsTimeout(timeout.value);
        } else {
            glfwPollEvents();
        }
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
