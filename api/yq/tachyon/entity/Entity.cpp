////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Entity.hpp"
#include "EntityData.hpp"
#include "EntityMetaWriter.hpp"
#include <yq/tachyon/api/Post.hpp>
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct EntityMeta::Repo {
        std::vector<const EntityMeta*> all;
    };
    
    EntityMeta::Repo& EntityMeta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const EntityMeta*>&    EntityMeta::all()
    {
        return repo().all;
    }

    EntityMeta::EntityMeta(std::string_view name, ModelMeta& base, const std::source_location& sl) : 
        ModelMeta(name, base, sl)
    {
        set(Type::Entity);
        repo().all.push_back(this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    EntityData::EntityData() = default;
    EntityData::~EntityData() = default;
    
    void EntityData::init_meta()
    {
        auto w = writer<EntityData>();
        w.description("Entity Frame Data");
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    EntitySnap::EntitySnap() = default;
    EntitySnap::~EntitySnap() = default;
    
    void EntitySnap::init_meta()
    {
        auto w = writer<EntitySnap>();
        w.description("Entity Snapshot");
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Entity::Entity(const Param& p) : Model(p)
    {
    }

    Entity::~Entity()
    {
    }


    void Entity::snap(EntitySnap& sn) const
    {
        Model::snap(sn);
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Entity::init_meta()
    {
        auto w   = writer<Entity>();
        w.abstract();
        w.description("Entity base");

        auto wt = writer<EntityID>();
        wt.description("Entity Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Entity>);
        wt.casts<TachyonID>();
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Entity)
YQ_TYPE_IMPLEMENT(yq::tachyon::EntityID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::EntityData)
YQ_OBJECT_IMPLEMENT(yq::tachyon::EntitySnap)
