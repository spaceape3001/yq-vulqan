////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIButton.hpp"
#include "UIButtonWriter.hpp"
#include <yt/ui/MyImGui.hpp>
#include <yt/logging.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIButton)

namespace yq::tachyon {
    void UIButton::init_info()
    {
        auto w = writer<UIButton>();
        w.description("UI Button");
    }
    
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

    ////////////////////////////
    
    UIButtonWriter::UIButtonWriter() = default;
    UIButtonWriter::UIButtonWriter(const UIButtonWriter&) = default;
    UIButtonWriter::~UIButtonWriter() = default;
    
    UIButton* UIButtonWriter::element()
    {
        return static_cast<UIButton*>(m_ui);
    }
    
    UIButtonWriter::UIButtonWriter(UIButton* ui) : UIElementWriter(ui)
    {
    }

}
