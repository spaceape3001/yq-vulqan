////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Moment3.hpp"
#include "Moment3Data.hpp"
#include "Moment3MetaWriter.hpp"
#include <yq/meta/Init.hpp>

namespace yq::tachyon {
    struct Moment³Meta::Repo {
        std::vector<const Moment³Meta*> all;
    };
    
    Moment³Meta::Repo& Moment³Meta::repo()
    {
        static Repo* s_repo = new Repo;
        return *s_repo;
    }

    const std::vector<const Moment³Meta*>&    Moment³Meta::all()
    {
        return repo().all;
    }

    Moment³Meta::Moment³Meta(std::string_view name, MomentMeta& base, const std::source_location& sl) : 
        MomentMeta(name, base, sl)
    {
        set(Type::Moment³);
        repo().all.push_back(this);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Moment³Data::Moment³Data() = default;
    Moment³Data::~Moment³Data() = default;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Moment³Snap::Moment³Snap() = default;
    Moment³Snap::~Moment³Snap() = default;


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Moment³::Moment³(const Param& p) : Moment(p)
    {
    }

    Moment³::~Moment³()
    {
    }

    void Moment³::finalize(Moment³Data&d) const
    {
        Moment::finalize(d);
    }

    void Moment³::snap(Moment³Snap& sn) const
    {
        Moment::snap(sn);
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void Moment³::init_meta()
    {
        auto w   = writer<Moment³>();
        w.abstract();
        w.description("Moment³");

        auto wt = writer<Moment³ID>();
        wt.description("Moment³ Identifier");
        wt.set(Meta::Flag::ID);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Moment³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Moment³ID)
