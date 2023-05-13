////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/Flag.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(SamplerCreateFlag, ,
        Subsampled              = 0,
        CoarseReconstruction    = 1,
        NonSeamlessCubeMap      = 2,
        DescriptorCapture       = 3,
        ImageProcessing         = 8
    )
    
    using SamplerCreateFlags  = Flag<SamplerCreateFlag>;
}

YQ_TYPE_DECLARE(yq::tachyon::SamplerCreateFlag)
YQ_TYPE_DECLARE(yq::tachyon::SamplerCreateFlags)
