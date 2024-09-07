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

namespace yq::tachyon {
    class Buffer;
    template <typename> class TypedAssetFactory;

    /*! \brief Image (data)
    
        An image is *not* drawable, it's data/asset for the GPU or other 
        render/destination.  Its data may be copied into a pixmap for 
        manipulation.
    */
    class ImageAsset : public Asset {
        YQ_OBJECT_DECLARE(ImageAsset, Asset)
    public:
    
        //! Cache of images
        static TypedAssetFactory<ImageAsset>&    cache();
        
        //! Loads an image by key
        static const ImageAsset*                 load(std::string_view);
    
        //! Data for the image
        const Memory      memory;
        
        //! Information for the image
        const ImageInfo   info;
        
        //! Constructor (takes info & data)
        ImageAsset(const ImageInfo&, Memory&&);

        //! Returns the size of the memory data
        virtual size_t      data_size() const  override;

    private:
        ~ImageAsset();
    };
}
