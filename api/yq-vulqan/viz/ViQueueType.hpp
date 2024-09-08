////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Flags.hpp>

namespace yq::tachyon {
    enum class ViQueueType : uint8_t {
        Graphic = 0,
        Present,
        Compute,
        VideoEncode,
        VideoDecode
    };

    using ViQueueTypeFlags  = Flags<ViQueueType>;
}
