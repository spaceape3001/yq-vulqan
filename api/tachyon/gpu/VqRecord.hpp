////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <vulkan/vulkan_core.h>
#include <tachyon/enum/PipelineBinding.hpp>

namespace yq {
    namespace tachyon {
    
        //! Helper to bind visualizer with the command buffer
        //! Allows for some state too
        class VqRecord {
        public:
        
            VkCommandBuffer         command() { return m_command; }
            Visualizer&             visualizer() { return m_viz; }
            
            VqRecord(Visualizer&viz, VkCommandBuffer cmd) : m_viz(viz), m_command(cmd) {}
            
            void    pipeline(VkPipeline, VkPipelineLayout, PipelineBinding binding=PipelineBinding::Graphics);

        private:
            Visualizer&             m_viz;
            VkCommandBuffer         m_command;
        };

    }
}
