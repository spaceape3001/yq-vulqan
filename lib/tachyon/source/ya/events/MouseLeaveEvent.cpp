////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/MouseLeaveEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

namespace yq::tachyon {

    MouseLeaveEvent::MouseLeaveEvent(Window* w, const Param& p) : MouseEvent(w, p)
    {
    }
    
    MouseLeaveEvent::MouseLeaveEvent(WindowID w, const Param& p) : MouseEvent(w, p)
    {
    }
    
    MouseLeaveEvent::~MouseLeaveEvent()
    {
    }

    void MouseLeaveEvent::init_info()
    {
        auto w = writer<MouseLeaveEvent>();
        w.description("Mouse Leave Event");
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseLeaveEvent)

