////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/BasicApp.hpp>
#include <tachyon/app/AppCreateInfo.hpp>
//#include <tachyon/glfw/AppGLFW.hpp>
#include <tachyon/v/VqApp.hpp>
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
        Application(int argc, char* argv[], std::shared_ptr<AppCreateInfo>);
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
        
        TaskEngine*     task_engine() const { return m_taskEngine.get(); }
        
        //! Creates a viewer with widget
        Viewer*         add_viewer(Widget*);
        //! Creates a viewer with title/widget
        Viewer*         add_viewer(std::string_view, Widget*);
        //! Creates a viewer with viewer
        Viewer*         add_viewer(Viewer*);
        
        bool            contains(const Viewer*) const;
        
        /*! \brief Exec loop for a bunch of windows

            \param[in] timeout      If positive, throttles the loop to the rate of user input, where timeout 
                                    is the max stall duration.
        */
        void            run(Second timeout={0.});
        
        
    private:
        friend class Viewer;
        
        static Application*                 s_app;
        
        std::error_code     init();
        void                kill();
        
        virtual bool        vk_init() override;
        
        Viewer*     _add(Viewer*);
        
        //using ExecFN    = std::function<void()>;
        
        //  this is being called by viewer, deletion unnecessary
        void    _remove(Viewer*);
        
        
        std::shared_ptr<AppCreateInfo>      m_appInfo;
        std::unique_ptr<TaskEngine>         m_taskEngine;
        std::vector<Viewer*>                m_viewers;
        std::atomic<bool>                   m_quit;
        
        std::unique_ptr<GLFWManager>        m_glfw;
    };

    void     configure_standand_asset_path();
}
