
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
    VulqanEventInfo::VulqanEventInfo(std::string_view zName, post::EventInfo& base, const std::source_location& sl) :
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

    void VulqanEvent::init_info()
    {
        auto w = writer<VulqanEvent>();
        w.description("Vulqan event base class");
    }
    
    YQ_INVOKE(VulqanEvent::init_info();)
}
