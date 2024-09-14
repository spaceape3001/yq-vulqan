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
#include <yq-vulqan/viz/ViBufferObjectVector.hpp>
#include <yq-vulqan/viz/ViQueueType.hpp>

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
    struct ViRendered;
    struct ViContext;
    
    class ViQueueManager;
    
    using ViRenderedMap   = std::unordered_multimap<uint64_t,ViRendered*>;
    
    struct ViBufferObject;
    using ViBO = ViBufferObject;

    struct ViTO;


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
        
        void    _ctor();
        void    _dtor();
        
        ViRendered*         create(const Rendered&, const Pipeline&);
        const ViRendered*   lookup(const Rendered&, const Pipeline&) const;
    };

    struct ViPipeline {
        Visualizer&             m_viz;
        const uint64_t          m_id;
        const PipelineConfig    m_cfg;
        
        ViBufferObjectVector    m_vbos;
        ViBufferObjectVector    m_ibos;
        ViBufferObjectVector    m_ubos;
        std::vector<ViTO>       m_texs;
        VkPipelineLayout        m_layout      = nullptr;
        VkPipeline              m_pipeline    = nullptr;
        VkPipeline              m_wireframe   = nullptr;
        VkDescriptorSetLayout   m_descriptors = nullptr;
        uint32_t                m_shaders     = 0;
        VkPipelineBindPoint     m_binding     = VK_PIPELINE_BIND_POINT_GRAPHICS;
        
        ViPipeline(Visualizer&, const Pipeline&);
        ~ViPipeline();
        
        std::error_code         _ctor();
        void                    _dtor();
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

        ViBufferObjectVector            m_vbos;
        ViBufferObjectVector            m_ibos;
        ViBufferObjectVector            m_ubos;
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

    struct ViSwapchain {
        Visualizer&                 m_viz;
        VkSwapchainKHR              m_swapchain       = nullptr;
        VkExtent2D                  m_extents         = {};
        uint32_t                    m_minImageCount   = 0;
        uint32_t                    m_imageCount      = 0;
        std::vector<VkImage>        m_images;
        std::vector<VkImageView>    m_imageViews;
        std::vector<VkFramebuffer>  m_frameBuffers;
        VkSurfaceCapabilitiesKHR    m_capabilities;
        
        
        ViSwapchain(Visualizer&, VkRenderPass, const ViSwapchain*old=nullptr);
        ~ViSwapchain();
        void        _ctor(VkRenderPass, const ViSwapchain* old);
        void        _dtor();
        
        
        VkRect2D    def_scissor() const;
        VkViewport  def_viewport() const;
        uint32_t    width() const;
        uint32_t    height() const;
    };


        // eventually multithread...
    struct ViThread {
        Visualizer&             m_viz;
        VkDescriptorPool        m_descriptors         = nullptr;
        VkCommandPool           m_graphics            = nullptr;
        VkCommandPool           m_compute             = nullptr;
        
        ViThread(Visualizer&);
        ~ViThread();
        
        void    _ctor();
        void    _dtor();
        
    };
}


