////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/KeyboardEvent.hpp>

#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::KeyboardEvent)

namespace yq::tachyon {
    
    KeyboardEventInfo::KeyboardEventInfo(std::string_view zName, InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::KEYBOARD);
    }

    ////////////////////////////////////////////////////////////////////////////

    KeyboardEvent::KeyboardEvent(Window* w, const Param& p) : InputEvent(w, p)
    {
    }

    KeyboardEvent::KeyboardEvent(WindowID w, const Param& p) : InputEvent(w, p)
    {
    }
    
    KeyboardEvent::~KeyboardEvent()
    {
    }


    ////////////////////////////////////////////////////////////////////////////

    void KeyboardEvent::init_info()
    {
        {
            auto w = writer<KeyboardEvent>();
            w.description("Keyboard event base class");
        }
    }
}
