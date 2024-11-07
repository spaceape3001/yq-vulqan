////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once


//#include <yq/tachyon/event/EventSocket.hpp>

#include <yq/core/Cleanup.hpp>
#include <yq/core/Flags.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/Tachyon.hpp>
#include <yq/tachyon/Thread.hpp>
#include <yq/tachyon/ViewerState.hpp>
#include <yq/tachyon/ViewerCreateInfo.hpp>
#include <yq/tachyon/commands/forward.hpp>
#include <yq/tachyon/events/forward.hpp>
#include <yq/tachyon/replies/forward.hpp>
#include <yq/tachyon/requests/forward.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/vigui.hpp>
#include <yq/tachyon/typedef/visualizer.hpp>
#include <yq/tachyon/typedef/widget.hpp>

//#include <yq/tachyon/viz/Visualizer.hpp>
//#include <yq/tachyon/glfw/Window.hpp>

#include <tbb/spin_rw_mutex.h>

#include <atomic>
#include <memory>
#include <exception>

namespace yq {
    class Object;
}

struct GLFWwindow;
struct GLFWmonitor;

namespace yq::tachyon {
    class Monitor;
    class Widget;
    class ViGui;
    class Visualizer;
    struct ViContext;
    
    
    /*! \brief Vulkan Window
    
        This is a vulkan window, called the viewer, that binds the 
        GLFW Window and the Vulkan Device.  It will hold ONE widget
        and one widget only, this is the root widget for the viewer.
        
    */
    class Viewer : public Tachyon, public RefCount {
        YQ_OBJECT_DECLARE(Viewer, Tachyon)
    
        friend class Application;

    /*
        THREADING -- being written so that each viewer is a separate thread.
            
    
        OWNERSHIP -- once submitted, the viewer will be owned by Application, 
            and only the application shall delete it
            
        INITIALIZATION -- have to separate
        
            >   Construction (new Viewer/derived)
            >   Windowing (new GLFW window instance)

        RUNNING
            
            >   Can't directly access GLFW, must rely on events
            
        CLOSING -- here's the current rub
        
        
    
    */


    //  TODO FEATURE LIST
    //
    //  + Raw Mouse Motion (set https://www.glfw.org/docs/latest/input_guide.html#input_mouse_button )
    //  + Cursor control
    
    public:
        
        
        
        //static bool raw_mouse_motion_supported();
    
    
        static void init_info();
    
        /*! \brief Creates the viewer
        */
        Viewer(ViewerCreateInfoUPtr&& vci, WidgetPtr w);
        
        //! Destructor
        virtual ~Viewer();
        
        //! Initialize viewer
        std::error_code     initialize();
        
        
        
        
        /*! \brief Creates & initializes viewer 
        
            \note This one throws a std::error_code if problems occur
        */
//        Viewer();

#if 0
        
        /*! \brief Initializes the viewer
            
            Initializes the viewer to render specified top-level widget
        */
        //std::error_code     initialize(const ViewerCreateInfo&vci, Widget*);
        
        //! Attention from the user
        void                cmd_attention();
#endif

        //! Starts the "close" process
        void                cmd_close();

#if 0    
        //! Focus onto this window
        void                cmd_focus();

        //! Hides the window
        void                cmd_hide();
        
        //! Iconify/minimizes the window;
        void                cmd_iconify();
        
        //! Maximizes widnow
        void                cmd_maximize();
        
        void                cmd_mouse_capture();
        void                cmd_mouse_disable();
        void                cmd_mouse_hide();
        void                cmd_mouse_normal();
        
        //! Pause the rendering
        void                cmd_pause();
        
        //! Restore the window to non-icon/non-fullscreen
        void                cmd_restore();

        //! Show the window
        void                cmd_show();
        
        //! Unpause the rendering
        void                cmd_unpause();
#endif

//        const Vector2D&     cursor_position() const { return m_cursorPos; }

        //! Runs the draw sequence
        std::error_code     draw(ViContext&);
        
        //! Runs the draw sequence (uses a default context and calls the other)
        std::error_code     draw();
        
        //! Time (in seconds) of last draw call
        double              draw_time() const { return m_drawTime; }
        
//        Size2I              framebuffer_size() const;

        //! Current frame number
        uint64_t            frame_number() const;
        
        Widget*             focus_widget() const { return m_focus; }
        
            //! Height of the window
//        int                 height() const;

        uint64_t            id() const { return m_id; }

#if 0
            //! TRUE if the window has standard decorations (close/buttons/frame)
        bool                is_decorated() const;
        
            //! TRUE if the window has input focus
        bool                is_focused() const;
        
