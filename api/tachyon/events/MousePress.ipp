////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MousePress.hpp"
#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {

    MousePress::MousePress(const Param& p) : MosueEvent(p), 
        m_cursor(p.cursor),
        m_button(p.button),
        m_modifiers(p.modifiers)
    {
    }
    
    MousePress::~MousePress()
    {
    }

    bool    MousePress::left() const
    {
        return m_button == MouseButton::Left;
    }
    
    bool    MousePress::middle() const
    {
        return m_button == MouseButton::Middle;
    }

    bool    MousePress::right() const
    {
        return m_button == MouseButton::Right;
    }
    
    static void reg_key_press()
    {
        auto w = writer<MousePress>();
        w.description("Mouse Press Event");
        w.property("button", &MousePress::button).description("Mouse button pressed");
        w.property("left", &MousePress::left).description("TRUE if the left button was pressed");
        w.property("middle", &MousePress::middle).description("TRUE if the middle button was pressed");
        w.property("right", &MousePress::right).description("TRUE if the right button was pressed");
    }
    
    YQ_INVOKE(reg_key_press();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MousePress)

