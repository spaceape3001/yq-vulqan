////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIMenuBarWriter.hpp"
#include <tachyon/ui/UIMenuBar.hpp>
#include <tachyon/ui/UIMenuItem.hpp>
#include <tachyon/ui/UIMenuItemWriter.hpp>

namespace yq::tachyon {
    UIMenuBarWriter::UIMenuBarWriter() = default;
    UIMenuBarWriter::UIMenuBarWriter(const UIMenuBarWriter&) = default;
    UIMenuBarWriter::~UIMenuBarWriter() = default;

    UIMenuBar* UIMenuBarWriter::element()
    {
        return static_cast<UIMenuBar*>(m_ui);
    }
    
    UIMenuBarWriter::UIMenuBarWriter(UIMenuBar* ui) : UIElementsWriter(ui)
    {
    }

        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

    UIMenuItemWriter    UIMenuBarWriter::menuitem(std::string_view name, std::string_view scut)
    {
        return make<UIMenuItem>(name, scut);
    }
}

