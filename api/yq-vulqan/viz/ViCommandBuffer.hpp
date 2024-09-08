////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <system_error>
#include <vulkan/vulkan_core.h>
#include <yq-vulqan/v/VqEnumerations.hpp>

namespace yq::tachyon {
    class ViVisualizer;
    
    class ViCommandBuffer {
    public:
    
        ViCommandBuffer();
        ~ViCommandBuffer();
    
        std::error_code init(ViVisualizer&, VkCommandPool, VqCommandBufferLevel lvl=VqCommandBufferLevel::Primary);
        void            kill();

        bool            consistent() const;
        bool            valid() const;
    
        operator VkCommandBuffer() const { return m_buffer; }
    private:
        ViVisualizer*   m_viz       = nullptr;
        VkCommandPool   m_pool      = nullptr;
        VkCommandBuffer m_buffer    = nullptr;
    };

}
