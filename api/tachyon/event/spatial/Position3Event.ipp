////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/event/spatial/Position3Event.hpp>
#include <tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Position³Event)

namespace yq::tachyon {
    Position³Event::Position³Event(const Header&h) : 
        SpatialEvent(h)
    {
    }
    
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
        w.property("x", &Position³Event::x).tag(kTag_Log);
        w.property("y", &Position³Event::y).tag(kTag_Log);
        w.property("z", &Position³Event::z).tag(kTag_Log);
        w.property("position", &Position³Event::m_position).tag(kTag_Save);
    }
}
