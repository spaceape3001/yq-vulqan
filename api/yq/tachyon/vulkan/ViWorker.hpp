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
            VqCommandPoolCreateFlags    command_pool_flags = VqCommandPoolCreateBit::ResetCommandBuffer;
            ViQueueType                 queue_type  = ViQueueType::Graphic;
        };
    
        ViWorker(ViProcessor&);
        ViWorker(ViProcessor&, const Param&);
        virtual ~ViWorker();
        
        VkCommandPool       command_pool() const;
        VkCommandBuffer     command_buffer() const;
        void                reset();
        bool                good() const { return m_good; }
        ViProcessor&        processor() { return m_proc; }
        uint32_t            worker_id() const { return m_id; }
    
    private:
        friend class ViProcessor;
    
        // WARNING: Init order matters here...
        ViProcessor&        m_proc;
        VizBase&            m_viz;
        ViDevice&           m_dev;
        ViCommandPool       m_cmdPool;
        ViCommandBuffer     m_cmdBuffer; 
        
        bool                m_good  = false;
        uint32_t            m_id    = 0;
    };
}
