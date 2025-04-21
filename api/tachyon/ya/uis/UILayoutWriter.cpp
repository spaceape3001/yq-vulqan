////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UILayout.hpp"
#include "UILayoutWriter.hpp"
#include "UIWindow.hpp"
#include "UIWindowWriter.hpp"

namespace yq::tachyon {

    UILayoutWriter::UILayoutWriter() = default;
    UILayoutWriter::UILayoutWriter(const UILayoutWriter&) = default;
    UILayoutWriter::~UILayoutWriter() = default;
    
    UILayout* UILayoutWriter::element()
    {
        return static_cast<UILayout*>(m_ui);
    }
    
    UILayoutWriter::UILayoutWriter(UILayout* ui) : UIElementsWriter(ui)
    {
    }

    UIWindowWriter      UILayoutWriter::window(std::string_view kName)
    {
        return make<UIWindow>(kName);
    }
}
