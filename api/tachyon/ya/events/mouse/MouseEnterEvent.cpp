////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/mouse/MouseEnterEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

namespace yq::tachyon {

    MouseEnterEvent::MouseEnterEvent(const Header& h, ModifierKeys mk, const Vector2D& pos, MouseButtons btns) :
        MouseEvent(h, mk, pos, btns)
    {
    }
    
    MouseEnterEvent::MouseEnterEvent(const MouseEnterEvent& cp, const Header& h) : MouseEvent(cp, h)
    {
    }
    
    MouseEnterEvent::~MouseEnterEvent()
    {
    }

    PostCPtr    MouseEnterEvent::clone(rebind_k, const Header&h) const
    {
        return new MouseEnterEvent(*this, h);
    }

    void MouseEnterEvent::init_info()
    {
        auto w = writer<MouseEnterEvent>();
        w.description("Mouse Enter Event");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseEnterEvent)

