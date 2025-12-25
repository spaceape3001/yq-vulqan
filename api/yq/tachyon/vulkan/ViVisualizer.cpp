////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/vulkan/ViVisualizer.hpp>

#include <yq/color/RGBA.hpp>
#include <yq/container/initlist_utils.hpp>
#include <yq/text/basic.hpp>
#include <yq/text/join.hpp>

#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/app/ViewerCreateInfo.hpp>
#include <yq/tachyon/pipeline/Buffer.hpp>
#include <yq/tachyon/pipeline/Pipeline.hpp>
#include <yq/tachyon/asset/Sampler.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/config/vulqan.hpp>
//#include <yq/tachyon/v/VqEnumerations.hpp>
#include <yq/tachyon/vulkan/VqEnums.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>
#include <yq/tachyon/vulkan/VqUtils.hpp>
#include <yq/tachyon/vulkan/VulqanManager.hpp>
#include <yq/tachyon/vulkan/ViContext.hpp>
#include <yq/tachyon/vulkan/ViDevice.hpp>
#include <yq/tachyon/vulkan/ViGraphicsProcessor.hpp>
#include <yq/tachyon/vulkan/ViManager.hpp>
#include <yq/tachyon/vulkan/ViBuffer.hpp>
#include <yq/tachyon/vulkan/ViImage.hpp>
#include <yq/tachyon/vulkan/ViPipeline.hpp>
#include <yq/tachyon/vulkan/ViPipelineLayout.hpp>
#include <yq/tachyon/vulkan/ViProcessor.hpp>
#include <yq/tachyon/vulkan/ViQueueTasker.hpp>
#include <yq/tachyon/vulkan/ViSampler.hpp>
#include <yq/tachyon/vulkan/ViShader.hpp>
#include <yq/tachyon/vulkan/ViSurface.hpp>
#include <yq/tachyon/vulkan/ViSwapchain.hpp>
#include <yq/tachyon/vulkan/ViTexture.hpp>
#include <yq/tachyon/vulkan/VisualizerCreateData.hpp>

#include <GLFW/glfw3.h>

#include <algorithm>

namespace yq::tachyon {

    ViVisualizer::ViVisualizer(ViDevice& dev, const CreateData& cfg) : 
        VizBase(dev, Param{  // temporary
            .color_clear            = cfg.viewer.clear,
            .compute                = cfg.viewer.compute,
            .depth_buffer           = cfg.viewer.depth_buffer,
            .descriptors            = cfg.viewer.descriptors,
            .graphics               = REQUIRED,
            //.graphics_processors    = std::clamp(cfg.viewer.frames_in_flight, MIN_FRAMES_IN_FLIGHT, MAX_FRAMES_IN_FLIGHT),
            .graphics_qidx          = cfg.number,
            .optical_flow           = cfg.viewer.optical_flow,
            .present                = REQUIRED,
            .present_queue          = cfg.present,
            .surface                = cfg.surface->vk_surface(),
            .transfer               = cfg.viewer.transfer,
            .video_decode           = cfg.viewer.video_decode,
            .video_encode           = cfg.viewer.video_encode
        }), 
        m_surface(cfg.surface)
    {
    
        // must be set before the swapchain is built
        graphics_processor_factory(SET, [this]() -> ViProcessorUPtr {
            return std::make_unique<ViGraphicsProcessor>(*this);
        });


        m_presentMode   = PresentMode::Fifo;
        std::error_code ec  = _init(cfg);
        if(ec != std::error_code()){
            _kill();
            throw ec;
        }
        
    }
    
    ViVisualizer::~ViVisualizer()
    {
        _kill();
    }

    ///////////////////////////////////////////////////////////////////////////
    
