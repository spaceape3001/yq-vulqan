////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yv/ViDevice.hpp>
#include <yv/VqUtils.hpp>
#include <yv/VulqanCreateInfo.hpp>
#include <yv/VulqanManager.hpp>
#include <yt/errors.hpp>
#include <yt/logging.hpp>

namespace yq::tachyon {

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
        VkQueueFamilyProperties     props;
        std::vector<float>          weights;
        std::vector<VkQueue>        queues;
        //std::vector<VkFence>        fences;
        //std::vector<void*>          taskers;
        uint32_t                    count   = 0;

        //  fences...
        //  taskers...
        
        void    configure(const QueueSpec& spec)
        {
            if(const std::vector<float>*p = std::get_if<std::vector<float>>(&spec)){
                if(!p->empty())
                    weights   = *p;
            }
            if(const uint32_t* p = std::get_if<uint32_t>(&spec))
                weights.resize(*p, 1.);
            if(weights.empty())
                weights.push_back(1.);
            count   = (uint32_t) weights.size();
            queues.resize(count, nullptr);
            //fences.resize(count, nullptr);
            //taskers.resize(count, nullptr);
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

        if(vci.api && (m_gpuProperties.apiVersion < vci.api)){
            vizWarning << "ViDevice(" << gpu_name() << "): Target API version mismatch, not everything will be supported";
        }

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
            Q.props = queues[i];
            
            bool    isGraphic   = static_cast<bool>(Q.props.queueFlags & VK_QUEUE_GRAPHICS_BIT);
            bool    isCompute   = static_cast<bool>(Q.props.queueFlags & VK_QUEUE_COMPUTE_BIT);
            bool    isTransfer  = static_cast<bool>(Q.props.queueFlags & VK_QUEUE_TRANSFER_BIT);
            bool    isOptical   = static_cast<bool>(Q.props.queueFlags & VK_QUEUE_OPTICAL_FLOW_BIT_NV);
            bool    isVEncode   = static_cast<bool>(Q.props.queueFlags & VK_QUEUE_VIDEO_ENCODE_BIT_KHR);
            bool    isVDecode   = static_cast<bool>(Q.props.queueFlags & VK_QUEUE_VIDEO_DECODE_BIT_KHR);
            
            if(wantGraphic && isGraphic){
                ViQueueFamilyID &graphicQueue = m_queueType2Family[ViQueueType::Graphic];
                if(graphicQueue.invalid()){
                    graphicQueue   = { (uint32_t) i };
                    Q.configure(vci.graphics);
                    queueFamilies.push_back(graphicQueue);
                    hasGraphic  = true;
                }
            }

            if(wantCompute && isCompute && (!isGraphic)){
                ViQueueFamilyID& computeQueue    = m_queueType2Family[ViQueueType::Compute];
                if(computeQueue.invalid()){
                    computeQueue    = { (uint32_t) i };
                    Q.configure(vci.compute);
                    queueFamilies.push_back(computeQueue);
                    hasCompute  = true;
                }
            }
            
            if(wantTransfer && isTransfer && !isGraphic && !isCompute && !isOptical && !isVEncode && !isVDecode){
                ViQueueFamilyID& transferQueue  = m_queueType2Family[ViQueueType::Transfer];
                if(transferQueue.invalid()){
                    transferQueue   = { (uint32_t) i };
                    Q.configure(vci.transfer);
                    queueFamilies.push_back(transferQueue);
                    hasTransfer = true;
                }
            }
            
            if(wantVEncode && isVEncode){
                ViQueueFamilyID& videoEncodeQueue = m_queueType2Family[ViQueueType::Transfer];
                if(videoEncodeQueue.invalid()){
                    videoEncodeQueue = { (uint32_t) i };
                    Q.configure(vci.video_encode);
                    queueFamilies.push_back(videoEncodeQueue);
                    hasVEncode  = true;
                }
            }

            if(wantVDecode && isVDecode){
                ViQueueFamilyID& videoEncodeQueue = m_queueType2Family[ViQueueType::Transfer];
                if(videoEncodeQueue.invalid()){
                    videoEncodeQueue = { (uint32_t) i };
                    Q.configure(vci.video_encode);
                    queueFamilies.push_back(videoEncodeQueue);
                    hasVDecode  = true;
                }
            }
            
            if(wantOptical && isOptical){
                ViQueueFamilyID& opticalQueue = m_queueType2Family[ViQueueType::OpticalFlow];
                if(opticalQueue.invalid()){
                    opticalQueue = { (uint32_t) i };
                    Q.configure(vci.optical_flow);
                    queueFamilies.push_back(opticalQueue);
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
            
        
        deviceCreateInfo.pQueueCreateInfos        = queueCreateInfos.data();
        deviceCreateInfo.queueCreateInfoCount     = (uint32_t) queueCreateInfos.size();
        deviceCreateInfo.pEnabledFeatures         = &v10features;

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

        for(size_t i=0;i<m_queueFamilies.size();++i){
            QueueFamily& Q  = m_queueFamilies[i];   // need the index, hence this way
            if(!Q.count)
                continue;
            for(uint32_t j=0;j<Q.queues.size();++j)
                vkGetDeviceQueue(m_device, i, j, &Q.queues[j]);
        }
        
        // --------------
        // EVENTUALLY DO MORE....
        
        return {};
    }

    void            ViDevice::_kill()
    {
        if(m_allocator){
            vmaDestroyAllocator(m_allocator);
            m_allocator = nullptr;
        }
        if(m_device){
            vkDestroyDevice(m_device, nullptr);
            m_device    = nullptr;
        }
        m_physical      = nullptr;
    }
        
    void            ViDevice::cleanup()
    {
    }

    std::string_view    ViDevice::gpu_name() const
    {
        return std::string_view(m_gpuProperties.deviceName);
    }
    
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
    
    bool    ViDevice::is_queue_sparse_binding(ViQueueFamilyID family) const
    {
        return static_cast<bool>(queue_family_flags(family) & VK_QUEUE_SPARSE_BINDING_BIT);
    }
    
    bool    ViDevice::is_queue_transfer(ViQueueFamilyID family) const
    {
        return static_cast<bool>(queue_family_flags(family) & VK_QUEUE_COMPUTE_BIT);
    }
    
    bool    ViDevice::is_queue_video_decode(ViQueueFamilyID family) const
    {
        return static_cast<bool>(queue_family_flags(family) & VK_QUEUE_VIDEO_DECODE_BIT_KHR);
    }
    
    bool    ViDevice::is_queue_video_encode(ViQueueFamilyID family) const
    {
        return static_cast<bool>(queue_family_flags(family) & VK_QUEUE_VIDEO_ENCODE_BIT_KHR);
    }

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

    bool    ViDevice::valid() const
    {   
        return m_physical && m_device && m_allocator;
    }
}
