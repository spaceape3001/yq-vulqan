////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Asset.hpp>
#include <tachyon/core/Memory.hpp>
#include <tachyon/gfx/ImageInfo.hpp>

namespace yq::tachyon {
    class Buffer;

    /*! \brief Texture is an image destined for the GPU
    
        A texture is *not* drawable, it's data/asset for the GPU or other 
        render/destination.  Its data may be copied into a pixmap for 
        manipulation.
    */
    class Texture : public Asset {
        YQ_OBJECT_DECLARE(Texture, Asset)
    public:
    
        static TypedAssetFactory<Texture>&  cache();
        static const Texture*       load(std::string_view);
    
        const ImageInfo&    info() const { return m_info; }
        const Memory&       memory() const { return m_memory; }
   
        Texture();
        Texture(const ImageInfo&, Memory&&);

        virtual size_t              data_size() const  override;

    private:
        ~Texture();

        ImageInfo   m_info;
        Memory      m_memory;
    };
}