    void                ViVisualizer::_rebuild_swapchain()
    {
        ViSwapchainConfig   cfg;
        if(m_swapchain)
            cfg.old_swapchain = m_swapchain -> vk_swapchain();
        
        wait_idle();
        m_swapchain     = new ViSwapchain(*this, cfg);
        m_semaphoreIndex    = 0;
        graphics_processor_expand(m_swapchain->image_count());
        graphics_processor(0) -> execute([&](ViProcessor&p){
            wait_idle();
            VqCommandBufferBeginInfo beginInfo;
            beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT; // Optional
            beginInfo.pInheritanceInfo = nullptr; // Optional

            if (vkBeginCommandBuffer(p.vk_command_buffer(), &beginInfo) != VK_SUCCESS){
                vizWarning << "Failed to begin recording command buffer";
                return ;
            }
            
            for(uint32_t n=0;n<m_swapchain->image_count();++n){
                ViImage* img = m_swapchain->vi_image(DEPTH, n);
                if(img){
                    img -> barrier(p.vk_command_buffer(), VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT, ViImage::Respec{
                        .access     = VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT | VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT,
                        .layout     = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL,
                        .queue      = graphics_queue_family().index
                    });
                }
            }
            
            if (vkEndCommandBuffer(p.vk_command_buffer()) != VK_SUCCESS)
                vizWarning << "Failed to record command buffer";
            
            VkCommandBuffer cmdbuf  = p.vk_command_buffer();
                
            VqSubmitInfo submitInfo;
            submitInfo.commandBufferCount   = 1;
            submitInfo.pCommandBuffers      = &cmdbuf;
            

            if (vkQueueSubmit(graphics_queue(), 1, &submitInfo, nullptr) != VK_SUCCESS) 
                vizWarning << "Failed to submit command buffer";

            wait_idle();
        });
    }

    ///////////////////////////////////////////////////////////////////////////

    std::error_code     ViVisualizer::_init(const CreateData& vcd)
    {
        if(!m_surface || !m_surface->valid())
            return create_error<"null surface">();

        for(auto pm : vqGetPhysicalDeviceSurfacePresentModesKHR(vk_physical_device(), vk_surface()))
            m_presentModes.insert((PresentMode::enum_t) pm);
        m_presentMode           = m_presentModes.contains(vcd.viewer.pmode) ? vcd.viewer.pmode : PresentMode{ PresentMode::Fifo };

        m_surfaceFormats        = vqGetPhysicalDeviceSurfaceFormatsKHR(physical(), surface());
        
        // right now, cheating on format & color space
        m_surfaceFormat         = VK_FORMAT_B8G8R8A8_SRGB;
        m_surfaceColorSpace     = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;

        _rebuild_swapchain();
        return {};
    }
    
    void                ViVisualizer::_kill()
    {
        m_swapchain     = {};
        wait_idle();
    }


