////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Image.hpp"

#include <yq/pixel/Pixels.hxx>

#include <yq/color/RGB.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/typedef/float16.hpp>

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

    pixel::PixmapSPtr  Image::to_pixmap() const
    {
        switch(info.type){
        case ImageType::D1:
            return to_pixmap1();
        case ImageType::D2:
            return to_pixmap2();
        case ImageType::D3:
            return to_pixmap3();
        default:
            return {};
        }
    }

    template <typename C>
    pixel::PixmapSPtr  Image:: _pixmap1() const
    {
        return std::make_shared<pixel::Pixels1<C>>(
            Coord1U(info.size.x), 
            COPY, (const C*) memory.data()
        );
    }
    
    pixel::PixmapSPtr  Image::to_pixmap1() const
    {
        switch(info.format){
        case DataFormat::A8_UNORM:
        case DataFormat::R8_SRGB:
        case DataFormat::R8_UINT:
        case DataFormat::R8_USCALED:
        case DataFormat::R8_UNORM:
            return _pixmap1<uint8_t>();
        case DataFormat::R8_SINT:
        case DataFormat::R8_SSCALED:
        case DataFormat::R8_SNORM:
            return _pixmap1<int8_t>();
        case DataFormat::R16_UINT:
        case DataFormat::R16_UNORM:
        case DataFormat::R16_USCALED:
            return _pixmap1<uint16_t>();
        //case DataFormat::R16_SFLOAT:
        //    return _pixmap1<float16_t>();
        case DataFormat::R32_UINT:
            return _pixmap1<uint32_t>();
        case DataFormat::R32_SINT:
            return _pixmap1<int32_t>();
        case DataFormat::R32_SFLOAT:
            return _pixmap1<float>();
        case DataFormat::R64_UINT:
            return _pixmap1<uint64_t>();
        case DataFormat::R64_SINT:
            return _pixmap1<int64_t>();
        case DataFormat::R64_SFLOAT:
            return _pixmap1<double>();
        case DataFormat::R8G8B8_UINT:
        case DataFormat::R8G8B8_SRGB:
            return _pixmap1<RGB3U8>();
        case DataFormat::R16G16B16_UINT:
            return _pixmap1<RGB3U16>();
        case DataFormat::R32G32B32_SFLOAT:
            return _pixmap1<RGB3F>();
        case DataFormat::R64G64B64_SFLOAT:
            return _pixmap1<RGB3D>();
        case DataFormat::R8G8B8A8_UINT:
        case DataFormat::R8G8B8A8_SRGB:
            return _pixmap1<RGBA4U8>();
        case DataFormat::R16G16B16A16_UINT:
            return _pixmap1<RGBA4U16>();
        case DataFormat::R32G32B32A32_SFLOAT:
            return _pixmap1<RGBA4F>();
        case DataFormat::R64G64B64A64_SFLOAT:
            return _pixmap1<RGBA4D>();
        default:
            return {};
        }
    }

    template <typename C>
    pixel::PixmapSPtr  Image::_pixmap2() const
    {
        return std::make_shared<pixel::Pixels2<C>>(
            Coord2U( info.size.x, info.size.y ), 
            COPY, (const C*) memory.data()
        );
    }
    
    pixel::PixmapSPtr  Image::to_pixmap2() const
    {
        switch(info.format){
        case DataFormat::A8_UNORM:
        case DataFormat::R8_SRGB:
        case DataFormat::R8_UINT:
        case DataFormat::R8_USCALED:
        case DataFormat::R8_UNORM:
            return _pixmap2<uint8_t>();
        case DataFormat::R8_SINT:
        case DataFormat::R8_SSCALED:
        case DataFormat::R8_SNORM:
            return _pixmap2<int8_t>();
        case DataFormat::R16_UINT:
        case DataFormat::R16_UNORM:
        case DataFormat::R16_USCALED:
            return _pixmap2<uint16_t>();
        //case DataFormat::R16_SFLOAT:
        //    return _pixmap2<float16_t>();
        case DataFormat::R32_UINT:
            return _pixmap2<uint32_t>();
        case DataFormat::R32_SINT:
            return _pixmap2<int32_t>();
        case DataFormat::R32_SFLOAT:
            return _pixmap2<float>();
        case DataFormat::R64_UINT:
            return _pixmap2<uint64_t>();
        case DataFormat::R64_SINT:
            return _pixmap2<int64_t>();
        case DataFormat::R64_SFLOAT:
            return _pixmap2<double>();
        case DataFormat::R8G8B8_UINT:
        case DataFormat::R8G8B8_SRGB:
            return _pixmap2<RGB3U8>();
        case DataFormat::R16G16B16_UINT:
            return _pixmap2<RGB3U16>();
        case DataFormat::R32G32B32_SFLOAT:
            return _pixmap2<RGB3F>();
        case DataFormat::R64G64B64_SFLOAT:
            return _pixmap2<RGB3D>();
        case DataFormat::R8G8B8A8_UINT:
        case DataFormat::R8G8B8A8_SRGB:
            return _pixmap2<RGBA4U8>();
        case DataFormat::R16G16B16A16_UINT:
            return _pixmap2<RGBA4U16>();
        case DataFormat::R32G32B32A32_SFLOAT:
            return _pixmap2<RGBA4F>();
        case DataFormat::R64G64B64A64_SFLOAT:
            return _pixmap2<RGBA4D>();
        default:
            return {};
        }
    }

    template <typename C>
    pixel::PixmapSPtr   Image::_pixmap3() const
    {
        return std::make_shared<pixel::Pixels3<C>>(
            Coord3U( info.size.x, info.size.y, info.size.z ), 
            COPY, (const C*) memory.data()
        );
    }
    
    pixel::PixmapSPtr  Image::to_pixmap3() const
    {
        using pixel::Pixels;
        switch(info.format){
        case DataFormat::A8_UNORM:
        case DataFormat::R8_SRGB:
        case DataFormat::R8_UINT:
        case DataFormat::R8_USCALED:
        case DataFormat::R8_UNORM:
            return _pixmap3<uint8_t>();
        case DataFormat::R8_SINT:
        case DataFormat::R8_SSCALED:
        case DataFormat::R8_SNORM:
            return _pixmap3<int8_t>();
        case DataFormat::R16_UINT:
        case DataFormat::R16_UNORM:
        case DataFormat::R16_USCALED:
            return _pixmap3<uint16_t>();
        //case DataFormat::R16_SFLOAT:
        //    return _pixmap3<float16_t>();
        case DataFormat::R32_UINT:
            return _pixmap3<uint32_t>();
        case DataFormat::R32_SINT:
            return _pixmap3<int32_t>();
        case DataFormat::R32_SFLOAT:
            return _pixmap3<float>();
        case DataFormat::R64_UINT:
            return _pixmap3<uint64_t>();
        case DataFormat::R64_SINT:
            return _pixmap3<int64_t>();
        case DataFormat::R64_SFLOAT:
            return _pixmap3<double>();
        case DataFormat::R8G8B8_UINT:
        case DataFormat::R8G8B8_SRGB:
            return _pixmap3<RGB3U8>();
        case DataFormat::R16G16B16_UINT:
            return _pixmap3<RGB3U16>();
        case DataFormat::R32G32B32_SFLOAT:
            return _pixmap3<RGB3F>();
        case DataFormat::R64G64B64_SFLOAT:
            return _pixmap3<RGB3D>();
        case DataFormat::R8G8B8A8_UINT:
        case DataFormat::R8G8B8A8_SRGB:
            return _pixmap3<RGBA4U8>();
        case DataFormat::R16G16B16A16_UINT:
            return _pixmap3<RGBA4U16>();
        case DataFormat::R32G32B32A32_SFLOAT:
            return _pixmap3<RGBA4F>();
        case DataFormat::R64G64B64A64_SFLOAT:
            return _pixmap3<RGBA4D>();
        default:
            return {};
        }
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

