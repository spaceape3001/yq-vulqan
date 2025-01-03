////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/3D/Spatial3.hpp>
#include <yt/3D/Spatial3Bind.hpp>
#include <yt/3D/Spatial3Data.hpp>
#include <yt/3D/Spatial3InfoWriter.hpp>

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

    Spatial³::Spatial³(const Param& p) : Spatial(p)
    {
    }
    
    Spatial³::~Spatial³()
    {
    }

    void        Spatial³::snap(Spatial³Snap& sn) const
    {
        Spatial::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////

    void Spatial³::init_info()
    {
        auto w = writer<Spatial³>();
        w.description("Spatial in 3 Dimensions");
    }
}
