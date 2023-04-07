////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Application.hpp>
#include <tachyon/AppCreateInfo.hpp>
#include <set>
#include <vector>

struct VkInstance_T;

namespace yq {
    namespace engine {

        class Application;
        class Viewer;
        
        /*! \brief Engine/Vulkan application
        
        */
        class Application : public tachyon::Application {
        public:
        
        
            /*! \brief Constructor
            
                \param[in]  argc    Pass onto me what the main() was given
                \param[in]  argv    Pass onto me what the main() was given
                \param[in]  aci     Initialization paraemters for this application
            */
            Application(int argc, char* argv[], const AppCreateInfo& aci=AppCreateInfo());
            ~Application();
            
            
            //void    run();
            
            /*!  Simple exec loop for a single window.
            
                Meant as a convienence function to run a single window in a tight event/draw loop
                until the window is ready to be closed
                
                \param[in] win          Viewer to watch
                \param[in] timeout      If positive, throttles the loop to the rate of user input, where timeout 
                                        is the max stall duration.
            */
            void    run_window(Viewer*win, double timeout=0.);
        };

    }
}
