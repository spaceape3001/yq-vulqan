////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/api/Tachyon.hxx>

#include <yq/tachyon/app/AppException.hpp>
#include <yq/tachyon/app/Application.hpp>
#include <yq/tachyon/app/Viewer.hpp>

#include <yq/tachyon/config/build.hpp>

#include <yq/tachyon/os/Window.hpp>
#include <yq/tachyon/os/glfw/DesktopGLFW.hpp>

#include <yq/tachyon/thread/AppThread.hpp>
#include <yq/tachyon/thread/AudioThread.hpp>
#include <yq/tachyon/thread/AuxillaryThread.hpp>
#include <yq/tachyon/thread/EditThread.hpp>
#include <yq/tachyon/thread/GameThread.hpp>
#include <yq/tachyon/thread/IOThread.hpp>
#include <yq/tachyon/thread/NetworkThread.hpp>
#include <yq/tachyon/thread/SimThread.hpp>
#include <yq/tachyon/thread/TaskThread.hpp>
#include <yq/tachyon/thread/ViewerThread.hpp>

#include <yq/tachyon/vulkan/VulqanManager.hpp>

#include <yq/resource/Resource.hpp>
#include <yq/core/ThreadId.hpp>
#include <yq/core/Cleanup.hpp>
#include <yq/meta/Init.hpp>
#include <yq/process/OSUtils.hpp>
#include <yq/process/PluginLoader.hpp>
//#include <yq/post/boxes/SimpleBox.hpp>

#include <filesystem>

namespace yq::tachyon {

    static AppCreateInfo    _update(const AppCreateInfo& aci)
    {
        AppCreateInfo   ret = aci;
        if(ret.app_name.empty()){
            std::filesystem::path   pth(BasicApp::app_name());
            ret.app_name    = pth.stem().string();
        }
        return ret;
    }
    
    void     configure_standand_resource_path()
    {
        static bool s_done  = false;
        if(s_done)
            return;
            
        Resource::add_paths(default_data_directory());
        s_done = true;
    }


    Application*    Application::s_app  = nullptr;

    std::string_view     Application::app_name()
    {
        if(s_app)
            return s_app->m_cInfo.app_name;
        return "";
    }

    Application::Application(int argc, char* argv[], const AppCreateInfo& aci) : 
        BasicApp(argc, argv), m_cInfo(_update(aci)), m_config("vulqan.cfg")
    {
        if(!is_main_thread()){
            throw AppException("Applications must only be used on the main thread!");
        }
        if(s_app){
            throw AppException("Only one application per customer!");
        }
        s_app   = this;
        
        configure_standand_resource_path();
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
        if(started()){
            {
                lock_t  lock(m_mutex);
                m_stage = Shutdown;
            }
            for(Thread*t : m_threads)
                t->shutdown();
            for(Thread*t : m_threads)
                t->join();
            m_thread.app -> shutdown();
            m_threads.clear();
            m_thread    = {};
            m_vulkan    = {};
            m_stage = Terminated;
        }
    }

    template <typename T>
    bool    Application::_start(StdThread st, Ref<T>& ptr, const thread_spec_t<T>& spec, std::string_view kName)
    {
        if(is_single(spec.enable)){
            if(spec.create){
                ptr = (spec.create)(*this);
                if(!ptr){
                    tachyonCritical << "Unable to create " << kName << " thread";
                    return false;
                }
            } else {
                ptr = new T;
            }
            m_threads.push_back(ptr.ptr());
            Thread::standard(st, ptr->id(), true);
        }
        return true;
    }
    
    void    Application::_stdthread(StdThread st, const thread_enabler_t& spec)
    {
        if(auto p = std::get_if<StdThread>(&spec)){
            Thread::standard(st, Thread::standard(*p));
        }
    }

    template <typename T>
    void    Application::_stdthread(StdThread st, const thread_spec_t<T>& spec)
    {
        _stdthread(st, spec.enable);
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
        switch(m_stage){
        case Uninit:
            if(!start())
                return {};
            [[fallthrough]];
        case Started:
            return m_thread.app->create_viewer(vci, w);
        case Running:
            m_thread.app->create(VIEWER, vci, w);
            [[fallthrough]];
        default:
            return {};
        }
    }

    void                        Application::run(const RunConfig& r)
    {
        if(!start())
            return ;
        m_stage = Running;
        m_thread.app->run();
    }

    void                        Application::run(WidgetPtr wid, const RunConfig& r)
    {
        if(!start())
            return ;
        if(!m_desktop)
            return ;
        ViewerID    vid = create(VIEWER, wid);
        if(!vid)
            return ;
        run(r);
    }

