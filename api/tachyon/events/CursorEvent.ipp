////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CursorEvent.hpp"

#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CursorEvent)

namespace yq::tachyon {
    
    CursorEventInfo::CursorEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::CURSOR);
    }

    ////////////////////////////////////////////////////////////////////////////

    CursorEvent::CursorEvent(const Param& p) : InputEvent(p), m_position(p.position)
    {
    }
    
    CursorEvent::~CursorEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_cursor_event()
    {
        {
            auto w = writer<CursorEvent>();
            w.description("Cursor event base class");
            w.property("position", &CursorEvent::position).description("Cursor position at event detection");
        }
    }
    
    YQ_INVOKE(reg_cursor_event();)
}
