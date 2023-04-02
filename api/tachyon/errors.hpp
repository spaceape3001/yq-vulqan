////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/ErrorDB.hpp>

namespace yq {
    namespace errors {
        using bad_extension             = error_db::entry<"Bad file extension">;
        using glfw_window_create        = error_db::entry<"Unable to create GLFW window">;
        using no_application            = error_db::entry<"No application available">;
        using no_compute_queue          = error_db::entry<"No compute queue capability">;
        using no_graphic_queue          = error_db::entry<"No graphic queue capability">;
        using no_gpu_device             = error_db::entry<"No GPU/Physical Device provided.">;
        using no_present_queue          = error_db::entry<"No present queue capability">;
        using no_queue_found            = error_db::entry<"No Suitable Queue Found">;
        using no_surface_capabilities   = error_db::entry<"Unable to get surface capabilities">;
        using no_video_decode_queue     = error_db::entry<"No video decode queue capability">;
        using no_video_encode_queue     = error_db::entry<"No video encode queue capability">;
        using no_vulkan                 = error_db::entry<"No vulkan available">;
        using no_window                 = error_db::entry<"No window provided.">;
        using no_window_surface         = error_db::entry<"No window surface available">;
        using shader_compile_failure    = error_db::entry<"Shader failed to compile">;
        using shader_needs_type         = error_db::entry<"Shader needs a valid type">;
        using shader_creation_failure   = error_db::entry<"Unable to create the shader">;
        using unavailable_layer         = error_db::entry<"Unavailable layer requested">;
        using unavailable_extension     = error_db::entry<"Unavailable extension requested">;
        using unavailable_validation    = error_db::entry<"Validataion layer is unavailable">;
        using vulkan_create_failure     = error_db::entry<"Unable to create vulkan instance">;
        using vulkan_device_cant_create = error_db::entry<"Unable to create vulkan logical device">;
    }
}
