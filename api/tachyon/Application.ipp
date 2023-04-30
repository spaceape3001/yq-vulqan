////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Application.hpp>
#include <tachyon/Viewer.hpp>
#include <tachyon/task/TaskEngine.hpp>
#include <GLFW/glfw3.h>

namespace yq::tachyon {
    Application*    Application::s_app    = nullptr;

    void Application::initialize()
    {
        if(s_app)
            s_app -> init();
    }

    //  ////////////////////////////////////////////////////////////////////////

    Application::Application(int argc, char* argv[], std::shared_ptr<AppCreateInfo> aci) : 
        BasicApp(argc, argv), VqApp(*this, aci), m_appInfo(aci)
    {
        assert(m_appInfo && "AppCreateInfo is not optional, it must be supplied.");
        if(!s_app)
            s_app   = this;
    }
    

    Application::Application(int argc, char *argv[], const AppCreateInfo& aci) : 
        Application(argc, argv, std::make_shared<AppCreateInfo>(aci))
    {
    }
    
    Application::~Application()
    {
        if(s_app == this)
            s_app   = nullptr;
        kill();
    }


    std::error_code    Application::init()
    { 
        if(m_appInfo->want_tasking)
            m_taskEngine    = std::make_unique<TaskEngine>();
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
            if(m_taskEngine)            // eventually be smarter about this... multithreading
                m_taskEngine -> step();
            
            win->draw();
        }
        
        vkDeviceWaitIdle(win->device());
    }

    bool    Application::vk_init() 
    {
        return init() == std::error_code();
    }
}
