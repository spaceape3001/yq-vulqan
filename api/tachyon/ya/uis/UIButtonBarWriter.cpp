////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIButtonBarWriter.hpp"
#include <ya/uis/UIButtonBar.hpp>

namespace yq::tachyon {
    UIButtonBarWriter::UIButtonBarWriter() = default;
    UIButtonBarWriter::UIButtonBarWriter(const UIButtonBarWriter&) = default;
    UIButtonBarWriter::~UIButtonBarWriter() = default;

    UIButtonBar* UIButtonBarWriter::element()
    {
        return static_cast<UIButtonBar*>(m_ui);
    }
    
    UIButtonBarWriter::UIButtonBarWriter(UIButtonBar* ui) : UIWindowWriter(ui)
    {
    }
}
