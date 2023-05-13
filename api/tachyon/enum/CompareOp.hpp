////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(CompareOp, , 
        Never           = 0,
        Less            = 1,
        Equal           = 2,
        LessOrEqual     = 3,
        Greater         = 4,
        NotEqual        = 5,
        GreaterOrEqual  = 6,
        Always          = 7
    )
}
YQ_TYPE_DECLARE(yq::tachyon::CompareOp)
