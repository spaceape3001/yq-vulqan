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
        return load(pp, Sampler::simple(), TextureInfo());
    }
    
    TextureCPtr  Texture::load(std::string_view pp, const SamplerCPtr& _sampler, const TextureInfo& _info)
    {
        if(!_sampler)
            return {};
        ImageCPtr   img = Image::load(pp);
        if(!img)
            return {};
        return new Texture(img, _sampler, _info);
    }

    TextureCPtr  Texture::load(std::string_view pp, const TextureInfo2& texInfo)
    {
        return load(pp, new Sampler(texInfo), texInfo);
    }
    
    TextureCPtr  Texture::load(std::string_view pp, const TextureInfo& texInfo)
    {
        return load(pp, Sampler::simple(), texInfo);
    }
    

    Texture::Texture(ImageCPtr img) : Texture(img, Sampler::simple())
    {
    }
    
    Texture::Texture(ImageCPtr img, const TextureInfo& texInfo) : Texture(img, Sampler::simple(), texInfo)
    {
    }

    Texture::Texture(ImageCPtr img, const TextureInfo2& texInfo) : Texture(img, new Sampler(texInfo), texInfo)
    {
    }

    Texture::Texture(ImageCPtr img, const SamplerCPtr& _sampler, const TextureInfo& _info) : image(img), sampler(_sampler), info(_info)
    {
    }
    
    Texture::~Texture()
    {
    }
}
