////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MouseEvent.hpp"

#include <yq-toolbox/basic/DelayInit.hpp>

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

    static void reg_mouse_input()
    {
        {
            auto w = writer<MouseEvent>();
            w.description("Mouse input event base class");
        }
    }
    
    YQ_INVOKE(reg_mouse_input();)
}
