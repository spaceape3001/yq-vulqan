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

    template <typename V, typename A, typename ... Args> class ViManager;
    using ViImageManager        = ViManager<const ViImage, Raster>;

    using ViImageManagerUPtr    = std::unique_ptr<ViImageManager>;
}
