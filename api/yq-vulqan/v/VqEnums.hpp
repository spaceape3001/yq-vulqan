////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vulkan/vulkan_core.h>
#include <string_view>

namespace yq::tachyon {
    std::string_view    to_string_view(VkColorSpaceKHR);
    std::string_view    to_string_view(VkDebugReportObjectTypeEXT);
    std::string_view    to_string_view(VkDynamicState);
    std::string_view    to_string_view(VkFormat);
    std::string_view    to_string_view(VkPhysicalDeviceType);
}