    ///////////////////////////////////////////////////////////////////////////
    std::error_code         ViVisualizer::draw2(ViContext& u, const DrawFunctions& fcn, uint64_t maxWait)
    {
        if(u.graphics_processor || u.command_buffer){
            vizAlert << "ViVisualizer::draw2 -- recursion detected!";
            return create_error<"ViVisualizer recursion detected">();
        }
        
        
        if(!m_swapchain){
            vizCritical << "Visualizer::draw ... attempting to draw on a swapchain WITHOUT a swapchain";
            return errors::swapchain_uninitialized();
        }

        VkSemaphore     imgAcquired    = m_swapchain->vk_semaphore(AVAILABLE, m_semaphoreIndex);
        VkSemaphore     renderComplete = m_swapchain->vk_semaphore(RENDERED, m_semaphoreIndex);

        VkResult        res = VK_SUCCESS;
        struct {
            VkFormat    format  = VK_FORMAT_UNDEFINED;
            bool        enable  = false;
        } snapshot;
        if(auto p = std::get_if<bool>(&u.snapshot)){
            snapshot.enable    = *p;
        }
        if(auto p = std::get_if<DataFormat>(&u.snapshot)){
            snapshot.enable = true;
            snapshot.format = (VkFormat) (p->value());
        }
        
        if(snapshot.enable){
            if(VkFence  fence   = m_swapchain->vk_fence(m_frameImageIndex)){
                res = vkWaitForFences(vk_device(), 1, &fence, VK_TRUE, maxWait);   // 100ms is 10Hz
                if(res == VK_TIMEOUT)
                    return create_error<"Fence timeout">();
            }
            auto r = m_swapchain -> snapshot(m_frameImageIndex, snapshot.format);
            if(r){
                u.snapshot  = r.value();
            } else {
                u.snapshot  = r.error();
            }
        }

        bool    rebuildFlag = m_rebuildSwap.exchange(false);
        if(rebuildFlag){
            _rebuild_swapchain();
            return std::error_code();
        }

        res    = vkAcquireNextImageKHR(device(), m_swapchain->vk_swapchain(), maxWait, imgAcquired, VK_NULL_HANDLE, &m_frameImageIndex);

        switch(res){
        case VK_TIMEOUT:
            return create_error<"Acquire image timeout">();
        case VK_ERROR_OUT_OF_DATE_KHR:
        case VK_SUBOPTIMAL_KHR:
            _rebuild_swapchain();
            return std::error_code();
        case VK_SUCCESS:
            break;
        case VK_ERROR_OUT_OF_HOST_MEMORY:
            return create_error<"Out of host memory">();
        case VK_ERROR_OUT_OF_DEVICE_MEMORY:
            return create_error<"Out of device memory">();
        case VK_ERROR_DEVICE_LOST:
            return create_error<"Device lost">();
        case VK_ERROR_SURFACE_LOST_KHR:
            return create_error<"Surface lost">();
        case VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT:
            return create_error<"Full screen exclusive mode lost">();
        default:
            return create_error<"Unexpected error">();
        }

        ViGraphicsProcessor*  gp  = graphics_processor(m_frameImageIndex);
        if(!gp){
            vizAlert << "ViVisualizer.draw(): No graphics processor on image index " << m_frameImageIndex;
            return create_error<"ViVisualizer.draw(): Abnormal situation... no graphics processor">();
        }

        u.graphics_processor    = gp;
        u.command_pool          = gp->vk_command_pool();
        u.command_buffer        = gp->vk_command_buffer();
        u.descriptor_pool       = vk_descriptor_pool();
        
        
        VkFence fence = m_swapchain->vk_fence(m_frameImageIndex);
        res = vkWaitForFences(vk_device(), 1, &fence, VK_TRUE, maxWait);   // 100ms is 10Hz
        if(res == VK_TIMEOUT)
            return create_error<"Fence timeout">();
        vkResetFences(vk_device(), 1, &fence);
        gp->reset();

        std::vector<VkCommandBuffer>    cmdBuffers;
        
        std::error_code ret;
        
            // we may want to bring "prep" outside ... or parallelize...?
        if(fcn.prerecord){
            gp -> execute([&](ViProcessor&) -> void {
                fcn.prerecord(u);
            });
        }
        if(fcn.record){
            gp -> execute([&](ViProcessor&){
                cmdBuffers.push_back(u.command_buffer);

                VqCommandBufferBeginInfo beginInfo;
                beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT; // Optional
                beginInfo.pInheritanceInfo = nullptr; // Optional

                if (vkBeginCommandBuffer(u.command_buffer, &beginInfo) != VK_SUCCESS){
                    ret = create_error<"Failed to begin recording command buffer">();
                    return ;
                }
                

                VqImageMemoryBarrier imb;
     
                //  AND.... moving to a new image layout
                imb.oldLayout           = VK_IMAGE_LAYOUT_UNDEFINED;
                imb.newLayout           = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
                imb.image               = m_swapchain->vk_image(m_frameImageIndex);
                imb.subresourceRange    = VkImageSubresourceRange{ 
                    .aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT,
                    .baseMipLevel   = 0,
                    .levelCount     = 1,
                    .baseArrayLayer = 0,
                    .layerCount     = 1
                };
                imb.srcAccessMask       = VK_ACCESS_NONE;
                imb.dstAccessMask       = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
            
                vkCmdPipelineBarrier(u.command_buffer, VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, 0, 0, nullptr, 0, nullptr, 1, &imb);
                
                
                VqRenderingInfo             renderingInfo;
                VqRenderingAttachmentInfo  colorAttachment;
                VqRenderingAttachmentInfo  depthAttachment;
                VqRenderingAttachmentInfo  stencilAttachment;

                renderingInfo.renderArea.offset = {0, 0};
                renderingInfo.renderArea.extent = m_swapchain->extents();
                renderingInfo.layerCount    = 1;
                
                {
                    colorAttachment.imageView       = m_swapchain->vk_image_view(m_frameImageIndex);
                    colorAttachment.imageLayout     = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

                    //colorAttachment.resolveMode           = VK_RESOLVE_MODE_NONE;
                    //colorAttachment.resolveImageView      = 
                    //colorAttachment.resolveImageLayout    = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL; ???
                    
                    colorAttachment.loadOp      = VK_ATTACHMENT_LOAD_OP_CLEAR;
                    colorAttachment.storeOp     = VK_ATTACHMENT_STORE_OP_STORE;
                    colorAttachment.clearValue  = (u.clear.alpha >= 0) ? vqClearValue(u.clear) : color_clear_vk();
                }
                
                renderingInfo.colorAttachmentCount  = 1;
                renderingInfo.pColorAttachments     = &colorAttachment;
                
                if(depth_enabled()){
                    renderingInfo.pDepthAttachment  = &depthAttachment;
                    depthAttachment.imageView       = m_swapchain->vk_image_view(DEPTH, m_frameImageIndex);
                    depthAttachment.imageLayout     = VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL;
                    depthAttachment.loadOp          = VK_ATTACHMENT_LOAD_OP_CLEAR;
                    depthAttachment.storeOp         = VK_ATTACHMENT_STORE_OP_DONT_CARE;
                    depthAttachment.clearValue      = depth_clear_vk();
                    depthAttachment.resolveMode     = VK_RESOLVE_MODE_NONE; 
                }
                
                if(false){
                    // something stencil related....
                }

                VkViewport  viewport = m_swapchain->def_viewport();
                
                VkRect2D  scissors    = m_swapchain->def_scissor();
                vkCmdBeginRendering(u.command_buffer, &renderingInfo);
                vkCmdSetViewport(u.command_buffer, 0, 1, &viewport);
                vkCmdSetScissor(u.command_buffer, 0, 1, &scissors);
                

                #ifdef NDEBUG
                try {
                #endif
                
                    fcn.record(u);
                
                #ifdef NDEBUG
                } catch(std::error_code ec){
                    ret = ec;
                }
                #endif

                vkCmdEndRendering(u.command_buffer);
                
                //  AND.... moving to a new image layout
                imb.oldLayout           = VK_IMAGE_LAYOUT_UNDEFINED;
                imb.newLayout           = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;
                imb.image               = m_swapchain->vk_image(m_frameImageIndex);
                imb.subresourceRange    = VkImageSubresourceRange{ 
                    .aspectMask     = VK_IMAGE_ASPECT_COLOR_BIT,
                    .baseMipLevel   = 0,
                    .levelCount     = 1,
                    .baseArrayLayer = 0,
                    .layerCount     = 1
                };
                imb.srcAccessMask       = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
                imb.dstAccessMask       = VK_ACCESS_NONE;
            
                vkCmdPipelineBarrier(u.command_buffer, VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT, VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT, 0, 0, nullptr, 0, nullptr, 1, &imb);
                
                if (vkEndCommandBuffer(u.command_buffer) != VK_SUCCESS)
                    ret = create_error<"Failed to record command buffer">();
            });
        }

        u.command_buffer        = nullptr;
        u.command_pool          = nullptr;
        u.graphics_processor    = nullptr;
        u.descriptor_pool       = nullptr;
        
        VqSubmitInfo submitInfo;

        VkPipelineStageFlags waitStages[] = {VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT};
        submitInfo.waitSemaphoreCount   = 1;
        submitInfo.pWaitSemaphores      = &imgAcquired;
        submitInfo.pWaitDstStageMask    = waitStages;
        submitInfo.commandBufferCount   = (uint32_t) cmdBuffers.size();;
        submitInfo.pCommandBuffers      = cmdBuffers.data();

        submitInfo.signalSemaphoreCount = 1;
        submitInfo.pSignalSemaphores    = &renderComplete;

        if (vkQueueSubmit(graphics_queue(), 1, &submitInfo, fence) != VK_SUCCESS) 
            return create_error<"Failed to submit draw command buffer">();
            
        VqPresentInfoKHR presentInfo;

        VkSwapchainKHR      swapchains[] = { m_swapchain -> vk_swapchain() };
        presentInfo.waitSemaphoreCount = 1;
        presentInfo.pWaitSemaphores = &renderComplete;
        presentInfo.swapchainCount = 1;
        presentInfo.pSwapchains = swapchains;
        presentInfo.pImageIndices = &m_frameImageIndex;
        presentInfo.pResults = nullptr; // Optional
        res = vkQueuePresentKHR(present_queue(), &presentInfo);
        if(res != VK_SUCCESS){
            vizError << "VkQueuePreset returned " << (int) res;
        }
        
        ++m_tick;
        if(++m_semaphoreIndex > m_swapchain->image_count())
            m_semaphoreIndex    = 0;
        
        
        return ret;
    }

