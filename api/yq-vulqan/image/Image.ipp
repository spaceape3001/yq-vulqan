////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Image.hpp"

#include <yq-vulqan/asset/AssetFactory.hpp>
#include <yq-vulqan/asset/AssetInfoWriter.hpp>

namespace yq::tachyon {
    TypedAssetFactory<Image>&  Image::cache()
    {
        static TypedAssetFactory<Image>   s_ret;
        return s_ret;
    }

    const Image*       Image::load(std::string_view pp)
    {
        return cache().load(pp);
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

