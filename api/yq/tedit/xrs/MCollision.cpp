////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MCollision.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/entity/Collision.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MCollision)

namespace yq::tachyon {
    MCollision::MCollision(TypedID tid) : MTachyon(tid)
    {
    }
    
    MCollision::~MCollision()
    {
    }
    
    void MCollision::init_meta()
    {
        auto w = writer<MCollision>();
        w.description("Collision Qt Binder");
        w.manage<Collision>();
    }
}


#include "moc_MCollision.cpp"
