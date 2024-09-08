////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/errors.hpp>

namespace yq::tachyon::errors {
    using namespace yq::errors;
    
    using INSUFFICIENT_GPU_MEMORY       = error_db::entry<"Insufficient GPU memory for requested operation">;
    using SKIPPING_ZERO_SIZED_BUFFER    = error_db::entry<"Skipping zero sized buffer">;
    using NO_BUFFER_MANAGER             = error_db::entry<"Buffer manager is missing (Visualizer initialized?)">;
    using NO_SHADER_MANAGER             = error_db::entry<"Shader manager is missing (Visualizer initialized?)">;
}
