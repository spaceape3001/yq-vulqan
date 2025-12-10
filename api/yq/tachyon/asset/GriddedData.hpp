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
#if 0
    enum class GriddedDataAxisScale : public uint8_t {
        Linear
    };
    struct GriddedDataAxis {
        size_t                  size        = 0;        //!< Count of values along this axis
        size_t                  count       = 0;        //!< Count of "cells" 0...N should get all walls, 0...N-1 should get all interiors
        std::vector<double>     intervals;              //!< Fractional intervals within... when empty, it's post 
        GriddedDataAxisScale    scale       = GriddedDataAxisScale::Linear;
        double                  min         = 0.;       //!< Min value to the axis
        double                  max         = 0.;       //!< Max value to the axis
    };
#endif

    /*! \brief Gridded Data (data)

        Gridded data  *not* drawable, it's data/resource for the GPU or other 
        render/destination.  
        
        Note, long term will likely move to the toolbox
    */
    class GriddedData : public Resource {
        YQ_RESOURCE_DECLARE(GriddedData, Resource)
    public:
    
    
        // Need to transition these toward getters... I think....
    
        //! Data for the image
        const Memory            memory;
        
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
