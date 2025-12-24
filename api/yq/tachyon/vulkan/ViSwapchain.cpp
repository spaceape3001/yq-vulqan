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

    struct ViSwapchain::Frame {
        VkImage             image       = nullptr;
        VkImageView         imageview   = nullptr;
        VkFramebuffer       framebuffer = nullptr;
        //VkSemaphore         available   = nullptr;
    };

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
        } else {
            Size2I fb  = viz.framebuffer_size();
            m_extents = {};
            m_extents.width  = std::clamp((uint32_t) fb.x, m_capabilities.minImageExtent.width, m_capabilities.maxImageExtent.width);
            m_extents.height = std::clamp((uint32_t) fb.y, m_capabilities.minImageExtent.height, m_capabilities.maxImageExtent.height);
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
        
        uint32_t queueFamilyIndices[] = {viz.graphics_queue_family().index, viz.present_queue_family().index};
        if (viz.graphics_queue_family() != viz.present_queue_family()) {
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
        
        std::vector<VkImage> images(m_imageCount, nullptr);
        
        res = vkGetSwapchainImagesKHR(viz.device(), m_swapchain, &m_imageCount, images.data());
        if(res != VK_SUCCESS){
            vizWarning << "ViSwapchain(): Cannot get images.  VkResult " << (int32_t) res;
            return errors::swapchain_cant_create();
        }
        
        VkRenderPass        rp  = cfg.render_pass ? cfg.render_pass : viz.render_pass();
        m_frames.resize(m_imageCount);
        for(size_t i=0;i<m_imageCount;++i){
            std::error_code ec  = _init(m_frames[i], images[i], rp);
            if(ec != std::error_code())
                return ec;
        }
        
        return {};
    }

    std::error_code ViSwapchain::_init(Frame& f, VkImage img, VkRenderPass vr)
    {   
        VkImageViewCreateInfo   imageViewInfo = vqCreateInfo(ImageViewInfo());
        imageViewInfo.format    = m_viz->surface_format();
        imageViewInfo.image     = img;
        f.image = img;

        int res = vkCreateImageView(m_viz->device(), &imageViewInfo, nullptr, &f.imageview);
        if(res != VK_SUCCESS){
            vizWarning << "ViSwapchain(): Cannot create a swapchain image viewer.  VkResult " << (int32_t) res;
            return errors::swapchain_cant_create();
        }
        
        VqFramebufferCreateInfo   frameBufferInfo;
        frameBufferInfo.renderPass      = vr;
        frameBufferInfo.attachmentCount = 1;
        frameBufferInfo.width           = m_extents.width;
        frameBufferInfo.height          = m_extents.height;
        frameBufferInfo.layers          = 1;
        frameBufferInfo.pAttachments    = &f.imageview;

        res = vkCreateFramebuffer(m_viz->device(), &frameBufferInfo, nullptr, &f.framebuffer);
        if (res != VK_SUCCESS){
            vizWarning << "ViSwapchain(): Cannot create a swapchain framebuffer.  VkResult " << (int32_t) res;
            return errors::swapchain_cant_create();
        }
        
        //VqSemaphoreCreateInfo   sci;
        //vkCreateSemaphore(m_viz->device(), &sci, nullptr, &f.available);
        return {};
    }

    void            ViSwapchain::_kill(Frame&f)
    {
        if(f.framebuffer){
            vkDestroyFramebuffer(m_viz->device(), f.framebuffer, nullptr);
            f.framebuffer   = nullptr;
        }
        if(f.imageview){
            vkDestroyImageView(m_viz->device(), f.imageview, nullptr);
            f.imageview     = nullptr;
        }
        //if(f.available){
            //vkDestroySemaphore(m_viz->device(), f.available, nullptr);
            //f.available     = nullptr;
        //}
    }
    
    void            ViSwapchain::_kill()
    {
        if(m_viz && m_viz->device()){
            for(auto& f : m_frames){
                _kill(f);
            }
        }
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
        if(i>=m_frames.size())
            return nullptr;
        return m_frames[i].framebuffer;
    }
    
    uint32_t  ViSwapchain::width() const 
    { 
        return m_extents.width; 
    }

    VkImage         ViSwapchain::image(uint32_t i) const
    {
        if(i>=m_frames.size())
            return nullptr;
        return m_frames[i].image;
    }
    
    VkImageView     ViSwapchain::image_view(uint32_t i) const
    {
        if(i>=m_frames.size())
            return nullptr;
        return m_frames[i].imageview;
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

    //VkSemaphore         ViSwapchain::semaphore_available(uint32_t i) const
    //{
        //if(i >= m_frames.size())
            //return nullptr;
        //return m_frames[i].available;
    //}
    
    Expect<RasterPtr>   ViSwapchain::snapshot(uint32_t i, VkFormat desired) const
    {
        if(i >= m_frames.size())
            return errors::swapchain_image_out_of_range();
        
        return export_image(m_viz->device(REF), m_frames[i].image, ViImageExport{
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
