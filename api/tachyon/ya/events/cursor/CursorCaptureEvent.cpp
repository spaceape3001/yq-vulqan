////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/cursor/CursorCaptureEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorCaptureEvent)

namespace yq::tachyon {

    CursorCaptureEvent::CursorCaptureEvent(const Header&h) : CursorEvent(h)
    {
    }
    
    CursorCaptureEvent::CursorCaptureEvent(const CursorCaptureEvent& cp, const Header&h) : CursorEvent(cp, h)
    {
    }

    CursorCaptureEvent::~CursorCaptureEvent()
    {
    }
    
    PostCPtr    CursorCaptureEvent::clone(rebind_k, const Header&h) const 
    {
        return new CursorCaptureEvent(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void CursorCaptureEvent::init_info()
    {
        auto w = writer<CursorCaptureEvent>();
        w.description("Cursor Capture Event");
    }
}
