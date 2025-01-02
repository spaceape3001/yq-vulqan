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
#include <yt/keywords.hpp>
#include <yq/tachyon/api/Thread.hpp>
#include <yq/tachyon/app/ViewerState.hpp>
#include <yq/tachyon/app/ViewerCreateInfo.hpp>
#include <yq/tachyon/typedef/commands.hpp>
#include <yq/tachyon/typedef/events.hpp>
#include <yq/tachyon/typedef/replies.hpp>
#include <yt/typedef/request.hpp>
#include <yq/tachyon/typedef/requests.hpp>
#include <yt/typedef/viewer.hpp>
#include <yq/tachyon/typedef/vigui.hpp>
#include <yq/tachyon/typedef/visualizer.hpp>
#include <yt/typedef/widget.hpp>
#include <yt/typedef/window.hpp>

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
    
    class ViewerInfo : public TachyonInfo {
    public:
        ViewerInfo(std::string_view, TachyonInfo&, const std::source_location& sl = std::source_location::current());
    };
    
    
    /*! \brief Vulkan Window
    
        This is a vulkan window, called the viewer, that binds the 
        GLFW Window, the Vulkan Device, and (optionally) ImGUI.  
        It will hold ONE widget and one widget only, this is the 
        root widget for the viewer.
    */
    class Viewer : public Tachyon {
        YQ_TACHYON_INFO(ViewerInfo)
        YQ_TACHYON_DATA(ViewerData)
        YQ_TACHYON_SNAP(ViewerSnap)
        YQ_TACHYON_DECLARE(Viewer, Tachyon)
    
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
            
            //! Deferred to widget... waiting
            WidgetStart,
            
            //! Running
            Running,
            
            //! Closing (ie, window still valid)
            Closing,
            
            //! Done/Busted (ie, ready for destruction)
            Kaput,
            
            Destruct
        };
    
        static void init_info();
    
        /*! \brief Creates the viewer
        
            \note this *WILL* throw exceptions if the viewer create or the widget are bad
        */
        Viewer(Window*, WidgetPtr, const ViewerCreateInfo& vci);
        Viewer(Window*, WidgetPtr, const ViewerCreateInfo& vci, const Param& );
        
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
        const ViewerCreateInfo&     create_info() const { return m_createInfo; }
        
        //! Time of last draw call
        unit::Second                draw_time() const { return m_drawTime; }

        //! Focus widget 
        //! \note Currently not safe outside viewer's thread
        Widget*                     focus_widget() const { return m_focus; }
        
        const Size2I&               framebuffer_size() const;

        int                         height() const;

        //! Viewer number
        ViewerID                    id() const { return ViewerID(UniqueID::id()); }
