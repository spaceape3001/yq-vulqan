////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gfx/DataFormat.hpp>
#include <tachyon/gfx/ComponentSwizzle.hpp>
#include <tachyon/gfx/ImageAspect.hpp>
#include <tachyon/gfx/ImageViewCreateFlags.hpp>
#include <tachyon/gfx/ImageViewType.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {

    //! Descriptive information for creating an image view
    struct ImageViewInfo {
    
        //! Image view type
        ImageViewType           type            = ImageViewType::Is2D;
        
        //! Image view flags
        ImageViewCreateFlags    flags           = {};
        
        //! Image view format
        DataFormat              format          = DataFormat::R8G8B8A8_SRGB;
        
        //! Image view swizzle
        RGBA<ComponentSwizzle>  swizzle         = { ComponentSwizzle::Identity, ComponentSwizzle::Identity, ComponentSwizzle::Identity, ComponentSwizzle::Identity };
        
        //! Image view aspect
        ImageAspectFlags        aspect          = ImageAspectFlags(ImageAspect::Color);
        
        //! Image view base mip level
        uint32_t                baseMipLevel    = 0;
        
        //! Image view level count
        uint32_t                levelCount      = 1;
        
        //! Image view base array layer
        uint32_t                baseArrayLayer  = 0;
        
        //! Image view layer count
        uint32_t                layerCount      = 1;
    };
};
