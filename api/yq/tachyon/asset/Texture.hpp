////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/resource/Resource.hpp>
#include <yq/tachyon/asset/TextureInfo.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <yq/tachyon/typedef/sampler.hpp>
#include <yq/tachyon/typedef/texture.hpp>

namespace yq::tachyon {


    //! Texture (image & view/sampler info)
    class Texture : public Resource {
        YQ_RESOURCE_DECLARE(Texture, Resource)
    public:
    
        /*! Image(s)
        
            When there are multiple images, it'll imply multiple layers.  
            
            \note While image sizes SHOULD MATCH, non-matching Images 
            will be RESIZED/RESCALED to the largest image size. 
        */
        std::vector<RasterCPtr>   images;

        //! Sampler info
        SamplerCPtr               sampler;
        
        //! View information
        TextureInfo               info;

        static TextureCPtr  load(const UrlView&);
        static TextureCPtr  load(std::string_view);
        static TextureCPtr  load(std::string_view, const TextureInfo& texInfo);
        static TextureCPtr  load(std::string_view, const TextureInfo2& texInfo);
        static TextureCPtr  load(std::string_view, const SamplerCPtr& _sampler, const TextureInfo& texInfo = {});

        static TextureCPtr  load(std::initializer_list<std::string_view>);
        static TextureCPtr  load(std::initializer_list<std::string_view>, const TextureInfo& texInfo);
        static TextureCPtr  load(std::initializer_list<std::string_view>, const TextureInfo2& texInfo);
        static TextureCPtr  load(std::initializer_list<std::string_view>, const SamplerCPtr& _sampler, const TextureInfo& texInfo = {});

        static TextureCPtr  load(std::span<const std::string_view>);
        static TextureCPtr  load(std::span<const std::string_view>, const TextureInfo& texInfo);
        static TextureCPtr  load(std::span<const std::string_view>, const TextureInfo2& texInfo);
        static TextureCPtr  load(std::span<const std::string_view>, const SamplerCPtr& _sampler, const TextureInfo& texInfo = {});

        Texture(RasterCPtr);
        Texture(RasterCPtr, const SamplerCPtr& _sampler, const TextureInfo& texInfo={});
        Texture(RasterCPtr, const TextureInfo& texInfo);
        Texture(RasterCPtr, const TextureInfo2& texInfo);
        
        Texture(std::vector<RasterCPtr>&&);
        Texture(std::vector<RasterCPtr>&&, const SamplerCPtr& _sampler, const TextureInfo& texInfo={});
        Texture(std::vector<RasterCPtr>&&, const TextureInfo& texInfo);
        Texture(std::vector<RasterCPtr>&&, const TextureInfo2& texInfo);
        
        static void init_meta();
        virtual size_t      data_size() const override { return 0; }
        
    private:
        ~Texture();
    };
}

