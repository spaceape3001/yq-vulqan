////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/vulkan/VqEnums.hpp>
#include <yq/core/Enum.hpp>

namespace yq::tachyon {
    static const std::string_view szUnknown   = "(unknown)";

        //  TODO: Fold these into tachyon/enum

    YQ_ENUM(VqColorSpaceKHR, , 
        SRGB_NONLINEAR_KHR = 0,
        DISPLAY_P3_NONLINEAR_EXT = 1000104001,
        EXTENDED_SRGB_LINEAR_EXT = 1000104002,
        DISPLAY_P3_LINEAR_EXT = 1000104003,
        DCI_P3_NONLINEAR_EXT = 1000104004,
        BT709_LINEAR_EXT = 1000104005,
        BT709_NONLINEAR_EXT = 1000104006,
        BT2020_LINEAR_EXT = 1000104007,
        HDR10_ST2084_EXT = 1000104008,
        DOLBYVISION_EXT = 1000104009,
        HDR10_HLG_EXT = 1000104010,
        ADOBERGB_LINEAR_EXT = 1000104011,
        ADOBERGB_NONLINEAR_EXT = 1000104012,
        PASS_THROUGH_EXT = 1000104013,
        EXTENDED_SRGB_NONLINEAR_EXT = 1000104014,
        DISPLAY_NATIVE_AMD = 1000213000
    )

    std::string_view to_string_view(VkColorSpaceKHR v)
    {
        int n   = (int) v;
        if(VqColorSpaceKHR::has_value(n))
            return VqColorSpaceKHR(n).key();
        return "(unknown color space)";
    }
    
    YQ_ENUM(VqDebugReportObjectType, , 
        UNKNOWN_EXT = 0,
        INSTANCE_EXT = 1,
        PHYSICAL_DEVICE_EXT = 2,
        DEVICE_EXT = 3,
        QUEUE_EXT = 4,
        SEMAPHORE_EXT = 5,
        COMMAND_BUFFER_EXT = 6,
        FENCE_EXT = 7,
        DEVICE_MEMORY_EXT = 8,
        BUFFER_EXT = 9,
        IMAGE_EXT = 10,
        EVENT_EXT = 11,
        QUERY_POOL_EXT = 12,
        BUFFER_VIEW_EXT = 13,
        IMAGE_VIEW_EXT = 14,
        SHADER_MODULE_EXT = 15,
        PIPELINE_CACHE_EXT = 16,
        PIPELINE_LAYOUT_EXT = 17,
        RENDER_PASS_EXT = 18,
        PIPELINE_EXT = 19,
        DESCRIPTOR_SET_LAYOUT_EXT = 20,
        SAMPLER_EXT = 21,
        DESCRIPTOR_POOL_EXT = 22,
        DESCRIPTOR_SET_EXT = 23,
        FRAMEBUFFER_EXT = 24,
        COMMAND_POOL_EXT = 25,
        SURFACE_KHR_EXT = 26,
        SWAPCHAIN_KHR_EXT = 27,
        DEBUG_REPORT_CALLBACK_EXT_EXT = 28,
        DISPLAY_KHR_EXT = 29,
        DISPLAY_MODE_KHR_EXT = 30,
        VALIDATION_CACHE_EXT_EXT = 33,
        SAMPLER_YCBCR_CONVERSION_EXT = 1000156000,
        DESCRIPTOR_UPDATE_TEMPLATE_EXT = 1000085000,
        CU_MODULE_NVX_EXT = 1000029000,
        CU_FUNCTION_NVX_EXT = 1000029001,
        ACCELERATION_STRUCTURE_KHR_EXT = 1000150000,
        ACCELERATION_STRUCTURE_NV_EXT = 1000165000,
        BUFFER_COLLECTION_FUCHSIA_EXT = 1000366000,
    )
    
    std::string_view                        to_string_view(VkDebugReportObjectTypeEXT v)
    {
        int n   = (int) v;
        if(VqDebugReportObjectType::has_value(n))
            return VqDebugReportObjectType(n).key();
        return "(unknown object_type)";
    }

