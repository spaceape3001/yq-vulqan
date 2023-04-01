////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Application.hpp"
#include "Viewer.hpp"

#include <basic/Logging.hpp>
#include <GLFW/glfw3.h>


using namespace yq::tachyon;

namespace yq {
    namespace engine {

        Application*    Application::s_app    = nullptr;


        //  ////////////////////////////////////////////////////////////////////////

        Application::Application(int argc, char *argv[], const AppCreateInfo& ci) : 
            BasicApp(argc, argv), VqApp(*this, ci)
        {
        }
        
        Application::~Application()
        {
            kill();
        }


        bool    Application::init()
        { 
            init_glfw();
            std::error_code ec = init_vulkan();
            return !ec;
        }
            
        void        Application::kill()
        {
            if(this == s_app)
                s_app = nullptr;

            kill_vulkan();
            kill_glfw();
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

        bool    Application::vk_init() 
        {
            return init();
        }

    }
}
