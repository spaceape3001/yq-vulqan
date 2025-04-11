////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIWindowWriter.hpp"
#include <ya/uis/UIMenuBar.hpp>
#include <ya/uis/UIMenuBarWriter.hpp>
#include <ya/uis/UIToolBar.hpp>
#include <ya/uis/UIToolBarWriter.hpp>
#include <ya/uis/UIWindow.hpp>

namespace yq::tachyon {
    UIWindowWriter::UIWindowWriter() = default;
    UIWindowWriter::UIWindowWriter(const UIWindowWriter&) = default;
    UIWindowWriter::~UIWindowWriter() = default;

    UIWindow* UIWindowWriter::element()
    {
        return static_cast<UIWindow*>(m_ui);
    }
    
    UIWindowWriter::UIWindowWriter(UIWindow* ui) : UIElementsWriter(ui)
    {
    }


        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

    UIMenuBarWriter     UIWindowWriter::menubar()
    {
        return make<UIMenuBar>();
    }

    UIToolBarWriter     UIWindowWriter::toolbar(UICardinal dir, std::string_view kName)
    {
        return make<UIToolBar>(dir, kName);
    }
    
    UIToolBarWriter     UIWindowWriter::toolbar(const Vector2F& dir, std::string_view kName)
    {
        return make<UIToolBar>(dir, kName);
    }
}

