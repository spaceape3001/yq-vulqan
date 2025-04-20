////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIAppMainWriter.hpp"
#include <ya/uis/UIAppMain.hpp>
#include <ya/uis/UIMenuBar.hpp>
#include <ya/uis/UIMenuBarWriter.hpp>
#include <ya/uis/UIToolBar.hpp>
#include <ya/uis/UIToolBarWriter.hpp>
#include <ya/uis/UIWindow.hpp>
#include <ya/uis/UIWindowWriter.hpp>
#include <yt/ui/Widget.hpp>

namespace yq::tachyon {
    UIAppMain*   UIAppMainWriter::attach(Widget* w)
    {
        if(!w)
            return nullptr;
        if(w->m_ui.root)
            return dynamic_cast<UIAppMain*>(w->m_ui.root);
        UIAppMain*ret   = new UIAppMain;
        w->m_ui.root = ret;
        return ret;
    }
    
    UIAppMain*   UIAppMainWriter::attach(WidgetInfo*w)
    {
        if(!w)
            return nullptr;
        if(w->m_ui)
            return dynamic_cast<UIAppMain*>(w->m_ui);
        UIAppMain*ret   = new UIAppMain;
        w->m_ui = ret;
        return ret;
    }

    UIAppMainWriter::UIAppMainWriter() = default;
    UIAppMainWriter::UIAppMainWriter(const UIAppMainWriter&) = default;
    UIAppMainWriter::~UIAppMainWriter() = default;
    
    UIAppMainWriter::UIAppMainWriter(Widget* w) : UIElementsWriter(attach(w))
    {
    }
    
    UIAppMainWriter::UIAppMainWriter(WidgetInfo* wi) : UIElementsWriter(attach(wi))
    {
    }

    UIAppMain* UIAppMainWriter::element()
    {
        return static_cast<UIAppMain*>(m_ui);
    }
    
    UIAppMainWriter::UIAppMainWriter(UIAppMain* ui) : UIElementsWriter(ui)
    {
    }
    
    /////////////////////////////////////////////
    // Element Creation Helpers
    /////////////////////////////////////////////

    UIMenuBarWriter     UIAppMainWriter::menubar()
    {
        return make<UIMenuBar>();
    }
    
    UIMenuBarWriter     UIAppMainWriter::menubar(main_k)
    {
        return make<UIMenuBar>(MAIN);
    }

    UIToolBarWriter   UIAppMainWriter::toolbar(UICardinal dir, std::string_view kName)
    {
        return make<UIToolBar>(dir, kName);
    }
    
    UIToolBarWriter   UIAppMainWriter::toolbar(const Vector2F& dir, std::string_view kName)
    {
        return make<UIToolBar>(dir, kName);
    }

    UIWindowWriter    UIAppMainWriter::window(std::string_view kName)
    {
        return make<UIWindow>(kName);
    }
}
