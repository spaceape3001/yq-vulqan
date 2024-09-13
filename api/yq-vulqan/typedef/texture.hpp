////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace yq {
    template <typename> class Ref;
}

namespace yq::tachyon {
    class Texture;
    using TexturePtr     = Ref<Texture>;
    using TextureCPtr    = Ref<const Texture>;

    class ViTexture;
    using ViTexturePtr   = Ref<ViTexture>;
    using ViTextureCPtr  = Ref<const ViTexture>;
}
