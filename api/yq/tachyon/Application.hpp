////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/BasicApp.hpp>
#include <tachyon/AppCreateInfo.hpp>
#include <tachyon/typedef/application.hpp>
#include <yq/units.hpp>
#include <memory>
#include <set>
#include <vector>
#include <atomic>

namespace yq::tachyon {

    class TaskEngine;
    class Viewer;
    class Widget;
    class GLFWManager;


    /*! \brief Engine/Vulkan application
    
    */
    class Application : public BasicApp {
    public:
    
        
        //! Creates a viewer with widget
        static Viewer*              add_viewer(Widget*);
        //! Creates a viewer with title/widget
        static Viewer*              add_viewer(std::string_view, Widget*);
        //! Creates a viewer with viewer
        static Viewer*              add_viewer(Viewer*);

        //! Global application, if any
        static Application*       app();

        static const AppCreateInfo& app_info();
        
        static bool                 contains(const Viewer*);
        
        /*! \brief Exec loop for a bunch of windows

            \param[in] timeout      If positive, throttles the loop to the rate of user input, where timeout 
                                    is the max stall duration.
        */
        static void                 run(Second timeout={0.});
        
        
        /*!  Simple exec loop for a single window.
        
            Meant as a convienence function to run a single window in a tight event/draw loop
            until the window is ready to be closed
            
            \param[in] win          Viewer to watch
            \param[in] timeout      If positive, throttles the loop to the rate of user input, where timeout 
                                    is the max stall duration.
        */
        static void    run(Viewer*win, Second timeout={0.});
        

        static TaskEngine*          task_engine();
        
    
        /*! \brief Constructor
        
            \param[in]  argc    Pass onto me what the main() was given
            \param[in]  argv    Pass onto me what the main() was given
            \param[in]  aci     Initialization paraemters for this application
        */
        Application(int argc, char* argv[], const AppCreateInfo& aci=AppCreateInfo());
        ~Application();

    private:
        friend class Viewer;
        
        
        static Viewer*     _add(Viewer*);
        
        //  this is being called by viewer, deletion unnecessary
        static void        _remove(Viewer*);
        

        struct Common;
        static Common&  common();
    };

    void     configure_standand_asset_path();
}
