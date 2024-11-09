////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "WindowFocusEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::WindowFocusEvent)

namespace yq::tachyon {

    WindowFocusEvent::WindowFocusEvent(Viewer* v, const Param& p) : WindowEvent(v, p)
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
