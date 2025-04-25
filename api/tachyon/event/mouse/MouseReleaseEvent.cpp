////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/mouse/MouseReleaseEvent.hpp>
#include <tachyon/api/EventInfoWriter.hpp>

namespace yq::tachyon {

    MouseReleaseEvent::MouseReleaseEvent(const Header& h, ModifierKeys mk, const Vector2D& pos, MouseButtons btns, MouseButton btn) :
        MouseEvent(h, mk, pos, btns), m_button(btn)
    {
    }
    
    MouseReleaseEvent::MouseReleaseEvent(const MouseReleaseEvent& cp, const Header& h) : MouseEvent(cp, h), m_button(cp.m_button)
    {
    }

    MouseReleaseEvent::~MouseReleaseEvent()
    {
    }

    PostCPtr    MouseReleaseEvent::clone(rebind_k, const Header& h) const 
    {
        return new MouseReleaseEvent(*this, h);
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
        w.property("button", &MouseReleaseEvent::m_button).description("Mouse button released").tag(kTag_Log).tag(kTag_Save);
        w.property("left", &MouseReleaseEvent::left).description("TRUE if the left button was released");
        w.property("middle", &MouseReleaseEvent::middle).description("TRUE if the middle button was released");
        w.property("right", &MouseReleaseEvent::right).description("TRUE if the right button was released");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseReleaseEvent)

