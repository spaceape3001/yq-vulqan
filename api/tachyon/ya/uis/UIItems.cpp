////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIItems.hpp"

namespace yq::tachyon {
    UIItems::UIItems()
    {
    }
    
    UIItems::UIItems(const UIItems& cp)
    {
        for(UIElement* ui : cp.m_items){
            UIElement* ui2 = ui -> clone();
            if(ui2)
                m_items.push_back(ui2);
        }
    }
    
    UIItems::~UIItems()
    {
        for(UIElement* ui : m_items)
            delete ui;
        m_items.clear();
    }

    UIItems&    UIItems::operator<<(UIElement*p)
    {
        append(p);
        return *this;
    }

    void    UIItems::append(UIElement*p)
    {
        if(!p)
            return;
        m_items.push_back(p);
    }

    UIItems*     UIItems::clone() const 
    {
        return new UIItems(*this);
    }

    void    UIItems::content() 
    {
        render(ITEMS);
    }
    
    bool    UIItems::empty() const
    {
        return m_items.empty();
    }
    
    void    UIItems::render() 
    {
        render(ITEMS);
    }
    
    void    UIItems::render(items_k) 
    {
        for(UIElement* ui : m_items)
            ui->draw();
    }

    size_t  UIItems::size() const
    {
        return m_items.size();
    }
}
