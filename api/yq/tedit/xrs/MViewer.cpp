////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MViewer.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/app/Viewer.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MViewer)

namespace yq::tachyon {
    MViewer::MViewer(TypedID tid) : MTachyon(tid)
    {
    }
    
    MViewer::~MViewer()
    {
    }
    
    void MViewer::init_meta()
    {
        auto w = writer<MViewer>();
        w.description("Viewer Qt Binder");
        w.manage<Viewer>();
    }
}


#include "moc_MViewer.cpp"
