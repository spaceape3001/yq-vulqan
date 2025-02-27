////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yv/ViVisualizer.hpp>

#include <yq/color/RGBA.hpp>
#include <yq/container/initlist_utils.hpp>
#include <yq/text/basic.hpp>
#include <yq/text/join.hpp>

#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <yt/gfx/Raster.hpp>
#include <yt/app/ViewerCreateInfo.hpp>
#include <yt/gfx/Buffer.hpp>
#include <yt/gfx/Pipeline.hpp>
#include <yt/gfx/Sampler.hpp>
#include <yt/gfx/Shader.hpp>
#include <yt/gfx/Texture.hpp>
//#include <yq/tachyon/v/VqEnumerations.hpp>
#include <yv/VqEnums.hpp>
#include <yv/VqStructs.hpp>
#include <yv/VqUtils.hpp>
#include <yv/VulqanManager.hpp>
#include <yv/ViManager.hpp>
#include <yv/ViBuffer.hpp>
#include <yv/ViImage.hpp>
#include <yv/ViPipeline.hpp>
#include <yv/ViPipelineLayout.hpp>
#include <yv/ViQueueManager.hpp>
#include <yv/ViQueueTasker.hpp>
#include <yv/ViRenderPass.hpp>
#include <yv/ViSampler.hpp>
#include <yv/ViShader.hpp>
#include <yv/ViSwapchain.hpp>
#include <yv/ViTexture.hpp>

#include <GLFW/glfw3.h>

namespace yq::tachyon {
    ViVisualizer::ViVisualizer(Cleanup& clean) : m_cleanup(clean)
    {
        m_presentMode   = PresentMode::Fifo;
    }
    
    ViVisualizer::~ViVisualizer()
    {
    }

    ///////////////////////////////////////////////////////////////////////////

    std::error_code  ViVisualizer::_0_app_window_initialize(GLFWwindow* w)
    {
        m_instance    = VulqanManager::instance();
        if(!m_instance)
            return errors::vulkan_uninitialized();

        m_window    = w;
        if(!w)
            return errors::vulkan_no_window_provided();
     
        glfwGetFramebufferSize(w, &m_frameBufferSize.x, &m_frameBufferSize.y);
        return {};
    }
    
    void             ViVisualizer::_0_app_window_kill()
    {
        m_instance      = nullptr;
        m_window        = nullptr;
    }

    std::error_code  ViVisualizer::_1_gpu_select_initialize(InitData& iData)
    {
        m_physical                    = iData.viewer.device;
        if(!m_physical){
            m_physical  = vqFirstDevice();
            if(!m_physical)
                return errors::vulkan_no_physical_device();
        }

        VqPhysicalDeviceProperties2         prop2;
        VqPhysicalDeviceMultiviewProperties multiProp;
        
        vkGetPhysicalDeviceFeatures(m_physical, &m_deviceFeatures);
        vkGetPhysicalDeviceMemoryProperties(m_physical, &m_memoryInfo);

        if(iData.viewer.multiview){
            m_multiview.enabled  = true;
            prop2.pNext     = &multiProp;
            vizDebug << "ViVisualizer: Multiview enabled";
        }

        vkGetPhysicalDeviceProperties2(m_physical, &prop2);
        m_deviceInfo    = prop2.properties;
        if(iData.viewer.multiview){
            m_multiview.maxViewCount        = multiProp.maxMultiviewViewCount;
            m_multiview.maxInstanceIndex    = multiProp.maxMultiviewInstanceIndex;

            //vizDebug << "ViVisualizer: Multiview max view count is " << m_multiview.maxViewCount;
            //vizDebug << "ViVisualizer: Multiview max instance count is " << m_multiview.maxInstanceIndex;
        }

        vizDebug << "ViVisualizer: Using GPU/physical device " << gpu_name();

        return {};
    }
    
    void             ViVisualizer::_1_gpu_select_kill()
    {
        m_physical  = nullptr;
        vizDebug << "ViVisualizer: GPU forgotten";
    }

