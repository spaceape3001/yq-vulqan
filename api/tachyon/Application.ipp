////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Application.hpp>
#include <tachyon/Viewer.hpp>
#include <GLFW/glfw3.h>

namespace yq {
    namespace tachyon {
        Application*    Application::s_app    = nullptr;

        void Application::initialize()
        {
            if(s_app)
                s_app -> init();
        }

        //  ////////////////////////////////////////////////////////////////////////

        Application::Application(int argc, char *argv[], const AppCreateInfo& ci) : 
            BasicApp(argc, argv), VqApp(*this, ci)
        {
            if(!s_app)
                s_app   = this;
        }
        
        Application::~Application()
        {
            if(s_app == this)
                s_app   = nullptr;
            kill();
        }


        std::error_code    Application::init()
        { 
            init_glfw();
            return init_vulkan();
        }
            
        void        Application::kill()
        {
            if(this == s_app)
                s_app = nullptr;

            kill_vulkan();
            kill_glfw();
        }

        void    Application::run(Viewer* win, Second amt)
        {
            if(!win)
                return;
            while(!win->should_close()){
                if(amt <= Second(0.)){
                    glfwPollEvents();
                } else { 
                    glfwWaitEventsTimeout(amt.value);
                }
                win->draw();
            }
            
            vkDeviceWaitIdle(win->device());
        }

        bool    Application::vk_init() 
        {
            return init() == std::error_code();
        }
    }
}