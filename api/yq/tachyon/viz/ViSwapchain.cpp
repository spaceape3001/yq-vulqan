////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViSwapchain.hpp"

#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/ImageViewInfo.hpp>
#include <yq/tachyon/api/Raster.hpp>
#include <yq/tachyon/v/VqLogging.hpp>
#include <yq/tachyon/v/VqStructs.hpp>
#include <yq/tachyon/v/VqUtils.hpp>
#include <yq/tachyon/viz/ViImage.hpp>
#include <yq/tachyon/viz/ViVisualizer.hpp>
#include <algorithm>
//#include <GLFW/glfw3.h>

namespace yq::tachyon {
    namespace errors {
        using swapchain_bad_state               = error_db::entry<"Swapchain is in a bad state">;
        using swapchain_cant_create             = error_db::entry<"Unable to create swapchain">;
        using swapchain_existing                = error_db::entry<"Swapchain already exists">;
        using swapchain_image_out_of_range      = error_db::entry<"Specified image index is out of range">;
    }

    ViSwapchain::ViSwapchain()
    {
    }
    
    ViSwapchain::ViSwapchain(ViVisualizer&viz, const ViSwapchainConfig& cfg)
    {
        if(viz.device() && viz.surface() && viz.physical() && (viz.render_pass() || cfg.render_pass)){
            std::error_code ec  = _init(viz, cfg);
            if(ec != std::error_code()){
                _kill();
            }
        }
    }
    
    ViSwapchain::~ViSwapchain()
    {
        kill();
    }
    
    std::error_code ViSwapchain::_init(ViVisualizer& viz, const ViSwapchainConfig& cfg)
    {
        m_viz   = &viz;
        
        VkResult    res;
        
        res = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(viz.physical(), viz.surface(), &m_capabilities);
        if(res != VK_SUCCESS){
            vizWarning << "ViSwapchain(): Cannot get capabilities.  VkResult " << (int32_t) res;
            return errors::swapchain_cant_create();
        }
        
        if (m_capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max()) {
            m_extents = m_capabilities.currentExtent;
        } else if(viz._window()){
            Size2I fb  = viz.framebuffer_size();
            m_extents = {};
            m_extents.width  = std::clamp((uint32_t) fb.x, m_capabilities.minImageExtent.width, m_capabilities.maxImageExtent.width);
            m_extents.height = std::clamp((uint32_t) fb.y, m_capabilities.minImageExtent.height, m_capabilities.maxImageExtent.height);
        } else {
            vizWarning << "ViSwapchain(): Cannot get extents.";
        }
        
        if(cfg.debug_echo_extents){
            Size2I fb  = viz.framebuffer_size();

            vizInfo << "ViSwapchain() : Extents\n" <<
                "Frame itself is " << VkExtent2D{ (uint32_t) fb.x, (uint32_t) fb.y } << " vs\n" <<
                "Image extents is " << m_extents << '\n' <<
                "Cur is " << m_capabilities.currentExtent << '\n' <<
                "Min is " << m_capabilities.minImageExtent << '\n' <<
                "Max is " << m_capabilities.maxImageExtent
            ;
        }

        m_minImageCount = std::max<uint32_t>(m_capabilities.minImageCount, 2);
        m_imageCount    = m_minImageCount + 1;
        if ((m_capabilities.maxImageCount > 0) && (m_imageCount > m_capabilities.maxImageCount)) {
            m_imageCount = m_capabilities.maxImageCount;
        }

        VqSwapchainCreateInfoKHR    swapInfo;
        swapInfo.surface          = viz.surface();
        swapInfo.minImageCount    = m_imageCount;
        swapInfo.imageFormat      = viz.surface_format();
        swapInfo.imageColorSpace  = viz.surface_color_space();
        swapInfo.imageExtent      = m_extents;
        swapInfo.imageArrayLayers = 1;    // we're not steroscopic (YET)  <-- OCULUS HERE
        swapInfo.imageUsage       = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
        
        uint32_t queueFamilyIndices[] = {viz.graphic_queue_family(), viz.present_queue_family()};
        if (viz.graphic_queue_family() != viz.present_queue_family()) {
            swapInfo.imageSharingMode = VK_SHARING_MODE_CONCURRENT;
            swapInfo.queueFamilyIndexCount = 2;
            swapInfo.pQueueFamilyIndices = queueFamilyIndices;
        } else {
            swapInfo.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
            swapInfo.queueFamilyIndexCount = 0; // Optional
            swapInfo.pQueueFamilyIndices = nullptr; // Optional
        }        
        swapInfo.preTransform     = m_capabilities.currentTransform;
        swapInfo.compositeAlpha   = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
        swapInfo.presentMode      = (VkPresentModeKHR) viz.present_mode().value();
        swapInfo.clipped          = VK_TRUE;
        swapInfo.oldSwapchain     = cfg.old_swapchain;
        
        res = vkCreateSwapchainKHR(viz.device(), &swapInfo, nullptr, &m_swapchain);
        if(res != VK_SUCCESS){
            vizWarning << "ViSwapchain(): Cannot create swapchain.  VkResult " << (int32_t) res;
            return errors::swapchain_cant_create();
        }

        uint32_t imageCount = m_imageCount;
        res = vkGetSwapchainImagesKHR(viz.device(), m_swapchain, &m_imageCount, nullptr);
        if(res != VK_SUCCESS){
            vizWarning << "ViSwapchain(): Cannot get swapchain image count.  VkResult " << (int32_t) res;
            return errors::swapchain_cant_create();
        }
        
        if(imageCount < m_imageCount){
            vizWarning << "ViSwapchain(): Cannot get desired number of images, might be an issue.  " << imageCount << " vs " << m_imageCount;
        }
        m_imageCount    = imageCount;
        m_images.resize(m_imageCount, nullptr);
        
        res = vkGetSwapchainImagesKHR(viz.device(), m_swapchain, &m_imageCount, m_images.data());
        if(res != VK_SUCCESS){
            vizWarning << "ViSwapchain(): Cannot get images.  VkResult " << (int32_t) res;
            return errors::swapchain_cant_create();
        }

        m_imageViews.resize(m_imageCount, nullptr);

        VkImageViewCreateInfo       imageViewInfo = vqCreateInfo(ImageViewInfo());
        imageViewInfo.format       = viz.surface_format();

        for(size_t i=0; i<m_imageCount; ++i){
            imageViewInfo.image        = m_images[i];
            res = vkCreateImageView(viz.device(), &imageViewInfo, nullptr, &m_imageViews[i]);
            if(res != VK_SUCCESS){
                vizWarning << "ViSwapchain(): Cannot create a swapchain image viewer.  VkResult " << (int32_t) res;
                return errors::swapchain_cant_create();
            }
        }                

        m_frameBuffers.resize(m_imageCount, nullptr);
        VqFramebufferCreateInfo   frameBufferInfo;
        
        if(cfg.render_pass){
            frameBufferInfo.renderPass  = cfg.render_pass;
        } else {
            frameBufferInfo.renderPass  = viz.render_pass();
        }
        frameBufferInfo.attachmentCount  = 1;
        frameBufferInfo.width            = m_extents.width;
        frameBufferInfo.height           = m_extents.height;
        frameBufferInfo.layers           = 1;

        for(size_t i=0;i<m_imageCount;++i){
            frameBufferInfo.pAttachments = &m_imageViews[i];
            res = vkCreateFramebuffer(viz.device(), &frameBufferInfo, nullptr, &m_frameBuffers[i]);
            if (res != VK_SUCCESS){
                vizWarning << "ViSwapchain(): Cannot create a swapchain framebuffer.  VkResult " << (int32_t) res;
                return errors::swapchain_cant_create();
            }
        }
        return {};
    }
    
