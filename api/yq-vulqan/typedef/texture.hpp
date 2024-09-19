////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Texture;
    using TexturePtr            = Ref<Texture>;
    using TextureCPtr           = Ref<const Texture>;

    class ViTexture;
    using ViTexturePtr          = Ref<ViTexture>;
    using ViTextureCPtr         = Ref<const ViTexture>;

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViTextureManager      = ViManager<ViTexture, Texture>;
    using ViTextureManagerUPtr  = std::unique_ptr<ViTextureManager>;
}
