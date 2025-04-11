////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIToolBarWriter.hpp"
#include <ya/uis/UIToolBar.hpp>

namespace yq::tachyon {
    UIToolBarWriter::UIToolBarWriter() = default;
    UIToolBarWriter::UIToolBarWriter(const UIToolBarWriter&) = default;
    UIToolBarWriter::~UIToolBarWriter() = default;

    UIToolBar* UIToolBarWriter::element()
    {
        return static_cast<UIToolBar*>(m_ui);
    }
    
    UIToolBarWriter::UIToolBarWriter(UIToolBar* ui) : UIWindowWriter(ui)
    {
    }
}
