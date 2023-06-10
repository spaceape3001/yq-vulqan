////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {

    /*! \brief Image type
    
        This is the type of the image for vulkan.  One...two...three dimensions.
    */
    YQ_ENUM(ImageType, ,
        D1 = 0,
        D2 = 1,
        D3 = 2,

        Is1D = D1,
        Is2D = D2,
        Is3D = D3
    )
}

YQ_TYPE_DECLARE(yq::tachyon::ImageType)
