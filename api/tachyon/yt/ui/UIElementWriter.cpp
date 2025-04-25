////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIElement.hpp"
#include "UIElementWriter.hpp"
#include <tachyon/api/Action.hpp>
#include <tachyon/action/VisibleUIAction.hpp>
#include <yt/logging.hpp>

namespace yq::tachyon {
    UIElementWriter::UIElementWriter(UIElement* ui) : m_ui(ui) {}

    UIElementWriter::UIElementWriter() = default;
    UIElementWriter::UIElementWriter(const UIElementWriter&) = default;
    UIElementWriter::~UIElementWriter() = default;

    UIElementWriter  UIElementWriter::action(ActionCPtr act)
    {
        if(act && m_ui)
            m_ui->m_actions.push_back(act);
        return *this;
    }

    UIElementWriter UIElementWriter::action(visible_k, UIElement*elem)
    {
        if(!elem)
            return *this;
        action(new VisibleUIAction(elem->binding(CREATE)));
        return *this;
    }
    
    UIElementWriter UIElementWriter::action(visible_k, UIElementWriter& elem)
    {
        return action(VISIBLE, elem.element());
    }
    
    //UIElementWriter UIElementWriter::action(visible_k, std::initializer_list<UIElement*>);
    //UIElementWriter UIElementWriter::action(visible_k, std::initializer_list<UIElementWriter&>);
    UIElementWriter UIElementWriter::action(visible_k, const std::string& k)
    {
        action(new VisibleUIAction(k));
        return *this;
    }

    UIElementWriter  UIElementWriter::flag(clear_k, UIFlag v)
    {
        if(m_ui)
            m_ui->flag(CLEAR, v);
        return *this;
    }
    
    UIElementWriter  UIElementWriter::flag(set_k, UIFlag v)
    {
        if(m_ui)
            m_ui->flag(SET, v);
        return *this;
    }
    
    UIElementWriter  UIElementWriter::flags(clear_k, UIFlags v)
    {
        if(m_ui)
            m_ui->flags(CLEAR, v);
        return *this;
    }

    UIElementWriter  UIElementWriter::flags(set_k, UIFlags v)
    {
        if(m_ui)
            m_ui->flags(SET, v);
        return *this;
    }
    
    UIElementWriter UIElementWriter::uid(std::string_view k)
    {
        if(m_ui)
            m_ui -> m_uId   = std::string(k);
        return *this;
    }
}