//        uint64_t                    id() const { return m_id; }

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
        
        //! Our viewer number (always incrementing 1...N)
        unsigned int                number() const { return m_number; }
        
        const Vector2I&             position() const;

        const Size2I&               size() const;

        Stage                       stage() const;

        //! TRUE if we're started
        bool                        started() const;
        
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
        void                set_aspect(unlock_k);
        void                set_aspect(unlocked_k);

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
        virtual Execution   tick(Context&) override;
        
        using Tachyon::owner;
        virtual void        owner(push_k, ThreadID) override;

    protected:

        //! Hint to do anything needed before the next render frame is actually rendered
        //! So do the uniform buffer & texture descriptor sets here.
        //virtual void        prerecord(ViContext&);
        
        struct Init {
            GLFWwindow*     window = nullptr;
        };

        //! Called *AFTER* vulkan/imgui are initialized
        virtual std::error_code startup(const Init&) { return {}; }

        virtual PostAdvice  advise(const Post&) const override;

        //virtual void    receive(const post::PostCPtr&) override;

        
        
        //! Call if you accept the close request
        void     accept(close_k);
        
        //! Call if you reject the close request
        void     reject(close_k);
        
        void        snap(ViewerSnap&) const;

    private:

        friend class GLFWManager;
        friend class Application;
        friend class Widget;

        static std::atomic<int>         s_count;
        static std::atomic<unsigned>    s_lastNumber;

        static Param   _params(const ViewerCreateInfo&);

        const ViewerCreateInfo          m_createInfo;
        const unsigned                  m_number;

        Cleanup                         m_cleanup;
        std::atomic<unit::Second>       m_drawTime      = { 0. };
        Widget*                         m_focus         = nullptr;
        std::unique_ptr<ViGui>          m_imgui;
        std::atomic<bool>               m_paused;
        ViewerState                     m_state;
        std::atomic<Stage>              m_stage         = { Stage::Preinit };
        std::atomic<uint64_t>           m_ticks{0};
        std::unique_ptr<Visualizer>     m_viz;
        WidgetPtr                       m_widget;
        WindowID                        m_window;
        Size2I                          m_pixels    = {};
        bool                            m_zeroSize  = false;

        // Might have a filter/time thing (later) so a spam of the close button triggers fast-close
        RequestCPtr                     m_closeRequest;


        void                _sweepwait();
        void                _install(widget_k);     // Installs new widget
        void                _remove(widget_k);      // Removes the current widget
        void                _widget(WidgetPtr);     // Changes the widget
        
        
        void    close_request();

        void    on_cursor_capture_command(const ViewerCursorCaptureCommand&);
        void    on_cursor_disable_command(const ViewerCursorDisableCommand&);
        void    on_cursor_hide_command(const ViewerCursorHideCommand&);
        void    on_cursor_normal_command(const ViewerCursorNormalCommand&);
        
        void    on_key_character_event(const KeyCharacterEvent&);
        void    on_key_press_event(const KeyPressEvent&);
        void    on_key_release_event(const KeyReleaseEvent&);

        void    on_mouse_move_event(const MouseMoveEvent&);
        void    on_mouse_press_event(const MousePressEvent&);
        void    on_mouse_release_event(const MouseReleaseEvent&);

        void    on_viewer_aspect_command(const ViewerAspectCommand&);
        void    on_viewer_attention_command(const ViewerAttentionCommand&);
        void    on_viewer_close_command(const ViewerCloseCommand&);
        void    on_viewer_close_request(const ViewerCloseRequestCPtr&);
        void    on_viewer_float_command(const ViewerFloatCommand&);
        void    on_viewer_focus_command(const ViewerFocusCommand&);
        void    on_viewer_hide_command(const ViewerHideCommand&);
        void    on_viewer_iconify_command(const ViewerIconifyCommand&);
        void    on_viewer_maximize_command(const ViewerMaximizeCommand&);
        void    on_viewer_move_command(const ViewerMoveCommand&);
        void    on_viewer_pause_command(const ViewerPauseCommand&);
        void    on_viewer_restore_command(const ViewerRestoreCommand&);
        void    on_viewer_resume_command(const ViewerResumeCommand&);
        void    on_viewer_show_command(const ViewerShowCommand&);
        void    on_viewer_size_command(const ViewerSizeCommand&);
        void    on_viewer_title_command(const ViewerTitleCommand&);
        void    on_viewer_unfloat_command(const ViewerUnfloatCommand&);

        void    on_window_close_request(const WindowCloseRequestCPtr&);
        void    on_window_defocus_event(const WindowDefocusEvent&);
        void    on_window_destroy_event(const WindowDestroyEvent&);
        void    on_window_fb_resize_event(const WindowFrameBufferResizeEvent&);
        void    on_window_focus_event(const WindowFocusEvent&);
        void    on_window_hide_event(const WindowHideEvent&);
        void    on_window_move_event(const WindowMoveEvent&);
        void    on_window_resize_event(const WindowResizeEvent&);
        void    on_window_show_event(const WindowShowEvent&);
        
        
        

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  OLD CODE

        void    widget_request(const ViewerWidgetRequestCPtr&);

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
