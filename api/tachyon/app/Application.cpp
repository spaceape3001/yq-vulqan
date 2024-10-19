////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Application.hpp"
#include <tachyon/logging.hpp>
#include <tachyon/app/Viewer.hpp>
#include <tachyon/config/build.hpp>
#include <tachyon/event/EventFrame.hpp>
#include <tachyon/glfw/GLFWManager.hpp>
#include <tachyon/task/TaskEngine.hpp>
#include <tachyon/viz/Visualizer.hpp>
#include <tachyon/vulqan/VulqanManager.hpp>
#include <yq/asset/Asset.hpp>
#include <GLFW/glfw3.h>

namespace yq::tachyon {

    struct Application::Common {
        AppCreateInfo                   app_info;
        Application*                    application    = nullptr;
        std::atomic_flag                claimed;
        std::unique_ptr<GLFWManager>    glfw;
        std::unique_ptr<TaskEngine>     tasking;
        std::vector<Viewer*>            viewers;
        std::unique_ptr<VulqanManager>  vulqan;
        std::atomic<bool>               quit{false};
        
        
        //  eventually the vulkan goes here too
    };
    
    Application::Common&    Application::common()
    {
        static Common s_ret;
        return s_ret;
    }

    Viewer*     Application::_add(Viewer* v)
    {
        common().viewers.push_back(v);
        return v;
    }

    void    Application::_remove(Viewer* v)
    {
        std::erase(common().viewers, v);
    }
    
    Viewer*         Application::add_viewer(Widget*w)
    {
        if(!w)
            return nullptr;

        Common& g = common();
        return _add(new Viewer(g.app_info.view, w));
    }
    
    Viewer*         Application::add_viewer(std::string_view n, Widget*w)
    {
        if(!w)
            return nullptr;
            
        Common& g = common();
        ViewerCreateInfo    vci = g.app_info.view;
        vci.title       = n;
        return _add(new Viewer(vci, w));
    }
    
    
    //! Creates a viewer with viewer
    Viewer*         Application::add_viewer(Viewer*v)
    {
        if(!v)
            return nullptr;
            
        if(contains(v))
            return v;
        return _add(v);
    }

    Application*       Application::app() 
    { 
        return common().application;
    }

    bool            Application::contains(const Viewer*v) 
    {
        Common& g = common();
        for(auto& p : g.viewers)
            if(p == v)
                return true;
        return false;
    }


    void    Application::run(Second amt)
    {
        Common& g   = common();
        
        if(g.glfw){
            while((!g.quit) && (g.app_info.headless || !g.viewers.empty())){
                EventFrame      events;
                g.glfw->poll(events, amt);
                events.dispatch_all();

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

    TaskEngine*         Application::task_engine() 
    { 
        return common().tasking.get(); 
    }

    void     configure_standand_asset_path()
    {
        Asset::resolver_add_paths(build::data_directory());
    }

    //  ////////////////////////////////////////////////////////////////////////
    //  ////////////////////////////////////////////////////////////////////////

    Application::Application(int argc, char* argv[], const AppCreateInfo& aci) : 
        BasicApp(argc, argv)
    {
        Common& g = common();
        if(g.claimed.test_and_set())
            return ;
            
        tachyonInfo << "Application::Application(" << argv[0] << ")";

        g.application   = this;
        g.app_info      = aci;
        if(g.app_info.app_name.empty())
            g.app_info.app_name = app_name();
        

        configure_standand_asset_path();
        
        if(g.app_info.tasking)
            g.tasking           = std::make_unique<TaskEngine>();
        if(g.app_info.glfw)
            g.glfw              = std::make_unique<GLFWManager>();
        if(g.app_info.vulkan)
            g.vulqan            = std::make_unique<VulqanManager>(g.app_info);
        
        //  TODO event connections
        
        tachyonDebug << "Application initialized";
    }
    

    Application::~Application()
    {
        Common& g = common();
        if(g.application != this)
            return ;
            
        g.application   = nullptr;

        for(Viewer* v : g.viewers){
            if(v){
                vkDeviceWaitIdle(v->visualizer().device());
                delete v;
            }
        }
        g.viewers.clear();
        
        g.vulqan        = {};
        g.glfw          = {};
        g.tasking       = {};
    
        tachyonDebug << "Application destroyed";
    }
}
