////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/dim/3D.hpp>
#include <yq/physicsvk/api/Domain.hpp>
#include <yq/tachyon/typedef/domain3.hpp>

namespace yq::tachyon {
    class Domain³Meta : public DomainMeta {
    public:
    
        template <typename> class Writer;
        
        Domain³Meta(std::string_view, DomainMeta&, const std::source_location& sl = std::source_location::current());
    protected:
        ~Domain³Meta();
    };
    
    class Domain³ : public Domain /* , public ③  */ {
        YQ_TACHYON_META(Domain³Meta)
        YQ_TACHYON_SNAP(Domain³Snap)
        YQ_TACHYON_DATA(Domain³Data)
        YQ_TACHYON_DECLARE(Domain³, Domain)
    public:
    
        struct Param : public Domain::Param {
        };
    
        static void init_meta();
    
        Domain³ID id() const { return Domain³ID(UniqueID::id()); }
    
    protected:
        Domain³(const Param&);
        ~Domain³();
        
        void finalize(Domain³Data&) const;
        void snap(Domain³Snap&) const;

        using Tachyon::mail;
        using Tachyon::send;
    };
}
YQ_TYPE_DECLARE(yq::tachyon::Domain³ID)
