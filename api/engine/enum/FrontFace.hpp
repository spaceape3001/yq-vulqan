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
        YQ_ENUM(FrontFace, , 
            CounterClockwise    = 0,
            Clockwise = 1
        )
    }
}
YQ_TYPE_DECLARE(yq::engine::FrontFace)
