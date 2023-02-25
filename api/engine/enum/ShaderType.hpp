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
}

YQ_TYPE_DECLARE(yq::engine::ShaderType)
YQ_TYPE_DECLARE(yq::engine::ShaderTypeFlags)
