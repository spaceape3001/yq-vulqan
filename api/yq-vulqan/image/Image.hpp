////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/asset/Asset.hpp>
#include <yq/core/Memory.hpp>
#include <yq-vulqan/image/ImageInfo.hpp>
#include <yq-vulqan/typedef/image.hpp>
#include <yq/raster/forward.hpp>

namespace yq::tachyon {
    class Buffer;

    /*! \brief Image (data)
    
        An image is *not* drawable, it's data/asset for the GPU or other 
        render/destination.  Its data may be copied into a pixmap for 
        manipulation.
    */
    class Image : public Asset {
        YQ_OBJECT_DECLARE(Image, Asset)
    public:
    
        //! Cache of images
        static TypedAssetFactory<Image>&    cache();
        
        //! Loads an image by key
        static const ImageCPtr              load(std::string_view);

        //! Loads an image by key
        static const ImageCPtr              load(std::string_view, const AssetLoadOptions&);
    
        //! Data for the image
        const Memory      memory;
        
        //! Information for the image
        const ImageInfo   info;
        
        //! Constructor (takes info & data)
        Image(const ImageInfo&, Memory&&);
        
        explicit Image(const raster::Pixmap&);
        Image(ref_t,  const raster::Pixmap&);
        Image(copy_t, const raster::Pixmap&);

        //! Returns the size of the memory data
        virtual size_t      data_size() const  override;

        //! Converts to a pixmap (NOTE, this *CAN* fail, check result)
        raster::PixmapSPtr  to_pixmap() const;

    private:
        ~Image();

        AssetFactory&       factory() const override;

        template <typename C>
        raster::PixmapSPtr  _pixmap1() const;
        template <typename C>
        raster::PixmapSPtr  _pixmap2() const;
        template <typename C>
        raster::PixmapSPtr  _pixmap3() const;

        raster::PixmapSPtr to_pixmap1() const;
        raster::PixmapSPtr to_pixmap2() const;
        raster::PixmapSPtr to_pixmap3() const;
    };
}
