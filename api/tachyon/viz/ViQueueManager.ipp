////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViQueueManager.hpp"
#include <tachyon/errors.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/v/VqStructs.hpp>
#include <tachyon/viewer/ViewerCreateInfo.hpp>
#include <tachyon/viz/ViQueueTasker.hpp>
#include <tachyon/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    bool    is_empty(const QueueSpec& qs)
    {
        if(std::get_if<std::monostate>(&qs) != nullptr)
            return true;
        if(std::get_if<optional_t>(&qs) != nullptr)
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
        if(std::get_if<optional_t>(&qs) != nullptr)
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
        if(std::get_if<optional_t>(&qs) != nullptr)
            return false;
        if(const std::vector<float>*p = std::get_if<std::vector<float>>(&qs))
            return !p->empty();
        if(const uint32_t* p = std::get_if<uint32_t>(&qs))
            return *p != 0;
        if(const bool* p = std::get_if<bool>(&qs))
            return *p;
        return false;
    }

    namespace {


        const QueueSpec&   biggest(const ViewerCreateInfo& vci, Flags<ViQueueType> which)
        {
            size_t  g       = 0;
            size_t  c       = 0;
            size_t  p       = 0;
            size_t  t       = 0;
            size_t  ve      = 0;
            size_t  vd      = 0;
            size_t  mx      = 0;
            
            if(which.is_set(ViQueueType::Graphic)){
                mx  = g   = std::max((size_t) 1,count(vci.graphic));
            }
            if(which.is_set(ViQueueType::Present)){
                p   = std::max((size_t) 1,count(vci.present));
                mx  = std::max(p,mx);
            };
            if(which.is_set(ViQueueType::Compute)){
                c   = count(vci.compute);
                mx  = std::max(c,mx);
            }
            if(which.is_set(ViQueueType::Transfer)){
                t   = count(vci.transfer);
                mx  = std::max(t,mx);
            }
            if(which.is_set(ViQueueType::VideoEncode)){
                ve  = count(vci.video_encode);
                mx  = std::max(ve,mx);
            }
            if(which.is_set(ViQueueType::VideoDecode)){
                vd  = count(vci.video_decode);
                mx  = std::max(vd,mx);
            }
            
            if(g==mx)
                return vci.graphic;
            if(p==mx)
                return vci.present;
            if(c==mx)
                return vci.compute;
            if(t==mx)
                return vci.transfer;
            if(vd==mx)
                return vci.video_decode;
            if(ve==mx)
                return vci.video_encode;
            throw create_error<"No queues remaining">();
        }
    }
    
    //  -------------------------------
        
    ViQueueManager::ViQueueManager(ViVisualizer&viz, const ViewerCreateInfo&vci, uint32_t fi, const VkQueueFamilyProperties&prop, ViQueueTypeFlags left) 
        : m_viz(viz), m_family(fi)
    {
        m_availableQueueCount           = prop.queueCount;
        m_timestampValidBits            = prop.timestampValidBits;
        m_minImageTransferGranularity   = prop.minImageTransferGranularity;
        m_vkFlags                       = prop.queueFlags;

        if(left.is_set(ViQueueType::Graphic) && (m_vkFlags & VK_QUEUE_GRAPHICS_BIT))
            m_type.set(ViQueueType::Graphic);
        if(left.is_set(ViQueueType::Compute) && (m_vkFlags & VK_QUEUE_COMPUTE_BIT))
            m_type.set(ViQueueType::Compute);
        if(left.is_set(ViQueueType::Transfer) && (m_vkFlags == VK_QUEUE_TRANSFER_BIT))
            m_type.set(ViQueueType::Transfer);
        if(left.is_set(ViQueueType::VideoEncode) && (m_vkFlags & VK_QUEUE_VIDEO_ENCODE_BIT_KHR))
            m_type.set(ViQueueType::VideoEncode);
        if(left.is_set(ViQueueType::VideoDecode) && (m_vkFlags & VK_QUEUE_VIDEO_DECODE_BIT_KHR))
            m_type.set(ViQueueType::VideoDecode);
        if(left.is_set(ViQueueType::Present)){
            VkBool32 presentSupport = false;
            vkGetPhysicalDeviceSurfaceSupportKHR(viz.physical(), fi, viz.surface(), &presentSupport);
            if(presentSupport)
                m_type.set(ViQueueType::Present);
        }
        
        const QueueSpec&  spec    = biggest(vci, m_type);
        if(const std::vector<float>*p = std::get_if<std::vector<float>>(&spec)){
            if(!p->empty())
                m_weights   = *p;
        }
        if(const uint32_t* p = std::get_if<uint32_t>(&spec))
            m_weights.resize(*p, 1.);
        if(m_weights.empty())
            m_weights.push_back(1.);
        m_queues.resize(m_weights.size(), nullptr);
    }
    
    ViQueueManager::~ViQueueManager()
    {
        m_taskers.clear();
    }

    bool      ViQueueManager::can_transfer() const
    {
        return static_cast<bool>(m_vkFlags & VK_QUEUE_TRANSFER_BIT);
    }

    uint32_t  ViQueueManager::count() const 
    { 
        return (uint32_t) m_queues.size(); 
    }
    
    bool      ViQueueManager::empty() const
    {
        return m_queues.empty();
    }

    uint32_t  ViQueueManager::family() const 
    { 
        return m_family; 
    }
    
    VkDeviceQueueCreateInfo ViQueueManager::info()
    {
        VqDeviceQueueCreateInfo  ret;
        ret.queueFamilyIndex   = m_family;
        ret.queueCount         = (uint32_t) m_weights.size();
        ret.pQueuePriorities   = m_weights.data();
        return ret;
    }

    void      ViQueueManager::init()
    {
        if(m_queues.size() != m_weights.size())
            throw create_error<"Queues size does not match weight sizes">();
        for(uint32_t i=0;i<m_queues.size();++i)
            vkGetDeviceQueue(m_viz.device(), m_family, i, &m_queues[i]);
        m_taskers.resize(m_queues.size());
        for(uint32_t i=0;i<m_queues.size();++i){
            m_taskers[i]    = new ViQueueTasker(m_viz, *this, i);
            if(!m_taskers[i]->valid()){
                vizWarning << "Tasker " << i << " is not valid!";
            }
        }
    }
    
    VkQueue   ViQueueManager::queue(uint32_t i) const
    {
        if(i<m_queues.size()) [[likely]]
            return m_queues[i];
        return nullptr;
    }

    ViQueueTaskerPtr       ViQueueManager::tasker(uint32_t i) const
    {
        if(i<m_taskers.size()) [[likely]]
            return m_taskers[i];
        return {};
    }

    ViQueueTypeFlags  ViQueueManager::types() const 
    { 
        return m_type; 
    }
}
