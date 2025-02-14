////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/core/ThreadId.hpp>
#include <yt/logging.hpp>
#include <yt/app/Application.hpp>
#include <yt/api/Frame.hpp>
#include <yt/api/Context.hpp>
#include <yt/os/DesktopInfoWriter.hpp>
#include <yt/app/ViewerCreateInfo.hpp>

#include <ya/desktops/glfw/CursorGLFW.hpp>
#include <ya/desktops/glfw/DesktopGLFW.hpp>
#include <ya/desktops/glfw/ExceptionGLFW.hpp>
#include <ya/desktops/glfw/GamepadGLFW.hpp>
#include <ya/desktops/glfw/JoystickGLFW.hpp>
#include <ya/desktops/glfw/KeyboardGLFW.hpp>
#include <ya/desktops/glfw/MouseGLFW.hpp>
#include <ya/desktops/glfw/MonitorGLFW.hpp>
#include <ya/desktops/glfw/WindowGLFW.hpp>
#include <ya/desktops/glfw/LoggingGLFW.hpp>

#include <ya/events/gamepad/GamepadConnectEvent.hpp>
#include <ya/events/gamepad/GamepadDisconnectEvent.hpp>

#include <ya/events/joystick/JoystickConnectEvent.hpp>
#include <ya/events/joystick/JoystickDisconnectEvent.hpp>

#include <yq/shape/Size2.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::DesktopGLFW)

namespace yq::tachyon {

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

    DesktopGLFW*     DesktopGLFW::s_desktop = nullptr;

    void DesktopGLFW::callback_joystick(int jid, int event)
    {
        if(!s_desktop)
            return;
        if((unsigned) jid > kCntGLFWJoysticks)
            return ;
        
        if(event == GLFW_CONNECTED){
            s_desktop -> _install(JOYSTICK, jid);
        } else {
            s_desktop -> _uninstall(JOYSTICK, jid);
        }
    }
    
    void DesktopGLFW::callback_monitor(GLFWmonitor* monitor, int event)
    {
        if(!s_desktop)
            return;
        
        // TODO
    }

    DesktopGLFW::DesktopGLFW(const AppCreateInfo&aci, const Param& p) : Desktop(aci, p)
    {
        if(!is_main_thread()){
            throw ExceptionGLFW("GLFW must only be used on the main thread!");
        }
        if(s_desktop){
            throw ExceptionGLFW("Only one GLFW desktop per customer!");
        }
        
        m_joysticks.fill(nullptr);
        m_gamepads.fill(nullptr);
        
        glfwLogging(0, nullptr);
        glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);
        glfwInit();
        
