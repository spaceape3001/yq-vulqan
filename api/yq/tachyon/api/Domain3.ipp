////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Domain3.hpp>
#include <yq/tachyon/api/Domain3Data.hpp>
#include <yq/tachyon/api/Domain3MetaWriter.hpp>
#include <yq/tachyon/api/3DWriter.hxx>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Domain³)
YQ_TYPE_IMPLEMENT(yq::tachyon::Domain³ID)

namespace yq::tachyon {

    Domain³Data::Domain³Data() = default;
    Domain³Data::~Domain³Data() = default;

    /////////////////////////////////////////////////////////////////////////////

    Domain³Meta::Domain³Meta(std::string_view name, DomainMeta& base, const std::source_location& sl) :
        DomainMeta(name, base, sl)
    {
        set(Type::Domain³);
    }

    Domain³Meta::~Domain³Meta()
    {
    }
    
    /////////////////////////////////////////////////////////////////////////////

    Domain³Snap::Domain³Snap() = default;
    Domain³Snap::~Domain³Snap() = default;

    /////////////////////////////////////////////////////////////////////////////

    Domain³::Domain³(const Param& p) : Domain(p)
    {
    }
    
    Domain³::~Domain³()
    {
    }

    void Domain³::finalize(Domain³Data& d) const
    {
        //③::finalize(d);
        Domain::finalize(d);
    }

    void Domain³::snap(Domain³Snap& sn) const
    {
        //③::snap(sn);
        Domain::snap(sn);
    }
    
    void Domain³::init_meta()
    {
        auto w = writer<Domain³>();
        //③::init_meta(w);
        w.description("Domain in 3D");
        w.alias("Domain3");

        auto wt = writer<Domain³ID>();
        wt.description("3D Domain Identifier");
        wt.set(Meta::Flag::ID);
        wt.alias("Domain3ID");
    }
}
