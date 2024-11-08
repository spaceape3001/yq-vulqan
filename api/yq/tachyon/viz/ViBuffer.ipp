////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViBuffer.hpp"

#include <yq/core/Memory.hpp>
#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/buffer/Buffer.hpp>
#include <yq/tachyon/v/VqStructs.hpp>
#include <yq/tachyon/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    namespace errors {
        using buffer_bad_state                  = error_db::entry<"Buffer is in a bad state">;
        using buffer_cant_allocate              = error_db::entry<"Buffer is unable to allocate requested memory">;
        using buffer_cant_map_memory            = error_db::entry<"Unable to map buffer memory">;
        using buffer_empty                      = error_db::entry<"Buffer is empty">;
        using buffer_existing                   = error_db::entry<"Buffer already created">;
        using buffer_uninitialized              = error_db::entry<"Attempting to use an uninitialized buffer">;
        using buffer_manager_uninitialized      = error_db::entry<"Buffer manager is uninitialized">;
    }

    ViBuffer::ViBuffer()
    {
    }
    
    ViBuffer::~ViBuffer()
    {
        kill();
    }

    ViBuffer::ViBuffer(ViVisualizer&viz, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu)
    {
        if(viz.device() && cb){
            if(_allocate(viz, cb, buf, vmu) != std::error_code()){
                _kill();
                _wipe();
            }
        }
    }
    
    ViBuffer::ViBuffer(ViVisualizer&viz, const Memory& v, VkBufferUsageFlags buf, const ViBufferOptions& opts)
    {
        if(viz.device() && v.bytes()){
            if(_create(viz, v, buf, opts) != std::error_code()){
                _kill();
                _wipe();
            }
        }
    }
    
    ViBuffer::ViBuffer(ViVisualizer&viz, const Buffer& v, const ViBufferOptions& opts) : 
        ViBuffer(viz, v.memory, v.usage.value(), opts)
    {
    }

    std::error_code ViBuffer::_allocate(ViVisualizer&viz, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu)
    {
        VqBufferCreateInfo  bufferInfo;
        bufferInfo.size         = (uint32_t) cb;
        bufferInfo.usage        = buf & VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM;
        
        VmaAllocationCreateInfo vmaallocInfo = {};
        vmaallocInfo.usage = vmu;
        VmaAllocationInfo   vai;
        
        VkResult res = vmaCreateBuffer(viz.allocator(), &bufferInfo, &vmaallocInfo, &m_buffer, &m_allocation, &vai);
        if(res != VK_SUCCESS){
            vizWarning << "vmaCreateBuffer(" << cb << "): VkResult " << (int32_t) res;
            return errors::buffer_cant_allocate();
        }

        m_size  = cb;
        m_viz   = &viz;
        return std::error_code();
    }
    
    std::error_code ViBuffer::_create(ViVisualizer&viz, const Memory& v, VkBufferUsageFlags buf, const ViBufferOptions& opts)
    {
        std::error_code     ec  = _allocate(viz, v.bytes(), buf, opts.usage);
        if(ec)
            return ec;
        if(vmaMapMemory(m_viz->allocator(), m_allocation, &m_data) != VK_SUCCESS)
            return errors::buffer_cant_map_memory();
        memcpy(m_data, v.data(), v.bytes());
        if(!opts.mapped){
            vmaUnmapMemory(m_viz->allocator(), m_allocation);
            m_data  = nullptr;
        }
        return {};
    }
    
    std::error_code ViBuffer::_create(ViVisualizer&viz, const Buffer& v, const ViBufferOptions& opts)
    {
        return _create(viz, v.memory, v.usage.value(), opts);
    }

    void            ViBuffer::_kill()
    {
        if(m_data){
            vmaUnmapMemory(m_viz->allocator(), m_allocation);
            m_data  = nullptr;
        }
        if(m_allocation){
            vmaDestroyBuffer(m_viz->allocator(), m_buffer, m_allocation);
        }
    }

    void                ViBuffer::_wipe()
    {
        m_buffer        = nullptr;
        m_allocation    = nullptr;
        m_viz           = nullptr;
        m_size          = 0;
        m_data          = nullptr;
    }

    std::error_code     ViBuffer::allocate(ViVisualizer&viz, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu)
    {
        if(m_viz || m_buffer || m_allocation)
            return errors::buffer_existing();
        if(m_data)
            return errors::buffer_bad_state();
        if(!cb)
            return errors::buffer_empty();
        if(!viz.device())
            return errors::visualizer_uninitialized();
        
        std::error_code ec =  _allocate(viz, cb, buf, vmu);
        if(ec != std::error_code())
            _kill();
        return ec;
    }
    
    bool                ViBuffer::consistent() const
    {
        return m_viz ? (m_allocation && m_buffer && m_viz -> device()) : (!m_allocation && !m_buffer);
    }

    std::error_code     ViBuffer::create(ViVisualizer&viz, const Memory& v, VkBufferUsageFlags buf, const ViBufferOptions&opts)
    {
        if(m_viz || m_buffer || m_allocation)
            return errors::buffer_existing();
        if(m_data)
            return errors::buffer_bad_state();
        if(!v.bytes())
            return errors::buffer_empty();
        if(!viz.device())
            return errors::visualizer_uninitialized();
        
        std::error_code ec = _create(viz, v, buf, opts);
        if(ec != std::error_code())
            _kill();
        return ec;
    }
    
    std::error_code     ViBuffer::create(ViVisualizer&viz, const Buffer& v, const ViBufferOptions&opts)
    {
        if(m_viz || m_buffer || m_allocation)
            return errors::buffer_existing();
        if(m_data)
            return errors::buffer_bad_state();
        if(!v.memory.bytes())
            return errors::buffer_empty();
        if(!viz.device())
            return errors::visualizer_uninitialized();

        std::error_code ec = _create(viz, v, opts);
        if(ec != std::error_code())
            _kill();
        return ec;
    }
    
    void                ViBuffer::kill()
    {
        if(valid()){
            _kill();
        }
        _wipe();
    }

    std::error_code     ViBuffer::map()
    {
        if(!valid())
            return errors::buffer_uninitialized();
        if(!m_data){
            if(vmaMapMemory(m_viz->allocator(), m_allocation, &m_data) != VK_SUCCESS){
                m_data  = nullptr;
                return errors::buffer_cant_map_memory();
            }
        }
        return {};
    }
    
    std::error_code     ViBuffer::unmap()
    {
        if(!valid())
            return errors::buffer_uninitialized();
        if(m_data){
            vmaUnmapMemory(m_viz->allocator(), m_allocation);
            m_data  = nullptr;
        }
        return {};
    }

    bool                ViBuffer::valid() const
    {
        return m_viz && m_allocation && m_buffer && m_viz -> device();
    }

}

