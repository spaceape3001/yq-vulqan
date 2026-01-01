////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QVulqanLL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/VulqanEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::VulqanEvent)

namespace yq::tachyon {
    VulqanEvent::VulqanEvent(const Header& h) : Event(h)
    {
    }
    
    VulqanEvent::VulqanEvent(const VulqanEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    VulqanEvent::~VulqanEvent()
    {
    }
    
    void VulqanEvent::init_meta()
    {
        auto w = writer<VulqanEvent>();
        w.abstract();
        w.description("Vulqan Event");
    }
}
