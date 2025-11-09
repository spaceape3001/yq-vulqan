////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UILineInput.hpp"
#include <yq/tachyon/ui/UILineInputWriter.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/tachyon/api/Payload.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UILineInput)

namespace yq::tachyon {
    void UILineInput::init_meta()
    {
        auto w = writer<UILineInput>();
        w.description("UI CheckBox");
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
        m_max       = cp.m_max;
        m_size      = 0;
        update(FLAGS);
    }
    
    UILineInput::~UILineInput()
    {
    }
    
    void         UILineInput::capacity(set_k, uint16_t n)
    {
        m_max       = n;
        m_text.clear();
        m_text.resize(n+1, '\0');
        m_size      = 0;
       
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
        if(ImGui::InputText(m_label.c_str(), m_text.data(), m_max+1, m_imFlags)){  // and more....
            triggered();
        }
    }

    std::string_view UILineInput::text() const
    {
        return std::string_view( m_text.data(), m_size );
    }

    void             UILineInput::text(set_k, std::string_view v)
    {
        if(v.empty()){
            m_size  = 0;
            return ;
        }
        size_t  n   = std::min((size_t) m_max, v.size());
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
