////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gpu/VqApp.hpp>

#include <basic/errors.hpp>
#include <math/color/RGBA.hpp>
#include <tachyon/errors.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/Shader.hpp>
#include <tachyon/gpu/Visualizer.hpp>
#include <tachyon/gpu/VqUtils.hpp>

#include <GLFW/glfw3.h>

namespace yq {
    namespace tachyon {
        Visualizer::Visualizer() 
        {
        }
        
        Visualizer::~Visualizer()
        {
            kill_visualizer();
        }
        
        namespace {
            std::vector<float>      make_weights(const ViQueueSpec& qs, uint32_t mincnt=0)
            { 
                if(const std::vector<float>*p = std::get_if<std::vector<float>>(&qs)){
                    if((!p->empty()) && (p->size() >= (size_t) mincnt))
                        return *p;
                }
                uint32_t    cnt = mincnt;
                if(const uint32_t* p = std::get_if<uint32_t>(&qs))
                    cnt = std::max(cnt, *p);
                if(const bool* p = std::get_if<bool>(&qs)){
                    if(*p)
                        cnt = std::max<uint32_t>(cnt, 1);
                }
                if(cnt){
                    std::vector<float> ret;
                    ret.resize(cnt, 1.);
                    return ret;
                }
                return std::vector<float>();
            }
        }

        std::error_code             Visualizer::_ctor(const ViewerCreateInfo&vci,GLFWwindow*w)
        {
            m_app       = VqApp::vk_app();
            if(!m_app)
                return errors::no_application();

            m_window    = w;
            if(!w)
                return errors::no_window();
                
            m_instance    = m_app -> vulkan();
            if(!m_instance)
                return errors::no_vulkan();

            //  ================================
            //  SELECT GPU (ie, physical device)

            m_physical                    = vci.device;
            if(!m_physical){
                m_physical  = vqFirstDevice();
                if(!m_physical)
                    return errors::no_gpu_device();
            }
            
            vkGetPhysicalDeviceProperties(m_physical, &m_deviceInfo);
            vkGetPhysicalDeviceMemoryProperties(m_physical, &m_memoryInfo);
           
            //  ================================
            //  GLFW "SURFACE"

            if(glfwCreateWindowSurface(m_instance, m_window, nullptr, &m_surface) != VK_SUCCESS)
                return errors::no_window_surface();
                
            for(auto pm : vqGetPhysicalDeviceSurfacePresentModesKHR(m_physical, m_surface))
                m_presentModes.insert((PresentMode::enum_t) pm);
            m_surfaceFormats        = vqGetPhysicalDeviceSurfaceFormatsKHR(m_physical, m_surface);
            
            // right now, cheating on format & color space
            m_surfaceFormat         = VK_FORMAT_B8G8R8A8_SRGB;
            m_surfaceColorSpace     = VK_COLOR_SPACE_SRGB_NONLINEAR_KHR;

            //  ================================
            //  LOGICAL DEVICE CREATION
            //
            //  Buckle up, this is a long one

                // list extensions, augmenting with swap chain
                
            std::vector<const char*>    devExtensions = vci.extensions;
            devExtensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);

                //  Query the GPU for valid queue families
            auto queueInfos         = vqFindQueueFamilies(m_physical, m_surface);
            
                //  And we need to create them... so request
            std::vector<VkDeviceQueueCreateInfo> qci;
            
                //  graphic is required....
            std::vector<float>  graphicWeights  = make_weights(vci.graphic, 1);
            if(!queueInfos.graphics.has_value()){
                return errors::no_graphic_queue();
            } else {
                m_graphic.family        = queueInfos.graphics.value();
                VqDeviceQueueCreateInfo info;
                info.queueFamilyIndex   = m_graphic.family;
                info.queueCount         = (uint32_t) graphicWeights.size();
                info.pQueuePriorities   = graphicWeights.data();
                qci.push_back(info);
            }
            
                //  present is required....
            std::vector<float>  presentWeights  = make_weights(vci.present, 1);
            if(!queueInfos.present.has_value()){
                return errors::no_present_queue();
            } else {
                m_present.family        = queueInfos.present.value();
                VqDeviceQueueCreateInfo info;
                info.queueFamilyIndex   = m_present.family;
                info.queueCount         = (uint32_t) presentWeights.size();
                info.pQueuePriorities   = presentWeights.data();
                qci.push_back(info);
            }
            
                //  Determine if compute is requested, create the request
            std::vector<float>  computeWeights  = make_weights(vci.compute, 0);
            if(!computeWeights.empty()){
                if(!queueInfos.compute.has_value()){
                    return errors::no_compute_queue();
                } else {
                    m_compute.family        = queueInfos.compute.value();
                    VqDeviceQueueCreateInfo info;
                    info.queueFamilyIndex   = m_compute.family;
                    info.queueCount         = (uint32_t) computeWeights.size();
                    info.pQueuePriorities   = computeWeights.data();
                    qci.push_back(info);
                }
            }

