////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MWidget.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Widget.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MWidget)

namespace yq::tachyon {
    MWidget::MWidget(TypedID tid) : MTachyon(tid)
    {
    }
    
    MWidget::~MWidget()
    {
    }
    
    void MWidget::init_meta()
    {
        auto w = writer<MWidget>();
        w.description("Widget Qt Binder");
        w.manage<Widget>();
    }
}


#include "moc_MWidget.cpp"
