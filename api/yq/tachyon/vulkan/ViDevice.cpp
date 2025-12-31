////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>

#include <yq/tachyon/api/Thread.hpp>

#include <yq/tachyon/vulkan/ViBuffer.hpp>
#include <yq/tachyon/vulkan/ViDevice.hpp>
#include <yq/tachyon/vulkan/ViImage.hpp>
#include <yq/tachyon/vulkan/ViManager.hpp>
#include <yq/tachyon/vulkan/ViPipelineLayout.hpp>
#include <yq/tachyon/vulkan/ViQueueTasker.hpp>
#include <yq/tachyon/vulkan/ViSampler.hpp>
#include <yq/tachyon/vulkan/ViShader.hpp>
#include <yq/tachyon/vulkan/ViTexture.hpp>
#include <yq/tachyon/vulkan/VulqanCreateInfo.hpp>
#include <yq/tachyon/vulkan/VulqanManager.hpp>

#include <yq/tachyon/vulkan/VqUtils.hpp>

#include <yq/tachyon/pipeline/Buffer.hpp>
#include <yq/tachyon/pipeline/Pipeline.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/asset/Sampler.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/asset/Texture.hpp>


namespace yq::tachyon {

    static constexpr const uint32_t kMinGraphicsQueues = 2; // so we can push the image loading to separate queue
    
    static const char* kDeviceExtensions[] = {
        "VK_KHR_swapchain",
        "VK_EXT_extended_dynamic_state3"
        //"VK_KHR_swapchain_maintenance1"
    };
    
    namespace errors {
        using device_existing                   = error_db::entry<"Device already created">;
        using optical_flow_queue_not_found      = error_db::entry<"No optical flow queue found">;
    };

    bool    is_empty(const QueueSpec& qs)
    {
        if(std::get_if<std::monostate>(&qs) != nullptr)
            return true;
        if(std::get_if<optional_k>(&qs) != nullptr)
            return false;
        if(std::get_if<maximum_k>(&qs) != nullptr)
            return false;
        if(const std::vector<float>*p = std::get_if<std::vector<float>>(&qs))
            return p->empty();
        if(const uint32_t* p = std::get_if<uint32_t>(&qs))
            return *p == 0;
        if(const bool* p = std::get_if<bool>(&qs))
            return !*p;
        return true;
    }

    size_t  count(const QueueSpec& qs)
    {
        if( std::get_if<std::monostate>(&qs) != nullptr)
            return 0;
        if(std::get_if<optional_k>(&qs) != nullptr)
            return 1;
        if(const std::vector<float>*p = std::get_if<std::vector<float>>(&qs))
            return p->size();
        if(const uint32_t* p = std::get_if<uint32_t>(&qs))  
            return *p;
        if(const bool* p = std::get_if<bool>(&qs))
            return *p ? 1 : 0;
        return 0;
    }

    bool    is_required(const QueueSpec& qs)
    {
        if(std::get_if<std::monostate>(&qs) != nullptr)
            return false;
        if(std::get_if<optional_k>(&qs) != nullptr)
            return false;
        if(const std::vector<float>*p = std::get_if<std::vector<float>>(&qs))
            return !p->empty();
        if(const uint32_t* p = std::get_if<uint32_t>(&qs))
            return *p != 0;
        if(const bool* p = std::get_if<bool>(&qs))
            return *p;
        return false;
    }
    
    
    struct ViDevice::QueueFamily {
        VkQueueFamilyProperties             props;
        std::vector<float>                  weights;
        std::vector<VkQueue>                queues;
        ViQueueFamilyID                     family;
        uint32_t                            count   = 0;
        mutable std::map<ThreadID,size_t>   byThread;
        mutable BitArray<uint64_t,2>        queueAlloc;
        //mutable mutex_t                     mutex;

        struct Extra {
            uint32_t    min;
            uint32_t    pre;
        };

        //  fences...
        //  taskers...
        
