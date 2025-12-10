////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/resource/Resource.hpp>
#include <yq/core/Memory.hpp>
#include <yq/raster/forward.hpp>
#include <yq/tachyon/asset/GriddedDataInfo.hpp>
#include <yq/tachyon/typedef/raster.hpp>

namespace yq::tachyon {
    /*! \brief Gridded Data (data)

        Gridded data  *not* drawable, it's data/resource for the GPU or other 
        render/destination.  
    */
    class GriddedData : public Resource {
        YQ_RESOURCE_DECLARE(GriddedData, Resource)
    public:
    
        // Need to transition these toward getters... I think....
    
        //! Data for the image
        const Memory        memory;
        
        //! Information for the image
        const GriddedDataInfo    info;
        
        //! Constructor (takes info & data)
        GriddedData(const GriddedDataInfo&, Memory&&);

        //  We'll likely handle double/vector2/3/4 arrays... TBD

        //! Returns the size of the memory data
        virtual size_t      data_size() const  override;

        static void init_meta();
        

    private:
        ~GriddedData();
    };
}