    ViGraphicsProcessor*    ViVisualizer::graphics_processor(uint32_t n) 
    {
        return dynamic_cast<ViGraphicsProcessor*>(VizBase::graphics_processor(n));
    }

    
    PresentMode  ViVisualizer::present_mode() const
    {
        return m_presentMode;
    }

    const std::set<PresentMode>&    ViVisualizer::present_modes_available() const
    {
        return m_presentModes;
    }
    
    void        ViVisualizer::set_framebuffer_size(const Size2I&sz)
    {
        if(sz != m_frameBufferSize){
            m_frameBufferSize   = sz;
            m_rebuildSwap       = true;
        }
    }

    void        ViVisualizer::set_present_mode(PresentMode pm)
    {
        if((pm != m_presentMode) && supports_present(pm)){
            m_presentMode   = pm;
            m_rebuildSwap   = true;
        }
    }

    bool        ViVisualizer::supports_surface(VkFormat fmt) const
    {
        for(auto f : m_surfaceFormats)
            if(fmt == f.format)
                return true;
        return false;
    }
    
    bool        ViVisualizer::supports_present(PresentMode pm) const
    {
        return m_presentModes.contains(pm);
    }


    VkSurfaceCapabilitiesKHR_x  ViVisualizer::surface_capabilities() const
    {
        VkSurfaceCapabilitiesKHR    ret;
        if(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(vk_physical_device(), vk_surface(), &ret) != VK_SUCCESS)
            return unexpected<"Unable to get surface capabilities">();
        return ret;
    }

