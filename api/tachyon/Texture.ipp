////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Texture.hpp>

namespace yq::tachyon {
    Texture::Texture(Ref<const Image> img, const ImageViewInfo& ivi, const SamplerInfo& si) : image(img), view(ivi), sampler(si)
    {
    }
    
    Texture::~Texture()
    {
    }
}