    std::string_view    to_string_view(VqDescriptorType v)
    {
        switch(v){
        case VqDescriptorType::Sampler:
            return "Sampler";
        case VqDescriptorType::CombinedImageSampler:
            return "CombinedImageSampler";
        case VqDescriptorType::SampledImage:
            return "SampledImage";
        case VqDescriptorType::StorageImage:
            return "StorageImage";
        case VqDescriptorType::UniformTexelBuffer:
            return "UniformTexelBuffer";
        case VqDescriptorType::StorageTexelBuffer:
            return "StorageTexelBuffer";
        case VqDescriptorType::UniformBuffer:
            return "UniformBuffer";
        case VqDescriptorType::StorageBuffer:
            return "StorageBuffer";
        case VqDescriptorType::UniformBufferDynamic:
            return "UniformBufferDynamic";
        case VqDescriptorType::StorageBufferDynamic:
            return "StorageBufferDynamic";
        case VqDescriptorType::InputAttachment:
            return "InputAttachment";
        case VqDescriptorType::InlineUniformBlock:
            return "InlineUniformBlock";
        case VqDescriptorType::AccelerationStructure:
            return "AccelerationStructure";
        case VqDescriptorType::SampleWeightImage:
            return "SampleWeightImage";
        case VqDescriptorType::BlockMatchImage:
            return "BlockMatchImage";
        case VqDescriptorType::Mutable:
            return "Mutable";
        default:
            return szUnknown;
        }
    }
    
    std::string_view    to_string_view(VkDescriptorType v)
    {
        return to_string_view(VqDescriptorType(v));
    }
        
    YQ_ENUM(VqDynamicState, ,
        VIEWPORT = 0,
        SCISSOR = 1,
        LINE_WIDTH = 2,
        DEPTH_BIAS = 3,
        BLEND_CONSTANTS = 4,
        DEPTH_BOUNDS = 5,
        STENCIL_COMPARE_MASK = 6,
        STENCIL_WRITE_MASK = 7,
        STENCIL_REFERENCE = 8,
        CULL_MODE = 1000267000,
        FRONT_FACE = 1000267001,
        PRIMITIVE_TOPOLOGY = 1000267002,
        VIEWPORT_WITH_COUNT = 1000267003,
        SCISSOR_WITH_COUNT = 1000267004,
        VERTEX_INPUT_BINDING_STRIDE = 1000267005,
        DEPTH_TEST_ENABLE = 1000267006,
        DEPTH_WRITE_ENABLE = 1000267007,
        DEPTH_COMPARE_OP = 1000267008,
        DEPTH_BOUNDS_TEST_ENABLE = 1000267009,
        STENCIL_TEST_ENABLE = 1000267010,
        STENCIL_OP = 1000267011,
        RASTERIZER_DISCARD_ENABLE = 1000377001,
        DEPTH_BIAS_ENABLE = 1000377002,
        PRIMITIVE_RESTART_ENABLE = 1000377004,
        VIEWPORT_W_SCALING_NV = 1000087000,
        DISCARD_RECTANGLE_EXT = 1000099000,
        SAMPLE_LOCATIONS_EXT = 1000143000,
        RAY_TRACING_PIPELINE_STACK_SIZE_KHR = 1000347000,
        VIEWPORT_SHADING_RATE_PALETTE_NV = 1000164004,
        VIEWPORT_COARSE_SAMPLE_ORDER_NV = 1000164006,
        EXCLUSIVE_SCISSOR_NV = 1000205001,
        FRAGMENT_SHADING_RATE_KHR = 1000226000,
        LINE_STIPPLE_EXT = 1000259000,
        VERTEX_INPUT_EXT = 1000352000,
        PATCH_CONTROL_POINTS_EXT = 1000377000,
        LOGIC_OP_EXT = 1000377003,
        COLOR_WRITE_ENABLE_EXT = 1000381000
    )
    
    std::string_view                        to_string_view(VkDynamicState v)
    {
        int n   = (int) v;
        if(VqDynamicState::has_value(n))
            return VqDynamicState(n).key();
        return "(unknown object_type)";
    }

