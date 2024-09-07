////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/math/UVW.hpp>

#include <yq-vulqan/logic/CompareOp.hpp>
#include <yq-vulqan/sampler/BorderColor.hpp>
#include <yq-vulqan/sampler/SamplerAddressMode.hpp>
#include <yq-vulqan/sampler/SamplerCreateFlags.hpp>
#include <yq-vulqan/sampler/SamplerFilter.hpp>
#include <yq-vulqan/sampler/SamplerMipmapMode.hpp>

namespace yq::tachyon {

    //! Capture the boundary condition to each axis
    using SamplerAddressModeUVW = UVW<SamplerAddressMode>;

    //! Sampler information used for sample creation
    struct SamplerInfo {
    
        //! Sampler creat flags
        SamplerCreateFlags      flags                   = {};
        
        //! Magnitude filter
        SamplerFilter           magFilter               = SamplerFilter::Linear;
        
        //! Minimum filter
        SamplerFilter           minFilter               = SamplerFilter::Linear;
        
        //! Mipmap mode
        SamplerMipmapMode       mipmapMode              = SamplerMipmapMode::Linear;
        
        //! Address mode (ie boundary conditions)
        SamplerAddressModeUVW   addressMode             = SamplerAddressModeUVW(ALL, SamplerAddressMode::ClampToBorder);
        
        //! MIP LOD Bias 
        float                   mipLodBias              = 0.;
        
        //! Anistropy Enable
        bool                    anisotropyEnable        = false;
        
        //! Max Anistropy
        float                   maxAnisotropy           = 0.;
        
        //! Compare enable
        bool                    compareEnable           = false;
        
        //! Comparison operator
        CompareOp               compareOp               = CompareOp::Always;
        
        //! Min LOD
        float                   minLod                  = 0.;
        
        //! Max LOD
        float                   maxLod                  = 0.;
        
        //! Border color
        BorderColor             borderColor             = BorderColor::FloatTransparentBlack;
        
        //! Custom border
        RGBA4F                  customBorder            = {};
        
        //! TRUE to not normalize coordinates (ie not 0...1)
        bool                    unnormalizedCoordinates = false;
    };
}

