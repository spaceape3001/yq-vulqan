////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UITextLabel.hpp"
#include <yt/ui/MyImGui.hpp>

namespace yq::tachyon {
    UITextLabel::UITextLabel(std::string_view kString, UIFlags flags) : 
        UIElement(flags), m_text(kString)
    {
    }
    
    UITextLabel::UITextLabel(const UITextLabel& cp) : UIElement(cp), m_text(cp.m_text)
    {
    }
    
    UITextLabel::~UITextLabel()
    {
    }

    UITextLabel*  UITextLabel::clone() const 
    {
        return new UITextLabel(*this);
    }
    
    void    UITextLabel::render()  
    {
        if(!m_text.empty()){
            ImGui::TextUnformatted(m_text.c_str());
        }
    }
}
