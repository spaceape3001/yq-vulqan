////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/Ref.hpp>
#include <yq-toolbox/basic/UniqueID.hpp>
#include <yq-toolbox/color/RGBA.hpp>
#include <yq-vulqan/data/DataFormat.hpp>
#include <yq-vulqan/image/ComponentSwizzle.hpp>
#include <yq-vulqan/image/ImageAspect.hpp>
#include <yq-vulqan/image/ImageViewCreateFlags.hpp>
#include <yq-vulqan/image/ImageViewType.hpp>
#include <yq-vulqan/sampler/SamplerInfo.hpp>
#include <yq-vulqan/typedef/image.hpp>
#include <yq-vulqan/typedef/sampler.hpp>
#include <yq-vulqan/typedef/texture.hpp>
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
        const ImageCPtr             image;
        
        //! View information
        const TextureInfo           info;

        //! Sampler info
        const SamplerCPtr           sampler;

        static TextureCPtr  load(std::string_view);
        static TextureCPtr  load(std::string_view, const SamplerCPtr& _sampler);
        static TextureCPtr  load(std::string_view, const TextureInfo& texInfo);
        static TextureCPtr  load(std::string_view, const TextureInfo2& texInfo);
        static TextureCPtr  load(std::string_view, const TextureInfo& texInfo, const SamplerCPtr& _sampler);

        Texture(ImageCPtr);
        Texture(ImageCPtr, const SamplerCPtr& _sampler);
        Texture(ImageCPtr, const TextureInfo& texInfo);
        Texture(ImageCPtr, const TextureInfo2& texInfo);
        Texture(ImageCPtr, const TextureInfo& texInfo, const SamplerCPtr& _sampler);
        
    private:
        ~Texture();
    };
}

