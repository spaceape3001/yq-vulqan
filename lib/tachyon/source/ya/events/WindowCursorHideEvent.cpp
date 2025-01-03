////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/WindowCursorHideEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCursorHideEvent)

namespace yq::tachyon {

    WindowCursorHideEvent::WindowCursorHideEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowCursorHideEvent::~WindowCursorHideEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowCursorHideEvent::init_info()
    {
        auto w = writer<WindowCursorHideEvent>();
        w.description("Window Cursor Hide Event");
    }
}
