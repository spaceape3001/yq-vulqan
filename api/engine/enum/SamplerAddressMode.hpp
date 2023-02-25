////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <basic/meta/InfoBinder.hpp>

namespace yq {
    namespace engine {
        YQ_ENUM(SamplerAddressMode, ,
            Repeat  = 0,
            MirroredRepeat = 1,
            ClampToEdge = 2,
            ClampToBorder = 3,
            MirrorClampToEdge = 4
        )
    }
}
YQ_TYPE_DECLARE(yq::engine::SamplerAddressMode)