        void    configure(const QueueSpec& spec, const Extra& extra=Extra{})
        {
            if(std::get_if<maximum_k>(&spec)){
                weights.resize(props.queueCount, 1.);
            } else {
                for(uint32_t i=0;i<extra.pre;++i)
                    weights.push_back(1.);
                if(const std::vector<float>*p = std::get_if<std::vector<float>>(&spec)){
                    if(!p->empty())
                        weights.insert(weights.end(), p->begin(), p->end());
                }
                if(const uint32_t* p = std::get_if<uint32_t>(&spec)){
                    for(uint32_t i=0;i<*p;++i)
                        weights.push_back(1.);
                }
                if(std::get_if<uint32_t>(&spec))
                    weights.push_back(1.);
                if(std::get_if<optional_k>(&spec))
                    weights.push_back(1.);
                while(weights.size() < extra.min + extra.pre)
                    weights.push_back(1.);
            }
            count   = (uint32_t) weights.size();
            queues.resize(count, nullptr);
            //fences.resize(count, nullptr);
        }
        
    };

    //ViDevice::ViDevice(VkDevice)
    //{
    //}
    //}
    
    ViDevice::ViDevice(VkPhysicalDevice pDev, const VulqanCreateInfo&vci)
    {
        if(pDev){
            std::error_code ec  = _init(pDev, vci);
            if(ec != std::error_code())
                _kill();
        }
    }
    
    ViDevice::~ViDevice()
    {
        _kill();
    }

    const ViDevice::QueueFamily*  ViDevice::_family(ViQueueFamilyID vqf) const
    {
        if(vqf.index >= m_queueFamilies.size())
            return nullptr;
        return &m_queueFamilies[vqf.index];
    }
    
    ViDevice::QueueFamily*        ViDevice::_family(ViQueueFamilyID vqf)
    {
        if(vqf.index >= m_queueFamilies.size())
            return nullptr;
        return &m_queueFamilies[vqf.index];
    }
    
