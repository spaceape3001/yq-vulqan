////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position2MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position2MEvent)

namespace yq::tachyon {
    Position2MEvent::Position2MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position2MEvent::Position2MEvent(const Header&h, const unit::Meter2D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position2MEvent::Position2MEvent(const Position2MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position2MEvent::~Position2MEvent()
    {
    }

    PostCPtr    Position2MEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position2MEvent(*this, h);
    }
   
    void Position2MEvent::init_meta()
    {
        auto w = writer<Position2MEvent>();
        w.description("Position Event in 2D (meters)");
        w.property("x", &Position2MEvent::x).tag(kTag_Log);
        w.property("y", &Position2MEvent::y).tag(kTag_Log);
        w.property("position", &Position2MEvent::m_position).tag(kTag_Save);
    }
}
