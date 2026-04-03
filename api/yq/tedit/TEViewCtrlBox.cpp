////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TEViewCtrlBox.hpp"
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::TEViewCtrlBox)

namespace yq::tachyon {
    TEViewCtrlBox::TEViewCtrlBox(QWidget* parent) : TEViewCtrlBox(TEViewCtrlBoxOptions(), parent)
    {
    }
    
    TEViewCtrlBox::TEViewCtrlBox(const TEViewCtrlBoxOptions& opts, QWidget* parent) : xwidget_type(parent)
    {
        //  TODO
    }

    TEViewCtrlBox::~TEViewCtrlBox()
    {
    }
    
    Execution   TEViewCtrlBox::setup(const Context&ctx) 
    {
        return Tachyon::setup(ctx);
    }

    void TEViewCtrlBox::init_meta()
    {
        auto w = writer<TEViewCtrlBox>();
        w.description("Dock of View Controls");
    }
}

#include "moc_TEViewCtrlBox.cpp"
