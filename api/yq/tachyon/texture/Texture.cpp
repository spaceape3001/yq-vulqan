////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Texture.hpp"

#include <tachyon/image/Raster.hpp>
#include <tachyon/sampler/Sampler.hpp>

namespace yq::tachyon {
    TextureCPtr  Texture::load(std::string_view pp)
    {
        return load(pp, Sampler::simple(), TextureInfo());
    }
    
    TextureCPtr  Texture::load(std::string_view pp, const SamplerCPtr& _sampler, const TextureInfo& _info)
    {
        if(!_sampler)
            return {};
        RasterCPtr   img = Raster::load(pp);
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
    

    Texture::Texture(RasterCPtr img) : Texture(img, Sampler::simple())
    {
    }
    
    Texture::Texture(RasterCPtr img, const TextureInfo& texInfo) : Texture(img, Sampler::simple(), texInfo)
    {
    }

    Texture::Texture(RasterCPtr img, const TextureInfo2& texInfo) : Texture(img, new Sampler(texInfo), texInfo)
    {
    }

    Texture::Texture(RasterCPtr img, const SamplerCPtr& _sampler, const TextureInfo& _info) : image(img), sampler(_sampler), info(_info)
    {
    }
    
    Texture::~Texture()
    {
    }
}
