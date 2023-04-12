////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/Enum.hpp>
#include <meta/InfoBinder.hpp>

namespace yq::tachyon {
    YQ_ENUM(ShaderType, ,
        UNKNOWN,
        VERT,
        TESE,
        TESC,
        FRAG,
        GEOM,
        COMP
    )
    
    using ShaderTypeFlags   = Flag<ShaderType>;
}

YQ_TYPE_DECLARE(yq::tachyon::ShaderType)
YQ_TYPE_DECLARE(yq::tachyon::ShaderTypeFlags)
