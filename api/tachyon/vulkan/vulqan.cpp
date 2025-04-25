////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/vulkan/vulqan.hpp>

//  UNITY BUILD HERE (if being done)

bool operator==(const VkOffset2D&a, const VkOffset2D&b)
{
    return (a.x == b.x) && (a.y == b.y);
}

bool operator==(const VkExtent2D&a, const VkExtent2D&b)
{
    return (a.width == b.width) && (a.height == b.height);
}

bool operator==(const VkRect2D&a, const VkRect2D&b)
{
    return (a.offset == b.offset) && (a.extent == b.extent);
}

bool operator==(const VkViewport&a, const VkViewport&b)
{
    return (a.x == b.x) && (a.y == b.y) && 
        (a.width == b.width) && (a.height == b.height) && 
        (a.minDepth == b.minDepth) && (a.maxDepth == b.maxDepth);
}

