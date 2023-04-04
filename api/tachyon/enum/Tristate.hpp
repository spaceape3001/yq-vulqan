////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq {
    namespace tachyon {
        YQ_ENUM(Tristate, ,
            INHERIT     = 1,
            NO          = 0,
            YES         = 2,
            MAYBE       = INHERIT
        );
    }
}
YQ_TYPE_DECLARE(yq::tachyon::Tristate)
