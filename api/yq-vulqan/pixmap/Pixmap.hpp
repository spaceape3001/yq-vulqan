////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/typedef/image.hpp>
#include <yq-vulqan/typedef/pixmap.hpp>
#include <yq-vulqan/asset/Asset.hpp>

namespace yq::tachyon {
    class PixmapInfo : public AssetInfo {
    public:
    
    
    private:
        const TypeInfo*     m_dataType          = nullptr;
        const TypeInfo*     m_indexType         = nullptr;
        uint8_t             m_dimensionCount    = 0;
    };

    struct ImageConfig {
    };

    /*! \brief A drawing surface
    
        Unlike an image, the pixmap is meant to be manipulated.
    */
    class Pixmap : public Asset {
        YQ_OBJECT_INFO(PixmapInfo)
        YQ_OBJECT_DECLARE(Pixmap, Asset)
    public:
    
        //Any     get_pixel(
        
        virtual ImageCPtr   to_image(const ImageConfig& config={}) const = 0;
    };
}

