////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElementsWriter.hpp"
#include <tachyon/ui/UIButton.hpp>
#include <tachyon/ui/UIButtonWriter.hpp>
#include <tachyon/ui/UICenterAlign.hpp>
#include <tachyon/ui/UICenterAlignWriter.hpp>
#include <tachyon/ui/UICheckBox_Simple.hpp>
#include <tachyon/ui/UICheckBox_Visible.hpp>
#include <tachyon/ui/UICheckBoxWriter.hpp>
#include <tachyon/ui/UIElements.hpp>
#include <tachyon/ui/UIHBox.hpp>
#include <tachyon/ui/UIHBoxWriter.hpp>
#include <tachyon/ui/UIHLine.hpp>
#include <tachyon/ui/UIHLineWriter.hpp>
#include <tachyon/ui/UIImage.hpp>
#include <tachyon/ui/UIImageWriter.hpp>
#include <tachyon/ui/UIMenu.hpp>
#include <tachyon/ui/UIMenuWriter.hpp>
#include <tachyon/ui/UIMenuBar.hpp>
#include <tachyon/ui/UIMenuBarWriter.hpp>
#include <tachyon/ui/UIRightAlign.hpp>
#include <tachyon/ui/UIRightAlignWriter.hpp>
#include <tachyon/ui/UISpacer.hpp>
#include <tachyon/ui/UISpacerWriter.hpp>
#include <tachyon/ui/UITextLabel.hpp>
#include <tachyon/ui/UITextLabelWriter.hpp>
#include <tachyon/ui/UIButtonBar.hpp>
#include <tachyon/ui/UIButtonBarWriter.hpp>
#include <tachyon/ui/UIVBox.hpp>
#include <tachyon/ui/UIVBoxWriter.hpp>
#include <yt/ui/Widget.hpp>

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

    UIHBoxWriter            UIElementsWriter::hbox()
    {
        return make<UIHBox>();
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

    UISpacerWriter          UIElementsWriter::spacer(const Size2F& sz)
    {
        return make<UISpacer>(sz);
    }

    UIVBoxWriter            UIElementsWriter::vbox()
    {
        return make<UIVBox>();
    }
}
