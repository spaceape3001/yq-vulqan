////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/BasicApp.hpp>
#include <yt/keywords.hpp>
#include <yt/app/AppCreateInfo.hpp>
#include <yt/typedef/application.hpp>
#include <yt/typedef/clock.hpp>
#include <yt/typedef/viewer.hpp>
#include <yt/typedef/widget.hpp>
#include <yq/units.hpp>
#include <memory>
#include <set>
#include <vector>
#include <atomic>

namespace yq::tachyon {
    class AppThread;
    class Desktop;
    class DesktopGLFW;
    class GameThread;
    class IOThread;
    class Manager;
    class NetworkThread;
    class SimThread;
    class TaskThread;
    class Thread;
    class Viewer;
    class ViewerThread;
    class VulqanManager;
    class Widget;

    /*! \brief Engine/Vulkan application
    
    */
    class Application : public BasicApp {
        friend class AppThread;
    public:
    
        struct RunConfig {
        
            /*! \brief ADVISORY time for a tick, zero is full/max rate
            */
            Second      tick    = { 0. };
            
            RunConfig(){}
        };
        

        //! Global application, if any
        static Application*         app() { return s_app; }

        /*! \brief Constructor
        
            \param[in]  argc    Pass onto me what the main() was given
            \param[in]  argv    Pass onto me what the main() was given
            \param[in]  aci     Initialization paraemters for this application
        */
        Application(int argc, char* argv[], const AppCreateInfo& aci=AppCreateInfo());
        ~Application();
        

        const AppCreateInfo&        app_info() const { return m_cInfo; }
        
        //! Creates a viewer with widget (note, application owns it)
        ViewerID                    create(viewer_k, WidgetPtr);
        
        //! Creates a viewer with title/widget
        ViewerID                    create(viewer_k, std::string_view, WidgetPtr);
        
        ViewerID                    create(viewer_k, const ViewerCreateInfo&, WidgetPtr);

        /*! \brief Exec loop for a bunch of windows

            \param[in] timeout      If positive, throttles the loop to the rate of user input, where timeout 
                                    is the max stall duration.
        */
        void                        run(const RunConfig& r = RunConfig());
        
        //! Simple create viewer & run the exec loop
        void                        run(WidgetPtr wid, const RunConfig& r = RunConfig());


        /*! \brief "Starts" the application
        
            This "starts" the application by launching vulqan, the various threads, 
            initializing the platform, loading plugins, etc. 
        */
        bool                        start();    // starts the threads

        //! When we first called "start()"
        const time_point_t&         start_time() const { return m_startTime; }

    private:

        static Application*     s_app;
        
        enum Stage {
            Uninit,
            Started,
            InError,
            Terminated
        };
        
        AppCreateInfo const     m_cInfo;
        std::vector<Desktop*>   m_desktops;
        std::vector<Thread*>    m_threads;
        
        struct {
            AppThread*      app     = nullptr;  //< valid while running
            GameThread*     game    = nullptr;  //< valid while running if "ENABLED" but not "PER"
            IOThread*       io      = nullptr;  //< valid while running if "ENABLED" but not "PER"
            NetworkThread*  network = nullptr;  //< valid while running if "ENABLED" but not "PER"
            SimThread*      sim     = nullptr;  //< valid while running if "ENABLED" but not "PER"
            TaskThread*     task    = nullptr;  //< valid while running if "ENABLED" but not "PER"
            ViewerThread*   viewer  = nullptr;  //< valid while running if "ENABLED" but not "PER"
        } m_thread;

        Desktop*                m_desktop   = nullptr;
        VulqanManager*          m_vulkan    = nullptr;
        time_point_t            m_startTime;
        Stage                   m_stage     = Stage::Uninit;
    
        friend class Viewer;
        
        void    _kill();
    };

    void     configure_standand_asset_path();
}
