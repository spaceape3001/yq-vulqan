////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <vulkan/vulkan_core.h>

namespace yq {
    namespace tachyon {
    
        //! Helper to bind visualizer with the command buffer
        //! Allows for some state too
        class VqRecord {
        public:
        
            VkCommandBuffer         command() { return m_command; }
            Visualizer&             visualizer() { return m_viz; }
            
            VqRecord(Visualizer&viz, VkCommandBuffer cmd) : m_viz(viz), m_command(cmd) {}

        private:
            Visualizer&             m_viz;
            VkCommandBuffer         m_command;
            VkPipeline              m_pipeline    = nullptr;
            VkPipelineLayout        m_layout      = nullptr;
        };

    }
}
