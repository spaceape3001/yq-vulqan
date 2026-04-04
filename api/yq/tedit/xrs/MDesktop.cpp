////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MDesktop.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Desktop.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MDesktop)

namespace yq::tachyon {
    MDesktop::MDesktop(TypedID tid) : MTachyon(tid)
    {
    }
    
    MDesktop::~MDesktop()
    {
    }
    
    void MDesktop::init_meta()
    {
        auto w = writer<MDesktop>();
        w.description("Desktop Qt Binder");
        w.manage<Desktop>();
    }
}


#include "moc_MDesktop.cpp"
