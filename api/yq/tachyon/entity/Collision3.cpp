////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Collision3.hpp"
#include "Collision3Data.hpp"
#include "Collision3MetaWriter.hpp"
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct Collision³Meta::Repo {
        std::vector<const Collision³Meta*> all;
    };
    
    Collision³Meta::Repo& Collision³Meta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const Collision³Meta*>&    Collision³Meta::all()
    {
        return repo().all;
    }

    Collision³Meta::Collision³Meta(std::string_view name, CollisionMeta& base, const std::source_location& sl) : 
        CollisionMeta(name, base, sl)
    {
        set(Type::Collision³);
        repo().all.push_back(this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Collision³Data::Collision³Data() = default;
    Collision³Data::~Collision³Data() = default;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Collision³Snap::Collision³Snap() = default;
    Collision³Snap::~Collision³Snap() = default;


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Collision³::Collision³(const Param& p) : Collision(p)
    {
    }

    Collision³::~Collision³()
    {
    }

    void Collision³::finalize(Collision³Data&d) const
    {
        Collision::finalize(d);
    }

    void Collision³::snap(Collision³Snap& sn) const
    {
        Collision::snap(sn);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Collision³::init_meta()
    {
        auto w   = writer<Collision³>();
        w.abstract();
        w.description("Collision³");

        auto wt = writer<Collision³ID>();
        wt.description("Collision³ Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Collision³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Collision³ID)
