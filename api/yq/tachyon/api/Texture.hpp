////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/core/UniqueID.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/tachyon/enum/DataFormat.hpp>
#include <yq/tachyon/enum/ComponentSwizzle.hpp>
#include <yq/tachyon/enum/ImageAspect.hpp>
#include <yq/tachyon/enum/ImageViewCreateFlags.hpp>
#include <yq/tachyon/enum/ImageViewType.hpp>
#include <yq/tachyon/api/SamplerInfo.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <yq/tachyon/typedef/sampler.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <optional>

namespace yq::tachyon {

    struct TextureInfo {
        //! Image view type
        std::optional<ImageViewType>    imageViewType;
        
        //! Image view flags
        ImageViewCreateFlags            imageViewFlags           = {};
        
        //! Image view format
        std::optional<DataFormat>       format;
        
        //! Image view swizzle
        RGBA<ComponentSwizzle>          swizzle         = { ComponentSwizzle::Identity, ComponentSwizzle::Identity, ComponentSwizzle::Identity, ComponentSwizzle::Identity };
        
        //! Image view aspect
        ImageAspectFlags                aspect          = ImageAspectFlags(ImageAspect::Color);
        
        //! Image view base mip level
        uint32_t                        baseMipLevel    = 0;
        
        //! Image view level count
        uint32_t                        levelCount      = 1;
        
        //! Image view base array layer
        uint32_t                        baseArrayLayer  = 0;
        
        //! Image view layer count
        uint32_t                        layerCount      = 1;
    };

    struct TextureInfo2 : public TextureInfo, public SamplerInfo {
    };


    //! Texture (image & view/sampler info)
    class Texture : public UniqueID, public RefCount {
    public:
    
        //! Image
        const RasterCPtr            image;

        //! Sampler info
        const SamplerCPtr           sampler;
        
        //! View information
        const TextureInfo           info;

        static TextureCPtr  load(std::string_view);
        static TextureCPtr  load(std::string_view, const SamplerCPtr& _sampler);
        static TextureCPtr  load(std::string_view, const TextureInfo& texInfo);
        static TextureCPtr  load(std::string_view, const TextureInfo2& texInfo);
        static TextureCPtr  load(std::string_view, const SamplerCPtr& _sampler, const TextureInfo& texInfo = {});

        Texture(RasterCPtr);
        Texture(RasterCPtr, const SamplerCPtr& _sampler, const TextureInfo& texInfo={});
        Texture(RasterCPtr, const TextureInfo& texInfo);
        Texture(RasterCPtr, const TextureInfo2& texInfo);
        
    private:
        ~Texture();
    };
}

