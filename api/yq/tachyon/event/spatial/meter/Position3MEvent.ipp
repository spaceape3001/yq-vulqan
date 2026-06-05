////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position3MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position³MEvent)

namespace yq::tachyon {
    Position³MEvent::Position³MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position³MEvent::Position³MEvent(const Header&h, const Meter3D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position³MEvent::Position³MEvent(const Position³MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position³MEvent::~Position³MEvent()
    {
    }

    PostCPtr    Position³MEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position³MEvent(*this, h);
    }
   
    void Position³MEvent::init_meta()
    {
        auto w = writer<Position³MEvent>();
        w.description("Position Event in 3D (meters)");
        w.property("x", &Position³MEvent::x).tag(kTag_Log);
        w.property("y", &Position³MEvent::y).tag(kTag_Log);
        w.property("z", &Position³MEvent::z).tag(kTag_Log);
        w.property("position", &Position³MEvent::m_position).tag(kTag_Save);
    }
}
