////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VqUtils.hpp"
#include <basic/CollectionUtils.hpp>
#include <engine/Application.hpp>
#include <GLFW/glfw3.h>

namespace yq {
    namespace engine {
        std::vector<VkExtensionProperties>   vqEnumerateDeviceExtensionProperties(VkPhysicalDevice device, const char* layerName)
        {
            uint32_t                        count  = 0;
            vkEnumerateDeviceExtensionProperties(device, layerName, &count, nullptr);
            std::vector<VkExtensionProperties>   ret(count);
            if(count)
                vkEnumerateDeviceExtensionProperties(device, layerName, &count, ret.data());
            return ret;
        }

        std::vector<VkLayerProperties>       vqEnumerateDeviceLayerProperties(VkPhysicalDevice device)
        {
            uint32_t                        count  = 0;
            vkEnumerateDeviceLayerProperties(device, &count, nullptr);
            std::vector<VkLayerProperties>   ret(count);
            if(count)
                vkEnumerateDeviceLayerProperties(device, &count, ret.data());
            return ret;
        }

        std::vector<VkExtensionProperties>   vqEnumerateInstanceExtensionProperties(const char* layerName)
        {
            uint32_t                        count  = 0;
            vkEnumerateInstanceExtensionProperties(layerName, &count, nullptr);
            std::vector<VkExtensionProperties>   ret(count);
            if(count)
                vkEnumerateInstanceExtensionProperties(layerName, &count, ret.data());
            return ret;
        }

        std::vector<VkLayerProperties>       vqEnumerateInstanceLayerProperties()
        {
            uint32_t                        count  = 0;
            vkEnumerateInstanceLayerProperties(&count, nullptr);
            std::vector<VkLayerProperties>   ret(count);
            if(count)
                vkEnumerateInstanceLayerProperties(&count, ret.data());
            return ret;
        }

        std::vector<VkPhysicalDeviceGroupProperties>    vqEnumeratePhysicalDeviceGroups(VkInstance inst)
        {
            if(!inst)
                inst    = Application::vulkan();
            uint32_t    count   = 0;
            vkEnumeratePhysicalDeviceGroups(inst, &count, nullptr);
            std::vector<VkPhysicalDeviceGroupProperties>    ret(count);
            if(count)
                vkEnumeratePhysicalDeviceGroups(inst, &count, ret.data());
            return ret;
        }

    #if 0
        // not in the SDK?
        std::vector<VkPhysicalDeviceGroupProperties>    vqEnumeratePhysicalDeviceGroupsKHR(VkInstance inst)
        {  
            if(!inst)
                inst    = Application::vulkan();
            uint32_t    count   = 0;
            vkEnumeratePhysicalDeviceGroupsKHR(inst, &count, nullptr);
            std::vector<VkPhysicalDeviceGroupProperties>    ret(count);
            if(count)
                vkEnumeratePhysicalDeviceGroupsKHR(inst, &count, ret.data());
            return ret;
        }
    #endif

        std::vector<VkPhysicalDevice>        vqEnumeratePhysicalDevices(VkInstance inst)
        {
            if(!inst)
                inst    = Application::vulkan();
            uint32_t    count   = 0;
            vkEnumeratePhysicalDevices(inst, &count, nullptr);
            std::vector<VkPhysicalDevice>    ret(count);
            if(count)
                vkEnumeratePhysicalDevices(inst, &count, ret.data());
            return ret;
        }


