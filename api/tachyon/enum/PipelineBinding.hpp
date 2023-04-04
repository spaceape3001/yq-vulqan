////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/Flag.hpp>
#include <meta/InfoBinder.hpp>

namespace yq {
    namespace tachyon {
        YQ_ENUM(PipelineBinding, , 
            Graphics = 0,
            Compute = 0,
            RayTracing = 1000165000,
            SubpassShading = 1000369003
        )
    }
}
YQ_TYPE_DECLARE(yq::tachyon::PipelineBinding)