    std::string_view to_string_view(VkFormat fmt)
    {
        using namespace std::literals::string_view_literals;
        switch(fmt){
        case VK_FORMAT_UNDEFINED:
            return "UNDEFINED"sv;
        case VK_FORMAT_R4G4_UNORM_PACK8:
            return "R4G4_UNORM_PACK8"sv;
        case VK_FORMAT_R4G4B4A4_UNORM_PACK16:
            return "R4G4B4A4_UNORM_PACK16"sv;
        case VK_FORMAT_B4G4R4A4_UNORM_PACK16:
            return "B4G4R4A4_UNORM_PACK16"sv;
        case VK_FORMAT_R5G6B5_UNORM_PACK16:
            return "R5G6B5_UNORM_PACK16"sv;
        case VK_FORMAT_B5G6R5_UNORM_PACK16:
            return "B5G6R5_UNORM_PACK16"sv;
        case VK_FORMAT_R5G5B5A1_UNORM_PACK16:
            return "R5G5B5A1_UNORM_PACK16"sv;
        case VK_FORMAT_B5G5R5A1_UNORM_PACK16:
            return "B5G5R5A1_UNORM_PACK16"sv;
        case VK_FORMAT_A1R5G5B5_UNORM_PACK16:
            return "A1R5G5B5_UNORM_PACK16"sv;
        case VK_FORMAT_R8_UNORM:
            return "R8_UNORM"sv;
        case VK_FORMAT_R8_SNORM:
            return "R8_SNORM"sv;
        case VK_FORMAT_R8_USCALED:
            return "R8_USCALED"sv;
        case VK_FORMAT_R8_SSCALED:
            return "R8_SSCALED"sv;
        case VK_FORMAT_R8_UINT:
            return "R8_UINT"sv;
        case VK_FORMAT_R8_SINT:
            return "R8_SINT"sv;
        case VK_FORMAT_R8_SRGB:
            return "R8_SRGB"sv;
        case VK_FORMAT_R8G8_UNORM:
            return "R8G8_UNORM"sv;
        case VK_FORMAT_R8G8_SNORM:
            return "R8G8_SNORM"sv;
        case VK_FORMAT_R8G8_USCALED:
            return "R8G8_USCALED"sv;
        case VK_FORMAT_R8G8_SSCALED:
            return "R8G8_SSCALED"sv;
        case VK_FORMAT_R8G8_UINT:
            return "R8G8_UINT"sv;
        case VK_FORMAT_R8G8_SINT:
            return "R8G8_SINT"sv;
        case VK_FORMAT_R8G8_SRGB:
            return "R8G8_SRGB"sv;
        case VK_FORMAT_R8G8B8_UNORM:
            return "R8G8B8_UNORM"sv;
        case VK_FORMAT_R8G8B8_SNORM:
            return "R8G8B8_SNORM"sv;
        case VK_FORMAT_R8G8B8_USCALED:
            return "R8G8B8_USCALED"sv;
        case VK_FORMAT_R8G8B8_SSCALED:
            return "R8G8B8_SSCALED"sv;
        case VK_FORMAT_R8G8B8_UINT:
            return "R8G8B8_UINT"sv;
        case VK_FORMAT_R8G8B8_SINT:
            return "R8G8B8_SINT"sv;
        case VK_FORMAT_R8G8B8_SRGB:
            return "R8G8B8_SRGB"sv;
        case VK_FORMAT_B8G8R8_UNORM:
            return "B8G8R8_UNORM"sv;
        case VK_FORMAT_B8G8R8_SNORM:
            return "B8G8R8_SNORM"sv;
        case VK_FORMAT_B8G8R8_USCALED:
            return "B8G8R8_USCALED"sv;
        case VK_FORMAT_B8G8R8_SSCALED:
            return "B8G8R8_SSCALED"sv;
        case VK_FORMAT_B8G8R8_UINT:
            return "B8G8R8_UINT"sv;
        case VK_FORMAT_B8G8R8_SINT:
            return "B8G8R8_SINT"sv;
        case VK_FORMAT_B8G8R8_SRGB:
            return "B8G8R8_SRGB"sv;
        case VK_FORMAT_R8G8B8A8_UNORM:
            return "R8G8B8A8_UNORM"sv;
        case VK_FORMAT_R8G8B8A8_SNORM:
            return "R8G8B8A8_SNORM"sv;
        case VK_FORMAT_R8G8B8A8_USCALED:
            return "R8G8B8A8_USCALED"sv;
        case VK_FORMAT_R8G8B8A8_SSCALED:
            return "R8G8B8A8_SSCALED"sv;
        case VK_FORMAT_R8G8B8A8_UINT:
            return "R8G8B8A8_UINT"sv;
        case VK_FORMAT_R8G8B8A8_SINT:
            return "R8G8B8A8_SINT"sv;
        case VK_FORMAT_R8G8B8A8_SRGB:
            return "R8G8B8A8_SRGB"sv;
        case VK_FORMAT_B8G8R8A8_UNORM:
            return "B8G8R8A8_UNORM"sv;
        case VK_FORMAT_B8G8R8A8_SNORM:
            return "B8G8R8A8_SNORM"sv;
        case VK_FORMAT_B8G8R8A8_USCALED:
            return "B8G8R8A8_USCALED"sv;
        case VK_FORMAT_B8G8R8A8_SSCALED:
            return "B8G8R8A8_SSCALED"sv;
        case VK_FORMAT_B8G8R8A8_UINT:
            return "B8G8R8A8_UINT"sv;
        case VK_FORMAT_B8G8R8A8_SINT:
            return "B8G8R8A8_SINT"sv;
        case VK_FORMAT_B8G8R8A8_SRGB:
            return "B8G8R8A8_SRGB"sv;
        case VK_FORMAT_A8B8G8R8_UNORM_PACK32:
            return "A8B8G8R8_UNORM_PACK32"sv;
        case VK_FORMAT_A8B8G8R8_SNORM_PACK32:
            return "A8B8G8R8_SNORM_PACK32"sv;
        case VK_FORMAT_A8B8G8R8_USCALED_PACK32:
            return "A8B8G8R8_USCALED_PACK32"sv;
        case VK_FORMAT_A8B8G8R8_SSCALED_PACK32:
            return "A8B8G8R8_SSCALED_PACK32"sv;
        case VK_FORMAT_A8B8G8R8_UINT_PACK32:
            return "A8B8G8R8_UINT_PACK32"sv;
        case VK_FORMAT_A8B8G8R8_SINT_PACK32:
            return "A8B8G8R8_SINT_PACK32"sv;
        case VK_FORMAT_A8B8G8R8_SRGB_PACK32:
            return "A8B8G8R8_SRGB_PACK32"sv;
        case VK_FORMAT_A2R10G10B10_UNORM_PACK32:
            return "A2R10G10B10_UNORM_PACK32"sv;
        case VK_FORMAT_A2R10G10B10_SNORM_PACK32:
            return "A2R10G10B10_SNORM_PACK32"sv;
        case VK_FORMAT_A2R10G10B10_USCALED_PACK32:
            return "A2R10G10B10_USCALED_PACK32"sv;
        case VK_FORMAT_A2R10G10B10_SSCALED_PACK32:
            return "A2R10G10B10_SSCALED_PACK32"sv;
        case VK_FORMAT_A2R10G10B10_UINT_PACK32:
            return "A2R10G10B10_UINT_PACK32"sv;
        case VK_FORMAT_A2R10G10B10_SINT_PACK32:
            return "A2R10G10B10_SINT_PACK32"sv;
        case VK_FORMAT_A2B10G10R10_UNORM_PACK32:
            return "A2B10G10R10_UNORM_PACK32"sv;
        case VK_FORMAT_A2B10G10R10_SNORM_PACK32:
            return "A2B10G10R10_SNORM_PACK32"sv;
        case VK_FORMAT_A2B10G10R10_USCALED_PACK32:
            return "A2B10G10R10_USCALED_PACK32"sv;
        case VK_FORMAT_A2B10G10R10_SSCALED_PACK32:
            return "A2B10G10R10_SSCALED_PACK32"sv;
        case VK_FORMAT_A2B10G10R10_UINT_PACK32:
            return "A2B10G10R10_UINT_PACK32"sv;
        case VK_FORMAT_A2B10G10R10_SINT_PACK32:
            return "A2B10G10R10_SINT_PACK32"sv;
        case VK_FORMAT_R16_UNORM:
            return "R16_UNORM"sv;
        case VK_FORMAT_R16_SNORM:
            return "R16_SNORM"sv;
        case VK_FORMAT_R16_USCALED:
            return "R16_USCALED"sv;
        case VK_FORMAT_R16_SSCALED:
            return "R16_SSCALED"sv;
        case VK_FORMAT_R16_UINT:
            return "R16_UINT"sv;
        case VK_FORMAT_R16_SINT:
            return "R16_SINT"sv;
        case VK_FORMAT_R16_SFLOAT:
            return "R16_SFLOAT"sv;
        case VK_FORMAT_R16G16_UNORM:
            return "R16G16_UNORM"sv;
        case VK_FORMAT_R16G16_SNORM:
            return "R16G16_SNORM"sv;
        case VK_FORMAT_R16G16_USCALED:
            return "R16G16_USCALED"sv;
        case VK_FORMAT_R16G16_SSCALED:
            return "R16G16_SSCALED"sv;
        case VK_FORMAT_R16G16_UINT:
            return "R16G16_UINT"sv;
        case VK_FORMAT_R16G16_SINT:
            return "R16G16_SINT"sv;
        case VK_FORMAT_R16G16_SFLOAT:
            return "R16G16_SFLOAT"sv;
        case VK_FORMAT_R16G16B16_UNORM:
            return "R16G16B16_UNORM"sv;
        case VK_FORMAT_R16G16B16_SNORM:
            return "R16G16B16_SNORM"sv;
        case VK_FORMAT_R16G16B16_USCALED:
            return "R16G16B16_USCALED"sv;
        case VK_FORMAT_R16G16B16_SSCALED:
            return "R16G16B16_SSCALED"sv;
        case VK_FORMAT_R16G16B16_UINT:
            return "R16G16B16_UINT"sv;
        case VK_FORMAT_R16G16B16_SINT:
            return "R16G16B16_SINT"sv;
        case VK_FORMAT_R16G16B16_SFLOAT:
            return "R16G16B16_SFLOAT"sv;
        case VK_FORMAT_R16G16B16A16_UNORM:
            return "R16G16B16A16_UNORM"sv;
        case VK_FORMAT_R16G16B16A16_SNORM:
            return "R16G16B16A16_SNORM"sv;
        case VK_FORMAT_R16G16B16A16_USCALED:
            return "R16G16B16A16_USCALED"sv;
        case VK_FORMAT_R16G16B16A16_SSCALED:
            return "R16G16B16A16_SSCALED"sv;
        case VK_FORMAT_R16G16B16A16_UINT:
            return "R16G16B16A16_UINT"sv;
        case VK_FORMAT_R16G16B16A16_SINT:
            return "R16G16B16A16_SINT"sv;
        case VK_FORMAT_R16G16B16A16_SFLOAT:
            return "R16G16B16A16_SFLOAT"sv;
        case VK_FORMAT_R32_UINT:
            return "R32_UINT"sv;
        case VK_FORMAT_R32_SINT:
            return "R32_SINT"sv;
        case VK_FORMAT_R32_SFLOAT:
            return "R32_SFLOAT"sv;
        case VK_FORMAT_R32G32_UINT:
            return "R32G32_UINT"sv;
        case VK_FORMAT_R32G32_SINT:
            return "R32G32_SINT"sv;
        case VK_FORMAT_R32G32_SFLOAT:
            return "R32G32_SFLOAT"sv;
        case VK_FORMAT_R32G32B32_UINT:
            return "R32G32B32_UINT"sv;
        case VK_FORMAT_R32G32B32_SINT:
            return "R32G32B32_SINT"sv;
        case VK_FORMAT_R32G32B32_SFLOAT:
            return "R32G32B32_SFLOAT"sv;
        case VK_FORMAT_R32G32B32A32_UINT:
            return "R32G32B32A32_UINT"sv;
        case VK_FORMAT_R32G32B32A32_SINT:
            return "R32G32B32A32_SINT"sv;
        case VK_FORMAT_R32G32B32A32_SFLOAT:
            return "R32G32B32A32_SFLOAT"sv;
        case VK_FORMAT_R64_UINT:
            return "R64_UINT"sv;
        case VK_FORMAT_R64_SINT:
            return "R64_SINT"sv;
        case VK_FORMAT_R64_SFLOAT:
            return "R64_SFLOAT"sv;
        case VK_FORMAT_R64G64_UINT:
            return "R64G64_UINT"sv;
        case VK_FORMAT_R64G64_SINT:
            return "R64G64_SINT"sv;
        case VK_FORMAT_R64G64_SFLOAT:
            return "R64G64_SFLOAT"sv;
        case VK_FORMAT_R64G64B64_UINT:
            return "R64G64B64_UINT"sv;
        case VK_FORMAT_R64G64B64_SINT:
            return "R64G64B64_SINT"sv;
        case VK_FORMAT_R64G64B64_SFLOAT:
            return "R64G64B64_SFLOAT"sv;
        case VK_FORMAT_R64G64B64A64_UINT:
            return "R64G64B64A64_UINT"sv;
        case VK_FORMAT_R64G64B64A64_SINT:
            return "R64G64B64A64_SINT"sv;
        case VK_FORMAT_R64G64B64A64_SFLOAT:
            return "R64G64B64A64_SFLOAT"sv;
        case VK_FORMAT_B10G11R11_UFLOAT_PACK32:
            return "B10G11R11_UFLOAT_PACK32"sv;
        case VK_FORMAT_E5B9G9R9_UFLOAT_PACK32:
            return "E5B9G9R9_UFLOAT_PACK32"sv;
        case VK_FORMAT_D16_UNORM:
            return "D16_UNORM"sv;
        case VK_FORMAT_X8_D24_UNORM_PACK32:
            return "X8_D24_UNORM_PACK32"sv;
        case VK_FORMAT_D32_SFLOAT:
            return "D32_SFLOAT"sv;
        case VK_FORMAT_S8_UINT:
            return "S8_UINT"sv;
        case VK_FORMAT_D16_UNORM_S8_UINT:
            return "D16_UNORM_S8_UINT"sv;
        case VK_FORMAT_D24_UNORM_S8_UINT:
            return "D24_UNORM_S8_UINT"sv;
        case VK_FORMAT_D32_SFLOAT_S8_UINT:
            return "D32_SFLOAT_S8_UINT"sv;
        case VK_FORMAT_BC1_RGB_UNORM_BLOCK:
            return "BC1_RGB_UNORM_BLOCK"sv;
        case VK_FORMAT_BC1_RGB_SRGB_BLOCK:
            return "BC1_RGB_SRGB_BLOCK"sv;
        case VK_FORMAT_BC1_RGBA_UNORM_BLOCK:
            return "BC1_RGBA_UNORM_BLOCK"sv;
        case VK_FORMAT_BC1_RGBA_SRGB_BLOCK:
            return "BC1_RGBA_SRGB_BLOCK"sv;
        case VK_FORMAT_BC2_UNORM_BLOCK:
            return "BC2_UNORM_BLOCK"sv;
        case VK_FORMAT_BC2_SRGB_BLOCK:
            return "BC2_SRGB_BLOCK"sv;
        case VK_FORMAT_BC3_UNORM_BLOCK:
            return "BC3_UNORM_BLOCK"sv;
        case VK_FORMAT_BC3_SRGB_BLOCK:
            return "BC3_SRGB_BLOCK"sv;
        case VK_FORMAT_BC4_UNORM_BLOCK:
            return "BC4_UNORM_BLOCK"sv;
        case VK_FORMAT_BC4_SNORM_BLOCK:
            return "BC4_SNORM_BLOCK"sv;
        case VK_FORMAT_BC5_UNORM_BLOCK:
            return "BC5_UNORM_BLOCK"sv;
        case VK_FORMAT_BC5_SNORM_BLOCK:
            return "BC5_SNORM_BLOCK"sv;
        case VK_FORMAT_BC6H_UFLOAT_BLOCK:
            return "BC6H_UFLOAT_BLOCK"sv;
        case VK_FORMAT_BC6H_SFLOAT_BLOCK:
            return "BC6H_SFLOAT_BLOCK"sv;
        case VK_FORMAT_BC7_UNORM_BLOCK:
            return "BC7_UNORM_BLOCK"sv;
        case VK_FORMAT_BC7_SRGB_BLOCK:
            return "BC7_SRGB_BLOCK"sv;
        case VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK:
            return "ETC2_R8G8B8_UNORM_BLOCK"sv;
        case VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK:
            return "ETC2_R8G8B8_SRGB_BLOCK"sv;
        case VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK:
            return "ETC2_R8G8B8A1_UNORM_BLOCK"sv;
        case VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK:
            return "ETC2_R8G8B8A1_SRGB_BLOCK"sv;
        case VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK:
            return "ETC2_R8G8B8A8_UNORM_BLOCK"sv;
        case VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK:
            return "ETC2_R8G8B8A8_SRGB_BLOCK"sv;
        case VK_FORMAT_EAC_R11_UNORM_BLOCK:
            return "EAC_R11_UNORM_BLOCK"sv;
        case VK_FORMAT_EAC_R11_SNORM_BLOCK:
            return "EAC_R11_SNORM_BLOCK"sv;
        case VK_FORMAT_EAC_R11G11_UNORM_BLOCK:
            return "EAC_R11G11_UNORM_BLOCK"sv;
        case VK_FORMAT_EAC_R11G11_SNORM_BLOCK:
            return "EAC_R11G11_SNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_4x4_UNORM_BLOCK:
            return "ASTC_4x4_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_4x4_SRGB_BLOCK:
            return "ASTC_4x4_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_5x4_UNORM_BLOCK:
            return "ASTC_5x4_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_5x4_SRGB_BLOCK:
            return "ASTC_5x4_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_5x5_UNORM_BLOCK:
            return "ASTC_5x5_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_5x5_SRGB_BLOCK:
            return "ASTC_5x5_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_6x5_UNORM_BLOCK:
            return "ASTC_6x5_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_6x5_SRGB_BLOCK:
            return "ASTC_6x5_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_6x6_UNORM_BLOCK:
            return "ASTC_6x6_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_6x6_SRGB_BLOCK:
            return "ASTC_6x6_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_8x5_UNORM_BLOCK:
            return "ASTC_8x5_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_8x5_SRGB_BLOCK:
            return "ASTC_8x5_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_8x6_UNORM_BLOCK:
            return "ASTC_8x6_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_8x6_SRGB_BLOCK:
            return "ASTC_8x6_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_8x8_UNORM_BLOCK:
            return "ASTC_8x8_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_8x8_SRGB_BLOCK:
            return "ASTC_8x8_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_10x5_UNORM_BLOCK:
            return "ASTC_10x5_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_10x5_SRGB_BLOCK:
            return "ASTC_10x5_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_10x6_UNORM_BLOCK:
            return "ASTC_10x6_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_10x6_SRGB_BLOCK:
            return "ASTC_10x6_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_10x8_UNORM_BLOCK:
            return "ASTC_10x8_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_10x8_SRGB_BLOCK:
            return "ASTC_10x8_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_10x10_UNORM_BLOCK:
            return "ASTC_10x10_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_10x10_SRGB_BLOCK:
            return "ASTC_10x10_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_12x10_UNORM_BLOCK:
            return "ASTC_12x10_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_12x10_SRGB_BLOCK:
            return "ASTC_12x10_SRGB_BLOCK"sv;
        case VK_FORMAT_ASTC_12x12_UNORM_BLOCK:
            return "ASTC_12x12_UNORM_BLOCK"sv;
        case VK_FORMAT_ASTC_12x12_SRGB_BLOCK:
            return "ASTC_12x12_SRGB_BLOCK"sv;
        case VK_FORMAT_G8B8G8R8_422_UNORM:
            return "G8B8G8R8_422_UNORM"sv;
        case VK_FORMAT_B8G8R8G8_422_UNORM:
            return "B8G8R8G8_422_UNORM"sv;
        case VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM:
            return "G8_B8_R8_3PLANE_420_UNORM"sv;
        case VK_FORMAT_G8_B8R8_2PLANE_420_UNORM:
            return "G8_B8R8_2PLANE_420_UNORM"sv;
        case VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM:
            return "G8_B8_R8_3PLANE_422_UNORM"sv;
        case VK_FORMAT_G8_B8R8_2PLANE_422_UNORM:
            return "G8_B8R8_2PLANE_422_UNORM"sv;
        case VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM:
            return "G8_B8_R8_3PLANE_444_UNORM"sv;
        case VK_FORMAT_R10X6_UNORM_PACK16:
            return "R10X6_UNORM_PACK16"sv;
        case VK_FORMAT_R10X6G10X6_UNORM_2PACK16:
            return "R10X6G10X6_UNORM_2PACK16"sv;
        case VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16:
            return "R10X6G10X6B10X6A10X6_UNORM_4PACK16"sv;
        case VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16:
            return "G10X6B10X6G10X6R10X6_422_UNORM_4PACK16"sv;
        case VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16:
            return "B10X6G10X6R10X6G10X6_422_UNORM_4PACK16"sv;
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16:
            return "G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16"sv;
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16:
            return "G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16"sv;
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16:
            return "G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16"sv;
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16:
            return "G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16"sv;
        case VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16:
            return "G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16"sv;
        case VK_FORMAT_R12X4_UNORM_PACK16:
            return "R12X4_UNORM_PACK16"sv;
        case VK_FORMAT_R12X4G12X4_UNORM_2PACK16:
            return "R12X4G12X4_UNORM_2PACK16"sv;
        case VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16:
            return "R12X4G12X4B12X4A12X4_UNORM_4PACK16"sv;
        case VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16:
            return "G12X4B12X4G12X4R12X4_422_UNORM_4PACK16"sv;
        case VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16:
            return "B12X4G12X4R12X4G12X4_422_UNORM_4PACK16"sv;
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16:
            return "G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16"sv;
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16:
            return "G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16"sv;
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16:
            return "G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16"sv;
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16:
            return "G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16"sv;
        case VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16:
            return "G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16"sv;
        case VK_FORMAT_G16B16G16R16_422_UNORM:
            return "G16B16G16R16_422_UNORM"sv;
        case VK_FORMAT_B16G16R16G16_422_UNORM:
            return "B16G16R16G16_422_UNORM"sv;
        case VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM:
            return "G16_B16_R16_3PLANE_420_UNORM"sv;
        case VK_FORMAT_G16_B16R16_2PLANE_420_UNORM:
            return "G16_B16R16_2PLANE_420_UNORM"sv;
        case VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM:
            return "G16_B16_R16_3PLANE_422_UNORM"sv;
        case VK_FORMAT_G16_B16R16_2PLANE_422_UNORM:
            return "G16_B16R16_2PLANE_422_UNORM"sv;
        case VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM:
            return "G16_B16_R16_3PLANE_444_UNORM"sv;
        case VK_FORMAT_G8_B8R8_2PLANE_444_UNORM:
            return "G8_B8R8_2PLANE_444_UNORM"sv;
        case VK_FORMAT_G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16:
            return "G10X6_B10X6R10X6_2PLANE_444_UNORM_3PACK16"sv;
        case VK_FORMAT_G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16:
            return "G12X4_B12X4R12X4_2PLANE_444_UNORM_3PACK16"sv;
        case VK_FORMAT_G16_B16R16_2PLANE_444_UNORM:
            return "G16_B16R16_2PLANE_444_UNORM"sv;
        case VK_FORMAT_A4R4G4B4_UNORM_PACK16:
            return "A4R4G4B4_UNORM_PACK16"sv;
        case VK_FORMAT_A4B4G4R4_UNORM_PACK16:
            return "A4B4G4R4_UNORM_PACK16"sv;
        case VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK:
            return "ASTC_4x4_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK:
            return "ASTC_5x4_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK:
            return "ASTC_5x5_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK:
            return "ASTC_6x5_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK:
            return "ASTC_6x6_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK:
            return "ASTC_8x5_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK:
            return "ASTC_8x6_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK:
            return "ASTC_8x8_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK:
            return "ASTC_10x5_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK:
            return "ASTC_10x6_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK:
            return "ASTC_10x8_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK:
            return "ASTC_10x10_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK:
            return "ASTC_12x10_SFLOAT_BLOCK"sv;
        case VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK:
            return "ASTC_12x12_SFLOAT_BLOCK"sv;
        case VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG:
            return "PVRTC1_2BPP_UNORM_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG:
            return "PVRTC1_4BPP_UNORM_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG:
            return "PVRTC2_2BPP_UNORM_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG:
            return "PVRTC2_4BPP_UNORM_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG:
            return "PVRTC1_2BPP_SRGB_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG:
            return "PVRTC1_4BPP_SRGB_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG:
            return "PVRTC2_2BPP_SRGB_BLOCK_IMG"sv;
        case VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG:
            return "PVRTC2_4BPP_SRGB_BLOCK_IMG"sv;
        case VK_FORMAT_R16G16_SFIXED5_NV:
            return "R16G16_SFIXED5_NV"sv;
        case VK_FORMAT_A1B5G5R5_UNORM_PACK16_KHR:
            return "A1B5G5R5_UNORM_PACK16_KHR"sv;
        case VK_FORMAT_A8_UNORM_KHR:
            return "A8_UNORM_KHR"sv;
        default:
            return "Not Listed"sv;
        }
    }
    
    YQ_ENUM(VqPhysicalDeviceType, ,
        Other = 0,
        Integrated = 1,
        Discrete = 2,
        Virtual = 3,
        CPU     = 4
    )

    std::string_view                        to_string_view(VkPhysicalDeviceType v)
    {
        int n   = (int) v;
        if(VqPhysicalDeviceType::has_value(n))
            return VqPhysicalDeviceType(n).key();
        return "(unknown device type)";
    }


    
    std::string_view    to_string_view(VqPipelineBindPoint v)
    {
        switch(v){
        case VqPipelineBindPoint::Graphics:
            return "Graphics";
        case VqPipelineBindPoint::Compute:
            return "Compute";
        case VqPipelineBindPoint::ExecutionGraphAmdx:
            return "ExecutionGraph";
        case VqPipelineBindPoint::RayTracing:
            return "RayTracing";
        case VqPipelineBindPoint::SubpassShadingHuawei:
            return "SubpassShading";
        default:
            return szUnknown;
        }
    }
    
    std::string_view    to_string_view(VkPipelineBindPoint v)
    {
        return to_string_view(VqPipelineBindPoint(v));
    }
}
