////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Kinetic.hpp"
#include "KineticData.hpp"
#include "KineticMetaWriter.hpp"
#include <yq/tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    struct KineticMeta::Repo {
        std::vector<const KineticMeta*> all;
    };
    
    KineticMeta::Repo& KineticMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const KineticMeta*>&    KineticMeta::all()
    {
        return repo().all;
    }

    KineticMeta::KineticMeta(std::string_view name, ModelMeta& base, const std::source_location& sl) : 
        ModelMeta(name, base, sl)
    {
        set(Flag::KINETIC);
        set(Type::Kinetic);
        repo().all.push_back(this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    KineticData::KineticData() = default;
    KineticData::~KineticData() = default;

    void KineticData::init_meta()
    {
        auto w = writer<KineticData>();
        w.description("Kinetic Frame Data");
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    KineticSnap::KineticSnap() = default;
    KineticSnap::~KineticSnap() = default;

    void KineticSnap::init_meta()
    {
        auto w = writer<KineticSnap>();
        w.description("Kinetic Snapshot");
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Kinetic::Kinetic(const Param& p) : Model(p)
    {
    }

    Kinetic::~Kinetic()
    {
    }

    void Kinetic::finalize(KineticData& d) const
    {
        Tachyon::finalize(d);
    }

    void Kinetic::snap(KineticSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Kinetic::init_meta()
    {
        auto w   = writer<Kinetic>();
        w.abstract();
        w.description("A kinetic, motion");

        auto wt = writer<KineticID>();
        wt.description("Kinetic Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Kinetic>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Kinetic)
YQ_TYPE_IMPLEMENT(yq::tachyon::KineticID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::KineticData)
YQ_OBJECT_IMPLEMENT(yq::tachyon::KineticSnap)
