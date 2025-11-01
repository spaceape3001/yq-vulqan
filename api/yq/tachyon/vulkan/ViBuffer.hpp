////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <vk_mem_alloc.h>
#include <vulkan/vulkan_core.h>
#include <system_error>

namespace yq {
    class Memory;
}

namespace yq::tachyon {
    class ViDevice;
    class Buffer;
    
    struct ViBufferOptions {
        VmaMemoryUsage      usage   = VMA_MEMORY_USAGE_CPU_TO_GPU;
        //! Maps (or keeps mapped) the data
        bool                mapped  = false;
    };
    
    class ViBuffer : public RefCount {
    public:
        ViBuffer();
        ViBuffer(ViDevice&, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu = VMA_MEMORY_USAGE_AUTO);
        ViBuffer(ViDevice&, const Memory& v, VkBufferUsageFlags buf, const ViBufferOptions& opts = {});
        ViBuffer(ViDevice&, const Buffer& v, const ViBufferOptions& opts = {});
        ~ViBuffer();
        
        operator VkBuffer() const { return m_buffer; }

        VmaAllocation       allocation() const { return m_allocation; }
        VkBuffer            buffer() const { return m_buffer; }
        bool                consistent() const;
        //! Data pointer (when mapped)
        void*               data() const { return m_data; }
        bool                mapped() const { return static_cast<bool>(m_data); }
        size_t              size() const { return m_size; }
        bool                valid() const;
        ViDevice*       visualizer() const { return m_viz; }
        
        //! Count from the original buffer... (zero if unspecified)
        size_t              count() const { return m_count; }

        std::error_code     allocate(ViDevice&, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu = VMA_MEMORY_USAGE_AUTO);
        std::error_code     create(ViDevice&, const Memory& v, VkBufferUsageFlags buf, const ViBufferOptions& opts = {});
        std::error_code     create(ViDevice&, const Buffer& v, const ViBufferOptions& opts = {});
        void                kill();
        std::error_code     map();
        std::error_code     unmap();

    private:
        
        ViBuffer(const ViBuffer&) = delete;
        ViBuffer(ViBuffer&&) = delete;
        ViBuffer& operator=(const ViBuffer&) = delete;
        ViBuffer& operator=(ViBuffer&&) = delete;
    
        std::error_code _allocate(ViDevice&, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu = VMA_MEMORY_USAGE_AUTO);
        std::error_code _create(ViDevice&, const Memory& v, VkBufferUsageFlags buf, const ViBufferOptions& opts = {});
        std::error_code _create(ViDevice&, const Buffer& v, const ViBufferOptions& opts = {});
        void            _kill();
        void            _wipe();
    
        ViDevice*   m_viz        = nullptr;
        VkBuffer        m_buffer     = nullptr;
        VmaAllocation   m_allocation = nullptr;
        void*           m_data       = nullptr;
        size_t          m_size       = 0ULL;
        size_t          m_count      = 0ULL;    // from the buffer...
    };
}
