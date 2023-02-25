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
        YQ_ENUM(StencilOp, ,
            Keep = 0,
            Zero = 1,
            Replace = 2,
            IncrementAndClamp = 3,
            DecrementAndClamp = 4,
            Invert = 5,
            IncrementAndWrap = 6,
            DecrementAndWrap = 7
        )
    }
}
YQ_TYPE_DECLARE(yq::engine::StencilOp)

