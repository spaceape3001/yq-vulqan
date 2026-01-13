////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGViewUI.hpp"
#include "XGViewUIWriter.hpp"
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::XGViewUI)

namespace yq::tachyon {
    XGViewUI::XGViewUI(std::string_view k, UIFlags flags) : UICanvas(k, flags)
    {
    }
    
    XGViewUI::XGViewUI(const XGViewUI& cp) : UICanvas(cp)
    {
    }
    
    XGViewUI::~XGViewUI()
    {
    }
    
    XGViewUI* XGViewUI::clone() const 
    {
        return new XGViewUI(*this);
    }
    
    void XGViewUI::init_info()
    {
        auto w = writer<XGViewUI>();
        w.description("Executive Graph View UI");
    }


////////////////////////////////////////////////////////////////////////////////

    XGViewUIWriter::XGViewUIWriter() = default;
    XGViewUIWriter::XGViewUIWriter(const XGViewUIWriter&) = default;
    XGViewUIWriter::~XGViewUIWriter() = default;

    XGViewUI* XGViewUIWriter::element()
    {
        return static_cast<XGViewUI*>(m_ui);
    }
    
    XGViewUIWriter::XGViewUIWriter(XGViewUI* ui) : UICanvasWriter(ui)
    {
    }
}
