////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CursorCaptureEvent.hpp"
#include <yq/tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorCaptureEvent)

namespace yq::tachyon {

    CursorCaptureEvent::CursorCaptureEvent(Window* v, const Param& p) : WindowEvent(v, p)
    {
    }
    
    CursorCaptureEvent::~CursorCaptureEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void CursorCaptureEvent::init_info()
    {
        auto w = writer<CursorCaptureEvent>();
        w.description("Cursor Capture Event");
    }
}
