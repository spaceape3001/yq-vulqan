////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <variant>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class ShaderAsset;
    //! Temporary hack
    using Shader = ShaderAsset;
    
    using ShaderAssetPtr    = Ref<ShaderAsset>;
    using ShaderAssetCPtr   = Ref<const ShaderAsset>;
    using ShaderCPtr        = Ref<const Shader>;

    using ShaderSpec        = std::variant<std::monostate, std::string, ShaderAssetCPtr>;

}
