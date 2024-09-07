////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "InputEvent.hpp"

#include <yq-toolbox/basic/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::InputEvent)

namespace yq::tachyon {
    
    InputEventInfo::InputEventInfo(std::string_view zName, const EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
        set(Flag::COMMAND);
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
            w.description("InputEvent base class");
        }
    }
    
    YQ_INVOKE(reg_input_event();)
}
