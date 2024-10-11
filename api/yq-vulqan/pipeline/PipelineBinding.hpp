////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/core/Flag.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Binding point for this pipeline
    
        Basically, the type of pipeline 
    */
    YQ_ENUM(PipelineBinding, , 
        Graphics        = 0,
        Compute         = 1,
        ExecutionGraph  = 1000134000,
        RayTracing      = 1000165000,
        SubpassShading  = 1000369003
    )
}
YQ_TYPE_DECLARE(yq::tachyon::PipelineBinding)
