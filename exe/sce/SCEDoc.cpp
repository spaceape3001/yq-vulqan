////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SCEDoc.hpp"
#include <yq/tachyon/api/ThreadMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(SCEDoc)

void SCEDoc::init_meta()
{
    auto w = writer<SCEDoc>();
    w.description("SCEDoc/Thread");
}
    
SCEDoc::SCEDoc()
{
}

SCEDoc::~SCEDoc()
{
}

void SCEDoc::snap(SCEDocSnap&sn) const
{
    EditThread::snap(sn);
}


#include "moc_SCEDoc.cpp"


