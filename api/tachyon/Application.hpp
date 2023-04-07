////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/BasicApp.hpp>
#include <basic/DbgRel.hpp>
#include <tachyon/AppCreateInfo.hpp>
#include <tachyon/host/AppGLFW.hpp>
#include <tachyon/gpu/VqApp.hpp>
#include <math/units.hpp>
#include <set>
#include <vector>

namespace yq {
    namespace tachyon {

        /*! \brief Engine/Vulkan application
        
        */
        class Application : public BasicApp, public AppGLFW, public VqApp {
        public:
        
            //! Global application, if any
            static Application*       app() { return s_app; }
            
        
            /*! \brief Constructor
            
                \param[in]  argc    Pass onto me what the main() was given
                \param[in]  argv    Pass onto me what the main() was given
                \param[in]  aci     Initialization paraemters for this application
            */
            Application(int argc, char* argv[], const AppCreateInfo& aci=AppCreateInfo());
            ~Application();
            
            /*!  Simple exec loop for a single window.
            
                Meant as a convienence function to run a single window in a tight event/draw loop
                until the window is ready to be closed
                
                \param[in] win          Viewer to watch
                \param[in] timeout      If positive, throttles the loop to the rate of user input, where timeout 
                                        is the max stall duration.
            */
            void    run(Viewer*win, Second timeout={0.});
            
            static void initialize();
            
            
        private:
            friend class Viewer;
            
            static Application*                 s_app;
            
            std::error_code     init();
            void                kill();
            
            virtual bool        vk_init() override;
        };

    }
}
