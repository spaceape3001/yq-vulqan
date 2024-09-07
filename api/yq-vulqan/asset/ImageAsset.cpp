////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ImageAsset.hpp"

#include <yq-vulqan/asset/AssetFactory.hpp>
#include <yq-vulqan/asset/AssetInfoWriter.hpp>

namespace yq::tachyon {
    TypedAssetFactory<ImageAsset>&  ImageAsset::cache()
    {
        static TypedAssetFactory<ImageAsset>   s_ret;
        return s_ret;
    }

    const ImageAsset*       ImageAsset::load(std::string_view pp)
    {
        return cache().load(pp);
    }

    ////////////////////////////////////////////////////////////////////////////////

    ImageAsset::ImageAsset(const ImageInfo& ii, Memory&& mem) : Asset(), memory(std::move(mem)), info(ii)
    {
    }

    size_t      ImageAsset::data_size() const  
    {
        return memory.bytes();
    }

    ImageAsset::~ImageAsset()
    {
    }

    ////////////////////////////////////////////////////////////////////////////////
    
    static void    reg_image_asset()
    {
        auto ti = writer<ImageAsset>();
        ti.description("Image Asset");
    }

    YQ_INVOKE(reg_image_asset();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::ImageAsset)

