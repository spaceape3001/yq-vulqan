////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Flags.hpp>
#include <tachyon/preamble.hpp>
#include <vulkan/vulkan_core.h>
#include <vk_mem_alloc.h>

namespace yq::tachyon {
    struct ViDevice {
        //enum class F : uint8_t {
        //};
    
        GLFWwindow*         window      = nullptr;
        VkInstance          instance    = nullptr;
        VkPhysicalDevice    gpu         = nullptr;
        VkSurfaceKHR        surface     = nullptr;
        VkDevice            device      = nullptr;
        VmaAllocator        allocator   = nullptr;
        VkQueue             compute     = nullptr;
        VkQueue             graphics    = nullptr;
        VkQueue             present     = nullptr;
        VkQueue             videoDec    = nullptr;
        VkQueue             videoEnc    = nullptr;
        //Flags<F>            flags           = {};
    };
}
