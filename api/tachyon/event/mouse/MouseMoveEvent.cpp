////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/mouse/MouseMoveEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

namespace yq::tachyon {

    MouseMoveEvent::MouseMoveEvent(const Header& h, ModifierKeys mk, const Vector2D& pos, MouseButtons btns) :
        MouseEvent(h, mk, pos, btns)
    {
    }
    
    MouseMoveEvent::MouseMoveEvent(const MouseMoveEvent& cp, const Header& h) : MouseEvent(cp, h)
    {
    }
    
    MouseMoveEvent::~MouseMoveEvent()
    {
    }

    PostCPtr    MouseMoveEvent::clone(rebind_k, const Header&h) const
    {
        return new MouseMoveEvent(*this, h);
    }

    void MouseMoveEvent::init_info()
    {
        auto w = writer<MouseMoveEvent>();
        w.description("Mouse Move Event");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseMoveEvent)

