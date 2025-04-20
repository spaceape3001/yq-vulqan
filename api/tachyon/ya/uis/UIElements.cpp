////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElements.hpp"
#include <yq/container/reverse.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIElements)

namespace yq::tachyon {
    void UIElements::init_info() 
    {
        auto w = writer<UIElements>();
        w.description("Collection of child UI elements");
    }

    UIElements::UIElements(UIFlags flags) : UIElement(flags)
    {
    }
    
    UIElements::UIElements(const UIElements& cp) : UIElement(cp)
    {
        for(UIElement* ui : cp.m_items){
            UIElement* ui2 = ui -> copy();
            if(ui2){
                ui2->m_parent   = this;
                m_items.push_back(ui2);
            }
        }
    }
    
    UIElements::~UIElements()
    {
        for(UIElement* ui : m_items){
            ui->m_parent = nullptr;
            delete ui;
        }
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
        if(is_accept(acceptable(p))){
            m_items.push_back(p);
            postadd(p);
        } else {
            delete p;
        }
    }

    UIElements*     UIElements::clone() const 
    {
        return new UIElements(*this);
    }

    UIElements* UIElements::copy() const 
    { 
        return static_cast<UIElements*>(UIElement::copy()); 
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
        if(m_flags(UIFlag::Reverse)){
            if(m_flags(UIFlag::Horizontal)){
                for(UIElement* ui : reverse(m_items)){
                    if(!ui) [[unlikely]]
                        continue;
                    ImGui::SameLine();
                    ui->draw();
                }
            } else {
                for(UIElement* ui : reverse(m_items)){
                    if(!ui) [[unlikely]]
                        continue;
                    ui->draw();
                }
            }
        } else {
            if(m_flags(UIFlag::Horizontal)){
                for(UIElement* ui : m_items){
                    if(!ui) [[unlikely]]
                        continue;
                    ImGui::SameLine();
                    ui->draw();
                }
            } else {
                for(UIElement* ui : m_items){
                    if(!ui) [[unlikely]]
                        continue;
                    ui->draw();
                }
            }
        }
    }

    size_t  UIElements::size() const
    {
        return m_items.size();
    }
}
