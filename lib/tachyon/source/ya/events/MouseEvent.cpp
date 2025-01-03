////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/MouseEvent.hpp>

#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseEvent)

namespace yq::tachyon {
    
    MouseEventInfo::MouseEventInfo(std::string_view zName, InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::MOUSE);
    }

    ////////////////////////////////////////////////////////////////////////////

    MouseEvent::MouseEvent(Window* w, const Param& p) : InputEvent(w, p), m_position(p.position), m_buttons(p.buttons)
    {
    }
    
    MouseEvent::MouseEvent(WindowID w, const Param& p) : InputEvent(w, p), m_position(p.position), m_buttons(p.buttons)
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
        w.property("position", &MouseEvent::position).description("Mouse (cursor) position");
        w.property("buttons", &MouseEvent::buttons).description("Currently pressed mouse buttons");
        w.property("left", &MouseEvent::left_button).description("State of Mouse's left button").tag(kTag_Log);
        w.property("middle", &MouseEvent::middle_button).description("State of Mouse's button button").tag(kTag_Log);
        w.property("right", &MouseEvent::right_button).description("State of Mouse's right button").tag(kTag_Log);
    }
}
