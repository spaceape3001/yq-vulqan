////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <math/shape/Size4.hpp>
#include <tachyon/preamble.hpp>
#include <tachyon/enum/DataFormat.hpp>
#include <tachyon/enum/ImageType.hpp>
#include <tachyon/enum/ImageTiling.hpp>

namespace yq::tachyon {

    /*! \brief Image information
    
        Basic image information structure, can be used by pixmaps & textures
    */
    struct ImageInfo {
        Size4U      size        = Size4U(ONE);
        DataFormat  format      = DataFormat::R8G8B8A8_SRGB;
        ImageType   type        = ImageType::Is2D;
        ImageTiling tiling      = ImageTiling::Optimal;
        unsigned    arrayLayers = 1;
        unsigned    mipLevels   = 1;
    };

};

