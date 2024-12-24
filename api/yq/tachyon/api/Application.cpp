////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/AppException.hpp>
#include <yq/tachyon/api/AppThread.hpp>
#include <yq/tachyon/api/Application.hpp>
#include <yq/tachyon/api/Viewer.hpp>
#include <yq/tachyon/api/ViewerThread.hpp>
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/api/Window.hpp>
//#include <yq/tachyon/api/TachyonInfoWriter.hpp>
#include <yq/tachyon/v/Vulqan.hpp>

//#include <yq/tachyon/commands/AppDeleteViewerCommand.hpp>
#include <yq/tachyon/glfw/DesktopGLFW.hpp>
//#include <yq/tachyon/task/TaskEngine.hpp>

#include <yq/asset/Asset.hpp>
#include <yq/core/ThreadId.hpp>
#include <yq/core/Cleanup.hpp>
#include <yq/meta/Init.hpp>
//#include <yq/post/boxes/SimpleBox.hpp>
#include <yq/tachyon/config/build.hpp>
//#include <GLFW/glfw3.h>

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
        
        if(!aci.headless)
            thread(APP);

        tachyonDebug << "Application initialized";
    }
    

    Application::~Application()
    {
        _kill();
        
        if(this == s_app){
            s_app   = nullptr;
        }

        tachyonDebug << "Application destroyed";
    }

    void    Application::_kill()
    {
        if(m_vthread){
            m_vthread -> shutdown();
            m_vthread -> join();
            m_vthread   = nullptr;
        }

        if(m_athread){
            m_athread -> shutdown();
            m_athread   = nullptr;
        }
        
    }

    ViewerID                    Application::create(viewer_t, WidgetPtr w)
    {
        return create(VIEWER, m_cInfo.view, w);
    }
    
    ViewerID                    Application::create(viewer_t, std::string_view n, WidgetPtr w)
    {
        ViewerCreateInfo        vci   = m_cInfo.view;
        vci.title       = n;
        return create(VIEWER, vci, w);
    }
    
    ViewerID                    Application::create(viewer_t, const ViewerCreateInfo&vci, WidgetPtr w)
    {
        AppThread&  at  = thread(APP);
        DesktopGLFW&        desk    = desktop(GLFW);
        manager(VULQAN);
        
        Window*             win     = desk.create(WINDOW, vci);
        if(!win)
            return {};
        
        
        Viewer*         v = nullptr;
        // TODO ... catch/replace
        v = Tachyon::create<Viewer>(win, w, vci);
        
        win->subscribe(v->id());
        v->subscribe(win->id());
        
        at.tick();
        
        //m_viewers.insert(v->id());
        
        switch(m_cInfo.vthreads){
        case ViewerThreadPolicy::Single:
        case ViewerThreadPolicy::Individual:
            v->owner(PUSH, thread(VIEWER).id());
            break;
        default:
            break;
        }
        
        at.tick();
        return v->id();
    }

    DesktopGLFW&                Application::desktop(glfw_t)
    {
        if(!m_glfw){
            thread(APP);
            m_glfw  = Tachyon::create<DesktopGLFW>(m_cInfo);
            
            //  Connections?
        }
        
        return *m_glfw;
    }

    Vulqan&                     Application::manager(vulqan_t)
    {
        if(!m_vulkan){
            thread(APP);
            m_vulkan    = Tachyon::create<Vulqan>(m_cInfo);
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

    AppThread&  Application::thread(app_t)
    {
        if(!m_athread){
            m_athread   = new AppThread(this);
        }
        return *m_athread;
    }

    ViewerThread&              Application::thread(viewer_t)
    {
        if(!m_vthread){
            m_vthread   = new ViewerThread;
            m_vthread->start();
        }
        return *m_vthread;
    }
    

#if 0
    Viewer*                     create_viewer(WidgetPtr);
    
    //! Creates a viewer with title/widget
    Viewer*                     create_viewer(std::string_view, WidgetPtr);
    
    Viewer*                     create_viewer(const ViewerCreateInfo&, WidgetPtr);
#endif

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  OLD STUFF
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#if 0
        // MIGHT need to bring this back... until then
    struct Application::ViewerData {
        ViewerPtr         viewer;
    };

    struct Application::Common {
        AppCreateInfo                   app_info;
        Application*                    app         = nullptr;
        std::atomic_flag                claimed;
        std::unique_ptr<GLFWManager>    glfw;
        //std::unique_ptr<TaskEngine>     tasking;
        std::unique_ptr<Vulqan>  vulqan;
        std::atomic<bool>               quit{false};
        std::vector<ViewerPtr>          viewers;
        Cleanup                         cleanup;
        
        Ref<AppThread>                  appThread;
        
        //  eventually the vulkan goes here too
    };
    
    Application::Common&    Application::common()
    {
        static Common s_ret;
        return s_ret;
    }

    Viewer*      Application::_add(ViewerPtr v)
    {
        if(!is_main_thread())
            return nullptr;
            
        static Common& g = common();
        if(!g.app)
            return nullptr;
            
        if(v->closing_or_kaput())
            return nullptr;

        if(!v->started_or_running()){
            std::error_code ec = g.glfw -> win_start(v.ptr());
            if(ec != std::error_code()){
                tachyonCritical << "Unable to start viewer.  [Error code] " << ec.message();
                return nullptr;
            }
        }
            
        g.viewers.push_back(v);
        g.app->connect(RX, *v);
        g.app->connect(TX, *v);

        if(!v->running()){
            //  TODO -- VIEWER THREAD/UPDATE/ETC
            GLFWManager::win_show(v.ptr());
            v->m_stage  = Viewer::Stage::Running;
        }

        return v.ptr();
    }

    bool            Application::_contains(const Viewer* v) 
    {
        Common& g = common();
        for(auto& p : g.viewers)
            if(p == v)
                return true;
        return false;
    }

    void     Application::_remove(Viewer*v)
    {
        Common& g = common();
        if(g.app)
            g.app->disconnect(*v);
        if(g.glfw)
            g.glfw->disconnect(*v);
        std::erase_if(g.viewers, [v](const ViewerPtr& vp) -> bool {
            return v == vp;
        });
    }


    void     Application::add_viewer(ViewerPtr v)
    {
        if(!v)
            return ;
        if(_contains(v))
            return ;
        _add(v);
    }

    Viewer* Application::create_viewer(const ViewerCreateInfo& vci, WidgetPtr w)
    {
        if(!w)
            return nullptr;
            
        return _add(new Viewer(vci, w));
    }


    bool    Application::initialized()
    {
        return static_cast<bool>(common().app);
    }

    Tachyon::Param  Application::params(const AppCreateInfo& aci)
    {
        Tachyon::Param ret;
        return ret;
    }

    void    Application::remove(Viewer* v)
    {
        if(!v)
            return ;
        if(!contains(v))
            return ;
            
        static Common& g = common();
        if(!g.app)
            return ;
            
        g.app->disconnect(*v);
        //GLFWManager::remove(*v);
        //std::erase(g.viewers, v);
    }

    void    Application::run(Second timeout)
    {
        Common& g   = common();
        
        if(g.glfw){
            while((!g.quit) && (g.app_info.headless || !g.viewers.empty())){
                post::SimpleBox     capture({ .name = "TachyonFrame"});
                g.glfw->poll(capture, timeout);
                //events.dispatch_all();

                if(g.tasking)            // eventually be smarter about this... multithreading
                    g.tasking -> step();

                for(auto& v : g.viewers){
                    v->tick();
                    #if 0
                    if(v->should_close() || !v->m_delete.empty()){
                        vkDeviceWaitIdle(v->visualizer().device());
                        v->purge_deleted();
                        if(v->should_close()){
                            delete v;
                            v   = nullptr;
                        }
                    }
                    #endif
                }
                
                g.cleanup.sweep();
                    
                //std::erase(g.viewers, nullptr);
            }
        }
    }

    void    Application::run(ViewerPtr win, Second timeout)
    {
        if(!win)
            return;
        _add(win);
        run(timeout);
    }

    void    Application::run(WidgetPtr wid, Second timeout)
    {
        if(!wid)
            return ;
        create_viewer(wid);
        run(timeout);
    }

    TaskEngine*         Application::task_engine() 
    { 
        return common().tasking.get(); 
    }


    //  ////////////////////////////////////////////////////////////////////////
    //  ////////////////////////////////////////////////////////////////////////

    
    Application::Application(int argc, char* argv[], const AppCreateInfo& aci) : 
        BasicApp(argc, argv), m_cInfo(_update(aci, app_name()))
    {
    
        Common& g = common();
        if(g.claimed.test_and_set())
            return ;
        
        add_role(R::Listener);
            
        tachyonInfo << "Application::Application(" << argv[0] << ")";

        g.app   = this;
        g.app_info      = aci;
        if(g.app_info.app_name.empty())
            g.app_info.app_name = app_name();
        Dispatcher::name(g.app_info.app_name);

        configure_standand_asset_path();
        
        if(g.app_info.tasking)
            g.tasking           = std::make_unique<TaskEngine>();
        if(g.app_info.glfw){
            g.glfw              = std::make_unique<GLFWManager>();
            connect(TX, *g.glfw);
        }
        if(g.app_info.vulkan){
            g.vulqan            = std::make_unique<Vulqan>(g.app_info);
            connect(TX, *g.vulqan);
        }

        set_post_mode(PostMode::Queued);
        
        
        tachyonDebug << "Application initialized";
    }
    

    Application::~Application()
    {
        Common& g = common();
        if(g.app != this)
            return ;
            
        g.app   = nullptr;
        
            //  TODO ... threads (which include the viewer)
    
        for(ViewerPtr& v : g.viewers){
            if(!v)
                continue;
            v -> _quit();
            v   = {};
            //if(v){
                //vkDeviceWaitIdle(v->visualizer().device());
                //delete v;
            //}
        }
        g.viewers.clear();
        
        if(g.vulqan){
            disconnect(*g.vulqan);
        }
        g.vulqan        = {};
        if(g.glfw){
            disconnect(*g.glfw);
        }
        g.glfw          = {};
        g.tasking       = {};

        tachyonDebug << "Application destroyed";
    }

    void    Application::cmd_delete_viewer(const AppDeleteViewerCommand&cmd)
    {
        static Common& g = common();
        Viewer* v = cmd.viewer();
        if(v){
            g.cleanup.add([v](){
                _remove(v);
            });
        }
    }

    void    Application::receive(const post::PostCPtr& pp) 
    {
        post::PBX::receive(pp);
        dispatch(pp);  // and rebroadcast
    }

    void Application::init_info()
    {
        auto w = writer<Application>();
        w.description("Tachyon Application");
        //w.receive(&Application::cmd_delete_viewer);
    }
#endif    

}
