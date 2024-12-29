////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Spatial³.hpp"
#include <yq/tachyon/api/Spatial³InfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Spatial³);

namespace yq::tachyon {
    Spatial³Info::Spatial³Info(std::string_view zName, SpatialInfo& base, const std::source_location& sl)
        : SpatialInfo(zName, base, sl)
    {
    }

    Spatial³Info::~Spatial³Info()
    {
    }
    

    ////////////////////////////////////////////////////////////////////////////

    Spatial³::Spatial³()
    {
    }
    
    Spatial³::~Spatial³()
    {
    }
    
    void Spatial³::init_info()
    {
        auto w = writer<Spatial³>();
        w.description("Spatial in ³ Dimensions");
    }
}
