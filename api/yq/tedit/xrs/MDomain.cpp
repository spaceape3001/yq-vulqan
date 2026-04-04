////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MDomain.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Domain.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MDomain)

namespace yq::tachyon {
    MDomain::MDomain(TypedID tid) : MTachyon(tid)
    {
    }
    
    MDomain::~MDomain()
    {
    }
    
    void MDomain::init_meta()
    {
        auto w = writer<MDomain>();
        w.description("Domain Qt Binder");
        w.manage<Domain>();
    }
}


#include "moc_MDomain.cpp"
