////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/enum/ComponentSwizzle.hpp>
#include <tachyon/enum/DataFormat.hpp>
#include <tachyon/enum/ImageAspect.hpp>
#include <tachyon/enum/ImageViewCreateFlags.hpp>
#include <tachyon/enum/ImageViewType.hpp>
#include <math/color/RGBA.hpp>

namespace yq::tachyon {
    struct ImageViewInfo {
        ImageViewType           type            = ImageViewType::Is2D;
        ImageViewCreateFlags    flags           = {};
        DataFormat              format          = DataFormat::R8G8B8A8_SRGB;
        RGBA<ComponentSwizzle>  swizzle         = { ComponentSwizzle::Identity, ComponentSwizzle::Identity, ComponentSwizzle::Identity, ComponentSwizzle::Identity };
        ImageAspectFlags        aspect          = ImageAspectFlags(ImageAspect::Color);
        uint32_t                baseMipLevel    = 0;
        uint32_t                levelCount      = 1;
        uint32_t                baseArrayLayer  = 0;
        uint32_t                layerCount      = 1;
    };
};
