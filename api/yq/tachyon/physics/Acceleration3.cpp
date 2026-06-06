////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Acceleration3.hpp"
#include "Acceleration3Data.hpp"
#include "Acceleration3MetaWriter.hpp"
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct Acceleration³Meta::Repo {
        std::vector<const Acceleration³Meta*> all;
    };
    
    Acceleration³Meta::Repo& Acceleration³Meta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const Acceleration³Meta*>&    Acceleration³Meta::all()
    {
        return repo().all;
    }

    Acceleration³Meta::Acceleration³Meta(std::string_view name, PhysicsMeta& base, const std::source_location& sl) : 
        PhysicsMeta(name, base, sl)
    {
        set(Type::Acceleration³);
        repo().all.push_back(this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Acceleration³Data::Acceleration³Data() = default;
    Acceleration³Data::~Acceleration³Data() = default;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Acceleration³Snap::Acceleration³Snap() = default;
    Acceleration³Snap::~Acceleration³Snap() = default;


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Acceleration³::Acceleration³(const Param& p) : Physics(p)
    {
    }

    Acceleration³::~Acceleration³()
    {
    }

    void Acceleration³::finalize(Acceleration³Data&d) const
    {
        Physics::finalize(d);
    }

    void Acceleration³::snap(Acceleration³Snap& sn) const
    {
        Physics::snap(sn);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Acceleration³::init_meta()
    {
        auto w   = writer<Acceleration³>();
        w.abstract();
        w.description("Acceleration³");

        auto wt = writer<Acceleration³ID>();
        wt.description("Acceleration³ Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Acceleration³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Acceleration³ID)
