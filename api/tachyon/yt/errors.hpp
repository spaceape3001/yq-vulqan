////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/errors.hpp>

namespace yq::tachyon::errors {
    using namespace yq::errors;
    
    //  Common errors go here, specialized ones in the relevant implementation files (unless they need to be shared)
    
    using command_buffer_bad_state          = error_db::entry<"Command buffer is in a bad state">;
    using command_buffer_cant_create        = error_db::entry<"Unable to create vulkan command buffer(s)">;
    using command_buffer_existing           = error_db::entry<"Command buffer already created">;
    using command_buffer_uninitialized      = error_db::entry<"Attempting to use an uninitialized command buffer">;
    using command_pool_bad_state            = error_db::entry<"Command pool is in a bad state">;
    using command_pool_cant_create          = error_db::entry<"Unable to create vulkan command pool">;
    using command_pool_cant_reset           = error_db::entry<"Unable to reset the command pool">;
    using command_pool_existing             = error_db::entry<"Command pool already created">;
    using command_pool_null_pointer         = error_db::entry<"Null pointer of a command pool">;
    using command_pool_uninitialized        = error_db::entry<"Attempting to use an uninitialized command pool">;
    using compute_queue_not_found           = error_db::entry<"No compute queue found">;
    using compute_queue_uninitialized       = error_db::entry<"Compute queue is uninitialized">;
    using data_cant_initialize              = error_db::entry<"Data object is unable to initialize">;
    using format_unsupported                = error_db::entry<"Requested format(s) is not supported">;
    using graphics_queue_not_found          = error_db::entry<"No graphics queue found">;
    using graphics_queue_uninitialized      = error_db::entry<"Graphics queue is uninitialized">;
    using insufficient_cpu_memory           = error_db::entry<"Insufficient CPU memory for requested operation">;
    using insufficient_gpu_memory           = error_db::entry<"Insufficient GPU memory for requested operation">;
    using present_queue_not_found           = error_db::entry<"No present queue found">;
    using present_queue_uninitialized       = error_db::entry<"Present queue is uninitialized">;
    using swapchain_uninitialized           = error_db::entry<"Attempting to use an uninitialized/missing swapchain!">;
    using tasker_bad_function               = error_db::entry<"Tasker function is invalid">;
    using tasker_cant_begin                 = error_db::entry<"Tasker unable to begin using the command buffer">;
    using tasker_cant_end                   = error_db::entry<"Tasker unable to end using the command buffer">;
    using tasker_cant_submit                = error_db::entry<"Tasker unable to submit task to queue">;
    using tasker_uninitialized              = error_db::entry<"Tasker is uninitialized">;
    using transfer_queue_not_found          = error_db::entry<"No transfer queue found">;
    using transfer_queue_uninitialized      = error_db::entry<"Transfer queue is uninitialized">;
    using video_decode_queue_not_found      = error_db::entry<"No video decoding queue found">;
    using video_decode_queue_uninitialized  = error_db::entry<"Video decoding queue is uninitialized">;
    using video_encode_queue_not_found      = error_db::entry<"No video encoding queue found">;
    using video_encode_queue_uninitialized  = error_db::entry<"Video encoding queue is uninitialized">;
    using visualizer_insufficient           = error_db::entry<"Attempting to use an under-initialized visualizer">;
    using visualizer_uninitialized          = error_db::entry<"Attempting to use an uninitialized visualizer">;
    using vulkan_device_cant_create         = error_db::entry<"Unable to create vulkan (logical) device">;
    using vulkan_device_lost                = error_db::entry<"Device has been lost">;
    using vulkan_instance_cant_create       = error_db::entry<"Unable to create vulkan instance">;
    using vulkan_no_application             = error_db::entry<"No application available">;
    using vulkan_no_physical_device         = error_db::entry<"No GPU/Physical device provided or detected">;
    using vulkan_no_window_provided         = error_db::entry<"No window provided">;
    using vulkan_no_window_surface          = error_db::entry<"No window surface available">;
    using vulkan_out_of_device_memory       = error_db::entry<"Out of device memory">;
    using vulkan_out_of_host_memory         = error_db::entry<"Out of host memory">;
    using vulkan_uninitialized              = error_db::entry<"Vulkan unavailable">;
    
    using not_object_looking_for            = error_db::entry<"This isn't the object we're looking for">;
    using not_delegate_looking_for          = error_db::entry<"This isn't the delegate we're looking for">;
    using not_asset_looking_for             = error_db::entry<"This isn't the asset we're looking for">;
}
