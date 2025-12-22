////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaInputBarUI.hpp"
#include "LuaInputBarUIWriter.hpp"
#include <yq/luavk/request/LuaExecuteStringRequest.hpp>
#include <yq/tachyon/api/Payload.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaInputBarUI)

namespace yq::tachyon {
    void LuaInputBarUI::init_meta()
    {
        auto w = writer<LuaInputBarUI>();
        w.description("Lua Input Bar");
    }

    LuaInputBarUI::LuaInputBarUI(UIFlags flags) : 
        UIElement(flags|UIFlag::EnterReturnsTrue), 
        m_label("##lua"), m_imFlags(ImGui::TextFlags(flags))
    {
        capacity(SET, 63);
        update(FLAGS);
    }
    
    LuaInputBarUI::LuaInputBarUI(const LuaInputBarUI&cp) : 
        UIElement(cp), m_label(cp.m_label), m_text(cp.m_text), m_imFlags(cp.m_imFlags)
    {
        // NOTE, we're not cloning the TVM ID as that could easily be different
    }
    
    LuaInputBarUI::~LuaInputBarUI()
    {
    }
    
    
    size_t       LuaInputBarUI::capacity() const 
    { 
        if(m_text.empty())
            return 0;
        return m_text.size() - 1;
    }

    void         LuaInputBarUI::capacity(set_k, size_t n)
    {
        m_text.clear();
        m_text.resize(n+1, '\0');
    }

    void            LuaInputBarUI::clear()
    {
        if(!m_text.empty())
            m_text[0]   = '\0';
    }

    LuaInputBarUI*    LuaInputBarUI::clone() const
    {
        return new LuaInputBarUI(*this);
    }

    void    LuaInputBarUI::label(set_k, std::string_view v)
    {
        m_label = std::string(v);
    }

    void            LuaInputBarUI::render()
    {
        if(ImGui::InputText(m_label.c_str(), m_text.data(), m_text.size(), m_imFlags))
            triggered();
        ImGui::SameLine();
        if(ImGui::Button("Submit"))
            triggered();
        ImGui::SameLine();
        if(ImGui::Button("Clear"))
            clear();
    }

    std::string_view LuaInputBarUI::text() const
    {
        return std::string_view( m_text.data() );
    }

    void             LuaInputBarUI::text(set_k, std::string_view v)
    {
        if(v.empty())
            return ;
        if(m_text.empty())
            return ;
        size_t  n   = std::min((size_t) m_text.size()-1, v.size());
        memcpy(m_text.data(), v.data(), n);
        m_text[n]   = '\0';
    }

    const char*      LuaInputBarUI::title() const 
    {
        return m_label.c_str();
    }

    void            LuaInputBarUI::triggered() 
    {
        if(m_tvm){
            send(new LuaExecuteStringRequest({.target=m_tvm}, text()));
        } else if(actions(HAS)){
            tachyon::Payload pay;
            pay.m_arguments.push_back(Any(text()));
            triggered(std::move(pay));
        }
        clear();
    }

    void            LuaInputBarUI::tvm(set_k, tachyon::TypedID tid)
    {
        m_tvm       = tid;
    }

    void            LuaInputBarUI::update(flags_k) 
    {
        UIElement::update(FLAGS);
        m_imFlags   = ImGui::TextFlags(m_flags);
    }


    ////////////////////////////
    
    LuaInputBarUIWriter::LuaInputBarUIWriter() = default;
    LuaInputBarUIWriter::LuaInputBarUIWriter(const LuaInputBarUIWriter&) = default;
    LuaInputBarUIWriter::~LuaInputBarUIWriter() = default;
    
    LuaInputBarUI* LuaInputBarUIWriter::element()
    {
        return static_cast<LuaInputBarUI*>(m_ui);
    }
    
    LuaInputBarUIWriter::LuaInputBarUIWriter(LuaInputBarUI* ui) : tachyon::UIElementWriter(ui)
    {
    }

}

