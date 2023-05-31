////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <vulkan/vulkan_core.h>
#include <tachyon/viz/PipelineConfig.hpp>
#include <vector>

namespace yq::tachyon {
    struct ABOConfig;
    struct BaseBOConfig;

    struct ViBO {
        VkBuffer        buffer  = nullptr;
        uint64_t        rev     = 0;
        uint32_t        count   = 0;
        uint32_t        offset  = 0;
        
        void    update(Visualizer&, const BaseBOConfig&, const void*);
    };

    struct ViPipeline {
        PipelineConfig          cfg;
        std::vector<ViBO>       vbos;
        std::vector<ViBO>       ibos;
        std::vector<ViBO>       ubos;
        VkPipelineLayout        layout      = nullptr;
        VkPipeline              pipeline    = nullptr;
        VkPipeline              wireframe   = nullptr;
        VkDescriptorSetLayout   descriptors = nullptr;
        uint32_t                shaders     = 0;
        VkPipelineBindPoint     binding     = VK_PIPELINE_BIND_POINT_GRAPHICS;
        uint64_t                id          = 0ULL;
    };


        //  This is the mirror to the rendered object
        //  (it'll take over the ViThing)
    struct ViRendered {
        std::vector<ViBO>               vbos;
        std::vector<ViBO>               ibos;
        std::vector<ViBO>               ubos;
        
        std::vector<VkDescriptorSet>    descriptors;        // to MAX_FRAMES_IN_FLIGHT * ibos * ubos needed...
        
        ViRendered(Visualizer& viz, const ViPipeline&, const Rendered* object);
        void    update(Visualizer& viz, const ViPipeline&, const Rendered* object);
    };
}


