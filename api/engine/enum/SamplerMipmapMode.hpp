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
        YQ_ENUM(SamplerMipmapMode, ,
            Nearest = 0,
            Linear = 1
        )
    }
}
YQ_TYPE_DECLARE(yq::engine::SamplerMipmapMode)
