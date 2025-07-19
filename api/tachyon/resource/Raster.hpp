////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/resource/Resource.hpp>
#include <yq/core/Memory.hpp>
#include <yq/raster/forward.hpp>
#include <tachyon/resource/RasterInfo.hpp>
#include <tachyon/typedef/raster.hpp>

namespace yq::tachyon {
    class Buffer;

    /*! \brief Raster image (data)
    
        A raster image is *not* drawable, it's data/resource for the GPU or other 
        render/destination.  Its data may be copied into a pixmap for 
        manipulation.
    */
    //  [2024-10-13] CSA -- Renamed from "Image" to avoid conflicts in the Mithril library
    class Raster : public Resource {
        YQ_RESOURCE_DECLARE(Raster, Resource)
    public:
    
        // Need to transition these toward getters... I think....
    
        //! Data for the image
        const Memory        memory;
        
        //! Information for the image
        const RasterInfo    info;
        
        //! Constructor (takes info & data)
        Raster(const RasterInfo&, Memory&&);
        
        explicit Raster(const Pixmap&);
        Raster(ref_k,  const Pixmap&, DataFormat df={});
        Raster(copy_k, const Pixmap&, DataFormat df={});

        //! Returns the size of the memory data
        virtual size_t      data_size() const  override;

        //! Converts to a pixmap (NOTE, this *CAN* fail, check result)
        PixmapSPtr  to_pixmap() const;
        
        static void init_meta();
        

    private:
        ~Raster();

        static RasterInfo    info_for(const Pixmap&, DataFormat df={});

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
