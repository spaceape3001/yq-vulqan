////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MonitorGLFW.hpp"
#include <yq/tachyon/api/MonitorInfoWriter.hpp>
#include <GLFW/glfw3.h>

namespace yq::tachyon {

    MonitorGLFW::MonitorGLFW(GLFWmonitor* m, const Param&p) : Monitor(p), m_monitor(m)
    {
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

    void MonitorGLFW::snap(MonitorSnap&sn) const
    {
        Monitor::snap(sn);
    }

    Execution MonitorGLFW::tick(Context&) 
    {
    }
    
    void MonitorGLFW::MonitorGLFW::init_info()
    {
        auto w = writer<MonitorGLFW>();
        w.description("GLFW Monitor");
        w.execution(EVERY(5_s));
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::MonitorGLFW)
