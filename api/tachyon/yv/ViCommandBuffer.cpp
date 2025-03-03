////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yv/ViCommandBuffer.hpp>
#include <yt/errors.hpp>
#include <yt/logging.hpp>
//#include <yq/tachyon/v/VqEnumerations.hpp>
#include <yv/VqStructs.hpp>
#include <yv/ViVisualizer.hpp>

namespace yq::tachyon {
    ViCommandBuffer::ViCommandBuffer()
    {
    }
    
    ViCommandBuffer::ViCommandBuffer(VkDevice dev, VkCommandPool pool, VqCommandBufferLevel lvl)
    {
        if(dev){
            if(_init(dev, pool, lvl) != std::error_code())
                _wipe();
        }
    }

    ViCommandBuffer::ViCommandBuffer(ViVisualizer& viz, VkCommandPool pool, VqCommandBufferLevel lvl) :
        ViCommandBuffer(viz.device(), pool, lvl)
    {
    }

    ViCommandBuffer::~ViCommandBuffer()
    {
        kill();
    }

    std::error_code ViCommandBuffer::_init(VkDevice dev, VkCommandPool pool, VqCommandBufferLevel lvl)
    {
        VqCommandBufferAllocateInfo cbai;
        cbai.level                  = (VkCommandBufferLevel) lvl;
        cbai.commandBufferCount     = 1;
        cbai.commandPool            = pool;
        VkResult res = vkAllocateCommandBuffers(dev, &cbai,  &m_buffer);
        if(res != VK_SUCCESS){
            vizWarning << "vkAllocateCommandBuffers(1): vkResult " << (int32_t) res;
            return errors::command_buffer_cant_create();
        }
        
        m_device    = dev;
        m_pool      = pool;
        return {};
    }
    
    void            ViCommandBuffer::_kill()
    {
        vkFreeCommandBuffers(m_device, m_pool, 1, &m_buffer);
    }
    
    void            ViCommandBuffer::_wipe()
    {
        m_device    = nullptr;
        m_pool      = nullptr;
        m_buffer    = nullptr;
    }

    std::error_code ViCommandBuffer::init(ViVisualizer&viz, VkCommandPool pool, VqCommandBufferLevel lvl)
    {
        return init(viz.device(), pool, lvl);
    }

    std::error_code ViCommandBuffer::init(VkDevice dev, VkCommandPool pool, VqCommandBufferLevel lvl)
    {
        if(!consistent())
            return errors::command_buffer_bad_state();
        if(m_buffer)
            return errors::command_buffer_existing();
        if(!dev)
            return errors::visualizer_uninitialized();
        if(!pool)
            return errors::command_pool_null_pointer();
        
        std::error_code ec = _init(dev, pool, lvl);
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
        return m_device ? (m_pool && m_buffer) : (!m_pool && !m_buffer);
    }
    
    bool            ViCommandBuffer::valid() const
    {
        return m_device && m_pool && m_buffer;
    }
}
