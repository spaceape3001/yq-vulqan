////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/preamble.hpp>
#include <tachyon/preamble.hpp>
#include <tachyon/gpu/VqStructs.hpp>
#include <vulkan/vulkan_core.h>
#include <0/math/preamble.hpp>

#include <expected>
#include <optional>
#include <set>
#include <string>
#include <vector>

/*
    The VqCore is about providing simple wrappers for boiler plate code, using the prefix "Vq" in lieu of "Vk".  
    For structures, it's adding in the proper stype assignment. 
*/

namespace yq::tachyon {
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

    bool                                    vqHasStencilComponent(VkFormat);

    std::string                             vqName(VkPhysicalDevice);

    std::set<std::string>                   vqNameSet(const std::vector<VkExtensionProperties>&);
    std::set<std::string>                   vqNameSet(const std::vector<VkLayerProperties>&);
    VkQueueFlags                            vqOrFlags(const std::vector<VkQueueFamilyProperties>&);

    Expect<uint32_t>                        vqFindFirstGraphicsQueue(const std::vector<VkQueueFamilyProperties>&);
    Expect<uint32_t>                        vqFindFirstPresentQueue(VkPhysicalDevice, VkSurfaceKHR);

    struct VqQueueFamilyIndices {
        std::optional<uint32_t> graphics;
        std::optional<uint32_t> compute;
        std::optional<uint32_t> present;
        std::optional<uint32_t> videoDecode;
        std::optional<uint32_t> videoEncode;
    };

    VqQueueFamilyIndices                    vqFindQueueFamilies(VkPhysicalDevice device, VkSurfaceKHR);

    //! Creates vulkan create info from our specification
    VkImageViewCreateInfo   vqCreateInfo(const ImageViewInfo&);
    VkSamplerCreateInfo     vqCreateInfo(const SamplerInfo&);
    
    //! Converts our color into vulkan clear value
    VkClearValue            vqClearValue(const RGBA4F&);
    
    //! Extracts vulkan clear value into our color
    RGBA4F                  vqExtractRGBA4F(const VkClearValue&);
}
