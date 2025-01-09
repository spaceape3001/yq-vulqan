////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/events/spatial/Position3Event.hpp>
#include <yt/msg/EventInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position³Event)

namespace yq::tachyon {
    Position³Event::Position³Event(const Header&h, const Vector3D& v) : 
        SpatialEvent(h), m_position(v)
    {
    }
    
    Position³Event::Position³Event(const Position³Event&cp, const Header&h) : 
        SpatialEvent(cp, h), m_position(cp.m_position)
    {
    }

    Position³Event::~Position³Event()
    {
    }

    PostCPtr    Position³Event::clone(rebind_k, const Header& h) const 
    {
        return new Position³Event(*this, h);
    }
   
    void Position³Event::init_info()
    {
        auto w = writer<Position³Event>();
        w.description("Position Positiond Event in 3D");
        w.property("x", &Position³Event::x);
        w.property("y", &Position³Event::y);
        w.property("z", &Position³Event::z);
    }
}
