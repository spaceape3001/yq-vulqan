////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QCountLL
//
////////////////////////////////////////////////////////////////////////////////

#include "CountEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::CountEvent)

namespace yq::tachyon {
    CountEvent::CountEvent(const Header& h) : Event(h)
    {
    }
    
    CountEvent::CountEvent(const CountEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    CountEvent::~CountEvent()
    {
    }
    
    void CountEvent::init_meta()
    {
        auto w = writer<CountEvent>();
        w.abstract();
        w.description("Count Event");
    }
}
