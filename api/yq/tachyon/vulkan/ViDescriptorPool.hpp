////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <vulkan/vulkan_core.h>

namespace yq::tachyon {
    class ViDevice;

    class ViDescriptorPool {
    public:
    
        ViDescriptorPool(ViDevice&, uint32_t);
        ~ViDescriptorPool();

        //! Count per type
        uint32_t            count() const { return m_count; }
        
        VkDescriptorPool    descriptor_pool() const { return m_descriptorPool; }
        bool                valid() const;
    
    private:
        ViDevice&           m_viz;
        VkDescriptorPool    m_descriptorPool    = nullptr;
        uint32_t            m_count             = 0;
    };
}
