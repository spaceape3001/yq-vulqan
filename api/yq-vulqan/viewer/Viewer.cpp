////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Viewer.hpp"

#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/app/Application.hpp>
#include <yq-vulqan/imgui/ViGui.hpp>
#include <yq-vulqan/viz/ViContext.hpp>
#include <yq-vulqan/viewer/ViewerCreateInfo.hpp>
#include <yq-vulqan/widget/Widget.hpp>

#include <yq-toolbox/errors.hpp>
#include <yq-toolbox/basic/AutoReset.hpp>
#include <yq-toolbox/basic/ErrorDB.hpp>

namespace yq::tachyon {

    Viewer::Viewer()
    {
    }
    
    Viewer::~Viewer()
    {
        kill();
    }

    Viewer::Viewer(const ViewerCreateInfo&vci, Widget*w) : Viewer()
    {
    
        std::error_code ec = initialize(vci, w);
        if(ec){
            tachyonCritical << "Unable to initialize the viewer ... " << ec.message();
            throw ec;
        }
    }

    std::error_code     Viewer::initialize(const ViewerCreateInfo&vci, Widget* w)
    {
        if(m_widget)
            return std::error_code();

        if(!w)
            return errors::null_pointer();
    
        Application::initialize();

        std::error_code ec = init_window(vci);
        if(ec)
            return ec;
        ec  = init_visualizer(vci, window());
        if(ec)
            return ec;
         
        if(vci.imgui){
            m_imgui = std::make_unique<ViGui>(*this);
        }

        install_hooks();
        m_widget    = w;
        w->m_viewer = this;
        return std::error_code();
    }

    void                Viewer::kill()
    {
        Application*    s   = Application::app();
        if(s)
            s->_remove(this);
        purge_deleted();
        if(m_widget){
            m_widget->m_viewer  = nullptr;
            delete m_widget;
        }
        m_widget    = nullptr;
        m_imgui     = {};
        kill_visualizer();
        Window::kill_window();
    }

    std::error_code     Viewer::draw()
    {
        ViContext   u;
        return draw(u);
    }

    std::error_code     Viewer::draw(ViContext& u)
    {
        if(m_paused || m_zeroSize)
            return std::error_code();
            
        auto start = std::chrono::high_resolution_clock::now();
        auto r1 = auto_reset(u.tick, tick());
        auto r2 = auto_reset(u.viewer, this);
        auto r3 = auto_reset(u.window, static_cast<Window*>(this));
        if(m_widget && m_imgui){
            m_imgui -> draw(u, m_widget);
        }
        std::error_code ec = Visualizer::draw(u);
        auto end   = std::chrono::high_resolution_clock::now();
        m_drawTime          = (end-start).count();
        if(ec != std::error_code())
            tachyonCritical << "Viewer::draw() failed ... " << ec.message();
        //cleanup_sweep();
        return ec;
    }

    void     Viewer::prerecord(ViContext&u)
    {
        if(m_widget){
            m_widget -> prerecord(u);
        }
        if(m_imgui){
            m_imgui -> update();
        }
    }

    void     Viewer::purge_deleted()
    {
        if(!m_delete.empty()){
            for(Widget* w : m_delete)
                delete w;
            m_delete.clear();
        }
    }

    void    Viewer::record(ViContext&u)
    {
        if(m_widget)
            m_widget -> vulkan_(u);
        if(m_imgui)
            m_imgui -> record(u);
    }

    void    Viewer::window_framebuffer_resized(const Size2I&s)
    {
        m_zeroSize  = zero_framebuffer();
        trigger_rebuild();
    }

    void    Viewer::set_render_paused(bool v)
    {
        m_paused    = v;
    }

    void    Viewer::set_widget(Widget*w, bool fDestroyOld)
    {
        if(!w)
            return ;
        if(w == m_widget)
            return ;
        
        m_widget -> m_viewer    = nullptr;
        w->m_viewer             = this;
            
        std::swap(w, m_widget);
        if(fDestroyOld)
            m_delete.push_back(w);
    }
    
    void    Viewer::cmd_pause()
    {
        set_render_paused(true);
    }
    
    void    Viewer::cmd_unpause()
    {
        set_render_paused(false);
    }
}
