////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/container/BasicBuffer.hpp>
#include <yq-toolbox/basic/Flags.hpp>
#include <yq-toolbox/basic/Ref.hpp>
#include <yq-vulqan/image/Image.hpp>
#include <yq-vulqan/memory/Memory.hpp>
#include <yq-vulqan/pipeline/PipelineConfig.hpp>
#include <yq-vulqan/typedef/pipeline.hpp>
#include <yq-vulqan/typedef/rendered.hpp>
#include <yq-vulqan/viz/ViBufferObjectVector.hpp>
#include <yq-vulqan/viz/ViQueueType.hpp>
#include <yq-vulqan/viz/ViTextureObjectVector.hpp>

#include <vulkan/vulkan_core.h>
#include <vector>
#include <vk_mem_alloc.h>
#include <unordered_map>
#include <tbb/spin_rw_mutex.h>

namespace yq::tachyon {
    class Visualizer;
    
    struct ABOConfig;
    struct BaseBOConfig;
    
    class Rendered;
    class Pipeline;
    struct ViContext;
    
    class ViQueueManager;
    

        //  and so we can be more efficient in rendering
    struct ViFrame0 {
        ViRenderedManagerUPtr       m_rendereds;
        mutable tbb::spin_rw_mutex  m_mutex;
        Visualizer&                 m_viz;
        VkCommandPool               m_commandPool     = nullptr;
        VkCommandBuffer             m_commandBuffer   = nullptr;    // TODO -- make vector 
        VkSemaphore                 m_imageAvailable  = nullptr;
        VkSemaphore                 m_renderFinished  = nullptr;
        VkFence                     m_fence           = nullptr;
        const uint32_t              m_id;
        
        ViFrame0(Visualizer&);
        ~ViFrame0();
        
        void    _ctor();
        void    _dtor();
        
        ViRenderedPtr         create(const RenderedCPtr&);
        //ViRenderedCPtr      create(const RenderedCPtr&, const PipelineCPtr&);
    };

#if 0
    struct ViPipeline0 {
        Visualizer&             m_viz;
        const uint64_t          m_id;
        SharedPipelineConfig    m_config;
        const PipelineConfig&   m_cfg;
        
        ViBufferObjectVector    m_vbos;
        ViBufferObjectVector    m_ibos;
        ViBufferObjectVector    m_ubos;
        ViTextureObjectVector   m_texs;
        VkPipelineLayout        m_layout      = nullptr;
        VkPipeline              m_pipeline    = nullptr;
        VkPipeline              m_wireframe   = nullptr;
        VkDescriptorSetLayout   m_descriptors = nullptr;
        uint32_t                m_shaders     = 0;
        VkPipelineBindPoint     m_binding     = VK_PIPELINE_BIND_POINT_GRAPHICS;
        
        ViPipeline0(Visualizer&, const Pipeline&);
        ~ViPipeline0();
        
        std::error_code         _ctor();
        void                    _dtor();
    };
#endif

#if 0
        //  This is the mirror to the rendered object
        //  (it'll take over the ViThing)
    struct ViRendered0 {
        Visualizer&                     m_viz;
        const ViPipeline0&               m_pipe;
        const Rendered&                 m_object;
        
        /*
        struct ubo_t {
            VkBuffer                    buffer      = nullptr;
            VmaAllocation               allocation  = nullptr;
            const void*                 pointer     = nullptr;
        };
        */

        ViBufferObjectVector            m_vbos;
        ViBufferObjectVector            m_ibos;
        ViBufferObjectVector            m_ubos;
        ViTextureObjectVector           m_texs;
        std::vector<VkDescriptorSet>    m_descriptors;        // sized to ubos + textures
        
        PushBuffer                      m_push;
        
        ViRendered0(Visualizer&, const ViPipeline0&, const Rendered&);
        ~ViRendered0();

        std::error_code     _ctor();
        void                _dtor();

        void                update(ViContext&);
        void                descriptors(ViContext&);
        void                record(ViContext&u);
        
        void    _ubo(size_t);
        void    _tex(size_t);
    };
#endif

        // eventually multithread...
    struct ViThread0 {
        Visualizer&             m_viz;
        VkDescriptorPool        m_descriptors         = nullptr;
        VkCommandPool           m_graphics            = nullptr;
        VkCommandPool           m_compute             = nullptr;
        
        ViThread0(Visualizer&);
        ~ViThread0();
        
        void    _ctor();
        void    _dtor();
        
    };
}


