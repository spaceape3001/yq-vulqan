////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/cursor/CursorNormalEvent.hpp>
#include <tachyon/api/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorNormalEvent)

namespace yq::tachyon {

    CursorNormalEvent::CursorNormalEvent(const Header&h) : CursorEvent(h)
    {
    }
    
    CursorNormalEvent::CursorNormalEvent(const CursorNormalEvent& cp, const Header&h) : CursorEvent(cp, h)
    {
    }

    CursorNormalEvent::~CursorNormalEvent()
    {
    }
    
    PostCPtr    CursorNormalEvent::clone(rebind_k, const Header&h) const 
    {
        return new CursorNormalEvent(*this, h);
    }

    ////////////////////////////////////////////////////////////////////////////

    void CursorNormalEvent::init_info()
    {
        auto w = writer<CursorNormalEvent>();
        w.description("Cursor Normal Event");
    }
}
