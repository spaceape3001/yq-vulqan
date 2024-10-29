////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size4.hpp>
#include <tachyon/enum/DataFormat.hpp>
#include <tachyon/enum/ImageTiling.hpp>
#include <tachyon/enum/RasterType.hpp>

namespace yq::tachyon {

    /*! \brief Raster image information
    
        Basic raster image information structure, can be used by pixmaps & textures
    */
    struct RasterInfo {
        //! Size of the image
        Size4U      size        = Size4U(ONE);
        
        //! Format of the image
        DataFormat  format      = DataFormat::R8G8B8A8_SRGB;
        
        //! General dimension of image
        RasterType   type        = RasterType::Is2D;
        
        //! Raster tiling
        ImageTiling  tiling      = ImageTiling::Optimal;
        
        //! Number of layers in the array
        unsigned    arrayLayers = 1;
        
        //! Number of miplevels in the image
        unsigned    mipLevels   = 1;
    };

};