    std::error_code  ViVisualizer::_2_surface_initialize(InitData& iData)
    {
        //  passing in the create info in case we get smarter
        if(glfwCreateWindowSurface(m_instance, m_window, nullptr, &m_surface) != VK_SUCCESS)
            return errors::vulkan_no_window_surface();
            
        for(auto pm : vqGetPhysicalDeviceSurfacePresentModesKHR(m_physical, m_surface))
            m_presentModes.insert((PresentMode::enum_t) pm);
        m_presentMode           = m_presentModes.contains(iData.viewer.pmode) ? iData.viewer.pmode : PresentMode{ PresentMode::Fifo };

        m_surfaceFormats        = vqGetPhysicalDeviceSurfaceFormatsKHR(m_physical, m_surface);
        
        // right now, cheating on format & color space
        m_surfaceFormat         = VK_FORMAT_B8G8R8A8_SRGB;
        m_surfaceColorSpace     = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;

        set_clear_color(iData.viewer.clear);
        
        vizDebug << "ViVisualizer: Presenting " << ((PresentMode) m_presentMode).key() << " on " 
            << to_string_view(m_surfaceFormat);
        
        return  {};
    }
    
    void             ViVisualizer::_2_surface_kill()
    {
        if(m_surface){
            vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
            m_surface               = nullptr;
        }
        vizDebug << "ViVisualizer: Surface destroyed";
    }

    std::error_code  ViVisualizer::_3_queues_create(InitData& iData)
    {
        ViQueueTypeFlags    wantQueue({ViQueueType::Graphic, ViQueueType::Present});
        ViQueueTypeFlags    hasQueue{};

        if(!is_empty(iData.viewer.compute))
            wantQueue.set(ViQueueType::Compute);
        if(!is_empty(iData.viewer.video_decode))
            wantQueue.set(ViQueueType::VideoDecode);
        if(!is_empty(iData.viewer.video_encode))
            wantQueue.set(ViQueueType::VideoEncode);
        if(!is_empty(iData.viewer.transfer))
            wantQueue.set(ViQueueType::Transfer);
        
        std::vector<VkQueueFamilyProperties> qfp = vqGetPhysicalDeviceQueueFamilyProperties(m_physical);
        for(uint32_t i=0;i<qfp.size();++i){
            if(wantQueue == hasQueue)
                break;
            ViQueueManagerPtr   r   = new ViQueueManager(*this, iData.viewer, i, qfp[i], wantQueue & ~hasQueue );
            hasQueue |= r->types();
            if(r->types().is_set(ViQueueType::Graphic)){
                vizInfo << "Discovered graphics queue " << i;
                m_graphicsQueue       = r.ptr();
            }
            if(r->types().is_set(ViQueueType::Compute)){
                vizInfo << "Discovered compute queue " << i;
                m_computeQueue       = r.ptr();
            }
            if(r->types().is_set(ViQueueType::VideoEncode)){
                vizInfo << "Discovered video encode queue " << i;
                m_videoEncQueue   = r.ptr();
            }
            if(r->types().is_set(ViQueueType::VideoDecode)){
                vizInfo << "Discovered video decode queue " << i;
                m_videoDecQueue   = r.ptr();
            }
            if(r->types().is_set(ViQueueType::Present)){
                vizInfo << "Discovered present queue " << i;
                m_presentQueue       = r.ptr();
            }
            if(r->types() == ViQueueTypeFlags(ViQueueType::Transfer)){
                vizInfo << "Discovered transfer queue " << i;
                m_transferQueue      = r.ptr();
            }
            iData.queues.push_back(r->info());
            m_queues.push_back(r);
        }
        
        if(!m_graphicsQueue)
            return errors::graphics_queue_not_found();
        if(!m_presentQueue)
            return errors::present_queue_not_found();
        if(wantQueue.is_set(ViQueueType::Compute) && !m_computeQueue){
            if(is_required(iData.viewer.compute)){
                return errors::compute_queue_not_found();
            } else {
                vizNotice << "Compute queue requested, but not found.";
            }
        }
        if(wantQueue.is_set(ViQueueType::VideoEncode) && !m_videoEncQueue){
            if(is_required(iData.viewer.video_encode)){
                return errors::video_encode_queue_not_found();
            } else {
                vizNotice << "Video encoding queue requested, but not found.";
            }
        }
        if(wantQueue.is_set(ViQueueType::VideoDecode) && !m_videoDecQueue){
            if(is_required(iData.viewer.video_decode)){
                return errors::video_decode_queue_not_found();
            } else {
                vizNotice << "Video decoding queue requested, but not found.";
            }
        }
        if(wantQueue.is_set(ViQueueType::Transfer) && !m_transferQueue){
            if(is_required(iData.viewer.transfer)){
                return errors::transfer_queue_not_found();
            } else {
                vizNotice << "Transfer-only queue requested, but not found (will be using the graphics queue instead).";
            }
        }
        if(!m_transferQueue)
            m_transferQueue  = m_graphicsQueue;
            
        std::set<uint32_t>  families;
        for(auto& r : m_queues){
            families.insert(r->family());
        }
            
        vizDebug << "ViVisualizer: Created the queue managers on queues... " << join(families, " ");
        return {};
    }
    
