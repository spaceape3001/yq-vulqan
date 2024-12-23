////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowCursorHideEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

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
