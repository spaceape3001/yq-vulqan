////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Application.hpp"
#include <yq/asset/Asset.hpp>
#include <yq-vulqan/config/build.hpp>
#include <yq-vulqan/viewer/Viewer.hpp>
#include <yq-vulqan/task/TaskEngine.hpp>
#include <GLFW/glfw3.h>

namespace yq::tachyon {
    Application*    Application::s_app    = nullptr;

    void Application::initialize()
    {
        if(s_app)
            s_app -> init();
    }

    //  ////////////////////////////////////////////////////////////////////////

    Application::Application(int argc, char* argv[], std::shared_ptr<AppCreateInfo> aci) : 
        BasicApp(argc, argv), VqApp(*this, aci), m_appInfo(aci)
    {
        assert(m_appInfo && "AppCreateInfo is not optional, it must be supplied.");
        if(!s_app)
            s_app   = this;
            
        Asset::resolver_add_paths(build::data_directory());
    }
    

    Application::Application(int argc, char *argv[], const AppCreateInfo& aci) : 
        Application(argc, argv, std::make_shared<AppCreateInfo>(aci))
    {
    }
    
    Application::~Application()
    {
        if(s_app == this)
            s_app   = nullptr;
        kill();
    }

    Viewer*     Application::_add(Viewer* v)
    {
        m_viewers.push_back(v);
        return v;
    }

    void    Application::_remove(Viewer* v)
    {
        std::erase(m_viewers, v);
    }

    Viewer*         Application::add_viewer(Widget*w)
    {
        if(!w)
            return nullptr;

        return _add(new Viewer(m_appInfo->view, w));
    }
    
    Viewer*         Application::add_viewer(std::string_view n, Widget*w)
    {
        if(!w)
            return nullptr;
            
        ViewerCreateInfo    vci = m_appInfo->view;
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

    bool            Application::contains(const Viewer*v) const
    {
        for(auto& p : m_viewers)
            if(p == v)
                return true;
        return false;
    }

    std::error_code    Application::init()
    { 
        if(m_appInfo->want_tasking)
            m_taskEngine    = std::make_unique<TaskEngine>();
        init_glfw();
        return init_vulkan();
    }
        
    void        Application::kill()
    {
        for(Viewer* v : m_viewers){
            if(v){
                vkDeviceWaitIdle(v->device());
                delete v;
            }
        }
        m_viewers.clear();
        if(this == s_app)
            s_app = nullptr;
        kill_vulkan();
        kill_glfw();
    }

    void    Application::run(Second amt)
    {
        while((!m_quit) && (m_appInfo->run_without_viewers || !m_viewers.empty())){
            if(amt <= Second(0.)){
                glfwPollEvents();
            } else { 
                glfwWaitEventsTimeout(amt.value);
            }
            
            if(m_taskEngine)            // eventually be smarter about this... multithreading
                m_taskEngine -> step();

            for(auto& v : m_viewers){
                v->draw();
                if(v->should_close() || !v->m_delete.empty()){
                    vkDeviceWaitIdle(v->device());
                    v->purge_deleted();
                    if(v->should_close()){
                        delete v;
                        v   = nullptr;
                    }
                }
            }
                
            std::erase(m_viewers, nullptr);
        }
    }


    void    Application::run(Viewer* win, Second amt)
    {
        if(!win)
            return;
        m_viewers.push_back(win);
        run(amt);
    }

    bool    Application::vk_init() 
    {
        return init() == std::error_code();
    }
}
