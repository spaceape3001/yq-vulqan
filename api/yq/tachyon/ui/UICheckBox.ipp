////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UICheckBox.hpp"
#include "UICheckBoxWriter.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/tachyon/api/Payload.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UICheckBox)

namespace yq::tachyon {
    void UICheckBox::init_meta()
    {
        auto w = writer<UICheckBox>();
        w.description("UI CheckBox");
        w.property("text", &UICheckBox::m_text);
    }
    
    UICheckBox::UICheckBox(std::string_view text, UIFlags flags) : UIElement(flags), m_text(text)
    {
    }
    
    UICheckBox::UICheckBox(const UICheckBox& cp) : UIElement(cp), m_text(cp.m_text)
    {
    }
    
    UICheckBox::~UICheckBox()
    {
    }
    
    bool            UICheckBox::checked() const 
    { 
        return get(); 
    }

    void            UICheckBox::render()
    {
        bool    value   = get();
        if(ImGui::Checkbox(m_text.c_str(), &value)){
            set(value);
            if(!m_actions.empty()){
                Payload payload;
                payload << value;
                UIElement::triggered(payload);
            }
        }
    }
    
    const char*     UICheckBox::title() const
    {
        return m_text.c_str();
    }

    ////////////////////////////
    
    UICheckBoxWriter::UICheckBoxWriter() = default;
    UICheckBoxWriter::UICheckBoxWriter(const UICheckBoxWriter&) = default;
    UICheckBoxWriter::~UICheckBoxWriter() = default;
    
    UICheckBox* UICheckBoxWriter::element()
    {
        return static_cast<UICheckBox*>(m_ui);
    }
    
    UICheckBoxWriter::UICheckBoxWriter(UICheckBox* ui) : UIElementWriter(ui)
    {
    }

}
