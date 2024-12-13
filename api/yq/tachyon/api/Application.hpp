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
    class Desktop;

    /*! \brief Engine/Vulkan application
    
    */
    class Application : public BasicApp {
    public:
    
        

        //! Global application, if any
        static Application*         app() { return s_app; }

        const AppCreateInfo&        app_info() const { return m_cInfo; }
        
        //! Creates a viewer with widget (note, application owns it)
        Viewer*                     create_viewer(WidgetPtr);
        
        //! Creates a viewer with title/widget
        Viewer*                     create_viewer(std::string_view, WidgetPtr);
        
        Viewer*                     create_viewer(const ViewerCreateInfo&, WidgetPtr);

        /*! \brief Exec loop for a bunch of windows

            \param[in] timeout      If positive, throttles the loop to the rate of user input, where timeout 
                                    is the max stall duration.
        */
        void                 run(Second timeout={0.});
        
        
        /*!  Simple exec loop for a single window.
        
            Meant as a convienence function to run a single window in a tight event/draw loop
            until the window is ready to be closed
            
            \param[in] win          Viewer to watch
            \param[in] timeout      If positive, throttles the loop to the rate of user input, where timeout 
                                    is the max stall duration.
        */
        void                 run(ViewerPtr win, Second timeout={0.});
        
        //! Simple create viewer & exec loop
        void                 run(WidgetPtr wid, Second timeout={0.});

        //TaskEngine*          task_engine();
        
        //! Adds a viewer, returns the pointer
        void                 add_viewer(ViewerPtr);
    
        /*! \brief Constructor
        
            \param[in]  argc    Pass onto me what the main() was given
            \param[in]  argv    Pass onto me what the main() was given
            \param[in]  aci     Initialization paraemters for this application
        */
        Application(int argc, char* argv[], const AppCreateInfo& aci=AppCreateInfo());
        ~Application();
        
        static void init_info();

    protected:
        //virtual void  receive(const post::PostCPtr&) override;
        
    private:

        static Application*     s_app;
    
        AppCreateInfo const     m_cInfo;
        std::vector<Desktop*>   m_desktops;
        std::vector<Viewer*>    m_viewers;
        AppThread*              m_athread   = nullptr;
        ViewerThread*           m_vthread   = nullptr;
    
        friend class Viewer;
        
        #if 0
        static Viewer*          _add(ViewerPtr);
        static bool             _contains(const Viewer*);
        static void             _remove(Viewer*);
        
        void    cmd_delete_viewer(const AppDeleteViewerCommand&);
        
        
        //  this is being called by viewer, deletion unnecessary
        
        static Tachyon::Param  params(const AppCreateInfo&);
        

        struct Common;
        static Common&  common();
        #endif
    };

    void     configure_standand_asset_path();
}
