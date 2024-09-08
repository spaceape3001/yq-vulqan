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
        void            kill();
        std::error_code reset(VqCommandPoolResetFlags={});
        bool            consistent() const;
        bool            valid() const;
        
        operator VkCommandPool() const { return m_pool; }
        
        
    private:
        ViVisualizer*       m_viz  = nullptr;
        VkCommandPool       m_pool = nullptr;
    };
}
