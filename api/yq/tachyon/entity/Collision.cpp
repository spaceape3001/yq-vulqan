////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Collision.hpp"
#include "CollisionData.hpp"
#include "CollisionMetaWriter.hpp"
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct CollisionMeta::Repo {
        std::vector<const CollisionMeta*> all;
    };
    
    CollisionMeta::Repo& CollisionMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const CollisionMeta*>&    CollisionMeta::all()
    {
        return repo().all;
    }

    CollisionMeta::CollisionMeta(std::string_view name, ModelMeta& base, const std::source_location& sl) : 
        ModelMeta(name, base, sl)
    {
        set(Type::Collision);
        repo().all.push_back(this);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Collision::Collision(const Param& p) : Model(p)
    {
    }

    Collision::~Collision()
    {
    }


    void Collision::snap(CollisionSnap& sn) const
    {
        Model::snap(sn);
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Collision::init_meta()
    {
        auto w   = writer<Collision>();
        w.abstract();
        w.description("Collision base");

        auto wt = writer<CollisionID>();
        wt.description("Collision Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Collision>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Collision)
YQ_TYPE_IMPLEMENT(yq::tachyon::CollisionID)
