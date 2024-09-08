////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Flags.hpp>

namespace yq::tachyon {
    enum class ViQueueType : uint8_t {
        Auto,       //!< Not a real queue, simply means to auto-select
        Graphic,
        Present,
        Compute,
        VideoEncode,
        VideoDecode,
        Transfer
    };

    using ViQueueTypeFlags  = Flags<ViQueueType>;
}