    void    Application::run(std::span<WidgetPtr> widgets, const RunConfig& r)
    {
        if(!start())
            return ;
        if(!m_desktop)
            return ;

        int success = 0;
        for(WidgetPtr wp : widgets){
            ViewerID vid = create(VIEWER, wp);
            if(vid)
                ++success;
        }
        if(!success)
            return;
        run(r);
    }

    bool    Application::running() const
    {
        return m_stage == Running;
    }

    bool        is_single(const thread_enabler_t& ts)
    {
        if(std::get_if<enabled_k>(&ts))
            return true;
        if(auto p = std::get_if<bool>(&ts))
            return *p;
        return false;
    }

    template <typename T>
    bool        is_single(const thread_spec_t<T>& ts)
    {
        return is_single(ts.enable);
    }

    bool        Application::start()
    {
        if(started())
            return true;
    
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
        
        if(m_cInfo.thread.app){
            m_thread.app       = m_cInfo.thread.app(*this);
            if(!m_thread.app){
                tachyonCritical << "Unable to create app thread.";
                return false;
            }
        } else {
            m_thread.app       = new AppThread(*this);
        }
        m_thread.app -> tick();
        Thread::standard(StdThread::App, m_thread.app->id(), true);
        for(StdThread st : StdThread::all_values()){
            if( st != StdThread::App)
                Thread::standard(st, m_thread.app->id());
        }
        
        
        switch(m_cInfo.platform){
        case Platform::GLFW:
            m_desktop       = Tachyon::create<DesktopGLFW>(m_cInfo);
            m_desktops.push_back(m_desktop);

            tick(); tick(); tick(); tick(); tick(); 

            //  connections...?
            
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
                tick(); tick();
                break;
            default:
                break;
            }
        }
        
        configure_vulqan();

        if(m_cInfo.vulkan.enable){
            m_vulkan    = Tachyon::create<VulqanManager>();
            m_thread.app -> tick();
            m_thread.app -> tick();
            m_thread.app -> tick();
        }

        if(!_start(AUDIO, m_thread.audio, m_cInfo.thread.audio, "audio"))
            return false;
        if(!_start(AUXILLARY, m_thread.auxillary, m_cInfo.thread.auxillary, "auxillary"))
            return false;
        if(!_start(GAME, m_thread.game, m_cInfo.thread.game, "game"))
            return false;
        if(!_start(EDIT, m_thread.edit, m_cInfo.thread.edit, "edit"))
            return false;
        if(!_start(IO, m_thread.io, m_cInfo.thread.io, "io"))
            return false;
        if(!_start(NETWORK, m_thread.network, m_cInfo.thread.network, "network"))
            return false;
        if(!_start(SIM, m_thread.sim, m_cInfo.thread.sim, "sim"))
            return false;
        if(!_start(TASK, m_thread.task, m_cInfo.thread.task, "task"))
            return false;
        if(!_start(VIEWER, m_thread.viewer, m_cInfo.thread.viewer, "viewer"))
            return false;

        _stdthread(AUDIO,       m_cInfo.thread.audio);
        _stdthread(AUXILLARY,   m_cInfo.thread.auxillary);
        _stdthread(EDIT,        m_cInfo.thread.edit);
        _stdthread(GAME,        m_cInfo.thread.game);
        _stdthread(IO,          m_cInfo.thread.io);
        _stdthread(NETWORK,     m_cInfo.thread.network);
        _stdthread(SIM,         m_cInfo.thread.sim);
        _stdthread(TASK,        m_cInfo.thread.task);
        _stdthread(VIEWER,      m_cInfo.thread.viewer);
        
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

    void    Application::shutting_down()
    {
        //  this tells managers/threads to quit
        if(m_vulkan)
            m_vulkan->cmd_teardown();
        if(m_desktop)
            m_desktop->cmd_teardown();
    }

    void    Application::start_thread(ThreadPtr th)
    {
        // This *might* be reentrant unsafe depending on if the thread does anything funny in their start...
        lock_t  _lock(m_mutex);
        if(started())
            return;
        m_thread.others.push_back(th);
        m_threads.push_back(th.ptr());
        th->start();
    }
    
        
    bool    Application::started() const
    {
        return (m_stage == Started) || (m_stage == Running);
    }
    


    void    Application::tick()
    {
        if(m_thread.app)
            m_thread.app -> tick();
    }

    void                    Application::vulqan_libraries(load_k)
    {
        for(std::string_view p : m_config.data_paths())
            Resource::add_paths(p);
        for(std::string_view l : m_config.vulqan_libraries()){
            std::string     libName = os::expected_shared_library_name(l);
            // TODO ... make this use the proper lib/app directory
            if(load_plugin(libName)){
                tachyonNotice << "Loaded vulqan library: " << libName;
            } else {
                tachyonWarning << "Failed to load vulqan library: " << libName;
            }
        }
    }
}
