////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/shape/Size4.hpp>
#include <yq/tachyon/pipeline/DataFormat.hpp>
#include <yq/tachyon/pipeline/ImageTiling.hpp>

namespace yq::tachyon {

    /*! \brief GriddedData image information
    
        Basic gridded image information structure, can be used by height maps.
        Leveraging the raster types (since it's the same thing TBH).  
    */
    struct GriddedDataInfo {
        //! Size of the gridded data, number of dimensions is the size of this vector
        std::vector<unsigned>   size;
        
        //! Format of the gridded data (used by vulkan)
        DataFormat  format      = DataFormat::R32_SFLOAT;
        
        //! GriddedData tiling
        ImageTiling tiling      = ImageTiling::Optimal;
        
        //! Number of layers in the array
        unsigned    arrayLayers = 1;
        
        //! Number of miplevels in the image
        unsigned    mipLevels   = 1;
    };

};

