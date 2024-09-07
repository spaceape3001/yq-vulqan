////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Enum.hpp>
#include <yq-toolbox/basic/Flag.hpp>
#include <yq-toolbox/meta/InfoBinder.hpp>

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
        COMP,
        //! Task shader
        TASK,
        //! Mesh shader
        MESH
    )
    
    //! Mask of shader types
    using ShaderTypeFlags   = Flag<ShaderType>;
}

YQ_TYPE_DECLARE(yq::tachyon::ShaderType)
YQ_TYPE_DECLARE(yq::tachyon::ShaderTypeFlags)
