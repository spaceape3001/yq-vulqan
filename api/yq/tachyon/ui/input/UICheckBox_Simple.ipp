////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UICheckBox_Simple.hpp"
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UICheckBox_Simple)

namespace yq::tachyon {
    UICheckBox_Simple::UICheckBox_Simple(std::string_view kText, bool value, UIFlags flags) : UICheckBox(kText, flags), m_state(value)
    {
    }
    
    UICheckBox_Simple::UICheckBox_Simple(const UICheckBox_Simple& cp) : UICheckBox(cp), m_state(cp.m_state)
    {
    }
    
    UICheckBox_Simple::~UICheckBox_Simple()
    {
    }
    
    UICheckBox_Simple* UICheckBox_Simple::clone() const 
    {
        return new UICheckBox_Simple(*this);
    }
    
    void    UICheckBox_Simple::set(bool v)  
    {
        m_state = v;
    }

    void UICheckBox_Simple::init_meta()
    {
        auto w = writer<UICheckBox_Simple>();
        w.description("Simple Stateful UI Checkbox");
        w.property("checked", &UICheckBox_Simple::m_state);
    }
}
