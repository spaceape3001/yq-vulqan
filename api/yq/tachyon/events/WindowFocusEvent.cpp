////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowFocusEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowFocusEvent)

namespace yq::tachyon {

    WindowFocusEvent::WindowFocusEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    WindowFocusEvent::~WindowFocusEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void WindowFocusEvent::init_info()
    {
        auto w = writer<WindowFocusEvent>();
        w.description("Window Focus Event");
    }
}
