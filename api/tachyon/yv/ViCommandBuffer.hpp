////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <system_error>
#include <vulkan/vulkan_core.h>
#include <tachyon/typedef/vi_device.hpp>
#include <yq/core/Ref.hpp>

namespace yq::tachyon {
    class ViVisualizer;

    enum class VqCommandBufferLevel : int32_t {
        Primary = 0,
        Secondary = 1
    };
    
    class ViCommandBuffer {
    public:
    
        ViCommandBuffer(ViDevice&, VkCommandPool, VqCommandBufferLevel lvl=VqCommandBufferLevel::Primary);
        ~ViCommandBuffer();
    
        operator VkCommandBuffer() const { return m_buffer; }
        
        VkCommandBuffer command_buffer() const { return m_buffer; }
        VkCommandPool   command_pool() const { return m_pool; }
        bool            consistent() const;
        bool            valid() const;
        //ViVisualizer*   visualizer() const { return m_viz; }

        VkCommandBuffer* command_buffer_ptr() { return &m_buffer; }

    private:
        ViDevice&       m_device;
        VkCommandPool   m_pool      = nullptr;
        VkCommandBuffer m_buffer    = nullptr;
    };

}
