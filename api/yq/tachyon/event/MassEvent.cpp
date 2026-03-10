////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QMassLL
//
////////////////////////////////////////////////////////////////////////////////

#include "MassEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MassEvent)

namespace yq::tachyon {
    MassEvent::MassEvent(const Header& h) : Event(h)
    {
    }
    
    MassEvent::MassEvent(const MassEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    MassEvent::~MassEvent()
    {
    }
    
    void MassEvent::init_meta()
    {
        auto w = writer<MassEvent>();
        w.description("Mass Event");
        w.abstract();
    }
}
