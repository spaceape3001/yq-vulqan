////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MKinetic3.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/entity/Kinetic3.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MKinetic3)

namespace yq::tachyon {
    MKinetic3::MKinetic3(TypedID tid) : MKinetic(tid)
    {
    }
    
    MKinetic3::~MKinetic3()
    {
    }
    
    void MKinetic3::init_meta()
    {
        auto w = writer<MKinetic3>();
        w.description("Kinetic³ Qt Binder");
        w.manage<Kinetic³>();
    }
}


#include "moc_MKinetic3.cpp"