                //  Determine if video decoding is requested, create the request
            std::vector<float>  videoDecWeights = make_weights(vci.video_decode, 0);
            if(!videoDecWeights.empty()){
                if(!queueInfos.videoDecode.has_value()){
                    return errors::no_video_decode_queue();
                } else {
                    m_videoDecode.family    = queueInfos.videoDecode.value();
                    VqDeviceQueueCreateInfo info;
                    info.queueFamilyIndex   = m_videoDecode.family;
                    info.queueCount         = (uint32_t) videoDecWeights.size();
                    info.pQueuePriorities   = videoDecWeights.data();
                    qci.push_back(info);
                }
            }
            
                //  Determine if video encoding is requested, create the request
            std::vector<float>  videoEncWeights = make_weights(vci.video_encode, 0);
            if(!videoEncWeights.empty()){
                if(!queueInfos.videoEncode.has_value()){
                    return errors::no_video_encode_queue();
                } else {
                    m_videoEncode.family    = queueInfos.videoEncode.value();
                    VqDeviceQueueCreateInfo info;
                    info.queueFamilyIndex   = m_videoEncode.family;
                    info.queueCount         = (uint32_t) videoEncWeights.size();
                    info.pQueuePriorities   = videoEncWeights.data();
                    qci.push_back(info);
                }
            }
            
            std::sort(qci.begin(), qci.end(), [](const VkDeviceQueueCreateInfo& a, const VkDeviceQueueCreateInfo& b) -> bool {
                return a.queueFamilyIndex < b.queueFamilyIndex;
            });
            
            for(size_t i=0;i<qci.size()-1;++i){
                VkDeviceQueueCreateInfo&    prev  = qci[i];
                VkDeviceQueueCreateInfo&    next  = qci[i+1];
                if(prev.queueFamilyIndex != next.queueFamilyIndex)
                    continue;
                
                //  carry the request forward
                if(next.queueCount < prev.queueCount){
                    //  steal the pointer
                    next.queueCount         = prev.queueCount;
                    next.pQueuePriorities   = prev.pQueuePriorities;
                }
                prev.queueFamilyIndex   = UINT32_MAX;
            }
            
            auto qitr = std::remove_if(qci.begin(), qci.end(), [](const VkDeviceQueueCreateInfo& a) -> bool {
                return a.queueFamilyIndex == UINT32_MAX;
            });
            if(qitr != qci.end())
                qci.erase(qitr, qci.end());
                    
            //  And with that, we have the queues all lined up, ready to be created.

            VkPhysicalDeviceFeatures    gpu_features{};
            if(vci.fill_non_solid)
                gpu_features.fillModeNonSolid    = VK_TRUE;

            VqDeviceCreateInfo          deviceCreateInfo;
            deviceCreateInfo.pQueueCreateInfos        = qci.data();
            deviceCreateInfo.queueCreateInfoCount     = (uint32_t) qci.size();
            deviceCreateInfo.pEnabledFeatures         = &gpu_features;
            
            const auto& layers = m_app->layers();
            
            deviceCreateInfo.enabledLayerCount          = (uint32_t) layers.size();
            if(deviceCreateInfo.enabledLayerCount)
                deviceCreateInfo.ppEnabledLayerNames    = layers.data();
        
            deviceCreateInfo.enabledExtensionCount      = (uint32_t) devExtensions.size();
            deviceCreateInfo.ppEnabledExtensionNames    = devExtensions.data();
            
            VqPhysicalDeviceVulkan12Features            v12features;
            v12features.bufferDeviceAddress = true;
            deviceCreateInfo.pNext          = &v12features;
            
            if(vkCreateDevice(m_physical, &deviceCreateInfo, nullptr, &m_device) != VK_SUCCESS)
                return errors::vulkan_device_cant_create();

            //  ================================
            //  GETTING THE QUEUES

            m_graphic.set(m_device, graphicWeights.size());
            m_present.set(m_device, presentWeights.size());
            if(m_compute.family != UINT32_MAX)
                m_compute.set(m_device, computeWeights.size());
            if(m_videoEncode.family != UINT32_MAX)
                m_videoEncode.set(m_device, videoEncWeights.size());
            if(m_videoDecode.family != UINT32_MAX)
                m_videoDecode.set(m_device, videoDecWeights.size());

            //  ================================
            //  ALLOCATOR