    std::error_code     ViDevice::_init(VkPhysicalDevice pDev, const VulqanCreateInfo& vci)
    {
    
        // ---------------
        // GET PROPERTIES
    
        m_physical                          = pDev;
        VqPhysicalDeviceProperties2         prop2;
        VqPhysicalDeviceMultiviewProperties multiProp;

        if(vci.multiview){
            m_multiview.enabled  = true;
            prop2.pNext     = &multiProp;
        }

        vkGetPhysicalDeviceProperties2(m_physical, &prop2);
    
        if(vci.multiview){
            m_multiview.maxViewCount        = multiProp.maxMultiviewViewCount;
            m_multiview.maxInstanceIndex    = multiProp.maxMultiviewInstanceIndex;
        }
        
        m_gpuProperties = prop2.properties;

        vizInfo << "ViDevice(" << gpu_name() << "): Creating device";

        if(vci.api && (m_gpuProperties.apiVersion < vci.api)){
            vizWarning << "ViDevice(" << gpu_name() << "): Target API version mismatch, not everything will be supported";
        }

        vkGetPhysicalDeviceMemoryProperties(pDev, &m_gpuMemory);

        // ---------------
        // SORT THE QUEUES

        auto    queues  = vqGetPhysicalDeviceQueueFamilyProperties(pDev);
        m_queueFamilies.resize(queues.size());
        
        std::vector<ViQueueFamilyID>            queueFamilies;
        
        bool    wantGraphic     = (!vci.headless) || !is_empty(vci.graphics);
        bool    wantCompute     = !is_empty(vci.compute);
        bool    wantTransfer    = !is_empty(vci.transfer);
        bool    wantVEncode     = !is_empty(vci.video_encode);
        bool    wantVDecode     = !is_empty(vci.video_decode);
        bool    wantOptical     = !is_empty(vci.optical_flow);
        
        bool    hasGraphic      = false;
        bool    hasCompute      = false;
        bool    hasTransfer     = false;
        bool    hasVEncode      = false;
        bool    hasVDecode      = false;
        bool    hasOptical      = false;
        
        for(size_t i=0;i<queues.size();++i){
            QueueFamily& Q  = m_queueFamilies[i];
            Q.family    = { (uint32_t) i };
            Q.props     = queues[i];
            
            bool    isGraphic   = static_cast<bool>(Q.props.queueFlags & VK_QUEUE_GRAPHICS_BIT);
            bool    isCompute   = static_cast<bool>(Q.props.queueFlags & VK_QUEUE_COMPUTE_BIT);
            bool    isTransfer  = static_cast<bool>(Q.props.queueFlags & VK_QUEUE_TRANSFER_BIT);
            bool    isOptical   = static_cast<bool>(Q.props.queueFlags & VK_QUEUE_OPTICAL_FLOW_BIT_NV);
            bool    isVEncode   = static_cast<bool>(Q.props.queueFlags & VK_QUEUE_VIDEO_ENCODE_BIT_KHR);
            bool    isVDecode   = static_cast<bool>(Q.props.queueFlags & VK_QUEUE_VIDEO_DECODE_BIT_KHR);
            
            if(wantGraphic && isGraphic){
                ViQueueFamilyID &graphicQueue = m_queueType2Family[ViQueueType::Graphic];
                if(graphicQueue.invalid()){
                    graphicQueue   = Q.family;
                    Q.configure(vci.graphics, {.min=1, .pre=1});
                    queueFamilies.push_back(Q.family);
                    hasGraphic  = true;
                }
            }

            if(wantCompute && isCompute && (!isGraphic)){
                ViQueueFamilyID& computeQueue    = m_queueType2Family[ViQueueType::Compute];
                if(computeQueue.invalid()){
                    computeQueue    = Q.family;
                    Q.configure(vci.compute);
                    queueFamilies.push_back(Q.family);
                    hasCompute  = true;
                }
            }
            
            if(wantTransfer && isTransfer && !isGraphic && !isCompute && !isOptical && !isVEncode && !isVDecode){
                ViQueueFamilyID& transferQueue  = m_queueType2Family[ViQueueType::Transfer];
                if(transferQueue.invalid()){
                    transferQueue   = Q.family;
                    Q.configure(vci.transfer);
                    queueFamilies.push_back(Q.family);
                    hasTransfer = true;
                }
            }
            
            if(wantVEncode && isVEncode){
                ViQueueFamilyID& videoEncodeQueue = m_queueType2Family[ViQueueType::Transfer];
                if(videoEncodeQueue.invalid()){
                    videoEncodeQueue = Q.family;
                    Q.configure(vci.video_encode);
                    queueFamilies.push_back(Q.family);
                    hasVEncode  = true;
                }
            }

            if(wantVDecode && isVDecode){
                ViQueueFamilyID& videoEncodeQueue = m_queueType2Family[ViQueueType::Transfer];
                if(videoEncodeQueue.invalid()){
                    videoEncodeQueue = Q.family;
                    Q.configure(vci.video_encode);
                    queueFamilies.push_back(Q.family);
                    hasVDecode  = true;
                }
            }
            
            if(wantOptical && isOptical){
                ViQueueFamilyID& opticalQueue = m_queueType2Family[ViQueueType::OpticalFlow];
                if(opticalQueue.invalid()){
                    opticalQueue = Q.family;
                    Q.configure(vci.optical_flow);
                    queueFamilies.push_back(Q.family);
                    hasOptical  = true;
                }
            }
        }
    
        if(wantGraphic && !hasGraphic){
            vizError << "ViDevice(" << gpu_name() << "): Cannot find graphics queue";
            return errors::graphics_queue_not_found();
        }

        if(wantCompute && !hasCompute){
            if(is_required(vci.compute)){
                vizError << "ViDevice(" << gpu_name() << "): Cannot find compute queue";
                return errors::compute_queue_not_found();
            }
            if(!hasGraphic){
                vizError << "ViDevice(" << gpu_name() << "): Cannot find compute queue (nor is graphics available)";
                return errors::compute_queue_not_found();
            }
            if(!is_queue_compute(m_queueType2Family[ViQueueType::Graphic])){
                vizError << "ViDevice(" << gpu_name() << "): Cannot find compute queue (nor does graphics support it)";
                return errors::compute_queue_not_found();
            }
            m_queueType2Family[ViQueueType::Compute] = m_queueType2Family[ViQueueType::Graphic];
            vizNotice << "ViDevice(" << gpu_name() << "): Cannot find dedicated compute queue, using graphics queue";
        }
        
        if(!hasTransfer){
            if(wantTransfer){
                if(is_required(vci.transfer)){
                    vizError << "ViDevice(" << gpu_name() << "): Cannot find dedicated transfer queue";
                    return errors::transfer_queue_not_found();
                } else {
                    vizNotice << "ViDevice(" << gpu_name() << "): Cannot find dedicated transfer queue";
                }
            }
        }
        
        if(wantOptical && !hasOptical){
            if(is_required(vci.optical_flow)){
                vizError << "ViDevice(" << gpu_name() << "): Cannot find optical flow queue";
                return errors::optical_flow_queue_not_found();
            } else {
                vizNotice << "ViDevice(" << gpu_name() << "): Cannot find optical flow queue";
            }
        }
        
        if(wantVDecode && !hasVDecode){
            if(is_required(vci.video_decode)){
                vizError << "ViDevice(" << gpu_name() << "): Cannot find video decode queue";
                return errors::video_decode_queue_not_found();
            } else {
                vizNotice << "ViDevice(" << gpu_name() << "): Cannot find video decode queue";
            }
        }
        
        if(wantVEncode && !hasVEncode){
            if(is_required(vci.video_encode)){
                vizError << "ViDevice(" << gpu_name() << "): Cannot find video encode queue";
                return errors::video_encode_queue_not_found();
            } else {
                vizNotice << "ViDevice(" << gpu_name() << "): Cannot find video encode queue";
            }
        }

        std::vector<VkDeviceQueueCreateInfo>    queueCreateInfos;
        for(auto qi : queueFamilies){
            const QueueFamily& qf   = *_family(qi);
        
            VqDeviceQueueCreateInfo dqci;
            dqci.queueFamilyIndex       = qi.index;
            dqci.queueCount             = (uint32_t) qf.weights.size();
            dqci.pQueuePriorities       = qf.weights.data();
            queueCreateInfos.push_back(dqci);
        }


        // --------------------------
        // FEATURES & DEVICE CREATION

        VqDeviceCreateInfo                  deviceCreateInfo;
        VkPhysicalDeviceFeatures            v10features{};
        VqPhysicalDeviceVulkan11Features    v11features;
        VqPhysicalDeviceVulkan12Features    v12features;
        VqPhysicalDeviceVulkan13Features    v13features;
        VqPhysicalDeviceVulkan14Features    v14features;

        deviceCreateInfo.pNext                  = &v11features;
        v11features.pNext                       = &v12features;
        v12features.pNext                       = &v13features;
        v13features.pNext                       = &v14features;
        
        VqPhysicalDeviceFeatures2   v10features2;
        v10features2.pNext   = &v11features;
        
        vkGetPhysicalDeviceFeatures2(pDev, &v10features2);
        v10features = v10features2.features;
        m_gpuFeatures   = v10features;
        if(vci.fill_non_solid && !v10features.fillModeNonSolid)
            vizWarning << "ViDevice(" << gpu_name() << "): GPU is unable to support fill mode non-solid!";
        if(!v10features.samplerAnisotropy)
            vizWarning << "ViDevice(" << gpu_name() << "): GPU is unable to handle sampler anistropy";
        if(!v12features.bufferDeviceAddress)
            vizWarning << "ViDevice(" << gpu_name() << "): GPU cannot handle buffer device addresses";
        if(!v12features.samplerMirrorClampToEdge)
            vizWarning << "ViDevice(" << gpu_name() << "): GPU samplers cannot handle samplers with mirror-clamp-to-edge mode";
        if(!v13features.dynamicRendering)
            vizWarning << "ViDevice(" << gpu_name() << "): GPU cannot handle dynamic rendering";
            
        v10features.fragmentStoresAndAtomics    = VK_TRUE;
        
        deviceCreateInfo.pQueueCreateInfos        = queueCreateInfos.data();
        deviceCreateInfo.queueCreateInfoCount     = (uint32_t) queueCreateInfos.size();
        deviceCreateInfo.pEnabledFeatures         = &v10features;
        
        std::vector<const char*>    extensions;
        for(const char* sz : kDeviceExtensions)
            extensions.push_back(sz);

        deviceCreateInfo.enabledExtensionCount      = extensions.size();
        deviceCreateInfo.ppEnabledExtensionNames    = extensions.data();

        VkResult        res = vkCreateDevice(m_physical, &deviceCreateInfo, nullptr, &m_device);
        if(res != VK_SUCCESS){
            vizError << "ViDevice(" << gpu_name() << "): Unable to create vulkan (logical) device with result code: " << (int32_t) res;
            return errors::vulkan_device_cant_create();
        }
        
        // ----------------
        // MEMORY ALLOCATOR
            
        VmaAllocatorCreateInfo      allocatorCreateInfo{};
        allocatorCreateInfo.instance                        = VulqanManager::instance();
        allocatorCreateInfo.physicalDevice                  = m_physical;
        allocatorCreateInfo.device                          = m_device;
        allocatorCreateInfo.vulkanApiVersion                = VulqanManager::vulkan_api();
        allocatorCreateInfo.preferredLargeHeapBlockSize     = (VkDeviceSize) vci.chunk_size;
        vmaCreateAllocator(&allocatorCreateInfo, &m_allocator);
        
        // --------------
        // GET THE QUEUES

        for(QueueFamily& Q : m_queueFamilies){
            if(!Q.count)
                continue;
            for(uint32_t j=0;j<Q.queues.size();++j)
                vkGetDeviceQueue(m_device, Q.family.index, j, &Q.queues[j]);
        }
        
        // --------------
        //  MANAGERS
        
        m_buffers           = std::make_unique<ViBufferManager>(*this);
        m_shaders           = std::make_unique<ViShaderManager>(*this);
        m_samplers          = std::make_unique<ViSamplerManager>(*this);
        m_images            = std::make_unique<ViImageManager>(*this);
        m_textures          = std::make_unique<ViTextureManager>(*this);
        m_pipelineLayouts   = std::make_unique<ViPipelineLayoutManager>(*this);

        // --------------
        // EVENTUALLY DO MORE....
        
        m_headlessQueue     = ViQueueID(queue_family(ViQueueType::Graphic), 0);
        
        return {};
    }

