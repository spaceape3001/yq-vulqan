////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QOSLL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/OSEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OSEvent)

namespace yq::tachyon {
    OSEvent::OSEvent(const Header& h) : Event(h)
    {
    }
    
    OSEvent::OSEvent(const OSEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    OSEvent::~OSEvent()
    {
    }
    
    void OSEvent::init_meta()
    {
        auto w = writer<OSEvent>();
        w.abstract();
        w.description("OS Event");
    }
}
