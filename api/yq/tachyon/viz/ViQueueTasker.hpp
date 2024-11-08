////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/vi_queue_tasker.hpp>

#include <yq/core/Ref.hpp>
#include <yq/tachyon/viz/ViCommandBuffer.hpp>
#include <yq/tachyon/viz/ViCommandPool.hpp>
#include <yq/tachyon/viz/ViFence.hpp>

namespace yq::tachyon {
    class ViVisualizer;
    class ViQueueManager;
    
    class ViQueueTasker : public RefCount {
    public:
        ViQueueTasker(ViVisualizer&, const ViQueueManager&, uint32_t queue=0);
        ~ViQueueTasker();
    
        std::error_code execute(queue_tasker_fn&&);
        std::error_code execute(uint64_t timeout, queue_tasker_fn&&);
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
