////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElements.hpp"
#include "UIElementsWriter.hpp"
#include <yq/container/reverse.hpp>
#include <yt/ui/MyImGui.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>
#include <yt/ui/Widget.hpp>

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
        m_items.push_back(p);
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

    ////////////////////////////

    UIElements*   UIElementsWriter::attach(Widget* w)
    {
        if(!w)
            return nullptr;
        if(w->m_ui)
            return dynamic_cast<UIElements*>(w->m_ui);
        UIElements*ret   = new UIElements;
        w->m_ui = ret;
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
        if(elem && m_ui){
            static_cast<UIElements*>(m_ui) -> m_items.push_back(elem);
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
}
