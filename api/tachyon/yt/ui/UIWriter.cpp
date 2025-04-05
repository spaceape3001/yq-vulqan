////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIWriter.hpp"
#include "Widget.hpp"
#include "UIElement.hpp"

#include <ya/uis/CenterAlign.hpp>
#include <ya/uis/Menu.hpp>
#include <ya/uis/MenuBar.hpp>
#include <ya/uis/MenuItem.hpp>
#include <ya/uis/RightAlign.hpp>
#include <ya/uis/UIItems.hpp>

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
    
    UIWriter::UIWriter(UIItems& ui) : m_owner(&ui)
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
                    w->m_ui = new UIItems();
                w->m_ui->append(ui);
                return true;
            }
        }
        if(auto p = std::get_if<WidgetInfo*>(&m_owner)){
            WidgetInfo* w   = *p;
            if(w){
                if(!w->m_ui)
                    w->m_ui = new UIItems;
                w->m_ui->append(ui);
                return true;
            }
        }
        if(auto p = std::get_if<UIItems*>(&m_owner)){
            if(*p){
                (*p) -> append(ui);
                return true;
            }
        }
        
        delete ui;
        return false;
    }

    UIWriter    UIWriter::operator<<(UIElement* ui)
    {
        if(!add(ui))    // this *likely* means a bad input/state
            return UIWriter();
        UIItems*    items   = dynamic_cast<UIItems*>(ui);
        if(!items)      // this isn't an error as there will be non-items elements
            return UIWriter();
        return UIWriter(*items);
    }

    UIWriter    UIWriter::center(align_k)
    {
        return *this << new CenterAlign;
    }

    UIWriter    UIWriter::menu(std::string_view name)
    {
        if(name.empty())
            return {};
        return *this << new Menu(name);
    }

    UIWriter    UIWriter::menubar()
    {
        return *this << new MenuBar;
    }
    
    UIWriter    UIWriter::menubar(main_k)
    {
        return *this << new MenuBar(MAIN);
    }

    void        UIWriter::menuitem(std::string_view kName, std::string_view scut)
    {
        if(kName.empty())
            return ;
        *this << new MenuItem(kName, scut);
    }

    UIWriter    UIWriter::right(align_k)
    {
        return *this << new RightAlign;
    }
}

