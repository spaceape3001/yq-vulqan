////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SCEViewer.hpp"
#include "SCEDoc.hpp"
#include <yq/tachyon/api/WidgetMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(SCEViewer)

SCEViewer::SCEViewer(TypedID docId) : m_docId(docId)
{
}

SCEViewer::~SCEViewer()
{
}
    
void SCEViewer::init_meta()
{
    auto w = writer<SCEViewer>();
    w.description("Scene Editor Viewer");
}



#include "moc_SCEViewer.cpp"
