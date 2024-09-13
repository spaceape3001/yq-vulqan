////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/shape/Size4.hpp>
#include <yq-vulqan/data/DataFormat.hpp>
#include <yq-vulqan/image/ImageType.hpp>
#include <yq-vulqan/image/ImageTiling.hpp>

namespace yq::tachyon {

    /*! \brief Image information
    
        Basic image information structure, can be used by pixmaps & textures
    */
    struct ImageInfo {
        //! Size of the image
        Size4U      size        = Size4U(ONE);
        
        //! Format of the image
        DataFormat  format      = DataFormat::R8G8B8A8_SRGB;
        
        //! General dimension of image
        ImageType   type        = ImageType::Is2D;
        
        //! Image tiling
        ImageTiling tiling      = ImageTiling::Optimal;
        
        //! Number of layers in the array
        unsigned    arrayLayers = 1;
        
        //! Number of miplevels in the image
        unsigned    mipLevels   = 1;
    };

};