    void  ViVisualizer::_3_queues_fetch()
    {
        for(auto& r : m_queues){
            try {
                r->init();
            }
            catch(const std::error_code&)
            {
                //  Shouldn't ever get here
            }
        }
        
        vizDebug << "ViVisualizer: Extracted queues from device";
    }
    
    void   ViVisualizer::_3_queues_kill()
    {
        m_graphicsQueue  = nullptr;
        m_presentQueue   = nullptr;
        m_computeQueue   = nullptr;
        m_transferQueue  = nullptr;
        m_videoEncQueue  = nullptr;
        m_videoDecQueue  = nullptr;
        m_queues.clear();
        
        vizDebug << "ViVisualizer: Killed the queue managers";
    }

    std::error_code     ViVisualizer::_4_device_init(InitData& iData)
    {
        VkPhysicalDeviceFeatures    gpu_features{};
        if(iData.viewer.fill_non_solid)
            gpu_features.fillModeNonSolid       = VK_TRUE;
        gpu_features.samplerAnisotropy          = VK_TRUE;

        VqDeviceCreateInfo          deviceCreateInfo;
        deviceCreateInfo.pQueueCreateInfos        = iData.queues.data();
        deviceCreateInfo.queueCreateInfoCount     = (uint32_t) iData.queues.size();
        deviceCreateInfo.pEnabledFeatures         = &gpu_features;
        
        deviceCreateInfo.enabledExtensionCount      = (uint32_t) iData.extensions.size();
        deviceCreateInfo.ppEnabledExtensionNames    = iData.extensions.data();
        
        VqPhysicalDeviceVulkan12Features            v12features;
        v12features.bufferDeviceAddress = true;
        deviceCreateInfo.pNext          = &v12features;
        
        VkResult        res = vkCreateDevice(m_physical, &deviceCreateInfo, nullptr, &m_device);
        if(res != VK_SUCCESS){
            vqError << "Unable to create vulkan (logical) device with result code: " << (int32_t) res;
            return errors::vulkan_device_cant_create();
        }
        
        vizDebug << "ViVisualizer: Created the logical device";
        return {};
    }
    
    void                ViVisualizer::_4_device_kill()
    {
        if(m_device){
            vkDestroyDevice(m_device, nullptr);
            m_device                = nullptr;
        }
        vizDebug << "ViVisualizer: Destroyed the logical device";
    }
    
    std::error_code     ViVisualizer::_5_allocator_init(InitData& iData)
    {
        VmaAllocatorCreateInfo      allocatorCreateInfo{};
        allocatorCreateInfo.instance                        = m_instance;
        allocatorCreateInfo.physicalDevice                  = m_physical;
        allocatorCreateInfo.device                          = m_device;
        allocatorCreateInfo.vulkanApiVersion                = VulqanManager::vulkan_api();
        allocatorCreateInfo.preferredLargeHeapBlockSize     = (VkDeviceSize) iData.viewer.chunk_size;
        vmaCreateAllocator(&allocatorCreateInfo, &m_allocator);
        
        vizDebug << "ViVisualizer: Created the allocator";
        return {};
    }
    
    void                ViVisualizer::_5_allocator_kill()
    {
        if(m_allocator){
            vmaDestroyAllocator(m_allocator);
            m_allocator = nullptr;
        }
        
        vizDebug << "ViVisualizer: Destroyed the allocator";
    }
    
