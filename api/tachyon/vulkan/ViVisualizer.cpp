////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/vulkan/ViVisualizer.hpp>

#include <yq/color/RGBA.hpp>
#include <yq/container/initlist_utils.hpp>
#include <yq/text/basic.hpp>
#include <yq/text/join.hpp>

#include <tachyon/errors.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/gfx/Raster.hpp>
#include <tachyon/app/ViewerCreateInfo.hpp>
#include <tachyon/gfx/Buffer.hpp>
#include <tachyon/gfx/Pipeline.hpp>
#include <tachyon/gfx/Sampler.hpp>
#include <tachyon/gfx/Shader.hpp>
#include <tachyon/gfx/Texture.hpp>
//#include <yq/tachyon/v/VqEnumerations.hpp>
#include <tachyon/vulkan/VqEnums.hpp>
#include <tachyon/vulkan/VqStructs.hpp>
#include <tachyon/vulkan/VqUtils.hpp>
#include <tachyon/vulkan/VulqanManager.hpp>
#include <tachyon/vulkan/ViDevice.hpp>
#include <tachyon/vulkan/ViManager.hpp>
#include <tachyon/vulkan/ViBuffer.hpp>
#include <tachyon/vulkan/ViImage.hpp>
#include <tachyon/vulkan/ViPipeline.hpp>
#include <tachyon/vulkan/ViPipelineLayout.hpp>
#include <tachyon/vulkan/ViQueueTasker.hpp>
#include <tachyon/vulkan/ViRenderPass.hpp>
#include <tachyon/vulkan/ViSampler.hpp>
#include <tachyon/vulkan/ViShader.hpp>
#include <tachyon/vulkan/ViSurface.hpp>
#include <tachyon/vulkan/ViSwapchain.hpp>
#include <tachyon/vulkan/ViTexture.hpp>
#include <tachyon/vulkan/VisualizerCreateData.hpp>

#include <GLFW/glfw3.h>

namespace yq::tachyon {
    VkInstance    ViVisualizer::instance() 
    { 
        return VulqanManager::instance(); 
    }

    ///////////////////////////////////////////////////////////////////////////

    ViVisualizer::ViVisualizer(const CreateData& cfg) : m_device(cfg.device), m_surface(cfg.surface)
    {
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
#if 0
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
        
        vizDebug << "ViVisualizer: Created the managers";
        return {};
    }
    
    void                ViVisualizer::_6_manager_kill()
    {
        
        vizDebug << "ViVisualizer: Destroyed the managers";
    }
#endif

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

        m_device->wait_idle();
        
