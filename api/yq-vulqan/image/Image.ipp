////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Image.hpp"

#include <yq-vulqan/asset/AssetFactory.hpp>
#include <yq-vulqan/asset/AssetInfoWriter.hpp>
#include <yq-vulqan/asset/AssetIO.hpp>

namespace yq::tachyon {
    TypedAssetFactory<Image>&  Image::cache()
    {
        static TypedAssetFactory<Image>   s_ret;
        return s_ret;
    }

    const ImageCPtr     Image::load(std::string_view pp)
    {
        return load(pp, AssetLoadOptions());
    }

    const ImageCPtr     Image::load(std::string_view pp, const AssetLoadOptions& options)
    {
        return cache().load(pp, options);
    }

    ////////////////////////////////////////////////////////////////////////////////

    Image::Image(const ImageInfo& ii, Memory&& mem) : Asset(), memory(std::move(mem)), info(ii)
    {
    }

    size_t      Image::data_size() const  
    {
        return memory.bytes();
    }

    Image::~Image()
    {
    }

    AssetFactory&       Image::factory() const 
    {
        return cache();
    }

    ////////////////////////////////////////////////////////////////////////////////
    
    static void    reg_image()
    {
        auto w = writer<Image>();
        w.description("Image Asset");
        w.options({Meta::Flag::IMAGE});
    }

    YQ_INVOKE(reg_image();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Image)