    std::error_code     ViVisualizer::_6_manager_init()
    {
        m_shaders           = std::make_unique<ViShaderManager>(*this);
        m_buffers           = std::make_unique<ViBufferManager>(*this);
        m_images            = std::make_unique<ViImageManager>(*this);
        m_samplers          = std::make_unique<ViSamplerManager>(*this);
        m_textures          = std::make_unique<ViTextureManager>(*this);
        m_pipelineLayouts   = std::make_unique<ViPipelineLayoutManager>(*this);
        
        vizDebug << "ViVisualizer: Created the managers";
        return {};
    }
    
    void                ViVisualizer::_6_manager_kill()
    {
        m_pipelineLayouts   = {};
        m_textures          = {};
        m_samplers          = {};
        m_queues            = {};
        m_shaders           = {};
        m_buffers           = {};
        m_images            = {};
        
        vizDebug << "ViVisualizer: Destroyed the managers";
    }

    std::error_code     ViVisualizer::_7_render_pass_create()
    {
        ViRenderPassPtr     rp  = new ViRenderPass;
        std::error_code ec  = rp -> init(*this, m_surfaceFormat);
        if(ec != std::error_code())
            return ec;
        m_renderPass    = (ViRenderPassCPtr) rp;
        vizDebug << "ViVisualizer: Created the render pass";
        return {};
    }
    
    void               ViVisualizer::_7_render_pass_kill()
    {
        m_renderPass    = nullptr;
        vizDebug << "ViVisualizer: Destroyed the render pass";
    }

    std::error_code    ViVisualizer:: _8_swapchain_create()
    {
        ViSwapchainPtr      sp = new ViSwapchain;
        std::error_code ec = sp->init(*this);
        if(ec != std::error_code())
            return ec;
        m_swapchain     = (ViSwapchainCPtr) sp;
        vizDebug << "ViVisualizer: Created the swapchain";
        return {};
    }
    
    void                ViVisualizer::_8_swapchain_kill()
    {
        m_swapchain     = nullptr;
        vizDebug << "ViVisualizer: Destroyed the swapchain";
    }

    std::error_code     ViVisualizer::_9_pipeline_manager_create()
    {
        ViPipelineOptions   opts{
            .swapchain  = m_swapchain
        };
        m_pipelines     = std::make_unique<ViPipelineManager>(*this, opts);
        vizDebug << "ViVisualizer: Created the pipeline manager";
        return {};
    }
    
    void                ViVisualizer::_9_pipeline_manager_kill()
    {
        m_pipelines     = {};
        vizDebug << "ViVisualizer: Destroyed the pipeline manager";
    }

    void                ViVisualizer::_rebuild_swapchain()
    {
        ViSwapchainConfig   cfg;
        if(m_swapchain)
            cfg.old_swapchain = m_swapchain -> swapchain();
        ViSwapchainPtr  p   = new ViSwapchain;

        vkDeviceWaitIdle(m_device);
        
        std::error_code ec  = p -> init(*this, cfg);
        if(ec != std::error_code()){
            vizWarning << "ViVisualizer unable to initialize new swapchain!  " << ec.message();
            return ;
        }
        m_swapchain     = ViSwapchainCPtr(p);
        vizDebug << "ViVisualizer: Rebuilt the swapchain";
    }

    ///////////////////////////////////////////////////////////////////////////

    ViBufferCPtr ViVisualizer::buffer(uint64_t i) const
    {
        if(!m_buffers)
            return {};
        return m_buffers->get(i);
    }

    ViBufferCPtr  ViVisualizer::buffer_create(const Buffer& buf)
    {
        if(!m_buffers)
            return {};
        return m_buffers->create(buf);
    }
    
    void  ViVisualizer::buffer_erase(uint64_t i)
    {
        if(m_buffers){
            m_buffers -> erase(i);
        }
    }
    
    void  ViVisualizer::buffer_erase(const Buffer& buf)
    {
        buffer_erase(buf.id());
    }

    ViBufferManager* ViVisualizer::buffer_manager() const 
    { 
        return m_buffers.get(); 
    }

    void              ViVisualizer::cleanup(cleanup_fn&& fn)
    {
        m_cleanup.add(std::move(fn));
    }