    void            ViDevice::_kill()
    {
        m_pipelineLayouts   = {};
        m_textures          = {};
        m_samplers          = {};
        m_images            = {};
        m_shaders           = {};
        m_buffers           = {};
        m_taskers.clear();
    
        cleanup(SWEEP);
        if(m_allocator){
            vmaDestroyAllocator(m_allocator);
            m_allocator = nullptr;
        }
        if(m_device){
            vkDeviceWaitIdle(m_device);
            vkDestroyDevice(m_device, nullptr);
            m_device    = nullptr;
        }
        m_physical      = nullptr;
    }
        
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    ViBufferCPtr ViDevice::buffer(uint64_t i) const
    {
        if(!m_buffers)
            return {};
        return m_buffers->get(i);
    }

    ViBufferCPtr  ViDevice::buffer_create(const Buffer& buf)
    {
        if(!m_buffers)
            return {};
        return m_buffers->create(buf);
    }
    
    void  ViDevice::buffer_erase(uint64_t i)
    {
        if(m_buffers){
            m_buffers -> erase(i);
        }
    }
    
    void  ViDevice::buffer_erase(const Buffer& buf)
    {
        buffer_erase(buf.id());
    }

/*
    ViBufferManager* ViDevice::buffer_manager() const 
    { 
        return m_buffers.get(); 
    }
*/

