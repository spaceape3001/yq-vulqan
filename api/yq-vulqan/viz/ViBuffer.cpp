////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViBuffer.hpp"

#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/memory/Buffer.hpp>
#include <yq-vulqan/memory/Memory.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    std::error_code     ViBuffer::allocate(ViVisualizer&viz, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu)
    {
        if(!cb)
            return errors::SKIPPING_ZERO_SIZED_BUFFER();
        
        VqBufferCreateInfo  bufferInfo;
        bufferInfo.size         = cb;
        bufferInfo.usage        = buf & VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM;
        
        VmaAllocationCreateInfo vmaallocInfo = {};
        vmaallocInfo.usage = vmu;
        VmaAllocationInfo   vai;
        if(vmaCreateBuffer(viz.allocator(), &bufferInfo, &vmaallocInfo, &buffer, &allocation, &vai) != VK_SUCCESS)
            return errors::INSUFFICIENT_GPU_MEMORY();
        return std::error_code();
    }
    
    std::error_code     ViBuffer::create(ViVisualizer&viz, const Memory& v, VkBufferUsageFlags buf, VmaMemoryUsage vmu)
    {
        std::error_code     ec  = allocate(viz, v.bytes(), buf, vmu);
        if(ec)
            return ec;
        
        void* dst = nullptr;
        vmaMapMemory(viz.allocator(), allocation, &dst);
        memcpy(dst, v.data(), v.bytes());
        vmaUnmapMemory(viz.allocator(), allocation);
        return std::error_code();
    }
    
    std::error_code     ViBuffer::create(ViVisualizer&viz, const Buffer& v)
    {
        return create(viz, v.memory, (VkBufferUsageFlags) v.usage.value(), VMA_MEMORY_USAGE_CPU_TO_GPU);
    }
    
    void                ViBuffer::destroy(ViVisualizer&viz)
    {
        if(allocation && buffer){
            vmaDestroyBuffer(viz.allocator(), buffer, allocation);
            allocation = nullptr;
            buffer = nullptr;
        }
    }
}

