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
    class Image;
    
    using ImagePtr = Ref<Image>;
    using ImageCPtr = Ref<const Image>;
    
    class ViImage;
    using ViImagePtr    = Ref<ViImage>;
    using ViImageCPtr   = Ref<const ViImage>;
    
    class ViImageManager;
}
