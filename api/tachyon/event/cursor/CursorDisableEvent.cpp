////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/cursor/CursorDisableEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorDisableEvent)

namespace yq::tachyon {

    CursorDisableEvent::CursorDisableEvent(const Header&h) : CursorEvent(h)
    {
    }
    
    CursorDisableEvent::CursorDisableEvent(const CursorDisableEvent& cp, const Header&h) : CursorEvent(cp, h)
    {
    }

    CursorDisableEvent::~CursorDisableEvent()
    {
    }
    
    PostCPtr    CursorDisableEvent::clone(rebind_k, const Header&h) const 
    {
        return new CursorDisableEvent(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void CursorDisableEvent::init_info()
    {
        auto w = writer<CursorDisableEvent>();
        w.description("Cursor Disable Event");
    }
}
