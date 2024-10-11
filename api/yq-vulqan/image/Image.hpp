////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Memory.hpp>
#include <yq-vulqan/asset/Asset.hpp>
#include <yq-vulqan/image/ImageInfo.hpp>
#include <yq-vulqan/typedef/image.hpp>
#include <yq/pixel/pixels_fwd.hpp>

namespace yq::tachyon {
    class Buffer;
    template <typename> class TypedAssetFactory;
    struct AssetLoadOptions;

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
        
        explicit Image(const pixel::Pixmap&);
        Image(ref_t,  const pixel::Pixmap&);
        Image(copy_t, const pixel::Pixmap&);

        //! Returns the size of the memory data
        virtual size_t      data_size() const  override;

        //! Converts to a pixmap (NOTE, this *CAN* fail, check result)
        pixel::PixmapSPtr  to_pixmap() const;

    private:
        ~Image();

        AssetFactory&       factory() const override;

        template <typename C>
        pixel::PixmapSPtr   _pixmap1() const;
        template <typename C>
        pixel::PixmapSPtr   _pixmap2() const;
        template <typename C>
        pixel::PixmapSPtr   _pixmap3() const;

        pixel::PixmapSPtr  to_pixmap1() const;
        pixel::PixmapSPtr  to_pixmap2() const;
        pixel::PixmapSPtr  to_pixmap3() const;
    };
}
