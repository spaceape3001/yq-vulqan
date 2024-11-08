////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/BasicApp.hpp>
#include <yq/tachyon/app/AppCreateInfo.hpp>
#include <yq/tachyon/core/Tachyon.hpp>
#include <yq/tachyon/typedef/application.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/widget.hpp>
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
    class Application : public BasicApp, public Tachyon {
        YQ_OBJECT_DECLARE(Application, Tachyon)
    public:
    
        

        //! Global application, if any
        static Application*         app();

        static const AppCreateInfo& app_info();
        
        //! Creates a viewer with widget
        static Viewer*            create_viewer(Widget*);
        //! Creates a viewer with title/widget
        static Viewer*            create_viewer(std::string_view, Widget*);

        static bool                 contains(const Viewer*&);
        
        static bool                 initialized();
        
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
        static void                 run(Viewer* win, Second timeout={0.});
        
        //! Simple create viewer & exec loop
        static void                 run(Widget* wid, Second timeout={0.});

        static TaskEngine*          task_engine();
        
    
        /*! \brief Constructor
        
            \param[in]  argc    Pass onto me what the main() was given
            \param[in]  argv    Pass onto me what the main() was given
            \param[in]  aci     Initialization paraemters for this application
        */
        Application(int argc, char* argv[], const AppCreateInfo& aci=AppCreateInfo());
        ~Application();

    protected:
        virtual void  receive(const post::PostCPtr&) override;
        
    private:
        friend class Viewer;
        
        
        struct ViewerData;
        
        static void         add(Viewer*);
        
        //  this is being called by viewer, deletion unnecessary
        static void         remove(Viewer*);
        
        static Tachyon::Param  params(const AppCreateInfo&);
        

        struct Common;
        static Common&  common();
    };

    void     configure_standand_asset_path();
}
