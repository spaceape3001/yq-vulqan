////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {

    //! Flags for creating image views
    enum class ImageViewCreateFlag : uint8_t {
        // Fragment Density Map dynamic
        FDM_Dynamic     = 0,
        // Fragment Density Map deferred
        FDM_Deferred    = 1,
        // Descriptor Buffer Capture replay
        DBC_Replay      = 2
    };
    
    using ImageViewCreateFlags  = Flags<ImageViewCreateFlag, uint32_t>;
}

YQ_TYPE_DECLARE(yq::tachyon::ImageViewCreateFlag)
YQ_TYPE_DECLARE(yq::tachyon::ImageViewCreateFlags)
