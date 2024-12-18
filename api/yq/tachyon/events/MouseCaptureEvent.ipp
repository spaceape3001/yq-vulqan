////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseCaptureEvent.hpp"
#include <yq/post/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseCaptureEvent)

namespace yq::tachyon {

    MouseCaptureEvent::MouseCaptureEvent(Viewer* v, const Param& p) : ViewerEvent(v, p)
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
