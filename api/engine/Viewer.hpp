////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Object.hpp>
#include <basic/Ref.hpp>
#include <trait/not_copyable.hpp>
#include <trait/not_moveable.hpp>
#include <math/preamble.hpp>
#include <math/shape/Size2.hpp>
#include <math/vector/Vector2.hpp>
#include <math/units.hpp>
#include <vulkan/vulkan_core.h>
#include <tachyon/enum/PresentMode.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/host/Window.hpp>

#include <functional>
#include <optional>
#include <memory>

struct GLFWwindow;
struct ImGuiContext;

namespace yq {
    namespace engine {
        class Scene;
        class Perspective;
        
        struct Visualizer;

        
        /*! \brief A basic window
        
            This encapsulates the GLFW & Vulkan into a single window, requires
            a Vulkan instance.
        */
        class Viewer : public Object, public RefCount, public Window {
            //YQ_OBJECT_INFO(WindowInfo)
            YQ_OBJECT_DECLARE(Viewer, Object)
        public:


                // Creates a window bound to the specified vulkan instance
            Viewer(const ViewerCreateInfo& i = ViewerCreateInfo());
            
            ~Viewer();
            

            RGBA4F              clear_color() const;

            
            VkCommandBuffer     command_buffer() const;
            
            VkCommandPool       command_pool() const;

            
            const Vector2D&     cursor_pos() const { return m_cursorPos; }
            
            VkDescriptorPool    descriptor_pool() const;
            
            VkDevice            device() const;

            uint64_t            frame_number() const { return m_frameNumber; }
            

                //! Good & initialized window
            bool                good() const { return m_viz != nullptr; }
            
                //! Returns the name of the GPU/physical device
            std::string_view    gpu_name() const;
            
                //! Returns the type of the GPU/physical device
            VkPhysicalDeviceType    gpu_type() const;
            

            
                //! Our device (logical)
            VkDevice            logical() const;

            uint32_t            max_memory_allocation_count() const;
            uint32_t            max_push_constants_size() const;
            uint32_t            max_viewports() const;
            

            VkPhysicalDevice    physical() const;

            
            tachyon::PresentMode         present_mode() const;
            
            const std::set<tachyon::PresentMode>&     present_modes_available() const;
            

            VkRenderPass        render_pass() const;
            

                //! Sets the background color
            void                set_clear_color(const RGBA4F&);

            
            void                set_present_mode(tachyon::PresentMode);

            
            //const VkExtent2D&   swap_extent() const { return m_swapExtent; }
            
                //! The Vulkan surface
            VkSurfaceKHR        surface() const;

            VkColorSpaceKHR     surface_color_space() const;

            VkFormat            surface_format() const;
            
            bool                supports(VkFormat) const;
            bool                supports(tachyon::PresentMode) const;
            
            VkRect2D            swap_def_scissor() const;
            
            VkViewport          swap_def_viewport() const;

            uint32_t            swap_image_count() const;
            uint32_t            swap_min_image_count() const;

            uint32_t            swap_width() const;
            
            uint32_t            swap_height() const;
            
            

                //! GLFW window handle
            //GLFWwindow*         window() const;
            
            //  This is the "DRAW" pass, do it all, whatever the result is
            bool                draw();

            operator Visualizer&  () { return *m_viz; }

            void                render(VkCommandBuffer, const Scene&, const Perspective&);

        protected:
        
            friend struct Visualizer;
            //friend class VqWindow;
        
            //VkPipeline                  m_lastPipeline  = nullptr;
            virtual void        window_resized(){}
            virtual void        viewport_changed(){}
            
            //  called if ImGUI is enabled
            virtual void        draw_imgui(tachyon::ViContext&){}
            virtual void        draw_vulqan(VkCommandBuffer);
            
            virtual void        window_framebuffer_resized(const Size2I&) override;
            
            
        private:
        
            std::unique_ptr<Visualizer>     m_viz;
            uint64_t                        m_frameNumber   = 0;
            unit::Second                    m_drawTime      = {};
            ImGuiContext*                   m_imgui         = nullptr;
            Vector2D                        m_cursorPos     = {};

            void    _dtor();
            bool    record(VkCommandBuffer, uint32_t);
            
            Viewer(const Viewer&) = delete;
            Viewer(Viewer&&) = delete;
            Viewer& operator=(const Viewer&) = delete;
            Viewer& operator=(Viewer&&) = delete;
        };
        
    }
}
