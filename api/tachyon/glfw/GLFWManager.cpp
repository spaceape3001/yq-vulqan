////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLFWManager.hpp"
#include <tachyon/app/ManagerInfoWriter.hpp>
#include <tachyon/glfw/Joystick.hpp>
#include <tachyon/glfw/Monitor.hpp>
#include <tachyon/glfw/Window.hpp>
#include <tachyon/input/JoystickConnect.hpp>
#include <GLFW/glfw3.h>
#include <tachyon/logging.hpp>

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
        
        JoystickData<std::span>     state;
        JoystickData<std::vector>   snapshot;
        
        
        bool                        connected   = false;
        bool                        gamepad     = false;

        void                        copy()
        {
            snapshot.axes.assign(state.axes.begin(), state.axes.end());
            snapshot.buttons.assign(state.buttons.begin(), state.buttons.end());
            snapshot.hats.assign(state.hats.begin(), state.hats.end());
        }
    };

    struct GLFWManager::Global {
        enum State { Uninit = 0, Init, Killed };
        static constexpr const unsigned kMaxJoysticks   = (unsigned) GLFW_JOYSTICK_LAST + 1;
        

        GLFWManager*                            manager = nullptr;
        State                                   state   = Uninit;
        std::atomic_flag                        claimed;
        std::array<Joystix, kMaxJoysticks>      joysticks{};
        bool                                    imgui   = false;
        
    };
    
    GLFWManager::Global&  GLFWManager::global()
    {
        static Global s_ret;
        return s_ret;
    }

    GLFWManager*        GLFWManager::manager()
    {
        return global().manager;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
    
    void GLFWManager::callback_joystick(int jid, int event)
    {
        if(jid > Global::kMaxJoysticks)
            return ;
    
        Global& g   = global();
        
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
        
    }
    
    void GLFWManager::callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
    }
    
    void GLFWManager::callback_monitor(GLFWmonitor* monitor, int event)
    {
        #if 0
        
            //  disabled until we can figure out the Monitor thing (because the pointer will be bad after the fact)
        Global& g   = global();
        if(!g.manager)
            return ;
            
        #endif
    }
    
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

    ///////////////////////////////////////////////////////////////////////////

    void GLFWManager::joystick_initialize(Joystick j)
    {
        Global& g = global();
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
        Global& g = global();
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

    GLFWManager::GLFWManager()
    {
        Global&     g = global();
        if(g.claimed.test_and_set())
            return ;
            
        g.manager   = this;

        glfwInfo << "GLFWManager::GLFWManager()";
        glfwLogging(0,nullptr);
        glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);
        glfwInit();
        
        for(int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_LAST; ++jid){
            joystick_initialize(Joystick(jid));
        }
        
        glfwSetJoystickCallback( callback_joystick );
        glfwSetMonitorCallback( callback_monitor );

        g.state     = Global::Init;


    }
    
    GLFWManager::~GLFWManager()
    {
        Global& g   = global();
        if(g.manager != this)
            return;
            
        glfwInfo << "GLFWManager::~GLFWManager()";
        glfwTerminate();
        g.manager   = nullptr;
        g.state     = Global::Killed;
    }


    void    GLFWManager::_poll() 
    {
        glfwPollEvents();
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::GLFWManager)
