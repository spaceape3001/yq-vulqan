////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViCommandBuffer.hpp"
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    ViCommandBuffer::ViCommandBuffer()
    {
    }
    
    ViCommandBuffer::~ViCommandBuffer()
    {
    }

    std::error_code ViCommandBuffer::init(ViVisualizer&viz, VkCommandPool pool, VqCommandBufferLevel lvl)
    {
        if(!consistent())
            return errors::BAD_STATE_COMMAND_BUFFER();
        if(m_buffer)
            return errors::EXISTING_COMMAND_BUFFER();
        if(!viz.device())
            return errors::UNINITIALIZED_VISUALIZER();
        
        VqCommandBufferAllocateInfo cbai;
        cbai.level                  = (VkCommandBufferLevel) lvl;
        cbai.commandBufferCount     = 1;
        cbai.commandPool            = pool;
        if(vkAllocateCommandBuffers(viz.device(), &cbai,  &m_buffer) != VK_SUCCESS)
            return errors::CANT_CREATE_COMMAND_BUFFER();
        
        m_viz   = &viz;
        m_pool  = pool;
        return {};
    }
    
    void            ViCommandBuffer::kill()
    {
        if(valid()){
            vkFreeCommandBuffers(m_viz->device(), m_pool, 1, &m_buffer);
        }
        
        m_viz       = nullptr;
        m_pool      = nullptr;
        m_buffer    = nullptr;
    }

    bool            ViCommandBuffer::consistent() const
    {
        return m_viz ? (m_pool && m_buffer && m_viz->device()) : (!m_pool && !m_buffer);
    }
    
    bool            ViCommandBuffer::valid() const
    {
        return m_viz && m_pool && m_buffer && m_viz->device();
    }
}