    void            ViDevice::cleanup(cleanup_fn&& fn)
    {
        m_cleanup.add(std::move(fn));
    }

    void            ViDevice::cleanup(sweep_k)
    {
        m_cleanup.sweep();
    }

    void            ViDevice::destroy()
    {
        _kill();
    }

    ViQueueID           ViDevice::graphics_queue(uint32_t viewerId) const
    {
        const QueueFamily*  qf  = _family(queue_family(ViQueueType::Graphic));
        if(!qf)
            return ViQueueID();
        uint32_t    N   = qf->count - 1;
        return ViQueueID( qf->family, 1+(viewerId%N));
    }

    std::string_view    ViDevice::gpu_name() const
    {
        return std::string_view(m_gpuProperties.deviceName);
    }

    VkPhysicalDeviceType    ViDevice::gpu_type() const
    {
        return m_gpuProperties.deviceType;
    }

    bool    ViDevice::has_queue(ViQueueType qt) const
    {   
        return m_queueType2Family.contains(qt);
    }


    ViImageCPtr     ViDevice::image(uint64_t i) const
    {
        if(!m_images)
            return {};
        return m_images -> get(i);
    }
    
    ViImageCPtr     ViDevice::image_create(const Raster& img)
    {
        if(!m_images)
            return {};
        return m_images -> create(img);
    }
    
    void  ViDevice::image_erase(uint64_t i)
    {
        if(m_images){
            m_images -> erase(i);
        }
    }
    
    void  ViDevice::image_erase(const Raster& img)
    {
        image_erase(img.id());
    }

    Expect<RasterPtr>       ViDevice::image_export(VkImage img, const VkExtent2D&size, VkFormat fmt)
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
    
