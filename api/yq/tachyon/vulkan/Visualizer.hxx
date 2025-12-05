////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/container/BasicBuffer.hpp>
#include <yq/core/Flags.hpp>
#include <yq/core/Ref.hpp>
#include <yq/tachyon/enum/RenderMode.hpp>
//#include <yq/tachyon/image/Image.hpp>
#include <yq/tachyon/typedef/pipeline.hpp>
#include <yq/tachyon/typedef/rendered.hpp>
#include <yq/tachyon/typedef/vi_rendered.hpp>
#include <yq/tachyon/typedef/vi_rendered_manager.hpp>
#include <yq/tachyon/vulkan/ViQueueType.hpp>

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
        
//        ViRenderedPtr         create(const RenderedCPtr&);
        ViRenderedPtr      create(const RenderedSnap*, RenderMode rm=RenderMode::Simple);
    };

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


