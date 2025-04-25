
////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/VulqanEvent.hpp>

#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::VulqanEvent)

namespace yq::tachyon {
    VulqanEventInfo::VulqanEventInfo(std::string_view zName, EventInfo& base, const std::source_location& sl) :
        EventInfo(zName, base, sl)
    {
        set(Flag::VULKAN);
    }

    ////////////////////////////////////////////////////////////////////////////

    VulqanEvent::VulqanEvent(const Param& p) : Event(p)
    {
    }
    
    VulqanEvent::~VulqanEvent()
    {
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void VulqanEvent::init_info()
    {
        auto w = writer<VulqanEvent>();
        w.description("Vulqan event base class");
    }
}
