////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UICalc.hpp"
#include "UICalcWriter.hpp"
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UICalc)

namespace yq::tachyon {

    UICalc::UICalc()
    {
    }
    
    UICalc::UICalc(const UICalc& cp) : UIElement(cp)
    {
    }
    
    UICalc::~UICalc()
    {
    }
        
    void UICalc::init_meta()
    {
        auto w = writer<UICalc>();
        w.description("UI Calculator");
    }

    ////////////////////////////
    
    UICalcWriter::UICalcWriter() = default;
    UICalcWriter::UICalcWriter(const UICalcWriter&) = default;
    UICalcWriter::~UICalcWriter() = default;
    
    UICalc* UICalcWriter::element()
    {
        return dynamic_cast<UICalc*>(m_ui);
    }
    
    UICalcWriter::UICalcWriter(UICalc* ui) : UIElementWriter(ui)
    {
    }

}
