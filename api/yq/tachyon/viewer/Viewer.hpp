////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once


//#include <yq/tachyon/event/EventSocket.hpp>

#include <yq/units.hpp>
#include <yq/core/Cleanup.hpp>
#include <yq/core/Flags.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/core/Tachyon.hpp>
#include <yq/tachyon/core/Thread.hpp>
#include <yq/tachyon/typedef/commands.hpp>
#include <yq/tachyon/typedef/events.hpp>
#include <yq/tachyon/typedef/replies.hpp>
#include <yq/tachyon/typedef/requests.hpp>
#include <yq/tachyon/typedef/viewer.hpp>
#include <yq/tachyon/typedef/vigui.hpp>
#include <yq/tachyon/typedef/visualizer.hpp>
#include <yq/tachyon/typedef/widget.hpp>
#include <yq/tachyon/viewer/ViewerState.hpp>
#include <yq/tachyon/viewer/ViewerCreateInfo.hpp>

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
    class GLFWManager;
    
    struct ViewerInitData;
    
    
    /*! \brief Vulkan Window
    
        This is a vulkan window, called the viewer, that binds the 
        GLFW Window and the Vulkan Device.  It will hold ONE widget
        and one widget only, this is the root widget for the viewer.
        
    */
    class Viewer : public Tachyon, public RefCount {
        YQ_OBJECT_DECLARE(Viewer, Tachyon)
    
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
        
        enum class Stage {
            
            //! Ctor called, that's it
            Preinit,
            
            //! Window created, but not yet running
            Started,
            
            //! Running
            Running,
            
            //! Closing (ie, window still valid)
            Closing,
            
            //! Done/Busted (ie, ready for destruction)
            Kaput
        };
    
        static void init_info();
    
        /*! \brief Creates the viewer
        
            \note this *WILL* throw exceptions if the viewer create or the widget are bad
        */
        Viewer(const ViewerCreateInfo& vci, WidgetPtr w);
        
        //! Destructor
        virtual ~Viewer();
        
        //  -----------------------------------------
        //  INFORMATION
        

        //! TRUE if we're closing
        bool                        closing() const;
        
        //! TRUE if we're closing or kaput
        bool                        closing_or_kaput() const;

        //! Create information that created us
        const ViewerCreateInfo&     create_info() const;
        
        //! Time of last draw call
        unit::Second                draw_time() const { return m_drawTime; }

        //! Focus widget 
        //! \note Currently not safe outside viewer's thread
        Widget*                     focus_widget() const { return m_focus; }

        //! Viewer number
        uint64_t                    id() const { return m_id; }

            //! TRUE if the window has standard decorations (close/buttons/frame)
        bool                        is_decorated() const;
        
            //! TRUE if the window has input focus
        bool                        is_focused() const;
        
            //! TRUE if window is floating (ie always-on-top)
        bool                        is_floating() const;
        
            //! TRUE if the window is fullscreen
        bool                        is_fullscreen() const;
        
            //! TRUE if the mouse cursor is hovering directly above us
        bool                        is_hovered() const;
        
            //! TRUE if the window is iconified
        bool                        is_iconified() const;
        
            //! TRUE if the window is maximized
        bool                        is_maximized() const;
        
            //! TRUE if the window is resizable
        bool                        is_resizable() const;
        
            //! TRUE if the window is visible
        bool                        is_visible() const;

        //! TRUE if we're done (ready for deletion)
        bool                        kaput() const;

        //! TRUE if we've not called START
        bool                        never_started() const;
        
        //! TRUE if we're started
        bool                        started() const;
        
        //! Current state
        const ViewerState&          state() const;

        //! TRUE if we're started or running
        bool                        started_or_running() const;

        //! TRUE if rendering is paused
        bool                        paused() const;

        //! TRUE if we're running
        bool                        running() const;
        
        //! Current tick/frame number
        //! \note Might not be the same as the visualizer's
        uint64_t                    ticks() const { return m_ticks; }


        //! \note Will throw exceptions if visualizer is not defined
        Visualizer&                 visualizer() const;

        //  -----------------------------------------
        //  ACTION/SETTERS

        //! Runs the draw sequence (uses a default context and calls the other)
        std::error_code     draw();

        //! Runs the draw sequence
        std::error_code     draw(ViContext&);

        void                cmd_close(bool force=false);
        void                cmd_pause();
        void                cmd_resume();

        void                tick(/* const AppFrame& */);

    protected:

        //! Hint to do anything needed before the next render frame is actually rendered
        //! So do the uniform buffer & texture descriptor sets here.
        //virtual void        prerecord(ViContext&);
        
        struct Init {
            GLFWwindow*     window = nullptr;
        };

        //! Called *AFTER* vulkan/imgui are initialized
        virtual std::error_code startup(const Init&) { return {}; }

        virtual void    receive(const post::PostCPtr&) override;

        //! Override to have a more nuianced approach
        virtual void    on_close_request();
        
        void     accept(close_t);
        void     reject(close_t);

    private:

        friend class GLFWManager;
        friend class Application;
        friend class Widget;

        static std::atomic<int>         s_count;
        static std::atomic<uint64_t>    s_lastId;

        static Tachyon::Param   _pbx(const ViewerCreateInfo&);

        const uint64_t                  m_id;
        Cleanup                         m_cleanup;
        ViewerCreateInfoUPtr            m_createInfo;
        std::atomic<unit::Second>       m_drawTime      = { 0. };
        Widget*                         m_focus         = nullptr;
        std::unique_ptr<ViGui>          m_imgui;
        std::atomic<bool>               m_paused;
        ViewerState                     m_state;
        std::atomic<Stage>              m_stage         = { Stage::Preinit };
        std::atomic<uint64_t>           m_ticks{0};
        std::unique_ptr<Visualizer>     m_viz;
        WidgetPtr                       m_widget;
        bool                            m_zeroSize  = false;

        // Might have a filter/time thing (later) so a spam of the close button triggers fast-close
        ViewerCloseRequestCPtr          m_viewerCloseRequest;


        void                _kill();
        void                _quit();    // basically unconditional (without app-destroy)
        std::error_code     _startup(GLFWwindow*, const ViewerState&);
        Stage               _stage() const;
        
        
        void    close();
        void    close_request(const ViewerCloseRequestCPtr&);
        void    close_command(const ViewerCloseCommand&);
        
        void    on_hide_closing();
        
        void    hide_event(const WindowHideEvent&);
        void    show_event(const WindowShowEvent&);
        void    destroy_event(const WindowDestroyEvent&);

        void    pause_command(const ViewerPauseCommand&);
        void    resume_command(const ViewerResumeCommand&);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  OLD CODE

    public:        
        
        
        
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

        
//        Size2I              framebuffer_size() const;

        
            //! Height of the window
//        int                 height() const;


#if 0
#endif
        
            //! Monitor (if fullscreen)
        //Monitor             monitor() const;
        
//        MouseMode          mouse_state() const { return m_mouseState; }


#if 0        
            //! Current window position
        Vector2I            position() const;
#endif

        //! Set the rendering paused flag
        //void                set_render_paused(bool);
        
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
        //void                set_widget(Widget*, bool fDestroyOld=true);

            //! TRUE if user wants window to close
        //bool                should_close() const;

#if 0

            //! Viewer size
        Size2I              size() const;
#endif

    
#if 0
        std::string         title() const;
#endif

        //Widget*             widget_at(const Vector2D&) const;

#if 0

            //! Width of the window
        int                 width() const;
        
#endif



//        GLFWwindow*         window() const { return m_window; }
        
    protected:



        //virtual void  handle(Event&) override;
        

        
        //virtual std::error_code init();
        
        
        
    private:
    
    
    
    
    #if 0
        bool    mouse_capture_command(const MouseCaptureCommandCPtr&);
        bool    mouse_disable_command(const MouseDisableCommandCPtr&);
        bool    mouse_hide_command(const MouseHideCommandCPtr&);
        bool    mouse_normal_command(const MouseNormalCommandCPtr&);
        
        bool    viewer_attention_command(const ViewerAttentionCommandCPtr&);
        bool    viewer_hide_command(const ViewerHideCommandCPtr&);
        bool    viewer_resize_event(const ViewerResizeEventCPtr&);
    #endif

    #if 0
        void    close_command(const ViewerCloseCommand&);
        void    close_request(const ViewerCloseRequestCPtr&);
    #endif

    private:
        //void                record(ViContext&);
        
        
        
        
        
        // SAME thread close & impending delete

        
        //void    _init(const ViewerCreateInfo&vci, Widget*w);

        
        
        
        
        //  Maybe some sort of focus manager (or policy)?
        
        void                purge_deleted();
        
        
        //Vector2D    _probe_cursor_position() const;
    };
    
    
    
}
