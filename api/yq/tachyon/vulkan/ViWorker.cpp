////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViWorker.hpp"
#include <yq/tachyon/vulkan/ViDevice.hpp>
#include <yq/tachyon/vulkan/ViProcessor.hpp>
#include <yq/tachyon/vulkan/VizBase.hpp>

namespace yq::tachyon {
    ViWorker::ViWorker(ViProcessor&vb) : ViWorker(vb, Param())
    {
    }

    ViWorker::ViWorker(ViProcessor& vb, const Param&p) : 
        m_proc(vb), m_viz(vb.viz()), m_dev(vb.device()),
        m_cmdPool(m_dev, p.queue_type, p.command_pool_flags), 
        m_cmdBuffer(m_dev, m_cmdPool.command_pool()),
        m_id(p.worker_id)
    {
        m_good  = m_cmdPool.valid();
    }
    
    ViWorker::~ViWorker()
    {
    }
    
    VkCommandBuffer     ViWorker::command_buffer() const
    {
        return m_cmdBuffer.command_buffer();
    }

    VkCommandPool       ViWorker::command_pool() const
    {
        return m_cmdPool.command_pool();
    }

    void    ViWorker::reset()
    {
        m_cmdPool.reset();
    }
}
