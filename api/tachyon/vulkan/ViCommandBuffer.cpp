////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/vulkan/ViCommandBuffer.hpp>
#include <tachyon/errors.hpp>
#include <tachyon/logging.hpp>
//#include <yq/tachyon/v/VqEnumerations.hpp>
#include <tachyon/vulkan/VqStructs.hpp>
#include <tachyon/vulkan/ViDevice.hpp>
#include <tachyon/vulkan/ViVisualizer.hpp>

namespace yq::tachyon {
    ViCommandBuffer::ViCommandBuffer(ViDevice& dev, VkCommandPool pool, VqCommandBufferLevel lvl) : 
        m_device(dev), m_pool(pool)
    {
        VqCommandBufferAllocateInfo cbai;
        cbai.level                  = (VkCommandBufferLevel) lvl;
        cbai.commandBufferCount     = 1;
        cbai.commandPool            = pool;
        VkResult res = vkAllocateCommandBuffers(m_device.device(), &cbai,  &m_buffer);
        if(res != VK_SUCCESS){
            vizWarning << "vkAllocateCommandBuffers(1): vkResult " << (int32_t) res;
            m_pool  = nullptr;
            return;
        }
    }

    ViCommandBuffer::~ViCommandBuffer()
    {
        if(m_pool && m_buffer){
            vkFreeCommandBuffers(m_device.device(), m_pool, 1, &m_buffer);
        }
        m_pool      = nullptr;
        m_buffer    = nullptr;
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
