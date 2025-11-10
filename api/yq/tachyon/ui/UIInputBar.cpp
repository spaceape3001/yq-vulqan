////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIInputBar.hpp"
#include <yq/tachyon/ui/UIInputBarWriter.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/tachyon/api/Payload.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIInputBar)

namespace yq::tachyon {
    void UIInputBar::init_meta()
    {
        auto w = writer<UIInputBar>();
        w.description("UI CheckBox");
        w.property("label", &UIInputBar::m_label);
    }
    
    UIInputBar::UIInputBar(std::string_view title_, UIFlags flags) : UIWindow(title_, flags | UIFlag::EnterReturnsTrue)
    {
        m_label     = "##Input";
        capacity(SET, 63);
        update(FLAGS);
    }
    
    UIInputBar::UIInputBar(const UIInputBar& cp) : UIWindow(cp)
    {
        m_label     = cp.m_label;
        m_text      = cp.m_text;
        update(FLAGS);
    }
    
    UIInputBar::~UIInputBar()
    {
    }
    
    size_t       UIInputBar::capacity() const
    {
        if(m_text.empty())
            return 0;
        return m_text.size() - 1;
    }

    void         UIInputBar::capacity(set_k, size_t n)
    {
        m_text.clear();
        m_text.resize(n+1, '\0');
    }

    UIInputBar*     UIInputBar::clone() const 
    {
        return new UIInputBar(*this);
    }

    void    UIInputBar::content()
    {
        if(ImGui::InputText(m_label.c_str(), m_text.data(), m_text.size(), m_imFlags))  // and more....
            triggered();
        ImGui::SameLine();
        if(ImGui::Button("Submit"))
            triggered();
        ImGui::SameLine();
        if(ImGui::Button("Clear"))
            m_text[0] = '\0';
    }

    void    UIInputBar::label(set_k, std::string_view v)
    {
        m_label = std::string(v);
    }


    std::string_view UIInputBar::text() const
    {
        return std::string_view( m_text.data() );
    }

    void             UIInputBar::text(set_k, std::string_view v)
    {
        if(v.empty())
            return ;
        if(m_text.empty())
            return ;
        size_t  n   = std::min((size_t) m_text.size()-1, v.size());
        memcpy(m_text.data(), v.data(), n);
        m_text[n]   = '\0';
    }

    const char*      UIInputBar::title() const 
    {
        return m_label.c_str();
    }

    void            UIInputBar::triggered() 
    {
        if(!actions(HAS))
            return ;
            
        Payload pay;
        pay.m_arguments.push_back(Any(text()));
        triggered(std::move(pay));
        m_text [0] = '\0';
    }

    void            UIInputBar::update(flags_k) 
    {
        UIElement::update(FLAGS);
        m_imFlags   = ImGui::TextFlags(m_flags);
    }


    ////////////////////////////
    
    UIInputBarWriter::UIInputBarWriter() = default;
    UIInputBarWriter::UIInputBarWriter(const UIInputBarWriter&) = default;
    UIInputBarWriter::~UIInputBarWriter() = default;
    
    UIInputBar* UIInputBarWriter::element()
    {
        return static_cast<UIInputBar*>(m_ui);
    }
    
    UIInputBarWriter::UIInputBarWriter(UIInputBar* ui) : UIWindowWriter(ui)
    {
    }

    UIInputBarWriter   UIInputBarWriter::capacity(size_t n)
    {
        if(UIInputBar* li = element())
            li -> capacity(SET, n);
        return *this;
    }

    UIInputBarWriter   UIInputBarWriter::label(std::string_view v)
    {
        if(UIInputBar* li = element())
            li -> label(SET, v);
        return *this;
    }
}
