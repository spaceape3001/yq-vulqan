////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SCEEditor.hpp"
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(SCEEditor)

SCEEditor::SCEEditor(TypedID docId) : m_docId(docId)
{
}

SCEEditor::~SCEEditor()
{
}
    
void SCEEditor::init_meta()
{
    auto w = writer<SCEEditor>();
    w.description("Scene Editor");
}

#include "moc_SCEEditor.cpp"
