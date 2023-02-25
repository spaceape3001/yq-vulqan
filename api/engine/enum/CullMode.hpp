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
        YQ_ENUM(CullMode, , 
            None    = 0,
            Front   = 1,
            Back    = 2,
            FrontBack   = 3
        )
    }
}

YQ_TYPE_DECLARE(yq::engine::CullMode)
