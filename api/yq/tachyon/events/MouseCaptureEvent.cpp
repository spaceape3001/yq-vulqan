////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseCaptureEvent.hpp"
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseCaptureEvent)

namespace yq::tachyon {

    MouseCaptureEvent::MouseCaptureEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    MouseCaptureEvent::~MouseCaptureEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void MouseCaptureEvent::init_info()
    {
        auto w = writer<MouseCaptureEvent>();
        w.description("Mouse Capture Event");
    }
}
