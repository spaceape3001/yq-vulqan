////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MForce3.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/physics/Force3.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MForce3)

namespace yq::tachyon {
    MForce3::MForce3(TypedID tid) : MPhysics(tid)
    {
    }
    
    MForce3::~MForce3()
    {
    }
    
    void MForce3::init_meta()
    {
        auto w = writer<MForce3>();
        w.description("Force³ Qt Binder");
        w.manage<Force³>();
    }
}


#include "moc_MForce3.cpp"
