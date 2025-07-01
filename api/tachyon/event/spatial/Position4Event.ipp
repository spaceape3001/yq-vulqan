////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/Position4Event.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position⁴Event)

namespace yq::tachyon {
    Position⁴Event::Position⁴Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
    Position⁴Event::Position⁴Event(const Header&h, const Vector4D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }

    Position⁴Event::Position⁴Event(const Position⁴Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position⁴Event::~Position⁴Event()
    {
    }

    PostCPtr    Position⁴Event::clone(rebind_k, const Header& h) const 
    {
        return new Position⁴Event(*this, h);
    }
   
    void Position⁴Event::init_meta()
    {
        auto w = writer<Position⁴Event>();
        w.description("Position Positiond Event in 4D");
        w.property("x", &Position⁴Event::x).tag(kTag_Log);
        w.property("y", &Position⁴Event::y).tag(kTag_Log);
        w.property("z", &Position⁴Event::z).tag(kTag_Log);
        w.property("w", &Position⁴Event::w).tag(kTag_Log);
        w.property("position", &Position⁴Event::m_position).tag(kTag_Save);
    }
}