        std::error_code ec  = p -> init(*this, cfg);
        if(ec != std::error_code()){
            vizWarning << "ViVisualizer unable to initialize new swapchain!  " << ec.message();
            return ;
        }
        m_swapchain     = ViSwapchainCPtr(p);
        vizDebug << "ViVisualizer: Rebuilt the swapchain";
    }

    ///////////////////////////////////////////////////////////////////////////

    std::error_code     ViVisualizer::_init(const CreateData& vcd)
    {
        if(!m_device || !m_device->valid())
            return create_error<"null device">();
        if(!m_surface || !m_surface->valid())
            return create_error<"null surface">();

        for(auto pm : vqGetPhysicalDeviceSurfacePresentModesKHR(physical(), surface()))
            m_presentModes.insert((PresentMode::enum_t) pm);
        m_presentMode           = m_presentModes.contains(vcd.viewer.pmode) ? vcd.viewer.pmode : PresentMode{ PresentMode::Fifo };

        m_surfaceFormats        = vqGetPhysicalDeviceSurfaceFormatsKHR(physical(), surface());
        
        // right now, cheating on format & color space
        m_surfaceFormat         = VK_FORMAT_B8G8R8A8_SRGB;
        m_surfaceColorSpace     = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;

        set_clear_color(vcd.viewer.clear);
            

            //  If you're debugging the present queue... means it's fouled up.  
            //  In order to break the surface dependency for the device, we
            //  assumed that it's generally available on the graphic queue.
            //  However, if that's not the case, then the vulkan create info
            //  needs to have the relevant queue enabled *AND* it needs to be
            //  set on the create data structure.
        
        m_graphicsQueue  = m_device->graphics_queue(vcd.number);
        if(!m_device->is_queue_valid(m_graphicsQueue))
            return create_error<"no graphic queue">();

        if(vcd.present.valid()){
            if(!m_device->is_queue_present_supported(vcd.present.family, m_surface->surface()))
                return create_error<"queue does not have present support">();
            m_presentQueue  = vcd.present;
        } else {
            if(!m_device->is_queue_present_supported(m_graphicsQueue.family, m_surface->surface()))
                return create_error<"queue does not have present support">();
            m_presentQueue  = m_graphicsQueue;
        }
            
        m_computeQueue  = { m_device->queue_family(ViQueueType::Compute), 0 };
        if(m_device->is_queue_valid(m_computeQueue))
            m_flags |= X::Compute;
        
        m_transferQueue = { m_device->queue_family(ViQueueType::Transfer), 0 };
        if(m_device->is_queue_valid(m_transferQueue))
            m_flags |= X::Transfer;
        
        m_videoDecQueue = { m_device->queue_family(ViQueueType::VideoDecode), 0 };
        if(m_device->is_queue_valid(m_videoDecQueue))
            m_flags |= X::VideoDec;
        m_videoEncQueue = { m_device->queue_family(ViQueueType::VideoEncode), 0 };
        if(m_device->is_queue_valid(m_videoEncQueue))
            m_flags |= X::VideoEnc;
            
        std::error_code     ec;

        ec = _7_render_pass_create();
        if(ec != std::error_code())
            return ec;
            
        ec = _8_swapchain_create();
        if(ec != std::error_code())
            return ec;
            
        ec = _9_pipeline_manager_create();
        if(ec != std::error_code())
            return ec;
        return {};
    }
    
    void                ViVisualizer::_kill()
    {
        if(!m_device->valid())
            return ;
            
        _9_pipeline_manager_kill();
        m_device->wait_idle();
        _8_swapchain_kill();
        m_device->wait_idle();
        _7_render_pass_kill();
        m_device->wait_idle();
    }


    ///////////////////////////////////////////////////////////////////////////

    VmaAllocator ViVisualizer::allocator() const 
    { 
        if(m_device)
            return m_device->allocator();
        return nullptr;
    }

    ViBufferCPtr ViVisualizer::buffer(uint64_t i) const
    {
        if(!m_device)
            return {};
        return m_device -> buffer(i);
    }

    ViBufferCPtr  ViVisualizer::buffer_create(const Buffer& buf)
    {
        if(!m_device)
            return {};
        return m_device -> buffer_create(buf);
    }
    
    void  ViVisualizer::buffer_erase(uint64_t i)
    {
        if(m_device)
            m_device -> buffer_erase(i);
    }
    
    void  ViVisualizer::buffer_erase(const Buffer& buf)
    {
        if(m_device)
            m_device -> buffer_erase(buf.id());
    }

    #if 0
    ViBufferManager* ViVisualizer::buffer_manager() const 
    { 
        return m_buffers.get(); 
    }
    #endif

    void              ViVisualizer::cleanup(cleanup_fn&& fn)
    {
        if(m_device){
            m_device->cleanup(std::move(fn));
        } else {
            fn();
        }
    }

    void   ViVisualizer::cleanup(sweep_k)
    {
        if(m_device)
            m_device->cleanup(SWEEP);
    }

    RGBA4F ViVisualizer::clear_color() const
    {
        VkClearValue    cv = m_clearValue;
        return vqExtractRGBA4F(cv);
    }

    VkQueue  ViVisualizer::compute_queue() const
    {
        if(m_device)
            return m_device -> queue(m_computeQueue);
        return nullptr;
    }
    
    std::error_code ViVisualizer::compute_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_computeQueue, opts.timeout, std::move(fn));
    }

    bool    ViVisualizer::compute_queue_valid() const
    {
        return m_device && m_device->is_queue_valid(m_computeQueue);
    }

    VkDevice            ViVisualizer::device() const
    {
        return logical();
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
            vkGetPhysicalDeviceFormatProperties(physical(), format, &props);
            
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
        if(m_device)
            return m_device->gpu_name();
        return {};
    }

    VkPhysicalDeviceType    ViVisualizer::gpu_type() const
    {
        if(m_device)
            return m_device->gpu_type();
        return {};
    }

    VkQueue     ViVisualizer::graphic_queue() const
    {
        if(m_device)
            return m_device->queue(m_graphicsQueue);
        return nullptr;
    }
    
    bool        ViVisualizer::graphic_queue_valid() const
    {
        return m_device && m_device->is_queue_valid(m_graphicsQueue);
    }

    std::error_code ViVisualizer::graphic_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_graphicsQueue, opts.timeout, std::move(fn));
    }

    ViImageCPtr     ViVisualizer::image(uint64_t i) const
    {
        if(!m_device)
            return {};
        return m_device->image(i);
    }
    
    ViImageCPtr     ViVisualizer::image_create(const Raster& img)
    {
        if(!m_device)
            return {};
        return m_device->image_create(img);
    }
    
    void  ViVisualizer::image_erase(uint64_t i)
    {
        if(m_device)
            m_device -> image_erase(i);
    }
    
    void  ViVisualizer::image_erase(const Raster& img)
    {
        if(m_device)
            m_device -> image_erase(img.id());
    }

    Expect<RasterPtr>       ViVisualizer::image_export(VkImage img, const VkExtent2D&size, VkFormat fmt)
    {
        if(!m_device)   
            return {};
        return m_device->image_export(img, size, fmt);
    }
    
    Expect<RasterPtr>       ViVisualizer::image_export(VkImage img, const VkExtent3D&size, VkFormat fmt)
    {
        if(!m_device)   
            return {};
        return m_device->image_export(img, size, fmt);
    }

    VkDevice    ViVisualizer::logical() const
    {
        if(m_device)
            return m_device->device();
        return nullptr;
    }

    uint32_t    ViVisualizer::max_memory_allocation_count() const  
    { 
        if(m_device)
            return m_device->max_memory_allocation_count();
        return 0;
    }
    
    uint32_t    ViVisualizer::max_push_constants_size() const 
    { 
        if(m_device)
            return m_device->max_push_constants_size();
        return 0;
    }

    float       ViVisualizer::max_sampler_anisotropy() const
    {
        if(m_device)
            return m_device->max_sampler_anisotropy();
        return 0.f;
    }
    
    uint32_t    ViVisualizer::max_viewports() const 
    { 
        if(m_device)
            return m_device->max_viewports();
        return 0;
    }

    bool         ViVisualizer::multiview_enabled() const
    {
        return m_device && m_device->multiview_enabled();
    }
    
    uint32_t     ViVisualizer::multiview_max_instance_index() const
    {
        if(m_device)
            return m_device->multiview_max_instance_index();
        return {};
    }

    uint32_t     ViVisualizer::multiview_max_view_count() const
    {
        if(m_device)
            return m_device->multiview_max_view_count();
        return {};
    }

    VkPhysicalDevice                ViVisualizer::physical() const 
    { 
        if(m_device)
            return m_device->physical();
        return nullptr;
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
        if(!m_device)
            return {};
        return m_device->pipeline_layout(i);
    }
    
    ViPipelineLayoutCPtr            ViVisualizer::pipeline_layout_create(const Pipeline* pipe)
    {
        if(!m_device)
            return {};
        return m_device->pipeline_layout_create(pipe);
    }
    
    void                            ViVisualizer::pipeline_layout_erase(uint64_t i)
    {
        if(m_device)
            m_device -> pipeline_layout_erase(i);
    }
    
    void                            ViVisualizer::pipeline_layout_erase(const Pipeline* pipe)
    {
        if(pipe && m_device)
            m_device -> pipeline_layout_erase(pipe->id());
    }
    
    PresentMode  ViVisualizer::present_mode() const
    {
        return m_presentMode;
    }

    const std::set<PresentMode>&    ViVisualizer::present_modes_available() const
    {
        return m_presentModes;
    }

    VkQueue      ViVisualizer::present_queue() const
    {
        if(m_device)
            return m_device -> queue(m_presentQueue);
        return nullptr;
    }

    std::error_code ViVisualizer::present_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_presentQueue, opts.timeout, std::move(fn));
    }

    bool        ViVisualizer::present_queue_valid() const
    {
        return m_device && m_device->is_queue_valid( m_presentQueue );
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
        if(!m_device)
            return {};
        return m_device->sampler(i);
    }
    
    ViSamplerCPtr     ViVisualizer::sampler_create(const Sampler& sam)
    {
        if(!m_device)
            return {};
        return m_device->sampler_create(sam);
    }
    
    void  ViVisualizer::sampler_erase(uint64_t i)
    {
        if(m_device)
            m_device -> sampler_erase(i);
    }
    
    void  ViVisualizer::sampler_erase(const Sampler& sam)
    {
        if(m_device)
            m_device -> sampler_erase(sam.id());
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
        if(!m_device)
            return {};
        return m_device->shader(i);
    }

    ViShaderCPtr    ViVisualizer::shader_create(const Shader&sha)
    {
        if(!m_device)
            return {};
        return m_device->shader_create(sha);
    }

    void  ViVisualizer::shader_erase(uint64_t i)
    {
        if(m_device)
            m_device->shader_erase(i);
    }
    
    void  ViVisualizer::shader_erase(const Shader& sha)
    {
        if(m_device)
            m_device->shader_erase(sha.id());
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

    VkSurfaceKHR      ViVisualizer::surface() const 
    { 
        if(m_surface)
            return m_surface -> surface();
        return nullptr;
    }

    VkSurfaceCapabilitiesKHR_x  ViVisualizer::surface_capabilities() const
    {
        VkSurfaceCapabilitiesKHR    ret;
        if(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physical(), surface(), &ret) != VK_SUCCESS)
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
        if(!m_device)
            return {};
        return m_device->texture(i);
    }

    ViTextureCPtr  ViVisualizer::texture_create(const Texture& tex)
    {
        if(!m_device)
            return {};
        return m_device->texture_create(tex);
    }
    
    void  ViVisualizer::texture_erase(uint64_t i)
    {
        if(m_device)
            m_device->texture_erase(i);
    }
    
    void  ViVisualizer::texture_erase(const Texture& tex)
    {
        if(m_device)
            m_device->texture_erase(tex.id());
    }

    VkQueue     ViVisualizer::transfer_queue() const
    {
        if(m_device)
            return m_device->queue(m_transferQueue);
        return nullptr;
    }
    
    std::error_code ViVisualizer::transfer_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_transferQueue, opts.timeout, std::move(fn));
    }

    bool    ViVisualizer::transfer_queue_valid() const
    {
        return m_device && m_device->is_queue_valid(m_transferQueue);
    }

    void    ViVisualizer::trigger_rebuild()
    {
        m_rebuildSwap       = true;
    }


    VkQueue   ViVisualizer::video_decode_queue() const
    {
        if(m_device)
            return m_device -> queue(m_videoDecQueue);
        return nullptr;
    }
    
    std::error_code ViVisualizer::video_decode_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_videoDecQueue, opts.timeout, std::move(fn));
    }

    bool        ViVisualizer::video_decode_queue_valid() const
    {
        return m_device && m_device->is_queue_valid(m_videoDecQueue);
    }

    VkQueue   ViVisualizer::video_encode_queue() const
    {
        if(m_device)
            return m_device->queue(m_videoEncQueue);
        return nullptr;
    }
    
    std::error_code ViVisualizer::video_encode_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_videoEncQueue, opts.timeout, std::move(fn));
    }

    bool        ViVisualizer::video_encode_queue_valid() const
    {
        return m_device && m_device->is_queue_valid(m_videoEncQueue);
    }

    std::error_code                 ViVisualizer::wait_idle()
    {
        if(m_device)
            return m_device->wait_idle();
        return errors::visualizer_uninitialized();
    }
}
