////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGView.hpp"
#include "XGViewWriter.hpp"
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::XGView)

namespace yq::tachyon {
    XGView::XGView(std::string_view k, UIFlags flags) : UICanvas(k, flags)
    {
    }
    
    XGView::XGView(const XGView& cp) : UICanvas(cp)
    {
    }
    
    XGView::~XGView()
    {
    }
    
    XGView* XGView::clone() const 
    {
        return new XGView(*this);
    }
    
    void XGView::init_info()
    {
        auto w = writer<XGView>();
        w.description("Executive Graph View UI");
    }


////////////////////////////////////////////////////////////////////////////////

    XGViewWriter::XGViewWriter() = default;
    XGViewWriter::XGViewWriter(const XGViewWriter&) = default;
    XGViewWriter::~XGViewWriter() = default;

    XGView* XGViewWriter::element()
    {
        return static_cast<XGView*>(m_ui);
    }
    
    XGViewWriter::XGViewWriter(XGView* ui) : UICanvasWriter(ui)
    {
    }
}
