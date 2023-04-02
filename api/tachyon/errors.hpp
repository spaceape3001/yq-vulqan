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
        using no_application            = error_db::entry<"No application available.">;
        using no_queue_found            = error_db::entry<"No Suitable Queue Found">;
        using vulkan_create_failure     = error_db::entry<"Unable to create vulkan instance">;
        using no_vulkan                 = error_db::entry<"No vulkan available">;
        using no_window                 = error_db::entry<"No window provided.">;
        using unavailable_layer         = error_db::entry<"Unavailable layer requested">;
        using unavailable_extension     = error_db::entry<"Unavailable extension requested">;
        using unavailable_validation    = error_db::entry<"Validataion layer is unavailable">;
        using shader_compile_failure    = error_db::entry<"Shader failed to compile">;
    }
}
