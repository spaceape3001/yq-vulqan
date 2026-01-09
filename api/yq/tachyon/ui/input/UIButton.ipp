////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIButtonWriter.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIButton)

namespace yq::tachyon {
    void UIButton::init_meta()
    {
        auto w = writer<UIButton>();
        w.description("UI Button");
        w.property("size", &UIButton::m_size);
        w.property("text", &UIButton::m_text);
    }
    
    UIButton::UIButton(std::string_view text, const Size2F& size, UIFlags flags) : UIElement(flags), m_text(text), m_size(size)
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
        return dynamic_cast<UIButton*>(m_ui);
    }
    
    UIButtonWriter::UIButtonWriter(UIButton* ui) : UIElementWriter(ui)
    {
    }

}
