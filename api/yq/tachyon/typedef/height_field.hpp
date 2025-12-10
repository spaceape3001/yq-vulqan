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
    class TextureInfo;
    
    //class HeightField;
    using HeightField = Texture;    // temporary... for now

    using HeightFieldPtr            = Ref<HeightField>;
    using HeightFieldCPtr           = Ref<const HeightField>;
    
    //struct HeightFieldInfo;
    using HeightFieldInfo       = TextureInfo;

    template <class> class ID;
    using HeightFieldID     = ID<HeightField>;
}
