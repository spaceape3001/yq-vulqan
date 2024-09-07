////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vk_mem_alloc.h>
#include <vulkan/vulkan_core.h>
#include <system_error>

namespace yq::tachyon {
    struct ViVisualizer;
    class Buffer;
    class Memory;
    
    struct ViBuffer {
        VkBuffer                buffer      = nullptr;
        VmaAllocation           allocation  = nullptr;
        
        std::error_code     allocate(ViVisualizer&, size_t cb, VkBufferUsageFlags buf, VmaMemoryUsage vmu);
        std::error_code     create(ViVisualizer&, const Memory& v, VkBufferUsageFlags buf, VmaMemoryUsage vmu);
        std::error_code     create(ViVisualizer&, const Buffer& v);
        void                destroy(ViVisualizer&);
    };
}