            VmaAllocatorCreateInfo      allocatorCreateInfo{};
            allocatorCreateInfo.instance                        = m_instance;
            allocatorCreateInfo.physicalDevice                  = m_physical;
            allocatorCreateInfo.device                          = m_device;
            allocatorCreateInfo.vulkanApiVersion                = m_app->app_info().vulkan_api;
            allocatorCreateInfo.preferredLargeHeapBlockSize     = (VkDeviceSize) vci.chunk_size;
            vmaCreateAllocator(&allocatorCreateInfo, &m_allocator);


            return std::error_code();
        }
        
        void                        Visualizer::_dtor()
        {
            //  At *this* point, we don't need the mutex... we're dying anyways
            for(auto& psh : m_shaders.hash)
                _destroy(psh.second);
            for(auto& psh : m_shaders.loose)
                _destroy(psh);
            m_shaders.clear();
            
        
            if(m_allocator){
                vmaDestroyAllocator(m_allocator);
                m_allocator = nullptr;
            }
        
            //  Generally in reverse order of above
            if(m_device){
                vkDestroyDevice(m_device, nullptr);
                m_device                = nullptr;
            }
            m_graphic                   = {};
            m_present                   = {};
            m_compute                   = {};
            m_videoEncode               = {};
            m_videoDecode               = {};

            if(m_surface){
                vkDestroySurfaceKHR(m_instance, m_surface, nullptr);
                m_surface               = nullptr;
            }

            m_physical      = nullptr;
            m_instance      = nullptr;
            m_window        = nullptr;
            m_app           = nullptr;
        }
    
        std::error_code             Visualizer::init_visualizer(const ViewerCreateInfo& vci, GLFWwindow* w)
        {
            if(m_init)
                return std::error_code();
                
            std::error_code ec  = _ctor(vci, w);
            if(ec){
                _dtor();
                return ec;
            }
            
            m_init      = true;
            return std::error_code();

        }
        
        void                        Visualizer::kill_visualizer()
        {
            if(!m_init)
                return ;
            _dtor();
            m_init  = false;
        }

        Expect<ViShader>            Visualizer::_create(const Shader&sh)
        {
            ViShader        p;
            switch(sh.shader_type()){
            case ShaderType::VERT:
                p.mask = VK_SHADER_STAGE_VERTEX_BIT;
                break;
            case ShaderType::TESC:
                p.mask = VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT;
                break;
            case ShaderType::TESE:
                p.mask = VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT;
                break;
            case ShaderType::FRAG:
                p.mask = VK_SHADER_STAGE_FRAGMENT_BIT;
                break;
            case ShaderType::GEOM:
                p.mask = VK_SHADER_STAGE_GEOMETRY_BIT;
                break;
            case ShaderType::COMP:
                p.mask = VK_SHADER_STAGE_COMPUTE_BIT;
                break;
            default:
                return errors::shader_needs_type();
            }
                
            const ByteArray&    code    = sh.payload();
            VqShaderModuleCreateInfo createInfo;
            createInfo.codeSize = code.size();
            createInfo.pCode    = reinterpret_cast<const uint32_t*>(code.data());
            if (vkCreateShaderModule(m_device, &createInfo, nullptr, &p.shader) != VK_SUCCESS) 
                return errors::shader_creation_failure();
            return p;
        }
        
        void                        Visualizer::_destroy(ViShader&sh)
        {
            if(sh.shader)
                vkDestroyShaderModule(m_device, sh.shader, nullptr);
        }

        ////////////////////////////////////////////////////////////////////////////////
        //  GETTERS/INFORMATION

        RGBA4F Visualizer::clear_color() const
        {
            VkClearValue    cv  = m_clearValue;
            return { 
                cv.color.float32[0], cv.color.float32[1], 
                cv.color.float32[2], cv.color.float32[3] 
            };
        }

        VkQueue  Visualizer::compute_queue(uint32_t i) const
        {
            return m_compute[i];
        }
        
        uint32_t  Visualizer::compute_queue_count() const
        {
            return (uint32_t) m_compute.queues.size();
        }
        
        uint32_t  Visualizer::compute_queue_family() const
        {
            return m_compute.family;
        }

        bool    Visualizer::compute_queue_valid() const
        {
            return m_compute.valid();
        }

        std::string_view    Visualizer::gpu_name() const
        {
            return std::string_view(m_deviceInfo.deviceName, strnlen(m_deviceInfo.deviceName, VK_MAX_PHYSICAL_DEVICE_NAME_SIZE));
        }

        VkPhysicalDeviceType    Visualizer::gpu_type() const
        {
            return m_deviceInfo.deviceType;
        }


        VkQueue     Visualizer::graphic_queue(uint32_t i) const
        {
            return m_graphic[i];
        }
        
        uint32_t    Visualizer::graphic_queue_count() const
        {
            return (uint32_t) m_graphic.queues.size();
        }
        
