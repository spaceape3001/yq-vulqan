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
    
    struct ViQueues;
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
        Visualizer&             m_viz;
        const uint64_t          m_id;
        const PipelineConfig    m_cfg;
        
        std::vector<ViBO>       m_vbos;
        std::vector<ViBO>       m_ibos;
        std::vector<ViBO>       m_ubos;
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

    struct ViRenderPass {
        Visualizer&         m_viz;
        VkRenderPass        m_renderPass    = nullptr;
        
        ViRenderPass(Visualizer&);
        ~ViRenderPass();
        
        void    _ctor();
        void    _dtor();
    };

    //! Shader storage
    //! \note the Client is expected to manually call create & destroy
    struct ViShader {
        VkShaderModule          shader  = nullptr;
        VkShaderStageFlagBits   mask    = {};
        
        std::error_code     create(VkDevice, const Shader&);
        void                destroy(VkDevice);
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
        
        
        ViSwapchain(Visualizer&, const ViRenderPass&, const ViSwapchain*old=nullptr);
        ~ViSwapchain();
        void        _ctor(const ViRenderPass&, const ViSwapchain* old);
        void        _dtor();
        
        
        VkRect2D    def_scissor() const;
        VkViewport  def_viewport() const;
        uint32_t    width() const;
        uint32_t    height() const;
    };

    struct ViTexture  {
        VkImageView             view        = nullptr;
        VkSampler               sampler     = nullptr;
    };

    struct ViUpload {
        Visualizer&             m_viz;
        VkFence                 m_fence           = nullptr;
        VkCommandPool           m_pool            = nullptr;
        VkCommandBuffer         m_commandBuffer   = nullptr;
        VkQueue                 m_queue           = nullptr;
        
        ViUpload(Visualizer&, const ViQueues&);
        ~ViUpload();
        
        void    _ctor(const ViQueues&);
        void    _dtor();
    };
}


