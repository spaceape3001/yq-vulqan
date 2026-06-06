////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Entity3.hpp"
#include "Entity3Data.hpp"
#include "Entity3MetaWriter.hpp"
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct Entity³Meta::Repo {
        std::vector<const Entity³Meta*> all;
    };
    
    Entity³Meta::Repo& Entity³Meta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const Entity³Meta*>&    Entity³Meta::all()
    {
        return repo().all;
    }

    Entity³Meta::Entity³Meta(std::string_view name, EntityMeta& base, const std::source_location& sl) : 
        EntityMeta(name, base, sl)
    {
        set(Type::Entity³);
        repo().all.push_back(this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Entity³Data::Entity³Data() = default;
    Entity³Data::~Entity³Data() = default;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Entity³Snap::Entity³Snap() = default;
    Entity³Snap::~Entity³Snap() = default;


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Entity³::Entity³(const Param& p) : Entity(p)
    {
    }

    Entity³::~Entity³()
    {
    }

    void Entity³::finalize(Entity³Data&d) const
    {
        Entity::finalize(d);
    }

    void Entity³::snap(Entity³Snap& sn) const
    {
        Entity::snap(sn);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Entity³::init_meta()
    {
        auto w   = writer<Entity³>();
        w.abstract();
        w.description("Entity³");

        auto wt = writer<Entity³ID>();
        wt.description("Entity³ Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Entity³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Entity³ID)
