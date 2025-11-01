////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/mouse/MousePressEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {

    MousePressEvent::MousePressEvent(const Header& h, ModifierKeys mk, const Vector2D& pos, MouseButtons btns, MouseButton btn) :
        MouseEvent(h, mk, pos, btns), m_button(btn)
    {
    }
    
    MousePressEvent::MousePressEvent(const MousePressEvent& cp, const Header&h) : MouseEvent(cp, h), m_button(cp.m_button)
    {
    }
    
    MousePressEvent::~MousePressEvent()
    {
    }

    PostCPtr    MousePressEvent::clone(rebind_k, const Header& h) const 
    {
        return new MousePressEvent(*this, h);
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


    void MousePressEvent::init_meta()
    {
        auto w = writer<MousePressEvent>();
        w.description("Mouse Press Event");
        w.property("button", &MousePressEvent::m_button).description("Mouse button pressed").tag(kTag_Log).tag(kTag_Save);
        w.property("left", &MousePressEvent::left).description("TRUE if the left button was pressed");
        w.property("middle", &MousePressEvent::middle).description("TRUE if the middle button was pressed");
        w.property("right", &MousePressEvent::right).description("TRUE if the right button was pressed");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MousePressEvent)

