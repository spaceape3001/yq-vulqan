////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseReleaseEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

namespace yq::tachyon {

    MouseReleaseEvent::MouseReleaseEvent(const Param& p) : MouseEvent(p), 
        m_button(p.button)
    {
    }
    
    MouseReleaseEvent::~MouseReleaseEvent()
    {
    }

    bool    MouseReleaseEvent::left() const
    {
        return m_button == MouseButton::Left;
    }
    
    bool    MouseReleaseEvent::middle() const
    {
        return m_button == MouseButton::Middle;
    }

    bool    MouseReleaseEvent::right() const
    {
        return m_button == MouseButton::Right;
    }
    
    void MouseReleaseEvent::init_info()
    {
        auto w = writer<MouseReleaseEvent>();
        w.description("Mouse Release Event");
        w.property("button", &MouseReleaseEvent::button).description("Mouse button released");
        w.property("left", &MouseReleaseEvent::left).description("TRUE if the left button was released");
        w.property("middle", &MouseReleaseEvent::middle).description("TRUE if the middle button was released");
        w.property("right", &MouseReleaseEvent::right).description("TRUE if the right button was released");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseReleaseEvent)

