////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Domain.hpp>

namespace yq::tachyon {
    class SimpleDomain : public Domain {
        YQ_TACHYON_DECLARE(SimpleDomain, Domain)
    public:
    
        using Param = Domain::Param;
    
        SimpleDomain();
        SimpleDomain(const Param&);
        ~SimpleDomain();
        static void init_meta();
        
    protected:
        //void    snap(DomainSnap&) const;
    };
}
