////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViVisualizer.hpp"

#include <yq-toolbox/color/RGBA.hpp>
#include <yq-toolbox/container/initlist_utils.hpp>
#include <yq-toolbox/text/basic.hpp>

#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/image/Image.hpp>
#include <yq-vulqan/memory/Buffer.hpp>
#include <yq-vulqan/shader/Shader.hpp>
#include <yq-vulqan/v/VqEnumerations.hpp>
#include <yq-vulqan/v/VqApp.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/v/VqUtils.hpp>
#include <yq-vulqan/viz/ViBuffer.hpp>
#include <yq-vulqan/viz/ViBufferManager.hpp>
#include <yq-vulqan/viz/ViImage.hpp>
#include <yq-vulqan/viz/ViImageManager.hpp>
#include <yq-vulqan/viz/ViQueueManager.hpp>
#include <yq-vulqan/viz/ViShader.hpp>
#include <yq-vulqan/viz/ViShaderManager.hpp>
#include <yq-vulqan/viz/ViQueueTasker.hpp>

#include <GLFW/glfw3.h>

namespace yq::tachyon {
    ViVisualizer::ViVisualizer()
    {
        m_presentMode   = PresentMode::Fifo;
    }
    
    ViVisualizer::~ViVisualizer()
    {
    }

    ///////////////////////////////////////////////////////////////////////////

    std::error_code  ViVisualizer::_0_app_window_initialize(GLFWwindow* w)
    {
        m_app       = VqApp::vk_app();
        if(!m_app)
            return errors::vulkan_no_application();

        m_instance    = m_app -> vulkan();
        if(!m_instance)
            return errors::vulkan_uninitialized();

        m_window    = w;
        if(!w)
            return errors::vulkan_no_window_provided();
            
        return {};
    }
    
    void             ViVisualizer::_0_app_window_kill()
    {
        m_instance      = nullptr;
        m_window        = nullptr;
        m_app           = nullptr;
    }

    std::error_code  ViVisualizer::_1_gpu_select_initialize(InitData& iData)
    {
        m_physical                    = iData.viewer.device;
        if(!m_physical){
            m_physical  = vqFirstDevice();
            if(!m_physical)
                return errors::vulkan_no_physical_device();
        }

        vkGetPhysicalDeviceFeatures(m_physical, &m_deviceFeatures);
        vkGetPhysicalDeviceProperties(m_physical, &m_deviceInfo);
        vkGetPhysicalDeviceMemoryProperties(m_physical, &m_memoryInfo);

        return {};
    }
    
    void             ViVisualizer::_1_gpu_select_kill()
    {
        m_physical  = nullptr;
    }

    std::error_code  ViVisualizer::_2_surface_initialize(InitData& iData)
    {
        //  passing in the create info in case we get smarter
        if(glfwCreateWindowSurface(m_instance, m_window, nullptr, &m_surface) != VK_SUCCESS)
            return errors::vulkan_no_window_surface();
            
        for(auto pm : vqGetPhysicalDeviceSurfacePresentModesKHR(m_physical, m_surface))
            m_presentModes.insert((PresentMode::enum_t) pm);
        m_surfaceFormats        = vqGetPhysicalDeviceSurfaceFormatsKHR(m_physical, m_surface);
        
        // right now, cheating on format & color space
        m_surfaceFormat         = VK_FORMAT_B8G8R8A8_SRGB;
        m_surfaceColorSpace     = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;
        return  {};
    }
    
