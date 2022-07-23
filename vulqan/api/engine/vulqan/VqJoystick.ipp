////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

//#pragma once

#include "VqJoystick.hpp"
#include <GLFW/glfw3.h>

namespace yq {
    namespace engine {
        std::vector<VqJoystick>  VqJoystick::gamepads()
        {
            std::vector<VqJoystick>     ret;
            
            for(int jid = GLFW_JOYSTICK_1; jid<=GLFW_JOYSTICK_LAST; ++jid){
                if(glfwJoystickIsGamepad(jid) == GLFW_TRUE)
                    ret.push_back({ (uint8_t) jid });
            }
            
            return ret;
        }
        
        std::vector<VqJoystick>  VqJoystick::joysticks()
        {
            std::vector<VqJoystick>     ret;

            for(int jid = GLFW_JOYSTICK_1; jid<=GLFW_JOYSTICK_LAST; ++jid){
                if(glfwJoystickPresent(jid) == GLFW_TRUE)
                    ret.push_back({ (uint8_t) jid });
            }
            
            return ret;
        }
        
        //  ------------------------------------------------------------------------------------------------------------
        
        std::span<const float>  VqJoystick::axes() const
        {
            int             count= 0;
            const float*    z   = glfwGetJoystickAxes(id, &count);
            if(!z)
                return std::span<const float>();
            return std::span<const float>(z, count);
        }
        
        unsigned int  VqJoystick::axes_count() const
        {
            int  count= 0;
            if(glfwGetJoystickAxes(id, &count))
                return (unsigned int) count;
            return 0;
        }
    
        unsigned int  VqJoystick::button_count() const
        {
            int  count= 0;
            if(glfwGetJoystickButtons(id, &count))
                return (unsigned int) count;
            return 0;
        }

        std::span<const unsigned char>  VqJoystick::buttons() const
        {
            int   count= 0;
            const unsigned char*    z   = glfwGetJoystickButtons(id, &count);
            if(!z)
                return std::span<const unsigned char>();
            return std::span<const unsigned char>(z, count);
        }
        
        std::string_view  VqJoystick::guid() const
        {
            const char* z   = glfwGetJoystickGUID(id);
            if(!z)
                return std::string_view();
            return std::string_view(z);
        }

        std::span<const unsigned char>  VqJoystick::hats() const
        {
            int             count= 0;
            const unsigned char*    z   = glfwGetJoystickHats(id, &count);
            if(!z)
                return std::span<const unsigned char>();
            return std::span<const unsigned char>(z, count);
        }
        
        bool  VqJoystick::is_gamepad() const
        {
            return glfwJoystickIsGamepad(id);
        }
        
        bool  VqJoystick::is_present() const
        {
            return glfwJoystickPresent(id);
        }

        std::string_view  VqJoystick::name() const
        {
            const char* z   = glfwGetJoystickName(id);
            if(!z)
                return std::string_view();
            return std::string_view(z);
        }
        

        void  VqJoystick::set_user_data(void* pointer)
        {
            glfwSetJoystickUserPointer(id, pointer);
        }
        
        void*  VqJoystick::user_data() const
        {
            return glfwGetJoystickUserPointer(id);
        }
    }
}
