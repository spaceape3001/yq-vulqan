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
        ViCommandBuffer(ViVisualizer&, VkCommandPool, VqCommandBufferLevel lvl=VqCommandBufferLevel::Primary);
        ~ViCommandBuffer();
    
        operator VkCommandBuffer() const { return m_buffer; }
        
        VkCommandBuffer command_buffer() const { return m_buffer; }
        VkCommandPool   command_pool();
        bool            consistent() const;
        bool            valid() const;
        ViVisualizer*   visualizer() const { return m_viz; }

        VkCommandBuffer* command_buffer_ptr() { return &m_buffer; }


        std::error_code init(ViVisualizer&, VkCommandPool, VqCommandBufferLevel lvl=VqCommandBufferLevel::Primary);
        void            kill();

    private:
        ViVisualizer*   m_viz       = nullptr;
        VkCommandPool   m_pool      = nullptr;
        VkCommandBuffer m_buffer    = nullptr;
        
        ViCommandBuffer(const ViCommandBuffer&) = delete;
        ViCommandBuffer(ViCommandBuffer&&) = delete;
        ViCommandBuffer& operator=(const ViCommandBuffer&) = delete;
        ViCommandBuffer& operator=(ViCommandBuffer&&) = delete;
        
        std::error_code _init(ViVisualizer&, VkCommandPool, VqCommandBufferLevel lvl);
        void            _kill();
        void            _wipe();
    };

}
