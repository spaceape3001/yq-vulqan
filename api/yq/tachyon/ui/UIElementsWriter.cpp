////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElementsWriter.hpp"
#include <yq/tachyon/ui/UIElements.hpp>
#include <yq/tachyon/ui/UIImageWriter.hpp>
#include <yq/tachyon/ui/UITextLabelWriter.hpp>
#include <yq/tachyon/ui/UIToolBarWriter.hpp>

#include <yq/tachyon/ui/align/UICenterAlignWriter.hpp>
#include <yq/tachyon/ui/align/UIHLineWriter.hpp>
#include <yq/tachyon/ui/align/UIRightAlignWriter.hpp>

#include <yq/tachyon/ui/input/UIButtonWriter.hpp>
#include <yq/tachyon/ui/input/UICheckBox_Simple.hpp>
#include <yq/tachyon/ui/input/UICheckBox_Visible.hpp>
#include <yq/tachyon/ui/input/UICheckBoxWriter.hpp>

#include <yq/tachyon/ui/layout/UIHBoxLayoutWriter.hpp>
#include <yq/tachyon/ui/layout/UISection.hpp>
#include <yq/tachyon/ui/layout/UISeparator.hpp>
#include <yq/tachyon/ui/layout/UITree.hpp>
#include <yq/tachyon/ui/layout/UISpacerWriter.hpp>
#include <yq/tachyon/ui/layout/UIVBoxLayoutWriter.hpp>

#include <yq/tachyon/ui/menu/UIMenuWriter.hpp>
#include <yq/tachyon/ui/menu/UIMenuBarWriter.hpp>
#include <yq/tachyon/ui/menu/UIMenuItemWriter.hpp>

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
        if(ui && elem)
            return ui->append(elem);
        return false;
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

    UIMenuItemWriter        UIElementsWriter::menuitem(std::string_view name, std::string_view scut)
    {
        return make<UIMenuItem>(name, scut);
    }

    UIRightAlignWriter      UIElementsWriter::right(align_k)
    {
        return make<UIRightAlign>();
    }

    UIElementsWriter        UIElementsWriter::section(std::string_view sz)
    {
        return make<UISection>(sz);
    }

    UIElementWriter         UIElementsWriter::separator()
    {
        return make<UISeparator>();
    }

    UISpacerWriter          UIElementsWriter::spacer(const Size2F& sz)
    {
        return make<UISpacer>(sz);
    }

    UIElementsWriter        UIElementsWriter::tree(UIFlags flags)
    {
        return make<UITree>(flags);
    }

    UIVBoxLayoutWriter            UIElementsWriter::vbox()
    {
        return make<UIVBoxLayout>();
    }
}
