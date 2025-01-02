////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowCursorCaptureEvent.hpp"
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCursorCaptureEvent)

namespace yq::tachyon {

    WindowCursorCaptureEvent::WindowCursorCaptureEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowCursorCaptureEvent::~WindowCursorCaptureEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowCursorCaptureEvent::init_info()
    {
        auto w = writer<WindowCursorCaptureEvent>();
        w.description("Window Cursor Capture Event");
    }
}
