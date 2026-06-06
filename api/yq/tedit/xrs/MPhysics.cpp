////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MPhysics.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Physics.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MPhysics)

namespace yq::tachyon {
    MPhysics::MPhysics(TypedID tid) : MTachyon(tid)
    {
    }
    
    MPhysics::~MPhysics()
    {
    }
    
    void MPhysics::init_meta()
    {
        auto w = writer<MPhysics>();
        w.description("Physics Qt Binder");
        w.manage<Physics>();
    }
}


#include "moc_MPhysics.cpp"
