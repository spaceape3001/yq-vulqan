////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MCollision3.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/entity/Collision3.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MCollision3)

namespace yq::tachyon {
    MCollision3::MCollision3(TypedID tid) : MCollision(tid)
    {
    }
    
    MCollision3::~MCollision3()
    {
    }
    
    void MCollision3::init_meta()
    {
        auto w = writer<MCollision3>();
        w.description("Collision³ Qt Binder");
        w.manage<Collision³>();
    }
}


#include "moc_MCollision3.cpp"
