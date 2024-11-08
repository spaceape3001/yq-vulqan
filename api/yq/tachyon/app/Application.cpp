////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/VulqanManager.hpp>
#include <yq/tachyon/app/Application.hpp>
#include <yq/tachyon/glfw/GLFWManager.hpp>
#include <yq/tachyon/task/TaskEngine.hpp>
#include <yq/tachyon/viewer/Viewer.hpp>
#include <yq/tachyon/viz/Visualizer.hpp>
#include <yq/tachyon/widget/Widget.hpp>

#include <yq/asset/Asset.hpp>
#include <yq/meta/Init.hpp>
#include <yq/post/boxes/SimpleBox.hpp>
#include <yq/tachyon/config/build.hpp>
#include <GLFW/glfw3.h>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Application)

namespace yq::tachyon {

    struct Application::ViewerData {
        Viewer*           viewer;
    };

    struct Application::Common {
        AppCreateInfo                   app_info;
        Application*                    app         = nullptr;
        std::atomic_flag                claimed;
        std::unique_ptr<GLFWManager>    glfw;
        std::unique_ptr<TaskEngine>     tasking;
        std::unique_ptr<VulqanManager>  vulqan;
        std::atomic<bool>               quit{false};
        
        std::map<Viewer*,ViewerData>    viewers;
        
        
        //  eventually the vulkan goes here too
    };
    
    Application::Common&    Application::common()
    {
        static Common s_ret;
        return s_ret;
    }

    void     Application::add(Viewer* v)
    {
        if(!v)
            return ;
            
        if(contains(v))
            return ;
        
        static Common& g = common();
        if(!g.app)
            return ;
            
        g.viewers.push_back(v);
        //GLFWManager::install(*v);
        g.app->connect(RX, *v);
    }


    Application*       Application::app() 
    { 
        return common().app;
    }

    bool            Application::contains(const Viewer*& v) 
    {
        Common& g = common();
        for(auto& p : g.viewers)
            if(p == v)
                return true;
        return false;
    }

    Viewer*         Application::create_viewer(Widget* w)
    {
        if(!w)
            return nullptr;

        Common& g = common();
        return new Viewer(g.app_info.view, w);
    }
    
    Viewer*         Application::create_viewer(std::string_view n, Widget* w)
    {
        if(!w)
            return nullptr;
            
        Common& g = common();
        ViewerCreateInfo    vci = g.app_info.view;
        vci.title       = n;
        return new Viewer(vci, w);
    }
    


    bool    Application::initialized()
    {
        return static_cast<bool>(common().app);
    }

    Thread::Param  Application::params(const AppCreateInfo& aci)
    {
        Thread::Param ret;
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

    void    Application::run(Second amt)
    {
        Common& g   = common();
        
        if(g.glfw){
            while((!g.quit) && (g.app_info.headless || !g.viewers.empty())){
                post::SimpleBox     capture({ .name = "TachyonFrame"});
                g.glfw->poll(capture, amt);
                //events.dispatch_all();

                if(g.tasking)            // eventually be smarter about this... multithreading
                    g.tasking -> step();

                for(auto& v : g.viewers){
                    v->draw();
                    if(v->should_close() || !v->m_delete.empty()){
                        vkDeviceWaitIdle(v->visualizer().device());
                        v->purge_deleted();
                        if(v->should_close()){
                            delete v;
                            v   = nullptr;
                        }
                    }
                }
                    
                std::erase(g.viewers, nullptr);
            }
        }
    }

    void    Application::run(Viewer* win, Second amt)
    {
        if(!win)
            return;
        Common& g = common();
        g.viewers.push_back(win);
        run(amt);
    }

    void    Application::run(Widget* wid, Second timeout)
    {
        if(!wid)
            return ;
        run(create_viewer(wid), timeout);
    }

    TaskEngine*         Application::task_engine() 
    { 
        return common().tasking.get(); 
    }

    void     configure_standand_asset_path()
    {
        static bool s_done  = false;
        if(s_done)
            return;
        Asset::resolver_add_paths(build::data_directory());
        s_done = true;
    }

    //  ////////////////////////////////////////////////////////////////////////
    //  ////////////////////////////////////////////////////////////////////////

    Application::Application(int argc, char* argv[], const AppCreateInfo& aci) : 
        BasicApp(argc, argv), Thread(params(aci))
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
            g.vulqan            = std::make_unique<VulqanManager>(g.app_info);
            connect(TX, *g.vulqan);
        }
        
        //  TODO event connections
        
        tachyonDebug << "Application initialized";
    }
    

    Application::~Application()
    {
        Common& g = common();
        if(g.app != this)
            return ;
            
        g.app   = nullptr;

        for(Viewer* v : g.viewers){
            if(v){
                vkDeviceWaitIdle(v->visualizer().device());
                delete v;
            }
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

    void    Application::receive(const post::PostCPtr& pp) 
    {
        post::PBX::receive(pp);
        dispatch(pp);  // and rebroadcast
    }
}
