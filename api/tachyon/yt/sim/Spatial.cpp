////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/sim/Spatial.hpp>
#include <yt/sim/SpatialData.hpp>
#include <yt/sim/SpatialInfoWriter.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Spatial)
YQ_TYPE_IMPLEMENT(yq::tachyon::SpatialID)

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

        auto wt = writer<SpatialID>();
        wt.description("Spatial Identifier");
        wt.set(Meta::Flag::ID);
    }
}
