
////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VulqanEvent.hpp"

#include <yq/post/EventInfoWriter.hpp>
#include <yq/core/DelayInit.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::VulqanEvent)

namespace yq::tachyon {
    VulqanEventInfo::VulqanEventInfo(std::string_view zName, const post::EventInfo& base, const std::source_location& sl) :
        post::EventInfo(zName, base, sl)
    {
        set(Flag::VULKAN);
    }

    ////////////////////////////////////////////////////////////////////////////

    VulqanEvent::VulqanEvent(const Param& p) : post::Event(p)
    {
    }
    
    VulqanEvent::~VulqanEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    static void reg_vulqan_event()
    {
        {
            auto w = writer<VulqanEvent>();
            w.description("Vulqan event base class");
        }
    }
    
    YQ_INVOKE(reg_vulqan_event();)
}
