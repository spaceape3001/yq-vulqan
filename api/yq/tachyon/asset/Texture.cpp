////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/asset/Sampler.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/resource/ResourceMetaWriter.hpp>
#include <yq/resource/Resource.hxx>

namespace yq::tachyon {

    static TexturePtr raster_to_texture(const RasterCPtr& ras)
    {
        return new Texture(ras, Sampler::simple(), TextureInfo());
    }

    void Texture::init_meta()
    {
        auto w = writer<Texture>();
        w.description("Texture");
        Texture::IO::add_converter_from<Raster>(raster_to_texture);
    }

    TextureCPtr  Texture::load(const UrlView&u)
    {
        return Texture::IO::load(u);
    }
    

    TextureCPtr  Texture::load(std::string_view pp)
    {
        return Texture::IO::load(pp);
    }
    
    TextureCPtr  Texture::load(std::string_view pp, const SamplerCPtr& _sampler, const TextureInfo& _info)
    {
        if(!_sampler)
            return {};
        RasterCPtr   img = Raster::IO::load(pp);
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

    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    TextureCPtr  Texture::load(std::initializer_list<std::string_view> pps)
    {
        return load(pps, Sampler::simple(), TextureInfo());
    }
    
    TextureCPtr  Texture::load(std::initializer_list<std::string_view> pps, const TextureInfo& texInfo)
    {
        return load(pps, Sampler::simple(), texInfo);
    }
    
    TextureCPtr  Texture::load(std::initializer_list<std::string_view> pps, const TextureInfo2& texInfo)
    {
        return load(pps, new Sampler(texInfo), texInfo);
    }
    
    TextureCPtr  Texture::load(std::initializer_list<std::string_view> pps, const SamplerCPtr& _sampler, const TextureInfo& texInfo)
    {
        if(!_sampler)
            return {};
        std::vector<RasterCPtr> imgs;
        for(std::string_view pp : pps){
            RasterCPtr  img = Raster::IO::load(pp);
            if(!img)
                return {};
            imgs.push_back(img);
        }

        return new Texture(std::move(imgs), _sampler, texInfo);
    }

    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    TextureCPtr  Texture::load(std::span<const std::string_view> pps)
    {
        return load(pps, Sampler::simple(), TextureInfo());
    }
    
    TextureCPtr  Texture::load(std::span<const std::string_view> pps, const TextureInfo& texInfo)
    {
        return load(pps, Sampler::simple(), texInfo);
    }
    
    TextureCPtr  Texture::load(std::span<const std::string_view> pps, const TextureInfo2& texInfo)
    {
        return load(pps, new Sampler(texInfo), texInfo);
    }
    
    TextureCPtr  Texture::load(std::span<const std::string_view> pps, const SamplerCPtr& _sampler, const TextureInfo& texInfo)
    {
        if(!_sampler)
            return {};
        std::vector<RasterCPtr> imgs;
        for(std::string_view pp : pps){
            RasterCPtr  img = Raster::IO::load(pp);
            if(!img)
                return {};
            imgs.push_back(img);
        }

        return new Texture(std::move(imgs), _sampler, texInfo);
    }
    
    // ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    Texture::Texture(RasterCPtr img) : Texture(img, Sampler::simple())
    {
    }
    
    Texture::Texture(RasterCPtr img, const TextureInfo& texInfo) : Texture(img, Sampler::simple(), texInfo)
    {
    }

    Texture::Texture(RasterCPtr img, const TextureInfo2& texInfo) : Texture(img, new Sampler(texInfo), texInfo)
    {
    }

    Texture::Texture(RasterCPtr img, const SamplerCPtr& _sampler, const TextureInfo& _info) : 
        images({img}), sampler(_sampler), info(_info)
    {
    }

    Texture::Texture(std::vector<RasterCPtr>&& imgs) : Texture(std::move(imgs), Sampler::simple())
    {
    }
    
    Texture::Texture(std::vector<RasterCPtr>&& imgs, const TextureInfo& texInfo) : 
        Texture(std::move(imgs), Sampler::simple(), texInfo)
    {
    }
    
    Texture::Texture(std::vector<RasterCPtr>&& imgs, const TextureInfo2& texInfo) : 
        Texture(std::move(imgs), new Sampler(texInfo), texInfo)
    {
    }

    Texture::Texture(std::vector<RasterCPtr>&& imgs, const SamplerCPtr& _sampler, const TextureInfo& texInfo) : 
        images(std::move(imgs)), sampler(_sampler), info(texInfo)
    {
    }
    
    Texture::~Texture()
    {
    }
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Texture)
