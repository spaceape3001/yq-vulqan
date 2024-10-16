////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseEvent.hpp"

#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MouseEvent)

namespace yq::tachyon {
    
    MouseEventInfo::MouseEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::MOUSE);
    }

    ////////////////////////////////////////////////////////////////////////////

    MouseEvent::MouseEvent()
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
        }
    }
    
    YQ_INVOKE(reg_mouse_event();)
}
