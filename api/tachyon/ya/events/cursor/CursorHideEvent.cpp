////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/cursor/CursorHideEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorHideEvent)

namespace yq::tachyon {

    CursorHideEvent::CursorHideEvent(const Header&h) : CursorEvent(h)
    {
    }
    
    CursorHideEvent::CursorHideEvent(const CursorHideEvent& cp, const Header&h) : CursorEvent(cp, h)
    {
    }

    CursorHideEvent::~CursorHideEvent()
    {
    }
    
    PostCPtr    CursorHideEvent::clone(rebind_k, const Header&h) const 
    {
        return new CursorHideEvent(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void CursorHideEvent::init_info()
    {
        auto w = writer<CursorHideEvent>();
        w.description("Cursor Hide Event");
    }
}
