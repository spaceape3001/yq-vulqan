////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vulkan/vulkan_core.h>
#include <tachyon/gpu/ViBO.hpp>
#include <tachyon/gfx/PipelineConfig.hpp>

namespace yq {
    namespace tachyon {
        struct ViPipeline {
            PipelineConfig          cfg;
            std::vector<ViBO>       vbos;
            std::vector<ViBO>       ibos;
            VkPipelineLayout        layout      = nullptr;
            VkPipeline              pipeline    = nullptr;
            VkPipeline              wireframe   = nullptr;
            VkDescriptorSetLayout   descriptors = nullptr;
            uint32_t                shaders     = 0;
            VkPipelineBindPoint     binding     = VK_PIPELINE_BIND_POINT_GRAPHICS;
            uint64_t                id          = 0ULL;
        };
    }
}
