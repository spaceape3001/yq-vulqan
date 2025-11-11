////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/mouse/MouseLeaveEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

namespace yq::tachyon {

    MouseLeaveEvent::MouseLeaveEvent(const Header& h, ModifierKeys mk, const Vector2D& pos, MouseButtons btns) :
        MouseEvent(h, mk, pos, btns)
    {
    }
    
    MouseLeaveEvent::MouseLeaveEvent(const MouseLeaveEvent& cp, const Header& h) : MouseEvent(cp, h)
    {
    }
    
    MouseLeaveEvent::~MouseLeaveEvent()
    {
    }

    PostCPtr    MouseLeaveEvent::clone(rebind_k, const Header&h) const
    {
        return new MouseLeaveEvent(*this, h);
    }

    void MouseLeaveEvent::init_meta()
    {
        auto w = writer<MouseLeaveEvent>();
        w.description("Mouse Leave Event");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseLeaveEvent)