    Expect<RasterPtr>       ViDevice::image_export(VkImage img, const VkExtent3D&size, VkFormat fmt)
    {
        return export_image(*this, img, ViImageExport{
            .type       = VK_IMAGE_TYPE_3D,
            .format     = fmt,
            .extent     = size
        });
    }

#if 0
    ViImageManager* ViDevice::image_manager() const
    {
        return m_images.get();
    }
#endif
        
    std::error_code     ViDevice::init(VkPhysicalDevice pDev, const VulqanCreateInfo& vci)
    {
        if(m_device)
            return errors::device_existing();
        std::error_code    ec  = _init(pDev, vci);
        if(ec != std::error_code())
            _kill();
        return ec;
    }

    bool    ViDevice::is_queue_compute(ViQueueFamilyID family) const
    {
        return static_cast<bool>(queue_family_flags(family) & VK_QUEUE_COMPUTE_BIT);
    }
    
    bool    ViDevice::is_queue_graphic(ViQueueFamilyID family) const
    {
        return static_cast<bool>(queue_family_flags(family) & VK_QUEUE_GRAPHICS_BIT);
    }
    
    bool    ViDevice::is_queue_optical(ViQueueFamilyID family) const
    {
        return static_cast<bool>(queue_family_flags(family) & VK_QUEUE_OPTICAL_FLOW_BIT_NV);
    }

    bool    ViDevice::is_queue_present_supported(ViQueueFamilyID family, VkSurfaceKHR surf) const
    {
        if(!m_physical)
            return false;
        if(!surf)
            return false;
        const QueueFamily*  qf = _family(family);
        if(!qf)
            return false;
        if(!qf->count)
            return false;
            
        VkBool32    support;
        vkGetPhysicalDeviceSurfaceSupportKHR(m_physical, family.index, surf, &support);
        return static_cast<bool>(support);
    }
    
    bool    ViDevice::is_queue_sparse_binding(ViQueueFamilyID family) const
    {
        return static_cast<bool>(queue_family_flags(family) & VK_QUEUE_SPARSE_BINDING_BIT);
    }
    
    bool    ViDevice::is_queue_transfer(ViQueueFamilyID family) const
    {
        return static_cast<bool>(queue_family_flags(family) & VK_QUEUE_COMPUTE_BIT);
    }
    
    bool    ViDevice::is_queue_valid(ViQueueID qid) const
    {
        const QueueFamily* qf = _family(qid.family);
        if(!qf) 
            return false;
        return qid.sub < qf->count;
    }

    bool    ViDevice::is_queue_video_decode(ViQueueFamilyID family) const
    {
        return static_cast<bool>(queue_family_flags(family) & VK_QUEUE_VIDEO_DECODE_BIT_KHR);
    }
    
    bool    ViDevice::is_queue_video_encode(ViQueueFamilyID family) const
    {
        return static_cast<bool>(queue_family_flags(family) & VK_QUEUE_VIDEO_ENCODE_BIT_KHR);
    }

    uint32_t        ViDevice::max_memory_allocation_count() const
    {
        return m_gpuProperties.limits.maxMemoryAllocationCount; 
    }
    
    uint32_t        ViDevice::max_push_constants_size() const
    {
        return m_gpuProperties.limits.maxPushConstantsSize; 
    }
    
    float           ViDevice::max_sampler_anisotropy() const
    {
        return m_gpuProperties.limits.maxSamplerAnisotropy;
    }
    
    uint32_t        ViDevice::max_viewports() const
    {
        return m_gpuProperties.limits.maxViewports; 
    }

    bool    ViDevice::multiview_enabled() const
    {
        return m_multiview.enabled;
    }
    
    uint32_t    ViDevice::multiview_max_instance_index() const
    {
        return m_multiview.maxInstanceIndex;
    }
    
    uint32_t    ViDevice::multiview_max_view_count() const
    {
        return m_multiview.maxViewCount;
    }


    ViPipelineLayoutCPtr            ViDevice::pipeline_layout(uint64_t i) const
    {
        if(!m_pipelineLayouts)
            return {};
        return m_pipelineLayouts -> get(i);
    }
    
    ViPipelineLayoutCPtr            ViDevice::pipeline_layout_create(const Pipeline* pipe)
    {
        if(!m_pipelineLayouts)
            return {};
        if(!pipe)
            return {};
        return m_pipelineLayouts -> create(pipe);
    }
    
    void                            ViDevice::pipeline_layout_erase(uint64_t i)
    {
        if(m_pipelineLayouts){
            m_pipelineLayouts -> erase(i);
        }
    }
    
