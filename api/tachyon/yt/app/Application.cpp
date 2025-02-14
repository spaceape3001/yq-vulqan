////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/logging.hpp>
#include <yt/ui/Widget.hpp>
#include <yt/app/AppException.hpp>
#include <yt/app/Application.hpp>
#include <yt/app/Viewer.hpp>
#include <yt/os/Window.hpp>
#include <yv/VulqanManager.hpp>

#include <ya/threads/AppThread.hpp>
#include <ya/threads/AudioThread.hpp>
#include <ya/threads/GameThread.hpp>
#include <ya/threads/IOThread.hpp>
#include <ya/threads/NetworkThread.hpp>
#include <ya/threads/SimThread.hpp>
#include <ya/threads/TaskThread.hpp>
#include <ya/threads/ViewerThread.hpp>

#include <ya/desktops/glfw/DesktopGLFW.hpp>

#include <yq/asset/Asset.hpp>
#include <yq/core/ThreadId.hpp>
#include <yq/core/Cleanup.hpp>
#include <yq/meta/Init.hpp>
#include <yq/process/PluginLoader.hpp>
//#include <yq/post/boxes/SimpleBox.hpp>
#include <yt/config/build.hpp>

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
        if(m_stage == Stage::Started){
            for(Thread*t : m_threads)
                t->shutdown();
            for(Thread*t : m_threads)
                t->join();
            m_thread.app -> shutdown();
            m_threads.clear();
            m_thread    = {};
            m_vulkan    = {};
            m_stage = Stage::Terminated;
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
        if(!start())
            return {};

        if(!m_desktop)
            return {};

        Window*             win     = m_desktop->create(WINDOW, vci);
        if(!win)
            return {};
        
        
        Viewer*         v = nullptr;
        // TODO ... catch/replace
        v = Tachyon::create<Viewer>(win, w.ptr(), vci);
        
        ++(m_thread.app->m_viewers);
        
        v->subscribe(m_thread.app->id());
        m_thread.app->subscribe(v->id());
        
        win->subscribe(v->id());
        v->subscribe(win->id());
        
        // Ticks to force things into the frame
        m_thread.app->tick();
        m_thread.app->tick();
        
        ThreadID        vt;
        if(m_thread.viewer){
            vt  = m_thread.viewer->id();
        } else if(std::get_if<per_k>(&m_cInfo.thread.viewer)){
            ViewerThread*   tt  = new ViewerThread;
            tt -> start();
            m_threads.push_back(tt);
        } else {
            vt      = Thread::standard(VIEWER);
        }
        
        if(vt != m_thread.app->id()){
            v->owner(PUSH, vt);
            w->owner(PUSH, vt);
        } 
        
        m_thread.app->tick();
        return v->id();
    }

    void                        Application::run(const RunConfig& r)
    {
        if(!start())
            return ;

        m_thread.app->run();
    }

    void                        Application::run(WidgetPtr wid, const RunConfig& r)
    {
        if(!start())
            return ;

        ViewerID    vid = create(VIEWER, wid);
        if(!vid)
            return ;
        run(r);
    }

    bool        is_single(const thread_spec_t& ts)
    {
        if(std::get_if<enabled_k>(&ts))
            return true;
        if(auto p = std::get_if<bool>(&ts))
            return *p;
        return false;
    }

    bool        Application::start()
    {
        if(thread::id()){
            tachyonCritical << "Cannot start application from anything other than the main thread.";
            return false;
        }

        if(m_stage != Stage::Uninit)
            return m_stage == Stage::Started;

        m_startTime     = clock_t::now();

        Meta::init();
        
        for(const std::filesystem::path& fp : m_cInfo.plugins ){
            if(std::filesystem::is_directory(fp)){
                size_t n = load_plugin_dir(fp);
                tachyonInfo << "loaded " << n << " plugins from: " << fp;
            } else if(!load_plugin(fp)){
                tachyonError << "Failed to load plugin " << fp;
                m_stage = InError;
                return false;
            }
            
            Meta::init();
        }
        
        Meta::freeze();
            
        m_thread.app       = new AppThread(this);
        m_thread.app -> tick();
        for(StdThread st : StdThread::all_values())
            Thread::standard(st, m_thread.app->id());
        
        
        switch(m_cInfo.platform){
        case Platform::GLFW:
            m_desktop       = Tachyon::create<DesktopGLFW>(m_cInfo);
            m_thread.app -> tick();
            m_thread.app -> tick();
            
            //  connections...?
            
            m_desktops.push_back(m_desktop);
            break;
        case Platform::None:
            if(!m_cInfo.headless){
                tachyonWarning << "No platform in a GUI application... are you sure about this?";
            }
            break;
        }
        
        for(Platform p : m_cInfo.platforms){
            if(p == m_cInfo.platform)
                continue;
                
            switch(p){
            case Platform::GLFW:
                Tachyon::create<DesktopGLFW>(m_cInfo);
                break;
            default:
                break;
            }
        }
        
        if(m_cInfo.vulkan){
            m_vulkan    = Tachyon::create<VulqanManager>();
            m_thread.app -> tick();
            m_thread.app -> tick();
            m_thread.app -> tick();
        }
        
        if(is_single(m_cInfo.thread.audio)){
            m_thread.audio     = new AudioThread;
            m_threads.push_back(m_thread.game.ptr());
            Thread::standard(AUDIO, m_thread.audio->id());
        }

        if(is_single(m_cInfo.thread.game)){
            m_thread.game       = new GameThread;
            m_threads.push_back(m_thread.game.ptr());
            Thread::standard(GAME, m_thread.game->id());
        }
        
        if(is_single(m_cInfo.thread.io)){
            m_thread.io    = new IOThread;
            m_threads.push_back(m_thread.io.ptr());
            Thread::standard(IO, m_thread.io->id());
        }
        
        if(is_single(m_cInfo.thread.network)){
            m_thread.network  = new NetworkThread;
            m_threads.push_back(m_thread.network.ptr());
            Thread::standard(NETWORK, m_thread.network->id());
        }
        
        if(is_single(m_cInfo.thread.sim)){
            m_thread.sim = new SimThread;
            m_threads.push_back(m_thread.sim.ptr());
            Thread::standard(SIM, m_thread.sim->id());
        }

        if(is_single(m_cInfo.thread.task)){
            m_thread.task  = new TaskThread;
            m_threads.push_back(m_thread.task.ptr());
            Thread::standard(TASK, m_thread.task->id());
        }

        if(is_single(m_cInfo.thread.viewer)){
            m_thread.viewer  = new ViewerThread;
            m_threads.push_back(m_thread.viewer.ptr());
            Thread::standard(VIEWER, m_thread.viewer->id());
        }
        
        if(auto p = std::get_if<StdThread>(&m_cInfo.thread.audio)){
            Thread::standard(AUDIO, Thread::standard(*p));
        }
        
        if(auto p = std::get_if<StdThread>(&m_cInfo.thread.game)){
            Thread::standard(GAME, Thread::standard(*p));
        }

        if(auto p = std::get_if<StdThread>(&m_cInfo.thread.io)){
            Thread::standard(IO, Thread::standard(*p));
        }

        if(auto p = std::get_if<StdThread>(&m_cInfo.thread.network)){
            Thread::standard(NETWORK, Thread::standard(*p));
        }

        if(auto p = std::get_if<StdThread>(&m_cInfo.thread.sim)){
            Thread::standard(SIM, Thread::standard(*p));
        }

        if(auto p = std::get_if<StdThread>(&m_cInfo.thread.task)){
            Thread::standard(TASK, Thread::standard(*p));
        }

        if(auto p = std::get_if<StdThread>(&m_cInfo.thread.viewer)){
            Thread::standard(VIEWER, Thread::standard(*p));
        }
        
        for(Thread* t : m_threads)
            t->start();
            
        m_thread.app -> tick();
        
        if(m_vulkan && m_thread.viewer){
            m_vulkan->owner(PUSH, m_thread.viewer->id());
            m_thread.app -> tick();
            m_thread.app -> tick();
        }
        
        m_stage = Stage::Started;
        return true;
    }
}
