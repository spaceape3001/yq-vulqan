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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  ADAPTER FUNCTIONS
//
//  Keep these listed alphabetically and we'll deprecate/remove as functions are brought into the vulkan standard linkage.
//  Arguments should reflect the documentation, except for
//  a.  VkInstance which will be taken from the VulqanManager
//  b.  Nonessential trailing arguments can be defaulted to null/zero/false
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

VkResult    vkCreateDebugReportCallback(
                const VkDebugReportCallbackCreateInfoEXT* pCreateInfo,
                const VkAllocationCallbacks* pAllocator,
                VkDebugReportCallbackEXT* pCallback
            );
            
VkResult    vkCreateDebugUtilsMessenger(
                const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                const VkAllocationCallbacks* pAllocator, 
                VkDebugUtilsMessengerEXT* pMessenger
            );

void        vkDestroyDebugReportCallback(
                VkDebugReportCallbackEXT        callback,
                const VkAllocationCallbacks*    pAllocator = nullptr
            );
            
void        vkDestroyDebugUtilsMessenger(
                VkDebugUtilsMessengerEXT messenger, 
                const VkAllocationCallbacks* pAllocator = nullptr
            );
            
VkResult    vkSetDebugUtilsObjectName(
                VkDevice device, 
                const VkDebugUtilsObjectNameInfoEXT* pNameInfo
            );
