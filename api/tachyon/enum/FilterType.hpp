////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq {
    namespace tachyon {
        YQ_ENUM(FilterType, , 
            Nearest = 0,
            Linear = 1,
            Cubic = 1000015000
        )
    }
}

YQ_TYPE_DECLARE(yq::tachyon::FilterType)

