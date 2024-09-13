////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Texture.hpp"

#include <yq-vulqan/image/Image.hpp>
#include <yq-vulqan/sampler/Sampler.hpp>

namespace yq::tachyon {
    TextureCPtr  Texture::load(std::string_view pp)
    {
        return load(pp, TextureInfo(), Sampler::simple());
    }
    
    TextureCPtr  Texture::load(std::string_view pp, const SamplerCPtr& _sampler)
    {
        return load(pp, TextureInfo(), _sampler);
    }

    TextureCPtr  Texture::load(std::string_view pp, const TextureInfo2& texInfo)
    {
        return load(pp, texInfo, new Sampler(texInfo));
    }
    
    TextureCPtr  Texture::load(std::string_view pp, const TextureInfo& texInfo)
    {
        return load(pp, texInfo, Sampler::simple());
    }
    
    TextureCPtr  Texture::load(std::string_view pp, const TextureInfo& texInfo, const SamplerCPtr& _sampler)
    {
        if(!_sampler)
            return {};
        
        ImageCPtr   img = Image::load(pp);
        if(!img)
            return {};
        
        return new Texture(img, texInfo, _sampler);
    }


    Texture::Texture(ImageCPtr img) : Texture(img, TextureInfo(), Sampler::simple())
    {
    }
    
    Texture::Texture(ImageCPtr img, const TextureInfo& texInfo) : Texture(img, texInfo, Sampler::simple())
    {
    }

    Texture::Texture(ImageCPtr img, const TextureInfo2& texInfo) : Texture(img, texInfo, new Sampler(texInfo))
    {
    }

    Texture::Texture(ImageCPtr img, const TextureInfo& _info, const SamplerCPtr& sam) : 
        image(img), info(_info), sampler(sam)
    {
    }
    
    Texture::~Texture()
    {
    }
}
