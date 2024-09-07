////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "KeyboardEvent.hpp"

#include <yq-toolbox/basic/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyboardEvent)

namespace yq::tachyon {
    
    KeyboardEventInfo::KeyboardEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::KEYBOARD);
    }

    ////////////////////////////////////////////////////////////////////////////

    KeyboardEvent::KeyboardEvent()
    {
    }
    
    KeyboardEvent::~KeyboardEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_keyboard_input()
    {
        {
            auto w = writer<KeyboardEvent>();
            w.description("Keyboard input event base class");
        }
    }
    
    YQ_INVOKE(reg_keyboard_input();)
}
