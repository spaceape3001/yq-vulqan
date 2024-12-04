////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/BasicApp.hpp>
#include <yq/tachyon/api/AppCreateInfo.hpp>
#include <yq/tachyon/api/Thread.hpp>
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
    class AppDeleteViewerCommand;
    class AppThread;
    class ViewerThread;

    /*! \brief Engine/Vulkan application
    
    */
    class Application : public BasicApp {
    public:
    
        

        //! Global application, if any
        static Application*         app();

        const AppCreateInfo&        app_info() const;
        
        //! Creates a viewer with widget (note, application owns it)
        static Viewer*              create_viewer(WidgetPtr);
        //! Creates a viewer with title/widget
        static Viewer*              create_viewer(std::string_view, WidgetPtr);
        
        static Viewer*              create_viewer(const ViewerCreateInfo&, WidgetPtr);

        
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
        static void                 run(ViewerPtr win, Second timeout={0.});
        
        //! Simple create viewer & exec loop
        static void                 run(WidgetPtr wid, Second timeout={0.});

        static TaskEngine*          task_engine();
        
        //! Adds a viewer, returns the pointer
        static void                 add_viewer(ViewerPtr);
    
        /*! \brief Constructor
        
            \param[in]  argc    Pass onto me what the main() was given
            \param[in]  argv    Pass onto me what the main() was given
            \param[in]  aci     Initialization paraemters for this application
        */
        Application(int argc, char* argv[], const AppCreateInfo& aci=AppCreateInfo());
        ~Application();
        
        static void init_info();

    protected:
        virtual void  receive(const post::PostCPtr&) override;
        
    private:
    
        AppThread*              m_athread   = nullptr;
        ViewerThread*           m_vthread   = nullptr;
    
        friend class Viewer;
        
        static Viewer*          _add(ViewerPtr);
        static bool             _contains(const Viewer*);
        static void             _remove(Viewer*);
        
        void    cmd_delete_viewer(const AppDeleteViewerCommand&);
        
        
        //  this is being called by viewer, deletion unnecessary
        
        static Tachyon::Param  params(const AppCreateInfo&);
        
        static Application*     s_app;
        
        AppCreateInfo const     m_cInfo;

        struct Common;
        static Common&  common();
    };

    void     configure_standand_asset_path();
}