    void                            ViDevice::pipeline_layout_erase(const Pipeline* pipe)
    {
        if(pipe){
            pipeline_layout_erase(pipe->id());
        }
    }
    
    #if 0
    ViPipelineLayoutManager*        ViDevice::pipeline_layout_manager() const
    {
        return m_pipelineLayouts.get();
    }
    #endif
    
    VkQueue         ViDevice::queue(ViQueueFamilyID family, uint32_t subIdx) const
    {
        const QueueFamily*  qf  = _family(family);
        if(!qf)
            return nullptr;
        if(subIdx >= qf->count)
            return nullptr;
        return qf->queues[subIdx];
    }

    VkQueue         ViDevice::queue(const ViQueueID&qid) const
    {
        return queue(qid.family, qid.sub);
    }

    VkQueue         ViDevice::queue(ViQueueType qType) const
    {
        return queue(queue_id(qType));
    }

            
    VkQueue ViDevice::ViDevice::queue(ViQueueType qType, ThreadID th) const
    {
        return queue(queue_id(qType, th));
    }

    VkQueue         ViDevice::queue(ViQueueFamilyID fam) const
    {
        return queue(queue_id(fam));
    }

    
    VkQueue     ViDevice::queue(ViQueueFamilyID fam, ThreadID th) const
    {
        return queue(queue_id(fam, th));
    }

    uint32_t        ViDevice::queue_count(ViQueueFamilyID family) const
    {
        const QueueFamily*  qf  = _family(family);
        if(!qf)
            return 0;
        return qf->count;
    }

    ViQueueFamilyID       ViDevice::queue_family(ViQueueType qt) const
    {
        auto i = m_queueType2Family.find(qt);
        if(i != m_queueType2Family.end())  [[likely]]
            return i->second;
        return ViQueueFamilyID();
    }

    uint32_t        ViDevice::queue_family_count() const
    {
        return (uint32_t) m_queueFamilies.size();
    }

    VkQueueFlags    ViDevice::queue_family_flags(ViQueueFamilyID family) const
    {
        const QueueFamily*  qf  = _family(family);
        if(!qf)
            return {};
        return qf->props.queueFlags;
    }

    ViQueueID   ViDevice::queue_id(ViQueueFamilyID fam) const
    {
        return queue_id(fam, Thread::current_id());
    }
    
    ViQueueID   ViDevice::queue_id(ViQueueFamilyID fam, ThreadID th) const
    {
        if(!th)
            return ViQueueID();
        const QueueFamily*  qf  = _family(fam);
        if(!qf)
            return ViQueueID();
            
        lock_t  _lock(m_queueMutex, false);
        if(auto i = qf->byThread.find(th); i != qf->byThread.end())
            return { .family=fam, .sub = (uint32_t) i->second };
    
        size_t  n;  
        for(n=qf->byThread.size();qf->queueAlloc[n];++n)
            ;
            
        if(n >= qf->queues.size()){
            vizFirstAlert(fam.index) << "ViDevice::Queue.  Limit exceeded, increase queue count for family " << fam.index;
            return ViQueueID();
        }
        
        if(!_lock.upgrade_to_writer()){
            // lost the lock, so repeat the search
            for(;qf->queueAlloc[n];++n)
                ;
        }
        
        qf->byThread[th]   = n;
        qf->queueAlloc.set(n);
        return { .family=fam, .sub = (uint32_t) n };
    }
    
    ViQueueID   ViDevice::queue_id(ViQueueType qType) const
    {
        return queue_id(queue_family(qType), Thread::current_id());
    }
    
    ViQueueID   ViDevice::queue_id(ViQueueType qType, ThreadID th) const
    {
        return queue_id(queue_family(qType), th);
    }

    std::error_code     ViDevice::queue_task(ViQueueID qid, queue_tasker_fn&& fn)
    {
        return queue_task(qid, DEFAULT_WAIT_TIMEOUT, std::move(fn));
    }
    
    std::error_code     ViDevice::queue_task(ViQueueID qid, uint64_t timeout, queue_tasker_fn&&fn)
    {
        ViQueueTaskerPtr    tasker  = queue_tasker(qid);
        if(!tasker)
            return create_error<"ViDevice::queue_task(): Invalid tasker queue">();
        return tasker->execute(timeout, std::move(fn));
    }

