////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/mouse/MouseScrollEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {

    MouseScrollEvent::MouseScrollEvent(const Header&h, ModifierKeys mk, const Vector2D& pos, MouseButtons btns, const Vector2D& delta)
        : MouseEvent(h, mk, pos, btns), m_delta(delta)
    {
    }
    
    MouseScrollEvent::MouseScrollEvent(const MouseScrollEvent& cp, const Header&h) : 
        MouseEvent(cp, h), m_delta(cp.m_delta)
    {
    }
    
    MouseScrollEvent::~MouseScrollEvent()
    {
    }

    PostCPtr    MouseScrollEvent::clone(rebind_k, const Header& h) const 
    {
        return new MouseScrollEvent(*this, h);
    }

    void MouseScrollEvent::init_meta()
    {
        auto w = writer<MouseScrollEvent>();
        w.description("Mouse Scroll Event");
        w.property("delta", &MouseScrollEvent::m_delta).tag(kTag_Save);
        w.property("dx", &MouseScrollEvent::delta_x).tag(kTag_Log);
        w.property("dy", &MouseScrollEvent::delta_y).tag(kTag_Log);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseScrollEvent)