        Result<uint32_t>                vqFindFirstGraphicsQueue(const std::vector<VkQueueFamilyProperties>&queues)
        {
            for(uint32_t i=0;i<queues.size();++i)
                if(queues[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
                    return { i, true };
            return {};
        }

        Result<uint32_t>                vqFindFirstPresentQueue(VkPhysicalDevice dev, VkSurfaceKHR srf)
        {
            uint32_t        count = 0;
            vkGetPhysicalDeviceQueueFamilyProperties(dev,&count,nullptr);
            for(uint32_t i=0;i<count;++i){
                VkBool32 presentSupport = false;
                vkGetPhysicalDeviceSurfaceSupportKHR(dev, i, srf, &presentSupport);
                if(presentSupport)
                    return { i, true };
            }
            return {};
        }

        VqQueueFamilyIndices                 vqFindQueueFamilies(VkPhysicalDevice dev, VkSurfaceKHR srf)
        {
            VqQueueFamilyIndices    ret;
            uint32_t        count = 0;
            vkGetPhysicalDeviceQueueFamilyProperties(dev,&count,nullptr);
            std::vector<VkQueueFamilyProperties> qfp(count);
            if(count){
                vkGetPhysicalDeviceQueueFamilyProperties(dev,&count,qfp.data());
                for(uint32_t i=0;i<count;++i){
                    if((qfp[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) && !ret.graphics.has_value())
                        ret.graphics = i;
                    if((qfp[i].queueFlags & VK_QUEUE_COMPUTE_BIT) && !ret.compute.has_value())
                        ret.compute = i;
                    if((qfp[i].queueFlags & VK_QUEUE_VIDEO_DECODE_BIT_KHR) && !ret.videoDecode.has_value())
                        ret.videoDecode = i;
                    if((qfp[i].queueFlags & VK_QUEUE_VIDEO_ENCODE_BIT_KHR) && !ret.videoEncode.has_value())
                        ret.videoEncode = i;
                    VkBool32 presentSupport = false;
                    vkGetPhysicalDeviceSurfaceSupportKHR(dev, i, srf, &presentSupport);
                    if(presentSupport && !ret.present.has_value())
                        ret.present = i;
                }
            }
            return ret;
        }

        VkPhysicalDevice                     vqFirstDevice(VkInstance inst)
        {
            if(!inst)
                inst    = Application::vulkan();
            for(VkPhysicalDevice v : vqEnumeratePhysicalDevices(inst)){
                if(v)
                    return v;
            }
            return nullptr;
        }

        std::vector<VkQueueFamilyProperties> vqGetPhysicalDeviceQueueFamilyProperties(VkPhysicalDevice dev)
        {
            uint32_t        count = 0;
            vkGetPhysicalDeviceQueueFamilyProperties(dev,&count,nullptr);
            std::vector<VkQueueFamilyProperties> ret(count);
            if(count)
                vkGetPhysicalDeviceQueueFamilyProperties(dev,&count,ret.data());
            return ret;
        }

        std::vector<VkSurfaceFormatKHR>      vqGetPhysicalDeviceSurfaceFormatsKHR(VkPhysicalDevice dev, VkSurfaceKHR surf)
        {
            uint32_t        count = 0;
            vkGetPhysicalDeviceSurfaceFormatsKHR(dev,surf, &count,nullptr);
            std::vector<VkSurfaceFormatKHR> ret(count);
            if(count)
                vkGetPhysicalDeviceSurfaceFormatsKHR(dev,surf, &count,ret.data());
            return ret;
        }

        std::vector<VkPresentModeKHR>           vqGetPhysicalDeviceSurfacePresentModesKHR(VkPhysicalDevice dev, VkSurfaceKHR surf)
        {
            uint32_t        count = 0;
            vkGetPhysicalDeviceSurfacePresentModesKHR(dev,surf, &count,nullptr);
            std::vector<VkPresentModeKHR> ret(count);
            if(count)
                vkGetPhysicalDeviceSurfacePresentModesKHR(dev,surf, &count,ret.data());
            return ret;
        }

        std::vector<const char*>             vqGlfwRequiredExtensions()
        {
            uint32_t    cnt = 0;
            const char**    them    = glfwGetRequiredInstanceExtensions(&cnt);
            return std::vector<const char*>(them, them+cnt);
        }

        std::string                             vqName(VkPhysicalDevice dev)
        {
            if(!dev) [[unlikely]]
                return std::string();
            VkPhysicalDeviceProperties  props;
            vkGetPhysicalDeviceProperties(dev, &props);
            return std::string(props.deviceName);
        }

        std::set<std::string>                     vqNameSet(const std::vector<VkExtensionProperties>& props)
        {
            std::set<std::string> ret;
            for(const auto& v : props)
                ret.insert(std::string(v.extensionName));
            return ret;
        }

        std::set<std::string>                     vqNameSet(const std::vector<VkLayerProperties>& props)
        {
            std::set<std::string> ret;
            for(const auto& v : props)
                ret.insert(std::string(v.layerName));
            return ret;
        }


        VkQueueFlags                    vqOrFlags(const std::vector<VkQueueFamilyProperties>& queues)
        {
            VkQueueFlags    ret{0};
            for(const auto& q : queues)
                ret |= q.queueFlags;
            return ret;
        }

    }
}
