////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElementWriter.hpp"
#include "Widget.hpp"
#include "UIElement.hpp"

#include <ya/uis/UIItems.hpp>

namespace yq::tachyon {
    UIElementWriter::UIElementWriter(const UIElementWriter&) = default;
    UIElementWriter::UIElementWriter(UIElementWriter&&) = default;
    UIElementWriter& UIElementWriter::operator=(const UIElementWriter&) = default;
    UIElementWriter& UIElementWriter::operator=(UIElementWriter&&) = default;

    UIElementWriter::UIElementWriter(Widget& widget) : m_owner(&widget)
    {
    }
    
    UIElementWriter::UIElementWriter(WidgetInfo& info) : m_owner(&info)
    {
    }
    
    UIElementWriter::UIElementWriter(UIItems& ui) : m_owner(&ui)
    {
    }
    
    UIElementWriter::~UIElementWriter()
    {
    }

    void        UIElementWriter::add(UIElement*ui)
    {
        if(!ui)
            return ;
            
        if(auto p = std::get_if<Widget*>(&m_owner)){
            Widget* w   = *p;
            if(w){
                if(!w->m_ui)
                    w->m_ui = std::make_unique<UIItems>();
                w->m_ui->append(ui);
                return;
            }
        }
        if(auto p = std::get_if<WidgetInfo*>(&m_owner)){
            WidgetInfo* w   = *p;
            if(w){
                if(!w->m_ui)
                    w->m_ui = new UIItems;
                w->m_ui->append(ui);
                return;
            }
        }
        if(auto p = std::get_if<UIItems*>(&m_owner)){
            if(*p){
                (*p) -> append(ui);
                return;
            }
        }
        
        delete ui;
    }
}