    Cleanup&          ViVisualizer::cleanup_manager() const
    {
        return *const_cast<Cleanup*>(&m_cleanup);
    }

    void   ViVisualizer::cleanup_sweep()
    {
        m_cleanup.sweep();
    }

    RGBA4F ViVisualizer::clear_color() const
    {
        VkClearValue    cv = m_clearValue;
        return vqExtractRGBA4F(cv);
    }

    VkQueue  ViVisualizer::compute_queue(uint32_t i) const
    {
        return m_computeQueue ? m_computeQueue->queue(i) : nullptr;
    }
    
    uint32_t  ViVisualizer::compute_queue_count() const
    {
        return m_computeQueue ? m_computeQueue->count() : 0;
    }
    
    uint32_t  ViVisualizer::compute_queue_family() const
    {
        return m_computeQueue ? m_computeQueue->family() : UINT32_MAX;
    }

    ViQueueManager* ViVisualizer::compute_queue_manager() const 
    { 
        return m_computeQueue; 
    }

    std::error_code ViVisualizer::compute_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_computeQueue)
            return errors::compute_queue_uninitialized();

        ViQueueTaskerPtr     tasker  = m_computeQueue->tasker(opts.queue);
        if(!tasker)
            return errors::tasker_uninitialized();
        return tasker->execute(opts.timeout, std::move(fn));
    }

    bool    ViVisualizer::compute_queue_valid() const
    {
        return m_computeQueue != nullptr;
    }


    Expect<VkFormat>    ViVisualizer::find_depth_format() const
    {
        return find_supported_format(
            {VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT}, 
            VK_IMAGE_TILING_OPTIMAL,
            VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT
        );
    }

    Expect<VkFormat>    ViVisualizer::find_supported_format(std::initializer_list<VkFormat> candidates, VkImageTiling tiling, VkFormatFeatureFlags features) const
    {
        return find_supported_format(span(candidates), tiling, features);
    }
    
    Expect<VkFormat>    ViVisualizer::find_supported_format(std::span<const VkFormat> candidates, VkImageTiling tiling, VkFormatFeatureFlags features) const
    {
        for(VkFormat format : candidates){
            VkFormatProperties props;
            vkGetPhysicalDeviceFormatProperties(m_physical, format, &props);
            
            switch(tiling){
            case VK_IMAGE_TILING_LINEAR:
                if((props.linearTilingFeatures & features) == features)
                    return format;
                break;
            case VK_IMAGE_TILING_OPTIMAL:
                if((props.optimalTilingFeatures & features) == features)
                    return format;
                break;
            default:
                break;
            }            
        }
        
        return errors::format_unsupported();
    }

    std::string_view    ViVisualizer::gpu_name() const
    {
        return std::string_view(m_deviceInfo.deviceName, strnlen(m_deviceInfo.deviceName, VK_MAX_PHYSICAL_DEVICE_NAME_SIZE));
    }

    VkPhysicalDeviceType    ViVisualizer::gpu_type() const
    {
        return m_deviceInfo.deviceType;
    }


    VkQueue     ViVisualizer::graphic_queue(uint32_t i) const
    {
        return m_graphicsQueue ? m_graphicsQueue->queue(i) : nullptr;
    }
    
    uint32_t    ViVisualizer::graphic_queue_count() const
    {
        return m_graphicsQueue ? m_graphicsQueue->count() : 0;
    }
    
    uint32_t    ViVisualizer::graphic_queue_family() const
    {
        return m_graphicsQueue ? m_graphicsQueue->family() : UINT32_MAX;
    }
    
    ViQueueManager* ViVisualizer::graphic_queue_manager() const 
    { 
        return m_graphicsQueue; 
    }

    bool        ViVisualizer::graphic_queue_valid() const
    {
        return m_graphicsQueue != nullptr;
    }

    std::error_code ViVisualizer::graphic_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_graphicsQueue)
            return errors::graphics_queue_uninitialized();

        ViQueueTaskerPtr     tasker  = m_graphicsQueue->tasker(opts.queue);
        if(!tasker)
            return errors::tasker_uninitialized();
        return tasker->execute(opts.timeout, std::move(fn));
    }

    ViImageCPtr     ViVisualizer::image(uint64_t i) const
    {
        if(!m_images)
            return {};
        return m_images -> get(i);
    }
    
    ViImageCPtr     ViVisualizer::image_create(const Raster& img)
    {
        if(!m_images)
            return {};
        return m_images -> create(img);
    }
    
    void  ViVisualizer::image_erase(uint64_t i)
    {
        if(m_images){
            m_images -> erase(i);
        }
    }
    
    void  ViVisualizer::image_erase(const Raster& img)
    {
        image_erase(img.id());
    }

    Expect<RasterPtr>       ViVisualizer::image_export(VkImage img, const VkExtent2D&size, VkFormat fmt)
    {
        return export_image(*this, img, ViImageExport{
            .type       = VK_IMAGE_TYPE_2D,
            .format     = fmt,
            .extent     = VkExtent3D{
                .width  = size.width,
                .height = size.height,
                .depth  = 1
            }
        });
    }
    
    Expect<RasterPtr>       ViVisualizer::image_export(VkImage img, const VkExtent3D&size, VkFormat fmt)
    {
        return export_image(*this, img, ViImageExport{
            .type       = VK_IMAGE_TYPE_3D,
            .format     = fmt,
            .extent     = size
        });
    }

    ViImageManager* ViVisualizer::image_manager() const
    {
        return m_images.get();
    }

    uint32_t    ViVisualizer::max_memory_allocation_count() const  
    { 
        return m_deviceInfo.limits.maxMemoryAllocationCount; 
    }
    
    uint32_t    ViVisualizer::max_push_constants_size() const 
    { 
        return m_deviceInfo.limits.maxPushConstantsSize; 
    }

    float       ViVisualizer::max_sampler_anisotropy() const
    {
        return m_deviceInfo.limits.maxSamplerAnisotropy;
    }
    
    uint32_t    ViVisualizer::max_viewports() const 
    { 
        return m_deviceInfo.limits.maxViewports; 
    }

    bool         ViVisualizer::multiview_enabled() const
    {
        return m_multiview.enabled;
    }
    
    uint32_t     ViVisualizer::multiview_max_instance_index() const
    {
        return m_multiview.maxInstanceIndex;
    }

    uint32_t     ViVisualizer::multiview_max_view_count() const
    {
        return m_multiview.maxViewCount;
    }

    ViPipelineCPtr                  ViVisualizer::pipeline(uint64_t i) const
    {
        if(!m_pipelines)
            return {};
        return m_pipelines -> get(i);
    }
    
    ViPipelineCPtr                  ViVisualizer::pipeline_create(const Pipeline* pipe)
    {
        if(!m_pipelines)
            return {};
        if(!pipe)
            return {};
        return m_pipelines -> create(pipe);
    }
    
    void                            ViVisualizer::pipeline_erase(uint64_t i)
    {
        if(m_pipelines)
            m_pipelines -> erase(i);
    }
    
    void                            ViVisualizer::pipeline_erase(const Pipeline* p)
    {
        if(p){
            pipeline_erase(p->id());
        }
    }
    
    ViPipelineManager*              ViVisualizer::pipeline_manager() const
    {
        return m_pipelines.get();
    }

    ViPipelineLayoutCPtr            ViVisualizer::pipeline_layout(uint64_t i) const
    {
        if(!m_pipelineLayouts)
            return {};
        return m_pipelineLayouts -> get(i);
    }
    
    ViPipelineLayoutCPtr            ViVisualizer::pipeline_layout_create(const Pipeline* pipe)
    {
        if(!m_pipelineLayouts)
            return {};
        if(!pipe)
            return {};
        return m_pipelineLayouts -> create(pipe);
    }
    
    void                            ViVisualizer::pipeline_layout_erase(uint64_t i)
    {
        if(m_pipelineLayouts){
            m_pipelineLayouts -> erase(i);
        }
    }
    
    void                            ViVisualizer::pipeline_layout_erase(const Pipeline* pipe)
    {
        if(pipe){
            pipeline_layout_erase(pipe->id());
        }
    }
    
    ViPipelineLayoutManager*        ViVisualizer::pipeline_layout_manager() const
    {
        return m_pipelineLayouts.get();
    }

    PresentMode  ViVisualizer::present_mode() const
    {
        return m_presentMode;
    }

    const std::set<PresentMode>&    ViVisualizer::present_modes_available() const
    {
        return m_presentModes;
    }

    VkQueue      ViVisualizer::present_queue(uint32_t i) const
    {
        return m_presentQueue ? m_presentQueue->queue(i) : nullptr;
    }
    
    uint32_t     ViVisualizer::present_queue_count() const
    {
        return m_presentQueue ? m_presentQueue->count() : 0;
    }
    
    uint32_t     ViVisualizer::present_queue_family() const
    {
        return m_presentQueue ? m_presentQueue->family() : UINT32_MAX;
    }

    ViQueueManager* ViVisualizer::present_queue_manager() const 
    { 
        return m_presentQueue; 
    }

    std::error_code ViVisualizer::present_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_presentQueue)
            return errors::present_queue_uninitialized();

        ViQueueTaskerPtr     tasker  = m_presentQueue->tasker(opts.queue);
        if(!tasker)
            return errors::tasker_uninitialized();
        return tasker->execute(opts.timeout, std::move(fn));
    }

    bool        ViVisualizer::present_queue_valid() const
    {
        return m_presentQueue != nullptr;
    }

    VkRenderPass        ViVisualizer::render_pass() const
    {
        if(m_renderPass)
            return m_renderPass -> render_pass();
        return nullptr;
    }
    
    std::error_code     ViVisualizer::queue_task(ViQueueType qt, queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        switch(qt){
        case ViQueueType::Auto:
            return graphic_queue_task(std::move(fn), opts);
        case ViQueueType::Graphic:
            return graphic_queue_task(std::move(fn), opts);
        case ViQueueType::Present:
            return present_queue_task(std::move(fn), opts);
        case ViQueueType::Compute:
            return compute_queue_task(std::move(fn), opts);
        case ViQueueType::VideoEncode:
            return video_encode_queue_task(std::move(fn), opts);
        case ViQueueType::VideoDecode:
            return video_decode_queue_task(std::move(fn), opts);
        case ViQueueType::Transfer:
            return transfer_queue_task(std::move(fn), opts);
        default:
            //  shrugs... how?
            return graphic_queue_task(std::move(fn), opts);
        }
    }

    ViSamplerCPtr     ViVisualizer::sampler(uint64_t i) const
    {
        if(!m_samplers)
            return {};
        return m_samplers -> get(i);
    }
    
    ViSamplerCPtr     ViVisualizer::sampler_create(const Sampler& sam)
    {
        if(!m_samplers)
            return {};
        return m_samplers -> create(sam);
    }
    
    void  ViVisualizer::sampler_erase(uint64_t i)
    {
        if(m_samplers){
            m_samplers -> erase(i);
        }
    }
    
    void  ViVisualizer::sampler_erase(const Sampler& sam)
    {
        sampler_erase(sam.id());
    }

    ViSamplerManager* ViVisualizer::sampler_manager() const
    {
        return m_samplers.get();
    }

    void        ViVisualizer::set_clear_color(const RGBA4F&i)
    {   
        m_clearValue    = vqClearValue(i);
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

    ViShaderCPtr ViVisualizer::shader(uint64_t i) const
    {
        if(!m_shaders)
            return {};
        return m_shaders -> get(i);
    }

    ViShaderCPtr    ViVisualizer::shader_create(const Shader&sha)
    {
        if(!m_shaders)
            return {};
        return m_shaders->create(sha);
    }

    void  ViVisualizer::shader_erase(uint64_t i)
    {
        if(m_shaders){
            m_shaders -> erase(i);
        }
    }
    
    void  ViVisualizer::shader_erase(const Shader& sha)
    {
        shader_erase(sha.id());
    }

    ViShaderManager*  ViVisualizer::shader_manager() const 
    { 
        return m_shaders.get(); 
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
        if(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_physical, m_surface, &ret) != VK_SUCCESS)
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

    VkSwapchainKHR  ViVisualizer::swapchain() const
    {
        if(!m_swapchain)
            return nullptr;
        return m_swapchain->swapchain();
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
            
    ViTextureCPtr ViVisualizer::texture(uint64_t i) const
    {
        if(!m_textures)
            return {};
        return m_textures->get(i);
    }

    ViTextureCPtr  ViVisualizer::texture_create(const Texture& tex)
    {
        if(!m_textures)
            return {};
        return m_textures->create(tex);
    }
    
    void  ViVisualizer::texture_erase(uint64_t i)
    {
        if(m_textures){
            m_textures -> erase(i);
        }
    }
    
    void  ViVisualizer::texture_erase(const Texture& tex)
    {
        texture_erase(tex.id());
    }

    ViTextureManager* ViVisualizer::texture_manager() const 
    { 
        return m_textures.get(); 
    }
    
    VkQueue     ViVisualizer::transfer_queue(uint32_t i) const
    {
        return m_transferQueue ? m_transferQueue->queue(i) : nullptr;
    }
    
    uint32_t    ViVisualizer::transfer_queue_count() const
    {
        return m_transferQueue ? m_transferQueue->count() : 0;
    }
    
    uint32_t    ViVisualizer::transfer_queue_family() const
    {
        return m_transferQueue ? m_transferQueue->family() : UINT32_MAX;
    }
    
    ViQueueManager* ViVisualizer::transfer_queue_manager() const 
    { 
        return m_transferQueue; 
    }

    std::error_code ViVisualizer::transfer_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_transferQueue)
            return errors::transfer_queue_uninitialized();

        ViQueueTaskerPtr     tasker  = m_transferQueue->tasker(opts.queue);
        if(!tasker)
            return errors::tasker_uninitialized();
        return tasker->execute(opts.timeout, std::move(fn));
    }

    bool    ViVisualizer::transfer_queue_valid() const
    {
        return m_transferQueue != nullptr;
    }

    void    ViVisualizer::trigger_rebuild()
    {
        m_rebuildSwap       = true;
    }


    VkQueue   ViVisualizer::video_decode_queue(uint32_t i) const
    {
        return m_videoDecQueue ? m_videoDecQueue->queue(i) : nullptr;
    }
    
    uint32_t  ViVisualizer::video_decode_queue_count() const
    {
        return m_videoDecQueue ? m_videoDecQueue->count() : 0;
    }
    
    uint32_t  ViVisualizer::video_decode_queue_family() const
    {
        return m_videoDecQueue ? m_videoDecQueue->family() : UINT32_MAX;
    }

    ViQueueManager*  ViVisualizer::video_decode_queue_manager() const 
    { 
        return m_videoDecQueue; 
    }

    std::error_code ViVisualizer::video_decode_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_videoDecQueue)
            return errors::video_decode_queue_uninitialized();

        ViQueueTaskerPtr     tasker  = m_videoDecQueue->tasker(opts.queue);
        if(!tasker)
            return errors::tasker_uninitialized();
        return tasker->execute(opts.timeout, std::move(fn));
    }

    bool        ViVisualizer::video_decode_queue_valid() const
    {
        return m_videoDecQueue != nullptr;
    }

    VkQueue   ViVisualizer::video_encode_queue(uint32_t i) const
    {
        return m_videoEncQueue ? m_videoEncQueue->queue(i) : nullptr;
    }
    
    uint32_t  ViVisualizer::video_encode_queue_count() const
    {
        return m_videoEncQueue ? m_videoEncQueue->count() : 0;
    }

    uint32_t  ViVisualizer::video_encode_queue_family() const
    {
        return m_videoEncQueue ? m_videoEncQueue->family() : UINT32_MAX;
    }

    ViQueueManager*  ViVisualizer::video_encode_queue_manager() const 
    { 
        return m_videoEncQueue; 
    }

    std::error_code ViVisualizer::video_encode_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_videoEncQueue)
            return errors::video_encode_queue_uninitialized();

        ViQueueTaskerPtr     tasker  = m_videoEncQueue->tasker(opts.queue);
        if(!tasker)
            return errors::tasker_uninitialized();
        return tasker->execute(opts.timeout, std::move(fn));
    }

    bool        ViVisualizer::video_encode_queue_valid() const
    {
        return m_videoEncQueue != nullptr;
    }

    std::error_code                 ViVisualizer::wait_idle()
    {
        vkDeviceWaitIdle(m_device);
        return {};
    }
}
