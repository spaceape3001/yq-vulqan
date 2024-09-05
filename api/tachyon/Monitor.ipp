////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/Monitor.hpp>
#include <tachyon/VideoMode.hpp>
#include <yq-toolbox/shape/Rectangle2.hpp>
#include <yq-toolbox/vector/Vector2.hpp>
#include <GLFW/glfw3.h>

namespace yq::tachyon {
    std::vector<Monitor>   Monitor::enumerate()
    {
        std::vector<Monitor>  ret;
        int                     count = 0;
        GLFWmonitor**   them    = glfwGetMonitors(&count);
        if(them && (count>0)){
            ret.reserve(count);
            for(int i=0;i<count;++i)
                ret.push_back(Monitor(them[i]));
        }
        return ret;
    }
    
    Monitor                Monitor::primary()
    {
        return Monitor( glfwGetPrimaryMonitor() );
    }


    ////////////////////////////////////////////////////////////////////////////////

    std::string         Monitor::name() const
    {
        if(!m_monitor)
            return std::string();
        const char* z   = glfwGetMonitorName(m_monitor);
        if(!z)
            return std::string();
        return std::string(z);
    }
    
    Size2I              Monitor::phys_size_mm() const
    {
        if(!m_monitor)
            return {};
        Size2I  ret;
        glfwGetMonitorPhysicalSize(m_monitor, &ret.x, &ret.y);
        return ret;
    }
    
    Vector2I            Monitor::position() const
    {
        if(!m_monitor)
            return {};
        Vector2I   ret;
        glfwGetMonitorPos(m_monitor, &ret.x, &ret.y);
        return ret;
    }

    Vector2F            Monitor::scale() const
    {
        if(!m_monitor)
            return {};
        Vector2F   ret;
        glfwGetMonitorContentScale(m_monitor, &ret.x, &ret.y);
        return ret;
    }
    
    
    VideoMode  Monitor::video_mode_current() const
    {
        if(!m_monitor)
            return {};
        const GLFWvidmode*  vm  = glfwGetVideoMode(m_monitor);
        if(!vm)
            return {};
        return *vm;
    }

    std::vector<VideoMode> Monitor::video_modes_available() const
    {
        std::vector<VideoMode> ret;
        if(m_monitor){
            int     count   = 0;
            const GLFWvidmode*  vms = glfwGetVideoModes(m_monitor, &count);
            if((count>0) && vms){
                ret.reserve(count);
                for(int i=0;i<count;++i)
                    ret.push_back(vms[i]);
            }
        }
        return ret;
    }

    Rectangle2I         Monitor::work_area() const
    {
        if(!m_monitor)
            return {};
        Rectangle2I  ret{};
        glfwGetMonitorWorkarea(m_monitor, &ret.position.x, &ret.position.y, &ret.size.x, &ret.size.y);
        return ret;
    }
}
