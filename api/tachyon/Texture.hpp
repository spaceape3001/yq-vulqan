////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Image.hpp>
#include <tachyon/viz/ImageViewInfo.hpp>
#include <tachyon/viz/SamplerInfo.hpp>

namespace yq::tachyon {

    //! Texture (image & view/sampler info)
    class Texture : public UniqueID, public RefCount {
    public:
    
        //! Image
        const Ref<const Image>      image;
        
        //! View information
        const ImageViewInfo         view;
        
        //! Sampler info
        const SamplerInfo           sampler;
        
        //! Default constructor
        Texture(Ref<const Image>, const ImageViewInfo&, const SamplerInfo&);
        
    private:
        ~Texture();
    };
}