    VkColorSpaceKHR  ViVisualizer::surface_color_space() const 
    { 
        return m_surfaceColorSpace; 
    }

    VkColorSpaceKHR ViVisualizer::surface_color_space(VkFormat fmt) const
    {
        for(auto& f : m_surfaceFormats)
            if(fmt == f.format)
                return f.colorSpace;
        return VK_COLOR_SPACE_MAX_ENUM_KHR;
    }
    
    VkFormat    ViVisualizer::surface_format() const 
    { 
        return m_surfaceFormat; 
    }

    VkRect2D    ViVisualizer::swapchain_def_scissor() const
    {
        if(!m_swapchain)
            return {};
        return m_swapchain->def_scissor();
    }
    
    VkViewport  ViVisualizer::swapchain_def_viewport() const
    {
        if(!m_swapchain)
            return {};
        return m_swapchain->def_viewport();
    }

    uint32_t    ViVisualizer::swapchain_image_count() const
    {
        if(!m_swapchain)
            return 0;
        return m_swapchain->image_count();
    }

    uint32_t    ViVisualizer::swapchain_height() const
    {
        if(!m_swapchain)
            return 0;
        return m_swapchain->height();
    }

    uint32_t    ViVisualizer::swapchain_min_image_count() const
    {
        if(!m_swapchain)
            return 0;
        return m_swapchain->min_image_count();
    }

    uint32_t    ViVisualizer::swapchain_width() const
    {
        if(!m_swapchain)
            return 0;
        return m_swapchain->width();
    }

    void    ViVisualizer::trigger_rebuild()
    {
        m_rebuildSwap       = true;
    }


    VkSurfaceKHR      ViVisualizer::vk_surface() const 
    { 
        if(m_surface)
            return m_surface -> vk_surface();
        return nullptr;
    }

    VkSwapchainKHR  ViVisualizer::vk_swapchain() const
    {
        if(!m_swapchain)
            return nullptr;
        return m_swapchain->vk_swapchain();
    }
}
