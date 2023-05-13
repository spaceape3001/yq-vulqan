////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/gfx/Image.hpp>
#include <tachyon/core/AssetFactory.hpp>
#include <tachyon/core/AssetInfoWriter.hpp>
#include <tachyon/Buffer.hpp>

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

    Image::Image(const ImageInfo& ii, Memory&& mem) : info(ii), memory(std::move(mem))
    {
    }

    size_t      Image::data_size() const  
    {
        return memory.bytes();
    }

    Image::~Image()
    {
    }

    ////////////////////////////////////////////////////////////////////////////////
    
    namespace {
        void    reg_texture()
        {
            auto ti = writer<Image>();
            ti.description("Image Asset");
        }

        YQ_INVOKE(reg_texture();)
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Image)

