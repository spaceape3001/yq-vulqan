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
    
    ViCommandBuffer::ViCommandBuffer(ViVisualizer& viz, VkCommandPool pool, VqCommandBufferLevel lvl)
    {
        if(viz.device()){
            if(_init(viz, pool, lvl) != std::error_code())
                _wipe();
        }
    }

    ViCommandBuffer::~ViCommandBuffer()
    {
        kill();
    }

    std::error_code ViCommandBuffer::_init(ViVisualizer& viz, VkCommandPool pool, VqCommandBufferLevel lvl)
    {
        VqCommandBufferAllocateInfo cbai;
        cbai.level                  = (VkCommandBufferLevel) lvl;
        cbai.commandBufferCount     = 1;
        cbai.commandPool            = pool;
        if(vkAllocateCommandBuffers(viz.device(), &cbai,  &m_buffer) != VK_SUCCESS)
            return errors::command_buffer_cant_create();
        
        m_viz   = &viz;
        m_pool  = pool;
        return {};
    }
    
    void            ViCommandBuffer::_kill()
    {
        vkFreeCommandBuffers(m_viz->device(), m_pool, 1, &m_buffer);
    }
    
    void            ViCommandBuffer::_wipe()
    {
        m_viz       = nullptr;
        m_pool      = nullptr;
        m_buffer    = nullptr;
    }

    std::error_code ViCommandBuffer::init(ViVisualizer&viz, VkCommandPool pool, VqCommandBufferLevel lvl)
    {
        if(!consistent())
            return errors::command_buffer_bad_state();
        if(m_buffer)
            return errors::command_buffer_existing();
        if(!viz.device())
            return errors::vizualizer_uninitialized();
        if(!pool)
            return errors::command_pool_null_pointer();
        
        std::error_code ec = _init(viz, pool, lvl);
        if(ec != std::error_code())
            _wipe();
        return ec;
    }
    
    void            ViCommandBuffer::kill()
    {
        if(valid()){
            _kill();
        }
        _wipe();
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
