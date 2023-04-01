////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <basic/Flags.hpp>
#include <math/preamble.hpp>
#include <system_error>

namespace yq {
    namespace tachyon {
        class Window {
        public:
        
            #if 0
            enum class Hook : uint8_t {
                Keyboard,
                Mouse,
                Joystick,
                Windowing,
                Monitor,
                Drop,
                Framebuffer
            };
        
            using Hooks = Flags<Hook>;
            #endif
        
            static bool rawMouseMotionSupported();
        
        
            //static_assert(!is_template_enum_v<Hooks>, "Hooks violates enum constraitn");
        
            Window();
            
            //! Warning, this will THROW std::error_code if problems on creation!
            Window(const ViewerCreateInfo&);
            ~Window();
            
            GLFWwindow*         window() const { return m_window; }

            //  ------------------------------------------------
            //  GETTERS

                //! Height of the window
            int                 height() const;

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

                //! Current window position
            Vector2I            position() const;

                //! TRUE if user wants window to close
            bool                should_close() const;

                //! Viewer size
            Size2I              size() const;

            std::string_view    title() const { return m_title; }

                //! Width of the window
            int                 width() const;

            //  ------------------------------------------------
            //  MANIPULATION/SETTING
            
            //! Attention from the user
            void        cmd_attention();

            //! Sets the close flag
            void        cmd_close();
        
            //! Focus onto this window
            void        cmd_focus();

            //! Hides the window
            void        cmd_hide();
            
            //! Iconify/minimizes the window;
            void        cmd_iconify();
            
                //! Maximizes widnow
            void        cmd_maximize();

            //! Restore the window to non-icon/non-fullscreen
            void        cmd_restore();

                //! Show the window
            void        cmd_show();

                //! Sets the window position
            void        set_position(const Vector2I&);

                //! Sets the window position
            void        set_position(int x, int y);

                //! Sets window size
            void        set_size(const Size2I&);

                //! Sets window size
            void        set_size(int w, int h);
            
                //! Sets the window title
            void        set_title(std::string_view);

        protected:
        
            //  NOTE... initializing w/o starting GLFW is bad mojo!
            std::error_code     init_window(const ViewerCreateInfo&);
            virtual void        kill_window();

        private:
            Window(const Window&) = delete;
            Window(Window&&) = delete;
            
            GLFWwindow*     m_window    = nullptr;
            std::string     m_title;
//            Vector2D        m_cursorPos = {};
            bool            m_init      = false;
        };
    }
}