    std::error_code     ViDevice::queue_task(ViQueueFamilyID fam, queue_tasker_fn&& fn)
    {
        return queue_task(queue_id(fam), std::move(fn));
    }

    std::error_code     ViDevice::queue_task(ViQueueFamilyID fam, uint64_t timeout, queue_tasker_fn&& fn)
    {
        return queue_task(queue_id(fam), timeout, std::move(fn));
    }

    std::error_code     ViDevice::queue_task(ViQueueType qType, queue_tasker_fn&& fn)
    {
        return queue_task(queue_id(qType), std::move(fn));
    }

    std::error_code     ViDevice::queue_task(ViQueueType qType, uint64_t timeout, queue_tasker_fn&& fn)
    {
        return queue_task(queue_id(qType), timeout, std::move(fn));
    }

    ViQueueTaskerPtr    ViDevice::queue_tasker(ViQueueID qid)
    {
        {
            lock_t  _lock(m_taskerMutex, false);
            auto i = m_taskers.find(qid);
            if(i != m_taskers.end())
                return i->second;
        }
        
        if(!is_queue_valid(qid))
            return {};
        
        ViQueueTaskerPtr    ret;
        ViQueueTaskerPtr    p   = new ViQueueTasker(*this, qid);
        
        {
            lock_t  _lock(m_taskerMutex, true);
            auto [i,f] = m_taskers.insert({ qid, p });
            if(f)
                return p;
            ret = i->second;
        }
        
        return ret;
    }


    ViSamplerCPtr     ViDevice::sampler(uint64_t i) const
    {
        if(!m_samplers)
            return {};
        return m_samplers -> get(i);
    }
    
    ViSamplerCPtr     ViDevice::sampler_create(const Sampler& sam)
    {
        if(!m_samplers)
            return {};
        return m_samplers -> create(sam);
    }
    
    void  ViDevice::sampler_erase(uint64_t i)
    {
        if(m_samplers){
            m_samplers -> erase(i);
        }
    }
    
    void  ViDevice::sampler_erase(const Sampler& sam)
    {
        sampler_erase(sam.id());
    }

#if 0
    ViSamplerManager* ViDevice::sampler_manager() const
    {
        return m_samplers.get();
    }
#endif
    
    ViShaderCPtr ViDevice::shader(uint64_t i) const
    {
        if(!m_shaders)
            return {};
        return m_shaders -> get(i);
    }

    ViShaderCPtr    ViDevice::shader_create(const Shader&sha)
    {
        if(!m_shaders)
            return {};
        return m_shaders->create(sha);
    }

    void  ViDevice::shader_erase(uint64_t i)
    {
        if(m_shaders){
            m_shaders -> erase(i);
        }
    }
    
    void  ViDevice::shader_erase(const Shader& sha)
    {
        shader_erase(sha.id());
    }

#if 0
    ViShaderManager*  ViDevice::shader_manager() const 
    { 
        return m_shaders.get(); 
    }
#endif


    ViTextureCPtr ViDevice::texture(uint64_t i) const
    {
        if(!m_textures)
            return {};
        return m_textures->get(i);
    }

    ViTextureCPtr  ViDevice::texture_create(const Texture& tex)
    {
        if(!m_textures)
            return {};
        return m_textures->create(tex);
    }
    
    void  ViDevice::texture_erase(uint64_t i)
    {
        if(m_textures){
            m_textures -> erase(i);
        }
    }
    
    void  ViDevice::texture_erase(const Texture& tex)
    {
        texture_erase(tex.id());
    }

#if 0
    ViTextureManager* ViDevice::texture_manager() const 
    { 
        return m_textures.get(); 
    }
#endif

    bool    ViDevice::valid() const
    {   
        return m_physical && m_device && m_allocator;
    }

    std::error_code     ViDevice::wait_idle() const
    {
        if(!m_device)
            return create_error<"null device">();

        switch(vkDeviceWaitIdle(m_device)){
        case VK_SUCCESS:
            return {};
        case VK_ERROR_OUT_OF_HOST_MEMORY:
            return create_error<"out of host memory">();
        case VK_ERROR_OUT_OF_DEVICE_MEMORY:
            return create_error<"out of device memory">();
        case VK_ERROR_DEVICE_LOST:
            return create_error<"device lost">();
        default:
            return create_error<"device wait failed">();
        }
    }

}
