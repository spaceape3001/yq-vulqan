////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/os/glfw/MonitorGLFW.hpp>
#include <tachyon/event/spatial/Position2Event.hpp>
#include <tachyon/event/spatial/Scale2Event.hpp>
#include <tachyon/event/spatial/Size2Event.hpp>
#include <tachyon/os/MonitorMetaWriter.hpp>
#include <GLFW/glfw3.h>

namespace yq::tachyon {

    MonitorGLFW* MonitorGLFW::_monitor(GLFWmonitor*m)
    {
        if(!m)
            return nullptr;
        return (MonitorGLFW*) glfwGetMonitorUserPointer(m);
    }

    MonitorID       MonitorGLFW::monitor(GLFWmonitor*m)
    {
        MonitorGLFW*p  = _monitor(m);
        if(!p)
            return {};
        return p->id();
    }
    
    MonitorGLFW*    MonitorGLFW::monitor(ptr_k, GLFWmonitor*m)
    {
        return _monitor(m);
    }
        
    //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    MonitorGLFW::MonitorGLFW(GLFWmonitor* m, const Param&p) : Monitor(p), m_monitor(m)
    {
        assert(m);
        glfwSetMonitorUserPointer(m, this);
        m_position      = _position();
        m_dimensions    = _dimensions();
        
    #if 0
        m_state.position    = _position();
        m_state.name        = _name();
        m_state.working     = _working();
        m_state.scale       = _scale();
    #endif
    }
    
    MonitorGLFW::~MonitorGLFW()
    {
    }
    
    
        ////////////////////////////////////////
    
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

        ////////////////////////////////////////

    Size2MM     MonitorGLFW::dimensions() const
    {
        return m_dimensions;
    }

    Vector2D    MonitorGLFW::position() const 
    {
        return m_position.cast<double>();
    }

    Size2D      MonitorGLFW::size() const 
    {
        return m_size;
    }

    Vector2F    MonitorGLFW::scale() const 
    {
        return m_scale;
    }

    void MonitorGLFW::snap(MonitorSnap&sn) const
    {
        Monitor::snap(sn);
        sn.size             = m_size;
        sn.scale            = m_scale;
        sn.dimensions       = m_dimensions;
    }

    Execution MonitorGLFW::tick(const Context&ctx) 
    {
        Monitor::tick(ctx);
        if(m_dead)
            return TEARDOWN;
            
        if(set(m_position, _position())){
            send(new Position²Event({.source=this}, m_position.cast<double>()));
        }
        
        const GLFWvidmode*  vm  =  glfwGetVideoMode(m_monitor);
        if(vm != m_mode){
            if(set(m_depth, RGB3I( vm->redBits, vm->greenBits, vm->blueBits ))){
                // TODO: when we have color depth event, send it here
            }
            if(set(m_size, Size2D( vm->width, vm->height))){
                send(new Size²Event({.source=this}, m_size));
            }
            m_mode      = vm;
        }
        
        if(set(m_scale, _scale())){
            send(new Scale²Event({.source=this}, m_scale.cast<double>()));
        }
        
        return {};
    }
    
    void MonitorGLFW::MonitorGLFW::init_meta()
    {
        auto w = writer<MonitorGLFW>();
        w.description("GLFW Monitor");
        w.execution(EVERY(5_s));
        w.interface<IPosition²>();
        w.interface<ISize²>();
        w.interface<IScale²>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::MonitorGLFW)
