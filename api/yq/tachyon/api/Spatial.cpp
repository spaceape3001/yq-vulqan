////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Spatial.hpp"

#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/SpatialData.hpp>
#include <yq/tachyon/api/SpatialMetaWriter.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Spatial)
YQ_TYPE_IMPLEMENT(yq::tachyon::SpatialID)

namespace yq::tachyon {
    struct SpatialMeta::Repo {
        std::vector<const SpatialMeta*> all;
    };
    
    SpatialMeta::Repo& SpatialMeta::repo()
    {
        static Repo s_repo;
        return s_repo;
    }

    const std::vector<const SpatialMeta*>&    SpatialMeta::all()
    {
        return repo().all;
    }


    SpatialMeta::SpatialMeta(std::string_view zName, TachyonMeta& base, const std::source_location& sl) :
        TachyonMeta(zName, base, sl)
    {
        set(Type::Spatial);
        repo().all.push_back(this);
    }

    SpatialMeta::~SpatialMeta()
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

    void Spatial::init_meta()
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
