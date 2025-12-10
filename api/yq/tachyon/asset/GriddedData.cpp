////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


#include <yq/typedef/float16.hpp>

#include <yq/resource/ResourceMetaWriter.hpp>
#include <yq/resource/ResourceIO.hpp>

#include <yq/tachyon/asset/GriddedData.hpp>

namespace yq::tachyon {

    GriddedData::GriddedData(const GriddedDataInfo& ii, Memory&& mem) : Resource(), memory(std::move(mem)), info(ii)
    {
    }

    size_t      GriddedData::data_size() const  
    {
        return memory.bytes();
    }

    GriddedData::~GriddedData()
    {
    }

    ////////////////////////////////////////////////////////////////////////////////
    
    void    GriddedData::init_meta()
    {
        auto w = writer<GriddedData>();
        w.description("GriddedData Image Resource");
        w.options({Meta::Flag::IMAGE, Meta::Flag::RASTER});
    }
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::GriddedData)

