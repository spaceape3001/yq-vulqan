////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/vulkan/ViSwapchain.hpp>

#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/pipeline/ImageViewInfo.hpp>
#include <yq/tachyon/vulkan/VqLogging.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>
#include <yq/tachyon/vulkan/VqUtils.hpp>
#include <yq/tachyon/vulkan/ViImage.hpp>
#include <yq/tachyon/vulkan/ViVisualizer.hpp>
#include <algorithm>
//#include <GLFW/glfw3.h>

namespace yq::tachyon {
    namespace errors {
        using swapchain_bad_state               = error_db::entry<"Swapchain is in a bad state">;
        using swapchain_cant_create             = error_db::entry<"Unable to create swapchain">;
        using swapchain_existing                = error_db::entry<"Swapchain already exists">;
        using swapchain_image_out_of_range      = error_db::entry<"Specified image index is out of range">;
    }

    ViSwapchain::ViSwapchain(ViVisualizer&viz, const ViSwapchainConfig& cfg) : m_viz(viz)
    {
        if(viz.device() && viz.surface() && viz.physical() && (viz.render_pass() || cfg.render_pass)){
            std::error_code ec  = _init(cfg);
            if(ec != std::error_code())
                _kill();
        }
    }
    
    ViSwapchain::~ViSwapchain()
    {
        _kill();
    }
    
    std::error_code ViSwapchain::_init(const ViSwapchainConfig& cfg)
    {
        VkResult    res;
        
        res = vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_viz.physical(), m_viz.surface(), &m_capabilities);
        if(res != VK_SUCCESS){
            vizWarning << "ViSwapchain(): Cannot get capabilities.  VkResult " << (int32_t) res;
            return errors::swapchain_cant_create();
        }
        
        if (m_capabilities.currentExtent.width != std::numeric_limits<uint32_t>::max()) {
            m_extents = m_capabilities.currentExtent;
        } else {
            Size2I fb  = m_viz.framebuffer_size();
            m_extents = {};
            m_extents.width  = std::clamp((uint32_t) fb.x, m_capabilities.minImageExtent.width, m_capabilities.maxImageExtent.width);
            m_extents.height = std::clamp((uint32_t) fb.y, m_capabilities.minImageExtent.height, m_capabilities.maxImageExtent.height);
        }
        
