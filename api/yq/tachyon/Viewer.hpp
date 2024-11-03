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
#include <yq/tachyon/commands/forward.hpp>
#include <yq/tachyon/enum/MouseState.hpp>
#include <yq/tachyon/events/forward.hpp>
#include <yq/tachyon/replies/forward.hpp>
#include <yq/tachyon/requests/forward.hpp>
#include <yq/typedef/size2.hpp>
#include <yq/vector/Vector2.hpp>

//#include <yq/tachyon/viz/Visualizer.hpp>
//#include <yq/tachyon/glfw/Window.hpp>

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
    struct ViewerCreateInfo;
    
    
    /*! \brief Vulkan Window
    
        This is a vulkan window, called the viewer, that binds the 
        GLFW Window and the Vulkan Device.  It will hold ONE widget
        and one widget only, this is the root widget for the viewer.
    */
    class Viewer : public Tachyon {
        YQ_OBJECT_DECLARE(Viewer, Tachyon)
    
        friend class Application;

    //  TODO FEATURE LIST
    //
    //  + Raw Mouse Motion (set https://www.glfw.org/docs/latest/input_guide.html#input_mouse_button )
    //  + Cursor control
    
    public:
        
        
    
        struct State {
            Vector2D        position, size, frame_buffer, scale;
            std::string     title;
        };

        static bool raw_mouse_motion_supported();
    
    
        static void init_info();
    
        /*! \brief Creates the viewer
        */
        Viewer(const ViewerCreateInfo&vci, Widget* w);
        
        //! Destructor
        virtual ~Viewer();
        
        /*! \brief Creates & initializes viewer 
        
            \note This one throws a std::error_code if problems occur
        */
//        Viewer();
        
        /*! \brief Initializes the viewer
            
            Initializes the viewer to render specified top-level widget
        */
        //std::error_code     initialize(const ViewerCreateInfo&vci, Widget*);
        
        //! Attention from the user
        void                cmd_attention();

        //! Sets the close flag
        void                cmd_close();
    
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

        const Vector2D&     cursor_position() const { return m_cursorPos; }

        //! Runs the draw sequence
        std::error_code     draw(ViContext&);
        
        //! Runs the draw sequence (uses a default context and calls the other)
        std::error_code     draw();
        
        //! Time (in seconds) of last draw call
        double              draw_time() const { return m_drawTime; }
        
        Size2I              framebuffer_size() const;

        //! Current frame number
        uint64_t            frame_number() const;
        
        Widget*             focus_widget() const { return m_focus; }
        
            //! Height of the window
        int                 height() const;

        uint64_t            id() const { return m_id; }


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
        
            //! Monitor (if fullscreen)
        Monitor             monitor() const;
        
        MouseState          mouse_state() const { return m_mouseState; }

        //! TRUE if rendering is paused
        bool                render_paused() const { return m_paused; }
        
            //! Current window position
        Vector2I            position() const;


        //! Set the rendering paused flag
        void                set_render_paused(bool);
        
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
        
        //! Set the widget
        void                set_widget(Widget*, bool fDestroyOld=true);

            //! TRUE if user wants window to close
        bool                should_close() const;

            //! Viewer size
        Size2I              size() const;

        std::string         title() const;

        Widget*             widget_at(const Vector2D&) const;

            //! Width of the window
        int                 width() const;

        Visualizer&         visualizer() const;

        GLFWwindow*         window() const { return m_window; }
        
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
        
    private:
    
        bool    mouse_capture_command(const MouseCaptureCommandCPtr&);
        bool    mouse_disable_command(const MouseDisableCommandCPtr&);
        bool    mouse_hide_command(const MouseHideCommandCPtr&);
        bool    mouse_normal_command(const MouseNormalCommandCPtr&);
        
        bool    viewer_attention_command(const ViewerAttentionCommandCPtr&);
        bool    viewer_close_request(const ViewerCloseRequestCPtr&);
        bool    viewer_close_command(const ViewerCloseCommandCPtr&);
        bool    viewer_hide_command(const ViewerHideCommandCPtr&);
        bool    viewer_resize_event(const ViewerResizeEventCPtr&);
        

    private:
        //void                record(ViContext&);
        
        static std::atomic<int>         s_count;
        static std::atomic<uint64_t>    s_lastId;
        
        static Tachyon::Param   _pbx(const ViewerCreateInfo&);

        
        void    _init(const ViewerCreateInfo&vci, Widget*w);
        void    _kill();

        const uint64_t                  m_id;
        GLFWwindow*                     m_window        = nullptr;
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
        std::string                     m_title;
        Vector2D                        m_cursorPos     = ZERO;
        MouseState                      m_mouseState    = MouseState::Normal;
        
        ViewerCloseRequestCPtr          m_viewerCloseRequest;
        
        //  No mutexes, if we can help it....
        //mutable tbb::spin_rw_mutex      m_mutex;
        
        //  Maybe some sort of focus manager (or policy)?
        
        void                purge_deleted();
        
        //virtual void        kill_window() { kill(); }
        //void                kill();

#if 0
        static void callback_character(GLFWwindow* window, unsigned int codepoint);
        static void callback_cursor_enter(GLFWwindow* window, int entered);
        static void callback_cursor_position(GLFWwindow* window, double xpos, double ypos);
        static void callback_drop(GLFWwindow* window, int count, const char** paths);
        static void callback_framebuffer_size(GLFWwindow* window, int width, int height);
        static void callback_key(GLFWwindow* window, int key, int scancode, int action, int mods);
        static void callback_mouse_button(GLFWwindow* window, int button, int action, int mods);
        static void callback_scroll(GLFWwindow* window, double xoffset, double yoffset);
        static void callback_window_close(GLFWwindow* window);
        static void callback_window_focus(GLFWwindow* window, int focused);
        static void callback_window_iconify(GLFWwindow* window, int iconified);
        static void callback_window_maximize(GLFWwindow* window, int maximized);
        static void callback_window_position(GLFWwindow* window, int xpos, int ypos);
        static void callback_window_refresh(GLFWwindow* window);
        static void callback_window_scale(GLFWwindow* window, float xscale, float yscale);
        static void callback_window_size(GLFWwindow*, int, int);
        
        void    dispatch_character(unsigned int);
        void    dispatch_cursor_enter(int);
        void    dispatch_cursor_position(double, double);
        void    dispatch_drop(int, const char**);
        void    dispatch_framebuffer_size(int, int);
        void    dispatch_key(int, int, int, int);
        void    dispatch_mouse_button(int, int, int);
        void    dispatch_scroll(double, double);
        void    dispatch_window_close();
        void    dispatch_window_focus(int);
        void    dispatch_window_iconify(int);
        void    dispatch_window_maximize(int);
        void    dispatch_window_position(int, int);
        void    dispatch_window_refresh();
        void    dispatch_window_scale(float, float);
        void    dispatch_window_size(int,int);
#endif
        
        Vector2D    _probe_cursor_position() const;
    };
    
    
    
}
