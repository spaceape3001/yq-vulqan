////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "InputEvent.hpp"

#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::InputEvent)

namespace yq::tachyon {
    
    InputEventInfo::InputEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
        set(Flag::INPUT);
    }

    ////////////////////////////////////////////////////////////////////////////

    InputEvent::InputEvent()
    {
    }
    
    InputEvent::~InputEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_input_event()
    {
        {
            auto w = writer<InputEvent>();
            w.description("Input event base class");
        }
    }
    
    YQ_INVOKE(reg_input_event();)
}
