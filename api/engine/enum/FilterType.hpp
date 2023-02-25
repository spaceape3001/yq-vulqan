////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/meta/InfoBinder.hpp>

namespace yq {
    namespace engine {
        YQ_ENUM(FilterType, , 
            Nearest = 0,
            Linear = 1,
            Cubic = 1000015000
        )
    }
}

YQ_TYPE_DECLARE(yq::engine::FilterType)

