////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(SamplerFilter, ,
        Nearest     = 0,
        Linear      = 1,
        Cubic       = 1000015000
    )
}
YQ_TYPE_DECLARE(yq::tachyon::SamplerFilter)