        s_desktop   = this;
    }
    
    DesktopGLFW::~DesktopGLFW()
    {
        glfwTerminate();
        s_desktop   = nullptr;
    }

    void DesktopGLFW::_install(cursor_k, all_k)
    {
        _install(CURSOR, StdCursor::Arrow,          GLFW_ARROW_CURSOR);
        _install(CURSOR, StdCursor::IBeam,          GLFW_IBEAM_CURSOR);
        _install(CURSOR, StdCursor::Crosshair,      GLFW_CROSSHAIR_CURSOR);
        _install(CURSOR, StdCursor::PointingHand,   GLFW_POINTING_HAND_CURSOR);
        _install(CURSOR, StdCursor::ResizeEW,       GLFW_RESIZE_EW_CURSOR);
        _install(CURSOR, StdCursor::ResizeNS,       GLFW_RESIZE_NS_CURSOR);
        _install(CURSOR, StdCursor::ResizeNWSE,     GLFW_RESIZE_NWSE_CURSOR);
        _install(CURSOR, StdCursor::ResizeNESW,     GLFW_RESIZE_NESW_CURSOR);
        _install(CURSOR, StdCursor::ResizeAll,      GLFW_RESIZE_ALL_CURSOR);
        _install(CURSOR, StdCursor::NotAllowed,     GLFW_NOT_ALLOWED_CURSOR);
    }

    bool DesktopGLFW::_install(cursor_k, StdCursor stdC, int glfwId)
    {
        if(m_stdCursors.contains(stdC))
            return false;
        
        GLFWcursor* c   = nullptr;
        {
            //auto  prior = glfwSetErrorCallback(nullptr);
            c           = glfwCreateStandardCursor(glfwId);
            //glfwSetErrorCallback(prior);
        }
        if(!c)
            return false;
            
        CursorGLFW* cc  = create_child<CursorGLFW>(c);
        m_cursors[cc->id()] = cc;
        m_stdCursors[stdC]  = cc->id();
        return true;
    }

    void DesktopGLFW::_install(joystick_k, all_k)
    {
        for(int j=0;j<kCntGLFWJoysticks;++j)
            _install(JOYSTICK, j);
    }

    static bool isReceiver(int jid)
    {
        const char* z   = glfwGetJoystickName(jid);
        if(!z)
            return false;
            
        return static_cast<bool>(strstr(z, "Receiver"));
    }

    bool DesktopGLFW::_install(joystick_k, int jid)
    {
        if((jid < 0) || (jid >=  kCntGLFWJoysticks))
            return false;
        if(!glfwJoystickPresent(jid))
            return false;

        if(m_joysticks[jid] || m_gamepads[jid])
            return false;
        if(isReceiver(jid))
            return false;
        
        //  GAMEPAD distinction... 
        
        if(glfwJoystickIsGamepad(jid)){
            GamepadGLFW*j      = create_child<GamepadGLFW>(jid);
            j->subscribe(id());
            m_gamepads[jid]    = j;
            send(new GamepadConnectEvent({.source=*j}));
        } else {
        
            JoystickGLFW*j      = create_child<JoystickGLFW>(jid);
            j->subscribe(id());
            m_joysticks[jid]    = j;
            send(new JoystickConnectEvent({.source=*j}));
        }
        
        return true;
    }
    
    void DesktopGLFW::_install(monitor_k, all_k)
    {
        int             cnt = 0;
        GLFWmonitor**   ptr = glfwGetMonitors(&cnt);
        if(!cnt || ptr)
            return ;
        for(int i=0;i<cnt;++i)
            _install(MONITOR, ptr[i]);
    }
    
    bool DesktopGLFW::_install(monitor_k, GLFWmonitor*m)
    {
        MonitorID   id  = MonitorGLFW::monitor(m);
        if(id || m_monitors.contains(id))
            return false;
        MonitorGLFW*    mm  = create_child<MonitorGLFW>(m);
        m_monitors[mm->id()]    = mm;
        return true;
    }
        
    MonitorGLFW*    DesktopGLFW::_monitor(MonitorID id)
    {
        auto i = m_monitors.find(id);
        if(i != m_monitors.end())
            return i->second;
        return nullptr;
    }


    void DesktopGLFW::_uninstall(joystick_k, int jid)
    {
        if((jid < 0) || (jid >=  kCntGLFWJoysticks))
            return;
        if(glfwJoystickPresent(jid))
            return;
            
        if(m_joysticks[jid]){
            send(new JoystickDisconnectEvent({.source=*m_joysticks[jid]}));
            m_joysticks[jid] -> cmd_teardown();
            m_joysticks[jid]    = nullptr;
        }
        
        if(m_gamepads[jid]){
            send(new GamepadDisconnectEvent({.source=*m_joysticks[jid]}));
            m_gamepads[jid] -> cmd_teardown();
            m_gamepads[jid] = nullptr;
        }
    }
    
    void DesktopGLFW::_uninstall(monitor_k, GLFWmonitor*)
    {
    }

    PostAdvice  DesktopGLFW::advise(const Post& pp) const 
    {
        PostAdvice  pa  = Desktop::advise(pp);
        if(!unspecified(pa))
            return pa;
    
        if(dynamic_cast<const GamepadEvent*>(&pp) && m_focus)
            return m_focus;
        if(dynamic_cast<const JoystickEvent*>(&pp))
            return m_focus;
        
        return {};
    }

    Window*     DesktopGLFW::create(window_k, const ViewerCreateInfo& vci)
    {
        return create_window(vci);
    }
    
    WindowGLFW*   DesktopGLFW::create_window(const ViewerCreateInfo& vci) 
    {
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
        
        GLFWmonitor*    m   = nullptr;
        if(vci.monitor){
            MonitorGLFW* mm   = _monitor(vci.monitor);
            if(!mm){
                glfwCritical << "Unable to find specified monitor.";
                return nullptr;
            }
            
            m   = mm->glfw();
            if(!m){
                glfwCritical << "Unable to find specified monitor.";
                return nullptr;
            }
        }
    
    
        GLFWwindow* ww  = glfwCreateWindow(wx, wy, title.c_str(), m, nullptr);
        if(!ww){
            const char* description = nullptr;
            glfwGetError(&description);
            if(description)
                glfwCritical << "Unable to create GLFW window.  " << description;
            return nullptr;
        }
        
        WindowGLFW* w       = create_child<WindowGLFW>(this, ww, vci);
        m_windows[w->id()]  = w;
        return w;
    }

    CursorID  DesktopGLFW::cursor(StdCursor sc) const 
    {
        auto i = m_stdCursors.find(sc);
        if(i != m_stdCursors.end())
            return i->second;
        return {};
    }


    Execution    DesktopGLFW::setup(const Context& ctx)
    {
        if(!m_init){
            if(m_control(C::Cursor)){
                _install(CURSOR, ALL);
            }
            if(m_control(C::Joystick)){
                _install(JOYSTICK, ALL);
                glfwSetJoystickCallback( callback_joystick );
            }
            if(m_control(C::Keyboard)){
                m_keyboard      = create_child<KeyboardGLFW>();
            }
            if(m_control(C::Monitor)){
                _install(MONITOR, ALL);
                m_monitor   = MonitorGLFW::monitor(PTR, glfwGetPrimaryMonitor());
                glfwSetMonitorCallback( callback_monitor );
            }
            if(m_control(C::Mouse)){
                m_mouse         = create_child<MouseGLFW>();
            }
            if(m_control(C::Window)){
                // this one might not be necessary
            }
            m_init = true;
        }
        return Desktop::setup(ctx);
    }

    Execution    DesktopGLFW::teardown(const Context& ctx)
    {
        if(m_init){
            bool    torn    = true;
            const Frame*    f   = Frame::current();
            if(f){
                f->foreach<Tachyon>(PTR, children(), [&](Tachyon* t) {
                    if(!t)
                        return;
                    if(!t->dying())
                        t->cmd_teardown();
                    if(!t->kaput())
                        torn    = false;
                });
            }
            if(!torn)
                return WAIT;
        }
        return Desktop::teardown(ctx);
    }
    
    Execution    DesktopGLFW::tick(const Context& ctx)
    {
        glfwPollEvents();
        return {};
    }

    void DesktopGLFW::init_info()
    {
        auto w = writer<DesktopGLFW>();
        w.description("GLFW Desktop");
        w.execution(ALWAYS);
    }
}
