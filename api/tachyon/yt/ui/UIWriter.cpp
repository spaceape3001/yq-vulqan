////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIWriter.hpp"
#include "Widget.hpp"
#include "UIElement.hpp"

#include <ya/uis/UIAppMain.hpp>
#include <ya/uis/UIButton.hpp>
#include <ya/uis/UICenterAlign.hpp>
#include <ya/uis/UIElements.hpp>
#include <ya/uis/UIHBox.hpp>
#include <ya/uis/UIMenu.hpp>
#include <ya/uis/UIMenuBar.hpp>
#include <ya/uis/UIMenuItem.hpp>
#include <ya/uis/UIRightAlign.hpp>
#include <ya/uis/UITextLabel.hpp>
#include <ya/uis/UIToolBar.hpp>
#include <ya/uis/UIWindow.hpp>

namespace yq::tachyon {
    UIWriter::UIWriter() = default;
    UIWriter::UIWriter(const UIWriter&) = default;
    UIWriter::UIWriter(UIWriter&&) = default;
    UIWriter& UIWriter::operator=(const UIWriter&) = default;
    UIWriter& UIWriter::operator=(UIWriter&&) = default;

    UIWriter::UIWriter(Widget& widget) : m_owner(&widget)
    {
    }
    
    UIWriter::UIWriter(WidgetInfo& info) : m_owner(&info)
    {
    }
    
    UIWriter::UIWriter(UIElements& ui) : m_owner(&ui)
    {
    }

    UIWriter::UIWriter(UIElement& ui) : m_owner(&ui)
    {
    }
    
    UIWriter::~UIWriter()
    {
    }

    bool        UIWriter::add(UIElement*ui)
    {
        if(!ui)
            return false;
            
        if(auto p = std::get_if<Widget*>(&m_owner)){
            Widget* w   = *p;
            if(w){
                if(!w->m_ui)
                    w->m_ui = new UIElements;
                w->m_ui->append(ui);
                return true;
            }
        }
        if(auto p = std::get_if<WidgetInfo*>(&m_owner)){
            WidgetInfo* w   = *p;
            if(w){
                if(!w->m_ui)
                    w->m_ui = new UIElements;
                w->m_ui->append(ui);
                return true;
            }
        }
        if(auto p = std::get_if<UIElements*>(&m_owner)){
            if(*p){
                ui -> m_parent    = *p;
                (*p) -> append(ui);
                return true;
            }
        }
        
        delete ui;
        return false;
    }

    bool        UIWriter::addable() const
    {
        if(auto p = std::get_if<Widget*>(&m_owner))
            return static_cast<bool>(*p);
        if(auto p = std::get_if<WidgetInfo*>(&m_owner))
            return static_cast<bool>(*p);
        if(auto p = std::get_if<UIElements*>(&m_owner))
            return static_cast<bool>(*p);
        return false;
    }
    
    UIWriter    UIWriter::operator<<(UIElement* ui)
    {
        if(!add(ui))    // this *likely* means a bad input/state
            return UIWriter();
        UIElements*    items   = dynamic_cast<UIElements*>(ui);
        if(!items)      // this isn't an error as there will be non-items elements
            return UIWriter();
        return UIWriter(*items);
    }

    UIWriter::operator UIElement*()
    {
        return element();
    }


    UIElement*  UIWriter::element()
    {
        if(auto p = std::get_if<UIElements*>(&m_owner))
            return *p;
        if(auto p = std::get_if<UIElement*>(&m_owner))
            return *p;
        return nullptr;
    }

    //  ------------------------------------------------------------------------
    //  ELEMENT CREATORS

    UIWriter    UIWriter::button(std::string_view text)
    {
        if(!addable())
            return {};
        return *this << new UIButton(text);
    }
    
    UIWriter    UIWriter::button(std::string_view text, const Vector2F& size)
    {
        if(!addable())
            return {};
        return *this << new UIButton(text, size);
    }

    UIWriter    UIWriter::center(align_k)
    {
        if(!addable())
            return {};
        return *this << new UICenterAlign;
    }

    UIWriter   UIWriter::hbox()
    {
        if(!addable())
            return {};
        return *this << new UIHBox;
    }

    UIWriter   UIWriter::label(std::string_view kText)
    {
        if(!addable())
            return {};
        if(kText.empty())
            return {};
        return *this << new UITextLabel(kText);
    }

    UIWriter    UIWriter::main(app_k, UIFlags flags)
    {
        if(auto p = std::get_if<Widget*>(&m_owner)){
            Widget* w   = *p;
            if(w && !w->m_ui){
                w->m_ui = new UIAppMain(flags);
                return UIWriter(*(w->m_ui));
            }
        }
        if(auto p = std::get_if<WidgetInfo*>(&m_owner)){
            WidgetInfo* w   = *p;
            if(w && !w->m_ui){
                w->m_ui = new UIAppMain(flags);
                return UIWriter(*(w->m_ui));
            }
        }
    
        return {};
    }

    UIWriter    UIWriter::menu(std::string_view name)
    {
        if(!addable())
            return {};
        if(name.empty())
            return {};
        return *this << new UIMenu(name);
    }

    UIWriter    UIWriter::menubar()
    {
        if(!addable())
            return {};
        return *this << new UIMenuBar;
    }
    
    UIWriter    UIWriter::menubar(main_k)
    {
        if(!addable())
            return {};
        return *this << new UIMenuBar(MAIN);
    }

    UIWriter     UIWriter::menuitem(std::string_view kName, std::string_view scut)
    {
        if(!addable())
            return {};
        if(kName.empty())
            return {};
        return *this << new UIMenuItem(kName, scut);
    }

    UIWriter    UIWriter::toolbar(UIBorder b, std::string_view kName, UIFlags flags)
    {
        if(!addable())
            return {};
        return *this << new UIToolBar(b, kName, flags);
    }

    UIWriter    UIWriter::right(align_k)
    {
        if(!addable())
            return {};
        return *this << new UIRightAlign;
    }

    UIWriter    UIWriter::window(std::string_view kName, UIFlags flags)
    {
        if(!addable())
            return {};
        return *this << new UIWindow(kName, flags);
    }
}

