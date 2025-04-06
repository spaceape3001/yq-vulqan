////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElements.hpp"

namespace yq::tachyon {
    UIElements::UIElements()
    {
    }
    
    UIElements::UIElements(const UIElements& cp)
    {
        for(UIElement* ui : cp.m_items){
            UIElement* ui2 = ui -> clone();
            if(ui2)
                m_items.push_back(ui2);
        }
    }
    
    UIElements::~UIElements()
    {
        for(UIElement* ui : m_items)
            delete ui;
        m_items.clear();
    }

    UIElements&    UIElements::operator<<(UIElement*p)
    {
        append(p);
        return *this;
    }

    void    UIElements::append(UIElement*p)
    {
        if(!p)
            return;
        m_items.push_back(p);
    }

    UIElements*     UIElements::clone() const 
    {
        return new UIElements(*this);
    }

    void    UIElements::content() 
    {
        render(ITEMS);
    }
    
    bool    UIElements::empty() const
    {
        return m_items.empty();
    }
    
    void    UIElements::render() 
    {
        render(ITEMS);
    }
    
    void    UIElements::render(items_k) 
    {
        for(UIElement* ui : m_items)
            ui->draw();
    }

    size_t  UIElements::size() const
    {
        return m_items.size();
    }
}
