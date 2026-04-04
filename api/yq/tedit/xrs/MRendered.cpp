////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MRendered.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Rendered.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MRendered)

namespace yq::tachyon {
    MRendered::MRendered(TypedID tid) : MTachyon(tid)
    {
    }
    
    MRendered::~MRendered()
    {
    }
    
    void MRendered::init_meta()
    {
        auto w = writer<MRendered>();
        w.description("Rendered Qt Binder");
        w.manage<Rendered>();
    }
}


#include "moc_MRendered.cpp"
