////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/errors.hpp>

namespace yq::tachyon::errors {
    using namespace yq::errors;
    
    using buffer_bad_state              = error_db::entry<"Buffer is in a bad state">;
    using buffer_cant_allocate          = error_db::entry<"Buffer is unable to allocate requested memory">;
    using buffer_cant_map_memory        = error_db::entry<"Unable to map buffer memory">;
    using buffer_empty                  = error_db::entry<"Buffer is empty">;
    using buffer_existing               = error_db::entry<"Buffer already created">;
    using buffer_uninitialized          = error_db::entry<"Attempting to use an uninitialized buffer">;
    using buffer_manager_uninitialized  = error_db::entry<"Buffer manager is uninitialized">;
    using command_buffer_bad_state      = error_db::entry<"Command buffer is in a bad state">;
    using command_buffer_cant_create    = error_db::entry<"Unable to create vulkan command buffer(s)">;
    using command_buffer_existing       = error_db::entry<"Command buffer already created">;
    using command_buffer_uninitialized  = error_db::entry<"Attempting to use an uninitialized command buffer">;
    using command_pool_bad_state        = error_db::entry<"Command pool is in a bad state">;
    using command_pool_cant_create      = error_db::entry<"Unable to create vulkan command pool">;
    using command_pool_cant_reset       = error_db::entry<"Unable to reset the command pool">;
    using command_pool_existing         = error_db::entry<"Command pool already created">;
    using command_pool_null_pointer     = error_db::entry<"Null pointer of a command pool">;
    using command_pool_uninitialized    = error_db::entry<"Attempting to use an uninitialized command pool">;
    using fence_bad_state               = error_db::entry<"Fence is in a bad state">;
    using fence_cant_create             = error_db::entry<"Unable to create vulkan fence">;
    using fence_existing                = error_db::entry<"Fence already created">;
    using fence_not_ready               = error_db::entry<"Fence not ready">;
    using fence_timeout                 = error_db::entry<"Fence wait timed out">;
    using fence_uninitialized           = error_db::entry<"Attempting to use an uninitialized fence">;
    using fence_unknown                 = error_db::entry<"Unknown fence error">;
    using format_unsupported            = error_db::entry<"Requested format(s) is not supported">;
    using insufficient_gpu_memory       = error_db::entry<"Insufficient GPU memory for requested operation">;
    //using SKIPPING_ZERO_SIZED_BUFFER    = error_db::entry<"Skipping zero sized buffer">;
    using shader_bad_state              = error_db::entry<"Shader is in a bad state">;
    using shader_cant_create            = error_db::entry<"Unable to create vulkan shader module">;
    using shader_empty                  = error_db::entry<"Shader is empty">;
    using shader_existing               = error_db::entry<"Shader already created">;
    using shader_uninitialized          = error_db::entry<"Attempting to use an uninitialized shader">;
    using shader_manager_uninitialized  = error_db::entry<"Shader manager is uninitialized">;
    using vizualizer_uninitialized      = error_db::entry<"Attempting to use an uninitialized visualizer">;
    using vulkan_device_cant_create     = error_db::entry<"Unable to create vulkan (logical) device">;
    using vulkan_device_lost            = error_db::entry<"Device has been lost">;
    using vulkan_instance_cant_create   = error_db::entry<"Unable to create vulkan instance">;
    using vulkan_no_application         = error_db::entry<"No application available">;
    using vulkan_no_compute_queue       = error_db::entry<"No compute queue found">;
    using vulkan_no_graphics_queue      = error_db::entry<"No graphics queue found">;
    using vulkan_no_physical_device     = error_db::entry<"No GPU/Physical device provided or detected">;
    using vulkan_no_present_queue       = error_db::entry<"No present queue found">;
    using vulkan_no_transfer_queue      = error_db::entry<"No transfer queue found">;
    using vulkan_no_window_provided     = error_db::entry<"No window provided">;
    using vulkan_no_window_surface      = error_db::entry<"No window surface available">;
    using vulkan_no_video_decode_queue  = error_db::entry<"No video decoding queue found">;
    using vulkan_no_video_encode_queue  = error_db::entry<"No video encoding queue found">;
    using vulkan_out_of_device_memory   = error_db::entry<"Out of device memory">;
    using vulkan_out_of_host_memory     = error_db::entry<"Out of host memory">;
    using vulkan_uninitialized          = error_db::entry<"Vulkan unavailable">;
}