            //! TRUE if window is floating (ie always-on-top)
        bool                is_floating() const;
        
            //! TRUE if the window is fullscreen
        bool                is_fullscreen() const;
        
            //! TRUE if the mouse cursor is hovering directly above us
        bool                is_hovered() const;
        
            //! TRUE if the window is iconified
        bool                is_iconified() const;
        
            //! TRUE if the window is maximized
        bool                is_maximized() const;
        
            //! TRUE if the window is resizable
        bool                is_resizable() const;
        
            //! TRUE if the window is visible
        bool                is_visible() const;
#endif
        
            //! Monitor (if fullscreen)
        Monitor             monitor() const;
        
//        MouseMode          mouse_state() const { return m_mouseState; }

        //! TRUE if rendering is paused
        bool                render_paused() const { return m_paused; }

#if 0        
            //! Current window position
        Vector2I            position() const;
#endif

        //! Set the rendering paused flag
        void                set_render_paused(bool);
        
#if 0        
            //! Sets the window position
        void                set_position(const Vector2I&);

            //! Sets the window position
        void                set_position(int x, int y);

            //! Sets window size
        void                set_size(const Size2I&);

            //! Sets window size
        void                set_size(int w, int h);
        
            //! Sets the window title
        void                set_title(std::string_view);
#endif
        
        //! Set the widget
        void                set_widget(Widget*, bool fDestroyOld=true);

            //! TRUE if user wants window to close
        bool                should_close() const;

#if 0

            //! Viewer size
        Size2I              size() const;

        std::string         title() const;
#endif

        Widget*             widget_at(const Vector2D&) const;

#if 0

            //! Width of the window
        int                 width() const;
        
#endif


        Visualizer&         visualizer() const;

//        GLFWwindow*         window() const { return m_window; }
        
        const ViewerState&  state() const;
        
    protected:

        //! Hint to do anything needed before the next render frame is actually rendered
        //! So do the uniform buffer & texture descriptor sets here.
        //virtual void        prerecord(ViContext&);
        
        enum class F : uint8_t {
            Paused,
            ZeroSize
        };
        
        void                set_flag(F);

        //virtual void  handle(Event&) override;
        
        //! Override to have a more nuianced approach
        virtual void    on_close_request() { accept(CLOSE); }
        
        void     accept(close_t);
        void     reject(close_t);

        virtual void    receive(const post::PostCPtr&) override;
        
        virtual std::error_code init();
        
    private:
    
        enum Mode {
            Init,
            Run,
            Destroy
        };
    
    
    #if 0
        bool    mouse_capture_command(const MouseCaptureCommandCPtr&);
        bool    mouse_disable_command(const MouseDisableCommandCPtr&);
        bool    mouse_hide_command(const MouseHideCommandCPtr&);
        bool    mouse_normal_command(const MouseNormalCommandCPtr&);
        
        bool    viewer_attention_command(const ViewerAttentionCommandCPtr&);
        bool    viewer_hide_command(const ViewerHideCommandCPtr&);
        bool    viewer_resize_event(const ViewerResizeEventCPtr&);
    #endif

        void    close_command(const ViewerCloseCommand&);
        void    close_request(const ViewerCloseRequestCPtr&);

    private:
        //void                record(ViContext&);
        
        static std::atomic<int>         s_count;
        static std::atomic<uint64_t>    s_lastId;
        
        static Tachyon::Param   _pbx(const ViewerCreateInfo&);

        
        //void    _init(const ViewerCreateInfo&vci, Widget*w);
        //void    _kill();

        const uint64_t                  m_id;
        Widget*                         m_widget        = nullptr;
        Widget*                         m_focus         = nullptr;
        double                          m_drawTime      = 0;
        Flags<F>                        m_flags         = {};
        bool                            m_paused        = false;
        bool                            m_zeroSize      = false;
        Cleanup                         m_cleanup;
        std::vector<Widget*>            m_delete;
        std::unique_ptr<ViGui>          m_imgui;
        std::unique_ptr<Visualizer>     m_viz;
        ViewerState                     m_state;
        Mode                            m_mode          = Mode::Init;
        
        ViewerCreateInfoUPtr            m_createInfo;
        
        ViewerCloseRequestCPtr          m_viewerCloseRequest;
        
        //  No mutexes, if we can help it....
        mutable tbb::spin_rw_mutex      m_mutex;
        
        //  Maybe some sort of focus manager (or policy)?
        
        void                purge_deleted();
        
        
        //Vector2D    _probe_cursor_position() const;
    };
    
    
    
}
