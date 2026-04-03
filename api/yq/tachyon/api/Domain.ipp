////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/Domain.hpp>
#include <yq/tachyon/api/DomainData.hpp>
#include <yq/tachyon/api/DomainMetaWriter.hpp>
#include <yq/meta/Init.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::Domain);
YQ_TYPE_IMPLEMENT(yq::tachyon::DomainID)

namespace yq::tachyon {

    struct DomainMeta::Repo {
        std::vector<const DomainMeta*> all;
    };
    
    DomainMeta::Repo& DomainMeta::repo()
    {
        static Repo s_repo;
        return s_repo;
    }

    const std::vector<const DomainMeta*>&    DomainMeta::all()
    {
        return repo().all;
    }

    DomainMeta::DomainMeta(std::string_view name, TachyonMeta& base, const std::source_location& sl) :
        TachyonMeta(name, base, sl)
    {
        set(Type::Domain);
        repo().all.push_back(this);
    }
    
    DomainMeta::~DomainMeta()
    {
    }
    

    Domain::Domain(const Param&p) : Tachyon(p)
    {
    }
    
    Domain::~Domain()
    {
    }

    void Domain::snap(DomainSnap&sn) const
    {
        Tachyon::snap(sn);
    }
    
    void Domain::finalize(DomainData&data) const
    {
        Tachyon::finalize(data);
    }

    void Domain::init_meta()
    {
        auto w = writer<Domain>();
        w.description("Domain");

        auto wt = writer<DomainID>();
        wt.description("Domain Identifier");
        wt.set(Meta::Flag::ID);
        wt.constructor(construct_id<Domain>);
        wt.casts<TachyonID>();
    }

}


