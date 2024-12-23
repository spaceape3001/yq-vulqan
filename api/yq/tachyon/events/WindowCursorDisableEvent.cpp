////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowCursorDisableEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCursorDisableEvent)

namespace yq::tachyon {

    WindowCursorDisableEvent::WindowCursorDisableEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowCursorDisableEvent::~WindowCursorDisableEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowCursorDisableEvent::init_info()
    {
        auto w = writer<WindowCursorDisableEvent>();
        w.description("Window Cursor Disable Event");
    }
}
