////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/MouseEvent.hpp>

#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseEvent)

namespace yq::tachyon {

    MouseEvent::MouseEvent(const Header& h, ModifierKeys mk, const Vector2D& pos, MouseButtons btns) : 
        InputEvent(h, mk), m_position(pos), m_buttons(btns)
    {
    }
    
    MouseEvent::MouseEvent(const MouseEvent& cp, const Header&h) : 
        InputEvent(cp, h), m_position(cp.m_position), m_buttons(cp.m_buttons)
    {
    }
    
    MouseEvent::~MouseEvent()
    {
    }

    bool    MouseEvent::left_button() const
    {
        return m_buttons(MouseButton::Left);
    }
    
    bool    MouseEvent::right_button() const
    {
        return m_buttons(MouseButton::Right);
    }
    
    bool    MouseEvent::middle_button() const
    {
        return m_buttons(MouseButton::Middle);
    }

    ////////////////////////////////////////////////////////////////////////////

    void MouseEvent::init_info()
    {
        auto w = writer<MouseEvent>();
        w.description("Mouse event base class");
        w.property("x", &MouseEvent::x).description("Mouse (cursor) X position").tag(kTag_Log);
        w.property("y", &MouseEvent::y).description("Mouse (cursor) Y position").tag(kTag_Log);
        w.property("position", &MouseEvent::m_position).description("Mouse (cursor) position").tag(kTag_Save);
        w.property("buttons", &MouseEvent::m_buttons).description("Currently pressed mouse buttons").tag(kTag_Save);
        w.property("left", &MouseEvent::left_button).description("State of Mouse's left button").tag(kTag_Log);
        w.property("middle", &MouseEvent::middle_button).description("State of Mouse's button button").tag(kTag_Log);
        w.property("right", &MouseEvent::right_button).description("State of Mouse's right button").tag(kTag_Log);
    }
}
