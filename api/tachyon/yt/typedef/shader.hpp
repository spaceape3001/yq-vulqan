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
    
    using ShaderPtr             = Ref<Shader>;
    using ShaderCPtr            = Ref<const Shader>;

    using ShaderSpec            = std::variant<std::monostate, std::string, ShaderCPtr>;
}
