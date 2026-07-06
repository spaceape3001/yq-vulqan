////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QDomainLL
//
////////////////////////////////////////////////////////////////////////////////

#include "DomainEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::DomainEvent)

namespace yq::tachyon {
    DomainEvent::DomainEvent(const Header& h) : Event(h)
    {
    }
    
    DomainEvent::DomainEvent(const DomainEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    DomainEvent::~DomainEvent()
    {
    }
    
    void DomainEvent::init_meta()
    {
        auto w = writer<DomainEvent>();
        w.abstract();
        w.description("Domain Event");
    }
}
