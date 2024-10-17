
////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VulqanEvent.hpp"

#include <tachyon/event/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::VulqanEvent)

namespace yq::tachyon {
    VulqanEventInfo::VulqanEventInfo(std::string_view zName, const InputEventInfo& base, const std::source_location& sl) :
        InputEventInfo(zName, base, sl)
    {
        set(Flag::VULKAN);
    }

    ////////////////////////////////////////////////////////////////////////////

    VulqanEvent::VulqanEvent() 
    {
    }
    
    VulqanEvent::~VulqanEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_joystick_event()
    {
        {
            auto w = writer<VulqanEvent>();
            w.description("Vulqan event base class");
        }
    }
    
    YQ_INVOKE(reg_joystick_event();)
}
