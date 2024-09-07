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
    class ImageAsset;
    //! Temporary hack
    using Image = ImageAsset;
    
    using ImageAssetPtr = Ref<ImageAsset>;
    using ImageAssetCPtr = Ref<const ImageAsset>;
}
