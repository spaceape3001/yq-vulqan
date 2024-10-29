////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseRelease.hpp"
#include <yq/tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

namespace yq::tachyon {

    MouseRelease::MouseRelease(const Param& p) : MosueEvent(p), 
        m_cursor(p.cursor),
        m_button(p.button),
        m_modifiers(p.modifiers)
    {
    }
    
    MouseRelease::~MouseRelease()
    {
    }

    bool    MouseRelease::left() const
    {
        return m_button == MouseButton::Left;
    }
    
    bool    MouseRelease::middle() const
    {
        return m_button == MouseButton::Middle;
    }

    bool    MouseRelease::right() const
    {
        return m_button == MouseButton::Right;
    }
    
    static void reg_key_press()
    {
        auto w = writer<MouseRelease>();
        w.description("Mouse Release Event");
        w.property("button", &MouseRelease::button).description("Mouse button released");
        w.property("left", &MouseRelease::left).description("TRUE if the left button was released");
        w.property("middle", &MouseRelease::middle).description("TRUE if the middle button was released");
        w.property("right", &MouseRelease::right).description("TRUE if the right button was released");
    }
    
    YQ_INVOKE(reg_key_press();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseRelease)

