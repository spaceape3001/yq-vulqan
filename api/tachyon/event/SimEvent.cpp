////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QSimLL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/SimEvent.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SimEvent)

namespace yq::tachyon {
    SimEvent::SimEvent(const Header& h) : Event(h)
    {
    }
    
    SimEvent::SimEvent(const SimEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    SimEvent::~SimEvent()
    {
    }
    
    void SimEvent::init_meta()
    {
        auto w = writer<SimEvent>();
        w.abstract();
        w.description("Sim Event");
    }
}
