////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Physics.hpp>
#include <yq/tachyon/api/PhysicsData.hpp>
#include <yq/tachyon/api/PhysicsMetaWriter.hpp>
#include <yq/tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {

    struct PhysicsMeta::Repo {
        std::vector<const PhysicsMeta*> all;
    };
    
    PhysicsMeta::Repo& PhysicsMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const PhysicsMeta*>&    PhysicsMeta::all()
    {
        return repo().all;
    }

    PhysicsMeta::PhysicsMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) : 
        TachyonMeta(name, base, sl)
    {
        set(Flag::PHYSICS);
        set(Type::Physics);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Physics::Physics(const Param& p) : Tachyon(p)
    {
    }

    Physics::~Physics()
    {
    }

    void Physics::finalize(PhysicsData& d) const
    {
        Tachyon::finalize(d);
    }

    void Physics::snap(PhysicsSnap& sn) const
    {
        Tachyon::snap(sn);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Physics::init_meta()
    {
        auto w   = writer<Physics>();
        w.abstract();
        w.description("Physics");

        auto wt = writer<PhysicsID>();
        wt.description("Physics Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Physics>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Physics)
YQ_TYPE_IMPLEMENT(yq::tachyon::PhysicsID)
