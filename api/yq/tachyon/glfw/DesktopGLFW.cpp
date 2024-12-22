////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DesktopGLFW.hpp"
#include <yq/core/ThreadId.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Application.hpp>
#include <yq/tachyon/api/Context.hpp>
#include <yq/tachyon/api/DesktopInfoWriter.hpp>
#include <yq/tachyon/api/ViewerCreateInfo.hpp>
#include <yq/tachyon/glfw/CursorGLFW.hpp>
#include <yq/tachyon/glfw/ExceptionGLFW.hpp>
#include <yq/tachyon/glfw/JoystickGLFW.hpp>
#include <yq/tachyon/glfw/KeyboardGLFW.hpp>
#include <yq/tachyon/glfw/MouseGLFW.hpp>
#include <yq/tachyon/glfw/MonitorGLFW.hpp>
#include <yq/tachyon/glfw/WindowGLFW.hpp>
#include <yq/tachyon/glfw/LoggingGLFW.hpp>

#include <yq/shape/Size2.hxx>
#include <GLFW/glfw3.h>

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
            
        // TODO
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
        
        glfwLogging(0, nullptr);
        glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);
        glfwInit();
        
        m_stage = Stage::Init;
        s_desktop   = this;
        tachyonInfo << "DesktopGFLW initialized";
    }
    
    DesktopGLFW::~DesktopGLFW()
    {
        tachyonInfo << "DesktopGFLW terminated";
        glfwTerminate();
        s_desktop   = nullptr;
    }

    void DesktopGLFW::_install(cursor_t, all_t)
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

    bool DesktopGLFW::_install(cursor_t, StdCursor stdC, int glfwId)
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
            
        CursorGLFW* cc  = create<CursorGLFW>(CHILD, c);
        m_cursors[cc->id()] = cc;
        m_stdCursors[stdC]  = cc->id();
        return true;
    }

    void DesktopGLFW::_install(joystick_t, all_t)
    {
        for(int j=0;j<kCntGLFWJoysticks;++j)
            _install(JOYSTICK, j);
    }

    bool DesktopGLFW::_install(joystick_t, int jid)
    {
        if((jid < 0) || (jid >=  kCntGLFWJoysticks))
            return false;
        if(!glfwJoystickPresent(jid))
            return false;
        if(m_joysticks[jid])
            return false;
        
        m_joysticks[jid]    = create<JoystickGLFW>(CHILD, jid);
        return true;
    }
    
    void DesktopGLFW::_install(monitor_t, all_t)
    {
        int             cnt = 0;
        GLFWmonitor**   ptr = glfwGetMonitors(&cnt);
        if(!cnt || ptr)
            return ;
        for(int i=0;i<cnt;++i)
            _install(MONITOR, ptr[i]);
    }
    
    bool DesktopGLFW::_install(monitor_t, GLFWmonitor*m)
    {
        MonitorID   id  = MonitorGLFW::monitor(m);
        if(id || m_monitors.contains(id))
            return false;
        MonitorGLFW*    mm  = create<MonitorGLFW>(CHILD, m);
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

    Execution    DesktopGLFW::_start(Context& ctx)
    {
        if(m_control(C::Cursor)){
            _install(CURSOR, ALL);
        }
        if(m_control(C::Joystick)){
            _install(JOYSTICK, ALL);
            glfwSetJoystickCallback( callback_joystick );
        }
        if(m_control(C::Keyboard)){
            m_keyboard      = create<KeyboardGLFW>(CHILD);
        }
        if(m_control(C::Monitor)){
            _install(MONITOR, ALL);
            m_monitor   = MonitorGLFW::monitor(PTR, glfwGetPrimaryMonitor());
            glfwSetMonitorCallback( callback_monitor );
        }
        if(m_control(C::Mouse)){
            m_mouse         = create<MouseGLFW>(CHILD);
        }
        if(m_control(C::Window)){
            // this one might not be necessary
        }
        
        m_stage = Stage::Running;
        return {};
    }
    
    Execution    DesktopGLFW::_tick(Context& ctx)
    {
//tachyonInfo << "DesktopGLFW::_tick(Context& ctx)";
        glfwPollEvents();
        return {};
    }

    void DesktopGLFW::_uninstall(joystick_t, int)
    {
    }
    
    void DesktopGLFW::_uninstall(monitor_t, GLFWmonitor*)
    {
    }

    Window*     DesktopGLFW::create(window_t, const ViewerCreateInfo& vci)
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
        
        WindowGLFW* w       = create<WindowGLFW>(CHILD, this, ww, vci);
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

    bool      DesktopGLFW::is_running() const 
    { 
        return m_stage == Stage::Running;
    }
    
    Execution DesktopGLFW::tick(Context& ctx)
    {
        Desktop::tick(ctx);
        switch(m_stage){
        case Stage::Uninit:
            return ERROR;
        case Stage::Init:
            return _start(ctx);
        case Stage::Running:
            return _tick(ctx);
        case Stage::Dead:
        default:
            return ERROR;
        }
    }

    void DesktopGLFW::init_info()
    {
        auto w = writer<DesktopGLFW>();
        w.description("GLFW Desktop");
        w.execution(ALWAYS);
    }
}
