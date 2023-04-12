////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(ImageType, ,
        D1 = 0,
        D2 = 1,
        D3 = 2,
        D4 = 3,

        Is1D = D1,
        Is2D = D2,
        Is3D = D3,
        Is4D = D4
    )
}

YQ_TYPE_DECLARE(yq::tachyon::ImageType)
