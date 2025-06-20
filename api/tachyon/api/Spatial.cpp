////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Spatial.hpp"

#include <tachyon/tags.hpp>
#include <tachyon/api/SpatialData.hpp>
#include <tachyon/api/SpatialInfoWriter.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Spatial)
YQ_TYPE_IMPLEMENT(yq::tachyon::SpatialID)

namespace yq::tachyon {
    struct SpatialInfo::Repo {
        std::vector<const SpatialInfo*> all;
    };
    
    SpatialInfo::Repo& SpatialInfo::repo()
    {
        static Repo s_repo;
        return s_repo;
    }

    const std::vector<const SpatialInfo*>&    SpatialInfo::all()
    {
        return repo().all;
    }


    SpatialInfo::SpatialInfo(std::string_view zName, TachyonInfo& base, const std::source_location& sl) :
        TachyonInfo(zName, base, sl)
    {
        set(Type::Spatial);
        repo().all.push_back(this);
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

    void Spatial::set_domain(TypedID m)
    {
        m_domain    = m;
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
        w.abstract();
        w.property("domain", &Spatial::m_domain).tag({kTag_TachyonID, kTag_Save});

        auto wt = writer<SpatialID>();
        wt.description("Spatial Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Spatial>);
        wt.casts<TachyonID>();
    }
}
