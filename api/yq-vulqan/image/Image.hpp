////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/asset/Asset.hpp>
#include <yq-vulqan/image/ImageInfo.hpp>
#include <yq-vulqan/memory/Memory.hpp>
#include <yq-vulqan/typedef/image.hpp>
#include <yq-vulqan/typedef/pixmap.hpp>

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

        //! Returns the size of the memory data
        virtual size_t      data_size() const  override;
        
        PixmapUPtr          to_pixmap() const;

    private:
        ~Image();

        AssetFactory&       factory() const override;
    };
}
