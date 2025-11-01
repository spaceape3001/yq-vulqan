////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIAppMainWriter.hpp"
#include <yq/tachyon/ui/UIAppMain.hpp>
#include <yq/tachyon/ui/UIMenuBar.hpp>
#include <yq/tachyon/ui/UIMenuBarWriter.hpp>
#include <yq/tachyon/ui/UIToolBar.hpp>
#include <yq/tachyon/ui/UIToolBarWriter.hpp>
#include <yq/tachyon/ui/UIWindow.hpp>
#include <yq/tachyon/ui/UIWindowWriter.hpp>
#include <yq/tachyon/api/Widget.hpp>

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
    
    UIAppMain*   UIAppMainWriter::attach(WidgetMeta*w)
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
    
    UIAppMainWriter::UIAppMainWriter(WidgetMeta* wi) : UIElementsWriter(attach(wi))
    {
    }

    UIAppMain* UIAppMainWriter::element()
    {
        return dynamic_cast<UIAppMain*>(m_ui);
    }
    
    UIAppMainWriter::UIAppMainWriter(UIAppMain* ui) : UIElementsWriter(ui)
    {
    }
    
    /////////////////////////////////////////////
    // Element Creation Helpers
    /////////////////////////////////////////////

    UIToolBarWriter   UIAppMainWriter::toolbar(Cardinal dir, std::string_view kName)
    {
        return make<UIToolBar>(dir, kName);
    }
    
    UIToolBarWriter   UIAppMainWriter::toolbar(const Vector2F& dir, std::string_view kName)
    {
        return make<UIToolBar>(dir, kName);
    }

    UIMenuBarWriter     UIAppMainWriter::menubar()
    {
        return make<UIMenuBar>();
    }
    
    UIMenuBarWriter     UIAppMainWriter::menubar(main_k)
    {
        return make<UIMenuBar>(MAIN);
    }
    UIWindowWriter    UIAppMainWriter::window(std::string_view kName)
    {
        return make<UIWindow>(kName);
    }
}
