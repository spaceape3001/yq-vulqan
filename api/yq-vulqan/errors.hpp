////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/errors.hpp>

namespace yq::tachyon::errors {
    using namespace yq::errors;
    
    using BAD_STATE_BUFFER              = error_db::entry<"Buffer is in a bad state">;
    using BAD_STATE_COMMAND_BUFFER      = error_db::entry<"Command buffer is in a bad state">;
    using BAD_STATE_COMMAND_POOL        = error_db::entry<"Command pool is in a bad state">;
    using BAD_STATE_FENCE               = error_db::entry<"Fence is in a bad state">;
    using BAD_STATE_SHADER              = error_db::entry<"Shader is in a bad state">;
    using CANT_CREATE_COMMAND_BUFFER    = error_db::entry<"Unable to create vulkan command buffer(s)">;
    using CANT_CREATE_COMMAND_POOL      = error_db::entry<"Unable to create vulkan command pool">;
    using CANT_CREATE_FENCE             = error_db::entry<"Unable to create vulkan fence">;
    using CANT_CREATE_VULKAN_DEVICE     = error_db::entry<"Unable to create vulkan (logical) device">;
    using CANT_CREATE_SHADER            = error_db::entry<"Unable to create vulkan shader module">;
    using CANT_MAP_BUFFER_MEMORY        = error_db::entry<"Unable to map buffer memory">;
    using CANT_RESET_COMMAND_POOL       = error_db::entry<"Unable to reset the command pool">;
    using EMPTY_BUFFER                  = error_db::entry<"Buffer is empty">;
    using EMPTY_SHADER                  = error_db::entry<"Shader is empty">;
    using EXISTING_BUFFER               = error_db::entry<"Buffer already created">;
    using EXISTING_COMMAND_BUFFER       = error_db::entry<"Command buffer already created">;
    using EXISTING_COMMAND_POOL         = error_db::entry<"Command pool already created">;
    using EXISTING_FENCE                = error_db::entry<"Fence already created">;
    using EXISTING_SHADER               = error_db::entry<"Shader already created">;
    using INSUFFICIENT_GPU_MEMORY       = error_db::entry<"Insufficient GPU memory for requested operation">;
    using NO_APPLICATION_AVAILABLE      = error_db::entry<"No application available">;
    using NO_BUFFER_MANAGER             = error_db::entry<"Buffer manager is missing (Visualizer initialized?)">;
    using NO_COMPUTE_QUEUE              = error_db::entry<"No compute queue found">;
    using NO_GRAPHICS_QUEUE             = error_db::entry<"No graphics queue found">;
    using NO_PHYSICAL_DEVICE            = error_db::entry<"No GPU/Physical device provided or detected">;
    using NO_PRESENT_QUEUE              = error_db::entry<"No present queue found">;
    using NO_SHADER_MANAGER             = error_db::entry<"Shader manager is missing (Visualizer initialized?)">;
    using NO_TRANSFER_QUEUE             = error_db::entry<"No transfer queue found">;
    using NO_WINDOW_PROVIDED            = error_db::entry<"No window provided">;
    using NO_WINDOW_SURFACE             = error_db::entry<"No window surface available">;
    using NO_VIDEO_DECODE_QUEUE         = error_db::entry<"No video decoding queue found">;
    using NO_VIDEO_ENCODE_QUEUE         = error_db::entry<"No video encoding queue found">;
    using NULLPTR_COMMAND_POOL          = error_db::entry<"Null pointer of a command pool">;
    using SKIPPING_ZERO_SIZED_BUFFER    = error_db::entry<"Skipping zero sized buffer">;
    using UNINITIALIZED_BUFFER          = error_db::entry<"Attempting to use an uninitialized buffer">;
    using UNINITIALIZED_COMMAND_BUFFER  = error_db::entry<"Attempting to use an uninitialized command buffer">;
    using UNINITIALIZED_COMMAND_POOL    = error_db::entry<"Attempting to use an uninitialized command pool">;
    using UNINITIALIZED_VISUALIZER      = error_db::entry<"Attempting to use an uninitialized visualizer">;
    using UNSUPPORTED_FORMAT            = error_db::entry<"Requested format(s) is not supported">;
    using VULKAN_UNAVAILABLE            = error_db::entry<"Vulkan unavailable">;
}
