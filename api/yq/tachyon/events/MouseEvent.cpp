////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseEvent.hpp"

#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseEvent)

namespace yq::tachyon {
    
    MouseEventInfo::MouseEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::MOUSE);
    }

    ////////////////////////////////////////////////////////////////////////////

    MouseEvent::MouseEvent(const Param& p) : InputEvent(p), m_position(p.position), m_buttons(p.buttons)
    {
    }
    
    MouseEvent::~MouseEvent()
    {
    }

    ////////////////////////////////////////////////////////////////////////////

    static void reg_mouse_event()
    {
        {
            auto w = writer<MouseEvent>();
            w.description("Mouse event base class");
            w.property("position", &MouseEvent;:position).description("Mouse (cursor) position");
            w.property("x", &MouseEvent::x).description("Mouse (cursor) X position");
            w.property("y", &MouseEvent::y).description("Mouse (cursor) Y position");
        }
    }
    
    YQ_INVOKE(reg_mouse_event();)
}
