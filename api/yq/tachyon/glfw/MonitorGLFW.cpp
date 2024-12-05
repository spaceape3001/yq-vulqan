////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MonitorGLFW.hpp"
#include <yq/tachyon/api/MonitorInfoWriter.hpp>
#include <GLFW/glfw3.h>

namespace yq::tachyon {

    MonitorGLFW* MonitorGLFW::_monitor(GLFWmonitor*m)
    {
        return (MonitorGLFW*) glfwGetMonitorUserPointer(m);
    }

    MonitorID       MonitorGLFW::monitor(GLFWmonitor*m)
    {
        MonitorGLFW*p  = _monitor(m);
        if(!p)
            return {};
        return p->id();
    }
    
    MonitorGLFW*    MonitorGLFW::monitor(ptr_t, GLFWmonitor*m)
    {
        return _monitor(m);
    }
        
    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    MonitorGLFW::MonitorGLFW(GLFWmonitor* m, const Param&p) : Monitor(p), m_monitor(m)
    {
        assert(m);
        glfwSetMonitorUserPointer(m, this);
        m_position  = _position();
        
    #if 0
        m_state.position    = _position();
        m_state.dimensions  = _dimensions();
        m_state.name        = _name();
        m_state.working     = _working();
        m_state.scale       = _scale();
    #endif
    }
    
    MonitorGLFW::~MonitorGLFW()
    {
    }
    
    Size2MM     MonitorGLFW::_dimensions() const
    {
        Size2I  tmp;
        glfwGetMonitorPhysicalSize(m_monitor, &tmp.x, &tmp.y);
        return {{ (double) tmp.x },{ (double) tmp.y }};
    }

    std::string     MonitorGLFW::_name() const
    {
        const char*z    = glfwGetMonitorName(m_monitor);
        if(!z)
            return {};
        return std::string(z);
    }

    Vector2I    MonitorGLFW::_position() const
    {
        Vector2I    ret;
        glfwGetMonitorPos(m_monitor, &ret.x, &ret.y);
        return ret;
    }

    Vector2F    MonitorGLFW::_scale() const
    {
        Vector2F    ret;
        glfwGetMonitorContentScale(m_monitor, &ret.x, &ret.y);
        return ret;
    }

    Rectangle2I MonitorGLFW::_working() const
    {
        Rectangle2I ret;
        glfwGetMonitorWorkarea(m_monitor, &ret.position.x, &ret.position.y, &ret.size.x, &ret.size.y);
        return ret;
    }

    Vector2I    MonitorGLFW::position2i() const 
    {
        return m_position;
    }

    void MonitorGLFW::snap(MonitorSnap&sn) const
    {
        Monitor::snap(sn);
    }

    Execution MonitorGLFW::tick(Context&ctx) 
    {
        Monitor::tick(ctx);
        if(m_dead)
            return STOP;
            
        set(m_position, _position());
        return {};
    }
    
    void MonitorGLFW::MonitorGLFW::init_info()
    {
        auto w = writer<MonitorGLFW>();
        w.description("GLFW Monitor");
        w.execution(EVERY(5_s));
        w.interface<IPosition2I>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::MonitorGLFW)
