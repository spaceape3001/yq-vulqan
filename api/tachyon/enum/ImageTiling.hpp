////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(ImageTiling, ,
        Optimal = 0,
        Linear = 1,
        DRMFormat = 1000158000
    )
}
YQ_TYPE_DECLARE(yq::tachyon::ImageTiling)
