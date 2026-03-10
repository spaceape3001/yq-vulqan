////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position3MEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position3MEvent)

namespace yq::tachyon {
    Position3MEvent::Position3MEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position3MEvent::Position3MEvent(const Header&h, const unit::Meter3D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position3MEvent::Position3MEvent(const Position3MEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position3MEvent::~Position3MEvent()
    {
    }

    PostCPtr    Position3MEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position3MEvent(*this, h);
    }
   
    void Position3MEvent::init_meta()
    {
        auto w = writer<Position3MEvent>();
        w.description("Position Event in 3D (meters)");
        w.property("x", &Position3MEvent::x).tag(kTag_Log);
        w.property("y", &Position3MEvent::y).tag(kTag_Log);
        w.property("z", &Position3MEvent::z).tag(kTag_Log);
        w.property("position", &Position3MEvent::m_position).tag(kTag_Save);
    }
}
