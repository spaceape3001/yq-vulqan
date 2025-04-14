////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElement.hpp"
#include "UIElementWriter.hpp"
#include <yt/api/Action.hpp>

namespace yq::tachyon {
    UIElementWriter::UIElementWriter(UIElement* ui) : m_ui(ui) {}

    UIElementWriter::UIElementWriter() = default;
    UIElementWriter::UIElementWriter(const UIElementWriter&) = default;
    UIElementWriter::~UIElementWriter() = default;

    UIElementWriter  UIElementWriter::action(Action*act)
    {
        if(act){
            if(m_ui){
                m_ui->m_actions.push_back(act);
            } else {
                delete act;
            }
        }
        return *this;
    }

    UIElementWriter  UIElementWriter::flag(set_k, UIFlag v)
    {
        if(m_ui)
            m_ui->flag(SET, v);
        return *this;
    }
    
    UIElementWriter  UIElementWriter::flag(set_k, UIFlags v)
    {
        if(m_ui)
            m_ui->flag(SET, v);
        return *this;
    }
    
    UIElementWriter  UIElementWriter::flag(clear_k, UIFlag v)
    {
        if(m_ui)
            m_ui->flag(CLEAR, v);
        return *this;
    }
    
    UIElementWriter  UIElementWriter::flag(clear_k, UIFlags v)
    {
        if(m_ui)
            m_ui->flag(CLEAR, v);
        return *this;
    }

    UIElementWriter UIElementWriter::uid(std::string_view k)
    {
        if(m_ui)
            m_ui -> m_uId   = std::string(k);
        return *this;
    }
}
