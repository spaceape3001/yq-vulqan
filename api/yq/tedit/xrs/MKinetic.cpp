////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MKinetic.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/physicsvk/api/Kinetic.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MKinetic)

namespace yq::tachyon {
    MKinetic::MKinetic(TypedID tid) : MTachyon(tid)
    {
    }
    
    MKinetic::~MKinetic()
    {
    }
    
    void MKinetic::init_meta()
    {
        auto w = writer<MKinetic>();
        w.description("Kinetic Qt Binder");
        w.manage<Kinetic>();
    }
}


#include "moc_MKinetic.cpp"
