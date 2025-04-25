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
    using TexturePtr            = Ref<Texture>;
    using TextureCPtr           = Ref<const Texture>;
    
    struct TextureInfo;

    template <class> class ID;
    
    using TextureID     = ID<Texture>;
}
