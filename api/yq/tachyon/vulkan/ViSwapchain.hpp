////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/core/Expect.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <yq/tachyon/typedef/vi_swapchain.hpp>
#include <vulkan/vulkan_core.h>
#include <system_error>
#include <vector>

namespace yq::tachyon {
    class ViVisualizer;

    struct ViSwapchainConfig {
        //! Overrides the render pass
        VkRenderPass    render_pass         = nullptr;
        VkSwapchainKHR  old_swapchain       = nullptr;
        bool            debug_echo_extents  = false;
    };

    class ViSwapchain : public RefCount {
    public:
        ViSwapchain();
        ViSwapchain(ViVisualizer&, const ViSwapchainConfig& cfg=ViSwapchainConfig{});
        ~ViSwapchain();
        
        std::error_code init(ViVisualizer&, const ViSwapchainConfig& cfg=ViSwapchainConfig{});
        void            kill();
        
        bool            consistent() const;
        VkRect2D        def_scissor() const;
        VkViewport      def_viewport() const;
        VkFramebuffer   framebuffer(uint32_t) const;
        uint32_t        height() const;
        VkImage         image(uint32_t) const;
        uint32_t        image_count() const { return m_imageCount; }
        VkImageView     image_view(uint32_t) const;
        uint32_t        min_image_count() const { return m_minImageCount; }
        VkSwapchainKHR  swapchain() const { return m_swapchain; }
        bool            valid() const;
        uint32_t        width() const;


        const VkSurfaceCapabilitiesKHR&     capabilities() const { return m_capabilities; }
        const VkExtent2D&                   extents() const { return m_extents; }
        //const std::vector<VkFramebuffer>&   framebuffers() const { return m_frameBuffers; }
        //const std::vector<VkImage>&         images() const { return m_images; }
        //const std::vector<VkImageView>&     image_views() const { return m_imageViews; }
        
        Expect<RasterPtr>   snapshot(uint32_t, VkFormat desired=VK_FORMAT_UNDEFINED) const;
        VkSemaphore         semaphore_available(uint32_t) const;

    private:
        struct Frame;
    
        ViVisualizer*               m_viz               = nullptr;
        VkSwapchainKHR              m_swapchain         = nullptr;
        VkExtent2D                  m_extents           = {};
        uint32_t                    m_minImageCount     = 0;
        uint32_t                    m_imageCount        = 0;
        VkSurfaceCapabilitiesKHR    m_capabilities;
        std::vector<Frame>          m_frames;
        struct {
            VkImage                 image       = nullptr;
            VkImage                 imageView   = nullptr;
        }   m_depth;

        std::error_code _init(ViVisualizer&, const ViSwapchainConfig& cfg=ViSwapchainConfig{});
        void            _kill();
        
        std::error_code _init(Frame&, VkImage, VkRenderPass);
        void            _kill(Frame&);
    };
}
