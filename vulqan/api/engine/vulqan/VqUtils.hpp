////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Result.hpp>
#include <vulkan/vulkan_core.h>
#include <engine/vulqan/VqStructs.hpp>

#include <optional>
#include <set>
#include <string>
#include <vector>

/*
    The VqCore is about providing simple wrappers for boiler plate code, using the prefix "Vq" in lieu of "Vk".  
    For structures, it's adding in the proper stype assignment. 
*/

namespace yq {
    namespace engine {
        std::vector<VkExtensionProperties>              vqEnumerateDeviceExtensionProperties(VkPhysicalDevice, const char* layerName=nullptr);
        std::vector<VkLayerProperties>                  vqEnumerateDeviceLayerProperties(VkPhysicalDevice);
        std::vector<VkExtensionProperties>              vqEnumerateInstanceExtensionProperties(const char* layerName=nullptr);
        std::vector<VkLayerProperties>                  vqEnumerateInstanceLayerProperties();
        std::vector<VkPhysicalDeviceGroupProperties>    vqEnumeratePhysicalDeviceGroups(VkInstance i=nullptr);
        std::vector<VkPhysicalDevice>                   vqEnumeratePhysicalDevices(VkInstance i=nullptr);
        
        
        VkPhysicalDevice                        vqFirstDevice(VkInstance i=nullptr);
        
        // not in the SDK
        //std::vector<VkPhysicalDeviceGroupProperties>    vqEnumeratePhysicalDeviceGroupsKHR(VkInstance);

        std::vector<VkQueueFamilyProperties>    vqGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice);
        std::vector<VkSurfaceFormatKHR>         vqGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice, VkSurfaceKHR);
        std::vector<VkPresentModeKHR>           vqGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice, VkSurfaceKHR);
        std::vector<const char*>                vqGlfwRequiredExtensions();

        std::string                             vqName(VkPhysicalDevice);

        std::set<std::string>                   vqNameSet(const std::vector<VkExtensionProperties>&);
        std::set<std::string>                   vqNameSet(const std::vector<VkLayerProperties>&);
        VkQueueFlags                            vqOrFlags(const std::vector<VkQueueFamilyProperties>&);

        Result<uint32_t>                        vqFindFirstGraphicsQueue(const std::vector<VkQueueFamilyProperties>&);
        Result<uint32_t>                        vqFindFirstPresentQueue(VkPhysicalDevice, VkSurfaceKHR);
        
        

        struct VqQueueFamilyIndices {
            std::optional<uint32_t> graphics;
            std::optional<uint32_t> compute;
            std::optional<uint32_t> present;
            std::optional<uint32_t> videoDecode;
            std::optional<uint32_t> videoEncode;
        };

        VqQueueFamilyIndices                    vqFindQueueFamilies(VkPhysicalDevice device, VkSurfaceKHR);


        std::string_view                        to_string(VkColorSpaceKHR);
        std::string_view                        to_string(VkDebugReportObjectTypeEXT);
        std::string_view                        to_string(VkDynamicState);
        std::string_view                        to_string(VkFormat);
        std::string_view                        to_string(VkPhysicalDeviceType);
    }
}
