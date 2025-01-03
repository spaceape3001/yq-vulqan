////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseLeaveEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

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

