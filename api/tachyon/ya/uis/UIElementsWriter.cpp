////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElementsWriter.hpp"
#include <ya/uis/UIButton.hpp>
#include <ya/uis/UIButtonWriter.hpp>
#include <ya/uis/UICenterAlign.hpp>
#include <ya/uis/UICenterAlignWriter.hpp>
#include <ya/uis/UIElements.hpp>
#include <ya/uis/UIHBox.hpp>
#include <ya/uis/UIHBoxWriter.hpp>
#include <ya/uis/UIMenu.hpp>
#include <ya/uis/UIMenuWriter.hpp>
#include <ya/uis/UIMenuBar.hpp>
#include <ya/uis/UIMenuBarWriter.hpp>
#include <ya/uis/UIRightAlign.hpp>
#include <ya/uis/UIRightAlignWriter.hpp>
#include <ya/uis/UISpacer.hpp>
#include <ya/uis/UISpacerWriter.hpp>
#include <ya/uis/UITextLabel.hpp>
#include <ya/uis/UITextLabelWriter.hpp>
#include <ya/uis/UIToolBar.hpp>
#include <ya/uis/UIToolBarWriter.hpp>
#include <yt/ui/Widget.hpp>

namespace yq::tachyon {
    UIElements*   UIElementsWriter::attach(Widget* w)
    {
        if(!w)
            return nullptr;
        if(w->m_ui)
            return dynamic_cast<UIElements*>(w->m_ui);
        UIElements*ret   = new UIElements;
        w->m_ui = ret;
        return ret;
    }
    
    UIElements*   UIElementsWriter::attach(WidgetInfo*w)
    {
        if(!w)
            return nullptr;
        if(w->m_ui)
            return dynamic_cast<UIElements*>(w->m_ui);
        UIElements*ret   = new UIElements;
        w->m_ui = ret;
        return ret;
    }


    UIElementsWriter::UIElementsWriter() = default;
    UIElementsWriter::UIElementsWriter(const UIElementsWriter&) = default;
    UIElementsWriter::~UIElementsWriter() = default;
    
    UIElementsWriter::UIElementsWriter(UIElements* elem) : UIElementWriter(elem)
    {
    }

    UIElementsWriter::UIElementsWriter(Widget*w) : UIElementWriter(attach(w))
    {
    }
    
    UIElementsWriter::UIElementsWriter(WidgetInfo* w) : UIElementWriter(attach(w))
    {
    }
    

    bool        UIElementsWriter::add(UIElement*elem)
    {
        if(elem && m_ui){
            static_cast<UIElements*>(m_ui) -> m_items.push_back(elem);
            return true;
        } else {
            if(elem)
                delete(elem);
            return false;
        }
    }

    UIElements*     UIElementsWriter::element()
    {
        return static_cast<UIElements*>(m_ui);
    }

        
        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////


    UIButtonWriter          UIElementsWriter::button(std::string_view text)
    {
        return make<UIButton>(text);
    }
    
    UIButtonWriter          UIElementsWriter::button(std::string_view text, const Size2F& size)
    {
        return make<UIButton>(text, size);
    }

    UICenterAlignWriter     UIElementsWriter::center(align_k)
    {
        return make<UICenterAlign>();
    }
    
    UIHBoxWriter            UIElementsWriter::hbox()
    {
        return make<UIHBox>();
    }
    
    UITextLabelWriter       UIElementsWriter::label(std::string_view text)
    {
        return make<UITextLabel>(text);
    }

    UIMenuWriter            UIElementsWriter::menu(std::string_view name)
    {
        return make<UIMenu>(name);
    }

    UIMenuBarWriter         UIElementsWriter::menubar()
    {
        return make<UIMenuBar>();
    }

    UIRightAlignWriter      UIElementsWriter::right(align_k)
    {
        return make<UIRightAlign>();
    }
    
    UIToolBarWriter         UIElementsWriter::toolbar(UICardinal dir, std::string_view kName)
    {
        return make<UIToolBar>(dir, kName);
    }
    
    UIToolBarWriter         UIElementsWriter::toolbar(const Vector2F& dir, std::string_view kName)
    {
        return make<UIToolBar>(dir, kName);
    }
}
