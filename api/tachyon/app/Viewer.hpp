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
#include <tachyon/keywords.hpp>
#include <tachyon/api/Thread.hpp>
#include <tachyon/app/ViewerState.hpp>
#include <tachyon/app/ViewerCreateInfo.hpp>

#include <tachyon/typedef/commands.hpp>
#include <tachyon/typedef/events.hpp>
#include <tachyon/typedef/replies.hpp>
#include <tachyon/typedef/requests.hpp>

#include <tachyon/typedef/request.hpp>
#include <tachyon/typedef/viewer.hpp>
#include <tachyon/typedef/widget.hpp>
#include <tachyon/typedef/window.hpp>

#include <tachyon/typedef/vigui.hpp>
#include <tachyon/typedef/visualizer.hpp>

//#include <tachyon/vulkan/Visualizer.hpp>
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
    
    class AspectCommand;
    class AttentionCommand;
    class CloseCommand;
    class CloseReply;
    class CloseRequest;
    class CursorCommand;
    class DefocusEvent;
    class DestroyEvent;
    class FloatCommand;
    class FocusCommand;
    class FocusEvent;
    class GetDeviceReply;
    class HideCommand;
    class HideEvent;
    class IconifyCommand;
    class IconifyEvent;
    class ImGuiDisableKeyboardCommand;
    class ImGuiEnableKeyboardCommand;
    class ImGuiDisableMouseCommand;
    class ImGuiEnableMouseCommand;
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
    class TitleCommand;
    class UnfloatCommand;
    class FramebufferResizeEvent;
    
    struct ViewerInitData;
    
    
    /*! \brief Vulkan Window
    
        This is a vulkan window, called the viewer, that binds the 
        GLFW Window, the Vulkan Device, and (optionally) ImGUI.  
        It will hold ONE widget and one widget only, this is the 
        root widget for the viewer.
    */
    class Viewer : public Tachyon {
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
        Viewer(Window*, Widget*, const ViewerCreateInfo& vci);
        
        //! Destructor
        virtual ~Viewer();
        
        //  -----------------------------------------
        //  INFORMATION
        

        //! Current specified locked aspect ratio (-1,-1 if unlocked)
        const Size2I&               aspect() const;

        //! TRUE if we're closing
        //bool                        closing() const;
        
        //! TRUE if we're closing or kaput
        //bool                        closing_or_kaput() const;

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

        //! Our viewer number (always incrementing 1...N)
        unsigned int                number() const { return m_number; }
        
        const Vector2D&             position() const { return m_state.window.position; }

        const Size2D&               size() const { return m_state.window.area; }

        const std::string&          title() const;
        
        //! Current tick/frame number
        //! \note Might not be the same as the visualizer's
        uint64_t                    ticks() const { return m_ticks; }


        //! \note Will throw exceptions if visualizer is not defined
        Visualizer&                 visualizer() const;

        //! Current widget (may be NULL at times)
        Widget*                     widget() const;

        int                         width() const;
        
        WindowMode                  window_mode() const;
        
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

        using Tachyon::teardown;

        //! Our general "update()" that includes the visualizer
        virtual Execution   tick(const Context&) override;
        
    protected:

        virtual Execution   setup(const Context&) override;
        virtual Execution   teardown(const Context&) override;

        virtual PostAdvice  advise(const Post&) const override;
        
        void        snap(ViewerSnap&) const;

    private:

        friend class GLFWManager;
        friend class Application;
        friend class Widget;

        static std::atomic<int>         s_count;
        static std::atomic<unsigned>    s_lastNumber;

        const ViewerCreateInfo          m_createInfo;
        const unsigned                  m_number;
        
        enum class X : uint8_t {
            Failure,
            SentDevRequest,
            DevReply,
            HideCommand,
            HideEvent,
            DestroyCommand,
            
            NoImGuiKeyboard,
            NoImGuiMouse
        };

        Cleanup                         m_cleanup;
        std::atomic<unit::Second>       m_drawTime      = { 0. };
        TypedID                         m_focus         = {};
        std::unique_ptr<ViGui>          m_imgui;
        //std::atomic<bool>               m_paused;
        ViewerState                     m_state;
        //std::atomic<Stage>              m_stage         = { Stage::Preinit };
        Flags<X>                        m_flags       = {};   //! Startup & shutdown
        std::atomic<uint64_t>           m_ticks{0};
        std::unique_ptr<Visualizer>     m_viz;
        TypedID                         m_widget;
        Widget*                         m_widgetPtr = nullptr;  // temporary cheat
        TypedID                         m_window;
        TypedID                         m_graphicsCard;
        bool                            m_zeroSize  = false;

        // Might have a filter/time thing (later) so a spam of the close button triggers fast-close
        RequestCPtr                     m_closeRequest;

        void                _sweepwait();
        void                _widget(TypedID);     // Changes the widget
        
        Execution    update(const Context&);
        

        void    on_aspect_command(const AspectCommand&);
        void    on_attention_command(const AttentionCommand&);
        void    on_close_command(const CloseCommand&);
        void    on_close_request(const CloseRequestCPtr&);
        void    on_close_reply(const CloseReply&);
        void    on_cursor_command(const CursorCommand&);
        void    on_defocus_event(const DefocusEvent&);
        void    on_destroy_event(const DestroyEvent&);
        void    on_fb_resize_event(const FramebufferResizeEvent&);
        void    on_focus_command(const FocusCommand&);
        void    on_focus_event(const FocusEvent&);
        void    on_float_command(const FloatCommand&);
        void    on_get_device_reply(const GetDeviceReply&);
        void    on_hide_event(const HideEvent&);
        void    on_hide_command(const HideCommand&);
        void    on_iconify_command(const IconifyCommand&);
        void    on_imgui_disable_keyboard_command(const ImGuiDisableKeyboardCommand&);
        void    on_imgui_enable_keyboard_command(const ImGuiEnableKeyboardCommand&);
        void    on_imgui_disable_mouse_command(const ImGuiDisableMouseCommand&);
        void    on_imgui_enable_mouse_command(const ImGuiEnableMouseCommand&);
        void    on_key_character_event(const KeyCharacterEvent&);
        void    on_key_press_event(const KeyPressEvent&);
        void    on_key_release_event(const KeyReleaseEvent&);
        void    on_maximize_command(const MaximizeCommand&);
        void    on_mouse_move_event(const MouseMoveEvent&);
        void    on_mouse_press_event(const MousePressEvent&);
        void    on_mouse_release_event(const MouseReleaseEvent&);
        void    on_move_event(const Position²Event&);
        void    on_restore_command(const RestoreCommand&);
        void    on_size_event(const Size²Event&);
        void    on_show_command(const ShowCommand&);
        void    on_spatial_command(const SpatialCommand&);
        void    on_title_command(const TitleCommand&);
        void    on_unfloat_command(const UnfloatCommand&);

        

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //  OLD CODE

        //void    on_widget_request(const SetWidgetRequest&);

            //! Monitor (if fullscreen)
        //Monitor             monitor() const;
        
        //! Set the widget
        //void                set_widget(Widget*, bool fDestroyOld=true);

    
        //Widget*             widget_at(const Vector2D&) const;

    };
}

YQ_TYPE_DECLARE(yq::tachyon::ViewerID)
