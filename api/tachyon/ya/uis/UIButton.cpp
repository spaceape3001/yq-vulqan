////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIButton.hpp"
#include <yt/ui/MyImGui.hpp>
#include <yt/logging.hpp>

namespace yq::tachyon {
    UIButton::UIButton(std::string_view text, const Vector2F& size) : m_text(text), m_size(size)
    {
    }
    
    UIButton::UIButton(const UIButton& cp) : UIElement(cp), m_text(cp.m_text), m_size(cp.m_size)
    {
    }
    
    UIButton::~UIButton()
    {
    }
    
    void            UIButton::render()
    {
        if(ImGui::Button(m_text.c_str(), m_size)){
            triggered();
        }
    }
    
    void            UIButton::triggered()
    {
        content();
    }
    
    UIButton*       UIButton::clone() const
    {
        return new UIButton(*this);
    }
    
    const char*     UIButton::title() const
    {
        return m_text.c_str();
    }
}
