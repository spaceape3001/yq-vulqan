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
#include <yq-vulqan/v/VqApp.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/v/VqUtils.hpp>
#include <yq-vulqan/viz/ViBuffer.hpp>
#include <yq-vulqan/viz/ViBufferManager.hpp>
#include <yq-vulqan/viz/ViQueueManager.hpp>
#include <yq-vulqan/viz/ViShader.hpp>
#include <yq-vulqan/viz/ViShaderManager.hpp>

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
            return create_error<"No application available">();

        m_window    = w;
        if(!w)
            return create_error<"No window provided">();
            
        m_instance    = m_app -> vulkan();
        if(!m_instance)
            return create_error<"Vulkan unavailable">();
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
                return create_error<"No GPU/Physical device provided or detected">();
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
            return create_error<"No window surface available">();
            
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

        if(!is_empty(iData.viewer.compute)){
            vqInfo << " Want compute queue with " << count(iData.viewer.compute) << " queues";
            wantQueue.set(ViQueueType::Compute);
        }
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
                m_graphics       = r.ptr();
            }
            if(r->types().is_set(ViQueueType::Compute)){
                vqInfo << "Discovered compute queue " << i;
                m_compute       = r.ptr();
            }
            if(r->types().is_set(ViQueueType::VideoEncode)){
                vqInfo << "Discovered video encode queue " << i;
                m_videoEnc   = r.ptr();
            }
            if(r->types().is_set(ViQueueType::VideoDecode)){
                vqInfo << "Discovered video decode queue " << i;
                m_videoDec   = r.ptr();
            }
            if(r->types().is_set(ViQueueType::Present)){
                vqInfo << "Discovered present queue " << i;
                m_present       = r.ptr();
            }
            if(r->types() == ViQueueTypeFlags(ViQueueType::Transfer)){
                vqInfo << "Discovered transfer queue " << i;
                m_transfer      = r.ptr();
            }
            iData.queues.push_back(r->info());
            m_queues.push_back(r);
        }
        
        if(!m_graphics)
            return create_error<"Missing graphic queue">();
        if(!m_present)
            return create_error<"Missing present queue">();
        if(wantQueue.is_set(ViQueueType::Compute) && !m_compute)
            return create_error<"Missing compute queue">();
        if(wantQueue.is_set(ViQueueType::VideoEncode) && !m_videoEnc)
            return create_error<"Missing video encode queue">();
        if(wantQueue.is_set(ViQueueType::VideoDecode) && !m_videoDec)
            return create_error<"Missing video decode queue">();
        if(wantQueue.is_set(ViQueueType::Transfer) && !m_transfer)
            return create_error<"Missing transfer queue">();
        return {};
    }
    
    void  ViVisualizer::_3_queues_fetch()
    {
        for(auto& r : m_queues)
            r->init();
    }
    
    void   ViVisualizer::_3_queues_kill()
    {
        m_graphics  = nullptr;
        m_present   = nullptr;
        m_compute   = nullptr;
        m_transfer  = nullptr;
        m_videoEnc  = nullptr;
        m_videoDec  = nullptr;
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
        
        if(vkCreateDevice(m_physical, &deviceCreateInfo, nullptr, &m_device) != VK_SUCCESS)
            return create_error<"Unable to create vulkan (logical) device">();
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
        m_shaders           = std::make_unique<ViShaderManager>(m_device);
        m_buffers           = std::make_unique<ViBufferManager>(*this);
        return {};
    }
    
    void                ViVisualizer::_6_manager_kill()
    {
        m_shaders       = {};
        m_buffers       = {};
    }


    ///////////////////////////////////////////////////////////////////////////

    Expect<ViBuffer> ViVisualizer::buffer(uint64_t i) const
    {
        if(!m_buffers)
            return errors::NO_BUFFER_MANAGER();
        return m_buffers->get(i);
    }

    Expect<ViBuffer>  ViVisualizer::buffer_create(const Buffer& buf)
    {
        if(!m_buffers)
            return errors::NO_BUFFER_MANAGER();
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
        return m_compute ? m_compute->queue(i) : nullptr;
    }
    
    uint32_t  ViVisualizer::compute_queue_count() const
    {
        return m_compute ? m_compute->count() : 0;
    }
    
    uint32_t  ViVisualizer::compute_queue_family() const
    {
        return m_compute ? m_compute->family() : UINT32_MAX;
    }

    ViQueueManager* ViVisualizer::compute_queue_manager() const 
    { 
        return m_compute; 
    }

    bool    ViVisualizer::compute_queue_valid() const
    {
        return m_compute != nullptr;
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
        
        return unexpected<"Failed to find supported format">();
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
        return m_graphics ? m_graphics->queue(i) : nullptr;
    }
    
    uint32_t    ViVisualizer::graphic_queue_count() const
    {
        return m_graphics ? m_graphics->count() : 0;
    }
    
    uint32_t    ViVisualizer::graphic_queue_family() const
    {
        return m_graphics ? m_graphics->family() : UINT32_MAX;
    }
    
    ViQueueManager* ViVisualizer::graphic_queue_manager() const 
    { 
        return m_graphics; 
    }

    bool        ViVisualizer::graphic_queue_valid() const
    {
        return m_graphics != nullptr;
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
        return m_present ? m_present->queue(i) : nullptr;
    }
    
    uint32_t     ViVisualizer::present_queue_count() const
    {
        return m_present ? m_present->count() : 0;
    }
    
    uint32_t     ViVisualizer::present_queue_family() const
    {
        return m_present ? m_present->family() : UINT32_MAX;
    }

    ViQueueManager* ViVisualizer::present_queue_manager() const 
    { 
        return m_present; 
    }

    bool        ViVisualizer::present_queue_valid() const
    {
        return m_present != nullptr;
    }
    
    void        ViVisualizer::set_clear_color(const RGBA4F&i)
    {   
        m_clearValue    = vqClearValue(i);
    }

    Expect<ViShader> ViVisualizer::shader(uint64_t i) const
    {
        if(!m_shaders)
            return errors::NO_SHADER_MANAGER();
        return m_shaders -> get(i);
    }

    Expect<ViShader>  ViVisualizer::shader_create(const Shader&sh)
    {
        if(!m_shaders)
            return errors::NO_SHADER_MANAGER();
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
        return m_transfer ? m_transfer->queue(i) : nullptr;
    }
    
    uint32_t    ViVisualizer::transfer_queue_count() const
    {
        return m_transfer ? m_transfer->count() : 0;
    }
    
    uint32_t    ViVisualizer::transfer_queue_family() const
    {
        return m_transfer ? m_transfer->family() : UINT32_MAX;
    }
    
    ViQueueManager* ViVisualizer::transfer_queue_manager() const 
    { 
        return m_transfer; 
    }

    bool        ViVisualizer::transfer_queue_valid() const
    {
        return m_transfer != nullptr;
    }

    VkQueue   ViVisualizer::video_decode_queue(uint32_t i) const
    {
        return m_videoDec ? m_videoDec->queue(i) : nullptr;
    }
    
    uint32_t  ViVisualizer::video_decode_queue_count() const
    {
        return m_videoDec ? m_videoDec->count() : 0;
    }
    
    uint32_t  ViVisualizer::video_decode_queue_family() const
    {
        return m_videoDec ? m_videoDec->family() : UINT32_MAX;
    }

    ViQueueManager*  ViVisualizer::video_decode_queue_manager() const 
    { 
        return m_videoDec; 
    }

    bool        ViVisualizer::video_decode_queue_valid() const
    {
        return m_videoDec != nullptr;
    }

    VkQueue   ViVisualizer::video_encode_queue(uint32_t i) const
    {
        return m_videoEnc ? m_videoEnc->queue(i) : nullptr;
    }
    
    uint32_t  ViVisualizer::video_encode_queue_count() const
    {
        return m_videoEnc ? m_videoEnc->count() : 0;
    }

    uint32_t  ViVisualizer::video_encode_queue_family() const
    {
        return m_videoEnc ? m_videoEnc->family() : UINT32_MAX;
    }

    ViQueueManager*  ViVisualizer::video_encode_queue_manager() const 
    { 
        return m_videoEnc; 
    }

    bool        ViVisualizer::video_encode_queue_valid() const
    {
        return m_videoEnc != nullptr;
    }
}
