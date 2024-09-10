////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <variant>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Shader;
    class ViShader;
    
    using ShaderPtr         = Ref<Shader>;
    using ShaderCPtr        = Ref<const Shader>;

    using ShaderSpec        = std::variant<std::monostate, std::string, ShaderCPtr>;

    using ViShaderPtr       = Ref<ViShader>;
    using ViShaderCPtr      = Ref<const ViShader>;
}
