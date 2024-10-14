////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Viewer.hpp"

#include <tachyon/logging.hpp>
#include <tachyon/app/Application.hpp>
#include <tachyon/imgui/ViGui.hpp>
#include <tachyon/image/Raster.hpp>
#include <tachyon/viz/ViContext.hpp>
#include <tachyon/viewer/ViewerCreateInfo.hpp>
#include <tachyon/widget/Widget.hpp>

#include <yq/errors.hpp>
#include <yq/core/ErrorDB.hpp>
#include <yq/util/AutoReset.hpp>

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

    void    Viewer::cmd_pause()
    {
        set_render_paused(true);
    }
    
    void    Viewer::cmd_unpause()
    {
        set_render_paused(false);
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
        
        //  ENABLE to get the validation issue
        //  u.snapshot  = DataFormat(DataFormat::R8G8B8A8_SRGB);
        return draw(u);
    }

    std::error_code     Viewer::draw(ViContext& u)
    {
        if(m_paused || m_zeroSize)
            return std::error_code();
        
        std::filesystem::path   snapshot;
        if(auto p = std::get_if<std::filesystem::path>(&u.snapshot)){
            snapshot    = *p;
            u.snapshot  = DataFormat(DataFormat::R8G8B8A8_SRGB);
        }
        
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
            viewCritical << "Viewer::draw() failed ... " << ec.message();
            
        if(!snapshot.empty()){
            if(auto p = std::get_if<RasterPtr>(&u.snapshot)){
                RasterPtr   img  = *p;
                if(img){
                    img -> save_to(snapshot);
                }
            }
            if(auto p = std::get_if<std::error_code>(&u.snapshot)){
                viewError << "Viewer::draw() snapshot failed ... " << p->message();
            }
        }
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
    
}
