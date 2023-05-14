////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <math/UVW.hpp>

#include <tachyon/enum/BorderColor.hpp>
#include <tachyon/enum/CompareOp.hpp>
#include <tachyon/enum/SamplerAddressMode.hpp>
#include <tachyon/enum/SamplerCreateFlags.hpp>
#include <tachyon/enum/SamplerFilter.hpp>
#include <tachyon/enum/SamplerMipmapMode.hpp>

namespace yq::tachyon {

    using SamplerAddressModeUVW = UVW<SamplerAddressMode>;

    struct SamplerInfo {
        SamplerCreateFlags      flags                   = {};
        SamplerFilter           magFilter               = SamplerFilter::Linear;
        SamplerFilter           minFilter               = SamplerFilter::Linear;
        SamplerMipmapMode       mipmapMode              = SamplerMipmapMode::Linear;
        SamplerAddressModeUVW   addressMode             = SamplerAddressModeUVW(ALL, SamplerAddressMode::ClampToBorder);
        float                   mipLodBias              = 0.;
        bool                    anisotropyEnable        = false;
        float                   maxAnisotropy           = 0.;
        bool                    compareEnable           = false;
        CompareOp               compareOp               = CompareOp::Always;
        float                   minLod                  = 0.;
        float                   maxLod                  = 0.;
        BorderColor             borderColor             = BorderColor::FloatTransparentBlack;
        RGBA4F                  customBorder            = {};
        bool                    unnormalizedCoordinates = false;
    };
}

