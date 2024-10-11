////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <tachyon/viz/Visualizer.hpp>
#include <tachyon/window/Window.hpp>
#include <yq/core/Flags.hpp>

namespace yq {
    class Object;
}

namespace yq::tachyon {
    class Widget;
    class ViGui;
    
    /*! \brief Vulkan Window
    
        This is a vulkan window, called the viewer, that binds the 
        GLFW Window and the Vulkan Device.  It will hold ONE widget
        and one widget only, this is the root widget for the viewer.
    */
    class Viewer : public Window, public Visualizer {
        friend class Application;
    public:

    
    
        /*! \brief Creates the viewer
        */
        Viewer();
        
        //! Destructor
        virtual ~Viewer();
        
        /*! \brief Creates & initializes viewer 
        
            \note This one throws a std::error_code if problems occur
        */
        Viewer(const ViewerCreateInfo&vci, Widget*);
        
        /*! \brief Initializes the viewer
            
            Initializes the viewer to render specified top-level widget
        */
        std::error_code     initialize(const ViewerCreateInfo&vci, Widget*);
        
        //! Runs the draw sequence
        std::error_code     draw(ViContext&);
        
        //! Runs the draw sequence (uses a default context and calls the other)
        std::error_code     draw();
        
        //! Time (in seconds) of last draw call
        double              draw_time() const { return m_drawTime; }
        
        //! Current frame number
        uint64_t            frame_number() const { return tick(); }
        
        //! TRUE if rendering is paused
        bool                render_paused() const { return m_paused; }
        
        //! Set the rendering paused flag
        void                set_render_paused(bool);
        
        //! Pause the rendering
        void                cmd_pause();
        
        //! Unpause the rendering
        void                cmd_unpause();
        
        //! Set the widget
        void                set_widget(Widget*, bool fDestroyOld=true);
        
    protected:
        virtual void        window_framebuffer_resized(const Size2I&) override;

        //! Hint to do anything needed before the next render frame is actually rendered
        //! So do the uniform buffer & texture descriptor sets here.
        virtual void        prerecord(ViContext&) override;
        
    private:
        void                record(ViContext&) override;

        Widget*                 m_widget        = nullptr;
        double                  m_drawTime      = 0;
        bool                    m_paused        = false;
        bool                    m_zeroSize      = false;
        std::vector<Widget*>    m_delete;
        std::unique_ptr<ViGui>  m_imgui;
        
        void                purge_deleted();
        
        virtual void        kill_window() { kill(); }
        void                kill();
    };
}
