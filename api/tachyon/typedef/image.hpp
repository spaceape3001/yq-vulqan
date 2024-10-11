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
    class Image;
    
    using ImagePtr              = Ref<Image>;
    using ImageCPtr             = Ref<const Image>;
    
    class ViImage;
    using ViImagePtr            = Ref<ViImage>;
    using ViImageCPtr           = Ref<const ViImage>;

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViImageManager        = ViManager<const ViImage, Image>;

    using ViImageManagerUPtr    = std::unique_ptr<ViImageManager>;
}
