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

    //! Flags for creating image views
    YQ_ENUM(ImageViewCreateFlag, ,
        // Fragment Density Map dynamic
        FDM_Dynamic     = 0,
        // Fragment Density Map deferred
        FDM_Deferred    = 1,
        // Descriptor Buffer Capture replay
        DBC_Replay      = 2
    )
    
    using ImageViewCreateFlags  = Flag<ImageViewCreateFlag>;
}

YQ_TYPE_DECLARE(yq::tachyon::ImageViewCreateFlag)
YQ_TYPE_DECLARE(yq::tachyon::ImageViewCreateFlags)
