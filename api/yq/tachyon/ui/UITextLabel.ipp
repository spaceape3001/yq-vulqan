////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UITextLabelWriter.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UITextLabel)

namespace yq::tachyon {
    void UITextLabel::init_meta()
    {
        auto w = writer<UITextLabel>();
        w.description("UI Text Label");
    }

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

    ////////////////////////////

    UITextLabelWriter::UITextLabelWriter() = default;
    UITextLabelWriter::UITextLabelWriter(const UITextLabelWriter&) = default;
    UITextLabelWriter::~UITextLabelWriter() = default;

    UITextLabel* UITextLabelWriter::element()
    {
        return static_cast<UITextLabel*>(m_ui);
    }
    
    UITextLabelWriter::UITextLabelWriter(UITextLabel* ui) : UIElementWriter(ui)
    {
    }
}
