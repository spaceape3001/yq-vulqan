////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Application.hpp"
#include "Viewer.hpp"
#include <GLFW/glfw3.h>

namespace yq {
    namespace engine {

        Application::Application(int argc, char *argv[], const AppCreateInfo& ci) : tachyon::Application(argc, argv, ci)
        {
        }
        
        Application::~Application()
        {
        }

        void    Application::run_window(Viewer* win, double amt)
        {
            if(!win)
                return;
            while(!win->should_close()){
                if(amt<=0.){
                    glfwPollEvents();
                } else { 
                    glfwWaitEventsTimeout(amt);
                }
                win->draw();
            }
            
            vkDeviceWaitIdle(win->device());
        }
    }
}
