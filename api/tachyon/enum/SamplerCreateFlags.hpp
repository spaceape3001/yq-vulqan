////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/basic/Flag.hpp>
#include <0/meta/InfoBinder.hpp>

namespace yq::tachyon {
    //! Creation flag for vulkan samplers
    YQ_ENUM(SamplerCreateFlag, ,
        //! Sampler will read from image created with this flag
        Subsampled              = 0,
        //! Permits the sampler to use approximations on color recreation on subsampled image
        CoarseReconstruction    = 1,
        //! Cube map edge handling won't be performed.
        NonSeamlessCubeMap      = 2,
        //! Allows for sampler to be used with descriptor buffers in capture & replay
        DescriptorCapture       = 3,
        //! Images used QCOM options
        ImageProcessing         = 4
    )
    
    //! Creation flag bit-field
    using SamplerCreateFlags  = Flag<SamplerCreateFlag>;
}

YQ_TYPE_DECLARE(yq::tachyon::SamplerCreateFlag)
YQ_TYPE_DECLARE(yq::tachyon::SamplerCreateFlags)
