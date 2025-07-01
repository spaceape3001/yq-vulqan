////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/cursor/CursorCaptureEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

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
