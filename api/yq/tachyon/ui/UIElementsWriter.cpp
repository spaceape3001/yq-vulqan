////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElementsWriter.hpp"
#include <yq/tachyon/ui/UIButton.hpp>
#include <yq/tachyon/ui/UIButtonWriter.hpp>
#include <yq/tachyon/ui/UIToolBar.hpp>
#include <yq/tachyon/ui/UIToolBarWriter.hpp>
#include <yq/tachyon/ui/UICheckBox_Simple.hpp>
#include <yq/tachyon/ui/UICheckBox_Visible.hpp>
#include <yq/tachyon/ui/UICheckBoxWriter.hpp>
#include <yq/tachyon/ui/UIElements.hpp>
#include <yq/tachyon/ui/UIImage.hpp>
#include <yq/tachyon/ui/UIImageWriter.hpp>
#include <yq/tachyon/ui/UIMenu.hpp>
#include <yq/tachyon/ui/UIMenuWriter.hpp>
#include <yq/tachyon/ui/UIMenuBar.hpp>
#include <yq/tachyon/ui/UIMenuBarWriter.hpp>
#include <yq/tachyon/ui/UISection.hpp>
#include <yq/tachyon/ui/UISpacer.hpp>
#include <yq/tachyon/ui/UISpacerWriter.hpp>
#include <yq/tachyon/ui/UITextLabel.hpp>
#include <yq/tachyon/ui/UITextLabelWriter.hpp>

#include <yq/tachyon/ui/align/UICenterAlign.hpp>
#include <yq/tachyon/ui/align/UICenterAlignWriter.hpp>
#include <yq/tachyon/ui/align/UIHLine.hpp>
#include <yq/tachyon/ui/align/UIHLineWriter.hpp>
#include <yq/tachyon/ui/align/UIRightAlign.hpp>
#include <yq/tachyon/ui/align/UIRightAlignWriter.hpp>

#include <yq/tachyon/ui/layout/UIHBoxLayout.hpp>
#include <yq/tachyon/ui/layout/UIHBoxLayoutWriter.hpp>
#include <yq/tachyon/ui/layout/UIVBoxLayout.hpp>
#include <yq/tachyon/ui/layout/UIVBoxLayoutWriter.hpp>

#include <yq/tachyon/api/Widget.hpp>

namespace yq::tachyon {
    UIElements*   UIElementsWriter::attach(Widget* w)
    {
        if(!w)
            return nullptr;
        if(w->m_ui.root)
            return dynamic_cast<UIElements*>(w->m_ui.root);
        UIElements*ret   = new UIElements;
        w->m_ui.root = ret;
        return ret;
    }
    
    UIElements*   UIElementsWriter::attach(WidgetMeta*w)
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
    
    UIElementsWriter::UIElementsWriter(WidgetMeta* w) : UIElementWriter(attach(w))
    {
    }
    
    bool        UIElementsWriter::add(UIElement*elem)
    {
        UIElements* ui  = element();
        if(elem && ui && is_accept(ui->acceptable(elem))){
            ui -> m_items.push_back(elem);
            ui -> postadd(elem);
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

    UICheckBoxWriter        UIElementsWriter::checkbox(std::string_view text, bool value)
    {
        return make<UICheckBox_Simple>(text, value);
    }

    UICheckBoxWriter        UIElementsWriter::checkbox(std::string_view text, visible_k, UIElement* uielem)
    {
        if(!uielem)
            return {};
        return make<UICheckBox_Visible>(text, uielem->binding(CREATE));
    }
    
    UICheckBoxWriter        UIElementsWriter::checkbox(std::string_view text, visible_k, UIElementWriter& uielem)
    {
        return checkbox(text, VISIBLE, uielem.element());
    }

    UICheckBoxWriter        UIElementsWriter::checkbox(visible_k, UIElement* uielem)
    {
        if(!uielem)
            return {};
        std::string_view    text;
        if(const char* title   = uielem->title())
            text    = title;
        return make<UICheckBox_Visible>(text, uielem->binding(CREATE));
    }
    
    UICheckBoxWriter        UIElementsWriter::checkbox(visible_k, UIElementWriter& elem)
    {
        return checkbox(VISIBLE, elem.element());
    }

    UIHBoxLayoutWriter            UIElementsWriter::hbox()
    {
        return make<UIHBoxLayout>();
    }
    
    UIHLineWriter            UIElementsWriter::hline()
    {
        return make<UIHLine>();
    }

    UIImageWriter           UIElementsWriter::image(std::string_view path)
    {
        return make<UIImage>(path);
    }
    
    UIImageWriter           UIElementsWriter::image(std::string_view path, const Size2F&sz)
    {
        return make<UIImage>(path, sz);
    }
    
    UITextLabelWriter       UIElementsWriter::label(std::string_view text)
    {
        return make<UITextLabel>(text);
    }

    UIMenuWriter            UIElementsWriter::menu(std::string_view name)
    {
        return make<UIMenu>(name);
    }

    UIRightAlignWriter      UIElementsWriter::right(align_k)
    {
        return make<UIRightAlign>();
    }

    UIElementsWriter        UIElementsWriter::section(std::string_view sz)
    {
        return make<UISection>(sz);
    }

    UISpacerWriter          UIElementsWriter::spacer(const Size2F& sz)
    {
        return make<UISpacer>(sz);
    }

    UIVBoxLayoutWriter            UIElementsWriter::vbox()
    {
        return make<UIVBoxLayout>();
    }
}