        uint32_t    Visualizer::graphic_queue_family() const
        {
            return m_graphic.family;
        }
        
        bool        Visualizer::graphic_queue_valid() const
        {
            return m_graphic.valid();
        }

        uint32_t    Visualizer::max_memory_allocation_count() const  
        { 
            return m_deviceInfo.limits.maxMemoryAllocationCount; 
        }
        
        uint32_t    Visualizer::max_push_constants_size() const 
        { 
            return m_deviceInfo.limits.maxPushConstantsSize; 
        }
        
        uint32_t    Visualizer::max_viewports() const 
        { 
            return m_deviceInfo.limits.maxViewports; 
        }

        VkQueue      Visualizer::present_queue(uint32_t i) const
        {
            return m_present[i];
        }
        
        uint32_t     Visualizer::present_queue_count() const
        {
            return (uint32_t) m_present.queues.size();
        }
        
        uint32_t     Visualizer::present_queue_family() const
        {
            return m_present.family;
        }

        bool        Visualizer::present_queue_valid() const
        {
            return m_present.valid();
        }
        
        bool        Visualizer::supports_surface(VkFormat fmt) const
        {
            for(auto f : m_surfaceFormats)
                if(fmt == f.format)
                    return true;
            return false;
        }
        
        bool        Visualizer::supports_present(PresentMode pm) const
        {
            return m_presentModes.contains(pm);
        }

        VkSurfaceCapabilitiesKHR    Visualizer::surface_capabilities() const
        {
            VkSurfaceCapabilitiesKHR    ret;
            if(vkGetPhysicalDeviceSurfaceCapabilitiesKHR(m_physical, m_surface, &ret) != VK_SUCCESS)
                throw errors::no_surface_capabilities();
            return ret;
        }

        VkColorSpaceKHR Visualizer::surface_color_space(VkFormat fmt) const
        {
            for(auto& f : m_surfaceFormats)
                if(fmt == f.format)
                    return f.colorSpace;
            return VK_COLOR_SPACE_MAX_ENUM_KHR;
        }
        
        VkQueue   Visualizer::video_decode_queue(uint32_t i) const
        {
            return m_videoDecode[i];
        }
        
        uint32_t  Visualizer::video_decode_queue_count() const
        {
            return (uint32_t) m_videoDecode.queues.size();
        }
        
        uint32_t  Visualizer::video_decode_queue_family() const
        {
            return m_videoDecode.family;
        }

        bool        Visualizer::video_decode_queue_valid() const
        {
            return m_videoDecode.valid();
        }

        VkQueue   Visualizer::video_encode_queue(uint32_t i) const
        {
            return m_videoEncode[i];
        }
        
        uint32_t  Visualizer::video_encode_queue_count() const
        {
            return (uint32_t) m_videoEncode.queues.size();
        }

        uint32_t  Visualizer::video_encode_queue_family() const
        {
            return m_videoEncode.family;
        }

        bool        Visualizer::video_encode_queue_valid() const
        {
            return m_videoEncode.valid();
        }

        ////////////////////////////////////////////////////////////////////////////////
        //  SETTERS/MANIPULATORS

        ViShader    Visualizer::shader(uint64_t i) const
        {
            tbb::spin_rw_mutex::scoped_lock _lock(m_shaders.mutex, false);
            auto j = m_shaders.hash.find(i);
            if(j != m_shaders.hash.end())
                return j->second;
            return ViShader();
        }
        
        Expect<ViShader>    Visualizer::shader_create(Ref<const Shader> sh)
        {
            if(!sh)
                return errors::null_pointer();
                
            {
                tbb::spin_rw_mutex::scoped_lock _lock(m_shaders.mutex, false);
                auto j = m_shaders.hash.find(sh->id());
                if(j != m_shaders.hash.end())
                    return j->second;
            }
            
            auto xp     = _create(*sh);
            if(!xp)
                return xp;
            
            ViShader    ret;
            
            {
                tbb::spin_rw_mutex::scoped_lock _lock(m_shaders.mutex, true);
                auto [ j, f]    = m_shaders.hash.emplace(sh->id(), *xp);
                if(f) [[likely]]
                    return *xp;

                //  collision
                ret = j->second;
            }
            
            _destroy(*xp);
            return ret;
        }

        void        Visualizer::set_clear_color(const RGBA4F&i)
        {
            m_clearValue = VkClearValue{{{ i.red, i.green, i.blue, i.alpha }}};
        }

        void        Visualizer::set_present_mode(PresentMode pm)
        {
            if((pm != m_presentMode) && supports_present(pm)){
                m_presentMode   = pm;
                m_rebuildSwap   = true;
            }
        }

        void        Visualizer::trigger_rebuild()
        {
            m_rebuildSwap       = true;
        }

    }
}
