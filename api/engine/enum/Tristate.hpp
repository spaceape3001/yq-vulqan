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
        YQ_ENUM(Tristate, ,
            INHERIT     = 1,
            NO          = 0,
            YES         = 2,
            MAYBE       = INHERIT
        );
    }
}
YQ_TYPE_DECLARE(yq::engine::Tristate)
