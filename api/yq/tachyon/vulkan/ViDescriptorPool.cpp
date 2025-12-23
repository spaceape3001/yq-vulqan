////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViDescriptorPool.hpp"
#include <yq/core/ErrorDB.hpp>
#include <yq/tachyon/vulkan/ViDevice.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>

namespace yq::tachyon {
    ViDescriptorPool::ViDescriptorPool(ViDevice&dev, uint32_t cnt) : m_viz(dev)
    {
        VkDescriptorPoolSize descriptorPoolSizes[] =
        {
            { VK_DESCRIPTOR_TYPE_SAMPLER, cnt },
            { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, cnt },
            { VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE, cnt },
            { VK_DESCRIPTOR_TYPE_STORAGE_IMAGE, cnt },
            { VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER, cnt },
            { VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER, cnt },
            { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, cnt },
            { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER, cnt },
            { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC, cnt },
            { VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC, cnt },
            { VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT, cnt }
        };
        
        size_t  cntDPS  = sizeof(descriptorPoolSizes)/sizeof(VkDescriptorPoolSize);
        
        VqDescriptorPoolCreateInfo descriptorPoolInfo;
        //descriptorPoolInfo.flags         = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT | VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT;
        descriptorPoolInfo.flags         = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT | VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT;
        descriptorPoolInfo.maxSets       = cnt * cntDPS;
        descriptorPoolInfo.poolSizeCount = (uint32_t) cntDPS;
        descriptorPoolInfo.pPoolSizes    = descriptorPoolSizes;
        if(vkCreateDescriptorPool(m_viz.device(), &descriptorPoolInfo, nullptr, &m_descriptorPool) != VK_SUCCESS)
            throw create_error<"Unable to allocate the descriptor pool">();
        m_count = cnt;
    }
    
    ViDescriptorPool::~ViDescriptorPool()
    {
        if(m_descriptorPool){
            vkDestroyDescriptorPool(m_viz.device(), m_descriptorPool, nullptr);
            m_descriptorPool = nullptr;
        }
        m_count             = 0;
    }
    
    bool    ViDescriptorPool::valid() const
    {
        return static_cast<bool>(m_descriptorPool);
    }
    
}
