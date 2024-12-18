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
#include <yq/tachyon/core/Controlling.hpp>
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
    class Viewer : public Controlling, public RefCount {
        YQ_OBJECT_DECLARE(Viewer, Controlling)
    
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
        

        //! Current specified locked aspect ratio (-1,-1 if unlocked)
        const Size2I&               aspect() const;

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
        
        const Size2I&               framebuffer_size() const;

        int                         height() const;

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
        
        const Vector2I&             position() const;

        const Size2I&               size() const;

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
        
        const std::string&          title() const;
        
        //! Current tick/frame number
        //! \note Might not be the same as the visualizer's
        uint64_t                    ticks() const { return m_ticks; }


        //! \note Will throw exceptions if visualizer is not defined
        Visualizer&                 visualizer() const;

        int                         width() const;
        
        bool                        zero_framebuffer() const;

        //  -----------------------------------------
        //  ACTION/SETTERS

        //! Runs the draw sequence (uses a default context and calls the other)
        std::error_code     draw();

        //! Runs the draw sequence
        std::error_code     draw(ViContext&);

        //! Attention from the user
        void                cmd_attention();
        
        //! Closes the viewer
        //! \param[in] force TRUE to force the close (ie, no option to save)
        void                cmd_close(bool force=false);
        
        void                cmd_cursor_capture();
        void                cmd_cursor_disable();
        void                cmd_cursor_hide();
        void                cmd_cursor_normal();
        
        //! Makes this viewer "always-on-top"
        void                cmd_float();
        
        //! Focuss on this window
        //! \note Excessive use annoys users
        void                cmd_focus();
        
        //! Hides the viewer (ie, renders invisible)
        void                cmd_hide();

        //! Minimizes/iconifies the viewer
        void                cmd_iconify();

        //! Maximizes widnow
        void                cmd_maximize();

        //! Pauses the viewer (ie, the render won't update)
        void                cmd_pause();
        
        //! Restore the window to non-icon/non-fullscreen
        void                cmd_restore();

        //! Resumes (unpauses) the viewer
        void                cmd_resume();
        
        //! Shows the viewer
        void                cmd_show();
        
        void                cmd_unfloat();

        void                set_aspect(const Size2I&);
        void                set_aspect(int w, int h);
        void                set_aspect(unlock_t);
        void                set_aspect(unlocked_t);

            //! Sets the window position
        void                set_position(const Vector2I&);

            //! Sets the window position
        void                set_position(int x, int y);
        
        void                set_size(const Size2I&);
        void                set_size(int w, int h);
        
            //! Sets the window title
        void                set_title(std::string_view);
        
            /*! Changes the main widget
            
                \note This will fail if the widget is attached to another viewer
                \note To *SWAP* widgets between viewers, use an empty widget as 
                        interrim, & wait for replies
            */
        void                set_widget(WidgetPtr);

        //! Our general "update()" that includes the visualizer
        void                tick(/* const AppFrame& */);

    protected:

        using Controlling::tick;

        //! Hint to do anything needed before the next render frame is actually rendered
        //! So do the uniform buffer & texture descriptor sets here.
        //virtual void        prerecord(ViContext&);
        
        struct Init {
            GLFWwindow*     window = nullptr;
        };

        //! Called *AFTER* vulkan/imgui are initialized
        virtual std::error_code startup(const Init&) { return {}; }

        virtual void    receive(const post::PostCPtr&) override;

        //! Override to have a more nuianced approach (default is accept)
        virtual void    on_close_request();
        
        
        //! Call if you accept the close request
        void     accept(close_t);
        
        //! Call if you reject the close request
        void     reject(close_t);

    private:

        friend class GLFWManager;
        friend class Application;
        friend class Widget;

        static std::atomic<int>         s_count;
        static std::atomic<uint64_t>    s_lastId;

        static Controlling::Param   _pbx(const ViewerCreateInfo&);

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
        void                _sweepwait();
        void                _install(widget_t);     // Installs new widget
        void                _remove(widget_t);      // Removes the current widget
        void                _widget(WidgetPtr);     // Changes the widget
        
        void    aspect_command(const ViewerAspectCommand&);
        void    attention_command(const ViewerAttentionCommand&);
        void    close_request(const ViewerCloseRequestCPtr&);
        void    close_command(const ViewerCloseCommand&);
        void    cursor_capture_command(const ViewerCursorCaptureCommand&);
        void    cursor_disable_command(const ViewerCursorDisableCommand&);
        void    cursor_hide_command(const ViewerCursorHideCommand&);
        void    cursor_normal_command(const ViewerCursorNormalCommand&);
        void    destroy_event(const WindowDestroyEvent&);
        void    float_command(const ViewerFloatCommand&);
        void    focus_command(const ViewerFocusCommand&);
        void    hide_command(const ViewerHideCommand&);
        void    hide_event(const WindowHideEvent&);
        void    iconify_command(const ViewerIconifyCommand&);
        void    maximize_command(const WindowMaximizeCommand&);
        void    move_command(const ViewerMoveCommand&);
        void    on_hide_closing();
        void    pause_command(const ViewerPauseCommand&);
        void    restore_command(const ViewerRestoreCommand&);
        void    resume_command(const ViewerResumeCommand&);
        void    show_command(const ViewerShowCommand&);
        void    show_event(const WindowShowEvent&);
        void    size_command(const ViewerSizeCommand&);
        void    state_event(const WindowStateEvent&);
        void    title_command(const ViewerTitleCommand&);
        void    unfloat_command(const ViewerUnfloatCommand&);
        void    widget_request(const ViewerWidgetRequestCPtr&);

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  OLD CODE

    public:        
        
        


            //! Monitor (if fullscreen)
        //Monitor             monitor() const;
        
//        MouseMode          mouse_state() const { return m_mouseState; }
        
        
        //! Set the widget
        //void                set_widget(Widget*, bool fDestroyOld=true);

            //! TRUE if user wants window to close
        //bool                should_close() const;

    
        //Widget*             widget_at(const Vector2D&) const;

    };
}
