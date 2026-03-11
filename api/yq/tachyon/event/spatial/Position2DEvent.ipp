////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Position2DEvent.hpp"
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position²DEvent)

namespace yq::tachyon {
    Position²DEvent::Position²DEvent(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position²DEvent::Position²DEvent(const Header&h, const Vector2D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position²DEvent::Position²DEvent(const Position²DEvent&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position²DEvent::~Position²DEvent()
    {
    }

    PostCPtr    Position²DEvent::clone(rebind_k, const Header& h) const 
    {
        return new Position²DEvent(*this, h);
    }
   
    void Position²DEvent::init_meta()
    {
        auto w = writer<Position²DEvent>();
        w.description("Position Positiond Event in 2D");
        w.property("x", &Position²DEvent::x).tag(kTag_Log);
        w.property("y", &Position²DEvent::y).tag(kTag_Log);
        w.property("position", &Position²DEvent::m_position).tag(kTag_Save);
    }
}
