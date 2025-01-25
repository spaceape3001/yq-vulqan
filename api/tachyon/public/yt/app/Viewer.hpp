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
#include <yt/api/Thread.hpp>
#include <yt/app/ViewerState.hpp>
#include <yt/app/ViewerCreateInfo.hpp>

#include <ya/typedef/commands.hpp>
#include <ya/typedef/events.hpp>
#include <ya/typedef/replies.hpp>
#include <ya/typedef/requests.hpp>

#include <yt/typedef/request.hpp>
#include <yt/typedef/viewer.hpp>
#include <yt/typedef/widget.hpp>
#include <yt/typedef/window.hpp>

#include <yv/typedef/vigui.hpp>
#include <yv/typedef/visualizer.hpp>

//#include <yv/Visualizer.hpp>
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
    
    class AttentionCommand;
    class CloseCommand;
    class CloseReply;
    class CloseRequest;
    class DefocusEvent;
    class FloatCommand;
    class FocusCommand;
    class FocusEvent;
    class HideCommand;
    class HideEvent;
    class IconifyCommand;
    class IconifyEvent;
    class MaximizeCommand;
    class MaximizeEvent;
    class PauseCommand;
    class Position²Event;
    class RestoreCommand;
    class RestoreEvent;
    class ResumeCommand;
    class ShowCommand;
    class ShowEvent;
    class Size²Event;
    class SpatialCommand;
    class UnfloatCommand;
    
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
        TypedID                     focus() const { return m_focus; }
        
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
        
        const Vector2D&             position() const { return m_state.window.position; }

        const Size2D&               size() const { return m_state.window.area; }

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

        //! Current widget (may be NULL at times)
        Widget*                     widget() const;

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
        void                set_position(const Vector2D&);

            //! Sets the window position
        void                set_position(double x, double y);
        
        void                set_size(const Size2D&);
        void                set_size(double w, double h);
        
            //! Sets the window title
        void                set_title(std::string_view);
        
            /*! Changes the main widget
            
                \note This will fail if the widget is attached to another viewer
                \note To *SWAP* widgets between viewers, use an empty widget as 
                        interrim, & wait for replies
            */
        void                set_widget(WidgetPtr);

        //! Our general "update()" that includes the visualizer
        virtual Execution   tick(const Context&) override;
        
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
        TypedID                         m_focus         = {};
        std::unique_ptr<ViGui>          m_imgui;
        std::atomic<bool>               m_paused;
        ViewerState                     m_state;
        std::atomic<Stage>              m_stage         = { Stage::Preinit };
        std::atomic<uint64_t>           m_ticks{0};
        std::unique_ptr<Visualizer>     m_viz;
        TypedID                         m_widget;
        TypedID                         m_window;
        Size2I                          m_pixels    = {};
        bool                            m_zeroSize  = false;

        // Might have a filter/time thing (later) so a spam of the close button triggers fast-close
        RequestCPtr                     m_closeRequest;


        void                _sweepwait();
        void                _install(widget_k);     // Installs new widget
        void                _remove(widget_k);      // Removes the current widget
        void                _widget(WidgetPtr);     // Changes the widget
        
        
        //void    close_request();

        void    on_attention_command(const AttentionCommand&);
        void    on_close_command(const CloseCommand&);
        void    on_close_request(const CloseRequestCPtr&);
        void    on_close_reply(const CloseReply&);
        void    on_cursor_capture_command(const ViewerCursorCaptureCommand&);
        void    on_cursor_disable_command(const ViewerCursorDisableCommand&);
        void    on_cursor_hide_command(const ViewerCursorHideCommand&);
        void    on_cursor_normal_command(const ViewerCursorNormalCommand&);
        void    on_defocus_event(const DefocusEvent&);
        void    on_focus_command(const FocusCommand&);
        void    on_focus_event(const FocusEvent&);
        void    on_float_command(const FloatCommand&);
        void    on_hide_event(const HideEvent&);
        void    on_hide_command(const HideCommand&);
        void    on_iconify_command(const IconifyCommand&);
        void    on_key_character_event(const KeyCharacterEvent&);
        void    on_key_press_event(const KeyPressEvent&);
        void    on_key_release_event(const KeyReleaseEvent&);
        void    on_maximize_command(const MaximizeCommand&);
        void    on_mouse_move_event(const MouseMoveEvent&);
        void    on_mouse_press_event(const MousePressEvent&);
        void    on_mouse_release_event(const MouseReleaseEvent&);
        void    on_move_event(const Position²Event&);
        void    on_pause_command(const PauseCommand&);
        void    on_restore_command(const RestoreCommand&);
        void    on_resume_command(const ResumeCommand&);
        void    on_size_event(const Size²Event&);
        void    on_show_command(const ShowCommand&);
        void    on_show_event(const ShowEvent&);
        void    on_spatial_command(const SpatialCommand&);
        void    on_unfloat_command(const UnfloatCommand&);

        void    on_viewer_aspect_command(const ViewerAspectCommand&);
        void    on_viewer_title_command(const ViewerTitleCommand&);

        void    on_window_destroy_event(const WindowDestroyEvent&);
        void    on_window_fb_resize_event(const WindowFrameBufferResizeEvent&);
        

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
