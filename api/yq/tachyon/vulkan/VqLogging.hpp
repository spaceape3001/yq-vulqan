////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Logging.hpp>
#include <vulkan/vulkan_core.h>

namespace yq { 
    class Stream; 
    Stream& operator<<(Stream&, const VkExtent2D&);
    Stream& operator<<(Stream&, const VkExtent3D&);
}

log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream&, const VkExtent2D&);
log4cpp::CategoryStream& operator<<(log4cpp::CategoryStream&, const VkExtent3D&);
