////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/vulkan/ViCommandPool.hpp>
#include <yq/tachyon/vulkan/ViCommandBuffer.hpp>

namespace yq::tachyon {
    class VizBase;
    class ViDevice;
    class ViProcessor;

    //! This is a worker bee, one thread/one frame
    class ViWorker {
    public:
    
        struct Param {
            VqCommandPoolCreateFlags    command_pool_flags;
            ViQueueType                 queue_type  = ViQueueType::Graphic;
            uint32_t                    worker_id   = 0;
        };
    
        ViWorker(ViProcessor&);
        ViWorker(ViProcessor&, const Param&);
        ~ViWorker();
        
        VkCommandPool       command_pool() const;
        VkCommandBuffer     command_buffer() const;
        void                reset();
        bool                good() const { return m_good; }
        ViProcessor&        processor() { return m_proc; }
        uint32_t            worker_id() const { return m_id; }
    
    private:
    
        // WARNING: Init order matters here...
        ViProcessor&        m_proc;
        VizBase&            m_viz;
        ViDevice&           m_dev;
        ViCommandPool       m_cmdPool;
        ViCommandBuffer     m_cmdBuffer; 
        
        bool                m_good  = false;
        const uint32_t      m_id;
    };
}
