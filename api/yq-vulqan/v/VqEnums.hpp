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


    enum class VqDescriptorType : int32_t {
        Sampler = 0,
        CombinedImageSampler = 1,
        SampledImage = 2,
        StorageImage = 3,
        UniformTexelBuffer = 4,
        StorageTexelBuffer = 5,
        UniformBuffer = 6,
        StorageBuffer = 7,
        UniformBufferDynamic = 8,
        StorageBufferDynamic = 9,
        InputAttachment = 10,
        InlineUniformBlock = 1000138000,
        AccelerationStructure = 1000150000,
        SampleWeightImage = 1000440000,
        BlockMatchImage = 1000440001,
        Mutable = 1000351000,
        MutableValve = Mutable
    };
    
    std::string_view    to_string_view(VqDescriptorType);
    std::string_view    to_string_view(VkDescriptorType);

    enum class VqPipelineBindPoint : int32_t {
        Graphics = 0,
        Compute = 1,
        ExecutionGraphAmdx = 1000134000,
        RayTracing = 1000165000,
        SubpassShadingHuawei = 1000369003
    };

    std::string_view    to_string_view(VqPipelineBindPoint);
    std::string_view    to_string_view(VkPipelineBindPoint);
}
