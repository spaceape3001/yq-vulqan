////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(ImageViewType, ,
        D1          = 0,
        D2          = 1,
        D3          = 2,
        Cube        = 3,
        Array1D     = 4,
        Array2D     = 5,
        ArrayCube   = 6,

        Is1D = D1,
        Is2D = D2,
        Is3D = D3
    )
}
YQ_TYPE_DECLARE(yq::tachyon::ImageViewType)


