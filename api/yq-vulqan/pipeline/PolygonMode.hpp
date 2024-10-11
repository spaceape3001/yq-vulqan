////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Enum.hpp>
#include <yq/meta/InfoBinder.hpp>

namespace yq::tachyon {

    /*! \brief Polygon mode for pipelines
    
        This is the polygon mode for pipelines.  
        Set to Line to get wireframe effect.
    */
    YQ_ENUM(PolygonMode, , 
        Auto = -1,
        Fill = 0,
        Line = 1,
        Point = 2,
        FillRectangleNV = 1000153000
    )
}

YQ_TYPE_DECLARE(yq::tachyon::PolygonMode)
