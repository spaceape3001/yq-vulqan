////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/Flag.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Binding point for this pipeline
    
        Basically, the type of pipeline 
    */
    YQ_ENUM(PipelineBinding, , 
        Graphics = 0,
        Compute = 1,
        RayTracing = 1000165000,
        SubpassShading = 1000369003
    )
}
YQ_TYPE_DECLARE(yq::tachyon::PipelineBinding)
