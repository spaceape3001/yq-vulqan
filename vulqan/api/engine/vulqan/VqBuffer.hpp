////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/trait/not_copyable.hpp>
#include <vulkan/vulkan_core.h>
#include <vk_mem_alloc.h>
#include <span>

namespace yq {
    namespace engine {
        struct Visualizer;
        
        class VqBuffer : trait::not_copyable {
        public:
        
        
            VqBuffer(){}
            
            VqBuffer(Visualizer&, VkBufferUsageFlags, const void*, size_t);
            
            template <typename T>
            VqBuffer(Visualizer&, VkBufferUsageFlags, std::span<T>);

            template <typename T>
            VqBuffer(Visualizer&, VkBufferUsageFlags, std::span<const T>);

            template <typename T, size_t N>
            VqBuffer(Visualizer&, VkBufferUsageFlags, const T(&)[N]);

            VqBuffer(VqBuffer&&);
            VqBuffer& operator=(VqBuffer&&);
            ~VqBuffer();
            
            bool    good() const noexcept { return m_buffer != nullptr; }
            operator bool() const noexcept { return good(); }
            operator VkBuffer() const noexcept { return m_buffer; }
            VkBuffer buffer() const noexcept { return m_buffer; }
            
            size_t  size() const { return m_size; }
        
        private:
            void    dtor();
            void    move(VqBuffer&&);
            
            void            assign(const void*, size_t);
            
            VkDevice        m_device        = nullptr;
            VmaAllocator    m_allocator     = nullptr;
            VkBuffer        m_buffer        = nullptr;
            VmaAllocation   m_allocation    = nullptr;
            size_t          m_size          = 0;
        };

        template <typename T>
        VqBuffer::VqBuffer(Visualizer& w, VkBufferUsageFlags flags, std::span<T> data) : 
            VqBuffer(w, flags, data.data(), data.size() * sizeof(T))
        {
        }
        

        template <typename T>
        VqBuffer::VqBuffer(Visualizer& w, VkBufferUsageFlags flags, std::span<const T>data) :
            VqBuffer(w, flags, data.data(), data.size() * sizeof(T))
        {
        }

        template <typename T, size_t N>
        VqBuffer::VqBuffer(Visualizer&w, VkBufferUsageFlags flags, const T (&data) [N]) : 
            VqBuffer(w,flags, data,N*sizeof(T))
        {
        }
    }
}
