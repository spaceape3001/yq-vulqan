////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/sim/Spatial.hpp>
#include <yt/sim/SpatialData.hpp>
#include <yt/sim/SpatialInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Spatial)

namespace yq::tachyon {
    SpatialInfo::SpatialInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
    }

    SpatialInfo::~SpatialInfo()
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Spatial::Spatial(const Param& p) : Tachyon(p), m_domain(p.domain)
    {
    }
        
    Spatial::~Spatial()
    {
    }

    void Spatial::snap(SpatialSnap&sn) const
    {
        Tachyon::snap(sn);
        sn.domain       = m_domain;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void Spatial::init_info()
    {
        auto w = writer<Spatial>();
        w.description("Spatial Delegate");
    }
}
