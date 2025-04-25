////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QCursorLL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/CursorEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorEvent)

namespace yq::tachyon {
    CursorEvent::CursorEvent(const Header& h) : Event(h)
    {
    }
    
    CursorEvent::CursorEvent(const CursorEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    CursorEvent::~CursorEvent()
    {
    }
    
    void CursorEvent::init_info()
    {
        auto w = writer<CursorEvent>();
        w.abstract();
        w.description("Cursor Event");
    }
}
