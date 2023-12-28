////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <0/basic/Enum.hpp>
#include <0/meta/InfoBinder.hpp>

namespace yq::tachyon {
    /*! \brief Shader Type
    
        This is the type of shader (supported)
    */
    YQ_ENUM(ShaderType, ,
        //! Unknown shader type
        UNKNOWN,
        //! Vertex shader
        VERT,
        //! Tessellation Evaluation shader
        TESE,
        //! Tessellation Control shader
        TESC,
        //! Fragment shader
        FRAG,
        //! Geometry shader
        GEOM,
        //! Compute shader
        COMP
    )
    
    //! Mask of shader types
    using ShaderTypeFlags   = Flag<ShaderType>;
}

YQ_TYPE_DECLARE(yq::tachyon::ShaderType)
YQ_TYPE_DECLARE(yq::tachyon::ShaderTypeFlags)
