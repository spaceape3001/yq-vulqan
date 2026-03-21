////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tbb/spin_rw_mutex.h>
#include <yq/gluon/app/UndoSubWindow.hpp>
#include <yq/vkqt/XWidget.hpp>

using namespace yq;
using namespace yq::gluon;
using namespace yq::tachyon;

class SCEEditor : public XWidget<UndoSubWindow, Tachyon> {
    YQ_TACHYON_DECLARE(SCEEditor, Tachyon)
    Q_OBJECT
public:

    SCEEditor(TypedID docId);
    ~SCEEditor();
    
    static void init_meta();
    
private:
    TypedID     m_docId;
};
