////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/BasicApp.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/AppCreateInfo.hpp>
//#include <yq/tachyon/api/Thread.hpp>
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
    class Manager;
    class AppDeleteViewerCommand;
    class AppThread;
    class ViewerThread;
    class Desktop;
    class DesktopGLFW;
    class Vulqan;

    /*! \brief Engine/Vulkan application
    
    */
    class Application : public BasicApp {
        friend class AppThread;
    public:
    
        struct RunConfig {
            Second      tick    = { 0. };
            
            RunConfig(){}
        };
        

        //! Global application, if any
        static Application*         app() { return s_app; }

        const AppCreateInfo&        app_info() const { return m_cInfo; }
        
        //! Creates a viewer with widget (note, application owns it)
        ViewerID                    create(viewer_t, WidgetPtr);
        
        //! Creates a viewer with title/widget
        ViewerID                    create(viewer_t, std::string_view, WidgetPtr);
        
        ViewerID                    create(viewer_t, const ViewerCreateInfo&, WidgetPtr);

        /*! \brief Exec loop for a bunch of windows

            \param[in] timeout      If positive, throttles the loop to the rate of user input, where timeout 
                                    is the max stall duration.
        */
        void                        run(const RunConfig& r = RunConfig());
        
        
        /*!  Simple exec loop for a single window.
        
            Meant as a convienence function to run a single window in a tight event/draw loop
            until the window is ready to be closed
            
            \param[in] win          Widget to watch
            \param[in] timeout      If positive, throttles the loop to the rate of user input, where timeout 
                                    is the max stall duration.
        */
        //void                 run(ViewerPtr win, Second timeout={0.});
        
        //! Simple create viewer & run the exec loop
        void                        run(WidgetPtr wid, const RunConfig& r = RunConfig());

        //TaskEngine*          task_engine();
        
        //! Adds a viewer
        //void                 add_viewer(ViewerPtr);
    
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
        std::vector<Manager*>   m_managers;
        std::set<ViewerID>      m_viewers;
        AppThread*              m_athread   = nullptr;
        ViewerThread*           m_vthread   = nullptr;
        DesktopGLFW*            m_glfw      = nullptr;
        Vulqan*                 m_vulkan    = nullptr;
    
        friend class Viewer;
        
        AppThread&              thread(app_t);
        ViewerThread&           thread(viewer_t);
        DesktopGLFW&            desktop(glfw_t);
        Vulqan&                 manager(vulqan_t);
        
        void    _kill();
        
        
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
