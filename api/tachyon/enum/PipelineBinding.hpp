////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/basic/Flag.hpp>
#include <yq/meta/InfoBinder.hpp>

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
