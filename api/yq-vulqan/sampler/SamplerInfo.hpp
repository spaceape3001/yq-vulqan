////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/color/RGBA.hpp>
#include <yq-toolbox/math/UVW.hpp>
#include <yq-toolbox/typedef/filesystem_path.hpp>
#include <yq-toolbox/typedef/optional.hpp>

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
        class File;
    
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
        boolean_opt             anisotropyEnable;
        
        //! Max Anistropy
        float_opt               maxAnisotropy;
        
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

    std::error_code     sampler_info_load(SamplerInfo&is, const std::filesystem::path&);
    std::error_code     sampler_info_save(const std::filesystem::path&path, const SamplerInfo&);
    
}

