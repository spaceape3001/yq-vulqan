////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowCursorNormalEvent.hpp"
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowCursorNormalEvent)

namespace yq::tachyon {

    WindowCursorNormalEvent::WindowCursorNormalEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowCursorNormalEvent::~WindowCursorNormalEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowCursorNormalEvent::init_info()
    {
        auto w = writer<WindowCursorNormalEvent>();
        w.description("Window Cursor Normal Event");
    }
}
