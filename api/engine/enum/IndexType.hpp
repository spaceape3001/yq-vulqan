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
        YQ_ENUM(IndexType, ,
            none    = 1000165000,
            uint16  = 0,
            uint32  = 1,
            uint8   = 1000265000
        )
    }
}
YQ_TYPE_DECLARE(yq::engine::IndexType)