    void            ViSwapchain::_kill()
    {
        if(m_viz && m_viz->device()){
            for(VkFramebuffer b : m_frameBuffers){
                if(!b)
                    continue;
                vkDestroyFramebuffer(m_viz->device(), b, nullptr);
            }
            for(VkImageView iv : m_imageViews){
                if(!iv)
                    continue;
                vkDestroyImageView(m_viz->device(), iv, nullptr);
            }
        }
        m_frameBuffers.clear();
        m_imageViews.clear();
        m_images.clear();
        if(m_swapchain && m_viz && m_viz->device()){
            vkDestroySwapchainKHR(m_viz->device(), m_swapchain, nullptr);
            m_swapchain  = nullptr;
        }

        m_viz           = nullptr;
        m_extents       = {};
        m_minImageCount = 0;
        m_imageCount    = 0;
        m_capabilities  = {};
    }
    

    bool            ViSwapchain::consistent() const
    {
        return m_viz ? (m_swapchain && m_imageCount && m_viz->device()) : (!m_swapchain && !m_imageCount);
    }
    
    VkRect2D  ViSwapchain::def_scissor() const
    {
        VkRect2D    ret{};
        ret.offset  = { 0, 0 };
        ret.extent  = m_extents;
        return ret;
    }
    
    VkViewport  ViSwapchain::def_viewport() const
    {
        VkViewport  ret{};
        ret.x = 0.0f;
        ret.y = 0.0f;
        ret.width = (float) m_extents.width;
        ret.height = (float) m_extents.height;
        ret.minDepth = 0.0f;
        ret.maxDepth = 1.0f;
        return ret;
    }

    VkFramebuffer   ViSwapchain::framebuffer(uint32_t i) const
    {
        if(i>=m_frameBuffers.size())
            return nullptr;
        return m_frameBuffers[i];
    }
    
    uint32_t  ViSwapchain::width() const 
    { 
        return m_extents.width; 
    }

    VkImage         ViSwapchain::image(uint32_t i) const
    {
        if(i>=m_images.size())
            return nullptr;
        return m_images[i];
    }
    
    VkImageView     ViSwapchain::image_view(uint32_t i) const
    {
        if(i>=m_imageViews.size())
            return nullptr;
        return m_imageViews[i];
    }
    
    std::error_code ViSwapchain::init(ViVisualizer&viz, const ViSwapchainConfig& cfg)
    {
        if(m_viz){
            if(!consistent()){
                return errors::swapchain_bad_state();
            }
            return errors::swapchain_existing();
        }
        if(!viz.device() || !viz.physical() || !viz.surface())
            return errors::visualizer_uninitialized();
        if(!(viz.render_pass() || cfg.render_pass))
            return errors::visualizer_insufficient();
        
        std::error_code ec  = _init(viz, cfg);
        if(ec != std::error_code()){
            _kill();
        }
        return ec;
    }
    
    void            ViSwapchain::kill()
    {
        _kill();
    }
    
    Expect<RasterPtr>   ViSwapchain::snapshot(uint32_t i, VkFormat desired) const
    {
        if(i >= m_images.size())
            return errors::swapchain_image_out_of_range();
        
        return export_image(*m_viz, m_images[i], ViImageExport{
            .type       = VK_IMAGE_TYPE_2D,
            .src_layout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
            .format     = m_viz -> surface_format(),
            .desired    = desired,
            .extent     = VkExtent3D{
                .width      = m_extents.width,
                .height     = m_extents.height,
                .depth      = 1
            }
        });
    }
    
    bool            ViSwapchain::valid() const
    {
        return m_viz && m_swapchain && m_imageCount;
    }

    uint32_t  ViSwapchain::height() const 
    { 
        return m_extents.height; 
    }
}
