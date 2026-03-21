////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Kinetic.hpp>
#include <yq/tachyon/api/KineticData.hpp>
#include <yq/tachyon/api/KineticMetaWriter.hpp>
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

    KineticMeta::KineticMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
    {
        set(Flag::KINETIC);
        set(Type::Kinetic);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Kinetic::Kinetic(const Param& p) : Tachyon(p)
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
