////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/spatial/Position2Event.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position²Event)

namespace yq::tachyon {
    Position²Event::Position²Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position²Event::Position²Event(const Header&h, const Vector2D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position²Event::Position²Event(const Position²Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position²Event::~Position²Event()
    {
    }

    PostCPtr    Position²Event::clone(rebind_k, const Header& h) const 
    {
        return new Position²Event(*this, h);
    }
   
    void Position²Event::init_info()
    {
        auto w = writer<Position²Event>();
        w.description("Position Positiond Event in 2D");
        w.property("x", &Position²Event::x).tag(kTag_Log);
        w.property("y", &Position²Event::y).tag(kTag_Log);
        w.property("position", &Position²Event::m_position).tag(kTag_Save);
    }
}
