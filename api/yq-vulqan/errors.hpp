////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/ErrorDB.hpp>

namespace yq::errors {
    using INSUFFICIENT_GPU_MEMORY       = error_db::entry<"Insufficient GPU memory for requested operation">;
    using SKIPPING_ZERO_SIZED_BUFFER    = error_db::entry<"Skipping zero sized buffer">;
}
