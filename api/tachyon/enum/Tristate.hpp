////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(Tristate, ,
        MAYBE       = 1,
        NO          = 0,
        YES         = 2,
        INHERIT     = MAYBE,
        OPTIONAL    = MAYBE
    );
}

YQ_TYPE_DECLARE(yq::tachyon::Tristate)
