////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViTasker.hpp"
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/viz/ViQueueManager.hpp>
#include <utility>

namespace yq::tachyon {
    ViTasker::ViTasker(ViVisualizer&viz, const ViQueueManager& qm, uint32_t qn) : 
        m_viz(viz), 
        m_commandPool(viz, qm.family()), 
        m_commandBuffer(viz, m_commandPool),
        m_queue(qm.queue(qn))
    {
    }
    
    ViTasker::~ViTasker()
    {
        m_commandBuffer.kill();
        m_commandPool.kill();
        m_fence.kill();
    }

    std::error_code ViTasker::execute(tasker_fn&&fn)
    {
        return execute(DEFAULT_WAIT_TIMEOUT, std::move(fn));
    }
    
    std::error_code ViTasker::execute(uint64_t timeout, tasker_fn&&)
    {   
        return errors::todo();
    }

    bool    ViTasker::valid() const
    {
        return m_commandPool.valid() && m_commandBuffer.valid() && m_fence.valid() && m_queue;
    }
}
