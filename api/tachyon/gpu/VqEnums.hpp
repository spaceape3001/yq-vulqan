////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vulkan/vulkan_core.h>
#include <string_view>

namespace yq::tachyon {
    std::string_view                        to_string(VkColorSpaceKHR);
    std::string_view                        to_string(VkDebugReportObjectTypeEXT);
    std::string_view                        to_string(VkDynamicState);
    std::string_view                        to_string(VkFormat);
    std::string_view                        to_string(VkPhysicalDeviceType);
}
