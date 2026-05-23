////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Flags.hpp>
#include <yq/meta/MetaBinder.hpp>

namespace yq::tachyon {
    /*! \brief Shader Type
    
        This is the type of shader (supported)
    */
    enum class ShaderType : uint8_t {
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
    };
    
    //! Mask of shader types
    using ShaderTypeFlags   = Flags<ShaderType, uint32_t>;
}

YQ_TYPE_DECLARE(yq::tachyon::ShaderType)
YQ_TYPE_DECLARE(yq::tachyon::ShaderTypeFlags)
