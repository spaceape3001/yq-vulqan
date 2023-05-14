////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/viz/Image.hpp>
#include <tachyon/viz/ImageViewInfo.hpp>
#include <tachyon/viz/SamplerInfo.hpp>

namespace yq::tachyon {

    class Texture : public UniqueID, public RefCount {
    public:
    
        const Ref<const Image>      image;
        const ImageViewInfo         view;
        const SamplerInfo           sampler;
        
        Texture(Ref<const Image>, const ImageViewInfo&, const SamplerInfo&);
        
    private:
        ~Texture();
    };
}

