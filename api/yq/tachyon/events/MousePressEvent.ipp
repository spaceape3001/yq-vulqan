////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MousePressEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

namespace yq::tachyon {

    MousePressEvent::MousePressEvent(const Param& p) : MouseEvent(p), 
        m_button(p.button)
    {
    }
    
    MousePressEvent::~MousePressEvent()
    {
    }

    bool    MousePressEvent::left() const
    {
        return m_button == MouseButton::Left;
    }
    
    bool    MousePressEvent::middle() const
    {
        return m_button == MouseButton::Middle;
    }

    bool    MousePressEvent::right() const
    {
        return m_button == MouseButton::Right;
    }

    void MousePressEvent::init_info()
    {
        auto w = writer<MousePressEvent>();
        w.description("Mouse Press Event");
        w.property("button", &MousePressEvent::button).description("Mouse button pressed").tag(kTag_Log);
        w.property("left", &MousePressEvent::left).description("TRUE if the left button was pressed");
        w.property("middle", &MousePressEvent::middle).description("TRUE if the middle button was pressed");
        w.property("right", &MousePressEvent::right).description("TRUE if the right button was pressed");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MousePressEvent)

