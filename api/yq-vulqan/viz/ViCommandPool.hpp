////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/v/VqEnumerations.hpp>
#include <system_error>
#include <vulkan/vulkan_core.h>

namespace yq::tachyon {
    class ViVisualizer;
    
    class ViCommandPool {
    public:
    
        ViCommandPool();
        ~ViCommandPool();
        
        std::error_code init(ViVisualizer&, uint32_t queueFamilyIndex, VqCommandPoolCreateFlags={});
        std::error_code init(ViVisualizer&, const VkCommandPoolCreateInfo&);
        void            kill(ViVisualizer&);
        
    private:
        VkCommandPool       m_pool;
    };
}
