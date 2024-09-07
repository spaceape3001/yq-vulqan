////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/image/Image.hpp>
#include <yq-vulqan/image_view/ImageViewInfo.hpp>
#include <yq-vulqan/sampler/SamplerInfo.hpp>

namespace yq::tachyon {

    //! Texture (image & view/sampler info)
    class Texture : public UniqueID, public RefCount {
    public:
    
        //! Image
        const Ref<const ImageAsset> image;
        
        //! View information
        const ImageViewInfo         view;
        
        //! Sampler info
        const SamplerInfo           sampler;
        
        //! Default constructor
        Texture(Ref<const ImageAsset>, const ImageViewInfo&, const SamplerInfo&);
        
    private:
        ~Texture();
    };
}

