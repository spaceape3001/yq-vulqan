////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIMenuBarWriter.hpp"
#include <ya/uis/UIMenuBar.hpp>
#include <ya/uis/UIMenuItem.hpp>
#include <ya/uis/UIMenuItemWriter.hpp>

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

