////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/ErrorDB.hpp>

namespace yq {
    namespace errors {
        using no_queue_found            = error_db::entry<"No Suitable Queue Found">;
        using no_vulkan                 = error_db::entry<"Unable to create vulkan instance">;
        using unavailable_layer         = error_db::entry<"Unavailable layer requested">;
        using unavailable_extension     = error_db::entry<"Unavailable extension requested">;
        using unavailable_validation    = error_db::entry<"Validataion layer is unavailable">;
    }
}
