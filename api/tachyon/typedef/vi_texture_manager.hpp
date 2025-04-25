////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <memory>

namespace yq::tachyon {
    class Texture;
    class ViTexture;
    template <typename V, typename A, typename ... Args> class ViManager2;
    using ViTextureManager      = ViManager2<const ViTexture, Texture>;
    using ViTextureManagerUPtr  = std::unique_ptr<ViTextureManager>;
}
