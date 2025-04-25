////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/SpatialEvent.hpp>
#include <tachyon/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SpatialEvent)

namespace yq::tachyon {
    SpatialEvent::SpatialEvent(const Header& h) : Event(h)
    {
    }
    
    SpatialEvent::SpatialEvent(const SpatialEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    SpatialEvent::~SpatialEvent()
    {
    }
    
    void SpatialEvent::init_info()
    {
        auto w = writer<SpatialEvent>();
        w.abstract();
        w.description("Spatial Event");
    }
}
