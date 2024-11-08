////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/asset/Asset.hpp>
#include <yq/core/Memory.hpp>
#include <yq/tachyon/image/RasterInfo.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <yq/raster/forward.hpp>

namespace yq::tachyon {
    class Buffer;

    /*! \brief Raster image (data)
    
        A raster image is *not* drawable, it's data/asset for the GPU or other 
        render/destination.  Its data may be copied into a pixmap for 
        manipulation.
    */
    //  [2024-10-13] CSA -- Renamed from "Image" to avoid conflicts in the Mithril library
    class Raster : public Asset {
        YQ_OBJECT_DECLARE(Raster, Asset)
    public:
    
        //! Cache of images
        static TypedAssetFactory<Raster>&    cache();
        
        //! Loads an image by key
        static const RasterCPtr              load(std::string_view);

        //! Loads an image by key
        static const RasterCPtr              load(std::string_view, const AssetLoadOptions&);
    
        //! Data for the image
        const Memory      memory;
        
        //! Information for the image
        const RasterInfo   info;
        
        //! Constructor (takes info & data)
        Raster(const RasterInfo&, Memory&&);
        
        explicit Raster(const Pixmap&);
        Raster(ref_t,  const Pixmap&, DataFormat df={});
        Raster(copy_t, const Pixmap&, DataFormat df={});

        //! Returns the size of the memory data
        virtual size_t      data_size() const  override;

        //! Converts to a pixmap (NOTE, this *CAN* fail, check result)
        PixmapSPtr  to_pixmap() const;
        
        static void init_info();
        

    private:
        ~Raster();

        static RasterInfo    info_for(const Pixmap&, DataFormat df={});

        AssetFactory&       factory() const override;

        template <typename C>
        PixmapSPtr  _pixmap1() const;
        template <typename C>
        PixmapSPtr  _pixmap2() const;
        template <typename C>
        PixmapSPtr  _pixmap3() const;

        PixmapSPtr to_pixmap1() const;
        PixmapSPtr to_pixmap2() const;
        PixmapSPtr to_pixmap3() const;
    };
}
