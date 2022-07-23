////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/trait/not_copyable.hpp>
#include <basic/trait/not_moveable.hpp>
#include <vulkan/vulkan_core.h>

namespace yq {
    namespace engine {
        struct PipelineConfig;
        struct Visualizer;
        class Pipeline;
        class VqBuffer;


        struct VqVBO {  // temporarily here....
            DataActivity    freq;
        };
        
        class VqPipeline : trait::not_copyable, trait::not_moveable {
        public:
        
            VqPipeline(Visualizer&, const PipelineConfig&);
            ~VqPipeline();
            
            bool                    good() const noexcept { return m_pipeline != nullptr; }
            VkPipeline              pipeline() const noexcept { return m_pipeline; }
            VkPipeline              wireframe() const noexcept { return m_wireframe; }
            VkPipelineLayout        layout() const noexcept { return m_layout; }
            
            uint32_t                shader_mask() const noexcept { return m_shaderMask; }
            
            uint64_t                id() const { return m_id; }
            
        private:
            void    dtor();
            
            //  All defined VBOS, in binding order
            std::vector<VqVBO>      m_vbos;
            VkDevice                m_device    = nullptr;
            VkPipelineLayout        m_layout    = nullptr;
            VkPipeline              m_pipeline  = nullptr;
            VkPipeline              m_wireframe = nullptr;
            VkDescriptorSetLayout   m_descriptorSetLayout   = nullptr;
            uint64_t                m_id            = 0;
            uint32_t                m_shaderMask    = 0;
        };

    }
}
