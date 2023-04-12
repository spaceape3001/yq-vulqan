////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(PolygonMode, , 
        Fill = 0,
        Line = 1,
        Point = 2,
        FillRectangleNV = 1000153000
    )
}

YQ_TYPE_DECLARE(yq::tachyon::PolygonMode)
