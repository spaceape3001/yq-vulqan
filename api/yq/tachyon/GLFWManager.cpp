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

#include <yq/tachyon/events/JoystickConnectEvent.hpp>
#include <yq/tachyon/events/JoystickDisconnectEvent.hpp>
#include <yq/tachyon/events/MonitorConnectEvent.hpp>
#include <yq/tachyon/events/MonitorDisconnectEvent.hpp>

#include <yq/tachyon/exceptions/GLFWException.hpp>

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

        void                        copy()
        {
            snapshot.axes.assign(state.axes.begin(), state.axes.end());
            snapshot.buttons.assign(state.buttons.begin(), state.buttons.end());
            snapshot.hats.assign(state.hats.begin(), state.hats.end());
        }
    };
    
    struct GLFWManager::ViewerData {
        Viewer*         viewer  = nullptr;
        GLFWwindow*     window  = nullptr;
    };

    struct GLFWManager::Common {
        static constexpr const unsigned kMaxJoysticks   = (unsigned) GLFW_JOYSTICK_LAST + 1;
        
        GLFWManager*                                m_manager = nullptr;
        std::atomic_flag                            m_claimed;
        std::array<JoystickData, kMaxJoysticks>     m_joysticks{};
        std::map<Viewer*, ViewerData>               m_viewers;
        bool                                        m_imgui   = false;
        
        void    install(Viewer& v)
        {
            ViewerData& vd = m_viewers[&v];
            vd.viewer   = &v;
            vd.window   = v.window();
        }
        
        void    remove(Viewer &v)
        {
            m_viewers.erase(&v);
        }
        
        
        void    initialize(Joystick j)
        {
            if(j.id >= kMaxJoysticks)
                return ;
            
            auto & jx = m_joysticks[j.id];
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
    };
    
    GLFWManager::Common&  GLFWManager::common()
    {
        static Common s_ret;
        return s_ret;
    }

    GLFWManager*        GLFWManager::manager()
    {
        return common().m_manager;
    }

    void    GLFWManager::install(Viewer& v)
    {
        common().install(v);
    }
    
    void    GLFWManager::remove(Viewer& v)
    {
        common().remove(v);
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
    
        Common& g   = common();
        if(!g.m_manager)
            return ;
            
        Joystick    j(jid);
        g.initialize(j);
        if(event == GLFW_CONNECTED){
            g.m_manager->dispatch(new JoystickConnectEvent(j));
        } else {
            g.m_manager->dispatch(new JoystickDisconnectEvent(j));
        }
    }
    
    #if 0
    void GLFWManager::callback_key(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
    }
    #endif
    
    void GLFWManager::callback_monitor(GLFWmonitor* monitor, int event)
    {
        if(!monitor)
            return ;

        Common& g = common();
        if(event == GLFW_CONNECTED){
            g.m_manager->dispatch(new MonitorConnectEvent(monitor));
        } else {
            g.m_manager->dispatch(new MonitorDisconnectEvent(monitor));
        }
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
            throw GLFWException("GLFW must be created/reside on the main thread");

        add_role(R::Poller);

        Common&     g = common();
        if(g.m_claimed.test_and_set())
            throw GLFWException("Only one GLFWManagers is permitted");
            
        g.m_manager   = this;

        glfwLogging(0,nullptr);
        glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);
        glfwInit();
        
        for(int jid = GLFW_JOYSTICK_1; jid <= GLFW_JOYSTICK_LAST; ++jid){
            g.initialize(Joystick(jid));
        }
        
        glfwSetJoystickCallback( callback_joystick );
        glfwSetMonitorCallback( callback_monitor );
        
        tachyonInfo << "GLFWManager initialized";
    }
    
    GLFWManager::~GLFWManager()
    {
        Common& g   = common();
        if(g.m_manager != this)
            return;
            
        glfwTerminate();
        g.m_manager   = nullptr;

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
