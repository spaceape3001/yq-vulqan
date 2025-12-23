////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>

namespace yq::tachyon {
    enum class ViQueueType : uint8_t {
        Auto,               //!< Not a real queue, simply means to auto-select
        Graphic,
        Present,            //!< Generally a property to the graphic queue
        Compute,
        VideoEncode,
        VideoDecode,
        OpticalFlow,
        Transfer
    };

    using ViQueueTypeFlags  = Flags<ViQueueType>;
    
    std::string_view    key_for(ViQueueType);
}
