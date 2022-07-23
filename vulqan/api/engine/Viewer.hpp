////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ViewerCreateInfo.hpp"

#include <basic/Object.hpp>
#include <basic/Ref.hpp>
#include <basic/trait/not_copyable.hpp>
#include <basic/trait/not_moveable.hpp>
#include <math/preamble.hpp>
#include <math/Size2.hpp>
#include <math/Vector2.hpp>
#include <math/Units.hpp>
#include <vulkan/vulkan_core.h>

#include <functional>
#include <optional>
#include <memory>

struct GLFWwindow;
struct ImGuiContext;

namespace yq {
    namespace engine {
        struct PipelineConfig;
        class VqWindow;
        struct Visualizer;
        class VqAllocator;
        struct Scene;
        struct Perspective;
        
        
        struct WindowInfo : public ObjectInfo {
            WindowInfo(std::string_view, ObjectInfo&, const std::source_location& sl = std::source_location::current());
        };
        
        
        /*! \brief A basic window
        
            This encapsulates the GLFW & Vulkan into a single window, requires
            a Vulkan instance.
        */
        class Viewer : public Object, public RefCount, trait::not_copyable, trait::not_moveable {
            YQ_OBJECT_INFO(WindowInfo)
            YQ_OBJECT_DECLARE(Viewer, Object)
        public:
        
            static constexpr const uint32_t kMinimumDescriptors = 1000;
            
                //! Polls for events (does not loiter)
            static void poll_events();


                // Creates a window bound to the specified vulkan instance
            Viewer(const ViewerCreateInfo& i = ViewerCreateInfo());
            
            ~Viewer();
            

                //! Calls user's attention to window
            void                attention();
            
            RGBA4F              clear_color() const;

                //! Closes (politely) this window....
            void                close();
            
            
            VkCommandBuffer     command_buffer() const;
            
            VkCommandPool       command_pool() const;

            VkQueue             compute_queue(uint32_t i=0) const;
            uint32_t            compute_queue_count() const;
            uint32_t            compute_queue_family() const;
            
            const Vector2D&     cursor_pos() const { return m_cursorPos; }
            
            VkDescriptorPool    descriptor_pool() const;
            
            VkDevice            device() const;

                //! Brings window to front & input focus
            void                focus();
            
            uint64_t            frame_number() const { return m_frameNumber; }
            

                //! Good & initialized window
            bool                good() const { return m_viz != nullptr; }
            
                //! Returns the name of the GPU/physical device
            std::string_view    gpu_name() const;
            
                //! Returns the type of the GPU/physical device
            VkPhysicalDeviceType    gpu_type() const;
            
            VkQueue             graphic_queue(uint32_t i=0) const;
            uint32_t            graphic_queue_count() const;
            uint32_t            graphic_queue_family() const;

                //! Height of the window
            int                 height() const;
            
                //! Hide the window
            void                hide();

                //! Iconifies (minimizes) window
            void                iconify();

            
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
            
                //! Our device (logical)
            VkDevice            logical() const;

            uint32_t            max_memory_allocation_count() const;
            uint32_t            max_push_constants_size() const;
            uint32_t            max_viewports() const;
            
                //! Maximizes widnow
            void                maximize();

                //! Monitor (if fullscreen)
            VqMonitor           monitor() const;

            VkPhysicalDevice    physical() const;

                //! Current window position
            Vector2I            position() const;
            
            PresentMode         present_mode() const;
            
            const std::set<PresentMode>&     present_modes_available() const;
            
            VkQueue             present_queue(uint32_t i=0) const;
            uint32_t            present_queue_count() const;
            uint32_t            present_queue_family() const;

            VkRenderPass        render_pass() const;
            
                //! Restores the window to non-fullscreen/iconify
            void                restore();

                //! Sets the background color
            void                set_clear_color(const RGBA4F&);

                //! Sets the window position
            void                set_position(const Vector2I&);

                //! Sets the window position
            void                set_position(int x, int y);
            
            void                set_present_mode(PresentMode);

                //! Sets window size
            void                set_size(const Size2I&);

                //! Sets window size
            void                set_size(int w, int h);
            
                //! Sets the window title
            void                set_title(const char*);

                //! Sets the window title
            void                set_title(const std::string&);

                //! TRUE if user wants window to close
            bool                should_close() const;
            
                //! Show the window
            void                show();

                //! Viewer size
            Size2I              size() const;
            
            //const VkExtent2D&   swap_extent() const { return m_swapExtent; }
            
                //! The Vulkan surface
            VkSurfaceKHR        surface() const;

            VkColorSpaceKHR     surface_color_space() const;

            VkFormat            surface_format() const;
            
            bool                supports(VkFormat) const;
            bool                supports(PresentMode) const;
            
            VkRect2D            swap_def_scissor() const;
            
            VkViewport          swap_def_viewport() const;

            uint32_t            swap_image_count() const;
            uint32_t            swap_min_image_count() const;

            uint32_t            swap_width() const;
            
            uint32_t            swap_height() const;
            
            const std::string&  title() const { return m_title; }

            VkQueue             video_decode_queue(uint32_t i=0) const;
            uint32_t            video_decode_queue_count() const;
            uint32_t            video_decode_queue_family() const;

            VkQueue             video_encode_queue(uint32_t i=0) const;
            uint32_t            video_encode_queue_count() const;
            uint32_t            video_encode_queue_family() const;

            
            
                //! Width of the window
            int                 width() const;

                //! GLFW window handle
            GLFWwindow*         window() const;
            
            //  This is the "DRAW" pass, do it all, whatever the result is
            bool                draw();

            operator Visualizer&  () { return *m_viz; }

            void                render(VkCommandBuffer, const Scene&, const Perspective&);

        protected:
        
            friend struct Visualizer;
            friend class VqWindow;
        
            //VkPipeline                  m_lastPipeline  = nullptr;
            virtual void        window_resized(){}
            virtual void        viewport_changed(){}
            
            //  called if ImGUI is enabled
            virtual void        draw_imgui(){}
            virtual void        draw_vulqan(VkCommandBuffer);
            
            
        private:
        
            GLFWwindow*                     m_window    = nullptr;
            std::unique_ptr<Visualizer>     m_viz;
            std::string                     m_title;
            uint64_t                        m_frameNumber   = 0;
            unit::Second                    m_drawTime      = {};
            ImGuiContext*                   m_imgui         = nullptr;
            Vector2D                        m_cursorPos     = {};

            void    _dtor();
            bool    record(VkCommandBuffer, uint32_t);
            
            static void callback_character(GLFWwindow* window, unsigned int codepoint);
            static void callback_cursor_enter(GLFWwindow* window, int entered);
            static void callback_cursor_position(GLFWwindow* window, double xpos, double ypos);
            static void callback_drop(GLFWwindow* window, int count, const char** paths);
            static void callback_framebuffer_size(GLFWwindow* window, int width, int height);
            static void callback_joystick(int jid, int event);
            static void callback_key(GLFWwindow* window, int key, int scancode, int action, int mods);
            static void callback_monitor(GLFWmonitor* monitor, int event);
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
        };
        
    }
}
