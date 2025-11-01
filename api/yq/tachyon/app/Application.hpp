////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/BasicApp.hpp>
#include <yq/core/Ref.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/app/AppCreateInfo.hpp>
#include <yq/tachyon/app/VulqanConfig.hpp>
#include <yq/tachyon/typedef/application.hpp>
#include <yq/tachyon/typedef/clock.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/widget.hpp>
#include <yq/units.hpp>
#include <tbb/spin_mutex.h>
#include <memory>
#include <set>
#include <vector>
#include <atomic>

namespace yq {
    class Settings;
}

namespace yq::tachyon {
    class AppThread;
    class AudioThread;
    class Desktop;
    class DesktopGLFW;
    class EditThread;
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
    class ViewerCreateCommand;

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
        
        static std::string_view     app_name();

        /*! \brief Constructor
        
            \param[in]  argc    Pass onto me what the main() was given
            \param[in]  argv    Pass onto me what the main() was given
            \param[in]  aci     Initialization paraemters for this application
        */
        Application(int argc, char* argv[], const AppCreateInfo& aci=AppCreateInfo());
        ~Application();
        
        
        const AppCreateInfo&        app_info() const { return m_cInfo; }
        
        //! This is the dynamic settings from the installed configuration file
        const VulqanConfig&         config() const { return m_config; }
        
        const Desktop*              desktop() const { return m_desktop; }
        
        //! Creates a viewer with widget (note, application owns it)
        //! \return Viewer ID if not running, null otherwise
        ViewerID                    create(viewer_k, WidgetPtr);
        
        //! Creates a viewer with title/widget
        //! \return Viewer ID if not running, null otherwise
        ViewerID                    create(viewer_k, std::string_view, WidgetPtr);
        
        //! \note WARNING... viewer ID might not be in the frame immediately....
        //! \return Viewer ID if not running, null otherwise
        ViewerID                    create(viewer_k, const ViewerCreateInfo&, WidgetPtr);

        /*! \brief Exec loop for a bunch of windows

            \param[in] timeout      If positive, throttles the loop to the rate of user input, where timeout 
                                    is the max stall duration.
        */
        void                        run(const RunConfig& r = RunConfig());
        
        //! Simple create viewer & run the exec loop
        void                        run(WidgetPtr wid, const RunConfig& r = RunConfig());

        void                        run(std::span<WidgetPtr> widgets, const RunConfig& r = RunConfig());


        /*! \brief "Starts" the application
        
            This "starts" the application by launching vulqan, the various threads, 
            initializing the platform, loading plugins, etc. 
        */
        virtual bool    start();    // starts the threads
        
        bool                    started() const;
        
        bool                    running() const;

        //! When we first called "start()"
        const time_point_t&         start_time() const { return m_startTime; }

        //! Used by save's reincarnation to start a thread
        void                        start_thread(ThreadPtr);
        
        void                    stop() { _kill(); }

        void                    tick(); // drives the app thread
        void                    vulqan_libraries(load_k);

    protected:
        AppCreateInfo           m_cInfo;
        
        virtual void            configure_vulqan() {}

    private:

        static Application*     s_app;
        
        enum Stage {
            Uninit,
            Started,
            Running,
            InError,
            Shutdown,
            Terminated
        };
        
        std::vector<Desktop*>   m_desktops;
        std::vector<Thread*>    m_threads;
        
        using ViewerThreadVec   = std::vector<Ref<ViewerThread>>;
        using ThreadRefPtrVec   = std::vector<Ref<Thread>>;
        
        struct {
            Ref<AppThread>          app;        //< valid while running
            Ref<AudioThread>        audio;      //< valid while running if "ENABLED" but not "PER"
            Ref<AuxillaryThread>    auxillary;  //< valid while running if "ENABLED" but not "PER"
            Ref<EditThread>         edit;     //< valid while running if "ENABLED" but not "PER"
            Ref<GameThread>         game;       //< valid while running if "ENABLED" but not "PER"
            Ref<IOThread>           io;         //< valid while running if "ENABLED" but not "PER"
            Ref<NetworkThread>      network;    //< valid while running if "ENABLED" but not "PER"
            Ref<SimThread>          sim;        //< valid while running if "ENABLED" but not "PER"
            Ref<TaskThread>         task;       //< valid while running if "ENABLED" but not "PER"
            Ref<ViewerThread>       viewer;     //< valid while running if "ENABLED" but not "PER"
            ViewerThreadVec         viewers;
            ThreadRefPtrVec         others;
        } m_thread;
        
        template <typename T>
        bool    _start(StdThread, Ref<T>&, const thread_spec_t<T>&, std::string_view);

        template <typename T>
        void    _stdthread(StdThread, const thread_spec_t<T>&);
        void    _stdthread(StdThread, const thread_enabler_t&);
        
        using mutex_t       = tbb::spin_mutex;
        using lock_t        = mutex_t::scoped_lock;
        
        mutex_t                     m_mutex;
        Desktop*                    m_desktop   = nullptr;
        VulqanManager*              m_vulkan    = nullptr;
        time_point_t                m_startTime;
        Stage                       m_stage     = Stage::Uninit;
        VulqanConfig                m_config;
    
        friend class Viewer;
        
        void    shutting_down();
        
        void    _kill();
    };

    void     configure_standand_resource_path();
}
