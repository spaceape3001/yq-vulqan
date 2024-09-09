////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/typedef/tasker.hpp>

#include <yq-toolbox/basic/Ref.hpp>
#include <yq-vulqan/viz/ViCommandBuffer.hpp>
#include <yq-vulqan/viz/ViCommandPool.hpp>
#include <yq-vulqan/viz/ViFence.hpp>

namespace yq::tachyon {
    class ViVisualizer;
    class ViQueueManager;
    
    class ViTasker : public RefCount {
    public:
        ViTasker(ViVisualizer&, const ViQueueManager&, uint32_t queue=0);
        ~ViTasker();
    
        std::error_code execute(tasker_fn&&);
        std::error_code execute(uint64_t timeout, tasker_fn&&);
        bool            valid() const;
        
        bool            valid_command_buffer() const;
        bool            valid_command_pool() const;
        bool            valid_fence() const;
        bool            valid_queue() const;
    
    private:
        ViVisualizer&   m_viz;
        ViCommandPool   m_commandPool;
        ViCommandBuffer m_commandBuffer;
        ViFence         m_fence;
        VkQueue         m_queue     = nullptr;
    };
}
