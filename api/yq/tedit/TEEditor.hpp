////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tbb/spin_rw_mutex.h>
#include <yq/gluon/app/UndoSubWindow.hpp>
#include <yq/vkqt/XWidget.hpp>

namespace yq::tachyon {
    struct TEEditorData;
    struct TEEditorSnap;
    
    class TEEditor : public XWidget<gluon::UndoSubWindow, Tachyon> {
        YQ_TACHYON_DATA(TEEditorData)
        YQ_TACHYON_SNAP(TEEditorSnap)
        YQ_TACHYON_DECLARE(TEEditor, Tachyon)
        Q_OBJECT
    public:
    
        TEEditor(QWidget*parent=nullptr);
        ~TEEditor();
    
        static void init_meta();
        
    protected:
        void    snap(TEEditorSnap&) const;
    };
}
