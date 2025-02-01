////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/logging.hpp>
#include <yt/ui/Widget.hpp>
#include <yt/app/AppException.hpp>
#include <yt/app/AppThread.hpp>
#include <yt/app/Application.hpp>
#include <yt/app/TaskThread.hpp>
#include <yt/app/Viewer.hpp>
#include <yt/app/ViewerThread.hpp>
#include <yt/os/Window.hpp>
//#include <yt/api/TachyonInfoWriter.hpp>
#include <yv/VulqanManager.hpp>

//#include <ya/commands/AppDeleteViewerCommand.hpp>
#include <ya/desktops/glfw/DesktopGLFW.hpp>
//#include <yq/tachyon/task/TaskEngine.hpp>

#include <yq/asset/Asset.hpp>
#include <yq/core/ThreadId.hpp>
#include <yq/core/Cleanup.hpp>
#include <yq/meta/Init.hpp>
//#include <yq/post/boxes/SimpleBox.hpp>
#include <yt/config/build.hpp>

//YQ_OBJECT_IMPLEMENT(yq::tachyon::Application)

namespace yq::tachyon {

    static AppCreateInfo    _update(const AppCreateInfo& aci, std::string_view appName)
    {
        AppCreateInfo   ret = aci;
        
        
        return ret;
    }
    
    void     configure_standand_asset_path()
    {
        static bool s_done  = false;
        if(s_done)
            return;
        Asset::resolver_add_paths(build::data_directory());
        s_done = true;
    }

    Application*    Application::s_app  = nullptr;

    Application::Application(int argc, char* argv[], const AppCreateInfo& aci) : 
        BasicApp(argc, argv), m_cInfo(_update(aci, app_name()))
    {
        if(!is_main_thread()){
            throw AppException("Applications must only be used on the main thread!");
        }
        if(s_app){
            throw AppException("Only one application per customer!");
        }
        s_app   = this;
        
        configure_standand_asset_path();
        m_startTime     = clock_t::now();
        
        if(!aci.headless)
            thread(APP);
    }
    

    Application::~Application()
    {
        _kill();
        
        if(this == s_app){
            s_app   = nullptr;
        }
    }

    void    Application::_kill()
    {
        if(m_vthread){
            m_vthread -> shutdown();
            m_vthread -> join();
            m_vthread   = nullptr;
        }

        if(m_tthread){
            m_tthread -> shutdown();
            m_tthread -> join();
            m_tthread   = nullptr;
        }

        if(m_athread){
            m_athread -> shutdown();
            m_athread   = nullptr;
        }
        
    }

    ViewerID                    Application::create(viewer_k, WidgetPtr w)
    {
        return create(VIEWER, m_cInfo.view, w);
    }
    
    ViewerID                    Application::create(viewer_k, std::string_view n, WidgetPtr w)
    {
        ViewerCreateInfo        vci   = m_cInfo.view;
        vci.title       = n;
        return create(VIEWER, vci, w);
    }
    
    ViewerID                    Application::create(viewer_k, const ViewerCreateInfo&vci, WidgetPtr w)
    {
        AppThread&  at  = thread(APP);
        DesktopGLFW&        desk    = desktop(GLFW);
        manager(VULQAN);
        
        Window*             win     = desk.create(WINDOW, vci);
        if(!win)
            return {};
        
        
        Viewer*         v = nullptr;
        // TODO ... catch/replace
        v = Tachyon::create<Viewer>(win, w.ptr(), vci);
        
        ++at.m_viewers;
        
        v->subscribe(at.id());
        at.subscribe(v->id());
        
        win->subscribe(v->id());
        v->subscribe(win->id());
        
        // Ticks to force things into the frame
        at.tick();
        at.tick();
        
        switch(m_cInfo.vthreads){
        case ViewerThreadPolicy::Single:
        case ViewerThreadPolicy::Individual:
            {
                ThreadID    vid = thread(VIEWER).id();
                v->owner(PUSH, vid);
                w->owner(PUSH, vid);
            }
            break;
        default:
            break;
        }
        
        at.tick();
        return v->id();
    }

    DesktopGLFW&                Application::desktop(glfw_k)
    {
        if(!m_glfw){
            thread(APP);
            m_glfw  = Tachyon::create<DesktopGLFW>(m_cInfo);
            
            //  Connections?
        }
        
        return *m_glfw;
    }

    VulqanManager&              Application::manager(vulqan_k)
    {
        if(!m_vulkan){
            thread(APP);
            m_vulkan    = Tachyon::create<VulqanManager>(m_cInfo);
        }
        return *m_vulkan;
    }

    void                        Application::run(const RunConfig& r)
    {
        thread(APP).run();
    }

    void                        Application::run(WidgetPtr wid, const RunConfig& r)
    {
        ViewerID    vid = create(VIEWER, wid);
        if(!vid)
            return ;
        run(r);
    }

    AppThread&  Application::thread(app_k)
    {
        if(!m_athread){
            m_athread   = new AppThread(this);
        }
        return *m_athread;
    }

    ViewerThread&              Application::thread(viewer_k)
    {
        if(!m_vthread){
            thread(APP);
            m_vthread   = new ViewerThread;
            m_vthread->start();
        }
        return *m_vthread;
    }
    
    TaskThread&             Application::thread(task_k)
    {
        if(!m_tthread){
            thread(APP);
            m_tthread   = new TaskThread;
            m_tthread->start();
        }
        return *m_tthread;
    }
}
