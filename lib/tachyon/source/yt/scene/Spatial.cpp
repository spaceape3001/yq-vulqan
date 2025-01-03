////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/scene/Spatial.hpp>
#include <yt/scene/SpatialData.hpp>
#include <yt/scene/SpatialBind.hpp>
#include <yt/scene/SpatialInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Spatial)

namespace yq::tachyon {

    SpatialBind::SpatialBind(const Spatial* v) : m_spatial(v ? v->id() : SpatialID{})
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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

    PostAdvice    Spatial::advise(const Post&pp) const
    {
        PostAdvice  pa  = Tachyon::advise(pp);
        if(!unspecified(pa))
            return pa;
        
        if(const SpatialBind* p = dynamic_cast<const SpatialBind*>(&pp)){
            if(p->spatial() != id())
                return REJECT;
        }
        return {};
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
