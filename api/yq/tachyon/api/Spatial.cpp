////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Spatial.hpp"
#include "SpatialInfoWriter.hpp"

YQ_OBJECT_IMPLEMENT(yq::tachyon::Spatial)

namespace yq::tachyon {

    SpatialInfo::SpatialInfo(std::string_view zName, DelegateInfo& base, const std::source_location& sl) :
        DelegateInfo(zName, base, sl)
    {
    }

    SpatialInfo::~SpatialInfo()
    {
    }

    Spatial::Spatial()
    {
    }
        
    Spatial::~Spatial()
    {
    }

    void Spatial::init_info()
    {
        auto w = writer<Spatial>();
        w.description("Spatial Delegate");
    }
}
