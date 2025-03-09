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
#include <yv/ViDevice.hpp>
#include <yv/ViVisualizer.hpp>

namespace yq::tachyon {
    ViCommandBuffer::ViCommandBuffer(ViDevice& dev, VkCommandPool pool, VqCommandBufferLevel lvl) : m_device(dev)
    {
        if(_init(pool, lvl) != std::error_code())
            _wipe();
    }

    ViCommandBuffer::~ViCommandBuffer()
    {
        kill();
    }

    std::error_code ViCommandBuffer::_init(VkCommandPool pool, VqCommandBufferLevel lvl)
    {
        VqCommandBufferAllocateInfo cbai;
        cbai.level                  = (VkCommandBufferLevel) lvl;
        cbai.commandBufferCount     = 1;
        cbai.commandPool            = pool;
        VkResult res = vkAllocateCommandBuffers(m_device.device(), &cbai,  &m_buffer);
        if(res != VK_SUCCESS){
            vizWarning << "vkAllocateCommandBuffers(1): vkResult " << (int32_t) res;
            return errors::command_buffer_cant_create();
        }
        
        m_pool      = pool;
        return {};
    }
    
    void            ViCommandBuffer::_kill()
    {
        if(m_pool && m_buffer){
            vkFreeCommandBuffers(m_device.device(), m_pool, 1, &m_buffer);
        }
    }
    
    void            ViCommandBuffer::_wipe()
    {
        m_pool      = nullptr;
        m_buffer    = nullptr;
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
        return m_buffer ? static_cast<bool>(m_pool) : !m_pool;
    }
    
    bool            ViCommandBuffer::valid() const
    {
        return m_pool && m_buffer;
    }
}
