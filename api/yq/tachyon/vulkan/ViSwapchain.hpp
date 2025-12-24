////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/core/Expect.hpp>
#include <yq/tachyon/keywords.hpp>
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
        //ViSwapchain();
        ViSwapchain(ViVisualizer&, const ViSwapchainConfig& cfg=ViSwapchainConfig{});
        ~ViSwapchain();
        
        VkRect2D        def_scissor() const;
        VkViewport      def_viewport() const;
        uint32_t        height() const;
        uint32_t        image_count() const { return m_imageCount; }
        uint32_t        min_image_count() const { return m_minImageCount; }
        bool            valid() const;
        uint32_t        width() const;

        const VkSurfaceCapabilitiesKHR&     capabilities() const { return m_capabilities; }
        const VkExtent2D&                   extents() const { return m_extents; }
        //const std::vector<VkFramebuffer>&   framebuffers() const { return m_frameBuffers; }
        //const std::vector<VkImage>&         images() const { return m_images; }
        //const std::vector<VkImageView>&     image_views() const { return m_imageViews; }
        
        Expect<RasterPtr>   snapshot(uint32_t, VkFormat desired=VK_FORMAT_UNDEFINED) const;
        //VkSemaphore         semaphore_available(uint32_t) const;

        VkFence         vk_fence(uint32_t) const;
        VkFramebuffer   vk_framebuffer(uint32_t) const;
        VkImage         vk_image(uint32_t) const;
        VkImage         vk_image(depth_k, uint32_t) const;
        VkImageView     vk_image_view(uint32_t) const;
        VkImageView     vk_image_view(depth_k, uint32_t) const;
        VkSemaphore     vk_semaphore(available_k, uint32_t) const;
        VkSemaphore     vk_semaphore(rendered_k, uint32_t) const;
        VkSwapchainKHR  vk_swapchain() const { return m_swapchain; }

    private:
    
        ViVisualizer&               m_viz;
        VkSwapchainKHR              m_swapchain         = nullptr;
        VkExtent2D                  m_extents           = {};
        uint32_t                    m_minImageCount     = 0;
        uint32_t                    m_imageCount        = 0;
        VkSurfaceCapabilitiesKHR    m_capabilities;
        
        std::vector<VkImage>        m_images;
        std::vector<VkImageView>    m_imageViews;
        std::vector<VkImage>        m_depthImages;
        std::vector<VkImageView>    m_depthViews;
        std::vector<VkFramebuffer>  m_framebuffers;

        std::vector<VkFence>        m_fences;
        std::vector<VkSemaphore>    m_imageAvailableSemaphores;
        std::vector<VkSemaphore>    m_renderCompleteSemaphores;
        bool                        m_good          = false;
        
        std::error_code _init(const ViSwapchainConfig& cfg=ViSwapchainConfig{});
        void            _kill();
    };
}
