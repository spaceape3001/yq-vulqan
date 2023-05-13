////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Joystick.hpp>
#include <GLFW/glfw3.h>

namespace yq::tachyon {
    std::vector<Joystick>  Joystick::gamepads()
    {
        std::vector<Joystick>     ret;
        
        for(int jid = GLFW_JOYSTICK_1; jid<=GLFW_JOYSTICK_LAST; ++jid){
            if(glfwJoystickIsGamepad(jid) == GLFW_TRUE)
                ret.push_back({ (uint8_t) jid });
        }
        
        return ret;
    }
    
    std::vector<Joystick>  Joystick::joysticks()
    {
        std::vector<Joystick>     ret;

        for(int jid = GLFW_JOYSTICK_1; jid<=GLFW_JOYSTICK_LAST; ++jid){
            if(glfwJoystickPresent(jid) == GLFW_TRUE)
                ret.push_back({ (uint8_t) jid });
        }
        
        return ret;
    }
    
    //  ------------------------------------------------------------------------------------------------------------
    
    std::span<const float>  Joystick::axes() const
    {
        int             count= 0;
        const float*    z   = glfwGetJoystickAxes(id, &count);
        if(!z)
            return std::span<const float>();
        return std::span<const float>(z, count);
    }
    
    unsigned int  Joystick::axes_count() const
    {
        int  count= 0;
        if(glfwGetJoystickAxes(id, &count))
            return (unsigned int) count;
        return 0;
    }

    unsigned int  Joystick::button_count() const
    {
        int  count= 0;
        if(glfwGetJoystickButtons(id, &count))
            return (unsigned int) count;
        return 0;
    }

    std::span<const unsigned char>  Joystick::buttons() const
    {
        int   count= 0;
        const unsigned char*    z   = glfwGetJoystickButtons(id, &count);
        if(!z)
            return std::span<const unsigned char>();
        return std::span<const unsigned char>(z, count);
    }
    
    std::string_view  Joystick::guid() const
    {
        const char* z   = glfwGetJoystickGUID(id);
        if(!z)
            return std::string_view();
        return std::string_view(z);
    }

    std::span<const unsigned char>  Joystick::hats() const
    {
        int             count= 0;
        const unsigned char*    z   = glfwGetJoystickHats(id, &count);
        if(!z)
            return std::span<const unsigned char>();
        return std::span<const unsigned char>(z, count);
    }
    
    bool  Joystick::is_gamepad() const
    {
        return glfwJoystickIsGamepad(id);
    }
    
    bool  Joystick::is_present() const
    {
        return glfwJoystickPresent(id);
    }

    std::string_view  Joystick::name() const
    {
        const char* z   = glfwGetJoystickName(id);
        if(!z)
            return std::string_view();
        return std::string_view(z);
    }
    

    void  Joystick::set_user_data(void* pointer)
    {
        glfwSetJoystickUserPointer(id, pointer);
    }
    
    void*  Joystick::user_data() const
    {
        return glfwGetJoystickUserPointer(id);
    }
}
