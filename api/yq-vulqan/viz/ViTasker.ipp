////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViTasker.hpp"
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViQueueManager.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>
#include <utility>
#include <exception>

namespace yq::tachyon {
    ViTasker::ViTasker(ViVisualizer&viz, const ViQueueManager& qm, uint32_t qn) : 
        m_viz(viz), 
        m_commandPool(viz, qm.family()), 
        m_commandBuffer(viz, m_commandPool),
        m_fence(viz),
        m_queue(qm.queue(qn))
    {
    }
    
    ViTasker::~ViTasker()
    {
    }

    std::error_code ViTasker::execute(tasker_fn&&fn)
    {
        return execute(DEFAULT_WAIT_TIMEOUT, std::move(fn));
    }
    
    std::error_code ViTasker::execute(uint64_t timeout, tasker_fn&&fn)
    {
        if(!valid())
            return errors::tasker_uninitialized();
        if(!fn)
            return errors::tasker_bad_function();
        
        std::error_code     ec;
        VqCommandBufferBeginInfo beginInfo;
        beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT; // Optional
        if(vkBeginCommandBuffer(m_commandBuffer, &beginInfo) != VK_SUCCESS)
            return errors::tasker_cant_begin();
        
        std::exception_ptr  exptr;
        
        try {
            fn(m_commandBuffer);
        }
        catch(std::error_code ec2){
            ec  = ec2;
        }
        catch(...)
        {
            exptr   = std::current_exception();
        }

        if(vkEndCommandBuffer(m_commandBuffer) != VK_SUCCESS)
            ec      = errors::tasker_cant_end();
        
        if((ec == std::error_code()) && !exptr){
            VqSubmitInfo    subinfo;
            subinfo.pCommandBuffers     = m_commandBuffer.command_buffer_ptr();
            subinfo.commandBufferCount  = 1;
            if(vkQueueSubmit(m_queue, 1, &subinfo, m_fence) != VK_SUCCESS)
                return errors::tasker_cant_submit();
            ec = m_fence.wait(timeout);
            m_fence.reset();
        }
        
        m_commandPool.reset();
        
        if(exptr){
            std::rethrow_exception(exptr);
        }
        return ec;
    }

    bool    ViTasker::valid() const
    {
        return m_commandPool.valid() && m_commandBuffer.valid() && m_fence.valid() && m_queue;
    }

    bool    ViTasker::valid_command_buffer() const
    {
        return m_commandBuffer.valid();
    }
    
    bool    ViTasker::valid_command_pool() const
    {
        return m_commandPool.valid();
    }
    
    bool    ViTasker::valid_fence() const
    {
        return m_fence.valid();
    }
    
    bool    ViTasker::valid_queue() const
    {
        return static_cast<bool>(m_queue);
    }
}
