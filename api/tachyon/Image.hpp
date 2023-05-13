////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Asset.hpp>
#include <tachyon/Memory.hpp>
#include <tachyon/ImageInfo.hpp>

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
    
        static TypedAssetFactory<Image>&    cache();
        static const Image*                 load(std::string_view);
    
        const Memory      memory;
        const ImageInfo   info;
    
        Image(const ImageInfo&, Memory&&);

        virtual size_t      data_size() const  override;

    private:
        ~Image();
    };
}
