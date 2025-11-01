////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <vulkan/vulkan_core.h>

bool operator==(const VkOffset2D&, const VkOffset2D&);
bool operator==(const VkExtent2D&, const VkExtent2D&);
bool operator==(const VkRect2D&, const VkRect2D&);
bool operator==(const VkViewport&, const VkViewport&);

