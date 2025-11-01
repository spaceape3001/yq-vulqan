////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq::tachyon {
    class Raster;
    class ViImage;

    template <typename V, typename A, typename ... Args> class ViManager2;
    using ViImageManager        = ViManager2<const ViImage, Raster>;

    using ViImageManagerUPtr    = std::unique_ptr<ViImageManager>;
}