    void             ViVisualizer::_2_surface_kill()
    {
        if(m_surface){
            vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
            m_surface               = nullptr;
        }
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
                vqInfo << "Discovered graphics queue " << i;
                m_graphicsQueue       = r.ptr();
            }
            if(r->types().is_set(ViQueueType::Compute)){
                vqInfo << "Discovered compute queue " << i;
                m_computeQueue       = r.ptr();
            }
            if(r->types().is_set(ViQueueType::VideoEncode)){
                vqInfo << "Discovered video encode queue " << i;
                m_videoEncQueue   = r.ptr();
            }
            if(r->types().is_set(ViQueueType::VideoDecode)){
                vqInfo << "Discovered video decode queue " << i;
                m_videoDecQueue   = r.ptr();
            }
            if(r->types().is_set(ViQueueType::Present)){
                vqInfo << "Discovered present queue " << i;
                m_presentQueue       = r.ptr();
            }
            if(r->types() == ViQueueTypeFlags(ViQueueType::Transfer)){
                vqInfo << "Discovered transfer queue " << i;
                m_transferQueue      = r.ptr();
            }
            iData.queues.push_back(r->info());
            m_queues.push_back(r);
        }
        
        if(!m_graphicsQueue)
            return errors::graphics_queue_not_found();
        if(!m_presentQueue)
            return errors::present_queue_not_found();
        if(wantQueue.is_set(ViQueueType::Compute) && !m_computeQueue && is_required(iData.viewer.compute))
            return errors::compute_queue_not_found();
        if(wantQueue.is_set(ViQueueType::VideoEncode) && !m_videoEncQueue && is_required(iData.viewer.video_encode))
            return errors::video_encode_queue_not_found();
        if(wantQueue.is_set(ViQueueType::VideoDecode) && !m_videoDecQueue && is_required(iData.viewer.video_decode))
            return errors::video_decode_queue_not_found();
        if(wantQueue.is_set(ViQueueType::Transfer) && !m_transferQueue && is_required(iData.viewer.transfer))
            return errors::transfer_queue_not_found();
        if(!m_transferQueue)
            m_transferQueue  = m_graphicsQueue;
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
            vqError << "Unable to create vulkan (logical) device with result code: " << to_string_view((VqResult) res);
            return errors::vulkan_device_cant_create();
        }
        return {};
    }
    
    void                ViVisualizer::_4_device_kill()
    {
        if(m_device){
            vkDestroyDevice(m_device, nullptr);
            m_device                = nullptr;
        }
    }
    
    std::error_code     ViVisualizer::_5_allocator_init(InitData& iData)
    {
        VmaAllocatorCreateInfo      allocatorCreateInfo{};
        allocatorCreateInfo.instance                        = m_instance;
        allocatorCreateInfo.physicalDevice                  = m_physical;
        allocatorCreateInfo.device                          = m_device;
        allocatorCreateInfo.vulkanApiVersion                = m_app->app_info().vulkan_api;
        allocatorCreateInfo.preferredLargeHeapBlockSize     = (VkDeviceSize) iData.viewer.chunk_size;
        vmaCreateAllocator(&allocatorCreateInfo, &m_allocator);
        return {};
    }
    
    void                ViVisualizer::_5_allocator_kill()
    {
        if(m_allocator){
            vmaDestroyAllocator(m_allocator);
            m_allocator = nullptr;
        }
    }
    
    std::error_code     ViVisualizer::_6_manager_init()
    {
        m_shaders           = std::make_unique<ViShaderManager>(*this);
        m_buffers           = std::make_unique<ViBufferManager>(*this);
        m_images            = std::make_unique<ViImageManager>(*this);
        return {};
    }
    
    void                ViVisualizer::_6_manager_kill()
    {
        m_queues        = {};
        m_shaders       = {};
        m_buffers       = {};
        m_images        = {};
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
    
    ViImageCPtr     ViVisualizer::image_create(const Image& img)
    {
        if(!m_images)
            return {};
        return m_images -> create(img);
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
    
    uint32_t    ViVisualizer::max_viewports() const 
    { 
        return m_deviceInfo.limits.maxViewports; 
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

    void        ViVisualizer::set_clear_color(const RGBA4F&i)
    {   
        m_clearValue    = vqClearValue(i);
    }

    ViShaderCPtr ViVisualizer::shader(uint64_t i) const
    {
        if(!m_shaders)
            return {};
        return m_shaders -> get(i);
    }

    ViShaderCPtr    ViVisualizer::shader_create(const Shader&sh)
    {
        if(!m_shaders)
            return {};
        return m_shaders->create(sh);
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

    bool        ViVisualizer::transfer_queue_valid() const
    {
        return m_transferQueue != nullptr;
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
}
