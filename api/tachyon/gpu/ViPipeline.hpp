////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vulkan/vulkan_core.h>

namespace yq {
    namespace tachyon {
        struct ViPipeline {
            VkPipelineLayout        layout      = nullptr;
            VkPipeline              pipeline    = nullptr;
            VkPipeline              wireframe   = nullptr;
            VkDescriptorSetLayout   descriptors = nullptr;
            uint32_t                shaders     = 0;
            VkPipelineBindPoint     binding     = VK_PIPELINE_BIND_POINT_GRAPHICS;
        };
    }
}
