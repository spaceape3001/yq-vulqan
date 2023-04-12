////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(CullMode, , 
        None    = 0,
        Front   = 1,
        Back    = 2,
        FrontBack   = 3
    )
}

YQ_TYPE_DECLARE(yq::tachyon::CullMode)
