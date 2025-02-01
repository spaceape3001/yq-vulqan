////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/MouseMoveEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

namespace yq::tachyon {

    MouseMoveEvent::MouseMoveEvent(Window* w, const Param& p) : MouseEvent(w, p)
    {
    }
    
    MouseMoveEvent::MouseMoveEvent(WindowID w, const Param& p) : MouseEvent(w, p)
    {
    }

    MouseMoveEvent::~MouseMoveEvent()
    {
    }

    void MouseMoveEvent::init_info()
    {
        auto w = writer<MouseMoveEvent>();
        w.description("Mouse Move Event");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseMoveEvent)

