////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UICheckBox_Visible.hpp"
#include <yt/ui/UIElementInfoWriter.hpp>
#include <yt/ui/Widget.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UICheckBox_Visible)

namespace yq::tachyon {
    UICheckBox_Visible::UICheckBox_Visible(std::string_view text, uint64_t id, UIFlags flags) : 
        UICheckBox(text, flags), m_uiElementID(id)
    {
    }
    
    UICheckBox_Visible::UICheckBox_Visible(const UICheckBox_Visible& cp) : 
        UICheckBox(cp), m_uiElementID(cp.m_uiElementID)
    {
    }
    
    UICheckBox_Visible::~UICheckBox_Visible()
    {
    }
    
    UICheckBox_Visible* UICheckBox_Visible::clone() const 
    {
        return new UICheckBox_Visible(*this);
    }
    
    bool                UICheckBox_Visible::get() const
    {
        Widget* w   = widget();
        if(!w)
            return false;
        UIElement*  elem    = w->element(FIRST, m_uiElementID);
        if(!elem)
            return false;
        return !(elem -> flag(UIFlag::Invisible));
    }
    
    void                UICheckBox_Visible::set(bool v)
    {
        Widget* w   = widget();
        if(!w)
            return;
        UIElement*  elem    = w->element(FIRST, m_uiElementID);
        if(!elem)
            return;
        elem -> flag(SET, UIFlag::Invisible, !v);
    }
    
    void UICheckBox_Visible::init_info()
    {
        auto w = writer<UICheckBox_Visible>();
        w.description("UI Element Visibility Checkbox");
    }
}
