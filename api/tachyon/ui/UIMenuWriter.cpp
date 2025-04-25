////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIMenuWriter.hpp"
#include <tachyon/ui/UIMenu.hpp>
#include <tachyon/ui/UIMenuItem.hpp>
#include <tachyon/ui/UIMenuItemWriter.hpp>

namespace yq::tachyon {
    UIMenuWriter::UIMenuWriter() = default;
    UIMenuWriter::UIMenuWriter(const UIMenuWriter&) = default;
    UIMenuWriter::~UIMenuWriter() = default;

    UIMenu* UIMenuWriter::element()
    {
        return static_cast<UIMenu*>(m_ui);
    }
    
    UIMenuWriter::UIMenuWriter(UIMenu* ui) : UIElementsWriter(ui)
    {
    }

        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

    UIMenuItemWriter    UIMenuWriter::menuitem(std::string_view name, std::string_view scut)
    {
        return make<UIMenuItem>(name, scut);
    }
}
