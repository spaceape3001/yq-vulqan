////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QSimLL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/SimEvent.hpp>
#include <yt/msg/EventInfoWriter.hpp>

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
    
    void SimEvent::init_info()
    {
        auto w = writer<SimEvent>();
        w.abstract();
        w.description("Sim Event");
    }
}
