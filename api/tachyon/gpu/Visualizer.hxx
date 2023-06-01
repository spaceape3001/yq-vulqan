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
#include <vk_mem_alloc.h>

namespace yq::tachyon {
    class Visualizer;
    
    struct ABOConfig;
    struct BaseBOConfig;

    struct ViBO {
        VkBuffer        buffer  = nullptr;
        uint64_t        rev     = 0;
        uint32_t        count   = 0;
        uint32_t        offset  = 0;
        
        void    update(Visualizer&, const BaseBOConfig&, const void*);
    };

    struct ViBuffer {
        VkBuffer                buffer      = nullptr;
        VmaAllocation           allocation  = nullptr;
        
        std::error_code     allocate(Visualizer&, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu);
        std::error_code     create(Visualizer&, const Memory& v, VkBufferUsageFlags buf, VmaMemoryUsage vmu);
        std::error_code     create(Visualizer&, const Buffer& v);
        void                destroy(Visualizer&);
    };

    //!  Represents an image (likely from file) that has been pushed to the GPU
    struct ViImage {
        VmaAllocation           allocation  = nullptr;
        VkImage                 image       = nullptr;

        std::error_code         create(Visualizer&, const Image&);
        void                    destroy(Visualizer&);
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
        uint64_t                        pipe    = 0ULL;
        
        std::error_code     create(Visualizer&, const ViPipeline&, const Rendered& object);
        std::error_code     update(Visualizer&, const ViPipeline&, const Rendered& object);
        std::error_code     destroy(Visualizer&);
        
        
        ViRendered(Visualizer& viz, const ViPipeline&, const Rendered* object);
        void    update(Visualizer& viz, const ViPipeline&, const Rendered* object);
    };

    //! Shader storage
    //! \note the Client is expected to manually call create & destroy
    struct ViShader {
        VkShaderModule          shader  = nullptr;
        VkShaderStageFlagBits   mask    = {};
        
        std::error_code     create(VkDevice, const Shader&);
        void                destroy(VkDevice);
    };
}


