////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MRendered3.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Rendered3.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MRendered3)

namespace yq::tachyon {
    MRendered3::MRendered3(TypedID tid) : MRendered(tid)
    {
    }
    
    MRendered3::~MRendered3()
    {
    }
    
    void MRendered3::init_meta()
    {
        auto w = writer<MRendered3>();
        w.description("Rendered³ Qt Binder");
        w.manage<Rendered³>();
    }
}


#include "moc_MRendered3.cpp"
