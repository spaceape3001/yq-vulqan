////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Force3.hpp"
#include "Force3Data.hpp"
#include "Force3MetaWriter.hpp"
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct Force³Meta::Repo {
        std::vector<const Force³Meta*> all;
    };
    
    Force³Meta::Repo& Force³Meta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const Force³Meta*>&    Force³Meta::all()
    {
        return repo().all;
    }

    Force³Meta::Force³Meta(std::string_view name, PhysicsMeta& base, const std::source_location& sl) : 
        PhysicsMeta(name, base, sl)
    {
        set(Type::Force³);
        repo().all.push_back(this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Force³Data::Force³Data() = default;
    Force³Data::~Force³Data() = default;

    void Force³Data::init_meta()
    {
        auto w = writer<Force³Data>();
        w.description("Force³ Frame Data");
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Force³Snap::Force³Snap() = default;
    Force³Snap::~Force³Snap() = default;

    void Force³Snap::init_meta()
    {
        auto w = writer<Force³Snap>();
        w.description("Force³ Snapshot");
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Force³::Force³(const Param& p) : Physics(p)
    {
    }

    Force³::~Force³()
    {
    }

    void Force³::finalize(Force³Data&d) const
    {
        Physics::finalize(d);
    }

    void Force³::snap(Force³Snap& sn) const
    {
        Physics::snap(sn);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Force³::init_meta()
    {
        auto w   = writer<Force³>();
        w.abstract();
        w.description("Force³");

        auto wt = writer<Force³ID>();
        wt.description("Force³ Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Force³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Force³ID)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Force³Data)
YQ_OBJECT_IMPLEMENT(yq::tachyon::Force³Snap)
