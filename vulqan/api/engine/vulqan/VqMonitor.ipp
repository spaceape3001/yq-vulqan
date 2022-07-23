////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VqMonitor.hpp"
#include <math/Vector2.hpp>
#include <math/Rectangle2.hpp>
#include <math/Size2.hpp>
#include <GLFW/glfw3.h>

namespace yq {
    namespace engine {
        VqVidMode::VqVidMode(const GLFWvidmode&g) : 
            size({g.width, g.height}), 
            bits({ g.redBits, g.greenBits, g.blueBits}), 
            refresh_rate(g.refreshRate)
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////


        std::vector<VqMonitor>   VqMonitor::enumerate()
        {
            std::vector<VqMonitor>  ret;
            int                     count = 0;
            GLFWmonitor**   them    = glfwGetMonitors(&count);
            if(them && (count>0)){
                ret.reserve(count);
                for(int i=0;i<count;++i)
                    ret.push_back(VqMonitor(them[i]));
            }
            return ret;
        }
        
        VqMonitor                VqMonitor::primary()
        {
            return VqMonitor( glfwGetPrimaryMonitor() );
        }


        ////////////////////////////////////////////////////////////////////////////////

        std::string         VqMonitor::name() const
        {
            if(!m_monitor)
                return std::string();
            const char* z   = glfwGetMonitorName(m_monitor);
            if(!z)
                return std::string();
            return std::string(z);
        }
        
        Size2I              VqMonitor::phys_size_mm() const
        {
            if(!m_monitor)
                return {};
            Size2I  ret;
            glfwGetMonitorPhysicalSize(m_monitor, &ret.x, &ret.y);
            return ret;
        }
        
        Vector2I            VqMonitor::position() const
        {
            if(!m_monitor)
                return {};
            Vector2I   ret;
            glfwGetMonitorPos(m_monitor, &ret.x, &ret.y);
            return ret;
        }

        Vector2F            VqMonitor::scale() const
        {
            if(!m_monitor)
                return {};
            Vector2F   ret;
            glfwGetMonitorContentScale(m_monitor, &ret.x, &ret.y);
            return ret;
        }
        
        
        VqVidMode  VqMonitor::video_mode_current() const
        {
            if(!m_monitor)
                return {};
            const GLFWvidmode*  vm  = glfwGetVideoMode(m_monitor);
            if(!vm)
                return {};
            return *vm;
        }

        std::vector<VqVidMode> VqMonitor::video_modes_available() const
        {
            std::vector<VqVidMode> ret;
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

        Rectangle2I         VqMonitor::work_area() const
        {
            if(!m_monitor)
                return {};
            Rectangle2I  ret{};
            glfwGetMonitorWorkarea(m_monitor, &ret.position.x, &ret.position.y, &ret.size.x, &ret.size.y);
            return ret;
        }
    }
}
