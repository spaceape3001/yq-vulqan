////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QEngineLL
//
////////////////////////////////////////////////////////////////////////////////

#include "EngineEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::EngineEvent)

namespace yq::tachyon {
    EngineEvent::EngineEvent(const Header& h) : Event(h)
    {
    }
    
    EngineEvent::EngineEvent(const EngineEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    EngineEvent::~EngineEvent()
    {
    }
    
    void EngineEvent::init_meta()
    {
        auto w = writer<EngineEvent>();
        w.abstract();
        w.description("Engine Event");
    }
}
