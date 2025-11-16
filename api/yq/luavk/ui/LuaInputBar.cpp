////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaInputBar.hpp"
#include "LuaInputBarWriter.hpp"
#include <yq/tachyon/api/Payload.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/luavk/request/LuaExecuteStringRequest.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::LuaInputBar)

namespace yq::lua {
    void LuaInputBar::init_meta()
    {
        auto w = writer<LuaInputBar>();
        w.description("Lua Input Bar");
    }

    LuaInputBar::LuaInputBar(tachyon::UIFlags flags) : 
        tachyon::UIElement(flags|tachyon::UIFlag::EnterReturnsTrue), 
        m_label("##lua"), m_imFlags(ImGui::TextFlags(flags))
    {
        capacity(SET, 63);
        update(FLAGS);
    }
    
    LuaInputBar::LuaInputBar(const LuaInputBar&cp) : 
        tachyon::UIElement(cp), m_label(cp.m_label), m_text(cp.m_text), m_imFlags(cp.m_imFlags)
    {
        // NOTE, we're not cloning the TVM ID as that could easily be different
    }
    
    LuaInputBar::~LuaInputBar()
    {
    }
    
    
    size_t       LuaInputBar::capacity() const 
    { 
        if(m_text.empty())
            return 0;
        return m_text.size() - 1;
    }

    void         LuaInputBar::capacity(set_k, size_t n)
    {
        m_text.clear();
        m_text.resize(n+1, '\0');
    }

    void            LuaInputBar::clear()
    {
        if(!m_text.empty())
            m_text[0]   = '\0';
    }

    LuaInputBar*    LuaInputBar::clone() const
    {
        return new LuaInputBar(*this);
    }

    void    LuaInputBar::label(set_k, std::string_view v)
    {
        m_label = std::string(v);
    }

    void            LuaInputBar::render()
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

    std::string_view LuaInputBar::text() const
    {
        return std::string_view( m_text.data() );
    }

    void             LuaInputBar::text(set_k, std::string_view v)
    {
        if(v.empty())
            return ;
        if(m_text.empty())
            return ;
        size_t  n   = std::min((size_t) m_text.size()-1, v.size());
        memcpy(m_text.data(), v.data(), n);
        m_text[n]   = '\0';
    }

    const char*      LuaInputBar::title() const 
    {
        return m_label.c_str();
    }

    void            LuaInputBar::triggered() 
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

    void            LuaInputBar::tvm(set_k, tachyon::TypedID tid)
    {
        m_tvm       = tid;
    }

    void            LuaInputBar::update(flags_k) 
    {
        UIElement::update(FLAGS);
        m_imFlags   = ImGui::TextFlags(m_flags);
    }


    ////////////////////////////
    
    LuaInputBarWriter::LuaInputBarWriter() = default;
    LuaInputBarWriter::LuaInputBarWriter(const LuaInputBarWriter&) = default;
    LuaInputBarWriter::~LuaInputBarWriter() = default;
    
    LuaInputBar* LuaInputBarWriter::element()
    {
        return static_cast<LuaInputBar*>(m_ui);
    }
    
    LuaInputBarWriter::LuaInputBarWriter(LuaInputBar* ui) : tachyon::UIElementWriter(ui)
    {
    }

}

