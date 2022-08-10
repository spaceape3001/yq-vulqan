////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "VqBuffer.hpp"
#include "VqException.hpp"
#include <engine/Visualizer.hpp>
#include "VqStructs.hpp"

namespace yq {
    namespace engine {
        VqBuffer::VqBuffer(Visualizer&viz, VkBufferUsageFlags uf, const void* data, size_t sz) 
        {
            assert(data);
            assert(sz);
            
            m_size      = sz;
            m_device    = viz.m_device;
            m_allocator = viz.m_allocator;
            
            VqBufferCreateInfo  bufferInfo;
            bufferInfo.size         = m_size;
            bufferInfo.usage        = uf;
            
            VmaAllocationCreateInfo vmaallocInfo = {};
            vmaallocInfo.usage = VMA_MEMORY_USAGE_CPU_TO_GPU;
            VmaAllocationInfo   vai;
            if(vmaCreateBuffer(m_allocator, &bufferInfo, &vmaallocInfo, &m_buffer, &m_allocation, &vai) != VK_SUCCESS)
                throw VqException("Cannot allocate buffer!");
            
            void* dst = nullptr;
            vmaMapMemory(m_allocator, m_allocation, &dst);
            memcpy(dst, data, m_size);
            vmaUnmapMemory(m_allocator, m_allocation);            
        }
        
        VqBuffer::VqBuffer(VqBuffer&& mv)
        {
            move(std::move(mv));
        }
        
        VqBuffer& VqBuffer::operator=(VqBuffer&&mv)
        {
            if(this != &mv){
                dtor();
                move(std::move(mv));
            }
            return *this;
        }
        
        VqBuffer::~VqBuffer()
        {
            dtor();
        }
        
        void    VqBuffer::dtor()
        {
            if(m_allocation){
                vmaDestroyBuffer(m_allocator, m_buffer, m_allocation);
                m_allocation = nullptr;
                m_buffer = nullptr;
            }
        }
        
        void    VqBuffer::move(VqBuffer&& mv)
        {
            steal(m_device, mv.m_device);
            steal(m_allocator, mv.m_allocator);
            steal(m_allocation, mv.m_allocation);
            steal(m_buffer, mv.m_buffer);
            m_size      = mv.m_size;
        }
    }
}
