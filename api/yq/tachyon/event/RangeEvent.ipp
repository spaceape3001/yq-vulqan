////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "RangeEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RangeEvent)

namespace yq::tachyon {
    RangeEvent::RangeEvent(const Header& h) : Event(h)
    {
    }
    
    RangeEvent::RangeEvent(const RangeEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    RangeEvent::~RangeEvent()
    {
    }
    
    void RangeEvent::init_meta()
    {
        auto w = writer<RangeEvent>();
        w.abstract();
        w.description("Range Event");
    }
}
