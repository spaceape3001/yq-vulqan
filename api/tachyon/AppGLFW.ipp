////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Logging.hpp>
#include <tachyon/TachyonLog.hpp>
#include <tachyon/AppGLFW.hpp>
#include <GLFW/glfw3.h>

#define glfwWarning         yWarning("glfw")

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
    
    //  ------------------------------------------------

    AppGLFW::AppGLFW()
    {
    }
    
    AppGLFW::~AppGLFW()
    {
        kill_glfw();
    }
    
    void    AppGLFW::init_glfw()
    {
        if(!m_init){
            tachyonInfo << "AppGLFW::init_glfw()";
            glfwLogging(0,nullptr);
            glfwInitHint(GLFW_JOYSTICK_HAT_BUTTONS, GLFW_FALSE);
            glfwInit();
            m_init  = true;
        }
    }
    
    void    AppGLFW::kill_glfw()
    {
        if(m_init){
            tachyonInfo << "AppGLFW::kill_glfw()";
            glfwTerminate();
            m_init  = false;
        }
    }
}

