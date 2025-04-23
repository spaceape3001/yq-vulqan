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
#include <ya/uis/UIHLine.hpp>
#include <ya/uis/UIHLineWriter.hpp>
#include <ya/uis/UIImage.hpp>
#include <ya/uis/UIImageWriter.hpp>
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
#include <ya/uis/UIButtonBar.hpp>
#include <ya/uis/UIButtonBarWriter.hpp>
#include <ya/uis/UIVBox.hpp>
#include <ya/uis/UIVBoxWriter.hpp>
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
