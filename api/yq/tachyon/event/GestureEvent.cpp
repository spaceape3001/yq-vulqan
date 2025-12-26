////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QGestureLL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/event/GestureEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::GestureEvent)

namespace yq::tachyon {
    GestureEvent::GestureEvent(const Header& h) : Event(h)
    {
    }
    
    GestureEvent::GestureEvent(const GestureEvent&cp, const Header&h) : Event(cp, h)
    {
    }

    GestureEvent::~GestureEvent()
    {
    }
    
    void GestureEvent::init_meta()
    {
        auto w = writer<GestureEvent>();
        w.abstract();
        w.description("Gesture Event");
    }
}
