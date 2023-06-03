////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <basic/BasicBuffer.hpp>
#include <vulkan/vulkan_core.h>
#include <tachyon/viz/PipelineConfig.hpp>
#include <vector>
#include <vk_mem_alloc.h>
#include <unordered_map>
#include <tbb/spin_rw_mutex.h>

namespace yq::tachyon {
    class Visualizer;
    
    struct ABOConfig;
    struct BaseBOConfig;
    
    struct ViRendered;
    
    using ViRenderedMap   = std::unordered_multimap<uint64_t,ViRendered*>;

    struct ViTO;

    struct ViBO {
        VkBuffer        buffer  = nullptr;
        uint64_t        rev     = 0;
        uint32_t        count   = 0;
        uint32_t        offset  = 0;
        
        //  returns TRUE if changed
        bool    update(Visualizer&, const BaseBOConfig&, const void*);
    };

    struct ViBuffer {
        VkBuffer                buffer      = nullptr;
        VmaAllocation           allocation  = nullptr;
        
        std::error_code     allocate(Visualizer&, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu);
        std::error_code     create(Visualizer&, const Memory& v, VkBufferUsageFlags buf, VmaMemoryUsage vmu);
        std::error_code     create(Visualizer&, const Buffer& v);
        void                destroy(Visualizer&);
    };

        //  and so we can be more efficient in rendering
    struct ViFrame {
        ViRenderedMap               m_rendereds;
        mutable tbb::spin_rw_mutex  m_mutex;
        Visualizer&                 m_viz;
        VkCommandPool               m_commandPool     = nullptr;
        VkCommandBuffer             m_commandBuffer   = nullptr;    // TODO -- make vector 
        VkSemaphore                 m_imageAvailable  = nullptr;
        VkSemaphore                 m_renderFinished  = nullptr;
        VkFence                     m_fence           = nullptr;
        const uint32_t              m_id;
        
        ViFrame(Visualizer&);
        ~ViFrame();
        
        std::error_code     _ctor();
        void                _dtor();
        
        ViRendered*         create(const Rendered&, const Pipeline&);
        const ViRendered*   lookup(const Rendered&, const Pipeline&) const;
    };


    //!  Represents an image (likely from file) that has been pushed to the GPU
    struct ViImage {
        VmaAllocation           allocation  = nullptr;
        VkImage                 image       = nullptr;

        std::error_code         create(Visualizer&, const Image&);
        void                    destroy(Visualizer&);
    };

    struct ViPipeline {
        //Visualizer&             viz;
        PipelineConfig          cfg;
        std::vector<ViBO>       vbos;
        std::vector<ViBO>       ibos;
        std::vector<ViBO>       ubos;
        std::vector<ViTO>       texs;
        VkPipelineLayout        layout      = nullptr;
        VkPipeline              pipeline    = nullptr;
        VkPipeline              wireframe   = nullptr;
        VkDescriptorSetLayout   descriptors = nullptr;
        uint32_t                shaders     = 0;
        VkPipelineBindPoint     binding     = VK_PIPELINE_BIND_POINT_GRAPHICS;
        uint64_t                id          = 0ULL;
    };

    struct ViTO {
        VkImageView             view        = nullptr;
        VkSampler               sampler     = nullptr;
        uint64_t                rev         = 0ULL;

        //  returns TRUE if changed
        bool    update(Visualizer&, const TexConfig&, const void*);
    };

        //  This is the mirror to the rendered object
        //  (it'll take over the ViThing)
    struct ViRendered {
        Visualizer&                     m_viz;
        const ViPipeline&               m_pipe;
        const Rendered&                 m_object;
        
        /*
        struct ubo_t {
            VkBuffer                    buffer      = nullptr;
            VmaAllocation               allocation  = nullptr;
            const void*                 pointer     = nullptr;
        };
        */

        std::vector<ViBO>               m_vbos;
        std::vector<ViBO>               m_ibos;
        std::vector<ViBO>               m_ubos;
        std::vector<ViTO>               m_texs;
        std::vector<VkDescriptorSet>    m_descriptors;        // sized to ubos + textures
        
        PushBuffer                      m_push;
        
        ViRendered(Visualizer&, const ViPipeline&, const Rendered&);
        ~ViRendered();

        std::error_code     _ctor();
        void                _dtor();

        void                update(ViContext&);
        void                descriptors(ViContext&);
        void                record(ViContext&u);
        
        void    _ubo(size_t);
        void    _tex(size_t);
    };

    //! Shader storage
    //! \note the Client is expected to manually call create & destroy
    struct ViShader {
        VkShaderModule          shader  = nullptr;
        VkShaderStageFlagBits   mask    = {};
        
        std::error_code     create(VkDevice, const Shader&);
        void                destroy(VkDevice);
    };

    struct ViTexture  {
        VkImageView             view        = nullptr;
        VkSampler               sampler     = nullptr;
    };
}


