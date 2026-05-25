////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QMasterLL
//
////////////////////////////////////////////////////////////////////////////////

#include "MasterEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MasterEvent)

namespace yq::tachyon {
    MasterEvent::MasterEvent(const Header& h) : Event(h)
    {
    }
    
    MasterEvent::MasterEvent(const MasterEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    MasterEvent::~MasterEvent()
    {
    }
    
    void MasterEvent::init_meta()
    {
        auto w = writer<MasterEvent>();
        w.abstract();
        w.description("Master Event");
    }
}
