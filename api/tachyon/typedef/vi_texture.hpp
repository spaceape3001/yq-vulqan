////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <tachyon/typedef/texture.hpp>
#include <variant>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class ViTexture;
    using ViTexturePtr          = Ref<ViTexture>;
    using ViTextureCPtr         = Ref<const ViTexture>;
    using Textured              = std::variant<std::monostate, TextureCPtr, ViTextureCPtr>;
}
