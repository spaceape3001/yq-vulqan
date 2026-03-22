////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TEEditor.hpp"
#include "TEEditorData.hpp"
#include "TEEditorMetaWriter.hpp"

YQ_TACHYON_IMPLEMENT(yq::tachyon::TEEditor)

namespace yq::tachyon {
    void TEEditor::init_meta()
    {
        auto w = writer<TEEditor>();
        w.description("Common Editor");
    }

    TEEditor::TEEditor(QWidget*parent) : XWidget<gluon::UndoSubWindow, Tachyon>(parent)
    {
    }
    
    TEEditor::~TEEditor()
    {
    }
    
    void    TEEditor::snap(TEEditorSnap&sn) const
    {
        Tachyon::snap(sn);
    }
}

#include "moc_TEEditor.cpp"
