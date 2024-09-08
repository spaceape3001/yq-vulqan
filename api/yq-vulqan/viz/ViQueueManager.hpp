////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Ref.hpp>
#include <yq-vulqan/typedef/queue_spec.hpp>
#include <yq-vulqan/viz/ViQueueType.hpp>
#include <vulkan/vulkan_core.h>
#include <vector>

namespace yq::tachyon {
    struct ViVisualizer;
    struct ViewerCreateInfo;
    
    class ViQueueManager : public RefCount {
    public:
    
        //! Constructor (WARNING, may throw a std::error_code)
        ViQueueManager(ViVisualizer&, const ViewerCreateInfo&, uint32_t, const VkQueueFamilyProperties&, ViQueueTypeFlags left);
        ~ViQueueManager();
        
        uint32_t                count() const;

        bool                    empty() const;
        uint32_t                family() const;

        VkDeviceQueueCreateInfo info();
        VkQueue                 queue(uint32_t i) const;
        
        
        ViQueueTypeFlags        types() const;

        //! Constructor (WARNING, may throw a std::error_code)
        void                    init();

    private:
        ViVisualizer&           m_viz;
        const uint32_t          m_family;
        ViQueueTypeFlags        m_type = {};
        std::vector<VkQueue>    m_queues;
        std::vector<float>      m_weights;
        VkExtent3D              m_minImageTransferGranularity;  //!< Min granularity for image transfers
        uint32_t                m_availableQueueCount;          //!< Available Queue count (from spec)
        uint32_t                m_timestampValidBits;           //!< valid bits for timestamps
        VkQueueFlags            m_vkFlags;                      //!< Flags from vulkan 
    };

    size_t  count(const QueueSpec&);
    bool    is_empty(const QueueSpec&);
}
