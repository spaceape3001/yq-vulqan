////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Spatial3.hpp"
#include <yq/tachyon/api/Spatial3InfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Spatial3);

namespace yq::tachyon {
    Spatial3Info::Spatial3Info(std::string_view zName, SpatialInfo& base, const std::source_location& sl)
        : SpatialInfo(zName, base, sl)
    {
    }

    Spatial3Info::~Spatial3Info()
    {
    }
    

    ////////////////////////////////////////////////////////////////////////////

    Spatial3::Spatial3(const Param& p) : Spatial(p)
    {
    }
    
    Spatial3::~Spatial3()
    {
    }

    void        Spatial3::snap(Spatial3Snap& sn) const
    {
        Spatial::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////

    void Spatial3::init_info()
    {
        auto w = writer<Spatial3>();
        w.description("Spatial in 3 Dimensions");
    }
}
