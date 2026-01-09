////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UILineInputWriter.hpp"
#include <yq/tachyon/api/Payload.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UILineInput)

namespace yq::tachyon {
    void UILineInput::init_meta()
    {
        auto w = writer<UILineInput>();
        w.description("UI Line Input");
        w.property("label", &UILineInput::m_label);
    }
    
    UILineInput::UILineInput(std::string_view label_, UIFlags flags) : UIElement(flags | UIFlag::EnterReturnsTrue), m_label(label_)
    {
        capacity(SET, 63);
        update(FLAGS);
    }
    
    UILineInput::UILineInput(const UILineInput& cp) : UIElement(cp), m_label(cp.m_label)
    {
        m_text      = cp.m_text;
        update(FLAGS);
    }
    
    UILineInput::~UILineInput()
    {
    }
    
    size_t       UILineInput::capacity() const 
    { 
        if(m_text.empty())
            return 0;
        return m_text.size() - 1;
    }

    void         UILineInput::capacity(set_k, size_t n)
    {
        m_text.clear();
        m_text.resize(n+1, '\0');
    }

    UILineInput*     UILineInput::clone() const 
    {
        return new UILineInput(*this);
    }

    void    UILineInput::label(set_k, std::string_view v)
    {
        m_label = std::string(v);
    }

    void    UILineInput::render()
    {
        if(ImGui::InputText(m_label.c_str(), m_text.data(), m_text.size(), m_imFlags))
            triggered();
    }

    std::string_view UILineInput::text() const
    {
        return std::string_view( m_text.data() );
    }

    void             UILineInput::text(set_k, std::string_view v)
    {
        if(v.empty())
            return ;
        if(m_text.empty())
            return ;
        size_t  n   = std::min((size_t) m_text.size()-1, v.size());
        memcpy(m_text.data(), v.data(), n);
        m_text[n]   = '\0';
    }

    const char*      UILineInput::title() const 
    {
        return m_label.c_str();
    }

    void            UILineInput::triggered() 
    {
        if(!actions(HAS))
            return ;
        Payload pay;
        pay.m_arguments.push_back(Any(text()));
        triggered(std::move(pay));
    }

    void            UILineInput::update(flags_k) 
    {
        UIElement::update(FLAGS);
        m_imFlags   = ImGui::TextFlags(m_flags);
    }


    ////////////////////////////
    
    UILineInputWriter::UILineInputWriter() = default;
    UILineInputWriter::UILineInputWriter(const UILineInputWriter&) = default;
    UILineInputWriter::~UILineInputWriter() = default;
    
    UILineInput* UILineInputWriter::element()
    {
        return static_cast<UILineInput*>(m_ui);
    }
    
    UILineInputWriter::UILineInputWriter(UILineInput* ui) : UIElementWriter(ui)
    {
    }

    UILineInputWriter   UILineInputWriter::capacity(uint16_t n)
    {
        if(UILineInput* li = element())
            li -> capacity(SET, n);
        return *this;
    }

    UILineInputWriter   UILineInputWriter::label(std::string_view v)
    {
        if(UILineInput* li = element())
            li -> label(SET, v);
        return *this;
    }
}
