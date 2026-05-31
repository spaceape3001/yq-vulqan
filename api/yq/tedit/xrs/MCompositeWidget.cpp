////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MCompositeWidget.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/asset/widget/CompositeWidget.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MCompositeWidget)

namespace yq::tachyon {
    MCompositeWidget::MCompositeWidget(TypedID tid) : MWidget(tid)
    {
    }
    
    MCompositeWidget::~MCompositeWidget()
    {
    }
    
    void MCompositeWidget::init_meta()
    {
        auto w = writer<MCompositeWidget>();
        w.description("CompositeWidget Qt Binder");
        w.manage<CompositeWidget>();
    }
}


#include "moc_MCompositeWidget.cpp"
