////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
#include <memory>
#include <variant>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Shader;
    class ViShader;
    
    using ShaderPtr             = Ref<Shader>;
    using ShaderCPtr            = Ref<const Shader>;

    using ShaderSpec            = std::variant<std::monostate, std::string, ShaderCPtr>;

    using ViShaderPtr           = Ref<ViShader>;
    using ViShaderCPtr          = Ref<const ViShader>;

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViShaderManager       = ViManager<const ViShader, Shader>;

    using ViShaderManagerUPtr   = std::unique_ptr<ViShaderManager>;
}