        if(cfg.debug_echo_extents){
            Size2I fb  = m_viz.framebuffer_size();

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
        swapInfo.surface          = m_viz.surface();
        swapInfo.minImageCount    = m_imageCount;
        swapInfo.imageFormat      = m_viz.surface_format();
        swapInfo.imageColorSpace  = m_viz.surface_color_space();
        swapInfo.imageExtent      = m_extents;
        swapInfo.imageArrayLayers = 1;    // we're not steroscopic (YET)  <-- OCULUS HERE
        swapInfo.imageUsage       = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
        
        uint32_t queueFamilyIndices[] = {m_viz.graphics_queue_family().index, m_viz.present_queue_family().index};
        if (m_viz.graphics_queue_family() != m_viz.present_queue_family()) {
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
        swapInfo.presentMode      = (VkPresentModeKHR) m_viz.present_mode().value();
        swapInfo.clipped          = VK_TRUE;
        swapInfo.oldSwapchain     = cfg.old_swapchain;
        
        res = vkCreateSwapchainKHR(m_viz.device(), &swapInfo, nullptr, &m_swapchain);
        if(res != VK_SUCCESS){
            vizWarning << "ViSwapchain(): Cannot create swapchain.  VkResult " << (int32_t) res;
            return errors::swapchain_cant_create();
        }

        uint32_t imageCount = m_imageCount;
        res = vkGetSwapchainImagesKHR(m_viz.device(), m_swapchain, &m_imageCount, nullptr);
        if(res != VK_SUCCESS){
            vizWarning << "ViSwapchain(): Cannot get swapchain image count.  VkResult " << (int32_t) res;
            return errors::swapchain_cant_create();
        }
        
        if(imageCount < m_imageCount){
            vizWarning << "ViSwapchain(): Cannot get desired number of images, might be an issue.  " << imageCount << " vs " << m_imageCount;
        }
        m_imageCount    = imageCount;
        
        m_images.resize(m_imageCount, nullptr);
        m_framebuffers.resize(m_imageCount, nullptr);
        m_imageViews.resize(m_imageCount, nullptr);
        m_imageAcquiredSemaphores.resize(m_imageCount+1, nullptr);
        m_renderCompleteSemaphores.resize(m_imageCount+1, nullptr);
        if(m_viz.depth_enabled()){
            m_depthImages.resize(m_imageCount, nullptr);
            m_depthViews.resize(m_imageCount, nullptr);
        }
        
        res = vkGetSwapchainImagesKHR(m_viz.device(), m_swapchain, &m_imageCount, m_images.data());
        if(res != VK_SUCCESS){
            vizWarning << "ViSwapchain(): Cannot get images.  VkResult " << (int32_t) res;
            return errors::swapchain_cant_create();
        }
        
        VkRenderPass        rp  = cfg.render_pass ? cfg.render_pass : m_viz.render_pass();
        

        VkImageViewCreateInfo   imageViewInfo = vqCreateInfo(ImageViewInfo());
        imageViewInfo.format    = m_viz.surface_format();
        

        VqFramebufferCreateInfo   frameBufferInfo;
        frameBufferInfo.renderPass      = rp;
        frameBufferInfo.attachmentCount = 1;
        frameBufferInfo.width           = m_extents.width;
        frameBufferInfo.height          = m_extents.height;
        frameBufferInfo.layers          = 1;

        VqImageCreateInfo   depthInfo;
        depthInfo.format            = m_viz.depth_format();
        depthInfo.extent            = { m_extents.width, m_extents.height, 1 };
        depthInfo.imageType         = VK_IMAGE_TYPE_2D;
        depthInfo.mipLevels         = 1;
        depthInfo.arrayLayers       = 1;
        depthInfo.samples           = VK_SAMPLE_COUNT_1_BIT;
        depthInfo.tiling            = VK_IMAGE_TILING_OPTIMAL;
        depthInfo.usage             = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT;
        depthInfo.sharingMode       = VK_SHARING_MODE_EXCLUSIVE;
        depthInfo.initialLayout     = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL;

        VqImageViewCreateInfo   depthViewInfo;
        depthViewInfo.viewType                          = VK_IMAGE_VIEW_TYPE_2D;
        depthViewInfo.format                            = m_viz.depth_format();

        depthViewInfo.components.r                      = VK_COMPONENT_SWIZZLE_IDENTITY;
        depthViewInfo.components.g                      = VK_COMPONENT_SWIZZLE_IDENTITY;
        depthViewInfo.components.b                      = VK_COMPONENT_SWIZZLE_IDENTITY;
        depthViewInfo.components.a                      = VK_COMPONENT_SWIZZLE_IDENTITY;
        depthViewInfo.subresourceRange.aspectMask       = VK_IMAGE_ASPECT_DEPTH_BIT;
        depthViewInfo.subresourceRange.baseMipLevel     = 0;
        depthViewInfo.subresourceRange.levelCount       = 1;
        depthViewInfo.subresourceRange.baseArrayLayer   = 0;
        depthViewInfo.subresourceRange.layerCount       = 1;


        for(size_t i=0;i<m_imageCount;++i){
            imageViewInfo.image     = m_images[i];
            
            res = vkCreateImageView(m_viz.device(), &imageViewInfo, nullptr, &m_imageViews[i]);
            if(res != VK_SUCCESS){
                vizWarning << "ViSwapchain(): Cannot create a swapchain image viewer.  VkResult " << (int32_t) res;
                return errors::swapchain_cant_create();
            }

            std::vector<VkImageView>    attachments = {m_imageViews[i]};

            if(m_viz.depth_enabled()){
                res = vkCreateImage(m_viz.device(), &depthInfo, nullptr, &m_depthImages[i]);
                if(res != VK_SUCCESS){
                    vizWarning << "ViSwapchain(): Cannot create a swapchain depth image.  VkResult " << (int32_t) res;
                    return errors::swapchain_cant_create();
                }
                
                depthViewInfo.image = m_depthImages[i];
                res = vkCreateImageView(m_viz.device(), &depthViewInfo, nullptr, &m_depthViews[i]);
                if(res != VK_SUCCESS){
                    vizWarning << "ViSwapchain(): Cannot create a swapchain depth image view.  VkResult " << (int32_t) res;
                    return errors::swapchain_cant_create();
                }
                
                attachments.push_back(m_depthViews[i]);
            }

            frameBufferInfo.attachmentCount = (uint32_t) attachments.size();
            frameBufferInfo.pAttachments    = attachments.data();

            res = vkCreateFramebuffer(m_viz.device(), &frameBufferInfo, nullptr, &m_framebuffers[i]);
            if (res != VK_SUCCESS){
                vizWarning << "ViSwapchain(): Cannot create a swapchain framebuffer.  VkResult " << (int32_t) res;
                return errors::swapchain_cant_create();
            }
        }
        return {};
    }
    
    
    void            ViSwapchain::_kill()
    {
        if(m_viz.device()){
            for(uint32_t n=0;n<=m_imageCount;++n){
                if(m_imageAcquiredSemaphores[n])
                    vkDestroySemaphore(m_viz.device(), m_imageAcquiredSemaphores[n], nullptr);
                if(m_renderCompleteSemaphores[n])
                    vkDestroySemaphore(m_viz.device(), m_renderCompleteSemaphores[n], nullptr);
            }
            m_imageAcquiredSemaphores.clear();
            m_renderCompleteSemaphores.clear();
            
            for(uint32_t n=0;n<m_imageCount;++n){
                if(m_framebuffers[n])
                    vkDestroyFramebuffer(m_viz.device(), m_framebuffers[n], nullptr);
                if(m_viz.depth_enabled()){
                    if(m_depthViews[n])
                        vkDestroyImageView(m_viz.device(), m_depthViews[n], nullptr);
                    if(m_depthImages[n])
                        vkDestroyImage(m_viz.device(), m_depthImages[n], nullptr);
                }
                if(m_imageViews[n])
                    vkDestroyImageView(m_viz.device(), m_imageViews[n], nullptr);
            }
            m_framebuffers.clear();
            m_imageViews.clear();
            m_depthViews.clear();
            m_depthImages.clear();
            m_images.clear();
        }
        if(m_swapchain && m_viz.device()){
            vkDestroySwapchainKHR(m_viz.device(), m_swapchain, nullptr);
            m_swapchain  = nullptr;
        }

        m_extents       = {};
        m_minImageCount = 0;
        m_imageCount    = 0;
        m_capabilities  = {};
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
        if(i>=m_framebuffers.size())
            return nullptr;
        return m_framebuffers[i];
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
    


    //VkSemaphore         ViSwapchain::semaphore_available(uint32_t i) const
    //{
        //if(i >= m_frames.size())
            //return nullptr;
        //return m_frames[i].available;
    //}
    
    Expect<RasterPtr>   ViSwapchain::snapshot(uint32_t i, VkFormat desired) const
    {
        if(i >= m_images.size())
            return errors::swapchain_image_out_of_range();
        
        return export_image(m_viz.device(REF), m_images[i], ViImageExport{
            .type       = VK_IMAGE_TYPE_2D,
            .src_layout = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
            .format     = m_viz.surface_format(),
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
        return m_swapchain && m_imageCount;
    }

    uint32_t  ViSwapchain::height() const 
    { 
        return m_extents.height; 
    }
}
